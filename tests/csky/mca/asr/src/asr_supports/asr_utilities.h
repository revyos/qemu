#ifndef __ASR_UTILITIES_H__
#define __ASR_UTILITIES_H__

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "asr_supports/asr_platform.h"

#ifdef ASR_CK805
#include "csky_vdsp2_math.h"
#endif

#include "asr_supports/asr_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Read or write registers.
#define reg_wr(reg_addr) *((volatile unsigned int *)reg_addr)

// Copy memory block.
#ifdef ASR_CK805
// By using VDSP registers, it can copy 128-bit data for each time.
static inline void *asr_memcpy(void *dst, const void *src, size_t size) {
	csky_vdsp2_copy_q7((q7_t *)src, (q7_t *)dst, size);
	return dst;
}
#else
#define asr_memcpy memcpy
#endif

#ifdef ASR_CSKY
#define CRITICAL_SECTION_ENTER asm("psrclr ie");
#define CRITICAL_SECTION_LEAVE asm("psrset ie");
#else
#define CRITICAL_SECTION_ENTER
#define CRITICAL_SECTION_LEAVE
#endif

// Round up to the nearest N times of step.
#define ROUND_UP_BY(value, step)                         \
	(((size_t)(value) + ((size_t)(step) - (size_t)0x1))  \
	& (~((size_t)(step) - (size_t)0x1)))

// TODO: FXP-float conversion will be deleted when FXP arithmetic is ready.
fxp16_t convert_float_to_fxp16(const float input, const int q);

fxp8_t convert_fxp16_to_fxp8_with_sat(const fxp16_t input);

fxp8_t convert_fxp32_to_fxp8_with_sat(const fxp32_t input);

fxp16_t convert_fxp32_to_fxp16_with_sat(const fxp32_t input);

fxp16_t convert_fxp64_to_fxp16(const fxp64_t input);

fxp16_t convert_fxp64_to_fxp16_with_sat(const fxp64_t input, const int shift);

// Convert fxp32 array to fxp8 array with round and saturation
void convert_fxp32_to_fxp8_array_with_rounding(
	const fxp32_t *src,
	fxp8_t *dst,
	const size_t size,
	const uint8_t shift);

void convert_fxp32_to_fxp16_array_with_rounding(
	const fxp32_t *src,
	fxp16_t *dst,
	const size_t size,
	const int shift);

void convert_fxp32_to_fxp8_array(
	const fxp32_t *src,
	fxp8_t *dst,
	const size_t size,
	const int8_t shift);

void convert_fxp64_to_fxp16_array_with_sat(
	const fxp64_t *src,
	fxp16_t *dst,
	const size_t size,
	const int shift);

fxp32_t convert_float_to_fxp32(const float input, const int q);

fxp8_t convert_float_to_fxp8(const float input, const int q);

float convert_fxp16_to_float(const fxp16_t input, const int q);

float convert_fxp32_to_float(const fxp32_t input, const int q);

void convert_float_to_fxp16_array(
	const float *src,
	fxp16_t *dst,
	const size_t size,
	const int q);

void convert_float_to_fxp8_array(
	const float *src,
	fxp8_t *dst,
	const size_t size,
	const int q);

void convert_float_to_fxp32_array(
	const float *src,
	fxp32_t *dst,
	const size_t size,
	const int q);

void convert_fxp16_to_float_array(
	const fxp16_t *src,
	float *dst,
	const size_t size,
	const int q);

void convert_fxp32_to_float_array(
	const fxp32_t *src,
	float *dst,
	const size_t size,
	const int q);

void convert_fxp8_to_float_array(
	const fxp8_t *src,
	float *dst,
	const size_t size,
	const int q);

void shift_fxp32_with_sat(
	const fxp32_t *input,
	fxp32_t *output,
	const size_t size,
	const int8_t right_shift);

fxp32_t get_vector_max_fxp(const fxp32_t *data, size_t size);

#pragma region MEMORY_MANAGER

typedef enum {
	SHORT_TERM,
	LONG_TERM
} ALLOCATION_ENTRANCE;

// RAW api. Please do not use these raw apis which start with
// _asr_, instead, use the wrapped ones.
void _asr_free(void *data);

void *_asr_malloc(
	size_t size,
	ALLOCATION_ENTRANCE entrance,
	const char *file_name,
	uint32_t line_number);

void *_asr_malloc_bus_aligned(
	size_t size,
	ALLOCATION_ENTRANCE entrance,
	const char *file_name,
	uint32_t line_number);

size_t check_memory_leak();

#define safe_free(x) _asr_free(x)

#define fast_free(x) _asr_free(x)

#ifdef ASR_ENABLE_MEMORY_CHECKING
#define safe_malloc(x) _asr_malloc((x), LONG_TERM, __FILE__, __LINE__)
#define fast_malloc(x) _asr_malloc((x), SHORT_TERM, __FILE__, __LINE__)

#define safe_malloc_bus_aligned(x)  \
	_asr_malloc_bus_aligned((x), LONG_TERM, __FILE__, __LINE__)
#define fast_malloc_bus_aligned(x)  \
	_asr_malloc_bus_aligned((x), SHORT_TERM, __FILE__, __LINE__)
#else
#define safe_malloc(x) _asr_malloc((x), LONG_TERM, NULL, 0)
#define fast_malloc(x) _asr_malloc((x), SHORT_TERM, NULL, 0)

#define safe_malloc_bus_aligned(x)  \
	_asr_malloc_bus_aligned((x), LONG_TERM, NULL, 0)
#define fast_malloc_bus_aligned(x)  \
	_asr_malloc_bus_aligned((x), SHORT_TERM, NULL, 0)
#endif

#pragma endregion

// Supported 1d array must have structure as:
// typedef struct {
//     size_t size;
//     xxxx data[1];
// } xxxx;
static inline void *create_array(size_t elem_size, size_t size)
{
	void *p = malloc(sizeof(size_t) + elem_size * size);
	*(size_t *)p = size;
	return p;
}

#ifdef ASR_CSKY
#define _DNN_ADDR_ __attribute__((section(".dnn")))
#define _NNET_BUFFER_ADDR_ __attribute__((section(".dnnIn")))
#define _SDRAM_ADDR_ __attribute__((section(".sdram")))
#else
#define _DNN_ADDR_
#define _NNET_BUFFER_ADDR_ 
#define _SDRAM_ADDR_ 
#endif // ASR_CSKY

// Swap the pointers.
#define SWAP_POINTER(a, b) {          \
	const void *_swapper = NULL;      \
	_swapper = (a);                   \
	(a) = (b);                        \
	*(const void **)&(b) = _swapper;  \
}

#if !defined(NDEBUG)
#define ASR_ASSERT(p)                                           \
	if(!(p)) {                                                  \
		fprintf(stderr, "Assert failed: %s,file %s,line %d\n",  \
		#p,__FILE__,__LINE__);                                  \
		abort();                                                \
	}

#else
#define ASR_ASSERT(p)
#endif

#if defined(ASR_CSKY) && !ASR_SIM_MODE
extern void start_timer();
extern uint32_t get_time();
extern void print_time();
#else
static inline void start_timer() {}
static inline uint32_t get_time() { return 0; }
static inline void print_time() {}
#endif

#ifdef __cplusplus
}
#endif

#endif
