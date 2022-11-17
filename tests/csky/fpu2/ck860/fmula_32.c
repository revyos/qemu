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

/* -1.0 + -1.5 * 1.5 = 3.25 */
struct ternary_calculation samples_fmacs_32[] = {
    {0xbf800000, 0xbfc00000, 0x3fc00000, 0xc0500000},
};

void test_fmacs()
{
    unsigned int fmacs_res;
    int i = 0;
    for (i = 0;
        i < sizeof(samples_fmacs_32) / sizeof(struct ternary_calculation);
        i++) {
        asm ("fmtvrl vr0, %2;\
            fmtvrl vr1, %3;\
            fmtvrl vr2, %1;\
            fmacs vr2, vr0, vr1;\
            fmfvrl %0, vr2;"
            : "=r"(fmacs_res)
            : "r"(samples_fmacs_32[i].op1),
            "r"(samples_fmacs_32[i].op2),
            "r"(samples_fmacs_32[i].op3)
            : "vr0", "vr1", "vr2"
        );
        TEST(fmacs_res == samples_fmacs_32[i].result);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fmacs instructions.\n");
    test_fmacs();

    return done_testing();
}
