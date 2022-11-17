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
#include "fpu_structs.h"

void test_fldmu_16()
{
    __fp16 f[4] = {1.0, 2.0, 3.0, 4.0};
    __fp16 fldmu_16_res[4];
    int bias;
    asm volatile ("mov r0, %2;\
                  mov r1, %1;\
                  fldmu.16 vr0-vr3, (r0);\
                  fstmu.16 vr0-vr3, (r1);\
                  sub %0, r0, %2"
                  : "=&r"(bias)
                  : "r"(&fldmu_16_res), "r"(&f)
                  : "vr0", "vr1", "vr2", "vr3", "r0", "r1"
    );
    TEST(f[0] == fldmu_16_res[0]
        && f[1] == fldmu_16_res[1]
        && f[2] == fldmu_16_res[2]
        && f[3] == fldmu_16_res[3]
        && bias == 8);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fldmu.16 instructions.\n");
    test_fldmu_16();

    return done_testing();
}
