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

unary_calculation_64_t samples_fnegm[] = {
    {.op1.a.f[0] = -2.0, .op1.a.f[1] = -1.0,
        .result.a.f[0] = 2.0, .result.a.f[1] = 1.0},
    {.op1.a.f[0] = 2.0, .op1.a.f[1] = -1.5,
        .result.a.f[0] = -2.0, .result.a.f[1] = 1.5},
};

/* fnegm */
void test_fabsm()
{
    union {
        double d;
        unsigned int i[2];
        float f[2];
    } a, fnegm_res;
    for (int i = 0;
        i < sizeof(samples_fnegm) / sizeof(samples_fnegm[0]);
        i++){
        a.d = samples_fnegm[i].op1.a.d;
        asm ("ldw r2, (%2, 0);\
            ldw r3, (%3, 0);\
            fmtd r2, fr0;\
            fnegm fr2, fr0, r2;\
            fmfd r2, fr2;\
            stw r2, (%0, 0);\
            stw r3, (%1, 0);"
            :
            : "r"(&fnegm_res.i[0]), "r"(&fnegm_res.i[1]),
            "r"(&a.i[0]), "r"(&a.i[1])
            : "r2"
        );
        TEST(fnegm_res.f[0] == samples_fnegm[i].result.a.f[0] &&
            fnegm_res.f[1] == samples_fnegm[i].result.a.f[1]);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fnegm instructions.\n");
    test_fabsm();

    return done_testing();
}
