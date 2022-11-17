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

struct op1_res1_f16_s32 data0[] = {
    {.op1.f = -1.0,     .res = -1},
    {.op1.d = SpZero,   .res = 0},
    {.op1.f = 1.5,      .res = 2},
};

struct op1_res1_f16_u32 data1[] = {
    {.op1.f = -2.5,     .res = 0},
    {.op1.d = SpZero,   .res = 0},
    {.op1.f = 1.4,      .res = 1},
};

void test_fftoi_f16_s32(float16 a, int32_t expt)
{
    int32_t res;
    asm ("fftoi.f16.s32 vr0, %1;\
         fmfvr.32.1 %0, vr0;"
         : "=r"(res)
         : "v"(a.f)
         : "vr0"
    );
    TEST(res == expt);
}

void test_fftoi_f16_u32(float16 a, uint32_t expt)
{
    uint32_t res;
    asm ("fftoi.f16.u32 vr0, %1;\
         fmfvr.32.1 %0, vr0;"
         : "=r"(res)
         : "v"(a.f)
         : "vr0"
    );
    TEST(res == expt);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fftoi.f16.s32/fftoi.f16.u32 instructions.\n");

    for (i = 0; i < sizeof(data0) / sizeof(struct op1_res1_f16_s32); i++) {
        test_fftoi_f16_s32(data0[i].op1, data0[i].res);
    }

    for (i = 0; i < sizeof(data1) / sizeof(struct op1_res1_f16_u32); i++) {
        test_fftoi_f16_u32(data1[i].op1, data1[i].res);
    }

    return done_testing();
}
