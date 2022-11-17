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

/* src reg 0 */
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
/* src reg 1 */
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
/* src reg 2 */
struct vdsp_reg src2[] = {
    {
        .fixs32 = {0x2ef3c1ca, 0xd167753f, 0xd345a93c, 0xcb8a4543, },
        .fixs16 = {0xf0f6, 0x8940, 0xf0cf, 0x70e1, 0x43dc, 0xd684, 0xd39d, 0x86d3, },
        .fixs8 = {0x5a, 0xeb, 0x19, 0x10, 0x5b, 0xcd, 0xa0, 0xda, 0x8f, 0x29, 0xb3, 0x35, 0x3d, 0xda, 0x0d, 0x99, },
        .fixu32 = {0xd6bc23ef, 0xd20235bb, 0xdb7e4b2f, 0x588d9bbf, },
        .fixu16 = {0x5d85, 0xab10, 0xc750, 0xab2a, 0xa9ae, 0xf97c, 0x415e, 0x882d, },
        .fixu8 = {0xd3, 0xd9, 0x4a, 0xd1, 0x8c, 0x5a, 0xef, 0x56, 0x6c, 0xc2, 0x44, 0xc2, 0x96, 0x9c, 0x23, 0x67, },
    },
};
/* dst reg 0 */
struct vdsp_reg dst0[] = {
    {
        .fixs32 = {0xa0eca4bc, 0x8262f661, 0x4494dce2, 0xd6b9745a, },
        .fixs16 = {0xe5e0, 0x51f2, 0x87af, 0x0ea1, 0xb27a, 0x4d3f, 0xd67c, 0xa163, },
        .fixs8 = {0x4b, 0x34, 0xa1, 0x74, 0xb4, 0x75, 0x82, 0x7a, 0x05, 0x19, 0x6f, 0x91, 0x5d, 0xac, 0x49, 0x21, },
        .fixu32 = {0xef133aca, 0x75bc7c2f, 0x1ebc8b62, 0x683e0475, },
        .fixu16 = {0xa0d1, 0x4b63, 0x4656, 0x08bc, 0xa7c6, 0x0dda, 0x338f, 0xafbe, },
        .fixu8 = {0xef, 0x28, 0xc0, 0x3d, 0x99, 0x82, 0x76, 0x88, 0x41, 0xfb, 0x53, 0x9e, 0xf7, 0x26, 0xbe, 0xc8, },
    },
};
/* dst reg 1 */
struct vdsp_reg dst1[] = {
    {
        .fixs32 = {0xa44f2c05, 0xf1bfac15, 0x9c596e3c, 0x12df3e7c, },
        .fixs16 = {0x0bdc, 0x39b3, 0x90c0, 0xfa98, 0xfae4, 0x997d, 0xa949, 0xcfb5, },
        .fixs8 = {0x92, 0xb6, 0x64, 0x3a, 0x2f, 0x0a, 0x5b, 0x15, 0xef, 0x12, 0xd2, 0x86, 0x1b, 0xce, 0xb6, 0xbb, },
        .fixu32 = {0x081396af, 0xb2c0dd9f, 0x3002519f, 0x1c3b70fe, },
        .fixu16 = {0xb9c3, 0x3b44, 0x5071, 0x7e25, 0x5d43, 0xd612, 0xd465, 0xfc47, },
        .fixu8 = {0xb0, 0x41, 0x11, 0x53, 0x50, 0x57, 0xb9, 0xa2, 0x18, 0x96, 0xa5, 0x27, 0x17, 0x59, 0x34, 0x70, },
    },
};

struct vdsp_reg res[2];

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vsub.t.x\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vsub_s8_x(src0[i].fixs8, src1[i].fixs8, src2[i].fixs8,
                       res[0].fixs8);
        result_compare_s8(res[0].fixs8, dst0[i].fixs8);
        result_compare_s8(res[1].fixs8, dst1[i].fixs8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vsub_s16_x(src0[i].fixs16, src1[i].fixs16, src2[i].fixs16,
                        res[0].fixs16);
        result_compare_s16(res[0].fixs16, dst0[i].fixs16);
        result_compare_s16(res[1].fixs16, dst1[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vsub_s32_x(src0[i].fixs32, src1[i].fixs32, src2[i].fixs32,
                        res[0].fixs32);
        result_compare_s32(res[0].fixs32, dst0[i].fixs32);
        result_compare_s32(res[1].fixs32, dst1[i].fixs32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vsub_u8_x(src0[i].fixu8, src1[i].fixu8, src2[i].fixu8,
                       res[0].fixu8);
        result_compare_u8(res[0].fixu8, dst0[i].fixu8);
        result_compare_u8(res[1].fixu8, dst1[i].fixu8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vsub_u16_x(src0[i].fixu16, src1[i].fixu16, src2[i].fixu16,
                        res[0].fixu16);
        result_compare_u16(res[0].fixu16, dst0[i].fixu16);
        result_compare_u16(res[1].fixu16, dst1[i].fixu16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vsub_u32_x(src0[i].fixu32, src1[i].fixu32, src2[i].fixu32,
                        res[0].fixu32);
        result_compare_u32(res[0].fixu32, dst0[i].fixu32);
        result_compare_u32(res[1].fixu32, dst1[i].fixu32);
    }

    return done_testing();
}
