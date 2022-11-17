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
        .fixs64 = {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
        .fixs32 = {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        .fixs16 = {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        .fixs8 = {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
    },
};

struct vdsp_reg src1[] = {
    {
        .fixs64 = {0x07d215928aa0d7b6, 0x07186161e5f9e80f, },
        .fixs32 = {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
        .fixs16 = {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
        .fixs8 = {0x21, 0xb6, 0x8d, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
    },
};

struct vdsp_reg dst0[] = {
    {
        .fixs64 = {0x3820a00930112000, 0xc0a6109202061770, },
        .fixs32 = {0x88602286, 0x02405260, 0x101c4000, 0xc4204002, },
        .fixs16 = {0x9046, 0x4040, 0x10ab, 0x0421, 0x2148, 0x4402, 0x4741, 0x2040, },
        .fixs8 = {0x84, 0x00, 0x00, 0x44, 0x0d, 0x74, 0x02, 0x6a, 0x40, 0x08, 0x10, 0x11, 0xd5, 0x21, 0x20, 0x00, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vandn\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vandn_8(src0[i].fixs8, src1[i].fixs8, res.fixs8);
        result_compare_s8(res.fixs8, dst0[i].fixs8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vandn_16(src0[i].fixs16, src1[i].fixs16, res.fixs16);
        result_compare_s16(res.fixs16, dst0[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vandn_32(src0[i].fixs32, src1[i].fixs32, res.fixs32);
        result_compare_s32(res.fixs32, dst0[i].fixs32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vandn_64(src0[i].fixs64, src1[i].fixs64, res.fixs64);
        result_compare_s64(res.fixs64, dst0[i].fixs64);
    }

    return done_testing();
}
