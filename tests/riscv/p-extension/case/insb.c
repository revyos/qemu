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
#include "rvp_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn insb\n");

    for (i = 0;
         i < sizeof(samples_insb)/sizeof(struct ternary_calculation);
         i++) {
        if (samples_insb[i].op3 == 0) {
            TEST(test_insb_0(samples_insb[i].op1, samples_insb[i].op2)
                 == samples_insb[i].result);
        } else if (samples_insb[i].op3 == 1) {
            TEST(test_insb_1(samples_insb[i].op1, samples_insb[i].op2)
                 == samples_insb[i].result);
        } else if (samples_insb[i].op3 == 2) {
            TEST(test_insb_2(samples_insb[i].op1, samples_insb[i].op2)
                 == samples_insb[i].result);
        } else if (samples_insb[i].op3 == 3) {
            TEST(test_insb_3(samples_insb[i].op1, samples_insb[i].op2)
                 == samples_insb[i].result);
#ifdef RV64
        } else if (samples_insb[i].op3 == 4) {
            TEST(test_insb_4(samples_insb[i].op1, samples_insb[i].op2)
                 == samples_insb[i].result);
        } else if (samples_insb[i].op3 == 5) {
            TEST(test_insb_5(samples_insb[i].op1, samples_insb[i].op2)
                 == samples_insb[i].result);
        } else if (samples_insb[i].op3 == 6) {
            TEST(test_insb_6(samples_insb[i].op1, samples_insb[i].op2)
                 == samples_insb[i].result);
        } else if (samples_insb[i].op3 == 7) {
            TEST(test_insb_7(samples_insb[i].op1, samples_insb[i].op2)
                 == samples_insb[i].result);
#endif
        }
    }
    return done_testing();
}
