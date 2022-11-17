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

struct op3_res1_f64 data[] = {
    {.op1.d = 0x7fff000100020003, .op2.d = 0x123456789abcdef0, .op3.f = 0.0, .res.d = 0x123456789abcdef0},
    {.op1.d = 0x0,        .op2.d = 0xffffffffff, .op3.f = 1.0, .res.d = 0x0},
};


void test_fsel_64(float64 a, float64 b, float64 c, float64 expt)
{
    float64 res;
    asm ("fcmpnez.64 %3;\
         fsel.64 %0, %1, %2;"
         : "=&v"(res.f)
         : "v"(a.f), "v"(b.f), "v"(c.f)
    );
    TEST(res.d == expt.d);
}


int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fsel.64 seltructions.\n");

    for (i = 0; i < sizeof(data) / sizeof(struct op3_res1_f64); i++) {
        test_fsel_64(data[i].op1, data[i].op2, data[i].op3, data[i].res);
    }


    return done_testing();
}
