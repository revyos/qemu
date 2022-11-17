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

struct unary_calculation samples_frecips[] = {
    {.op1.a.f = 4.0, .result.a.f = 0.25},
    {.op1.a.f = 5.0, .result.a.f = 0.2}
};

/* frecips */
void test_frecips()
{
    float a = -1.5, frecips_res = 0;
    for (int i = 0;
        i < sizeof(samples_frecips) / sizeof(samples_frecips[0]);
        i++){
        a = samples_frecips[i].op1.a.f;
        asm ("fmts %1, fr0;\
            frecips fr1, fr0, r2;\
            fmfs %0, fr1;"
            : "=r"(frecips_res)
            : "r"(a)
            : "r2"
        );
        TEST(frecips_res == samples_frecips[i].result.a.f);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu frecips instructions.\n");
    test_frecips();

    return done_testing();
}
