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

struct ternary_calculation_64 samples_fnmscd[] = {
    {.op1.a.d = -3.0, .op2.a.d = 2.0, .op3.a.d = 2.0, .result.a.d = -1.0},
    {.op1.a.d = 3.0, .op2.a.d = 2.0, .op3.a.d = 2.0, .result.a.d = -7.0}
};

/* fnmscd */
void test_fnmscd()
{
    union {
        double d;
        unsigned int i[2];
    } a, b, c, fnmscd_res;
    for (int i = 0;
        i < sizeof(samples_fnmscd) / sizeof(samples_fnmscd[0]);
        i++){
        a.d = samples_fnmscd[i].op1.a.d;
        b.d = samples_fnmscd[i].op2.a.d;
        c.d = samples_fnmscd[i].op3.a.d;
        asm ("ldw r2, (%2, 0);\
            ldw r3, (%2, 4);\
            fmtd r2, fr4;\
            ldw r4, (%3, 0);\
            ldw r5, (%3, 4);\
            fmtd r4, fr0;\
            ldw r6, (%4, 0);\
            ldw r7, (%4, 4);\
            fmtd r6, fr2;\
            fnmscd fr4, fr0, fr2, r2;\
            fmfd r2, fr4;\
            mov %0, r2;\
            mov %1, r3;"
            : "=r"(fnmscd_res.i[0]),  "=r"(fnmscd_res.i[1])
            :"r"(&a.i[0]), "r"(&b.i[0]), "r"(&c.i[0])
            : "r2", "r3", "r4", "r5", "r6", "r7"
        );
        TEST(fnmscd_res.d == samples_fnmscd[i].result.a.d);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fnmscd instructions.\n");
    test_fnmscd();

    return done_testing();
}
