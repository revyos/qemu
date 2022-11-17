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

/* fabsm */
void test_fabsm()
{
    float a = -1.5, fabsm_res_1 = 0;
    float b = 1.5, fabsm_res_2 = 0;
    asm ("fmtvrl vr0, %2;\
        fmtvrh vr0, %3;\
        fabsm vr1, vr0;\
        fmfvrl %0, vr1;\
        fmfvrh %1, vr1;"
        : "=r"(fabsm_res_1), "=r"(fabsm_res_2)
        : "r"(a), "r"(b)
        : "vr0", "vr1"
    );
    TEST(fabsm_res_1 == 1.5 && fabsm_res_2 == 1.5);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fabsm instructions.\n");
    test_fabsm();

    return done_testing();
}
