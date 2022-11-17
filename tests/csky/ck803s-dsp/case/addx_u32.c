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
#define TEST_TIMES      22
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn ADDX.U32 \n");

    /*
     * ADDX.U32
     * rz = rx + ry[15:0], unsigned
     *
     * TEST(test_addx_u32(0x12345678, 0x12345678) == 0x2468acf0)
     */
    struct binary_calculation bin_sample[TEST_TIMES] = {
        {0x12345678, 0x12345678, 0x1234acf0},
        {0x12345678, 0x7f000000, 0x12345678},
        {0xffffffff, 0x11111111, 0x00001110},
        {0x12345678, 0x88888888, 0x1234df00},
        {0x00000000, 0x80000000, 0x00000000},
        {0X00000000, 0X00000000, 0x00000000},
        {0X00000000, 0X00000001, 0x00000001},
        {0X00000000, 0XFFFFFFFF, 0x0000ffff},
        {0X00000001, 0X00000000, 0x00000001},
        {0X00000001, 0X00000001, 0x00000002},
        {0X00000001, 0XFFFFFFFF, 0x00010000},
        {0XFFFFFFFF, 0X00000000, 0xffffffff},
        {0XFFFFFFFF, 0X00000001, 0x00000000},
        {0XFFFFFFFF, 0XFFFFFFFF, 0x0000fffe},
        {0X00000000, 0XFFFF0000, 0x00000000},
        {0X00000000, 0X00008000, 0x00008000},
        {0X00000001, 0XFFFF0000, 0x00000001},
        {0X00000001, 0X00008000, 0x00008001},
        {0XFFFFFFFF, 0XFFFF0000, 0xffffffff},
        {0XFFFFFFFF, 0X00008000, 0x00007fff},
        {0X7FFFFFFF, 0XFFFF7FFF, 0x80007ffe},
        {0X80000000, 0X00008000, 0x80008000},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_addx_u32(bin_sample[i].op1, bin_sample[i].op2)
                     == bin_sample[i].result);
    }

    return done_testing();
}

