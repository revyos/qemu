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

struct op3_res1_f16 data[] = {
    {.op1.f = -1.0,   .op2.f = 1.0,     .op3.f = 1.0,     .res.f = 0.0},
    {.op1.f = -1.5,   .op2.f = 0.5,     .op3.f = -0.5,    .res.f = -1.25},
    {.op1.f = 0.0,    .op2.f = 1.0,     .op3.f = 3.0,     .res.f = 3.0},
    {.op1.f = 0.5,    .op2.d = HpInf,   .op3.f = 0.5,     .res.d = HpInf},
    {.op1.f = -2.5,   .op2.d = HpsNaN,  .op3.f = 0.12,    .res.d = 0x7e01},
};

void test_ffmula_16(float16 a, float16 b, float16 c, float16 expt)
{
    float16 res;
    asm ("fmov.16 %0, %3;\
         ffmula.16 %0, %1, %2;"
         : "=&v"(res.f)
         : "v"(a.f), "v"(b.f), "v"(c.f)
    );
    TEST(res.d == expt.d);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu ffmula.16 instructions.\n");

    for (i = 0; i < sizeof(data) / sizeof(struct op3_res1_f16); i++) {
        test_ffmula_16(data[i].op1, data[i].op2, data[i].op3, data[i].res);
    }

    return done_testing();
}
