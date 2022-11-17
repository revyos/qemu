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

struct op2_res1_f32_s16_s16 data0[] = {
    {.op1.f = -1.0,     .op2 = 1,   .res = 0xfffe},
    {.op1.d = SpZero,   .op2 = 2,   .res = 0},
    {.op1.f = 1.5,      .op2 = 3,   .res = 0xc},
};

struct op2_res1_f32_s16_u16 data1[] = {
    {.op1.f = -1.0,     .op2 = 1,   .res = 0},
    {.op1.d = SpZero,   .op2 = 2,   .res = 0},
    {.op1.f = 1.5,      .op2 = 3,   .res = 0xc},
};


void test_fftox_f32_s16(float32 a, int16_t b, int16_t expt)
{
    float16 res;
    asm ("subi %2, %2, 1;\
         andi %2, %2, 0x1f;\
         lsli %2, %2, 16;\
         mfcr r0, cr<1, 2>;\
         lrw  r1, 0xffe0ffff;\
         and r0, r0, r1;\
         or  r0, r0, %2;\
         mtcr r0, cr<1, 2>;\
         fftox.f32.s16 %0, %1;\
         "
         : "=v"(res.d)
         : "v"(a.f), "r"(b)
         : "r0", "r1"
    );
    TEST(res.d == (uint16_t)expt);
}

void test_fftox_f32_u16(float32 a, int16_t b, uint16_t expt)
{
    float16 res;
    asm ("subi %2, %2, 1;\
         andi %2, %2, 0xf;\
         lsli %2, %2, 16;\
         mfcr r0, cr<1, 2>;\
         lrw  r1, 0xffe0ffff;\
         and r0, r0, r1;\
         or  r0, r0, %2;\
         mtcr r0, cr<1, 2>;\
         fftox.f32.u16 %0, %1;\
         "
         : "=v"(res.d)
         : "v"(a.f), "r"(b)
         : "r0", "r1"
    );
    TEST(res.d == expt);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fftox.f32.s16/fftox.f32.u16 instructions.\n");

    for (i = 0; i < sizeof(data0) / sizeof(struct op2_res1_f32_s16_s16); i++) {
        test_fftox_f32_s16(data0[i].op1, data0[i].op2, data0[i].res);
    }

    for (i = 0; i < sizeof(data1) / sizeof(struct op2_res1_f32_s16_u16); i++) {
        test_fftox_f32_u16(data1[i].op1, data0[i].op2, data1[i].res);
    }

    return done_testing();
}
