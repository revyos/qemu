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
#include "dsp_insn.h"
#define TEST_TIMES      9
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn MAX.S32 \n");

    /*
     * MAX.S32
     * rz = max(rx, ry), signed
     */
    struct binary_calculation bin_sample[TEST_TIMES] = {
        {0x80000000, 0x80000000, 0x80000000},
        {0x80000000, 0x00000000, 0x00000000},
        {0x80000000, 0x7FFFFFFF, 0x7FFFFFFF},
        {0x00000000, 0x80000000, 0x00000000},
        {0x00000000, 0x00000000, 0x00000000},
        {0x00000000, 0x7FFFFFFF, 0x7FFFFFFF},
        {0x7FFFFFFF, 0x80000000, 0x7FFFFFFF},
        {0x7FFFFFFF, 0x00000000, 0x7FFFFFFF},
        {0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_max_s32(bin_sample[i].op1, bin_sample[i].op2)
                     == bin_sample[i].result);
    }

    return done_testing();
}

