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

/* faddd */
void test_faddd()
{
    union {
        double d;
        unsigned int i[2];
    } a, b, faddd_res;
    a.d = -1.5, b.d = 1.0, faddd_res.d = 0;
    asm ("fmtvrl vr0, %2;\
        fmtvrh vr0, %3;\
        fmtvrl vr1, %4;\
        fmtvrh vr1, %5;\
        fadd.64 vr2, vr0, vr1;\
        fmfvrl %0, vr2;\
        fmfvrh %1, vr2;"
        : "=r"(faddd_res.i[0]), "=r"(faddd_res.i[1])
        : "r"(a.i[0]), "r"(a.i[1]), "r"(b.i[0]), "r"(b.i[1])
        : "vr0", "vr1", "vr2"
    );
    TEST(faddd_res.d == -0.5);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fadd.64 instructions.\n");
    test_faddd();

    return done_testing();
}
