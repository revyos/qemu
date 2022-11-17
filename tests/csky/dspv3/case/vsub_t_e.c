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

struct vdsp_reg res0;
struct vdsp_reg res1;

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
/* dst reg 0 */
struct vdsp_reg dst0[] = {
    {
        .fixs32 = {0x584b9145, 0xffffffff, 0x90a34a4c, 0xffffffff, },
        .fixs16 = {0x871e, 0xffff, 0x183f, 0x0000, 0xa9ab, 0xffff, 0x1409, 0x0000, },
        .fixs8 = {0x84, 0xff, 0x7e, 0x00, 0xff, 0xff, 0x3a, 0x00, 0xeb, 0xff, 0x6c, 0x00, 0x02, 0x00, 0x65, 0x00, },
        .fixu32 = {0xe23d7cdb, 0xffffffff, 0xc2fb9e91, 0xffffffff, },
        .fixu16 = {0x9ae5, 0x0000, 0x101e, 0x0000, 0xa779, 0x0000, 0x8a96, 0xffff, },
        .fixu8 = {0xa6, 0x00, 0xe7, 0xff, 0xc6, 0xff, 0xeb, 0xff, 0x4f, 0x00, 0x2b, 0x00, 0xcc, 0xff, 0xe6, 0xff, },
    },
};
/* dst reg 1 */
struct vdsp_reg dst1[] = {
    {
        .fixs32 = {0xae189ea2, 0xffffffff, 0xc3da35de, 0xffffffff, },
        .fixs16 = {0xd4c8, 0xffff, 0xb3c2, 0x0000, 0x1741, 0x0000, 0xd1af, 0xffff, },
        .fixs8 = {0x34, 0x00, 0x06, 0x00, 0x90, 0x00, 0x0b, 0x00, 0xd5, 0xff, 0xdd, 0xff, 0xd4, 0xff, 0x66, 0x00, },
        .fixu32 = {0x682ed3bf, 0x00000000, 0x4c029377, 0x00000000, },
        .fixu16 = {0xd075, 0xffff, 0x37c9, 0xffff, 0x8227, 0x0000, 0xb376, 0xffff, },
        .fixu8 = {0x1f, 0x00, 0x65, 0x00, 0x6c, 0x00, 0x76, 0x00, 0xac, 0x00, 0xce, 0xff, 0x79, 0xff, 0x59, 0x00, },
    },
};

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vsub.t.e\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vsub_s8_e(src0[i].fixs8, src1[i].fixs8, res0.fixs8, res1.fixs8);
        result_compare_s8(res0.fixs8, dst0[i].fixs8);
        result_compare_s8(res1.fixs8, dst1[i].fixs8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vsub_s16_e(src0[i].fixs16, src1[i].fixs16, res0.fixs16, res1.fixs16);
        result_compare_s16(res0.fixs16, dst0[i].fixs16);
        result_compare_s16(res1.fixs16, dst1[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vsub_s32_e(src0[i].fixs32, src1[i].fixs32, res0.fixs32, res1.fixs32);
        result_compare_s32(res0.fixs32, dst0[i].fixs32);
        result_compare_s32(res1.fixs32, dst1[i].fixs32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vsub_u8_e(src0[i].fixu8, src1[i].fixu8, res0.fixu8, res1.fixu8);
        result_compare_u8(res0.fixu8, dst0[i].fixu8);
        result_compare_u8(res1.fixu8, dst1[i].fixu8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vsub_u16_e(src0[i].fixu16, src1[i].fixu16, res0.fixu16, res1.fixu16);
        result_compare_u16(res0.fixu16, dst0[i].fixu16);
        result_compare_u16(res1.fixu16, dst1[i].fixu16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vsub_u32_e(src0[i].fixu32, src1[i].fixu32, res0.fixu32, res1.fixu32);
        result_compare_u32(res0.fixu32, dst0[i].fixu32);
        result_compare_u32(res1.fixu32, dst1[i].fixu32);
    }

    return done_testing();
}
