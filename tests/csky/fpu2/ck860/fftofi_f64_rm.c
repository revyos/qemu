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
struct op1_res1_f64 data0[] = {
    {.op1.f = 1.50,     .res.f = 2.0    },
    {.op1.f = -1.25,    .res.f = -1.0   },
    {.op1.f = 8773.2,   .res.f = 8773.0 },
    {.op1.f = 0.0,      .res.f = 0.0    },
};

/* rz */
struct op1_res1_f64 data1[] = {
    {.op1.f = 1.50,     .res.f = 1.0    },
    {.op1.f = -1.25,    .res.f = -1     },
    {.op1.f = 8773.2,   .res.f = 8773.0 },
    {.op1.f = 0.0,      .res.f = 0.0    },
};

/* rpi */
struct op1_res1_f64 data2[] = {
    {.op1.f = 1.50,     .res.f = 2.0    },
    {.op1.f = -1.25,    .res.f = -1.0   },
    {.op1.f = 8773.2,   .res.f = 8774.0 },
    {.op1.f = 0.0,      .res.f = 0.0    },
};

/* rni */
struct op1_res1_f64 data3[] = {
    {.op1.f = 1.50,     .res.f = 1.0    },
    {.op1.f = -1.25,    .res.f = -2.0   },
    {.op1.f = 8773.2,   .res.f = 8773.0 },
    {.op1.f = 0.0,      .res.f = 0.0    },
};

void test_fftofi_f64_rn(float64 a, float64 expt)
{
    float64 res;
    asm ("fftofi.f64.rn %0, %1;"
         : "=v"(res.f)
         : "v"(a.f)
    );
    TEST(res.f == expt.f);
}

void test_fftofi_f64_rz(float64 a, float64 expt)
{
    float64 res;
    asm ("fftofi.f64.rz %0, %1;"
         : "=v"(res.f)
         : "v"(a.f)
    );
    TEST(res.f == expt.f);
}

void test_fftofi_f64_rpi(float64 a, float64 expt)
{
    float64 res;
    asm ("fftofi.f64.rpi %0, %1;"
         : "=v"(res.f)
         : "v"(a.f)
    );
    TEST(res.f == expt.f);
}

void test_fftofi_f64_rni(float64 a, float64 expt)
{
    float64 res;
    asm ("fftofi.f64.rni %0, %1;"
         : "=v"(res.f)
         : "v"(a.f)
    );
    TEST(res.f == expt.f);
}

int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu fftofi.f64.rm/fftof.f64.rm instructions.\n");

    for (i = 0; i < sizeof(data0) / sizeof(struct op1_res1_f64); i++) {
        test_fftofi_f64_rn(data0[i].op1, data0[i].res);
    }

    for (i = 0; i < sizeof(data1) / sizeof(struct op1_res1_f64); i++) {
        test_fftofi_f64_rz(data1[i].op1, data1[i].res);
    }

    for (i = 0; i < sizeof(data2) / sizeof(struct op1_res1_f64); i++) {
        test_fftofi_f64_rpi(data2[i].op1, data2[i].res);
    }

    for (i = 0; i < sizeof(data3) / sizeof(struct op1_res1_f64); i++) {
        test_fftofi_f64_rni(data3[i].op1, data3[i].res);
    }

    return done_testing();
}
