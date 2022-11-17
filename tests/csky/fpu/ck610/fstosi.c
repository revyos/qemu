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

struct unary_calculation samples_fstosi[] = {
    {.op1.a.f = -1.2, .result.a.i = -1.0},
    {.op1.a.f = 1.2, .result.a.i = 1.0}
};

/* fstosi */
void test_fstosi()
{
    int fstosi_res = 0;
    for (int i = 0;
        i < sizeof(samples_fstosi) / sizeof(samples_fstosi[0]);
        i++){
        float a = samples_fstosi[i].op1.a.f;
        asm ("fmts %1, fr0;\
            fstosi fr1, fr0, RM_NEAREST, r2;\
            fmfs %0, fr1;"
            : "=r"(fstosi_res)
            : "r"(a)
            : "r2"
        );
        TEST(fstosi_res == samples_fstosi[i].result.a.i);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fstosi instructions.\n");
    test_fstosi();

    return done_testing();
}
