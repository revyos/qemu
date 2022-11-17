/*
 * Copyright (c) 2021 T-Head Semiconductor Co., Ltd. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn dexti\n");

    for (i = 0;
         i < sizeof(samples_dexti)/sizeof(struct ternary_calculation);
         i++) {
        if (samples_dexti[i].op3 == 0) {
            TEST(test_dexti_0(samples_dexti[i].op1, samples_dexti[i].op2)
                            == samples_dexti[i].result);
        } else if (samples_dexti[i].op3 == 2) {
            TEST(test_dexti_2(samples_dexti[i].op1, samples_dexti[i].op2)
                            == samples_dexti[i].result);
        } else if (samples_dexti[i].op3 == 5) {
            TEST(test_dexti_5(samples_dexti[i].op1, samples_dexti[i].op2)
                            == samples_dexti[i].result);
        } else if (samples_dexti[i].op3 == 31) {
            TEST(test_dexti_31(samples_dexti[i].op1, samples_dexti[i].op2)
                            == samples_dexti[i].result);
        }
    }
    return done_testing();
}
