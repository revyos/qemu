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
        .fixs32 = {0xcfe06686, 0x8262f661, 0x80000000, 0x80000000, },
        .fixs16 = {0xd6d6, 0x51f2, 0x8000, 0x8000, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        .fixs8 = {0xa5, 0x34, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
    },
};

struct vdsp_reg src1[] = {
    {
        .fixs32 = {0x7794d541, 0xf1bfac15, 0x80000000, 0x80000000, },
        .fixs16 = {0x4fb8, 0x39b3, 0x8000, 0x8000, 0xce81, 0x997d, 0x301c, 0xcfb5, },
        .fixs8 = {0x21, 0xb6, 0x80, 0x80, 0x80, 0x09, 0x90, 0x80, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
    },
};

struct vdsp_reg dst0[] = {
    {
        .fixs32 = {0xc50e5cad, 0x90019657, 0x00000000, 0x7fffffff, },
        .fixs16 = {0xc16d, 0x207b, 0x0000, 0x7fff, 0x61b7, 0x2c62, 0xf721, 0xc184, },
        .fixs8 = {0x07, 0x42, 0x00, 0x7f, 0x7f, 0xf7, 0x80, 0x70, 0x1d, 0x17, 0x80, 0x10, 0xde, 0xe7, 0x27, 0x02, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vrcmul.t.rs\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrcmul_s8_rs(src0[i].fixs8, src1[i].fixs8, res.fixs8);
        result_compare_s8(res.fixs8, dst0[i].fixs8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrcmul_s16_rs(src0[i].fixs16, src1[i].fixs16, res.fixs16);
        result_compare_s16(res.fixs16, dst0[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrcmul_s32_rs(src0[i].fixs32, src1[i].fixs32, res.fixs32);
        result_compare_s32(res.fixs32, dst0[i].fixs32);
    }

    return done_testing();
}
