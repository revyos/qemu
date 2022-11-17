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
    asm ("movi r0, 1;\n\
         mov r1, r0;\n\
         mov r2, r0;\n\
         mul.u32 r0, r1, r2;\n\
         mul.s32 r0, r1, r2;\n\
         mula.s32 r0, r1, r2;\n\
         mula.s32 r0, r1, r2;\n\
         mula.32.l r0, r1, r2;\n\
         mulall.s16.s r0, r1, r2;\n\
         divul r0, r1, r2;\n\
         divsl r0, r1, r2;\n"
        :
        :
        : "r0", "r1", "r2"
    );
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fadd.32 instructions.\n");
    test_fadds();

    return done_testing();
}
