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

    init_testsuite("Testing insn PMULWH.S16.F \n");

    /*
     * PMULWH.S16.F
     * rz = lo_x * hi_y << 1, rn = hi_x * hi_y << 1, signed & fraction
     */
    struct binary64_calculation sample[TEST_TIMES] = {
        {0x7fff8000, 0x80008000, 0x8001000080000000},
        {0x76540000, 0x8000abcd, 0x89ac000000000000},
        {0x76540000, 0x7fff7654, 0x7653135800000000},
        {0xabcd0000, 0x80000000, 0x5433000000000000},
        {0xabcdffff, 0x7fffabcd, 0xabcda866ffff0002},
        {0x7fffffff, 0x7fff7654, 0x7ffe0002ffff0002},
        {0xffffffff, 0xffffffff, 0x0000000200000002},
        {0x7fff8000, 0x80008000, 0x8001000080000000},
        {0x76540000, 0xabcd8000, 0xb229ba8800000000},
        {0x76540000, 0x76547fff, 0x6d63172000000000},
        {0xabcd0000, 0x00008000, 0x0000000000000000},
        {0xabcdffff, 0xabcd7fff, 0x376304520000a866},
        {0x7fffffff, 0x76547fff, 0x76531358ffff1358},
        {0xffffffff, 0xffffffff, 0x0000000200000002},
       };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_pmulwh_s16_f(sample[i].op1, sample[i].op2)
                     == sample[i].result);
    }

    return done_testing();
}

