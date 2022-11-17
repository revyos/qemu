#include "hardware_test.h"
#include "csky_mca.h"
#include "csky_mca_test_helper.h"

typedef enum {
	VEC_OP_TYPE_ADD,
	VEC_OP_TYPE_MUL,
} vec_op_type_t;

typedef enum {
	SECOND_OP_DATA_TYPE_VECTOR,
	SECOND_OP_DATA_TYPE_SCALAR,
} second_op_data_type_t;

static bool test_mca_vec_compute(mca_num_type_t type, vec_op_type_t op_type,
	second_op_data_type_t second_op_data_type, int8_t output_shift);

bool test_mca_vec_add_vec_fxp8() {
	return test_mca_vec_compute(MCA_FXP8, VEC_OP_TYPE_ADD,
		SECOND_OP_DATA_TYPE_VECTOR, 0);
}

bool test_mca_vec_add_vec_fxp16() {
	return test_mca_vec_compute(MCA_FXP16, VEC_OP_TYPE_ADD,
		SECOND_OP_DATA_TYPE_VECTOR, 0);
}

bool test_mca_vec_add_vec_fxp32() {
	return test_mca_vec_compute(MCA_FXP32, VEC_OP_TYPE_ADD,
		SECOND_OP_DATA_TYPE_VECTOR, 0);
}

bool test_mca_vec_add_scalar_fxp8() {
	return test_mca_vec_compute(MCA_FXP8, VEC_OP_TYPE_ADD,
		SECOND_OP_DATA_TYPE_SCALAR, 0);
}

bool test_mca_vec_add_scalar_fxp16() {
	return test_mca_vec_compute(MCA_FXP16, VEC_OP_TYPE_ADD,
		SECOND_OP_DATA_TYPE_SCALAR, 0);
}

bool test_mca_vec_add_scalar_fxp32() {
	return test_mca_vec_compute(MCA_FXP32, VEC_OP_TYPE_ADD,
		SECOND_OP_DATA_TYPE_SCALAR, 0);
}

bool test_mca_vec_mul_vec_fxp8() {
	return test_mca_vec_compute(MCA_FXP8, VEC_OP_TYPE_MUL,
		SECOND_OP_DATA_TYPE_VECTOR, 7);
}

bool test_mca_vec_mul_vec_fxp16() {
	return test_mca_vec_compute(MCA_FXP16, VEC_OP_TYPE_MUL,
		SECOND_OP_DATA_TYPE_VECTOR, 15);
}

bool test_mca_vec_mul_vec_fxp32() {
	return test_mca_vec_compute(MCA_FXP32, VEC_OP_TYPE_MUL,
		SECOND_OP_DATA_TYPE_VECTOR, 31);
}

bool test_mca_vec_mul_scalar_fxp8() {
	return test_mca_vec_compute(MCA_FXP8, VEC_OP_TYPE_MUL,
		SECOND_OP_DATA_TYPE_SCALAR, 7);
}

bool test_mca_vec_mul_scalar_fxp16() {
	return test_mca_vec_compute(MCA_FXP16, VEC_OP_TYPE_MUL,
		SECOND_OP_DATA_TYPE_SCALAR, 15);
}

bool test_mca_vec_mul_scalar_fxp32() {
	return test_mca_vec_compute(MCA_FXP32, VEC_OP_TYPE_MUL,
		SECOND_OP_DATA_TYPE_SCALAR, 31);
}

static const size_t INPUT_LEN_ARRAY[] = {
	1, 5, 1023, 1024, 2048
};
#define INPUT_LEN_ARRAY_SIZE (sizeof(INPUT_LEN_ARRAY) / sizeof(size_t))

static void gen_mca_vec_compute_golden_data(
	void *params,
	const mca_cache_block_t *cache_blocks,
	void **cache_ptrs);

static bool test_mca_vec_compute_kernal(
	void *params,
	const mca_test_block_t *test_blocks,
	void **block_ptrs);

typedef struct {
	vec_op_type_t op_type;
	second_op_data_type_t second_op_data_type;
	int8_t output_shift;
} mca_vec_compute_params_t;

bool test_mca_vec_compute(mca_num_type_t type, vec_op_type_t op_type,
	second_op_data_type_t second_op_data_type, int8_t output_shift) {
	bool total_passed = true, passed;

	for (size_t i = 0; i < INPUT_LEN_ARRAY_SIZE; ++i) {
		size_t input_b_count =
			second_op_data_type == SECOND_OP_DATA_TYPE_SCALAR
			? 1
			: INPUT_LEN_ARRAY[i];

		mca_cache_block_t cache_blocks[] = {
			// Input a
			{
				.type = type,
				.count = INPUT_LEN_ARRAY[i],
			},
			// Input b
			{
				.type = type,
				.count = input_b_count,
			},
			// Output
			{
				.type = type,
				.count = INPUT_LEN_ARRAY[i],
			},
		};

		mca_test_block_t test_blocks[] = {
			// Input a
			{
				.type = type,
				.count = INPUT_LEN_ARRAY[i],
				.aligns = align_0,
				.io_dir = io_dir_input,
				.cache_index = 0,
				.input_change_allowed = false,
			},
			// Input b
			{
				.type = type,
				.count = input_b_count,
				.aligns = align_0,
				.io_dir = io_dir_input,
				.cache_index = 1,
				.input_change_allowed = false,
			},
			// Output
			{
				.type = type,
				.count = INPUT_LEN_ARRAY[i],
				.aligns = align_0,
				.io_dir = io_dir_output,
				.cache_index = 2,
				.tolerance = 0,
			},
		};

		mca_vec_compute_params_t params = {
			.op_type = op_type,
			.second_op_data_type = second_op_data_type,
			.output_shift = output_shift,
		};

		passed = mca_generic_hardware_test(
			&params,
			gen_mca_vec_compute_golden_data,
			cache_blocks,
			sizeof(cache_blocks) / sizeof(cache_blocks[0]),
			test_mca_vec_compute_kernal,
			test_blocks,
			sizeof(test_blocks) / sizeof(test_blocks[0]));

		if (!passed) {
			print_log("Failed for input size %d.\n", INPUT_LEN_ARRAY[i]);
			total_passed = false;
		}
	}

	return total_passed;
}

void gen_mca_vec_compute_golden_data(
	void *params,
	const mca_cache_block_t *cache_blocks,
	void **cache_ptrs) {
	mca_vec_compute_params_t *tp = (mca_vec_compute_params_t *)params;

	const mca_cache_block_t *input_block = &cache_blocks[0];
	mca_num_type_t data_type = input_block->type;
	size_t block_count = input_block->count;

	void *input_a_ptr = cache_ptrs[0];
	void *input_b_ptr = cache_ptrs[1];
	void *output_ptr = cache_ptrs[2];

	generate_random_data_fxp(input_a_ptr, size_of(data_type), block_count);
	generate_random_data_fxp(input_b_ptr, size_of(data_type), block_count);

	for (size_t i = 0; i < block_count; ++i) {
		fxp128_t sum;
		fxp128_init(&sum);
		switch (tp->op_type) {
		case VEC_OP_TYPE_ADD:
			switch (tp->second_op_data_type) {
			case SECOND_OP_DATA_TYPE_VECTOR:
				switch (data_type) {
				case MCA_FXP32:
					fxp128_add(&sum,
						(fxp64_t)((const fxp32_t *)input_a_ptr)[i] +
						(fxp64_t)((const fxp32_t *)input_b_ptr)[i]);
					break;
				case MCA_FXP16:
					fxp128_add(&sum,
						(fxp32_t)((const fxp16_t *)input_a_ptr)[i] +
						(fxp32_t)((const fxp16_t *)input_b_ptr)[i]);
					break;
				case MCA_FXP8:
					fxp128_add(&sum,
						(fxp32_t)((const fxp8_t *)input_a_ptr)[i] +
						(fxp32_t)((const fxp8_t *)input_b_ptr)[i]);
					break;
				default:
					ASR_ASSERT(false && "Not supported");
					break;
				}
				break;
			case SECOND_OP_DATA_TYPE_SCALAR:
				switch (data_type) {
				case MCA_FXP32:
					fxp128_add(&sum,
						(fxp64_t)((const fxp32_t *)input_a_ptr)[i] +
						(fxp64_t)(*(const fxp32_t *)input_b_ptr));
					break;
				case MCA_FXP16:
					fxp128_add(&sum,
						(fxp32_t)((const fxp16_t *)input_a_ptr)[i] +
						(fxp32_t)(*(const fxp16_t *)input_b_ptr));
					break;
				case MCA_FXP8:
					fxp128_add(&sum,
						(fxp32_t)((const fxp8_t *)input_a_ptr)[i] +
						(fxp32_t)(*(const fxp8_t *)input_b_ptr));
					break;
				default:
					ASR_ASSERT(false && "Not supported");
					break;
				}
				break;
			}
			break;
		case VEC_OP_TYPE_MUL:
			switch (tp->second_op_data_type) {
			case SECOND_OP_DATA_TYPE_VECTOR:
				switch (data_type) {
				case MCA_FXP32:
					fxp128_add(&sum,
						(fxp64_t)((const fxp32_t *)input_a_ptr)[i] *
						(fxp64_t)((const fxp32_t *)input_b_ptr)[i]);
					break;
				case MCA_FXP16:
					fxp128_add(&sum,
						(fxp32_t)((const fxp16_t *)input_a_ptr)[i] *
						(fxp32_t)((const fxp16_t *)input_b_ptr)[i]);
					break;
				case MCA_FXP8:
					fxp128_add(&sum,
						(fxp32_t)((const fxp8_t *)input_a_ptr)[i] *
						(fxp32_t)((const fxp8_t *)input_b_ptr)[i]);
					break;
				default:
					ASR_ASSERT(false && "Not supported");
					break;
				}
				break;
			case SECOND_OP_DATA_TYPE_SCALAR:
				switch (data_type) {
				case MCA_FXP32:
					fxp128_add(&sum,
						(fxp64_t)((const fxp32_t *)input_a_ptr)[i] *
						(fxp64_t)(*(const fxp32_t *)input_b_ptr));
					break;
				case MCA_FXP16:
					fxp128_add(&sum,
						(fxp32_t)((const fxp16_t *)input_a_ptr)[i] *
						(fxp32_t)(*(const fxp16_t *)input_b_ptr));
					break;
				case MCA_FXP8:
					fxp128_add(&sum,
						(fxp32_t)((const fxp8_t *)input_a_ptr)[i] *
						(fxp32_t)(*(const fxp8_t *)input_b_ptr));
					break;
				default:
					ASR_ASSERT(false && "Not supported");
					break;
				}
				break;
			}
			break;
		}
		fxp128_shr(&sum, tp->output_shift);
		fxp128_sat_to(&sum, output_ptr, data_type);
		INC_PTR_VAL_BY_TYPE(output_ptr, data_type);
	}
}

bool test_mca_vec_compute_kernal(
	void *params,
	const mca_test_block_t *test_blocks,
	void **block_ptrs) {
	mca_vec_compute_params_t *tp = (mca_vec_compute_params_t *)params;

	const mca_test_block_t *input_block = &test_blocks[0];
	mca_num_type_t data_type = input_block->type;
	size_t block_count = input_block->count;

	void *input_a_ptr = block_ptrs[0];
	void *input_b_ptr = block_ptrs[1];
	void *output_ptr = block_ptrs[2];

	switch (tp->op_type) {
	case VEC_OP_TYPE_ADD:
		switch (tp->second_op_data_type) {
		case SECOND_OP_DATA_TYPE_VECTOR:
			switch (data_type) {
			case MCA_FXP8:
				csky_mca_vec_add_vec_fxp8(input_a_ptr, input_b_ptr,
					output_ptr, block_count);
				break;
			case MCA_FXP16:
				csky_mca_vec_add_vec_fxp16(input_a_ptr, input_b_ptr,
					output_ptr, block_count);
				break;
			case MCA_FXP32:
				csky_mca_vec_add_vec_fxp32(input_a_ptr, input_b_ptr,
					output_ptr, block_count);
				break;
			default:
				ASR_ASSERT(false && "Not supported");
				break;
			}
			break;
		case SECOND_OP_DATA_TYPE_SCALAR:
			switch (data_type) {
			case MCA_FXP8:
				csky_mca_vec_add_scalar_fxp8(input_a_ptr,
					*(fxp8_t *)input_b_ptr, output_ptr, block_count);
				break;
			case MCA_FXP16:
				csky_mca_vec_add_scalar_fxp16(input_a_ptr,
					*(fxp16_t *)input_b_ptr, output_ptr, block_count);
				break;
			case MCA_FXP32:
				csky_mca_vec_add_scalar_fxp32(input_a_ptr,
					*(fxp32_t *)input_b_ptr, output_ptr, block_count);
				break;
			default:
				ASR_ASSERT(false && "Not supported");
				break;
			}
			break;
		}
		break;
	case VEC_OP_TYPE_MUL:
		switch (tp->second_op_data_type) {
		case SECOND_OP_DATA_TYPE_VECTOR:
			switch (data_type) {
			case MCA_FXP8:
				csky_mca_vec_mul_vec_fxp8(input_a_ptr, input_b_ptr,
					output_ptr, tp->output_shift, block_count);
				break;
			case MCA_FXP16:
				csky_mca_vec_mul_vec_fxp16(input_a_ptr, input_b_ptr,
					output_ptr, tp->output_shift, block_count);
				break;
			case MCA_FXP32:
				csky_mca_vec_mul_vec_fxp32(input_a_ptr, input_b_ptr,
					output_ptr, tp->output_shift, block_count);
				break;
			default:
				ASR_ASSERT(false && "Not supported");
				break;
			}
			break;
		case SECOND_OP_DATA_TYPE_SCALAR:
			switch (data_type) {
			case MCA_FXP8:
				csky_mca_vec_mul_scalar_fxp8(input_a_ptr,
					*(fxp8_t *)input_b_ptr, output_ptr, tp->output_shift,
					block_count);
				break;
			case MCA_FXP16:
				csky_mca_vec_mul_scalar_fxp16(input_a_ptr,
					*(fxp16_t *)input_b_ptr, output_ptr, tp->output_shift,
					block_count);
				break;
			case MCA_FXP32:
				csky_mca_vec_mul_scalar_fxp32(input_a_ptr,
					*(fxp32_t *)input_b_ptr, output_ptr, tp->output_shift,
					block_count);
				break;
			default:
				ASR_ASSERT(false && "Not supported");
				break;
			}
			break;
		}
		break;
	}

	return true;
}
