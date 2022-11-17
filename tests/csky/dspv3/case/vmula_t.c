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
        .float32 = {0xd10a0134, 0x4fb2d2a7, 0x4f43f7cd, 0x50575326, },
        .float16 = {0xda4f, 0x50fe, 0x4a62, 0x5464, 0xd95c, 0x504f, 0x493b, 0x5362, },
        .fixs32 = {0x3bb347d0, 0x246dd734, 0x43227a9b, 0x65f26cdb, },
        .fixs16 = {0x64c6, 0xb776, 0x994b, 0x5a79, 0x49a5, 0x3547, 0x11c9, 0x7e87, },
        .fixs8 = {0x9f, 0xe3, 0x35, 0x58, 0x55, 0xea, 0xc0, 0xdc, 0x0f, 0x04, 0x03, 0x1b, 0xc5, 0x74, 0xda, 0xb4, },
        .fixu32 = {0x5499e15d, 0x2d48c78b, 0x21840cd5, 0xbb0037d5, },
        .fixu16 = {0xe37b, 0xcdbf, 0x58be, 0x7f12, 0x1a84, 0x04e2, 0xc2e0, 0xfd9d, },
        .fixu8 = {0x0b, 0x6b, 0x65, 0xeb, 0xc8, 0x88, 0x0c, 0x91, 0xc2, 0xd4, 0x31, 0x72, 0xb2, 0x2b, 0x3f, 0x57, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0, j;
    init_testsuite("Testing insn vmula.t\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmula_s8(src0[i].fixs8, src1[i].fixs8, src2[i].fixs8);
        result_compare_s8(src2[i].fixs8, dst0[i].fixs8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmula_s16(src0[i].fixs16, src1[i].fixs16, src2[i].fixs16);
        result_compare_s16(src2[i].fixs16, dst0[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmula_s32(src0[i].fixs32, src1[i].fixs32, src2[i].fixs32);
        result_compare_s32(src2[i].fixs32, dst0[i].fixs32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmula_u8(src0[i].fixu8, src1[i].fixu8, src2[i].fixu8);
        result_compare_u8(src2[i].fixu8, dst0[i].fixu8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmula_u16(src0[i].fixu16, src1[i].fixu16, src2[i].fixu16);
        result_compare_u16(src2[i].fixu16, dst0[i].fixu16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmula_u32(src0[i].fixu32, src1[i].fixu32, src2[i].fixu32);
        result_compare_u32(src2[i].fixu32, dst0[i].fixu32);
    }

#ifdef VDSP_FLOAT
    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmula_f32(src0[i].float32, src1[i].float32, src2[i].float32);
        result_compare_f32(src2[i].float32, dst0[i].float32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmula_f16(src0[i].float16, src1[i].float16, src2[i].float16);
        result_compare_f16(src2[i].float16, dst0[i].float16);
    }
#endif
    return done_testing();
}
