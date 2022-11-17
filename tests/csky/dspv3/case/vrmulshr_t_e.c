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
        .fixs32 = {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
        .fixs16 = {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
        .fixs8 = {0x21, 0xb6, 0x8d, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
    },
};

struct vdsp_reg dst[] = {
    {
        .fixs64 = {0xF4C2AAA6865FC303, 0x037F137B298330FA, },
        .fixs32 = {0xF99739E8, 0x093C171B, 0x036A543E, 0xFFD874CC, },
        .fixs16 = {0xfa22, 0xf87c, 0x1a0e, 0x0d24, 0x02fd, 0x020e, 0x1810, 0x0501, },
    },
    {
        .fixs64 = {0x0476099937EE68AF, 0xFE7A85D3CD3413CC, },
        .fixs32 = {0x08F682E4, 0xf088af61, 0x06B49F16, 0x08EC7BDA, },
        .fixs16 = {0x0840, 0x00ed, 0xf628, 0x1a73, 0xffc4, 0x084d, 0x0566, 0xfb8d, },
    },
};


struct vdsp_reg res[2];

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vrmulshr.t.e\n");

    test_vrmulshr_s8_e(src0[0].fixs8, src1[0].fixs8, res[0].fixs16, res[1].fixs16);
    result_compare_s16(res[0].fixs16, dst[0].fixs16);
    result_compare_s16(res[1].fixs16, dst[1].fixs16);

    test_vrmulshr_s16_e(src0[0].fixs16, src1[0].fixs16, res[0].fixs32, res[1].fixs32);
    result_compare_s32(res[0].fixs32, dst[0].fixs32);
    result_compare_s32(res[1].fixs32, dst[1].fixs32);

    test_vrmulshr_s32_e(src0[0].fixs32, src1[0].fixs32, res[0].fixs64, res[1].fixs64);
    result_compare_s64(res[0].fixs64, dst[0].fixs64);
    result_compare_s64(res[1].fixs64, dst[1].fixs64);

    return done_testing();
}
