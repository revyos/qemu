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

/* rn */
struct op1_res1_f16 data0[] = {
    {.op1.d = 0x4aee, .res.d = 0x4b00},
    {.op1.d = 0x40aa, .res.d = 0x4000},
    {.op1.d = 0xc524, .res.d = 0xc500},
    {.op1.d = 0x46a9, .res.d = 0x4700},
    {.op1.d = 0x4a65, .res.d = 0x4a80},
    {.op1.d = 0x404e, .res.d = 0x4000},
    {.op1.d = 0xc4bf, .res.d = 0xc500},
    {.op1.d = 0x4626, .res.d = 0x4600},
};

/* rz */
struct op1_res1_f16 data1[] = {
    {.op1.d = 0x4aee, .res.d = 0x4a80},
    {.op1.d = 0x40aa, .res.d = 0x4000},
    {.op1.d = 0xc524, .res.d = 0xc500},
    {.op1.d = 0x46a9, .res.d = 0x4600},
    {.op1.d = 0x4a65, .res.d = 0x4a00},
    {.op1.d = 0x404e, .res.d = 0x4000},
    {.op1.d = 0xc4bf, .res.d = 0xc400},
    {.op1.d = 0x4626, .res.d = 0x4600},
};

/* rpi */
struct op1_res1_f16 data2[] = {
    {.op1.d = 0x4aee, .res.d = 0x4b00},
    {.op1.d = 0x40aa, .res.d = 0x4200},
    {.op1.d = 0xc524, .res.d = 0xc500},
    {.op1.d = 0x46a9, .res.d = 0x4700},
    {.op1.d = 0x4a65, .res.d = 0x4a80},
    {.op1.d = 0x404e, .res.d = 0x4200},
    {.op1.d = 0xc4bf, .res.d = 0xc400},
    {.op1.d = 0x4626, .res.d = 0x4700},
};

/* rni */
struct op1_res1_f16 data3[] = {
    {.op1.d = 0x4aee, .res.d = 0x4a80},
    {.op1.d = 0x40aa, .res.d = 0x4000},
    {.op1.d = 0xc524, .res.d = 0xc600},
    {.op1.d = 0x46a9, .res.d = 0x4600},
    {.op1.d = 0x4a65, .res.d = 0x4a00},
    {.op1.d = 0x404e, .res.d = 0x4000},
    {.op1.d = 0xc4bf, .res.d = 0xc500},
    {.op1.d = 0x4626, .res.d = 0x4600},
};

void test_fftofi_f16_rn(float16 a, float16 expt)
{
    float16 res;
    asm ("fftofi.f16.rn %0, %1;"
         : "=v"(res.f)
         : "v"(a.f)
    );
    TEST(res.f == expt.f);
}

void test_fftofi_f16_rz(float16 a, float16 expt)
{
    float16 res;
    asm ("fftofi.f16.rz %0, %1;"
         : "=v"(res.f)
         : "v"(a.f)
    );
    TEST(res.f == expt.f);
}

void test_fftofi_f16_rpi(float16 a, float16 expt)
{
    float16 res;
    asm ("fftofi.f16.rpi %0, %1;"
         : "=v"(res.f)
         : "v"(a.f)
    );
    TEST(res.f == expt.f);
}

void test_fftofi_f16_rni(float16 a, float16 expt)
{
    float16 res;
    asm ("fftofi.f16.rni %0, %1;"
         : "=v"(res.f)
         : "v"(a.f)
    );
    TEST(res.f == expt.f);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fftofi.f16.rm/fftof.f16.rm instructions.\n");

    for (i = 0; i < sizeof(data0) / sizeof(struct op1_res1_f16); i++) {
        test_fftofi_f16_rn(data0[i].op1, data0[i].res);
    }

    for (i = 0; i < sizeof(data1) / sizeof(struct op1_res1_f16); i++) {
        test_fftofi_f16_rz(data1[i].op1, data1[i].res);
    }

    for (i = 0; i < sizeof(data2) / sizeof(struct op1_res1_f16); i++) {
        test_fftofi_f16_rpi(data2[i].op1, data2[i].res);
    }

    for (i = 0; i < sizeof(data3) / sizeof(struct op1_res1_f16); i++) {
        test_fftofi_f16_rni(data3[i].op1, data3[i].res);
    }

    return done_testing();
}
