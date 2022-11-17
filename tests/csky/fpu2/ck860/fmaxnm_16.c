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

struct op2_res1_f16 data[] = {
    {.op1.f = -1.0,     .op2.d = HpqNaN,    .res.f = -1.0},
    {.op1.f = -1.0,     .op2.f = 0.5,       .res.f = 0.5},
};

void test_fmaxnm_16(float16 a, float16 b, float16 c)
{
    float16 res;
    asm ("fmaxnm.16 %0, %1, %2;"
         : "=v"(res.f)
         : "v"(a.f), "v"(b.f)
    );
    TEST(res.f == c.f);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fmaxnm.16 instructions.\n");

    for (i = 0; i < sizeof(data) / sizeof(struct op2_res1_f16); i++) {
        test_fmaxnm_16(data[i].op1, data[i].op2, data[i].res);
    }

    return done_testing();
}
