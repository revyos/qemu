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

struct unary_calculation samples_fnegs[] = {
    {.op1.a.f = -1.5, .result.a.f = 1.5},
    {.op1.a.f = 1.5, .result.a.f = -1.5}
};

/* fnegs */
void test_fnegs()
{
    float a = -1.5, fnegs_res = 0;
    for (int i = 0;
        i < sizeof(samples_fnegs) / sizeof(samples_fnegs[0]);
        i++){
        a = samples_fnegs[i].op1.a.f;
        asm ("fmts %1, fr0;\
            fnegs fr1, fr0, r2;\
            fmfs %0, fr1;"
            : "=r"(fnegs_res)
            : "r"(a)
            : "r2"
        );
        TEST(fnegs_res == samples_fnegs[i].result.a.f);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fnegs instructions.\n");
    test_fnegs();

    return done_testing();
}
