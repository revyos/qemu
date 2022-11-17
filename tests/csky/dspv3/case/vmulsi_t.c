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
        .float32 = {0x483471f7, 0x46f2e02b, 0xc785dc35, 0x47ad69d9, },
        .float16 = {0x4aee, 0x40aa, 0xc524, 0x46a9, 0x4a65, 0x404e, 0xc4bf, 0x4626, },
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
        .float32 = {0xc843ca22, 0x483c7bbf, 0xc73b64a7, 0x481eefee, },
        .float16 = {0xcb85, 0x4b3d, 0xc332, 0x4a1a, 0xcaf1, 0x4aae, 0xc2a4, 0x49a2, },
        .fixs32 = {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
        .fixs16 = {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
        .fixs8 = {0x21, 0xb6, 0x8d, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
        .fixu32 = {0xe391e1de, 0xb2c0dd9f, 0x888fed5e, 0x1c3b70fe, },
        .fixu16 = {0x6371, 0x3b45, 0x49ed, 0x7e26, 0x9ea1, 0xd612, 0x5c92, 0xfc48, },
        .fixu8 = {0x1c, 0x42, 0xd3, 0x53, 0x94, 0x57, 0x7b, 0xa3, 0xae, 0x96, 0x41, 0x28, 0x3a, 0x59, 0x9b, 0x70, },
    },
};

struct vdsp_reg src2[] = {
    {
        .float32 = {0x47a9ac4e, 0x47a16b54, 0xc79573cb, 0xc80fabbd, },
        .float16 = {0x4684, 0x4633, 0xc5bd, 0xc984, 0x4604, 0x45b9,  0xc54c, 0xc918,},
        .fixs32 = {0x2ef3c1ca, 0xd167753f, 0xd345a93c, 0xcb8a4543, },
        .fixs16 = {0xf0f6, 0x8940, 0xf0cf, 0x70e1, 0x43dc, 0xd684, 0xd39d, 0x86d3, },
        .fixs8 = {0x5a, 0xeb, 0x19, 0x10, 0x5b, 0xcd, 0xa0, 0xda, 0x8f, 0x29, 0xb3, 0x35, 0x3d, 0xda, 0x0d, 0x99, },
        .fixu32 = {0xd6bc23ef, 0xd20235bb, 0xdb7e4b2f, 0x588d9bbf, },
        .fixu16 = {0x5d85, 0xab10, 0xc750, 0xab2a, 0xa9ae, 0xf97c, 0x415e, 0x882d, },
        .fixu8 = {0xd3, 0xd9, 0x4a, 0xd1, 0x8c, 0x5a, 0xef, 0x56, 0x6c, 0xc2, 0x44, 0xc2, 0x96, 0x9c, 0x23, 0x67, },
    },
};

struct vdsp_reg dst0[] = {
    {
        .float32 = {0x510a015e, 0x4fb9c127, 0xd04cc127, 0x5084a045, },
        .float16 = {0x5ab7, 0x5128, 0xd531, 0x5592, 0x5a33, 0x50c3, 0xd4cb, 0x5524, },
        .fixs32 = {0x22343bc4, 0xd834319e, 0x7bcb59db, 0xde9cd869, },
        .fixs16 = {0x7d26, 0xf550, 0x0407, 0x3e29, 0x6064, 0xe03c, 0xd5c5, 0xaaf3, },
        .fixs8 = {0x15, 0x37, 0x0d, 0x1c, 0xee, 0xb8, 0xce, 0x20, 0x2f, 0xf0, 0xf7, 0x84, 0xa0, 0xcf, 0x8a, 0x58, },
        .fixu32 = {0x58de6681, 0x2838541b, 0x55eb5709, 0x2b95e949, },
        .fixu16 = {0xd78f, 0x1b5d, 0xc74a, 0x1c2e, 0x1ef8, 0x2ad1, 0x66b5, 0x7b4f, },
        .fixu8 = {0x9b, 0x5d, 0x8e, 0x09, 0xb8, 0x22, 0x2b, 0x5a, 0x00, 0x4e, 0x58, 0x7a, 0x6e, 0x58, 0xf3, 0x6b, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vmulsi\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmulsi_s8(src0[i].fixs8, src1[i].fixs8, src2[i].fixs8);
        result_compare_s8(src2[i].fixs8, dst0[i].fixs8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmulsi_s16(src0[i].fixs16, src1[i].fixs16, src2[i].fixs16);
        result_compare_s16(src2[i].fixs16, dst0[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmulsi_s32(src0[i].fixs32, src1[i].fixs32, src2[i].fixs32);
        result_compare_s32(src2[i].fixs32, dst0[i].fixs32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmulsi_u8(src0[i].fixu8, src1[i].fixu8, src2[i].fixu8);
        result_compare_u8(src2[i].fixu8, dst0[i].fixu8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmulsi_u16(src0[i].fixu16, src1[i].fixu16, src2[i].fixu16);
        result_compare_u16(src2[i].fixu16, dst0[i].fixu16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmulsi_u32(src0[i].fixu32, src1[i].fixu32, src2[i].fixu32);
        result_compare_u32(src2[i].fixu32, dst0[i].fixu32);
    }
#ifdef VDSP_FLOAT
    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmulsi_f32(src0[i].float32, src1[i].float32, src2[i].float32);
        result_compare_f32(src2[i].float32, dst0[i].float32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmulsi_f16(src0[i].float16, src1[i].float16, src2[i].float16);
        result_compare_f16(src2[i].float16, dst0[i].float16);
    }
#endif
    return done_testing();
}
