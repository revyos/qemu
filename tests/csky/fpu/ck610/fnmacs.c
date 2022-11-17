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

struct ternary_calculation samples_fnmacs[] = {
    {.op1.a.f = -3.0, .op2.a.f = 2.0, .op3.a.f = 2.0, .result.a.f = -7.0},
    {.op1.a.f = 3.0, .op2.a.f = 2.0, .op3.a.f = 2.0, .result.a.f = -1.0}
};

/* fnmacs */
void test_fnmacs()
{
    float a = -1.5, b, c, fnmacs_res = 0;
    for (int i = 0;
        i < sizeof(samples_fnmacs) / sizeof(samples_fnmacs[0]);
        i++){
        a = samples_fnmacs[i].op1.a.f;
        b = samples_fnmacs[i].op2.a.f;
        c = samples_fnmacs[i].op3.a.f;
        asm ("fmts %1, fr2;\
            fmts %2, fr1;\
            fmts %3, fr0;\
            fnmacs fr2, fr0, fr1, r2;\
            fmfs %0, fr2;"
            : "=r"(fnmacs_res)
            : "r"(a), "r"(b), "r"(c)
            : "r2"
        );
        TEST(fnmacs_res == samples_fnmacs[i].result.a.f);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fnmacs instructions.\n");
    test_fnmacs();

    return done_testing();
}
