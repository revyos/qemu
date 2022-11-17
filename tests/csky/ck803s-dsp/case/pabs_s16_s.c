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
#define TEST_TIMES      5
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn PABS.S16.S \n");

    /*
     * PABS.S16.S
     * rz[15:0] = | rx[15:0] |, rz[31:16] = | rx[31:16] |, signed
     */
    struct unary_calculation un_sample[TEST_TIMES] = {
        {0X00000000, 0x00000000},
        {0X0001FFFF, 0x00010001},
        {0XFFFF0001, 0x00010001},
        {0X7FFF8000, 0x7fff7fff},
        {0X80017FFF, 0x7fff7fff},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_pabs_s16_s(un_sample[i].op1)
                     == un_sample[i].result);
    }
    return done_testing();
}

