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

/* sqrt(4.0) = 2.0 */
struct unary_calculation_64 samples_fsqrtd_64[] = {
    {.op1.a.d = 4.0, .result.a.d = 2.0}
};

void test_fsqrtd()
{
    union {
        double d;
        unsigned int i[2];
    } fsqrtd_res;
    int i = 0;
    for (i = 0;
        i < sizeof(samples_fsqrtd_64) / sizeof(struct unary_calculation_64);
        i++) {
        asm ("fmtvrl vr0, %2;\
            fmtvrh vr0, %3;\
            fsqrtd vr1, vr0;\
            fmfvrl %0, vr1;\
            fmfvrh %1, vr1;"
            : "=r"(fsqrtd_res.i[0]), "=r"(fsqrtd_res.i[1])
            : "r"(samples_fsqrtd_64[i].op1.a.i[0]),
            "r"(samples_fsqrtd_64[i].op1.a.i[1])
            : "vr0", "vr1"
        );
        TEST(fsqrtd_res.d == samples_fsqrtd_64[i].result.a.d);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fsqrtd instructions.\n");
    test_fsqrtd();

    return done_testing();
}
