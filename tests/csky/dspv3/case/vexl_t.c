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
#include "dspv3_insn.h"

struct vdsp_reg src0[] = {
    {
        .fixs64 = {0x2222222211111111, 0x2222222211111111, },
        .fixs32 = {0x22221111, 0x22221111, 0x22221111, 0x22221111,  },
        .fixs16 = {0x2211, 0x2211, 0x2211, 0x2211, 0x2211, 0x2211, 0x2211, 0x2211, },
        .fixs8 = {0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, },
    },
};

/* 64 32 16 8 */
int src1[] = {0xc0f, 0x5c8, 0x2c4, 0x142};

struct vdsp_reg src2[] = {
    {
        .fixs64 = {0x3333333333333333, 0x3333333333333333, },
        .fixs32 = {0x33333333, 0x33333333, 0x33333333, 0x33333333, },
        .fixs16 = {0x3333, 0x3333, 0x3333, 0x3333, 0x3333, 0x3333, 0x3333, 0x3333, },
        .fixs8 = {0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, },
    },
};

struct vdsp_reg dst0[] = {
    {
        .fixs64 = {0x3333333044442222, 0x3333333044442222, },
        .fixs32 = {0x33332211, 0x33332211, 0x33332211, 0x33332211, },
        .fixs16 = {0x3321, 0x3321, 0x3321, 0x3321, 0x3321, 0x3321, 0x3321, 0x3321, },
        .fixs8 = {0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vexl.t\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vexl_8(src0[i].fixs8, src1[3], src2[i].fixs8, res.fixs8);
        result_compare_s8(res.fixs8, dst0[i].fixs8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vexl_16(src0[i].fixs16, src1[2], src2[i].fixs16, res.fixs16);
        result_compare_s16(res.fixs16, dst0[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vexl_32(src0[i].fixs32, src1[1], src2[i].fixs32, res.fixs32);
        result_compare_s32(res.fixs32, dst0[i].fixs32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vexl_64(src0[i].fixs64, src1[0], src2[i].fixs64, res.fixs64);
        result_compare_s64(res.fixs64, dst0[i].fixs64);
    }

    return done_testing();
}
