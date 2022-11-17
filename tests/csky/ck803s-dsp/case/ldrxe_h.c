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
#define TEST_TIMES      2
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn LDRXE.H \n");

    /*
     * LDRXE.H
     * rz = {mem(rx+ry)[15:0], rz[15:0]}
     * r(z+1) = {r(z+1)[31:16], mem(rx+ry)[15:0]}
     */
    struct unary64_calculation sample[TEST_TIMES] = {
        {0, 0x0000ffffffff0000},
        {4, 0x00007fff7fff0000},
    };
    for (i = 0; i< TEST_TIMES; i++) {
        TEST(test_ldrxe_h(sample[i].op1) == sample[i].result);
    }

    return done_testing();
}

