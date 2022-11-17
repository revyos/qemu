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
        .fixu32 = {0xc5cf5eb9, 0x75bc7c30, 0xf0bec11d, 0x683e0475, },
        .fixu16 = {0xfe56, 0x4b63, 0xf166, 0x08bc, 0x6f16, 0x0ddb, 0xdeb9, 0xafbe, },
        .fixu8 = {0xc2, 0x29, 0x99, 0x3e, 0xe3, 0x82, 0x47, 0x89, 0xcd, 0xfb, 0xad, 0x9e, 0xe6, 0x27, 0x14, 0xc9, },
    },
};

struct vdsp_reg dst0[] = {
    {
        .fixs32 = {0xfe066860, 0xfffffffc, 0x262f6610, 0xfffffff8, },
        .fixs16 = {0x6d60, 0xfffd, 0x1f20, 0x0005, 0x0ef0, 0x0001, 0xea10, 0x0000, },
        .fixs8 = {0x50, 0xfa, 0x40, 0x03, 0xc0, 0xf8, 0x40, 0x07, 0xd0, 0xfc, 0x50, 0x07, 0x20, 0xf9, 0xa0, 0x07, },
        .fixu32 = {0x5cf5eb90, 0x0000000c, 0x5bc7c300, 0x00000007, },
        .fixu16 = {0xe560, 0x000f, 0xb630, 0x0004, 0x1660, 0x000f, 0x8bc0, 0x0000, },
        .fixu8 = {0x20, 0x0c, 0x90, 0x02, 0x90, 0x09, 0xe0, 0x03, 0x30, 0x0e, 0x20, 0x08, 0x70, 0x04, 0x90, 0x08, },
    },
};

struct vdsp_reg dst1[] = {
    {
        .fixs32 = {0x5fc52210, 0x00000001, 0x6b9745a0, 0xfffffffd, },
        .fixs16 = {0x3490, 0xfffa, 0xd3f0, 0x0004, 0x75d0, 0x0004, 0x1640, 0xfffa, },
        .fixs8 = {0x00, 0x06, 0x90, 0x01, 0xc0, 0x03, 0x10, 0xf9, 0xd0, 0xff, 0xb0, 0xfa, 0x30, 0x02, 0x10, 0x02, },
        .fixu32 = {0x0bec11d0, 0x0000000f, 0x83e04750, 0x00000006, },
        .fixu16 = {0xf160, 0x0006, 0xddb0, 0x0000, 0xeb90, 0x000d, 0xfbe0, 0x000a, },
        .fixu8 = {0xd0, 0x0c, 0xb0, 0x0f, 0xd0, 0x0a, 0xe0, 0x09, 0x60, 0x0e, 0x70, 0x02, 0x40, 0x01, 0x90, 0x0c, },
    },
};


struct vdsp_reg res0, res1;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vshli.t.e\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshli_s8_e(src0[i].fixs8, res0.fixs8, res1.fixs8);
        result_compare_s8(res0.fixs8, dst0[i].fixs8);
        result_compare_s8(res1.fixs8, dst1[i].fixs8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshli_s16_e(src0[i].fixs16, res0.fixs16, res1.fixs16);
        result_compare_s16(res0.fixs16, dst0[i].fixs16);
        result_compare_s16(res1.fixs16, dst1[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshli_s32_e(src0[i].fixs32, res0.fixs32, res1.fixs32);
        result_compare_s32(res0.fixs32, dst0[i].fixs32);
        result_compare_s32(res1.fixs32, dst1[i].fixs32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshli_u8_e(src0[i].fixu8, res0.fixu8, res1.fixu8);
        result_compare_u8(res0.fixu8, dst0[i].fixu8);
        result_compare_u8(res1.fixu8, dst1[i].fixu8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshli_u16_e(src0[i].fixu16, res0.fixu16, res1.fixu16);
        result_compare_u16(res0.fixu16, dst0[i].fixu16);
        result_compare_u16(res1.fixu16, dst1[i].fixu16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshli_u32_e(src0[i].fixu32, res0.fixu32, res1.fixu32);
        result_compare_u32(res0.fixu32, dst0[i].fixu32);
        result_compare_u32(res1.fixu32, dst1[i].fixu32);
    }

    return done_testing();
}
