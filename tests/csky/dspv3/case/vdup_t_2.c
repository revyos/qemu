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
        .fixs32 = {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        .fixs16 = {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        .fixs8 = {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
    },
};

struct vdsp_reg src1[] = {
    {
        .fixs32 = {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
        .fixs16 = {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
        .fixs8 = {0x21, 0xb6, 0x8d, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
    },
};

struct vdsp_reg dst0[] = {
    {
        .fixs32 = {0xcfe06686, 0xcfe06686, 0xcfe06686, 0xcfe06686, },
        .fixs16 = {0xd6d6, 0xd6d6, 0xd6d6, 0xd6d6, 0xd6d6, 0xd6d6, 0xd6d6, 0xd6d6, },
        .fixs8 = {0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, },
    },
};

struct vdsp_reg dst1[] = {
    {
        .fixs32 = {0x8262f661, 0x8262f661, 0x8262f661, 0x8262f661, },
        .fixs16 = {0x51f2, 0x51f2, 0x51f2, 0x51f2, 0x51f2, 0x51f2, 0x51f2, 0x51f2, },
        .fixs8 = {0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, },
    },
};

struct vdsp_reg res0, res1;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vdup.t.2\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vdup_8_2(src0[i].fixs8, src1[i].fixs8, res0.fixs8, res1.fixs8);
        result_compare_s8(res0.fixs8, dst0[i].fixs8);
        result_compare_s8(res1.fixs8, dst1[i].fixs8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vdup_16_2(src0[i].fixs16, src1[i].fixs16, res0.fixs16, res1.fixs16);
        result_compare_s16(res0.fixs16, dst0[i].fixs16);
        result_compare_s16(res1.fixs16, dst1[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vdup_32_2(src0[i].fixs32, src1[i].fixs32, res0.fixs32, res1.fixs32);
        result_compare_s32(res0.fixs32, dst0[i].fixs32);
        result_compare_s32(res1.fixs32, dst1[i].fixs32);
    }

    return done_testing();
}
