#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "soc_config.h"
#include "hardware_test.h"

int main() {
	run_hardware_test(regression_test);

	return 0;
}
