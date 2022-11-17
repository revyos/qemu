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
#define TEST_TIMES      12
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn SUB.S32.S \n");

    /*
     * SUB.S32.S
     * rz = rx - ry, signed & saturated
     */
    struct binary_calculation bin_sample[TEST_TIMES] = {
        {0X00000001, 0X00000001, 0x00000000},
        {0XFFFFFFFF, 0X00000001, 0xfffffffe},
        {0X00000001, 0XFFFFFFFF, 0x00000002},
        {0XFFFFFFFF, 0XFFFFFFFF, 0x00000000},
        {0X30000000, 0X80000001, 0x7fffffff},
        {0X80000001, 0X30000000, 0x80000000},
        {0X7FFFFFFF, 0X00000000, 0x7fffffff},
        {0X7FFFFFFF, 0X7FFFFFFF, 0x00000000},
        {0X7FFFFFFF, 0X80000000, 0x7fffffff},
        {0X80000000, 0X00000000, 0x80000000},
        {0X80000000, 0X80000000, 0x00000000},
        {0X80000000, 0X7FFFFFFF, 0x80000000},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_sub_s32_s(bin_sample[i].op1, bin_sample[i].op2)
                     == bin_sample[i].result);
    }

    return done_testing();
}

