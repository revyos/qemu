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

void test_fmovi_16(__fp16 expt)
{
    __fp16 res;
    asm ("fmovi.16 %0, -1.5;"
         : "=v"(res)
    );
    TEST(res == expt);
}

void test_fmovi_16_xpinf(__fp16 expt)
{
    __fp16 res;
    asm ("fmovi.16 %0, +4088.0;"
         : "=v"(res)
    );
    TEST(res == expt);
}

void test_fmovi_16_xninf(__fp16 expt)
{
    __fp16 res;
    asm ("fmovi.16 %0, -4088.0;"
         : "=v"(res)
    );
    TEST(res == expt);
}


int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fmovi.16 instructions.\n");

    test_fmovi_16(-1.5);
    test_fmovi_16_xpinf(4088.0);
    test_fmovi_16_xninf(-4088.0);
    return done_testing();
}
