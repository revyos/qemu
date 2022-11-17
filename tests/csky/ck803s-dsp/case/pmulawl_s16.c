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
#define TEST_TIMES      7
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn PMULAWL.S16 \n");

    /*
     * PMULAWL.S16
     * rz = rz + rx[15:0] * ry[15:0], rn = rn + rx[31:16] * ry[15:0],
     * signed
     */
    struct ternary64_calculation sample[TEST_TIMES] = {
        {0x7fff8000, 0x80008000, 0x00000000ffffffff, 0xc00080003fffffff},
        {0x76540000, 0x8000abcd, 0x80000000ffffffff, 0x5914dd44ffffffff},
        {0x76540000, 0x7fff7654, 0x0000000000000000, 0x36b18b9000000000},
        {0xabcd0000, 0x80000000, 0x0123456789abcdef, 0x0123456789abcdef},
        {0xabcdffff, 0x7fffabcd, 0x0000000100000001, 0x1bb1822a00005434},
        {0x7fffffff, 0x7fff7654, 0x7fffffffffffffff, 0xbb2989abffff89ab},
        {0xffffffff, 0xffffffff, 0x7fffffff7fffffff, 0x8000000080000000},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_pmulawl_s16(sample[i].op1, sample[i].op2, sample[i].op3)
                     == sample[i].result);
    }

    return done_testing();
}

