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


int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vmfvr.t\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        TEST(test_vmfvr_s8(src0[i].fixs8) == 0xffffffa5);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        TEST(test_vmfvr_s16(src0[i].fixs16) == 0xffffd6d6);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        TEST(test_vmfvr_s32(src0[i].fixs32) == 0xcfe06686);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        TEST(test_vmfvr_u8(src0[i].fixu8) == 0xc2);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        TEST(test_vmfvr_u16(src0[i].fixu16) == 0xfe56);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        TEST(test_vmfvr_u32(src0[i].fixu32) == 0xc5cf5eb9);
    }

    return done_testing();
}
