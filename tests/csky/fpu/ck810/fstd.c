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

/* fstd */
void test_fstd()
{
    volatile union {
        double d;
        unsigned int i[2];
    } a[2];
    a[0].d = 0;
    a[1].d = 1.5;
    asm volatile ("fmtvrl vr0, %0;\
        fmtvrh vr0, %1;\
        fstd vr0, (%2, %3);"
        :
        : "r"(a[1].i[0]), "r"(a[1].i[1]), "r"(&a[0]), "i"(0)
        : "vr0", "vr1"
    );
    TEST(a[0].d == a[1].d);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fstd instructions.\n");
    test_fstd();

    return done_testing();
}
