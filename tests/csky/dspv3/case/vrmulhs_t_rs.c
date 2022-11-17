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
        .fixs32 = {0xcfe06686, 0x00000001, 0x00000001, 0xd6b9745a, },
        .fixs16 = {0xd6d6, 0x0001, 0x0001, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        .fixs8 = {0xa5, 0x01, 0x01, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
    },
};

struct vdsp_reg src1[] = {
    {
        .fixs32 = {0x7794d541, 0x7fffffff, 0x80000000, 0x12df3e7c, },
        .fixs16 = {0x4fb8, 0x7fff, 0x8000, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
        .fixs8 = {0x21, 0x7f, 0x80, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
    },
};

struct vdsp_reg src2[] = {
    {
        .fixs32 = {0x2ef3c1ca, 0x80000000, 0x7fffffff, 0xcb8a4543, },
        .fixs16 = {0xf0f6, 0x8000, 0x7fff, 0x70e1, 0x43dc, 0xd684, 0xd39d, 0x86d3, },
        .fixs8 = {0x5a, 0x80, 0x7f, 0x10, 0x5b, 0xcd, 0xa0, 0xda, 0x8f, 0x29, 0xb3, 0x35, 0x3d, 0xda, 0x0d, 0x99, },
    },
};

struct vdsp_reg dst0[] = {
    {
        .fixs32 = {0x5be91730, 0x80000000, 0x7fffffff, 0xd1a02df4, },
        .fixs16 = {0x0a99, 0x8000, 0x7fff, 0x717f, 0x2002, 0x1461, 0xb8cb, 0x8000, },
        .fixs8 = {0x71, 0x80, 0x7f, 0xdb, 0x4f, 0xc5, 0x80, 0xc6, 0x80, 0x25, 0xda, 0xcb, 0x3e, 0xb9, 0xf7, 0xab, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vrmulhs.t.rs\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrmulhs_s8_rs(src0[i].fixs8, src1[i].fixs8, src2[i].fixs8, res.fixs8);
        result_compare_s8(res.fixs8, dst0[i].fixs8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrmulhs_s16_rs(src0[i].fixs16, src1[i].fixs16, src2[i].fixs16, res.fixs16);
        result_compare_s16(res.fixs16, dst0[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrmulhs_s32_rs(src0[i].fixs32, src1[i].fixs32, src2[i].fixs32, res.fixs32);
        result_compare_s32(res.fixs32, dst0[i].fixs32);
    }

    return done_testing();
}
