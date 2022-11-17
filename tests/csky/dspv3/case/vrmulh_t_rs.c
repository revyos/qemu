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
        .fixs32 = {0xcfe06686, 0x80000000, 0x15fc5221, 0xd6b9745a, },
        .fixs16 = {0xd6d6, 0x8000, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        .fixs8 = {0xa5, 0x80, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
    },
};

struct vdsp_reg src1[] = {
    {
        .fixs32 = {0x7794d541, 0x80000000, 0x67e3b37f, 0x12df3e7c, },
        .fixs16 = {0x4fb8, 0x8000, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
        .fixs8 = {0x21, 0x80, 0x8d, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
    },
};

struct vdsp_reg dst0[] = {
    {
        .fixs32 = {0xd30aaa9a, 0x7fffffff, 0x11d82665, 0xf9ea174f, },
        .fixs16 = {0xe65d, 0x7fff, 0x0da9, 0xff62, 0x23da, 0xc223, 0x1ad2, 0x23b2, },
        .fixs8 = {0xe9, 0x7f, 0x68, 0x35, 0x0c, 0x08, 0x60, 0x14, 0x21, 0x04, 0xd9, 0x6a, 0xff, 0x21, 0x16, 0xee, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vrmulh.t.rs\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrmulh_s8_rs(src0[i].fixs8, src1[i].fixs8, res.fixs8);
        result_compare_s8(res.fixs8, dst0[i].fixs8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrmulh_s16_rs(src0[i].fixs16, src1[i].fixs16, res.fixs16);
        result_compare_s16(res.fixs16, dst0[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vrmulh_s32_rs(src0[i].fixs32, src1[i].fixs32, res.fixs32);
        result_compare_s32(res.fixs32, dst0[i].fixs32);
    }

    return done_testing();
}
