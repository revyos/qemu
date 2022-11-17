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
#define TEST_TIMES      18
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn MULA.32.L \n");

    /*
     * MULA.32.L
     * rz = rn + rx * ry
     */
    struct ternary_calculation ter_sample[TEST_TIMES] = {
        {0x00000001, 0x00000001, 0x00000000, 0x00000001},
        {0x00000002, 0x40000000, 0x00000000, 0x80000000},
        {0x00000001, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF},
        {0x00000001, 0x00000001, 0x00000001, 0x00000002},
        {0x00000002, 0x20000000, 0x40000000, 0x80000000},
        {0x00000002, 0x80000000, 0x00000000, 0x00000000},
        {0x00000002, 0x80000001, 0x00000000, 0x00000002},
        {0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000001},
        {0x80000000, 0x80000000, 0x00000000, 0x00000000},
        {0x80000000, 0x80000000, 0x80000000, 0x80000000},
        {0x00000100, 0x10000001, 0xFFFFFFFF, 0x000000FF},
        {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000},
        {0x00000000, 0x00000001, 0x00000000, 0x00000000},
        {0x00000000, 0x00000000, 0x00000000, 0x00000000},
        {0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000},
        {0x00000000, 0x00000001, 0x00000001, 0x00000001},
        {0x00000000, 0x00000000, 0x00000001, 0x00000001},
        {0x00000000, 0xFFFFFFFF, 0x00000001, 0x00000001},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_mula_32_l(ter_sample[i].op1, ter_sample[i].op2,
                            ter_sample[i].op3) == ter_sample[i].result);
    }

    return done_testing();
}

