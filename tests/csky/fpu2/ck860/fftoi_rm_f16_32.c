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

/* fmtvrl, fmfvrl, fftoi.f16.s32 */
void test_fftoi_f16_s32()
{
    __fp16 a = -1.5;
    int32_t res;
    asm volatile ("fftoi.f16.s32.rn vr0, %1;\
        fmfvrl %0, vr0;"
        : "=r"(res)
        : "v"(a)
        : "vr0"
        );
    /*printf("a = %f, res = %d\n", a, res);*/
    TEST(res == -2);

    asm volatile ("fftoi.f16.s32.rz vr0, %1;\
        fmfvrl %0, vr0;"
        : "=r"(res)
        : "v"(a)
        : "vr0"
        );
    /*printf("a = %f, res = %d\n", a, res);*/
    TEST(res == -1);

    asm volatile ("fftoi.f16.s32.rpi vr0, %1;\
        fmfvrl %0, vr0;"
        : "=r"(res)
        : "v"(a)
        : "vr0"
        );
    /*printf("a = %f, res = %d\n", a, res);*/
    TEST(res == -1);

    asm volatile ("fftoi.f16.s32.rni vr0, %1;\
        fmfvrl %0, vr0;"
        : "=r"(res)
        : "v"(a)
        : "vr0"
        );
    /*printf("a = %f, res = %d\n", a, res);*/
    TEST(res == -2);
}

/* fmtvrl, fmfvrl, fftoi.f16.u32 */
void test_fftoi_f16_u32()
{
    __fp16 a = 1.75;
    int32_t res;
    asm volatile ("fftoi.f16.u32.rn vr0, %1;\
        fmfvrl %0, vr0;"
        : "=r"(res)
        : "v"(a)
        : "vr0"
        );
    /*printf("a = %f, res = %d\n", a, res);*/
    TEST(res == 2);

    asm volatile ("fftoi.f16.u32.rz vr0, %1;\
        fmfvrl %0, vr0;"
        : "=r"(res)
        : "v"(a)
        : "vr0"
        );
    /*printf("a = %f, res = %d\n", a, res);*/
    TEST(res == 1);

    asm volatile ("fftoi.f16.u32.rpi vr0, %1;\
        fmfvrl %0, vr0;"
        : "=r"(res)
        : "v"(a)
        : "vr0"
        );
    /*printf("a = %f, res = %d\n", a, res);*/
    TEST(res == 2);

    asm volatile ("fftoi.f16.u32.rni vr0, %1;\
        fmfvrl %0, vr0;"
        : "=r"(res)
        : "v"(a)
        : "vr0"
        );
    /*printf("a = %f, res = %d\n", a, res);*/
    TEST(res == 1);
}

/* fmtvrl, fmfvrl, fftoi.rm f32 to s32/u32 */
int main()
{
    int i = 0;
    init_testsuite("Testing fpu fftoi.f16.s32 fftoi.f16.u32 instructions.\n");
    test_fftoi_f16_s32();
    test_fftoi_f16_u32();

    return done_testing();
}
