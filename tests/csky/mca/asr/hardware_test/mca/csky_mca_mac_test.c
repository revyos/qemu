#include "hardware_test.h"
#include "csky_mca.h"
#include "csky_mca_test_helper.h"
#include "csky_vdsp2_nnfunctions.h"

// We cannot test the case of 1024 * 1024 (1 MB) because of memory limit.
static const size_t INPUT_ROW_ARRAY[] = {
	1, /*1024, */3
};
static const size_t INPUT_COL_ARRAY[] = {
	16, /*16, */1024
};
#define INPUT_ROW_COL_ARRAY_SIZE (sizeof(INPUT_ROW_ARRAY) / sizeof(size_t))

// We can test 1024 rows for 8-bit input.
static const size_t INPUT_ROW_ARRAY_8BIT[] = {
	1, 1024, 3
};
static const size_t INPUT_COL_ARRAY_8BIT[] = {
	16, 16, 1024
};
#define INPUT_ROW_COL_ARRAY_8BIT_SIZE \
	(sizeof(INPUT_ROW_ARRAY_8BIT) / sizeof(size_t))

// Number of columns more than 1024.
static const size_t INPUT_ROW_ARRAY_NOT_LIMITED[] = {
	1, 1024, 3, 2, 2,
};
static const size_t INPUT_COL_ARRAY_NOT_LIMITED[] = {
	16, 16, 1024, 2048, 3056,
};
#define INPUT_ROW_COL_ARRAY_NOT_LIMITED_SIZE \
	(sizeof(INPUT_ROW_ARRAY_NOT_LIMITED) / sizeof(size_t))

static bool test_mca_mac(
	const size_t *num_rows_array,
	const size_t *num_cols_array,
	size_t num_row_col_array_size,
	mca_num_type_t vec_mat_type,
	mca_num_type_t output_type,
	int8_t output_shift,
	bool has_bias,
	mca_num_type_t bias_type,
	int8_t bias_shift,
	bool has_relu);

bool test_mca_mat_mul_vec_fxp8() {
	return test_mca_mac(
		INPUT_ROW_ARRAY_8BIT,
		INPUT_COL_ARRAY_8BIT,
		INPUT_ROW_COL_ARRAY_8BIT_SIZE,
		MCA_FXP8,
		MCA_FXP8,
		7,
		false,
		MCA_FXP8,
		0,
		false);
}

bool test_mca_mat_mul_vec_fxp16() {
	return test_mca_mac(
		INPUT_ROW_ARRAY,
		INPUT_COL_ARRAY,
		INPUT_ROW_COL_ARRAY_SIZE,
		MCA_FXP16,
		MCA_FXP16,
		15,
		false,
		MCA_FXP16,
		0,
		false);
}

bool test_mca_mat_mul_vec_fxp32() {
	return test_mca_mac(
		INPUT_ROW_ARRAY,
		INPUT_COL_ARRAY,
		INPUT_ROW_COL_ARRAY_SIZE,
		MCA_FXP32,
		MCA_FXP32,
		31,
		false,
		MCA_FXP32,
		0,
		false);
}

bool test_mca_mat_mul_vec_v8_m8_o32() {
	return test_mca_mac(
		INPUT_ROW_ARRAY_NOT_LIMITED,
		INPUT_COL_ARRAY_NOT_LIMITED,
		INPUT_ROW_COL_ARRAY_NOT_LIMITED_SIZE,
		MCA_FXP8,
		MCA_FXP32,
		0,
		false,
		MCA_FXP8,
		0,
		false);
}

bool test_mca_fully_connected_fxp8() {
	return test_mca_mac(
		INPUT_ROW_ARRAY_8BIT,
		INPUT_COL_ARRAY_8BIT,
		INPUT_ROW_COL_ARRAY_8BIT_SIZE,
		MCA_FXP8,
		MCA_FXP8,
		7,
		true,
		MCA_FXP8,
		7,
		false);
}

bool test_mca_fully_connected_fxp16() {
	return test_mca_mac(
		INPUT_ROW_ARRAY,
		INPUT_COL_ARRAY,
		INPUT_ROW_COL_ARRAY_SIZE,
		MCA_FXP16,
		MCA_FXP16,
		15,
		true,
		MCA_FXP16,
		15,
		false);
}

bool test_mca_fully_connected_v8_m8_b8_o32() {
	return test_mca_mac(
		INPUT_ROW_ARRAY_NOT_LIMITED,
		INPUT_COL_ARRAY_NOT_LIMITED,
		INPUT_ROW_COL_ARRAY_NOT_LIMITED_SIZE,
		MCA_FXP8,
		MCA_FXP32,
		0,
		true,
		MCA_FXP8,
		7,
		false);
}

bool test_mca_fully_connected_v8_m8_b16_o32() {
	return test_mca_mac(
		INPUT_ROW_ARRAY_NOT_LIMITED,
		INPUT_COL_ARRAY_NOT_LIMITED,
		INPUT_ROW_COL_ARRAY_NOT_LIMITED_SIZE,
		MCA_FXP8,
		MCA_FXP32,
		0,
		true,
		MCA_FXP16,
		0,
		false);
}

bool test_mca_fully_connected_with_relu_fxp8() {
	return test_mca_mac(
		INPUT_ROW_ARRAY_8BIT,
		INPUT_COL_ARRAY_8BIT,
		INPUT_ROW_COL_ARRAY_8BIT_SIZE,
		MCA_FXP8,
		MCA_FXP8,
		7,
		true,
		MCA_FXP8,
		7,
		true);
}

bool test_mca_fully_connected_with_relu_fxp16() {
	return test_mca_mac(
		INPUT_ROW_ARRAY,
		INPUT_COL_ARRAY,
		INPUT_ROW_COL_ARRAY_SIZE,
		MCA_FXP16,
		MCA_FXP16,
		15,
		true,
		MCA_FXP16,
		15,
		true);
}

bool test_mca_fully_connected_with_relu_v8_m8_b8_o32() {
	return test_mca_mac(
		INPUT_ROW_ARRAY_NOT_LIMITED,
		INPUT_COL_ARRAY_NOT_LIMITED,
		INPUT_ROW_COL_ARRAY_NOT_LIMITED_SIZE,
		MCA_FXP8,
		MCA_FXP32,
		0,
		true,
		MCA_FXP8,
		7,
		true);
}

bool test_mca_fully_connected_with_relu_v8_m8_b16_o32() {
		return test_mca_mac(
		INPUT_ROW_ARRAY_NOT_LIMITED,
		INPUT_COL_ARRAY_NOT_LIMITED,
		INPUT_ROW_COL_ARRAY_NOT_LIMITED_SIZE,
		MCA_FXP8,
		MCA_FXP32,
		0,
		true,
		MCA_FXP16,
		0,
		true);
}

static void gen_mca_mac_golden_data(
	void *params,
	const mca_cache_block_t *cache_blocks,
	void **cache_ptrs);

static bool test_mca_mac_kernal(
	void *params,
	const mca_test_block_t *test_blocks,
	void **block_ptrs);

typedef struct {
	size_t num_rows;
	size_t num_cols;
	mca_num_type_t vec_mat_type;
	mca_num_type_t output_type;
	int8_t output_shift;
	bool has_bias;
	mca_num_type_t bias_type;
	int8_t bias_shift;
	bool has_relu;
} mca_mac_test_params_t;

bool test_mca_mac(
	const size_t *num_rows_array,
	const size_t *num_cols_array,
	size_t num_row_col_array_size,
	mca_num_type_t vec_mat_type,
	mca_num_type_t output_type,
	int8_t output_shift,
	bool has_bias,
	mca_num_type_t bias_type,
	int8_t bias_shift,
	bool has_relu) {
	bool total_passed = true, passed;

	for (size_t i = 0; i < num_row_col_array_size; ++i) {
		mca_cache_block_t cache_blocks[] = {
			// Input vec
			{
				.type = vec_mat_type,
				.count = num_cols_array[i],
			},
			// Input mat
			{
				.type = vec_mat_type,
				.count = num_cols_array[i] * num_rows_array[i],
			},
			// Input bias
			{
				.type = bias_type,
				.count = num_rows_array[i],
			},
			// Output
			{
				.type = output_type,
				.count = num_rows_array[i],
			},
		};

		mca_test_block_t test_blocks[] = {
			// Input vec
			{
				.type = vec_mat_type,
				.count = num_cols_array[i],
				.aligns = align_0,
				.io_dir = io_dir_input,
				.cache_index = 0,
				.input_change_allowed = false,
			},
			// Input mat
			{
				.type = vec_mat_type,
				.count = num_cols_array[i] * num_rows_array[i],
				.aligns = align_0,
				.io_dir = io_dir_input,
				.cache_index = 1,
				.input_change_allowed = false,
			},
			// Input bias
			{
				.type = bias_type,
				.count = num_rows_array[i],
				.aligns = align_0,
				.io_dir = io_dir_input,
				.cache_index = 2,
				.input_change_allowed = false,
			},
			// Output
			{
				.type = output_type,
				.count = num_rows_array[i],
				.aligns = align_0,
				.io_dir = io_dir_output,
				.cache_index = 3,
				.tolerance = 0,
			},
		};

		mca_mac_test_params_t params = {
			.num_rows = num_rows_array[i],
			.num_cols = num_cols_array[i],
			.vec_mat_type = vec_mat_type,
			.output_type = output_type,
			.output_shift = output_shift,
			.has_bias = has_bias,
			.bias_type = bias_type,
			.bias_shift = bias_shift,
			.has_relu = has_relu,
		};

		passed = mca_generic_hardware_test(
			&params,
			gen_mca_mac_golden_data,
			cache_blocks,
			sizeof(cache_blocks) / sizeof(cache_blocks[0]),
			test_mca_mac_kernal,
			test_blocks,
			sizeof(test_blocks) / sizeof(test_blocks[0]));

		if (!passed) {
			print_log("Failed for num_rows = %d, num_cols = %d.\n",
				num_rows_array[i], num_cols_array[i]);
			total_passed = false;
		}
	}

	return total_passed;
}

static void golden_mac(
	const void *vec,
	const void *mat,
	size_t num_cols,
	size_t num_rows,
	int8_t bias_shift,
	int8_t out_shift,
	const void *bias,
	void *out,
	bool with_relu,
	mca_num_type_t vec_mat_type,
	mca_num_type_t bias_type,
	mca_num_type_t out_type) {
	for (size_t o_index = 0; o_index < num_rows; ++o_index) {
		fxp128_t sum;
		fxp128_init(&sum);

		// multiply & accumulate
		fxp128_mac(&sum, mat, vec, vec_mat_type, num_cols);
		INC_PTR_VAL_BY_SIZE(mat, size_of(vec_mat_type) * num_cols);

		// add bias
		if (NULL != bias) {
			fxp64_t bias_val;
			switch (bias_type) {
			case MCA_FXP8:
				bias_val = ((const fxp8_t *)bias)[o_index];
				break;
			case MCA_FXP16:
				bias_val = ((const fxp16_t *)bias)[o_index];
				break;
			case MCA_FXP32:
				bias_val = ((const fxp32_t *)bias)[o_index];
				break;
			default:
				bias_val = ((const fxp64_t *)bias)[o_index];
				break;
			}
			if (bias_shift > 0) {
				bias_val <<= bias_shift;
			}
			else {
				bias_val >>= -bias_shift;
			}
			fxp128_add(&sum, bias_val);
		}

		// shift
		if (out_shift > 0) {
			fxp128_shr(&sum, out_shift);
		}
		else {
			fxp128_shl(&sum, -out_shift);
		}

		// relu
		if (with_relu && sum.hi.s < 0) {
			fxp128_init(&sum);
		}

		// saturation
		fxp128_sat_to(&sum, out, out_type);
		INC_PTR_VAL_BY_TYPE(out, out_type);
	}
}

void gen_mca_mac_golden_data(
	void *params,
	const mca_cache_block_t *cache_blocks,
	void **cache_ptrs) {
	mca_mac_test_params_t *tp = (mca_mac_test_params_t *)params;

	void *vec_ptr = cache_ptrs[0];
	void *mat_ptr = cache_ptrs[1];
	void *bias_ptr = cache_ptrs[2];
	void *out_ptr = cache_ptrs[3];

	generate_random_data_fxp(vec_ptr, size_of(tp->vec_mat_type), tp->num_cols);
	generate_random_data_fxp(mat_ptr, size_of(tp->vec_mat_type),
		tp->num_cols * tp->num_rows);
	if (tp->has_bias) {
		generate_random_data_fxp(bias_ptr, size_of(tp->vec_mat_type),
			tp->num_rows);
	}

	golden_mac(vec_ptr, mat_ptr, tp->num_cols, tp->num_rows, tp->bias_shift,
		tp->output_shift, tp->has_bias ? bias_ptr : NULL, out_ptr, tp->has_relu,
		tp->vec_mat_type, tp->bias_type, tp->output_type);
}

bool test_mca_mac_kernal(
	void *params,
	const mca_test_block_t *test_blocks,
	void **block_ptrs) {
	mca_mac_test_params_t *tp = (mca_mac_test_params_t *)params;

	void *vec_ptr = block_ptrs[0];
	void *mat_ptr = block_ptrs[1];
	void *bias_ptr = block_ptrs[2];
	void *out_ptr = block_ptrs[3];

	if (tp->has_bias) {
		if (tp->output_type == MCA_FXP32) {
			if (tp->bias_type == MCA_FXP8) {
				if (tp->has_relu) {
					csky_mca_fully_connected_with_relu_v8_m8_b8_o32(vec_ptr,
						mat_ptr, tp->num_cols, tp->num_rows, bias_ptr,
						tp->bias_shift, out_ptr, tp->output_shift);
				} else {
					csky_mca_fully_connected_v8_m8_b8_o32(vec_ptr, mat_ptr,
						tp->num_cols, tp->num_rows, bias_ptr, tp->bias_shift,
						out_ptr, tp->output_shift);
				}
			} else {
				if (tp->has_relu) {
					csky_mca_fully_connected_with_relu_v8_m8_b16_o32(vec_ptr,
						mat_ptr, tp->num_cols, tp->num_rows, bias_ptr,
						tp->bias_shift, out_ptr, tp->output_shift);
				} else {
					csky_mca_fully_connected_v8_m8_b16_o32(vec_ptr, mat_ptr,
						tp->num_cols, tp->num_rows, bias_ptr, tp->bias_shift,
						out_ptr, tp->output_shift);
				}
			}
		} else {
			if (tp->vec_mat_type == MCA_FXP8) {
				if (tp->has_relu) {
					csky_mca_fully_connected_with_relu_fxp8(vec_ptr, mat_ptr,
						tp->num_cols, tp->num_rows, bias_ptr, tp->bias_shift,
						out_ptr, tp->output_shift);
				} else {
					csky_mca_fully_connected_fxp8(vec_ptr, mat_ptr,
						tp->num_cols, tp->num_rows, bias_ptr, tp->bias_shift,
						out_ptr, tp->output_shift);
				}
			} else {
				if (tp->has_relu) {
					csky_mca_fully_connected_with_relu_fxp16(vec_ptr, mat_ptr,
						tp->num_cols, tp->num_rows, bias_ptr, tp->bias_shift,
						out_ptr, tp->output_shift);
				} else {
					csky_mca_fully_connected_fxp16(vec_ptr, mat_ptr,
						tp->num_cols, tp->num_rows, bias_ptr, tp->bias_shift,
						out_ptr, tp->output_shift);			
				}
			}
		}
	} else {
		if (tp->output_type == MCA_FXP32) {
			if (tp->vec_mat_type == MCA_FXP32) {
				csky_mca_mat_mul_vec_fxp32(vec_ptr, mat_ptr, tp->num_cols,
					tp->num_rows, out_ptr, tp->output_shift);
			} else {
				csky_mca_mat_mul_vec_v8_m8_o32(vec_ptr, mat_ptr, tp->num_cols,
					tp->num_rows, out_ptr, tp->output_shift);
			}
		} else {
			if (tp->vec_mat_type == MCA_FXP8) {
				csky_mca_mat_mul_vec_fxp8(vec_ptr, mat_ptr, tp->num_cols,
					tp->num_rows, out_ptr, tp->output_shift);
			} else {
				csky_mca_mat_mul_vec_fxp16(vec_ptr, mat_ptr, tp->num_cols,
					tp->num_rows, out_ptr, tp->output_shift);
			}
		}
	}

	return true;
}
