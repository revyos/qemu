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

void test_str_d()
{
    int res[4];
    int a[2] = {0x10203040, 0x50607080};
    asm ("movi r0, 1;\
         mov r1, %1;\
         mov r2, %2;\
         str.d r1, (%0, r0 << 2);"
         :
         : "r"(res), "r"(a[0]), "r"(a[1])
         : "r0", "r1", "r2"
    );
    TEST(res[1] == a[0] && res[2] == a[1]);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu str.d instructions.\n");
    test_str_d();

    return done_testing();
}
