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
    },
};

struct vdsp_reg src1[] = {
    {
        .fixs32 = {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
        .fixs16 = {0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
        .fixs8 = {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
    },
};


struct vdsp_reg dst0[] = {
    {
        .fixs32 = {0xcfe06686, 0x00000000, 0x00000000, 0x00000000, },
        .fixs16 = {0xd6d6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, },
        .fixs8 = {0xa5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    },
    {
        .fixs32 = {0xcfe06686, 0x8262f661, 0x00000000, 0x00000000, },
        .fixs16 = {0xd6d6, 0x51f2, 0x10ef, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, },
        .fixs8 = {0xa5, 0x34, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    },
    {
        .fixs32 = {0xcfe06686, 0x8262f661, 0x15fc5221, 0x00000000, },
        .fixs16 = {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x0, 0x0, },
        .fixs8 = {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0x00, 0x00, 0x00,},
    },
    {
        .fixs32 = {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        .fixs16 = {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        .fixs8 = {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i;
    int ry[3][4] = {{1, 2, 13, 0}, {1, 3, 6, 0}, {1, 2, 3, 0}};

    init_testsuite("Testing insn vldx.t\n");

    for (i = 0; i < sizeof(dst0) / sizeof(struct vdsp_reg); i++) {
        test_vldx_8(src0[0].fixs8, src1[0].fixs8, ry[0][i], res.fixs8);
        result_compare_s8(res.fixs8, dst0[i].fixs8);
    }

    for (i = 0; i < sizeof(dst0) / sizeof(struct vdsp_reg); i++) {
        test_vldx_16(src0[0].fixs16, src1[0].fixs16, ry[1][i], res.fixs16);
        result_compare_s16(res.fixs16, dst0[i].fixs16);
    }

    for (i = 0; i < sizeof(dst0) / sizeof(struct vdsp_reg); i++) {
        test_vldx_32(src0[0].fixs32, src1[0].fixs32, ry[2][i], res.fixs32);
        result_compare_s32(res.fixs32, dst0[i].fixs32);
    }

    return done_testing();
}
