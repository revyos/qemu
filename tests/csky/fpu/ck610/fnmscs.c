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

struct ternary_calculation samples_fnmscs[] = {
    {.op1.a.f = -3.0, .op2.a.f = 2.0, .op3.a.f = 2.0, .result.a.f = -1.0},
    {.op1.a.f = 3.0, .op2.a.f = 2.0, .op3.a.f = 2.0, .result.a.f = -7.0}
};

/* fnmscs */
void test_fnmscs()
{
    float a = -1.5, b, c, fnmscs_res = 0;
    for (int i = 0;
        i < sizeof(samples_fnmscs) / sizeof(samples_fnmscs[0]);
        i++){
        a = samples_fnmscs[i].op1.a.f;
        b = samples_fnmscs[i].op2.a.f;
        c = samples_fnmscs[i].op3.a.f;
        asm ("fmts %1, fr2;\
            fmts %2, fr1;\
            fmts %3, fr0;\
            fnmscs fr2, fr0, fr1, r2;\
            fmfs %0, fr2;"
            : "=r"(fnmscs_res)
            : "r"(a), "r"(b), "r"(c)
            : "r2"
        );
        TEST(fnmscs_res == samples_fnmscs[i].result.a.f);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fnmscs instructions.\n");
    test_fnmscs();

    return done_testing();
}
