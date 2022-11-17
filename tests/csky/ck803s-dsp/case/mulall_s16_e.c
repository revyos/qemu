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

    init_testsuite("Testing insn MULALL.S16.E \n");

    /*
     * MULALL.S16.E
     * {rn, rz} = {rn, rz} + rx[15:0] * ry[15:0] + rx[31:16] * ry[31:16],
     * signed
     */
    struct ternary64_calculation ter64_sample[TEST_TIMES] = {
        {0x00017fff, 0x00007fff, 0x8000000000000000, 0x800000003fff0001},
        {0x00017fff, 0x00007fff, 0xffffffffffffffff, 0x000000003fff0000},
        {0x00017fff, 0x00007fff, 0x7fffffffffffffff, 0x800000003fff0000},
        {0xFFFF8000, 0x00008000, 0x8000000000000000, 0x8000000040000000},
        {0x80008000, 0x7FFF8000, 0xffffffffffffffff, 0x000000003fffffff},
        {0xFFFF8000, 0x80008000, 0x7fffffffffffffff, 0x800000003fffffff},
        {0xFFFF7fff, 0x00008000, 0x8000000000000000, 0x7fffffffc0008000},
        {0x80007fff, 0x7FFF8000, 0xffffffffffffffff, 0xffffffffc0007fff},
        {0x80007fff, 0x80008000, 0x7fffffffffffffff, 0x7fffffffc0007fff},
        {0x0000ffff, 0x0000ffff, 0x8000000000000000, 0x8000000000000001},
        {0x7FFFffff, 0x7FFFffff, 0xffffffffffffffff, 0x0000000000000000},
        {0x8000ffff, 0x8000ffff, 0x7fffffffffffffff, 0x8000000000000000},
        {0x0000ffff, 0x00018000, 0x8000000000000000, 0x8000000000008000},
        {0x00008000, 0x0001ffff, 0xffffffffffffffff, 0x0000000000007fff},
        {0x00008000, 0x0001ffff, 0x7fffffffffffffff, 0x8000000000007fff},
        {0x00000000, 0xFFFFffff, 0x0000000000000000, 0x0000000000000000},
        {0x7FFF0000, 0x8000ffff, 0xffffffffffffffff, 0xffffffffffffffff},
        {0x8000ffff, 0xFFFF0000, 0x0000000000000000, 0x0000000000000000},
        {0x0000ffff, 0xFFFF0000, 0xffffffffffffffff, 0xffffffffffffffff},
        {0x7FFF0000, 0x80000000, 0x0000000000000000, 0x0000000000000000},
        {0x80000000, 0x80000000, 0xffffffffffffffff, 0xffffffffffffffff},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_mulall_s16_e(ter64_sample[i].op1, ter64_sample[i].op2,
                               ter64_sample[i].op3) == ter64_sample[i].result);
    }

    return done_testing();
}

