#ifndef __CSKY_MCA_TEST_HELPER_H__
#define __CSKY_MCA_TEST_HELPER_H__

#include "asr_supports/asr_math.h"
#include "asr_supports/asr_utilities.h"

/**
 * Numeric types in MCA, this type is used for (void *) functions.
 * Enum value = 0x{index}{element_size}
 */
typedef enum {
	MCA_FXP64       = 0x08,
	MCA_FXP32       = 0x14,
	MCA_FXP24       = 0x24,
	MCA_FXP16_32BIT = 0x34,
	MCA_FXP16       = 0x42,
	MCA_FXP8        = 0x51
} mca_num_type_t;

/* Gets size of MCA numeric type. */
static inline size_t size_of(mca_num_type_t type) {
	return type & 0x0F;
}

/* Increases pointer value by element size. */
#define INC_PTR_VAL_BY_SIZE(p, elem_size) \
	(p = (void *)((char *)p + elem_size))

/* Increases pointer value by element type. */
#define INC_PTR_VAL_BY_TYPE(p, elem_type) \
	INC_PTR_VAL_BY_SIZE(p, size_of(elem_type))

/* Description of a cache block. */
typedef struct {
	mca_num_type_t type;
	size_t count;
} mca_cache_block_t;

/* Alignment in memory test */
typedef enum {
	align_any = 0x0000,
	align_0   = 0x0001,
	align_1   = 0x0002,
	align_2   = 0x0004,
	align_3   = 0x0008,
	align_4   = 0x0010,
	align_5   = 0x0020,
	align_6   = 0x0040,
	align_7   = 0x0080,
	align_8   = 0x0100,
	align_9   = 0x0200,
	align_a   = 0x0400,
	align_b   = 0x0800,
	align_c   = 0x1000,
	align_d   = 0x2000,
	align_e   = 0x4000,
	align_f   = 0x8000,
	align_all = 0xFFFF,
} mca_memory_alignment_t;

/* Input/Ouput direction. */
typedef enum {
	io_dir_input,
	io_dir_output,
} mca_io_dir_t;

/* A single block in memory test */
typedef struct {
	mca_num_type_t type;
	size_t count;
	mca_memory_alignment_t aligns;
	mca_io_dir_t io_dir;
	size_t cache_index;
	bool input_change_allowed;
	fxp32_t tolerance;
} mca_test_block_t;

typedef void (*mca_gen_cache_func)(
	void *params,
	const mca_cache_block_t *cache_blocks,
	void **cache_ptrs);

typedef bool (*mca_test_func)(
	void *params,
	const mca_test_block_t *test_blocks,
	void **block_ptrs);

/* Generic hardware test for MCA functions. */
bool mca_generic_hardware_test(
	void *params,
	mca_gen_cache_func cache_generator,
	const mca_cache_block_t *cache_blocks,
	size_t num_cache_blocks,
	mca_test_func test_func,
	mca_test_block_t *test_blocks,
	size_t num_test_blocks);

void *allocate_bank_awareness(
	void **bank_a, size_t size_bank_a,
	void **bank_b, size_t size_bank_b,
	size_t num_additional_blocks, ...);

void linear_regression(
	const float *x,
	const float *y,
	size_t n,
	float *slope,
	float *intercept,
	float *r2);

/**
 * A simple implementation of 128-bit integer
 *
 * We need this type to generate golden results for MCA test since MCA uses
 * 70+ bits to store intermediate results.
 * Since MCA only accepts input less than or equal to 64-bit, so only
 * accumulation and bit-shift operations are implemented as 128-bit.
 */
typedef struct {
	ufxp64_t lo;
	union {
		ufxp64_t u; /// As unsigned 64-bit
		fxp64_t s;  /// As signed 64-bit
	} hi;
} fxp128_t;

/* Initializes an instance of fxp128_t. */
void fxp128_init(fxp128_t *x);

/* Adds with a signed 64-bit number. */
void fxp128_add(fxp128_t *x, fxp64_t v);

/* Calculates the negative number of x, i.e. -x. */
void fxp128_negate(fxp128_t *x);

/* Shifts left. */
void fxp128_shl(fxp128_t *x, uint8_t bits);
/* Shifts right. */
void fxp128_shr(fxp128_t *x, uint8_t bits);

/* Rounds at specified position q, ASRC has such operation. */
void fxp128_round(fxp128_t *x, uint8_t q);

/* Saturates to specified numeric type. */
void fxp128_sat_to(const fxp128_t *x, void *v, mca_num_type_t v_type);
/* Saturates to signed 64-bit number. */
void fxp128_sat_to_fxp64(const fxp128_t *x, fxp64_t *v);

/* Multiply and accumulate, a and b are same type. */
void fxp128_mac(
	fxp128_t *x,
	const void *a,
	const void *b,
	mca_num_type_t type,
	size_t n);

/* Multiply and accumulate, a and b are different types. */
void fxp128_mac_diff_types(
	fxp128_t *x,
	const void *a,
	mca_num_type_t a_type,
	const void *b,
	mca_num_type_t b_type,
	size_t n);

#endif // !__CSKY_MCA_TEST_HELPER_H__
