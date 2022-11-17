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

    init_testsuite("Testing insn PSUB.S16.S \n");

    /*
     * PSUB.S16.S
     * rz[15:0] = rx[15:0] - ry[15:0],
     * rz[31:16] = rx[31:16] - ry[31:16], signed & saturated
     */
    struct binary_calculation bin_sample[TEST_TIMES] = {
        {0X00000000, 0X00000000, 0x00000000},
        {0X00000001, 0X00010000, 0xffff0001},
        {0X00010001, 0X00010001, 0x00000000},
        {0XFFFF0001, 0X0001FFFF, 0xfffe0002},
        {0XFFFFFFFF, 0XFFFF0000, 0x0000ffff},
        {0X0000FFFF, 0XFFFFFFFF, 0x00010000},
        {0X7FFF8000, 0X7FFF8000, 0x00000000},
        {0X7FFF8000, 0X80007FFF, 0x7fff8000},
        {0X80007FFF, 0X7FFF8000, 0x80007fff},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_psub_s16_s(bin_sample[i].op1, bin_sample[i].op2)
                     == bin_sample[i].result);
    }

    return done_testing();
}

