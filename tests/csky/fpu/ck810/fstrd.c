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

/* fstrd */
void test_fstrd()
{
    volatile union {
        double d;
        unsigned int i[2];
    } a[2];
    a[0].d = 0;
    a[1].d = -1.5;
    asm volatile ("fldrd vr0, (%0, %1 << 0);\
        fstrd vr0, (%0, %2 << 0);"
        :
        : "r"(&a), "r"(8), "r"(0)
        : "vr0", "vr1", "vr2"
    );
    TEST(a[0].d == -1.5);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fstrd instructions.\n");
    test_fstrd();

    return done_testing();
}
