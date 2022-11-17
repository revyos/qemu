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

struct vdsp_reg src[] = {
    {
        .fixs32 = {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        .fixs16 = {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        .fixs8 = {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c,
            0x91, 0xfd, 0xab, 0x23, 0x21, },
        .fixu32 = {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        .fixu16 = {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        .fixu8 = {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c,
            0x91, 0xfd, 0xab, 0x23, 0x21, },
    },
};

struct vdsp_reg dst0[] = {
    {
        .fixs32 = {0xcfe06686, 0xffffffff, 0x8262f661, 0xffffffff, },
        .fixs16 = {0xd6d6, 0xffff, 0x51f2, 0x0000, 0x10ef, 0x0000, 0x0ea1, 0x0000, },
        .fixs8 = {0xa5, 0xff, 0x34, 0x00, 0x8c, 0xff, 0x74, 0x00, 0xcd, 0xff, 0x75,
            0x00, 0x92, 0xff, 0x7a, 0x00, },
        .fixu32 = {0xcfe06686, 0x00000000, 0x8262f661, 0x00000000, },
        .fixu16 = {0xd6d6, 0x0000, 0x51f2, 0x0000, 0x10ef, 0x0000, 0x0ea1, 0x0000, },
        .fixu8 = {0xa5, 0x00, 0x34, 0x00, 0x8c, 0x00, 0x74, 0x00, 0xcd, 0x00, 0x75,
            0x00, 0x92, 0x00, 0x7a, 0x00, },
    },
};

struct vdsp_reg dst1[] = {
    {
        .fixs32 = {0x15fc5221, 0x00000000, 0xd6b9745a, 0xffffffff, },
        .fixs16 = {0xa349, 0xffff, 0x4d3f, 0x0000, 0x475d, 0x0000, 0xa164, 0xffff, },
        .fixs8 = {0x60, 0x00, 0x19, 0x00, 0x3c, 0x00, 0x91, 0xff, 0xfd, 0xff, 0xab,
            0xff, 0x23, 0x00, 0x21, 0x00, },
        .fixu32 = {0x15fc5221, 0x00000000, 0xd6b9745a, 0x00000000, },
        .fixu16 = {0xa349, 0x0000, 0x4d3f, 0x0000, 0x475d, 0x0000, 0xa164, 0x0000, },
        .fixu8 = {0x60, 0x00, 0x19, 0x00, 0x3c, 0x00, 0x91, 0x00, 0xfd, 0x00, 0xab,
            0x00, 0x23, 0x00, 0x21, 0x00, },
    },
};

struct vdsp_reg res0, res1;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vmov.t.e\n");

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vmov_s8_e(src[i].fixs8, res0.fixs8, res1.fixs8);
        result_compare_s8(res0.fixs8, dst0[i].fixs8);
        result_compare_s8(res1.fixs8, dst1[i].fixs8);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vmov_s16_e(src[i].fixs16, res0.fixs16, res1.fixs16);
        result_compare_s16(res0.fixs16, dst0[i].fixs16);
        result_compare_s16(res1.fixs16, dst1[i].fixs16);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vmov_s32_e(src[i].fixs32, res0.fixs32, res1.fixs32);
        result_compare_s32(res0.fixs32, dst0[i].fixs32);
        result_compare_s32(res1.fixs32, dst1[i].fixs32);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vmov_u8_e(src[i].fixu8, res0.fixu8, res1.fixu8);
        result_compare_u8(res0.fixu8, dst0[i].fixu8);
        result_compare_u8(res1.fixu8, dst1[i].fixu8);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vmov_u16_e(src[i].fixu16, res0.fixu16, res1.fixu16);
        result_compare_u16(res0.fixu16, dst0[i].fixu16);
        result_compare_u16(res1.fixu16, dst1[i].fixu16);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vmov_u32_e(src[i].fixu32, res0.fixu32, res1.fixu32);
        result_compare_u32(res0.fixu32, dst0[i].fixu32);
        result_compare_u32(res1.fixu32, dst1[i].fixu32);
    }

    return done_testing();
}
