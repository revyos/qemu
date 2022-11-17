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

void test_fsub_16()
{
    unsigned short int fsub_16_res;
    float16 a, b, c;
    a.f = -1.5;
    b.f = 1.5;
    c.f = -3;
    asm ("fmtvrl vr0, %1;\
        fmtvrl vr1, %2;\
        fsub.16 vr2, vr0, vr1;\
        fmfvrl %0, vr2;"
        : "=r"(fsub_16_res)
        : "r"(a.d), "r"(b.d)
        : "vr0", "vr1", "vr2"
    );
    TEST(fsub_16_res == c.d);
}
int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fsub_16 instructions.\n");
    test_fsub_16();

    return done_testing();
}
