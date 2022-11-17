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
    },
};

struct vdsp_reg src1[] = {
    {
        .fixs64 = {0x1111111111111111, 0x1111111111111111, },
        .fixs32 = {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
        .fixs16 = {0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
        .fixs8 = {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
    },
};

struct vdsp_reg dst0[] = {
    {
        .fixs64 = {0xc6a630b347e7377b, 0x1111111111111111, },
        .fixs32 = {0x8262f661, 0x11111111, 0x11111111, 0x11111111, },
        .fixs16 = {0x51f2, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
        .fixs8 = {0x34, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
    },
    {
        .fixs64 = {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
        .fixs32 = {0x8262f661,0x15fc5221, 0x11111111, 0x11111111, },
        .fixs16 = {0x51f2, 0x10ef, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
        .fixs8 = {0x34, 0x8c, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
    },
    {
        .fixs64 = {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
        .fixs32 = {0x8262f661, 0x15fc5221, 0xd6b9745a, 0x11111111, },
        .fixs16 = {0x51f2, 0x10ef, 0x0ea1, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
        .fixs8 = {0x34, 0x8c, 0x74, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
    },
    {
        .fixs64 = {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
        .fixs32 = {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        .fixs16 = {0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x1111, 0x1111, 0x1111, 0x1111, },
        .fixs8 = {0x34, 0x8c, 0x74, 0xcd, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
    },
};

struct vdsp_reg res;

int main(void)
{
    init_testsuite("Testing insn vld.t.n\n");

    test_vld_8_1(src0[0].fixs8, src1[0].fixs8, res.fixs8);
    result_compare_s8(res.fixs8, dst0[0].fixs8);

    test_vld_8_2(src0[0].fixs8, src1[0].fixs8, res.fixs8);
    result_compare_s8(res.fixs8, dst0[1].fixs8);

    test_vld_8_3(src0[0].fixs8, src1[0].fixs8, res.fixs8);
    result_compare_s8(res.fixs8, dst0[2].fixs8);

    test_vld_8_4(src0[0].fixs8, src1[0].fixs8, res.fixs8);
    result_compare_s8(res.fixs8, dst0[3].fixs8);

    test_vld_16_1(src0[0].fixs16, src1[0].fixs16, res.fixs16);
    result_compare_s16(res.fixs16, dst0[0].fixs16);

    test_vld_16_2(src0[0].fixs16, src1[0].fixs16, res.fixs16);
    result_compare_s16(res.fixs16, dst0[1].fixs16);

    test_vld_16_3(src0[0].fixs16, src1[0].fixs16, res.fixs16);
    result_compare_s16(res.fixs16, dst0[2].fixs16);

    test_vld_16_4(src0[0].fixs16, src1[0].fixs16, res.fixs16);
    result_compare_s16(res.fixs16, dst0[3].fixs16);

    test_vld_32_1(src0[0].fixs32, src1[0].fixs32, res.fixs32);
    result_compare_s32(res.fixs32, dst0[0].fixs32);

    test_vld_32_2(src0[0].fixs32, src1[0].fixs32, res.fixs32);
    result_compare_s32(res.fixs32, dst0[1].fixs32);

    test_vld_32_3(src0[0].fixs32, src1[0].fixs32, res.fixs32);
    result_compare_s32(res.fixs32, dst0[2].fixs32);

    test_vld_32_4(src0[0].fixs32, src1[0].fixs32, res.fixs32);
    result_compare_s32(res.fixs32, dst0[3].fixs32);

    return done_testing();
}
