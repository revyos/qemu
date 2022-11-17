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

/* fldmm */
void test_fldmm()
{
    double f[4] = {1.0, 2.0, 3.0, 4.0};
    double fldmm_res[4];
    asm volatile ("fldmm vr0-vr3, (%1);\
        fstmm vr0-vr3, (%0);"
        :
        : "r"(&fldmm_res), "r"(&f)
        : "vr0", "vr1", "vr2", "vr3"
    );
    TEST(f[0] == fldmm_res[0]
        && f[1] == fldmm_res[1]
        && f[2] == fldmm_res[2]
        && f[3] == fldmm_res[3]);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fldmm instructions.\n");
    test_fldmm();

    return done_testing();
}
