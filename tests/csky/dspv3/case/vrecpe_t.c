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
        .fixs32 = {0xcfe06686, 0x2262f661, 0x15fc5221, 0x10b9745a, },
        .fixs16 = {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        .fixs8 = {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
        .fixu32 = {0xc5cf5eb9, 0x75bc7c30, 0xf0bec11d, 0x683e0475, },
        .fixu16 = {0xfe56, 0x4b63, 0xf166, 0x08bc, 0x6f16, 0x0ddb, 0xdeb9, 0xafbe, },
        .fixu8 = {0xc2, 0x29, 0x99, 0x3e, 0xe3, 0x82, 0x47, 0x89, 0xcd, 0xfb, 0xad, 0x9e, 0xe6, 0x27, 0x14, 0xc9, },
    },
};

struct vdsp_reg dst0[] = {
    {
        .float32 = {0x36bc31e0, 0x37fdc3ac, 0xb76ac7a2, 0x374339fe, },
        .float16 = {0x2c97, 0x36db, 0xb261, 0x30dc, 0x2d20, 0x3737, 0xb2c6, 0x315f, },
        .fixs32 = {0x3c381d7d, 0x1e1a36e3, 0x30f3d3e5, 0x3adb08c0, },
        .fixs16 = {0x3c38, 0x1e1b, 0x3a76, 0x3c38, 0x3c38, 0x1e1b, 0x1e1b, 0x3c38, },
        .fixs8 = {0x3c, 0x1e, 0x3c, 0x1e, 0x3c, 0x1e, 0x3c, 0x1e, 0x1e, 0x2b, 0x1e, 0x3c, 0x3c, 0x3c, 0x1e, 0x1e, },
        .fixu32 = {0x3c346dc6, 0x3c346dc6, 0x3c346dc6, 0x3c346dc6, },
        .fixu16 = {0x3c35, 0x3c35, 0x3c35, 0x7870, 0x3c35, 0x7870, 0x3c35, 0x3c35, },
        .fixu8 = {0x3c, 0x67, 0x3c, 0x3f, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x6a, 0x78, 0x3c, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vrecpe.t\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrecpe_s8(src0[i].fixs8, res.fixs8);
        result_compare_s8(res.fixs8, dst0[i].fixs8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrecpe_s16(src0[i].fixs16, res.fixs16);
        result_compare_s16(res.fixs16, dst0[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrecpe_s32(src0[i].fixs32, res.fixs32);
        result_compare_s32(res.fixs32, dst0[i].fixs32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrecpe_u8(src0[i].fixu8, res.fixu8);
        result_compare_u8(res.fixu8, dst0[i].fixu8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrecpe_u16(src0[i].fixu16, res.fixu16);
        result_compare_u16(res.fixu16, dst0[i].fixu16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrecpe_u32(src0[i].fixu32, res.fixu32);
        result_compare_u32(res.fixu32, dst0[i].fixu32);
    }
#ifdef VDSP_FLOAT
    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrecpe_f32(src0[i].float32, res.float32);
        result_compare_f32(res.float32, dst0[i].float32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrecpe_f16(src0[i].float16, res.float16);
        result_compare_f16(res.float16, dst0[i].float16);
    }
#endif
    return done_testing();
}
