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

    init_testsuite("Testing insn DIVUR \n");

    /*
     * DIVUR
     * rz = rx / ry, rn = rx % ry, unsigned
     */
    struct binary64_calculation bin64_sample[TEST_TIMES] = {
        {0x7fffffff, 0x00000001, 0x000000007FFFFFFF},
        {0x7fffffff, 0x00000002, 0x000000013FFFFFFF},
        {0x00000001, 0x7fffffff, 0x0000000100000000},
        {0x7fffffff, 0x7fffffff, 0x0000000000000001},
        {0x7fffffff, 0xffffffff, 0x7fffffff00000000},
        {0x7fffffff, 0x80000000, 0x7fffffff00000000},
        {0x00000001, 0xfffffffe, 0x0000000100000000},
        {0x80000001, 0x00000002, 0x0000000140000000},
        {0xffffffff, 0x7fffffff, 0x0000000100000002},
        {0x80000000, 0xffffffff, 0x8000000000000000},
        {0x80000001, 0xfffffffe, 0x8000000100000000},
        {0x00000000, 0xffffffff, 0x0000000000000000},
        /* {0xffffffff, 0x00000000, 0x0000000000000000}, */
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_divur(bin64_sample[i].op1, bin64_sample[i].op2)
                     == bin64_sample[i].result);
    }

    return done_testing();
}

