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

/* faddm */
void test_faddm()
{
    float a = -1.5, b = 1.0, faddm_res = 0;
    float c = 0, d = 1.5, faddm_res_2 = 0;
    asm ("fmtvrl vr0, %2;\
        fmtvrh vr0, %4;\
        fmtvrl vr1, %3;\
        fmtvrh vr1, %5;\
        faddm vr2, vr0, vr1;\
        fmfvrl %0, vr2;\
        fmfvrh %1, vr2;"
        : "=r"(faddm_res), "=r"(faddm_res_2)
        : "r"(a), "r"(b), "r"(c), "r"(d)
        : "vr0", "vr1"
    );
    TEST(faddm_res == -0.5 && faddm_res_2 == 1.5);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu faddm instructions.\n");
    test_faddm();

    return done_testing();
}
