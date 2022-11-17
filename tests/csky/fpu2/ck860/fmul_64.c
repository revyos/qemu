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

/* -1.5 * 1.5 = -2.25 */
struct binary_calculation_64 samples_fmuld_64[] = {
    {.op1.a.d = -1.5, .op2.a.d = 1.5, .result.a.d = -2.25},
};

void test_fmuld()
{
    union {
        double d;
        unsigned int i[2];
    } fmuld_res;
    int i = 0;
    for (i = 0;
        i < sizeof(samples_fmuld_64) / sizeof(struct binary_calculation_64);
        i++) {
        asm ("fmtvrl vr0, %2;\
            fmtvrh vr0, %3;\
            fmtvrl vr1, %4;\
            fmtvrh vr1, %5;\
            fmuld vr2, vr0, vr1;\
            fmfvrl %0, vr2;\
            fmfvrh %1, vr2;"
            : "=r"(fmuld_res.i[0]), "=r"(fmuld_res.i[1])
            : "r"(samples_fmuld_64[i].op1.a.i[0]),
            "r"(samples_fmuld_64[i].op1.a.i[1]),
            "r"(samples_fmuld_64[i].op2.a.i[0]),
            "r"(samples_fmuld_64[i].op2.a.i[1])
            : "vr0", "vr1", "vr2"
        );
        TEST(fmuld_res.d == samples_fmuld_64[i].result.a.d);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fmuld instructions.\n");
    test_fmuld();

    return done_testing();
}
