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

/* fabs_16 */
void test_fabs_16()
{
    __fp16 a = -1.5, fabs_16_res = 0;
    asm ("fmtvrl vr0, %1;\
        fabs.16 vr1, vr0;\
        fmfvrl %0, vr1;"
        : "=r"(fabs_16_res)
        : "r"(a)
        : "vr0", "vr1"
    );
    TEST(fabs_16_res == 1.5);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fabs_16 instructions.\n");
    test_fabs_16();

    return done_testing();
}
