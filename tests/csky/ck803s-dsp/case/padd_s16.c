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
#define TEST_TIMES      14
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn PADD.S16 \n");

    /*
     * PADD.S16
     * rz = {(hi_x + hi_y)[15:0], (lo_x + lo_y)[15:0]}, signed
     */
    struct binary_calculation bin_sample[TEST_TIMES] = {
        {0x56785678, 0x12341234, 0x68ac68ac},
        {0x12345678, 0x12345678, 0x2468acf0},
        {0x12349876, 0x9090a0a0, 0xa2c43916},
        {0xffffffff, 0x11111111, 0x11101110},
        {0X00000000, 0X00000000, 0x00000000},
        {0X00000001, 0X00010000, 0x00010001},
        {0X00010001, 0X00010001, 0x00020002},
        {0XFFFF0001, 0X0001FFFF, 0x00000000},
        {0XFFFFFFFF, 0XFFFF0000, 0xfffeffff},
        {0X0000FFFF, 0XFFFFFFFF, 0xfffffffe},
        {0X60003000, 0X30006000, 0x90009000},
        {0X80018001, 0X80000001, 0x00018002},
        {0X7FFF8000, 0X7FFF8000, 0xfffe0000},
        {0X7FFF8000, 0X80007FFF, 0xffffffff},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_padd_s16(bin_sample[i].op1, bin_sample[i].op2)
                     == bin_sample[i].result);
    }

    return done_testing();
}

