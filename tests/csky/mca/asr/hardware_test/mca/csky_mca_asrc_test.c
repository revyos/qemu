#include "hardware_test.h"
#include "csky_mca.h"
#include "csky_mca_test_helper.h"

static bool test_mca_asrc(mca_num_type_t io_type, size_t num_channels);

bool test_mca_asrc_stereo_fxp32() {
	return test_mca_asrc(MCA_FXP32, 2);
}

bool test_mca_asrc_stereo_fxp24() {
	return test_mca_asrc(MCA_FXP24, 2);
}

bool test_mca_asrc_stereo_fxp16() {
	return test_mca_asrc(MCA_FXP16, 2);
}

bool test_mca_asrc_mono_fxp32() {
	return test_mca_asrc(MCA_FXP32, 1);
}

bool test_mca_asrc_mono_fxp24() {
	return test_mca_asrc(MCA_FXP24, 1);
}

bool test_mca_asrc_mono_fxp16() {
	return test_mca_asrc(MCA_FXP16, 1);
}

/* ASRC internal state. */
static const fxp32_t *g_asrc_coeff;
static size_t g_asrc_order;
static size_t g_asrc_list_size;
static size_t g_asrc_coeff_index;

/* Golden ASRC config. */
static void golden_asrc_config(
	const fxp32_t *coeff,
	size_t order,
	size_t list_size) {
	g_asrc_coeff = coeff;
	g_asrc_order = order;
	g_asrc_list_size = list_size;

	g_asrc_coeff_index = 0;
}

/* Golden ASRC body. */
static size_t golden_asrc(
	mca_num_type_t io_type,
	size_t num_channels,
	const void *input_channels[],
	size_t input_size,
	void *output) {
	size_t output_sample_size_in_byte = 0;

	size_t input_offset = 0;
	while (true) {
		if (input_offset + g_asrc_order + 1 > input_size) {
			break;
		}

		const fxp32_t *coeff =
			g_asrc_coeff + (g_asrc_order + 2) * g_asrc_coeff_index;
		for (size_t ch_idx = 0; ch_idx < num_channels; ++ch_idx) {
			fxp128_t sum;
			fxp128_init(&sum);

			const void *input = (char *)input_channels[ch_idx] +
				input_offset * size_of(io_type);
			fxp128_mac_diff_types(&sum,
				input, io_type,
				coeff, MCA_FXP32,
				g_asrc_order + 1);

			uint8_t q_output = 31; // Q1.0.31
			fxp128_round(&sum, q_output);
			fxp128_shr(&sum, q_output);
			fxp128_sat_to(&sum, output, io_type);
			INC_PTR_VAL_BY_TYPE(output, io_type);
			output_sample_size_in_byte += size_of(io_type);
		}

		// Increases input offset by step for next output sample.
		input_offset += coeff[g_asrc_order + 1];

		// Next row of coefficients.
		++g_asrc_coeff_index;
		if (g_asrc_coeff_index == g_asrc_list_size) {
			g_asrc_coeff_index = 0;
		}
	}

	return output_sample_size_in_byte;
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

// Q1.0.31, direct output, no frequency change
static const fxp32_t ASRC_NOT_CHANGED_COEFF[] TEST_DATA_ATTR = {
	0x7fffffff, 1,
};
#define ASRC_NOT_CHANGED_ORDER 0

// Q1.0.31, linear interpolation
static const fxp32_t ASRC_UP_SAMPLE_COEFF[] TEST_DATA_ATTR = {
	0x7fffffff, 0x00000000, 0,
	0x0e38e38e, 0x71c71c72, 1,
	0x1c71c71c, 0x638e38e4, 1,
	0x2aaaaaab, 0x55555555, 1,
	0x38e38e39, 0x471c71c7, 1,
	0x471c71c7, 0x38e38e39, 1,
	0x55555555, 0x2aaaaaab, 1,
	0x638e38e4, 0x1c71c71c, 1,
	0x71c71c72, 0x0e38e38e, 1,
};
#define ASRC_UP_SAMPLE_ORDER 1

// Q1.0.31, FIR lowpass filter + linear interpolation
static const fxp32_t ASRC_DOWN_SAMPLE_COEFF[] TEST_DATA_ATTR = {
	0xff8057cd, 0xfbdde750, 0x44a1c0e3, 0x44a1c0e3, 0xfbdde750, 0xff8057cd,
	0x00000000, 1,
	0xffaae533, 0xfd140ccf, 0x2c60785d, 0x44a1c0e3, 0x141f2fd7, 0xfe4a324e,
	0xffd5729a, 1,
	0xffd5729a, 0xfe4a324e, 0x141f2fd7, 0x44a1c0e3, 0x2c60785d, 0xfd140ccf,
	0xffaae533, 2,
};
#define ASRC_DOWN_SAMPLE_ORDER 6

#define LIST_SIZE_OF(coeff, order) \
	(sizeof(coeff) / sizeof(coeff[0]) / (order + 2))

// Refers to doc in csky_mca.h.
static void optimize_asrc_for_continuous_resample(
	const fxp32_t *coeff,
	size_t order,
	size_t list_size,
	size_t *num_old_samples_per_loop,
	size_t *num_new_samples_per_loop) {
	size_t index_last_sample_current_loop = order;
	size_t index_first_sample_next_loop = 0;
	for (size_t i = 0; i < list_size; ++i) {
		size_t step = coeff[i * (order + 2) + order + 1];
		if (i + 1 < list_size) {
			index_last_sample_current_loop += step;
		}
		index_first_sample_next_loop += step;
	}
	if (index_last_sample_current_loop < index_first_sample_next_loop) {
		*num_new_samples_per_loop = index_first_sample_next_loop;
		*num_old_samples_per_loop = 0;
	}
	else {
		*num_new_samples_per_loop = index_first_sample_next_loop;
		*num_old_samples_per_loop = 1 +
			index_last_sample_current_loop - index_first_sample_next_loop;
	}
}

static size_t get_num_output_samples(
	const fxp32_t *coeff,
	size_t order,
	size_t list_size,
	size_t num_channels,
	size_t input_size) {
	size_t num_output_samples = 0;
	size_t input_offset = 0;
	size_t coeff_index = 0;
	while (true) {
		if (input_offset + order + 1 > input_size) {
			break;
		}

		const fxp32_t *coeff_ptr = coeff + (order + 2) * coeff_index;
		num_output_samples += num_channels;

		input_offset += coeff_ptr[order + 1];

		++coeff_index;
		if (coeff_index == list_size) {
			coeff_index = 0;
		}
	}
	return num_output_samples;
}

typedef struct {
	size_t num_channels;

	size_t order;
	size_t list_size;

	size_t num_old_samples_per_loop;
	size_t num_new_samples_per_loop;

	// Q1.0.31
	const fxp32_t *raw_coeff;

	// Q1.31.0
	const fxp32_t *raw_input;

	size_t output_sample_size_in_byte;
} mca_asrc_test_params;

static void gen_mca_asrc_golden_data(
	void *params,
	const mca_cache_block_t *cache_blocks,
	void **cache_ptrs) {
	mca_asrc_test_params *tp = params;

	mca_num_type_t io_type = cache_blocks[0].type;
	size_t input_size = cache_blocks[0].count;

	void **input_ptrs = cache_ptrs;
	void *coeff_ptr = NULL;
	void *output_ptr = NULL;
	size_t ptr_index;
	for (ptr_index = 0; ptr_index < tp->num_channels; ++ptr_index) {
		input_ptrs[ptr_index] = cache_ptrs[ptr_index];
		switch (cache_blocks[ptr_index].type) {
		case MCA_FXP32:
			for (size_t i = 0; i < cache_blocks[ptr_index].count; ++i) {
				((fxp32_t *)input_ptrs[ptr_index])[i]
					= tp->raw_input[i] >> ptr_index;
			}
			break;
		case MCA_FXP24:
			for (size_t i = 0; i < cache_blocks[ptr_index].count; ++i) {
				((fxp32_t *)input_ptrs[ptr_index])[i]
					= tp->raw_input[i] >> (8 + ptr_index);
			}
			break;
		case MCA_FXP16:
			for (size_t i = 0; i < cache_blocks[ptr_index].count; ++i) {
				((fxp16_t *)input_ptrs[ptr_index])[i]
					= (fxp16_t)(tp->raw_input[i] >> (16 + ptr_index));
			}
			break;
		case MCA_FXP16_32BIT:
		case MCA_FXP64:
		case MCA_FXP8:
		default:
			ASR_ASSERT("IO type not implemented.");
			break;
		}
	}
	coeff_ptr = cache_ptrs[ptr_index++];
	output_ptr = cache_ptrs[ptr_index++];

	size_t coeff_size = sizeof(fxp32_t) * (tp->order + 2) * tp->list_size;
	asr_memcpy(coeff_ptr, tp->raw_coeff, coeff_size);

	golden_asrc_config(coeff_ptr, tp->order, tp->list_size);
	golden_asrc(io_type, tp->num_channels, (const void **)input_ptrs,
		input_size, output_ptr);
}

static void mca_asrc_config_wrapper(
	mca_num_type_t io_type,
	size_t num_channels,
	const fxp32_t *coeff,
	size_t order,
	size_t list_size) {
	if (num_channels == 1) {
		switch (io_type) {
		case MCA_FXP32:
			csky_mca_asrc_mono_fxp32_config(coeff, order, list_size);
			break;
		case MCA_FXP24:
			csky_mca_asrc_mono_fxp24_config(coeff, order, list_size);
			break;
		case MCA_FXP16:
			csky_mca_asrc_mono_fxp16_config(coeff, order, list_size);
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
			csky_mca_asrc_stereo_fxp32_config(coeff, order, list_size);
			break;
		case MCA_FXP24:
			csky_mca_asrc_stereo_fxp24_config(coeff, order, list_size);
			break;
		case MCA_FXP16:
			csky_mca_asrc_stereo_fxp16_config(coeff, order, list_size);
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

static size_t mca_asrc_wrapper(
	mca_num_type_t io_type,
	const void *input_channels[],
	size_t num_channels,
	size_t input_size,
	void *output) {
	size_t size_in_byte = 0;
	if (num_channels == 1) {
		switch (io_type) {
		case MCA_FXP32:
			size_in_byte = csky_mca_asrc_mono_fxp32(
				input_channels[0], input_size, output);
			break;
		case MCA_FXP24:
			size_in_byte = csky_mca_asrc_mono_fxp24(
				input_channels[0], input_size, output);
			break;
		case MCA_FXP16:
			size_in_byte = csky_mca_asrc_mono_fxp16(
				input_channels[0], input_size, output);
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
			size_in_byte = csky_mca_asrc_stereo_fxp32(
				input_channels[0], input_channels[1], input_size, output);
			break;
		case MCA_FXP24:
			size_in_byte = csky_mca_asrc_stereo_fxp24(
				input_channels[0], input_channels[1], input_size, output);
			break;
		case MCA_FXP16:
			size_in_byte = csky_mca_asrc_stereo_fxp16(
				input_channels[0], input_channels[1], input_size, output);
			break;
		case MCA_FXP16_32BIT:
		case MCA_FXP64:
		case MCA_FXP8:
		default:
			ASR_ASSERT("IO type not implemented.");
			break;
		}
	}
	return size_in_byte;
}

static bool test_mca_asrc_kernal(
	void *params,
	const mca_test_block_t *test_blocks,
	void **block_ptrs) {
	bool total_passed = true, passed;

	mca_asrc_test_params *tp = params;

	const mca_test_block_t *input_blocks = test_blocks;
	const void **input_ptrs = fast_malloc(sizeof(void *) * tp->num_channels);
	asr_memcpy(input_ptrs, block_ptrs, sizeof(void *) * tp->num_channels);

	void *coeff_ptr = block_ptrs[tp->num_channels];
	void *output_single_shot_ptr = block_ptrs[tp->num_channels + 1];
	void *output_continuous_ptr = block_ptrs[tp->num_channels + 2];

	// Single-shot filtering
	mca_asrc_config_wrapper(input_blocks[0].type, tp->num_channels, coeff_ptr,
		tp->order, tp->list_size);
	passed = tp->output_sample_size_in_byte == mca_asrc_wrapper(
		input_blocks[0].type,
		input_ptrs,
		tp->num_channels,
		input_blocks[0].count,
		output_single_shot_ptr);
	if (!passed) {
		print_log("ASRC single-shot returned wrong size.\n");
		total_passed = false;
	}

	// Continuous filtering
	mca_asrc_config_wrapper(input_blocks[0].type, tp->num_channels, coeff_ptr,
		tp->order, tp->list_size);
	size_t ideal_input_size = tp->num_old_samples_per_loop +
		tp->num_new_samples_per_loop;
	size_t accumulated_outut_size_in_byte = 0;
	size_t sample_index = 0;
	while (true) {
		if (sample_index >= input_blocks[0].count) {
			break;
		}
		size_t actual_input_size = MIN(ideal_input_size,
			input_blocks[0].count - sample_index);

		size_t output_size_in_byte = mca_asrc_wrapper(
			input_blocks[0].type,
			input_ptrs,
			tp->num_channels,
			actual_input_size,
			output_continuous_ptr);

		sample_index += tp->num_new_samples_per_loop;
		accumulated_outut_size_in_byte += output_size_in_byte;

		for (size_t i = 0; i < tp->num_channels; ++i) {
			INC_PTR_VAL_BY_SIZE(input_ptrs[i],
				size_of(input_blocks[0].type) * tp->num_new_samples_per_loop);
		}

		INC_PTR_VAL_BY_SIZE(output_continuous_ptr, output_size_in_byte);
	}
	passed = tp->output_sample_size_in_byte == accumulated_outut_size_in_byte;
	if (!passed) {
		print_log("ASRC continuous returned wrong size.\n");
		total_passed = false;
	}

	fast_free(input_ptrs);

	return total_passed;
}

bool test_mca_asrc(mca_num_type_t io_type, size_t num_channels) {
	bool total_passed = true, passed;

	size_t num_input_samples =
		sizeof(INPUT_SAMPLES) / sizeof(INPUT_SAMPLES[0]);
	struct {
		const fxp32_t *coeff;
		size_t order;
		size_t list_size;
	} asrc_coeffs[] = {
		{
			ASRC_NOT_CHANGED_COEFF,
			ASRC_NOT_CHANGED_ORDER,
			LIST_SIZE_OF(ASRC_NOT_CHANGED_COEFF, ASRC_NOT_CHANGED_ORDER),
		},
		{
			ASRC_UP_SAMPLE_COEFF,
			ASRC_UP_SAMPLE_ORDER,
			LIST_SIZE_OF(ASRC_UP_SAMPLE_COEFF, ASRC_UP_SAMPLE_ORDER),
		},
		{
			ASRC_DOWN_SAMPLE_COEFF,
			ASRC_DOWN_SAMPLE_ORDER,
			LIST_SIZE_OF(ASRC_DOWN_SAMPLE_COEFF, ASRC_DOWN_SAMPLE_ORDER),
		},
	};
	for (size_t i = 0; i < sizeof(asrc_coeffs) / sizeof(asrc_coeffs[0]); ++i) {
		size_t num_old_samples_per_loop = 0;
		size_t num_new_samples_per_loop = 0;
		optimize_asrc_for_continuous_resample(
			asrc_coeffs[i].coeff,
			asrc_coeffs[i].order,
			asrc_coeffs[i].list_size,
			&num_old_samples_per_loop,
			&num_new_samples_per_loop);

		size_t num_input_samples_padded =
			num_input_samples + num_old_samples_per_loop;
		size_t num_output_samples = get_num_output_samples(
			asrc_coeffs[i].coeff,
			asrc_coeffs[i].order, asrc_coeffs[i].list_size,
			num_channels,
			num_input_samples_padded);

		size_t coeff_size =
			(asrc_coeffs[i].order + 2) *asrc_coeffs[i].list_size;

		fxp32_t *input_samples_with_zeros =
		fast_malloc(sizeof(fxp32_t) * num_input_samples_padded);
		memset(input_samples_with_zeros, 0,
			sizeof(fxp32_t) * num_old_samples_per_loop);
		asr_memcpy(input_samples_with_zeros + num_old_samples_per_loop,
			INPUT_SAMPLES, sizeof(fxp32_t) * num_input_samples);

		size_t num_cache_blocks = num_channels + 2;
		mca_cache_block_t *cache_blocks =
			fast_malloc(sizeof(mca_cache_block_t) * num_cache_blocks);
		size_t cache_blocks_index = 0;
		// Input
		for (size_t j = 0; j < num_channels; ++j) {
			cache_blocks[cache_blocks_index++] = (mca_cache_block_t){
				.type = io_type,
				.count = num_input_samples_padded,
			};
		}
		// Coefficients
		cache_blocks[cache_blocks_index++] = (mca_cache_block_t){
			.type = MCA_FXP32,
			.count = coeff_size,
		};
		// Output
		cache_blocks[cache_blocks_index++] = (mca_cache_block_t){
			.type = io_type,
			.count = num_output_samples,
		};

		size_t num_test_blocks = num_channels + 3;
		mca_test_block_t *test_blocks =
			fast_malloc(sizeof(mca_test_block_t) * num_test_blocks);
		size_t test_block_index = 0;
		// Input
		for (size_t j = 0; j < num_channels; ++j) {
			test_blocks[test_block_index++] = (mca_test_block_t){
				.type = io_type,
				.count = num_input_samples_padded,
				.aligns = align_0,
				.io_dir = io_dir_input,
				.cache_index = j,
				.input_change_allowed = false,
			};
		}
		// Coefficients
		test_blocks[test_block_index++] = (mca_test_block_t){
			.type = MCA_FXP32,
			.count = coeff_size,
			.aligns = align_0,
			.io_dir = io_dir_input,
			.cache_index = num_channels,
			.input_change_allowed = false,
		};
		// Output: single-shot
		test_blocks[test_block_index++] = (mca_test_block_t){
			.type = io_type,
			.count = num_output_samples,
			.aligns = align_0,
			.io_dir = io_dir_output,
			.cache_index = num_channels + 1,
			.tolerance = 0,
		};
		// Output: continuous
		test_blocks[test_block_index++] = (mca_test_block_t){
			.type = io_type,
			.count = num_output_samples,
			.aligns = align_0,
			.io_dir = io_dir_output,
			.cache_index = num_channels + 1,
			.tolerance = 0,
		};

		mca_asrc_test_params params = {
			.num_channels = num_channels,

			.order = asrc_coeffs[i].order,
			.list_size = asrc_coeffs[i].list_size,

			.num_old_samples_per_loop = num_old_samples_per_loop,
			.num_new_samples_per_loop = num_new_samples_per_loop,

			.raw_coeff = asrc_coeffs[i].coeff,
			.raw_input = input_samples_with_zeros,

			.output_sample_size_in_byte = num_output_samples * size_of(io_type),
		};

		passed = mca_generic_hardware_test(
			&params,
			gen_mca_asrc_golden_data,
			cache_blocks,
			num_cache_blocks,
			test_mca_asrc_kernal,
			test_blocks,
			num_test_blocks);
		if (!passed) {
			print_log("Failed in ASRC test: order=%d, list_size=%d\n",
				params.order, params.list_size);
			total_passed = false;
		}

		fast_free(test_blocks);
		fast_free(cache_blocks);
		fast_free(input_samples_with_zeros);
	}

	return total_passed;
}
