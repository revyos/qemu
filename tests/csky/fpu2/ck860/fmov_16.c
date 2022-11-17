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

/* fmov.16 */
void test_fmov_16()
{
    __fp16 a = 1.5, fmov_16_res = 0;
    asm ("fmtvr.16 vr0, %1;\
        fmov.16 vr1, vr0;\
        fmfvr.16 %0, vr1;"
        : "=r"(fmov_16_res)
        : "r"(a)
        : "vr0", "vr1"
    );
    TEST(fmov_16_res == 1.5);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fmov_16 instructions.\n");
    test_fmov_16();

    return done_testing();
}
