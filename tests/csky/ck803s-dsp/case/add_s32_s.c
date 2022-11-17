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
#define TEST_TIMES      15
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn ADD.S32.S \n");

    /*
     * ADD.S32.S
     * rz = rx + ry, signed & saturated
     *
     * TEST(test_add_s32_s(0x12345678, 0x12345678) == 0x2468acf0)
     */
    struct binary_calculation bin_sample[TEST_TIMES] = {
        {0x12345678, 0x12345678, 0x2468acf0},
        {0x12345678, 0x7f000000, 0x7fffffff},
        {0x92345678, 0xf2345678, 0x8468acf0},
        {0x92345678, 0x92345678, 0x80000000},
        {0x00000000, 0x80000000, 0x80000000},
        {0x80000000, 0x80000000, 0x80000000},
        {0x00000001, 0x00000001, 0x00000002},
        {0xffffffff, 0x00000001, 0x00000000},
        {0x00000001, 0xffffffff, 0x00000000},
        {0xffffffff, 0xffffffff, 0xfffffffe},
        {0x30000000, 0x60000000, 0x7fffffff},
        {0x80000001, 0x80000001, 0x80000000},
        {0x7fffffff, 0x7fffffff, 0x7fffffff},
        {0x80000000, 0x80000000, 0x80000000},
        {0x7fffffff, 0x80000000, 0xffffffff},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_add_s32_s(bin_sample[i].op1, bin_sample[i].op2)
                     == bin_sample[i].result);
    }

    return done_testing();
}

