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
        .fixs32 = {0xcfe06686, 0x20000000, 0x15fc5221, 0x10000000, },
        .fixs16 = {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0x7fff, 0xffff, 0x2000, 0x1000, },
        .fixs8 = {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0x7f, 0xff, 0x20, 0x10, },
        .fixu32 = {0xc5cf5eb9, 0x35bc7c30, 0x40000000, 0x20000000, },
        .fixu16 = {0xfe56, 0x4b63, 0xf166, 0x08bc, 0x6f16, 0x2345, 0x2000, 0x4000, },
        .fixu8 = {0xc2, 0x29, 0x99, 0x3e, 0xe3, 0x82, 0x47, 0x89, 0xcd, 0xfb, 0xad, 0x9e, 0x40, 0x27, 0x14, 0x20, },
    },
};

struct vdsp_reg dst0[] = {
    {
        .float32 = {0x3b1d2b34, 0x3bbdf41a, 0x7b747615, 0x3b60af43, },
        .float16 = {0x3444, 0x3966, 0x7729, 0x3667, 0x3489, 0x3994, 0x775c,
            0x36a8, },
        .fixs32 = {0x2c28f5c2, 0x1c28f5c2, 0x262ca3a1, 0x2c28f5c2, },
        .fixs16 = {0x2c28, 0x1c28, 0x2b39, 0x2c28, 0x1c28, 0x2c28, 0x1c28, 0x2c28, },
        .fixs8 = {0x2c, 0x1c, 0x2c, 0x1c, 0x2c, 0x1c, 0x2c, 0x1c, 0x1c, 0x23, 0x1c, 0x2c, 0x1c, 0x2c, 0x1c, 0x2c, },
        .fixu32 = {0x3851eb85, 0x42956F55, 0x3851eb85, 0x5851eb85, },
        .fixu16 = {0x3851, 0x3851, 0x3851, 0x5851, 0x3851, 0x550c, 0x5851, 0x3851, },
        .fixu8 = {0x38, 0x4f, 0x38, 0x3a, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x51, 0x58, 0x58, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vrsqrte.t\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrsqrte_s8(src0[i].fixs8, res.fixs8);
        result_compare_s8(res.fixs8, dst0[i].fixs8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrsqrte_s16(src0[i].fixs16, res.fixs16);
        result_compare_s16(res.fixs16, dst0[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrsqrte_s32(src0[i].fixs32, res.fixs32);
        result_compare_s32(res.fixs32, dst0[i].fixs32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrsqrte_u8(src0[i].fixu8, res.fixu8);
        result_compare_u8(res.fixu8, dst0[i].fixu8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrsqrte_u16(src0[i].fixu16, res.fixu16);
        result_compare_u16(res.fixu16, dst0[i].fixu16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrsqrte_u32(src0[i].fixu32, res.fixu32);
        result_compare_u32(res.fixu32, dst0[i].fixu32);
    }

#ifdef VDSP_FLOAT
    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrsqrte_f32(src0[i].float32, res.float32);
        result_compare_f32(res.float32, dst0[i].float32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrsqrte_f16(src0[i].float16, res.float16);
        result_compare_f16(res.float16, dst0[i].float16);
    }
#endif
    return done_testing();
}
