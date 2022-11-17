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
    init_testsuite("Testing insn srli16\n");

    for (i = 0;
         i < sizeof(samples_srli16)/sizeof(struct binary_calculation);
         i++) {
        if (samples_srli16[i].op2 == 1) {
            TEST(test_srli16_1(samples_srli16[i].op1)
                 == samples_srli16[i].result);
        } else if (samples_srli16[i].op2 == 2) {
            TEST(test_srli16_2(samples_srli16[i].op1)
                 == samples_srli16[i].result);
        } else if (samples_srli16[i].op2 == 3) {
            TEST(test_srli16_3(samples_srli16[i].op1)
                 == samples_srli16[i].result);
        } else if (samples_srli16[i].op2 == 15) {
            TEST(test_srli16_15(samples_srli16[i].op1)
                 == samples_srli16[i].result);
        }
    }
    return done_testing();
}
