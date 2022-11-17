#ifndef __ASR_MATH_H__
#define __ASR_MATH_H__

#include "asr_supports/asr_platform.h"
#include "asr_supports/asr_types.h"

#if defined(ASR_CK803)
#include "csky_math.h"
#include "csky_const_structs.h"
#elif defined(ASR_CK805)
#include "csky_vdsp2_math.h"
#include "csky_vdsp2_const_structs.h"
#elif defined(_LINUX_)
#include <stddef.h>
#else
#include <math.h>
#endif

#ifdef HIFI3
#include "NatureDSP_Signal.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

#if defined(ASR_CSKY) || defined(HIFI3)
// C-Sky and HIFI Math doesn't have max and min macros.
#endif

#define coerce(value, max_limit, min_limit) \
MAX((min_limit), MIN((max_limit), (value)))

#ifndef M_PI
#define M_PI 3.141592654f
#endif // M_PI

#ifndef M_2PI
#define M_2PI 6.283185307f
#endif

fxp32_t multiply_accumulate_fxp8_fxp8(
	const fxp8_t *src0,
	const fxp8_t *src1,
	size_t size);

fxp32_t multiply_accumulate_fxp16_fxp8(
	const fxp16_t *src0,
	const fxp8_t *src1,
	const size_t size);

fxp64_t multiply_accumulate_fxp16_fxp16(
	const fxp16_t *src0,
	const fxp16_t *src1,
	const size_t size);

fxp64_t multiply_accumulate_fxp32_fxp16(
	const fxp32_t *src0,
	const fxp16_t *src1,
	const size_t size);

float multiply_accumulate(
	const float *src0,
	const float *src1,
	const size_t size);

void multiply_matrix_vector(
	const float *matrix,
	const float *vector,
	float *dst,
	const size_t cols,
	const size_t rows);

void multiply_matrix_vector_fxp8_fxp8(
	const fxp8_t *matrix,
	const fxp8_t *vector,
	fxp32_t *dst,
	const size_t cols,
	size_t rows);

int32_t round_to_nearest_pow2(int32_t n);

float get_vector_max(const float *data, const size_t size);

fxp32_t get_vector_abs_max(const fxp32_t *data, const size_t size);

void multiply_element_wise(
	const float *src0,
	const float *src1,
	float *dst,
	const size_t size);

void sqrt_element_wise(const float *src, float *dst, const size_t size);

void safe_log_element_wise(
	const float *src,
	float *dst,
	const size_t size,
	const float epsilon);

void add_element_wise(
	const float *src0,
	const float *src1,
	float *dst,
	const size_t size);

void add_array_scalar(
	const float *src0,
	const float src1,
	float *dst,
	const size_t size);

void add_array_scalar_fxp32(
	const fxp32_t *src0,
	const fxp32_t src1,
	fxp32_t *dst,
	const size_t size);

void transpose_matrix(
	const float *src,
	float *dst,
	const size_t num_row,
	const size_t num_col);

void rfft(float *data, const size_t size, const bool forward);

void mean_normalize(
	const float *input,
	const size_t size,
	const float *mean,
	const float *inv_std, // 1/std
	float *output);

/* Array operations */

void asr_array_scale_f32_c(
	const float *src,
	float factor,
	float *dst,
	size_t size);

void asr_array_scale_fxp16_c(
	const fxp16_t *src,
	fxp16_t factor,
	int8_t shift,
	fxp16_t *dst,
	size_t size);

void asr_array_add_fxp16_c(
	const fxp16_t *src0,
	const fxp16_t *src1,
	fxp16_t *dst,
	size_t size);

fxp32_t asr_array_sum_fxp16_c(const fxp16_t *data, size_t size);

void asr_array_max_fxp16_c(
	const fxp16_t *data,
	size_t size,
	fxp16_t *max_value,
	size_t *max_index);

void asr_array_sub_fxp32_c(
	const fxp32_t *src0,
	const fxp32_t *src1,
	fxp32_t *dst,
	size_t size);

/* Wrappers of array operations */

#if defined(ASR_CK803)
static inline void asr_array_scale_f32(
	const float *src,
	float factor,
	float *dst,
	size_t size) {
	csky_scale_f32((float *)src, factor, dst, size);
}

static inline void asr_array_scale_fxp16(
	const fxp16_t *src,
	fxp16_t factor,
	int8_t shift,
	fxp16_t *dst,
	size_t size) {
	csky_scale_q15((q15_t *)src, factor, 15 - shift, dst, size);
}

static inline void asr_array_add_fxp16(
	const fxp16_t *src0,
	const fxp16_t *src1,
	fxp16_t *dst,
	size_t size) {
	csky_add_q15((q15_t *)src0, (q15_t *)src1, dst, size);
}

#define asr_array_sum_fxp16 asr_array_sum_fxp16_c

#define asr_array_sub_fxp32 asr_array_sub_fxp32_c

static inline void asr_array_max_fxp16(
	const fxp16_t *data,
	size_t size,
	fxp16_t *max_value,
	size_t *max_index) {
	csky_max_q15((q15_t *)data, size, max_value, max_index);
}
#elif defined(ASR_CK805)
#define asr_array_scale_f32 asr_array_scale_f32_c

static inline void asr_array_scale_fxp16(
	const fxp16_t *src,
	fxp16_t factor,
	int8_t shift,
	fxp16_t *dst,
	size_t size) {
	csky_vdsp2_scale_q15((q15_t *)src, factor, 15 - shift, dst, size);
}

static inline void asr_array_add_fxp16(
	const fxp16_t *src0,
	const fxp16_t *src1,
	fxp16_t *dst,
	size_t size) {
	csky_vdsp2_add_q15((q15_t *)src0, (q15_t *)src1, dst, size);
}

static inline fxp32_t asr_array_sum_fxp16(const fxp16_t *data, size_t size) {
	fxp64_t sum = 0;
	csky_vdsp2_sum_q15((q15_t *)data, &sum, size);
	return (fxp32_t)sum;
}

static inline void asr_array_max_fxp16(const fxp16_t *data,
	size_t size,
	fxp16_t *max_value,
	size_t *max_index) {
	csky_vdsp2_max_q15((q15_t *)data, size, max_value, max_index);
}
#define asr_array_sub_fxp32 csky_vdsp2_sub_q31
#else
#define asr_array_scale_f32 asr_array_scale_f32_c
#define asr_array_scale_fxp16 asr_array_scale_fxp16_c
#define asr_array_add_fxp16 asr_array_add_fxp16_c
#define asr_array_sum_fxp16 asr_array_sum_fxp16_c
#define asr_array_max_fxp16 asr_array_max_fxp16_c
#define asr_array_sub_fxp32 asr_array_sub_fxp32_c
#endif

#ifdef __cplusplus
}
#endif

#endif
