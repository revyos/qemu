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
#define TEST_TIMES      11
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn PMUL.S16 \n");

    /*
     * PMUL.S16
     * rz = lo_x * lo_y, rn = hi_x * hi_y, signed
     */
    struct binary64_calculation bin64_sample[TEST_TIMES] = {
        {0x56785678, 0xc000b000, 0xea620000e4fa8000},
        {0x12345678, 0x12345678, 0x014b5a901d34d840},
        {0x8080c0c0, 0x9090a0a0, 0x3780480017907800},
        {0xf0007fff, 0x90000001, 0x0700000000007fff},
        {0x7fff8000, 0x80008000, 0xC000800040000000},
        {0x76540000, 0x8000abcd, 0xC4D6000000000000},
        {0x76540000, 0x7fff7654, 0x3B2989AC00000000},
        {0xabcd0000, 0x80000000, 0x2A19800000000000},
        {0xabcdffff, 0x7fffabcd, 0xD5E6D43300005433},
        {0x7fffffff, 0x7fff7654, 0x3FFF0001ffff89ac},
        {0xffffffff, 0xffffffff, 0x0000000100000001},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_pmul_s16(bin64_sample[i].op1, bin64_sample[i].op2)
                     == bin64_sample[i].result);
    }

    return done_testing();
}

