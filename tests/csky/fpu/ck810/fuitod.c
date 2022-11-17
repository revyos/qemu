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

/* fmtvrl, fmfvrl, fuitod */
void test_fuitod()
{
    union {
        double d;
        unsigned int i[2];
    } fuitod_res;
    unsigned int a = 0xffffffff;
    asm("fmtvrl vr0, %2;\
        fuitod vr1, vr0;\
        fmfvrl %0, vr1;\
        fmfvrh %1, vr1;"
        : "=r"(fuitod_res.i[0]), "=r"(fuitod_res.i[1])
        : "r"(a)
        : "vr0", "vr1"
    );
    TEST(fuitod_res.d == 4294967295);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fuitod instructions.\n");
    test_fuitod();

    return done_testing();
}
