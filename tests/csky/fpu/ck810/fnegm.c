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

struct unary_calculation_64 samples_fnegm_64[] = {
    {.op1.a.ull = 0xbfc000003fc00000, .result.a.ull = 0x3fc00000bfc00000},
    {.op1.a.ull = 0x3fc00000bfc00000, .result.a.ull = 0xbfc000003fc00000},
};

/* fnegm */
void test_fnegm()
{
    operand_64_t fnegm_res;
    int i = 0;
    for (i = 0;
        i < sizeof(samples_fnegm_64) / sizeof(struct unary_calculation_64);
        i++)
    {
        asm ("fmtvrl vr0, %2;\
            fmtvrh vr0, %3;\
            fnegm vr1, vr0;\
            fmfvrl %0, vr1;\
            fmfvrh %1, vr1;"
            : "=r"(fnegm_res.a.i[0]), "=r"(fnegm_res.a.i[1])
            : "r"(samples_fnegm_64[i].op1.a.i[0]),
            "r"(samples_fnegm_64[i].op1.a.i[1])
            : "vr0", "vr1"
        );
        TEST(fnegm_res.a.ull == samples_fnegm_64[i].result.a.ull);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fnegm instructions.\n");
    test_fnegm();

    return done_testing();
}
