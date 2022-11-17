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
#define TEST_TIMES      23
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn ADDX.S32 \n");

    /*
     * ADDX.S32
     * rz = rx + ry[15:0], unsigned
     *
     * TEST(test_addx_s32(0x12345678, 0x12345678) == 0x2468acf0)
     */
    struct binary_calculation bin_sample[TEST_TIMES] = {
        {0x12345678, 0x12345678, 0x1234acf0},
        {0x12345678, 0x7f000000, 0x12345678},
        {0xffffffff, 0x11111111, 0x00001110},
        {0x12345678, 0x88888888, 0x1233df00},
        {0xa0a0a0a0, 0x90909090, 0xa0a03130},
        {0x80000000, 0x80000000, 0x80000000},
        {0X00000000, 0X00000000, 0x00000000},
        {0X00000000, 0X00000001, 0x00000001},
        {0X00000000, 0XFFFFFFFF, 0xffffffff},
        {0X00000001, 0X00000000, 0x00000001},
        {0X00000001, 0X00000001, 0x00000002},
        {0X00000001, 0XFFFFFFFF, 0x00000000},
        {0XFFFFFFFF, 0X00000000, 0xffffffff},
        {0XFFFFFFFF, 0X00000001, 0x00000000},
        {0XFFFFFFFF, 0XFFFFFFFF, 0xfffffffe},
        {0X00000000, 0XFFFF0000, 0x00000000},
        {0X00000000, 0X00008000, 0xffff8000},
        {0X00000001, 0XFFFF0000, 0x00000001},
        {0X00000001, 0X00008000, 0xffff8001},
        {0XFFFFFFFF, 0XFFFF0000, 0xffffffff},
        {0XFFFFFFFF, 0X00008000, 0xffff7fff},
        {0X7FFFFFFF, 0XFFFF7FFF, 0x80007ffe},
        {0X80000000, 0X00008000, 0x7fff8000},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_addx_s32(bin_sample[i].op1, bin_sample[i].op2)
                     == bin_sample[i].result);
    }
    return done_testing();
}

