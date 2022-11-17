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

binary_calculation_64_t samples_fsubm[] = {
    {.op1.a.f[0] = -2.0, .op1.a.f[1] = -1.0,
        .op2.a.f[0] = 1.0, .op2.a.f[1] = 1.0,
        .result.a.f[0] = -3.0, .result.a.f[1] = -2.0},
    {.op1.a.f[0] = -2.0, .op1.a.f[1] = -1.0,
        .op2.a.f[0] = 2.0, .op2.a.f[1] = 2.0,
        .result.a.f[0] = -4.0, .result.a.f[1] = -3.0},
};

/* fsubm */
void test_faddd()
{
    union {
        double d;
        unsigned int i[2];
        float f[2];
    } a, b, fsubm_res;
    for (int i = 0;
        i < sizeof(samples_fsubm) / sizeof(samples_fsubm[0]);
        i++){
        a.d = samples_fsubm[i].op1.a.d;
        b.d = samples_fsubm[i].op2.a.d;
        asm ("mov r2, %2;\
             mov r3, %3;\
            fmtd r2, fr0;\
            mov  r4, %4;\
            mov  r5, %5;\
            fmtd r4, fr2;\
            fsubm fr2, fr0, fr2, r2;\
            fmfd r2, fr2;\
            mov %0, r2;\
            mov %1, r3;"
            :"=r"(fsubm_res.i[0]), "=r"(fsubm_res.i[1])
            :"r"(a.i[0]), "r"(a.i[1]), "r"(b.i[0]), "r"(b.i[1])
            : "r2", "r3", "r4", "r5"
        );
        TEST(fsubm_res.f[0] == samples_fsubm[i].result.a.f[0] &&
            fsubm_res.f[1] == samples_fsubm[i].result.a.f[1]);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fsubm instructions.\n");
    test_faddd();

    return done_testing();
}
