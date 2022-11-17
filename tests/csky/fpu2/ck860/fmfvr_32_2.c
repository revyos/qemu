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
#include "fpu_structs.h"

struct op2_res2_f32_f32_s32_s32 data[] = {
    {.op1.d = 0x0,        .op2.d = 0x0,         .res1 = 0         , .res2 = 0},
    {.op1.d = 0xffffffff, .op2.d = 0x00000001,  .res1 = 0xffffffff, .res2 = 0x1},
    {.op1.d = 0x80000000, .op2.d = 0x7fffffff,  .res1 = 0x80000000, .res2 = 0x7fffffff},
};

void test_fmfvr_32_2(float32 a, float32 b, int expt1, int expt2)
{
    int res1, res2;
    asm ("fmov.32 vr0, %2;\
         fmov.32 vr1, %3;\
         fmfvr.32.2 %0, %1, vr0;"
         : "=r"(res1), "=r"(res2)
         : "v"(a.f), "v"(b.f)
         : "vr0", "vr1"
    );
    TEST(res1 == expt1 && res2 == expt2);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fmfvr.32.2 instructions.\n");

    for (i = 0; i < sizeof(data) / sizeof(struct op2_res2_f32_f32_s32_s32); i++) {
        test_fmfvr_32_2(data[i].op1, data[i].op2, data[i].res1, data[i].res2);
    }

    return done_testing();
}
