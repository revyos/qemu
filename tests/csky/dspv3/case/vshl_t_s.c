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
        .fixs64 = {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
        .fixs32 = {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        .fixs16 = {0xd6d6, 0x51f2, 0x00ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        .fixs8 = {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
        .fixu64 = {0x7ff0e92e56fe196a, 0x1c626bcd2715a031, },
        .fixu32 = {0xc5cf5eb9, 0x75bc7c30, 0xf0bec11d, 0x683e0475, },
        .fixu16 = {0xfe56, 0x4b63, 0xf166, 0x08bc, 0x6f16, 0x0ddb, 0xdeb9, 0xafbe, },
        .fixu8 = {0xc2, 0x29, 0x99, 0x3e, 0xe3, 0x82, 0x47, 0x89, 0xcd, 0xfb, 0xad, 0x9e, 0xe6, 0x27, 0x14, 0xc9, },
    },
};

struct vdsp_reg src1[] = {
    {
        .fixs64 = {0x4, 0x40, },
        .fixs32 = {0x4, 0x20, 0x21, 0x0, },
        .fixs16 = {0x0, 0x10, 0x4, 0x11, 0x80, 0x81, 0x84, 0x91, },
        .fixs8 = {0x0, 0x8, 0x4, 0x9, 0x0, 0x8, 0x4, 0x9, 0x80, 0x88, 0x84, 0x89, 0x80, 0x88, 0x84, 0x89, },
        .fixu64 = {0x4, 0x40 },
        .fixu32 = {0x4, 0x20, 0x21, 0x0, },
        .fixu16 = {0x0, 0x10, 0x4, 0x11, 0x80, 0x81, 0x84, 0x91, },
        .fixu8 = {0x0, 0x8, 0x4, 0x9, 0x0, 0x8, 0x4, 0x9, 0x80, 0x88, 0x84, 0x89, 0x80, 0x88, 0x84, 0x89, },
    },
};

struct vdsp_reg dst0[] = {
    {
        .fixs64 = {0x7fffffffffffffff, 0x8000000000000000, },
        .fixs32 = {0x80000000, 0x80000000, 0x7fffffff, 0xd6b9745a, },
        .fixs16 = {0xd6d6, 0x7fff, 0x0ef0,0x7fff, 0x8000, 0x7fff, 0x7fff, 0x8000, },
        .fixs8 = {0xa5, 0x7f, 0x80, 0x7f, 0xcd, 0x7f, 0x80, 0x7f, 0x7f, 0x7f, 0x7f, 0x80, 0x80, 0x80, 0x7f, 0x7f, },
        .fixu64 = {0xffffffffffffffff, 0xffffffffffffffff, },
        .fixu32 = {0xffffffff, 0xffffffff, 0xffffffff, 0x683e0475, },
        .fixu16 = {0xfe56, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,},
        .fixu8 = {0xc2, 0xff, 0xff, 0xff, 0xe3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,  0xff, 0xff, 0xff, 0xff, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vshl.t.s\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshl_s8_s(src0[i].fixs8, src1[i].fixs8, res.fixs8);
        result_compare_s8(res.fixs8, dst0[i].fixs8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshl_s16_s(src0[i].fixs16, src1[i].fixs16, res.fixs16);
        result_compare_s16(res.fixs16, dst0[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshl_s32_s(src0[i].fixs32, src1[i].fixs32, res.fixs32);
        result_compare_s32(res.fixs32, dst0[i].fixs32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshl_s64_s(src0[i].fixs64, src1[i].fixs64, res.fixs64);
        result_compare_s64(res.fixs64, dst0[i].fixs64);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshl_u8_s(src0[i].fixu8, src1[i].fixu8, res.fixu8);
        result_compare_u8(res.fixu8, dst0[i].fixu8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshl_u16_s(src0[i].fixu16, src1[i].fixu16, res.fixu16);
        result_compare_u16(res.fixu16, dst0[i].fixu16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshl_u32_s(src0[i].fixu32, src1[i].fixu32, res.fixu32);
        result_compare_u32(res.fixu32, dst0[i].fixu32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshl_u64_s(src0[i].fixu64, src1[i].fixu64, res.fixu64);
        result_compare_u64(res.fixu64, dst0[i].fixu64);
    }

    return done_testing();
}
