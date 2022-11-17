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

struct op2_res1_s32_s32_f64 data[] = {
    {.op1 = 0x0,        .op2 = 0x0,         .res.d = 0},
    {.op1 = 0xffffffff, .op2 = 0x00000001,  .res.d = 0x00000001ffffffff},
    {.op1 = 0x80000000, .op2 = 0x7fffffff,  .res.d = 0x7fffffff80000000},
};

void test_fmtvr_64(int a, int b, float64 expt)
{
    float64 res;
    asm ("fmtvr.64 %0, %1, %2;"
         : "=v"(res.f)
         : "r"(a), "r"(b)
    );
    TEST(res.d == expt.d);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fmtvr.64 instructions.\n");

    for (i = 0; i < sizeof(data) / sizeof(struct op2_res1_s32_s32_f64); i++) {
        test_fmtvr_64(data[i].op1, data[i].op2, data[i].res);
    }

    return done_testing();
}
