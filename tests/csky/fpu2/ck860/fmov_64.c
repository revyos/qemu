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

/* fmovd */
void test_fmovd()
{
    union {
        double d;
        unsigned int i[2];
    } a, fmovd_res;
    a.d = 1.5;
    asm ("fmtvrl vr0, %2;\
        fmtvrh vr0, %3;\
        fmovd vr1, vr0;\
        fmfvrl %0, vr1;\
        fmfvrh %1, vr1;"
        : "=r"(fmovd_res.i[0]), "=r"(fmovd_res.i[1])
        : "r"(a.i[0]), "r"(a.i[1])
        : "vr0", "vr1"
    );
    TEST(fmovd_res.d == 1.5);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fmovd instructions.\n");
    test_fmovd();

    return done_testing();
}
