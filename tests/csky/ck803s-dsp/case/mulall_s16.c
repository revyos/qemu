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
#define TEST_TIMES      21
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn MULALL.S16 \n");

    /*
     * MULALL.S16
     * rz = rx[15:0] * ry[15:0] + rn, signed
     */
    struct ternary_calculation ter_sample[TEST_TIMES] = {
        {0x00017fff, 0x00007fff, 0x80000000, 0xbfff0001},
        {0x00017fff, 0x00007fff, 0xffffffff, 0x3fff0000},
        {0x00017fff, 0x00007fff, 0x7fffffff, 0xbfff0000},
        {0xFFFF8000, 0x00008000, 0x80000000, 0xc0000000},
        {0x80008000, 0x7FFF8000, 0xffffffff, 0x3fffffff},
        {0xFFFF8000, 0x80008000, 0x7fffffff, 0xbfffffff},
        {0xFFFFffff, 0x0000ffff, 0x80000000, 0x80000001},
        {0x8000ffff, 0x7FFFffff, 0xffffffff, 0x00000000},
        {0x8000ffff, 0x8000ffff, 0x7fffffff, 0x80000000},
        {0x00007fff, 0x00008000, 0x80000000, 0x40008000},
        {0x7FFF8000, 0x7FFF7fff, 0xffffffff, 0xc0007fff},
        {0x80008000, 0x80007fff, 0x7fffffff, 0x40007fff},
        {0x0000ffff, 0x00018000, 0x80000000, 0x80008000},
        {0x00008000, 0x0001ffff, 0xffffffff, 0x00007fff},
        {0x00008000, 0x0001ffff, 0x7fffffff, 0x80007fff},
        {0x00000000, 0xFFFFffff, 0x00000000, 0x00000000},
        {0x7FFF0000, 0x8000ffff, 0xffffffff, 0xffffffff},
        {0x8000ffff, 0xFFFF0000, 0x00000000, 0x00000000},
        {0x0000ffff, 0xFFFF0000, 0xffffffff, 0xffffffff},
        {0x7FFF0000, 0x80000000, 0x00000000, 0x00000000},
        {0x80000000, 0x80000000, 0xffffffff, 0xffffffff},
     };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_mulall_s16(ter_sample[i].op1, ter_sample[i].op2,
                             ter_sample[i].op3) == ter_sample[i].result);
    }

    return done_testing();
}

