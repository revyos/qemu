#include "hardware_test.h"
#include "csky_mca.h"
#include "csky_mca_test_helper.h"

static bool test_mca_fir(mca_num_type_t io_type, mca_num_type_t coeff_type);

bool test_mca_fir_fxp32() {
	return test_mca_fir(MCA_FXP32, MCA_FXP32);
}

bool test_mca_fir_fxp24() {
	return test_mca_fir(MCA_FXP24, MCA_FXP32);
}

bool test_mca_fir_fxp16() {
	return test_mca_fir(MCA_FXP16, MCA_FXP32);
}

bool test_mca_fir_fxp32_coeff64() {
	return test_mca_fir(MCA_FXP32, MCA_FXP64);
}

bool test_mca_fir_fxp24_coeff64() {
	return test_mca_fir(MCA_FXP24, MCA_FXP64);
}

bool test_mca_fir_fxp16_coeff64() {
	return test_mca_fir(MCA_FXP16, MCA_FXP64);
}

/* Golden FIR filter. */
static void golden_fir(
	mca_num_type_t io_type,
	const void *input, size_t input_size,
	const void *coeff, size_t order, mca_num_type_t coeff_type,
	void *output, uint8_t output_loc_sel) {
	for (size_t o_idx = 0; o_idx + order < input_size; ++o_idx) {
		const void *coeff_ptr = coeff;

		fxp128_t sum;
		fxp128_init(&sum);

		fxp128_mac_diff_types(&sum, input, io_type, coeff_ptr, coeff_type,
			order + 1);

		// Q1.7.24 or Q1.15.48
		uint8_t q_output = coeff_type == MCA_FXP32 ? 24 : (output_loc_sel * 4);
		fxp128_round(&sum, q_output);
		fxp128_shr(&sum, q_output);
		fxp128_sat_to(&sum, output, io_type);

		INC_PTR_VAL_BY_TYPE(output, io_type);
		INC_PTR_VAL_BY_TYPE(input, io_type);
	}
}

// Q1.31.0
static const fxp32_t INPUT_SAMPLES[] TEST_DATA_ATTR = {
	0x00000000, 0x4d3ea0bb, 0x53a7a333, 0x3cae6280, 0x40000000, 0x39934cbd,
	0x06dad667, 0xe3bd2492, 0x00000000, 0x1c42db6e, 0xf9252999, 0xc66cb343,
	0xc0000000, 0xc3519d80, 0xac585ccd, 0xb2c15f45, 0x00000000, 0x4d3ea0bb,
	0x53a7a333, 0x3cae6280, 0x40000000, 0x39934cbd, 0x06dad667, 0xe3bd2492,
	0x00000000, 0x1c42db6e, 0xf9252999, 0xc66cb343, 0xc0000000, 0xc3519d80,
	0xac585ccd, 0xb2c15f45, 0x00000000, 0x4d3ea0bb, 0x53a7a333, 0x3cae6280,
	0x40000000, 0x39934cbd, 0x06dad667, 0xe3bd2492, 0x00000000, 0x1c42db6e,
	0xf9252999, 0xc66cb343, 0xc0000000, 0xc3519d80, 0xac585ccd, 0xb2c15f45,
	0x00000000, 0x4d3ea0bb, 0x53a7a333, 0x3cae6280, 0x40000000, 0x39934cbd,
	0x06dad667, 0xe3bd2492, 0x00000000, 0x1c42db6e, 0xf9252999, 0xc66cb343,
	0xc0000000, 0xc3519d80, 0xac585ccd, 0xb2c15f45,
};

// Q1.15.48
static const fxp64_t FIR_COEFF[] TEST_DATA_ATTR = {
	0xffffff233ecb0800, 0xffffff0331d06000, 0xffffffa68154b000,
	0x0000038558ee9f1b, 0x00000c84c51ede38, 0x000019e50af39f5d,
	0x000027b621bb023f, 0x0000308dc353cd70, 0x0000308dc353cd70,
	0x000027b621bb023f, 0x000019e50af39f5d, 0x00000c84c51ede38,
	0x0000038558ee9f1b, 0xffffffa68154b000, 0xffffff0331d06000,
	0xffffff233ecb0800,
};

typedef struct {
	const fxp32_t *raw_input;
	const fxp64_t *raw_coeff;
	size_t order;
	uint8_t output_loc_sel;
} mca_fir_test_params;

static void gen_mca_fir_golden_data(
	void *params,
	const mca_cache_block_t *cache_blocks,
	void **cache_ptrs) {
	mca_fir_test_params *tp = params;

	const mca_cache_block_t *input_block = &cache_blocks[0];
	void *input_ptr = cache_ptrs[0];
	const mca_cache_block_t *coeff_block = &cache_blocks[1];
	void *coeff_ptr = cache_ptrs[1];
	void *output_ptr = cache_ptrs[2];

	switch (input_block->type) {
	case MCA_FXP32:
		asr_memcpy(input_ptr, tp->raw_input,
			size_of(input_block->type) * input_block->count);
		break;
	case MCA_FXP24:
		for (size_t i = 0; i < input_block->count; ++i) {
			((fxp32_t *)input_ptr)[i] = tp->raw_input[i] >> 8;
		}
		break;
	case MCA_FXP16:
		for (size_t i = 0; i < input_block->count; ++i) {
			((fxp16_t *)input_ptr)[i] = (fxp16_t)(tp->raw_input[i] >> 16);
		}
		break;
	case MCA_FXP16_32BIT:
	case MCA_FXP64:
	case MCA_FXP8:
	default:
		ASR_ASSERT("IO type not implemented.");
		break;
	}

	switch (coeff_block->type) {
	case MCA_FXP64:
		asr_memcpy(coeff_ptr, tp->raw_coeff,
			size_of(coeff_block->type) * coeff_block->count);
		break;
	case MCA_FXP32:
		for (size_t i = 0; i < coeff_block->count; ++i) {
			((fxp32_t *)coeff_ptr)[i] = (fxp32_t)(tp->raw_coeff[i] >> 24);
		}
		break;
	default:
		break;
	}

	golden_fir(
		input_block->type,
		input_ptr, input_block->count,
		coeff_ptr, tp->order, coeff_block->type,
		output_ptr, tp->output_loc_sel);
}

static void mca_fir_config_wrapper(
	mca_num_type_t io_type,
	mca_num_type_t coeff_type,
	const void *coeff,
	size_t order,
	uint8_t output_loc_sel) {
	if (coeff_type == MCA_FXP64) {
		switch (io_type) {
		case MCA_FXP32:
			csky_mca_fir_fxp32_coeff64_config(coeff, order,
				output_loc_sel << 2);
			break;
		case MCA_FXP24:
			csky_mca_fir_fxp24_coeff64_config(coeff, order,
				output_loc_sel << 2);
			break;
		case MCA_FXP16:
			csky_mca_fir_fxp16_coeff64_config(coeff, order,
				output_loc_sel << 2);
			break;
		case MCA_FXP16_32BIT:
		case MCA_FXP64:
		case MCA_FXP8:
		default:
			ASR_ASSERT("IO type not implemented.");
			break;
		}
	}
	else {
		switch (io_type) {
		case MCA_FXP32:
			csky_mca_fir_fxp32_coeff32_config(coeff, order);
			break;
		case MCA_FXP24:
			csky_mca_fir_fxp24_coeff32_config(coeff, order);
			break;
		case MCA_FXP16:
			csky_mca_fir_fxp16_coeff32_config(coeff, order);
			break;
		case MCA_FXP16_32BIT:
		case MCA_FXP64:
		case MCA_FXP8:
		default:
			ASR_ASSERT("IO type not implemented.");
			break;
		}
	}
}

static void mca_fir_wrapper(
	mca_num_type_t io_type,
	const void *input,
	size_t input_size,
	void *output) {
	switch (io_type) {
	case MCA_FXP32:
		csky_mca_fir_fxp32(input, input_size, output);
		break;
	case MCA_FXP24:
		csky_mca_fir_fxp24(input, input_size, output);
		break;
	case MCA_FXP16:
		csky_mca_fir_fxp16(input, input_size, output);
		break;
	case MCA_FXP16_32BIT:
	case MCA_FXP64:
	case MCA_FXP8:
	default:
		ASR_ASSERT("IO type not implemented.");
		break;
	}
}

static bool test_mca_fir_kernal(
	void *params,
	const mca_test_block_t *test_blocks,
	void **block_ptrs) {
	mca_fir_test_params *tp = params;

	const mca_test_block_t *input_block = &test_blocks[0];
	void *input_ptr = block_ptrs[0];
	const mca_test_block_t *coeff_block = &test_blocks[1];
	void *coeff_ptr = block_ptrs[1];
	void *output_single_shot_ptr = block_ptrs[2];
	const mca_test_block_t *output_block_continuous = &test_blocks[3];
	void *output_continuous_ptr = block_ptrs[3];

	// Single-shot filtering	
	mca_fir_config_wrapper(input_block->type, coeff_block->type,
		coeff_ptr, tp->order, tp->output_loc_sel);

	mca_fir_wrapper(
		input_block->type,
		input_ptr,
		input_block->count,
		output_single_shot_ptr);

	// Continuous filtering	
	const size_t new_samples_per_loop = 20; // Should be greater than FIR_ORDER.
	const size_t ideal_input_size = new_samples_per_loop + tp->order;

	mca_fir_config_wrapper(input_block->type, coeff_block->type,
		coeff_ptr, tp->order, tp->output_loc_sel);

	size_t sample_index = 0;
	while (sample_index < input_block->count) {
		size_t actual_input_size = MIN(ideal_input_size,
			input_block->count - sample_index);
		if (actual_input_size <= tp->order) {
			break;
		}

		mca_fir_wrapper(
			input_block->type,
			input_ptr,
			actual_input_size,
			output_continuous_ptr);

		sample_index += new_samples_per_loop;
		INC_PTR_VAL_BY_SIZE(input_ptr,
			size_of(input_block->type) * new_samples_per_loop);

		INC_PTR_VAL_BY_SIZE(output_continuous_ptr,
			size_of(output_block_continuous->type) *new_samples_per_loop);
	}

	return true;
}

bool test_mca_fir(mca_num_type_t io_type, mca_num_type_t coeff_type) {
	size_t num_fir_coeff = 
		sizeof(FIR_COEFF) / sizeof(FIR_COEFF[0]);
	size_t fir_order = num_fir_coeff - 1;
	size_t num_input_samples = 
		sizeof(INPUT_SAMPLES) / sizeof(INPUT_SAMPLES[0]);
	// Adds zeros to the front of input samples.
	size_t num_input_samples_padded = num_input_samples + fir_order;
	size_t num_output_samples = num_input_samples;

	fxp32_t *input_samples_with_zeros =
		fast_malloc(sizeof(fxp32_t) * num_input_samples_padded);
	memset(input_samples_with_zeros, 0, sizeof(fxp32_t) * fir_order);
	asr_memcpy(input_samples_with_zeros + fir_order, INPUT_SAMPLES,
		sizeof(fxp32_t) * num_input_samples);

	mca_cache_block_t cache_blocks[] = {
		// Input
		{
			.type = io_type,
			.count = num_input_samples_padded,
		},
		// Coefficients
		{
			.type = coeff_type,
			.count = num_fir_coeff,
		},
		// Output
		{
			.type = io_type,
			.count = num_output_samples,
		},
	};

	mca_test_block_t test_blocks[] = {
		// Input
		{
			.type = io_type,
			.count = num_input_samples_padded,
			.aligns = align_any,
			.io_dir = io_dir_input,
			.cache_index = 0,
			.input_change_allowed = false,
		},
		// Coefficients
		{
			.type = coeff_type,
			.count = num_fir_coeff,
			.aligns = align_any,
			.io_dir = io_dir_input,
			.cache_index = 1,
			.input_change_allowed = false,
		},
		// Output: single-shot
		{
			.type = io_type,
			.count = num_output_samples,
			.aligns = align_any,
			.io_dir = io_dir_output,
			.cache_index = 2,
			.tolerance = 0,
		},
		// Output: continuous
		{
			.type = io_type,
			.count = num_output_samples,
			.aligns = align_any,
			.io_dir = io_dir_output,
			.cache_index = 2,
			.tolerance = 0,
		},
	};

	mca_fir_test_params params = {
		.raw_input = INPUT_SAMPLES,
		.raw_coeff = FIR_COEFF,
		.order = fir_order,
		.output_loc_sel = 13, // 12 for 32-bit coefficients
	};

	bool passed = mca_generic_hardware_test(
		&params,
		gen_mca_fir_golden_data,
		cache_blocks,
		sizeof(cache_blocks) / sizeof(cache_blocks[0]),
		test_mca_fir_kernal,
		test_blocks,
		sizeof(test_blocks) / sizeof(test_blocks[0]));

	fast_free(input_samples_with_zeros);

	return passed;
}
