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
struct op1_res1_f32 data0[] = {
    {.op1.d = 0x483471f7, .res.d = 0x48347200},
    {.op1.d = 0x46f2e02b, .res.d = 0x46f2e000},
    {.op1.d = 0xc785dc35, .res.d = 0xc785dc00},
    {.op1.d = 0x47ad69d9, .res.d = 0x47ad6a00},
};

/* rz */
struct op1_res1_f32 data1[] = {
    {.op1.d = 0x483471f7, .res.d = 0x483471c0},
    {.op1.d = 0x46f2e02b, .res.d = 0x46f2e000},
    {.op1.d = 0xc785dc35, .res.d = 0xc785dc00},
    {.op1.d = 0x47ad69d9, .res.d = 0x47ad6980},
};

/* rpi */
struct op1_res1_f32 data2[] = {
    {.op1.d = 0x483471f7, .res.d = 0x48347200},
    {.op1.d = 0x46f2e02b, .res.d = 0x46f2e200},
    {.op1.d = 0xc785dc35, .res.d = 0xc785dc00},
    {.op1.d = 0x47ad69d9, .res.d = 0x47ad6a00},
};

/* rni */
struct op1_res1_f32 data3[] = {
    {.op1.d = 0x483471f7, .res.d = 0x483471c0},
    {.op1.d = 0x46f2e02b, .res.d = 0x46f2e000},
    {.op1.d = 0xc785dc35, .res.d = 0xc785dc80},
    {.op1.d = 0x47ad69d9, .res.d = 0x47ad6980},
};

void test_fftofi_f32_rn(float32 a, float32 expt)
{
    float32 res;
    asm ("fftofi.f32.rn %0, %1;"
         : "=v"(res.f)
         : "v"(a.f)
    );
    TEST(res.f == expt.f);
}

void test_fftofi_f32_rz(float32 a, float32 expt)
{
    float32 res;
    asm ("fftofi.f32.rz %0, %1;"
         : "=v"(res.f)
         : "v"(a.f)
    );
    TEST(res.f == expt.f);
}

void test_fftofi_f32_rpi(float32 a, float32 expt)
{
    float32 res;
    asm ("fftofi.f32.rpi %0, %1;"
         : "=v"(res.f)
         : "v"(a.f)
    );
    TEST(res.f == expt.f);
}

void test_fftofi_f32_rni(float32 a, float32 expt)
{
    float32 res;
    asm ("fftofi.f32.rni %0, %1;"
         : "=v"(res.f)
         : "v"(a.f)
    );
    TEST(res.f == expt.f);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fftofi.f32.rm/fftof.f32.rm instructions.\n");

    for (i = 0; i < sizeof(data0) / sizeof(struct op1_res1_f32); i++) {
        test_fftofi_f32_rn(data0[i].op1, data0[i].res);
    }

    for (i = 0; i < sizeof(data1) / sizeof(struct op1_res1_f32); i++) {
        test_fftofi_f32_rz(data1[i].op1, data1[i].res);
    }

    for (i = 0; i < sizeof(data2) / sizeof(struct op1_res1_f32); i++) {
        test_fftofi_f32_rpi(data2[i].op1, data2[i].res);
    }

    for (i = 0; i < sizeof(data3) / sizeof(struct op1_res1_f32); i++) {
        test_fftofi_f32_rni(data3[i].op1, data3[i].res);
    }

    return done_testing();
}
