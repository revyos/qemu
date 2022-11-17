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

/* fmtvrl, fmfvrl, fstosi */
void test_fstosi()
{
    float a = -1.5;
    int res;
    asm ("fmtvrl vr0, %1;\
        fstosi.rn vr1, vr0;\
        fmfvrl %0, vr1"
        : "=r"(res)
        : "r"(a)
        : "vr0", "vr1"
        );
    /*printf("a = %f, res = %d\n", a, res);*/
    TEST(res == -2);

    asm("fmtvrl vr0, %1;\
        fstosi.rz vr1, vr0;\
        fmfvrl %0, vr1;"
        : "=r"(res)
        : "r"(a)
        : "vr0", "vr1"
    );
    /*printf("a = %f, res = %d\n", a, res);*/
    TEST(res == -1);

    asm("fmtvrl vr0, %1;\
        fstosi.rpi vr1, vr0;\
        fmfvrl %0, vr1;"
        : "=r"(res)
        : "r"(a)
        : "vr0", "vr1"
    );
    /*printf("a = %f, res = %d\n", a, res);*/
    TEST(res == -1);

    asm("fmtvrl vr0, %1;\
        fstosi.rni vr1, vr0;\
        fmfvrl %0, vr1;"
        : "=r"(res)
        : "r"(a)
        : "vr0", "vr1"
    );
    /*printf("a = %f, res = %d\n", a, res);*/
    TEST(res == -2);
}

/* fmtvrl, fmfvrl, fstoui */
void test_fstoui()
{
    float a = 1.5;
    unsigned int res;
    asm ("fmtvrl vr0, %1;\
        fstoui.rn vr1, vr0;\
        fmfvrl %0, vr1"
        : "=r"(res)
        : "r"(a)
        : "vr0", "vr1"
        );
    TEST(res == 2);

    asm("fmtvrl vr0, %1;\
        fstoui.rz vr1, vr0;\
        fmfvrl %0, vr1;"
        : "=r"(res)
        : "r"(a)
        : "vr0", "vr1"
    );
    TEST(res == 1);

    asm("fmtvrl vr0, %1;\
        fstoui.rpi vr1, vr0;\
        fmfvrl %0, vr1;"
        : "=r"(res)
        : "r"(a)
        : "vr0", "vr1"
    );
    TEST(res == 2);

    asm("fmtvrl vr0, %1;\
        fstoui.rni vr1, vr0;\
        fmfvrl %0, vr1;"
        : "=r"(res)
        : "r"(a)
        : "vr0", "vr1"
    );
    TEST(res == 1);
}

/* fmtvrl, fmfvrl, fftoi.rm f32 to s32/u32 */
int main()
{
    int i = 0;
    init_testsuite("Testing fpu fstosi fstoui instructions.\n");
    test_fstosi();
    test_fstoui();

    return done_testing();
}
