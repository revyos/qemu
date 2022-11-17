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

struct op1_res1_s16_f16 data0[] = {
    {.op1 = -1,     .res.f = -1.0},
    {.op1 = 0,      .res.f = 0.0},
    {.op1 = 10000,  .res.f = 10000.0},
};

struct op1_res1_u16_f16 data1[] = {
    {.op1 = 3,      .res.f = 3.0},
    {.op1 = 0,      .res.f = 0.0},
    {.op1 = 10000,  .res.f = 10000.0},
};

void test_fitof_s16_f16(int16_t a, float16 expt)
{
    float16 res;
    asm ("fmtvr.16 vr0, %1;\
         fitof.s16.f16 %0, vr0;"
         : "=v"(res.f)
         : "r"(a)
         : "vr0"
    );
    TEST(res.f == expt.f);
}

void test_fitof_u16_f16(uint16_t a, float16 expt)
{
    float16 res;
    asm ("fmtvr.16 vr0, %1;\
         fitof.u16.f16 %0, vr0;"
         : "=v"(res.f)
         : "r"(a)
         : "vr0"
    );
    TEST(res.f == expt.f);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fitof.s16.f16/fitof.u16.f16 instructions.\n");

    for (i = 0; i < sizeof(data0) / sizeof(struct op1_res1_s16_f16); i++) {
        test_fitof_s16_f16(data0[i].op1, data0[i].res);
    }

    for (i = 0; i < sizeof(data1) / sizeof(struct op1_res1_u16_f16); i++) {
        test_fitof_u16_f16(data1[i].op1, data1[i].res);
    }

    return done_testing();
}
