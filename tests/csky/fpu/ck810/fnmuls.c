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

struct binary_calculation samples_fnmuls_32[] = {
    {0xbfc00000, 0x3fc00000, 0x40100000},
};

void test_fnmuls()
{
    unsigned int fnmuls_res;
    int i = 0;
    for (i = 0;
        i < sizeof(samples_fnmuls_32) / sizeof(struct binary_calculation);
        i++) {
        asm ("fmtvrl vr0, %1;\
            fmtvrl vr1, %2;\
            fnmuls vr2, vr0, vr1;\
            fmfvrl %0, vr2;"
            : "=r"(fnmuls_res)
            : "r"(samples_fnmuls_32[i].op1), "r"(samples_fnmuls_32[i].op2)
            : "vr0", "vr1", "vr2"
        );
        TEST(fnmuls_res == samples_fnmuls_32[i].result);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fnmuls instructions.\n");
    test_fnmuls();

    return done_testing();
}
