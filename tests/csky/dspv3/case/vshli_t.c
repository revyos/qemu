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
        .fixs16 = {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        .fixs8 = {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
        .fixu64 = {0x7ff0e92e56fe196a, 0x1c626bcd2715a031, },
        .fixu32 = {0xc5cf5eb9, 0x75bc7c30, 0xf0bec11d, 0x683e0475, },
        .fixu16 = {0xfe56, 0x4b63, 0xf166, 0x08bc, 0x6f16, 0x0ddb, 0xdeb9, 0xafbe, },
        .fixu8 = {0xc2, 0x29, 0x99, 0x3e, 0xe3, 0x82, 0x47, 0x89, 0xcd, 0xfb, 0xad, 0x9e, 0xe6, 0x27, 0x14, 0xc9, },
    },
};

struct vdsp_reg dst0[] = {
    {
        .fixs64 = {0xcb85acc9d58f9090, 0x3531859a3f39bbd8, },
        .fixs32 = {0x7f033430, 0x1317b308, 0xafe29108, 0xb5cba2d0, },
        .fixs16 = {0xb6b0, 0x8f90, 0x8778, 0x7508, 0x1a48, 0x69f8, 0x3ae8, 0x0b20, },
        .fixs8 = {0x28, 0xa0, 0x60, 0xa0, 0x68, 0xa8, 0x90, 0xd0, 0x00, 0xc8, 0xe0, 0x88, 0xe8, 0x58, 0x18, 0x08, },
        .fixu64 = {0xff874972b7f0cb50, 0xe3135e6938ad0188, },
        .fixu32 = {0x2e7af5c8, 0xade3e180, 0x85f608e8, 0x41f023a8, },
        .fixu16 = {0xf2b0, 0x5b18, 0x8b30, 0x45e0, 0x78b0, 0x6ed8, 0xf5c8, 0x7df0, },
        .fixu8 = {0x10, 0x48, 0xc8, 0xf0, 0x18, 0x10, 0x38, 0x48, 0x68, 0xd8, 0x68, 0xf0, 0x30, 0x38, 0xa0, 0x48, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vshli\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshli_s8(src0[i].fixs8,  res.fixs8);
        result_compare_s8(res.fixs8, dst0[i].fixs8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshli_s16(src0[i].fixs16,  res.fixs16);
        result_compare_s16(res.fixs16, dst0[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshli_s32(src0[i].fixs32,  res.fixs32);
        result_compare_s32(res.fixs32, dst0[i].fixs32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshli_s64(src0[i].fixs64,  res.fixs64);
        result_compare_s64(res.fixs64, dst0[i].fixs64);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshli_u8(src0[i].fixu8,  res.fixu8);
        result_compare_u8(res.fixu8, dst0[i].fixu8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshli_u16(src0[i].fixu16,  res.fixu16);
        result_compare_u16(res.fixu16, dst0[i].fixu16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshli_u32(src0[i].fixu32,  res.fixu32);
        result_compare_u32(res.fixu32, dst0[i].fixu32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshli_u64(src0[i].fixu64,  res.fixu64);
        result_compare_u64(res.fixu64, dst0[i].fixu64);
    }

    return done_testing();
}
