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

struct op1_res1_f64 data0[] = {
    {.op1.d = -1,       .res.f = -1.0},
    {.op1.d = 0,        .res.f = 0.0},
    {.op1.d = 10000000, .res.f = 10000000.0},
};

struct op1_res1_f64 data1[] = {
    {.op1.d = 3,        .res.f = 3.0},
    {.op1.d = 0,        .res.f = 0.0},
    {.op1.d = 10000000, .res.f = 10000000.0},
};

void test_fitof_s32_f64(float64 a, float64 expt)
{
    float64 res;
    asm ("fitof.s32.f64 %0, %1;"
         : "=v"(res.f)
         : "v"(a.f)
    );
    TEST(res.f == expt.f);
}

void test_fitof_u32_f64(float64 a, float64 expt)
{
    float64 res;
    asm ("fitof.u32.f64 %0, %1;"
         : "=v"(res.f)
         : "v"(a.f)
    );
    TEST(res.f == expt.f);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fitof.s32.f64/fitof.u32.f64 instructions.\n");

    for (i = 0; i < sizeof(data0) / sizeof(struct op1_res1_f64); i++) {
        test_fitof_s32_f64(data0[i].op1, data0[i].res);
    }

    for (i = 0; i < sizeof(data1) / sizeof(struct op1_res1_f64); i++) {
        test_fitof_u32_f64(data1[i].op1, data1[i].res);
    }

    return done_testing();
}
