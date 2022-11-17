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

/* fstm */
void test_fstm()
{
    volatile union {
        double d;
        unsigned int i[2];
        float f[2];
    } a[4];
    a[0].d = 0;
    a[1].f[0] = 1.5;
    a[1].f[1] = 1.6;
    asm volatile ("fmtvrl vr0, %0;\
        fmtvrh vr0, %1;\
        fstm vr0, (%2, %3);"
        :
        : "r"(a[1].i[0]), "r"(a[1].i[1]), "r"(&a[0]), "i"(0)
        : "vr0", "vr1"
    );
    TEST(a[0].f[0] == a[1].f[0] && a[0].f[1] == a[1].f[1]);
    asm volatile ("fmtvrl vr0, %0;\
        fmtvrh vr0, %1;\
        fstm vr0, (%2, %3);"
        :
        : "r"(a[1].i[0]), "r"(a[1].i[1]), "r"(&a[2]), "i"(8)
        : "vr0", "vr1"
    );
    TEST(a[0].f[0] == a[3].f[0] && a[0].f[1] == a[3].f[1]);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fstm instructions.\n");
    test_fstm();

    return done_testing();
}
