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

unary_calculation_64_t samples_fnegd[] = {
    {.op1.a.d = -2.0, .result.a.d = 2.0},
    {.op1.a.d = 2.0, .result.a.d = -2.0},
};

/* fnegd */
void test_fnegd()
{
    union {
        double d;
        unsigned int i[2];
    } a, fnegd_res;
    for (int i = 0;
        i < sizeof(samples_fnegd) / sizeof(samples_fnegd[0]);
        i++){
        a.d = samples_fnegd[i].op1.a.d;
        asm ("ldw r2, (%2, 0);\
            ldw r3, (%3, 0);\
            fmtd r2, fr0;\
            fnegd fr2, fr0, r2;\
            fmfd r2, fr2;\
            stw r2, (%0, 0);\
            stw r3, (%1, 0);"
            :
            : "r"(&fnegd_res.i[0]), "r"(&fnegd_res.i[1]),
            "r"(&a.i[0]), "r"(&a.i[1])
            : "r2"
        );
        TEST(fnegd_res.d == samples_fnegd[i].result.a.d);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fnegd instructions.\n");
    test_fnegd();

    return done_testing();
}
