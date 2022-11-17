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

/* fmtvrl, fmfvrl, fsitos */
void test_fsitod()
{
    union {
        double d;
        unsigned int i[2];
    } fsitod_res;

    int a = -2;
    asm("fmtvrl vr0, %2;\
        fsitod vr1, vr0;\
        fmfvrl %0,vr1;\
        fmfvrh %1, vr1;"
        : "=r"(fsitod_res.i[0]), "=r"(fsitod_res.i[1])
        : "r"(a)
        : "vr0", "vr1"
    );
    /*printf("a = %d, res = %f\n", a, fsitod_res);*/
    TEST(fsitod_res.d == -2.0);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fsitod instructions.\n");
    test_fsitod();

    return done_testing();
}
