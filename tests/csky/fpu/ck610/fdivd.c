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

binary_calculation_64_t samples_fdivd[] = {
    {.op1.a.d = -4.0, .op2.a.d = 2.0, .result.a.d = -2.0},
    {.op1.a.d = 2.0, .op2.a.d = 2.0, .result.a.d = 1.0},
};

/* fdivd */
void test_fdivd()
{
    union {
        double d;
        unsigned int i[2];
    } a, b, fdivd_res;
    for (int i = 0;
        i < sizeof(samples_fdivd) / sizeof(samples_fdivd[0]);
        i++){
        a.d = samples_fdivd[i].op1.a.d;
        b.d = samples_fdivd[i].op2.a.d;
        asm ("mov r2, %2;\
             mov r3, %3;\
            fmtd r2, fr0;\
            mov  r4, %4;\
            mov  r5, %5;\
            fmtd r4, fr2;\
            fdivd fr2, fr0, fr2, r2;\
            fmfd r2, fr2;\
            mov %0, r2;\
            mov %1, r3;"
            : "=r"(fdivd_res.i[0]), "=r"(fdivd_res.i[1])
            :"r"(a.i[0]), "r"(a.i[1]), "r"(b.i[0]), "r"(b.i[1])
            : "r2", "r3", "r4", "r5"
        );
        TEST(fdivd_res.d == samples_fdivd[i].result.a.d);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fdivd instructions.\n");
    test_fdivd();

    return done_testing();
}
