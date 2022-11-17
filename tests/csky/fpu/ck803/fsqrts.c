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
#include "test_device.h"

/* sqrt(4.0) = 2.0 */
struct unary_calculation samples_fsqrts_32[] = {
    {0x40800000, 0x40000000}
};

void test_fsqrts()
{
    unsigned int fsqrts_res;
    int i = 0;
    for (i = 0;
        i < sizeof(samples_fsqrts_32) / sizeof(struct unary_calculation);
        i++) {
        asm ("fmtvrl vr0, %1;\
            fsqrts vr1, vr0;\
            fmfvrl %0, vr1;"
            : "=r"(fsqrts_res)
            : "r"(samples_fsqrts_32[i].op1)
            : "vr0", "vr1"
        );
        TEST(fsqrts_res == samples_fsqrts_32[i].result);
    }
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fsqrts instructions.\n");
    test_fsqrts();

    return done_testing();
}
