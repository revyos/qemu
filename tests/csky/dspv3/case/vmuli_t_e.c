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
        .fixs64 = {0xe985554d0cbf8606, 0xc552f919f93343a1,  },
        .fixs32 = {0xf32e73d0, 0x198493f0, 0x545ecc8, 0x48e32b8, },
        .fixs16 = {0xf445, 0x06b4, 0xf10c, 0x0ef4, 0xf96d, 0x0f15, 0xf1d2, 0x0fba, },
        .fixu64 = {0xafd799f97dddbd6e, 0x68a939c1a9c9e1a0, },
        .fixu32 = {0x62cb85f6, 0x1d488fb3, 0x5dc50006, 0x03648efc,  },
        .fixu16 = {0x1538, 0x047c, 0x10bc, 0x06c8, 0x18d4, 0x0e38, 0x07c4, 0x0efc,},
    },
};
struct vdsp_reg dst1[] = {
    {
        .fixs64 = {0x0a45125d577a4f61, 0xecb835eaeced6cda,  },
        .fixs32 = {0xe320e378, 0x180df648, 0x1638fdd8, 0xe289dbe0, },
        .fixs16 = {0x0c60, 0x0339, 0x07bc, 0xf1b1, 0xff9d, 0xf50b, 0x0483, 0x0441, },
        .fixu64 = {0xd60255b08592f426, 0x5caa650d2cf7b276, },
        .fixu32 = {0x2b268ab6, 0x0561ceab, 0x5683daa9, 0x44440cde, },
        .fixu16 = {0x166c, 0x1b74, 0x12ec, 0x1148, 0x1928, 0x0444, 0x0230, 0x15fc, },
    },
};
struct vdsp_reg res0, res1;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vmulei\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmuli_s8_e(src0[i].fixs8, src1[i].fixs8, res0.fixs16, res1.fixs16);
        result_compare_s16(res0.fixs16, dst0[i].fixs16);
        result_compare_s16(res1.fixs16, dst1[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmuli_s16_e(src0[i].fixs16, src1[i].fixs16, res0.fixs32, res1.fixs32);
        result_compare_s32(res0.fixs32, dst0[i].fixs32);
        result_compare_s32(res1.fixs32, dst1[i].fixs32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmuli_s32_e(src0[i].fixs32, src1[i].fixs32, res0.fixs64, res1.fixs64);
        result_compare_s64(res0.fixs64, dst0[i].fixs64);
        result_compare_s64(res1.fixs64, dst1[i].fixs64);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmuli_u8_e(src0[i].fixu8, src1[i].fixu8, res0.fixu16, res1.fixu16);
        result_compare_u16(res0.fixu16, dst0[i].fixu16);
        result_compare_u16(res1.fixu16, dst1[i].fixu16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmuli_u16_e(src0[i].fixu16, src1[i].fixu16, res0.fixu32, res1.fixu32);
        result_compare_u32(res0.fixu32, dst0[i].fixu32);
        result_compare_u32(res1.fixu32, dst1[i].fixu32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmuli_u32_e(src0[i].fixu32, src1[i].fixu32, res0.fixu64, res1.fixu64);
        result_compare_u64(res0.fixu64, dst0[i].fixu64);
        result_compare_u64(res1.fixu64, dst1[i].fixu64);
    }

    return done_testing();
}
