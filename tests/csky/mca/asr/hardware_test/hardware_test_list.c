#include "hardware_test.h"

// A macro to help build test case structure
#define build_test_case(level_, test_case) \
  { .level = level_, .name = nameof(test_case), .entry_point = test_case }

////////////////////////////////////////////////////////////////////////////////
// Declare entry points of your hardware test cases (extern) here...

// Hardware test cases run on MCA 2.0
#ifdef ASR_MCA_2
extern bool test_mca_vec_add_vec_fxp8();
extern bool test_mca_vec_add_vec_fxp16();
extern bool test_mca_vec_add_vec_fxp32();
extern bool test_mca_vec_add_scalar_fxp8();
extern bool test_mca_vec_add_scalar_fxp16();
extern bool test_mca_vec_add_scalar_fxp32();
extern bool test_mca_vec_mul_vec_fxp8();
extern bool test_mca_vec_mul_vec_fxp16();
extern bool test_mca_vec_mul_vec_fxp32();
extern bool test_mca_vec_mul_scalar_fxp8();
extern bool test_mca_vec_mul_scalar_fxp16();
extern bool test_mca_vec_mul_scalar_fxp32();
extern bool test_mca_mat_mul_vec_fxp8();
extern bool test_mca_mat_mul_vec_fxp16();
extern bool test_mca_mat_mul_vec_fxp32();
extern bool test_mca_mat_mul_vec_v8_m8_o32();
extern bool test_mca_fully_connected_fxp8();
extern bool test_mca_fully_connected_fxp16();
extern bool test_mca_fully_connected_v8_m8_b8_o32();
extern bool test_mca_fully_connected_v8_m8_b16_o32();
extern bool test_mca_fully_connected_with_relu_fxp8();
extern bool test_mca_fully_connected_with_relu_fxp16();
extern bool test_mca_fully_connected_with_relu_v8_m8_b8_o32();
extern bool test_mca_fully_connected_with_relu_v8_m8_b16_o32();
extern bool test_mca_softmax_fxp16();
extern bool test_mca_rfft_512_fxp32();
extern bool test_mca_rfft_256_fxp32();
extern bool test_mca_rfft_128_fxp32();
extern bool test_mca_rfft_64_fxp32();
extern bool test_mca_rfft_32_fxp32();
extern bool test_mca_rfft_16_fxp32();
extern bool test_mca_cfft_512_fxp32();
extern bool test_mca_cfft_256_fxp32();
extern bool test_mca_cfft_128_fxp32();
extern bool test_mca_cfft_64_fxp32();
extern bool test_mca_cfft_32_fxp32();
extern bool test_mca_cfft_16_fxp32();
extern bool test_mca_rifft_512_fxp32();
extern bool test_mca_rifft_256_fxp32();
extern bool test_mca_rifft_128_fxp32();
extern bool test_mca_rifft_64_fxp32();
extern bool test_mca_rifft_32_fxp32();
extern bool test_mca_rifft_16_fxp32();
extern bool test_mca_cifft_512_fxp32();
extern bool test_mca_cifft_256_fxp32();
extern bool test_mca_cifft_128_fxp32();
extern bool test_mca_cifft_64_fxp32();
extern bool test_mca_cifft_32_fxp32();
extern bool test_mca_cifft_16_fxp32();
extern bool test_mca_power_spectrum_512_fxp32();
extern bool test_mca_power_spectrum_256_fxp32();
extern bool test_mca_power_spectrum_128_fxp32();
extern bool test_mca_power_spectrum_64_fxp32();
extern bool test_mca_power_spectrum_32_fxp32();
extern bool test_mca_power_spectrum_16_fxp32();
extern bool test_mca_fir_fxp32();
extern bool test_mca_fir_fxp24();
extern bool test_mca_fir_fxp16();
extern bool test_mca_fir_fxp32_coeff64();
extern bool test_mca_fir_fxp24_coeff64();
extern bool test_mca_fir_fxp16_coeff64();
extern bool test_mca_iir_fxp32();
extern bool test_mca_iir_fxp24();
extern bool test_mca_iir_fxp16();
extern bool test_mca_iir_fxp32_coeff64();
extern bool test_mca_iir_fxp24_coeff64();
extern bool test_mca_iir_fxp16_coeff64();
extern bool test_mca_asrc_stereo_fxp32();
extern bool test_mca_asrc_stereo_fxp24();
extern bool test_mca_asrc_stereo_fxp16();
extern bool test_mca_asrc_mono_fxp32();
extern bool test_mca_asrc_mono_fxp24();
extern bool test_mca_asrc_mono_fxp16();
#endif

////////////////////////////////////////////////////////////////////////////////
// Register your hardware test cases here...

static const hardware_test_case_t g_hardware_test_cases[] = {
	// Hardware test cases run on MCA 2.0
#ifdef ASR_MCA_2
	build_test_case(regression_test, test_mca_vec_add_vec_fxp8),
	build_test_case(regression_test, test_mca_vec_add_vec_fxp16),
	build_test_case(regression_test, test_mca_vec_add_vec_fxp32),
	build_test_case(regression_test, test_mca_vec_add_scalar_fxp8),
	build_test_case(regression_test, test_mca_vec_add_scalar_fxp16),
	build_test_case(regression_test, test_mca_vec_add_scalar_fxp32),
	build_test_case(regression_test, test_mca_vec_mul_vec_fxp8),
	build_test_case(regression_test, test_mca_vec_mul_vec_fxp16),
	build_test_case(regression_test, test_mca_vec_mul_vec_fxp32),
	build_test_case(regression_test, test_mca_vec_mul_scalar_fxp8),
	build_test_case(regression_test, test_mca_vec_mul_scalar_fxp16),
	build_test_case(regression_test, test_mca_vec_mul_scalar_fxp32),
	build_test_case(regression_test, test_mca_mat_mul_vec_fxp8),
	build_test_case(regression_test, test_mca_mat_mul_vec_fxp16),
	build_test_case(regression_test, test_mca_mat_mul_vec_fxp32),
	build_test_case(regression_test, test_mca_mat_mul_vec_v8_m8_o32),
	build_test_case(regression_test, test_mca_fully_connected_fxp8),
	build_test_case(regression_test, test_mca_fully_connected_fxp16),
	build_test_case(regression_test, test_mca_fully_connected_v8_m8_b8_o32),
	build_test_case(regression_test, test_mca_fully_connected_v8_m8_b16_o32),
	build_test_case(regression_test, test_mca_fully_connected_with_relu_fxp8),
	build_test_case(regression_test, test_mca_fully_connected_with_relu_fxp16),
	build_test_case(regression_test, test_mca_fully_connected_with_relu_v8_m8_b8_o32),
	build_test_case(regression_test, test_mca_fully_connected_with_relu_v8_m8_b16_o32),
	build_test_case(regression_test, test_mca_softmax_fxp16),
	build_test_case(regression_test, test_mca_rfft_512_fxp32),
	build_test_case(regression_test, test_mca_rfft_256_fxp32),
	build_test_case(regression_test, test_mca_rfft_128_fxp32),
	build_test_case(regression_test, test_mca_rfft_64_fxp32),
	build_test_case(regression_test, test_mca_rfft_32_fxp32),
	build_test_case(regression_test, test_mca_rfft_16_fxp32),
	build_test_case(regression_test, test_mca_cfft_512_fxp32),
	build_test_case(regression_test, test_mca_cfft_256_fxp32),
	build_test_case(regression_test, test_mca_cfft_128_fxp32),
	build_test_case(regression_test, test_mca_cfft_64_fxp32),
	build_test_case(regression_test, test_mca_cfft_32_fxp32),
	build_test_case(regression_test, test_mca_cfft_16_fxp32),
	build_test_case(regression_test, test_mca_rifft_512_fxp32),
	build_test_case(regression_test, test_mca_rifft_256_fxp32),
	build_test_case(regression_test, test_mca_rifft_128_fxp32),
	build_test_case(regression_test, test_mca_rifft_64_fxp32),
	build_test_case(regression_test, test_mca_rifft_32_fxp32),
	build_test_case(regression_test, test_mca_rifft_16_fxp32),
	build_test_case(regression_test, test_mca_cifft_512_fxp32),
	build_test_case(regression_test, test_mca_cifft_256_fxp32),
	build_test_case(regression_test, test_mca_cifft_128_fxp32),
	build_test_case(regression_test, test_mca_cifft_64_fxp32),
	build_test_case(regression_test, test_mca_cifft_32_fxp32),
	build_test_case(regression_test, test_mca_cifft_16_fxp32),
	build_test_case(regression_test, test_mca_power_spectrum_512_fxp32),
	build_test_case(regression_test, test_mca_power_spectrum_256_fxp32),
	build_test_case(regression_test, test_mca_power_spectrum_128_fxp32),
	build_test_case(regression_test, test_mca_power_spectrum_64_fxp32),
	build_test_case(regression_test, test_mca_power_spectrum_32_fxp32),
	build_test_case(regression_test, test_mca_power_spectrum_16_fxp32),
	build_test_case(regression_test, test_mca_fir_fxp32),
	build_test_case(regression_test, test_mca_fir_fxp24),
	build_test_case(regression_test, test_mca_fir_fxp16),
	build_test_case(regression_test, test_mca_fir_fxp32_coeff64),
	build_test_case(regression_test, test_mca_fir_fxp24_coeff64),
	build_test_case(regression_test, test_mca_fir_fxp16_coeff64),
	build_test_case(regression_test, test_mca_iir_fxp32),
	build_test_case(regression_test, test_mca_iir_fxp24),
	build_test_case(regression_test, test_mca_iir_fxp16),
	build_test_case(regression_test, test_mca_iir_fxp32_coeff64),
	build_test_case(regression_test, test_mca_iir_fxp24_coeff64),
	build_test_case(regression_test, test_mca_iir_fxp16_coeff64),
	build_test_case(regression_test, test_mca_asrc_stereo_fxp32),
	build_test_case(regression_test, test_mca_asrc_stereo_fxp24),
	build_test_case(regression_test, test_mca_asrc_stereo_fxp16),
	build_test_case(regression_test, test_mca_asrc_mono_fxp32),
	build_test_case(regression_test, test_mca_asrc_mono_fxp24),
	build_test_case(regression_test, test_mca_asrc_mono_fxp16),
#endif
};

// Return hardware test cases as well as its size to the test entry point.
void get_hardware_test_cases(
	const hardware_test_case_t **test_cases,
	size_t *num_of_test_cases) {
	*test_cases = g_hardware_test_cases;
	*num_of_test_cases =
		sizeof(g_hardware_test_cases) / sizeof(hardware_test_case_t);
}
