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

struct op2_res1_s16_s16_f64 data0[] = {
    {.op1 = 0xfffe,     .op2 = 1,   .res.f = -1.0,    },
    {.op1 = 0,          .op2 = 2,   .res.d = SpZero,  },
    {.op1 = 0xc,        .op2 = 3,   .res.f = 1.5,     },
};

struct op2_res1_u16_s16_f64 data1[] = {
    {.op1 = 0xfffe,     .op2 = 1,   .res.f = 32767.0,    },
    {.op1 = 0,          .op2 = 2,   .res.d = SpZero,  },
    {.op1 = 0xc,        .op2 = 3,   .res.f = 1.5,     },
};


void test_fxtof_s16_f64(int16_t a, int16_t b, float64 expt)
{
    float64 res;
    asm ("subi %2, %2, 1;\
         andi %2, %2, 0x1f;\
         lsli %2, %2, 16;\
         mfcr r0, cr<1, 2>;\
         lrw  r1, 0xffe0ffff;\
         and r0, r0, r1;\
         or  r0, r0, %2;\
         mtcr r0, cr<1, 2>;\
         fxtof.s16.f64 %0, %1;\
         "
         : "=v"(res.f)
         : "v"(a), "r"(b)
         : "r0", "r1"
    );
    TEST(res.f == expt.f);
}

void test_fxtof_u16_f64(uint16_t a, int16_t b, float64 expt)
{
    float64 res;
    asm ("subi %2, %2, 1;\
         andi %2, %2, 0x1f;\
         lsli %2, %2, 16;\
         mfcr r0, cr<1, 2>;\
         lrw  r1, 0xffe0ffff;\
         and r0, r0, r1;\
         or  r0, r0, %2;\
         mtcr r0, cr<1, 2>;\
         fxtof.u16.f64 %0, %1;\
         "
         : "=v"(res.f)
         : "v"(a), "r"(b)
         : "r0", "r1"
    );
    TEST(res.f == expt.f);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fxtof.s16.f64/fxtof.u16.f64 instructions.\n");

    for (i = 0; i < sizeof(data0) / sizeof(struct op2_res1_s16_s16_f64); i++) {
        test_fxtof_s16_f64(data0[i].op1, data0[i].op2, data0[i].res);
    }

    for (i = 0; i < sizeof(data1) / sizeof(struct op2_res1_u16_s16_f64); i++) {
        test_fxtof_u16_f64(data1[i].op1, data1[i].op2, data1[i].res);
    }

    return done_testing();
}
