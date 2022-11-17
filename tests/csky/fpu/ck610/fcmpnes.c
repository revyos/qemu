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

struct binary_calculation samples_fcmpnes_32[] = {
    {.op1.a.f = 1.5, .op2.a.f = -1.5, .result.a.ui = 1}, /* 1.5, -1.5 */
    {.op1.a.f = -1.5, .op2.a.f = 1.5, .result.a.ui = 1}, /* -1.5, 1.5 */
    {.op1.a.f = 1.5, .op2.a.f = 1.5, .result.a.ui = 0}, /* 1.5, 1.5 */
};

/* fmtvrl, mfcr32, fcmpnes */
void test_fcmpnes()
{
    unsigned int fcmpnes_psr;
    int i = 0;
    for (i = 0;
        i < sizeof(samples_fcmpnes_32) / sizeof(struct binary_calculation);
        i++)
    {
        asm ("fmts %1, fr0;\n\t"\
            "fmts %2, fr1;\n\t"\
            "fcmpnes fr0, fr1, r2;\n\t"\
            "bt set_true;\n\t"\
            "movi %0, 0\n\t"\
            "br done;\n\t" \
            "set_true:\n\t" \
            "movi %0, 1\n\t" \
            "done:\n\t"
            : "=r"(fcmpnes_psr)
            : "r"(samples_fcmpnes_32[i].op1.a.f),
            "r"(samples_fcmpnes_32[i].op2.a.f)
            : "fr0", "fr1", "r2"
        );
        TEST((fcmpnes_psr & 0x1)
            == samples_fcmpnes_32[i].result.a.ui);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fcmpnes instructions.\n");
    test_fcmpnes();

    return done_testing();
}
