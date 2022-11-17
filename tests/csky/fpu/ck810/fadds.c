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

/* fadds */
void test_fadds()
{
    float a = -1.5, b = 1.0, fadds_res = 0;
    asm ("fmtvrl vr0, %1;\
        fmtvrl vr1, %2;\
        fadds vr2, vr0, vr1;\
        fmfvrl %0, vr2;"
        : "=r"(fadds_res)
        : "r"(a), "r"(b)
        : "vr0", "vr1"
    );
    TEST(fadds_res == -0.5);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fadds instructions.\n");
    test_fadds();

    return done_testing();
}
