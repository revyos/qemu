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
void test_fuitod()
{
    union {
        double d;
        unsigned int i[2];
    } fuitod_res;

    unsigned int a = 2.0;
    asm("fmts %2, fr0;\
        fuitod fr2, fr0, r2;\
        fmfd r4, fr2;\
        st.w r4, (%0, 0);\
        st.w r5, (%1, 0);"
        :
        : "r"(&fuitod_res.i[0]), "r"(&fuitod_res.i[1]), "r"(a)
        : "r2", "r4"
    );
    /*printf("a = %d, res = %f\n", a, fuitod_res);*/
    TEST(fuitod_res.d == 2.0);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fuitod instructions.\n");
    test_fuitod();

    return done_testing();
}
