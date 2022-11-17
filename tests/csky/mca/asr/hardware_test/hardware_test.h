#ifndef __HARDWARE_TEST_H__
#define __HARDWARE_TEST_H__

#include "asr_supports/asr_utilities.h"

/*******************************************************************************
 * Hardware test entry point and test types
 ******************************************************************************/

 // Hardware test levels. Refer to the following page for more details about the
 // differences.
 // https://www.asktester.com/smoke-test-vs-sanity-test-vs-retest-vs-regression-test/
typedef enum {
	// Lowest level, determine if critical functionalities are working fine.
	smoke_test,
	// Medium level, determine if major functionalities are working fine.
	sanity_test,
	// Highest level, include all tests to ensure product quality.
	regression_test,

	// Special level for running performance benchmark only.
	performance_test
} hardware_test_level_t;

// Hardware test case structure
typedef struct {
	hardware_test_level_t level;
	const char *name;
	bool(*entry_point)();
} hardware_test_case_t;

// Hardware test entry point
void run_hardware_test(hardware_test_level_t test_level);

/*******************************************************************************
 * Hardware test utilities
 ******************************************************************************/

// Represents the ratio between CPU frequency and timer frequency. By using
// this constant, we can calculate CPU cycles from timer cycles.
static const float cpu_timer_freq_ratio = 1.0f; // (30 MHz / 30 MHz)

// A macro to control enable state of printf. Sometimes we need to export an ELF
// file without any printf call to the Verification team for hardware simulation
// and turning off the macro would be much easier than to comment printf calls.
#define ENABLE_LOG_PRINT 1

// A simple wrapper of printf. Its behavior is controlled by the macro
// ENABLE_LOG_PRINT.
// The following macro seems not work for calls like: print_log("something").
// #define print_log(fmt, ...) printf(fmt, __VA_ARGS__)
void print_log(const char *fmt, ...);

// Section attribute for non-performance related test data.
#define TEST_DATA_ATTR _SDRAM_ADDR_

// A macro to convert a word in C to a C-string
#define nameof(x) (#x)

// Generate random data for testing. You can control the repeatness by setting
// rand seed before this function by calling: srand(seed).
void generate_random_data_fxp8(fxp8_t *data, size_t size);
void generate_random_data_fxp16(fxp16_t *data, size_t size);
void generate_random_data_fxp32(fxp32_t *data, size_t size);
void generate_random_data_fxp(void *data, size_t elem_size, size_t elem_count);

// Find the maximal error for fixed-point arrays.
fxp8_t find_max_error_fxp8(
	const fxp8_t *actual,
	const fxp8_t *expected,
	size_t size);
fxp16_t find_max_error_fxp16(
	const fxp16_t *actual,
	const fxp16_t *expected,
	size_t size);
fxp32_t find_max_error_fxp32(
	const fxp32_t *actual,
	const fxp32_t *expected,
	size_t size);

// A macro to control the enable state of printing elements exceed the tolerance
// when comparing two arrays.
// It may print LOTS LOTS LOTS of lines for some cases, so by default it's set
// to false.
#define ENABLE_ELEMENT_WISE_PRINT_WHEN_COMPARE false

// Expect elements in an fxp array are equal to the expected ones with
// specified tolerance.
#define __expect_array_equal_with_tol_fxp(bits) \
bool _expect_array_equal_with_tol_fxp##bits( \
	const fxp##bits##_t *actual, \
	const fxp##bits##_t *expected, \
	size_t size, \
	fxp32_t tolerance, \
	const char *function, \
	const char *file, \
	size_t line);
__expect_array_equal_with_tol_fxp(8)
__expect_array_equal_with_tol_fxp(16)
__expect_array_equal_with_tol_fxp(32)
#define expect_array_equal_with_tol_fxp8(actual, expected, size, tol) \
	_expect_array_equal_with_tol_fxp8(actual, expected, size, tol, __FUNCTION__, __FILE__, __LINE__)
#define expect_array_equal_with_tol_fxp16(actual, expected, size, tol) \
	_expect_array_equal_with_tol_fxp16(actual, expected, size, tol, __FUNCTION__, __FILE__, __LINE__)
#define expect_array_equal_with_tol_fxp32(actual, expected, size, tol) \
	_expect_array_equal_with_tol_fxp32(actual, expected, size, tol, __FUNCTION__, __FILE__, __LINE__)

bool _expect_array_equal_with_tol_fxp(
	const void *actual,
	const void *expected,
	size_t elem_size,
	size_t elem_count,
	fxp32_t tolerance,
	const char *function,
	const char *file,
	size_t line);
#define expect_array_equal_with_tol_fxp(actual, expected, elem_size, elem_count, tol) \
	_expect_array_equal_with_tol_fxp(actual, expected, elem_size, elem_count, tol, __FUNCTION__, __FILE__, __LINE__)

// Expect elements in an fxp array are exactly equal to the expected ones.
#define __expect_array_equal_fxp(bits) \
static inline bool _expect_array_equal_fxp##bits( \
	const fxp##bits##_t *actual, \
	const fxp##bits##_t *expected, \
	size_t size, \
	const char *function, \
	const char *file, \
	size_t line) { \
	return _expect_array_equal_with_tol_fxp##bits(actual, expected, size, 0, function, file, line); \
}
__expect_array_equal_fxp(8)
__expect_array_equal_fxp(16)
__expect_array_equal_fxp(32)
#define expect_array_equal_fxp8(actual, expected, size) \
	_expect_array_equal_fxp8(actual, expected, size, __FUNCTION__,  __FILE__, __LINE__)
#define expect_array_equal_fxp16(actual, expected, size) \
	_expect_array_equal_fxp16(actual, expected, size, __FUNCTION__, __FILE__, __LINE__)
#define expect_array_equal_fxp32(actual, expected, size) \
	_expect_array_equal_fxp32(actual, expected, size, __FUNCTION__, __FILE__, __LINE__)

static inline bool _expect_array_equal_fxp(
	const void *actual,
	const void *expected,
	size_t elem_size,
	size_t elem_count,
	const char *function,
	const char *file,
	size_t line) {
	return _expect_array_equal_with_tol_fxp(actual, expected, elem_size, elem_count, 0, function, file, line);
}
#define expect_array_equal_fxp(actual, expected, elem_size, elem_count) \
	_expect_array_equal_fxp(actual, expected, elem_size, elem_count, __FUNCTION__, __FILE__, __LINE__)

// Expect the condition is true.
bool _expect_true(bool condition, const char *file, size_t line);
#define expect_true(condition) _expect_true(condition, __FILE__, __LINE__)

// Expect the condition is false.
bool _expect_false(bool condition, const char *file, size_t line);
#define expect_false(condition) _expect_false(condition, __FILE__, __LINE__)

// Expect two fixed-point numbers are equal.
#define _expect_equal_fxp(bits) \
bool _expect_equal_fxp##bits( \
	fxp####bits##_t actual, \
	fxp####bits##_t expected, \
	const char *file, \
	size_t line);
_expect_equal_fxp(8)
_expect_equal_fxp(16)
_expect_equal_fxp(32)
#define expect_equal_fxp8(actual, expected) \
	_expect_equal_fxp8(actual, expected, __FILE__, __LINE__)
#define expect_equal_fxp16(actual, expected) \
	_expect_equal_fxp16(actual, expected, __FILE__, __LINE__)
#define expect_equal_fxp32(actual, expected) \
	_expect_equal_fxp32(actual, expected, __FILE__, __LINE__)

// Align memory address to specified alignment, e.g. 0x0, 0x4, 0x8, 0xC.
void *align_memory_addr_to(void *addr, size_t alignment);

#endif // !__HARDWARE_TEST_H__
