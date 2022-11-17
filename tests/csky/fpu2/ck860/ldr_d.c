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

void test_ldr_d()
{
    int res[2];
    int a[4] = {0x10203040, 0x50607080, 0x90a0b0c0, 0xd0e0f000};
    asm volatile ("movi r2, 1;\
         ldr.d r0, (%2, r2 << 2);\
         mov %0, r0;\
         mov %1, r1;"
        : "=&r"(res[0]), "=&r"(res[1])
        : "r"(&a[0])
        : "r0", "r1", "r2"
    );
    TEST(res[0] == a[1] && res[1] == a[2]);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu ldr.d instructions.\n");
    test_ldr_d();

    return done_testing();
}
