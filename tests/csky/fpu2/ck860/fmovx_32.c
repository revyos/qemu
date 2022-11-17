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

struct op1_res1_f32 data[] = {
    {.op1.d = 0x7fff0001,   .res.d = 0x7fff},
    {.op1.d = 0x0,          .res.d = 0x0},
};


void test_fmovx_32(float32 a, float32 expt)
{
    float32 res;
    asm ("fmovx.32 %0, %1;"
         : "=v"(res.f)
         : "v"(a.f)
    );
    TEST(res.d == expt.d);
}


int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fmovx.32 instructions.\n");

    for (i = 0; i < sizeof(data) / sizeof(struct op1_res1_f32); i++) {
        test_fmovx_32(data[i].op1, data[i].res);
    }


    return done_testing();
}
