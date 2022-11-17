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
#include "test_device.h"

struct unary_calculation samples_fcmpzuos_32[] = {
    {0x7fc00000, 0x1}, /* QNaN */
    {0x3f800000, 0x0}, /* 1.0 */
    {0x7f800001, 0x1}, /* SNaN */
    {0xff800001, 0x1}, /* SNaN */
    {0xffc0000c, 0x1}, /* QNaN */
};

/* fmtvrl, mfcr32, fcmpzuos */
void test_fcmpzuos()
{
    unsigned int fcmpzuos_psr;
    int i = 0;
    for (i = 0;
        i < sizeof(samples_fcmpzuos_32) / sizeof(struct unary_calculation);
        i++)
    {
        asm ("fmtvrl vr0, %1;\
            fcmpzuos vr0;\
            mfcr32 %0, cr<0, 0>"
            : "=r"(fcmpzuos_psr)
            : "r"(samples_fcmpzuos_32[i].op1)
            : "vr0"
        );
        TEST((fcmpzuos_psr & 0x1) == samples_fcmpzuos_32[i].result);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fcmpzuos instructions.\n");
    test_fcmpzuos();

    return done_testing();
}
