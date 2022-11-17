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
        .fixu32 = {0x99988889, 0xaaa44555, 0x33331111, 0xddddbbbb, },
        .fixu16 = {0x1110, 0x2221, 0x3334, 0x4441, 0x5556, 0x666a, 0x7772, 0x888c, },
        .fixu8 = {0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0, 0x13, 0x57, 0x9b, 0xdf, 0x24, 0x68, 0xac, 0xe0, },
    },
};

struct vdsp_reg src1[] = {
    {
        .fixs32 = {0x0, 0x4, 0x8, 0xc, },
        .fixs16 = {0x0, 0x0, 0x0, 0x0, 0x2, 0x2, 0x2, 0x2, },
        .fixs8 = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, },
    },
};


struct vdsp_reg dst0[] = {
    {
        .fixs32 = {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        .fixs16 = {0xd6d6, 0xd6d6, 0xd6d6, 0xd6d6, 0x51f2, 0x51f2, 0x51f2, 0x51f2, },
        .fixs8 = {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i;
    init_testsuite("Testing insn vlde.t\n");
#ifdef CK803
    for (i = 0; i < sizeof(dst0) / sizeof(struct vdsp_reg); i++) {
        test_vlde_8(src0[i].fixs8, src1[i].fixs8, res.fixs8);
        result_compare_s8(res.fixs8, dst0[i].fixs8);

        test_vlde_16(src0[i].fixs16, src1[i].fixs16, res.fixs16);
        result_compare_s16(res.fixs16, dst0[i].fixs16);

        test_vlde_32(src0[i].fixs32, src1[i].fixs32, res.fixs32);
        result_compare_s32(res.fixs32, dst0[i].fixs32);
    }
#endif
    return done_testing();
}
