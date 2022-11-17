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

struct binary_calculation_64 samples_fcmphsd[] = {
    {.op1.a.d = 1.5, .op2.a.d = -1.5, .result.a.ull = 0x1}, /* 1.5, -1.5 */
    {.op1.a.d = -1.5, .op2.a.d = 1.5, .result.a.ull = 0x0}, /* -1.5, 1.5 */
    {.op1.a.d = 1.5, .op2.a.d = 1.5, .result.a.ull = 0x1}, /* 1.5, 1.5 */
};

/* fmtvrl, mfcr32, fcmphsd */
void test_fcmphsd()
{
    unsigned int fcmphsd_psr;
    int i = 0;
    for (i = 0;
        i < sizeof(samples_fcmphsd) / sizeof(struct binary_calculation_64);
        i++)
    {
        asm volatile ("fmtvrl vr0, %1;\
            fmtvrh vr0, %2;\
            fmtvrl vr1, %3;\
            fmtvrh vr1, %4;\
            fcmphsd vr0, vr1;\
            bt32 .L1;\
            movi32 r0, 0;\
            st32.w r0, (%0, 0);\
            br32 .L2;\
            .L1:\
            movi r0, 1;\
            st32.w r0, (%0, 0);\
            .L2:"
            :
            : "r"(&fcmphsd_psr), "r"(samples_fcmphsd[i].op1.a.i[0]),
            "r"(samples_fcmphsd[i].op1.a.i[1]),
            "r"(samples_fcmphsd[i].op2.a.i[0]),
            "r"(samples_fcmphsd[i].op2.a.i[1])
            : "vr0", "vr1", "r0"
        );
        TEST((fcmphsd_psr & 0x1) == samples_fcmphsd[i].result.a.ull);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fcmphsd instructions.\n");
    test_fcmphsd();

    return done_testing();
}
