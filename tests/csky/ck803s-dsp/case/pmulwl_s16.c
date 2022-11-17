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

    init_testsuite("Testing insn PMULWL.S16 \n");

    /*
     * PMULWL.S16
     * rz = lo_x * lo_y, rn = hi_x * lo_y, signed
     */
    struct binary64_calculation sample[TEST_TIMES] = {
        {0x7fff8000, 0x80008000, 0xc000800040000000},
        {0x76540000, 0x8000abcd, 0xd914dd4400000000},
        {0x76540000, 0x7fff7654, 0x36b18b9000000000},
        {0xabcd0000, 0x80000000, 0x0000000000000000},
        {0xabcdffff, 0x7fffabcd, 0x1bb1822900005433},
        {0x7fffffff, 0x7fff7654, 0x3b2989acffff89ac},
        {0xffffffff, 0xffffffff, 0x0000000100000001},
        {0x7fff8000, 0x80008000, 0xc000800040000000},
        {0x76540000, 0xabcd8000, 0xc4d6000000000000},
        {0x76540000, 0x76547fff, 0x3b2989ac00000000},
        {0xabcd0000, 0x00008000, 0x2a19800000000000},
        {0xabcdffff, 0xabcd7fff, 0xd5e6d433ffff8001},
        {0x7fffffff, 0x76547fff, 0x3fff0001ffff8001},
        {0xffffffff, 0xffffffff, 0x0000000100000001},
       };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_pmulwl_s16(sample[i].op1, sample[i].op2)
                     == sample[i].result);
    }

    return done_testing();
}

