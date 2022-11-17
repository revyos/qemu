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

struct op2_res2_s32_s32_f32_f32 data[] = {
    {.op1 = 0x0,        .op2 = 0x0,         .res1.d = 0         , .res2.d = 0},
    {.op1 = 0xffffffff, .op2 = 0x00000001,  .res1.d = 0xffffffff, .res2.d = 0x1},
    {.op1 = 0x80000000, .op2 = 0x7fffffff,  .res1.d = 0x80000000, .res2.d = 0x7fffffff},
};

void test_fmtvr_32_2(int a, int b, float32 expt1, float32 expt2)
{
    float32 res1, res2;
    asm ("fmtvr.32.2 vr0, %2, %3;\
         fmov.32 %0, vr0;\
         fmov.32 %1, vr1;"
         : "=v"(res1.f), "=v"(res2.f)
         : "r"(a), "r"(b)
         : "vr0", "vr1"
    );
    TEST(res1.d == expt1.d && res2.d == expt2.d);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fmtvr.32.2 instructions.\n");

    for (i = 0; i < sizeof(data) / sizeof(struct op2_res2_s32_s32_f32_f32); i++) {
        test_fmtvr_32_2(data[i].op1, data[i].op2, data[i].res1, data[i].res2);
    }

    return done_testing();
}
