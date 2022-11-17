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
#define TEST_TIMES      6
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn PADDX.S32 \n");

    /*
     * PADDX.S32
     * rz = rx + lo_ry, r(z+1) = rn + hi_ry, signed
     */
    struct ternary64_calculation ter64_sample[TEST_TIMES] = {
        {0X00000000, 0X00000000, 0X00000000, 0x0000000000000000},
        {0XFFFFFFFF, 0X00000000, 0X00000001, 0x00000001ffffffff},
        {0X00000001, 0XFFFF0001, 0XFFFFFFFF, 0xfffffffe00000002},
        {0XFFFFFFFF, 0XFFFF0001, 0X00000001, 0x0000000000000000},
        {0X7FFFFFFF, 0XFFFF0001, 0X80000000, 0x7fffffff80000000},
        {0X80000000, 0X0001FFFF, 0X7FFFFFFF, 0x800000007fffffff},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_paddx_s32(ter64_sample[i].op1, ter64_sample[i].op2,
                           ter64_sample[i].op3) == ter64_sample[i].result);
    }

    return done_testing();
}

