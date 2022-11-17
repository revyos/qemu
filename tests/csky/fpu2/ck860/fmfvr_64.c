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

struct op1_res2_f64_s32_s32 data[] = {
    {.op1.d = 0,                    .res1 = 0x0,        .res2 = 0x0},
    {.op1.d = 0x00000001ffffffff,   .res1 = 0xffffffff, .res2 = 0x00000001},
    {.op1.d = 0x7fffffff80000000,   .res1 = 0x80000000, .res2 = 0x7fffffff},
};

void test_fmfvr_64(float64 a, int expt1, int expt2)
{
    int res1, res2;
    asm ("fmfvr.64 %0, %1, %2;"
         : "=r"(res1), "=r"(res2)
         : "v"(a.f)
    );
    TEST(res1 == expt1 && res2 == expt2);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fmfvr.64 instructions.\n");

    for (i = 0; i < sizeof(data) / sizeof(struct op1_res2_f64_s32_s32); i++) {
        test_fmfvr_64(data[i].op1, data[i].res1, data[i].res2);
    }

    return done_testing();
}
