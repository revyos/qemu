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

struct vdsp_reg src1[] = {
    {
        .fixs32 = {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
        .fixs16 = {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
        .fixs8 = {0x21, 0xb6, 0x8d, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
        .fixu32 = {0xe391e1de, 0xb2c0dd9f, 0x888fed5e, 0x1c3b70fe, },
        .fixu16 = {0x6371, 0x3b45, 0x49ed, 0x7e26, 0x9ea1, 0xd612, 0x5c92, 0xfc48, },
        .fixu8 = {0x1c, 0x42, 0xd3, 0x53, 0x94, 0x57, 0x7b, 0xa3, 0xae, 0x96, 0x41, 0x28, 0x3a, 0x59, 0x9b, 0x70, },
    },
};

struct vdsp_reg dst0[] = {
    {
        .fixs32 = {0x23ba9de3, 0xba11513b, 0x3ef002d0, 0xf4cc596b, },
        .fixs16 = {0x1347, 0x45d2, 0x3c19, 0x049c, 0xb8e5, 0xf35e, 0x3bbc, 0xb88c, },
        .fixs8 = {0xe3, 0xf5, 0x8c, 0x57, 0xd7, 0x3f, 0x91, 0x47, 0x46, 0x16, 0xf4, 0x8b, 0x12, 0xbc, 0x39, 0xee, },
        .fixu32 = {0xd4b0a04b, 0x943eace7, 0xbca7573d, 0x423cbab9, },
        .fixu16 = {0xb0e3, 0x4354, 0x9da9, 0x4371, 0x86db, 0x71f6, 0x9da5, 0xd603, },
        .fixu8 = {0x6f, 0x35, 0xb6, 0x48, 0xbb, 0x6c, 0x61, 0x96, 0xbd, 0xc8, 0x77, 0x63, 0x90, 0x40, 0x57, 0x9c, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vaddh\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vaddh_s8(src0[i].fixs8, src1[i].fixs8, res.fixs8);
        result_compare_s8(res.fixs8, dst0[i].fixs8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vaddh_s16(src0[i].fixs16, src1[i].fixs16, res.fixs16);
        result_compare_s16(res.fixs16, dst0[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vaddh_s32(src0[i].fixs32, src1[i].fixs32, res.fixs32);
        result_compare_s32(res.fixs32, dst0[i].fixs32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vaddh_u8(src0[i].fixu8, src1[i].fixu8, res.fixu8);
        result_compare_u8(res.fixu8, dst0[i].fixu8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vaddh_u16(src0[i].fixu16, src1[i].fixu16, res.fixu16);
        result_compare_u16(res.fixu16, dst0[i].fixu16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vaddh_u32(src0[i].fixu32, src1[i].fixu32, res.fixu32);
        result_compare_u32(res.fixu32, dst0[i].fixu32);
    }

    return done_testing();
}
