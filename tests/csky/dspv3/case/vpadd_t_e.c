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

/* src reg 0 */
struct vdsp_reg src[] = {
    {
        .fixs32 = {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        .fixs16 = {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        .fixs8 = {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
        .fixu32 = {0xc5cf5eb9, 0x75bc7c30, 0xf0bec11d, 0x683e0475, },
        .fixu16 = {0xfe56, 0x4b63, 0xf166, 0x08bc, 0x6f16, 0x0ddb, 0xdeb9, 0xafbe, },
        .fixu8 = {0xc2, 0x29, 0x99, 0x3e, 0xe3, 0x82, 0x47, 0x89, 0xcd, 0xfb, 0xad, 0x9e, 0xe6, 0x27, 0x14, 0xc9, },
    },
};
/* dst reg 0 */
struct vdsp_reg dst[] = {
    {
        .fixs32 = {0x52435ce7, 0xffffffff, 0xecb5c67b, 0xffffffff, },
        .fixs16 = {0x28c8, 0x0000, 0x1f90, 0x0000, 0xf088, 0xffff, 0xe8c1, 0xffff, },
        .fixs8 = {0xd9, 0xff, 0x00, 0x00, 0x42, 0x00, 0x0c, 0x00, 0x79, 0x00, 0xcd, 0xff, 0xa8, 0xff, 0x44, 0x00, },
        .fixu32 = {0x3b8bdae9, 0x00000001, 0x58fcc592, 0x00000001, },
        .fixu16 = {0x49b9, 0x0001, 0xfa22, 0x0000, 0x7cf1, 0x0000, 0x8e77, 0x0001, },
        .fixu8 = {0xeb, 0x00, 0xd7, 0x00, 0x65, 0x01, 0xd0, 0x00, 0xc8, 0x01, 0x4b, 0x01, 0x0d, 0x01, 0xdd, 0x00, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vpadd.t.e\n");

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vpadd_s8_e(src[i].fixs8, res.fixs8);
        result_compare_s8(res.fixs8, dst[i].fixs8);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vpadd_s16_e(src[i].fixs16, res.fixs16);
        result_compare_s16(res.fixs16, dst[i].fixs16);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vpadd_s32_e(src[i].fixs32, res.fixs32);
        result_compare_s32(res.fixs32, dst[i].fixs32);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vpadd_u8_e(src[i].fixu8, res.fixu8);
        result_compare_u8(res.fixu8, dst[i].fixu8);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vpadd_u16_e(src[i].fixu16, res.fixu16);
        result_compare_u16(res.fixu16, dst[i].fixu16);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vpadd_u32_e(src[i].fixu32, res.fixu32);
        result_compare_u32(res.fixu32, dst[i].fixu32);
    }

    return done_testing();
}
