#include "hardware_test.h"
#include <assert.h>
#include <stdarg.h>
#include <math.h>

/*******************************************************************************
 * Hardware test utilities
 ******************************************************************************/

void print_log(const char *fmt, ...) {
#if ENABLE_LOG_PRINT
	va_list ap;
	va_start(ap, fmt);
	vprintf(fmt, ap);
	va_end(ap);
#endif
}

#define _generate_random_data_impl(bits) \
void generate_random_data_fxp##bits(fxp##bits##_t *data, size_t size) { \
	while (size--) { \
		*data++ = (fxp##bits##_t) \
			(((float)rand() / RAND_MAX - 0.5f) * INT##bits##_MAX); \
	} \
}
_generate_random_data_impl(8)
_generate_random_data_impl(16)
_generate_random_data_impl(32)

void generate_random_data_fxp(void *data, size_t elem_size, size_t elem_count) {
	switch (elem_size) {
	case sizeof(fxp8_t):
		generate_random_data_fxp8((fxp8_t *)data, elem_count);
		break;
	case sizeof(fxp16_t):
		generate_random_data_fxp16((fxp16_t *)data, elem_count);
		break;
	case sizeof(fxp32_t):
		generate_random_data_fxp32((fxp32_t *)data, elem_count);
		break;
	default:
		assert(false && "Element size is not supported.");
		break;
	}
}

#define _find_max_error_impl(bits) \
fxp##bits##_t find_max_error_fxp##bits( \
	const fxp##bits##_t *actual, \
	const fxp##bits##_t *expected, \
	size_t size) { \
	fxp##bits##_t max_error = 0; \
	for (size_t i = 0; i < size; ++i) { \
		fxp##bits##_t error = actual[i] - expected[i]; \
		if (error < 0) { \
			error = -error; \
		} \
		if (max_error < error) { \
			max_error = error; \
		} \
	} \
	return max_error; \
}
_find_max_error_impl(8)
_find_max_error_impl(16)
_find_max_error_impl(32)

#if ENABLE_ELEMENT_WISE_PRINT_WHEN_COMPARE
#define _expect_array_equal_with_tol_impl(bits) \
bool _expect_array_equal_with_tol_fxp##bits( \
	const fxp##bits##_t *actual, \
	const fxp##bits##_t *expected, \
	size_t size, \
	fxp32_t tolerance, \
	const char *function, \
	const char *file, \
	size_t line) { \
	for (size_t i = 0; i < size; ++i) { \
		fxp32_t error = actual[i] - expected[i]; \
		if (error < 0) { \
			error = -error; \
		} \
		if (error > tolerance) { \
			print_log( \
				"Element at [%d] (actual %d, expected %d) exceeds the " \
				"maximal tolerance %d in %s %s:%d.\n",\
				i, actual[i], expected[i], tolerance, function, file, line); \
			return false; \
		} \
	} \
	return true; \
}
#else
#define _expect_array_equal_with_tol_impl(bits) \
bool _expect_array_equal_with_tol_fxp##bits( \
	const fxp##bits##_t *actual, \
	const fxp##bits##_t *expected, \
	size_t size, \
	fxp32_t tolerance, \
	const char *function, \
	const char *file, \
	size_t line) { \
	fxp32_t error = find_max_error_fxp##bits(actual, expected, size); \
	if (error > tolerance) { \
		print_log( \
			"Expected maximal tolerance %d but found error %d in %s %s:%d.\n", \
			tolerance, error, function, file, line); \
		return false; \
	} \
	return true; \
}
#endif
_expect_array_equal_with_tol_impl(8)
_expect_array_equal_with_tol_impl(16)
_expect_array_equal_with_tol_impl(32)

bool _expect_array_equal_with_tol_fxp(
	const void *actual,
	const void *expected,
	size_t elem_size,
	size_t elem_count,
	fxp32_t tolerance,
	const char *function,
	const char *file,
	size_t line) {
	switch (elem_size) {
	case sizeof(fxp8_t):
		return _expect_array_equal_with_tol_fxp8(actual, expected, elem_count,
			tolerance, function, file, line);
	case sizeof(fxp16_t):
		return _expect_array_equal_with_tol_fxp16(actual, expected, elem_count,
			tolerance, function, file, line);
	case sizeof(fxp32_t):
		return _expect_array_equal_with_tol_fxp32(actual, expected, elem_count,
			tolerance, function, file, line);
	default:
		assert(false && "Element size is not supported.");
		return false;
	}
}

bool _expect_true(bool condition, const char *file, size_t line) {
	if (!condition) {
		print_log("Expected true but found false in %s:%d.\n", file, line); \
	}
	return condition;
}

bool _expect_false(bool condition, const char *file, size_t line) {
	if (condition) {
		print_log("Expected false but found true in %s:%d.\n", file, line); \
	}
	return !condition;
}

#define _expect_equal_fxp_impl(bits) \
bool _expect_equal_fxp##bits( \
	fxp##bits##_t actual, \
	fxp##bits##_t expected, \
	const char *file, \
	size_t line) { \
	if (actual != expected) { \
		print_log("Expected %d but found %d in %s:%d.\n", \
			expected, actual, file, line); \
		return false; \
	} \
	return true; \
}
_expect_equal_fxp_impl(8)
_expect_equal_fxp_impl(16)
_expect_equal_fxp_impl(32)

void *align_memory_addr_to(void *addr, size_t alignment) {
	alignment &= 0xF;
	unsigned int addr_val = (unsigned int)addr;
	while ((addr_val & 0xF) != alignment) {
		++addr_val;
	}
	return (void *)addr_val;
}
/*******************************************************************************
 * Hardware test entry point
 ******************************************************************************/

static const char *g_hardware_test_level_names[] = {
	nameof(smoke_test),
	nameof(sanity_test),
	nameof(regression_test),
	nameof(performance_test)
};

extern void get_hardware_test_cases(
	const hardware_test_case_t **test_cases,
	size_t *num_of_test_cases);

void run_hardware_test(hardware_test_level_t test_level) {
	// Get list of hardware test cases.
	const hardware_test_case_t *test_cases;
	size_t num_of_test_cases;
	get_hardware_test_cases(&test_cases, &num_of_test_cases);

	// Generate test index format string.
	char index_fmt[6];
	sprintf(index_fmt, "%%%dd", (size_t)ceil(log10(num_of_test_cases)));

	char msg_fmt[80];
	bool *test_results = fast_malloc(sizeof(bool) * num_of_test_cases);
	bool any_fail = false;

	// Run each hardware test case.
	print_log(
		"****** HARDWARE TEST RUNNING (level = %s) ******\n",
		g_hardware_test_level_names[test_level]);
	sprintf(msg_fmt, "Running hardware test %s: %%s\n", index_fmt);
	for (size_t test_index = 0; test_index < num_of_test_cases; ++test_index) {
		// It test level is performance_test, run performance tests only.
		// Otherwise, run tests with level less than or equal to the test level.
		hardware_test_level_t level = test_cases[test_index].level;
		bool not_skip = (test_level == performance_test && test_level == level)
			|| (test_level != performance_test && test_level >= level);
		if (not_skip) {
			print_log(msg_fmt,
				test_index, test_cases[test_index].name);
			if (test_level == performance_test) {
				timer_start();
			}
			bool passed = test_cases[test_index].entry_point();
			if (test_level == performance_test) {
				timer_stop();
			}
			test_results[test_index] = passed;
			if (!passed) {
				any_fail = true;
			}
			print_log("\n");
		}
	}

	// Report hardware test results.
	print_log("****** HARDWARE TEST COMPLETED ******\n");
	sprintf(msg_fmt, "%%s%s %%s - %%s\n", index_fmt);
	const char *prefix_fail = any_fail ? "[x] " : "";
	const char *prefix_pass_or_skip = any_fail ? "    " : "";
	const char *tag_pass = "PASS";
	const char *tag_fail = "FAIL";
	const char *tag_skip = "SKIP";
	size_t passed_count = 0, failed_count = 0, skipped_count = 0;
	for (size_t test_index = 0; test_index < num_of_test_cases; ++test_index) {
		const hardware_test_case_t *test_case = &test_cases[test_index];
		hardware_test_level_t level = test_case->level;
		bool not_skip = (test_level == performance_test && test_level == level)
			|| (test_level != performance_test && test_level >= level);
		if (not_skip) {
			if (test_results[test_index]) {
				++passed_count;
			}
			else {
				++failed_count;
			}
			bool passed = test_results[test_index];
			print_log(msg_fmt,
				passed ? prefix_pass_or_skip : prefix_fail,
				test_index,
				passed ? tag_pass : tag_fail,
				test_case->name);
		}
		else {
			++skipped_count;
			print_log(msg_fmt,
				prefix_pass_or_skip, test_index, tag_skip, test_case->name);
		}
	}
	print_log("\n%d tests passed, %d tests failed, %d tests skipped.\n",
		passed_count, failed_count, skipped_count);

	fast_free(test_results);
}
