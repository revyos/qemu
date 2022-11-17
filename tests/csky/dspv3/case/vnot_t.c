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
        .fixs64 = {0x0123456789abcdef, 0xffffffff00000000, },
        .fixs32 = {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        .fixs16 = {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        .fixs8 = {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
    },
};

struct vdsp_reg dst[] = {
    {
        .fixs64 = {0xfedcba9876543210, 0x00000000ffffffff, },
        .fixs32 = {0x301f9979, 0x7d9d099e, 0xea03adde, 0x29468ba5, },
        .fixs16 = {0x2929, 0xae0d, 0xef10, 0xf15e, 0x5cb6, 0xb2c0, 0xb8a2, 0x5e9b, },
        .fixs8 = {0x5a, 0xcb, 0x73, 0x8b, 0x32, 0x8a, 0x6d, 0x85, 0x9f, 0xe6, 0xc3, 0x6e, 0x02, 0x54, 0xdc, 0xde, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vnot\n");

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vnot_8(src[i].fixs8, res.fixs8);
        result_compare_s8(res.fixs8, dst[i].fixs8);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vnot_16(src[i].fixs16, res.fixs16);
        result_compare_s16(res.fixs16, dst[i].fixs16);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vnot_32(src[i].fixs32, res.fixs32);
        result_compare_s32(res.fixs32, dst[i].fixs32);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vnot_64(src[i].fixs64, res.fixs64);
        result_compare_s64(res.fixs64, dst[i].fixs64);
    }

    return done_testing();
}
