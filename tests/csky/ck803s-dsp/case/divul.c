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

    init_testsuite("Testing insn DIVUL \n");

    /*
     * DIVUL
     * rz = {rx,32'b0}/ry, signed
     */
    struct binary_calculation sample[TEST_TIMES] = {
        {0x12345678, 0x00000005, 0x03a4114b},
        {0x00000005, 0x12345678, 0x00000000},
        {0x77654321, 0x12345678, 0x00000006},
        {0xffff21ce, 0x00000004, 0x3fffc873},
        {0xfffffffd, 0x00000008, 0x1fffffff},
        {0xfffffffb, 0x00000004, 0x3ffffffe},
        {0x77654321, 0xfffffff2, 0x00000000},
        {0xfffffffb, 0x00000004, 0x3ffffffe},
        {0xfffffff3, 0xfffffff5, 0x00000000},
        {0x00000000, 0xffffffff, 0x00000000},
        {0x80000000, 0xffffffff, 0x00000000},
        /* {0xffffffff, 0x00000000, 0x00000000}, */
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_divul(sample[i].op1, sample[i].op2)
                     == sample[i].result);
    }

    return done_testing();
}

