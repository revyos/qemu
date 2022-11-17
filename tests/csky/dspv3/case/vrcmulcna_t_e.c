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
        .fixs32 = {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        .fixs16 = {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        .fixs8 = {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
    },
    {
        .fixs32 = {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
        .fixs16 = {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
        .fixs8 = {0x21, 0xb6, 0x8d, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
    },
    {
        .fixs64 = {0xfbb347d0ca9ab8e0, 0xfabff89db877b21d, },
        .fixs32 = {0x2ef3c1ca, 0xd167753f, 0xd345a93c, 0xcb8a4543, },
        .fixs16 = {0xf0f6, 0x8940, 0xf0cf, 0x70e1, 0x43dc, 0xd684, 0xd39d, 0x86d3, },
    },
    {
        .fixs64 = {0x3bb347d0ca9ab8e0, 0x2abff89db877b21d, },
        .fixs32 = {0x3bb347d0, 0xca9ab8e0, 0x2abff89d, 0xb877b21d, },
        .fixs16 = {0x64c6, 0x1d30, 0xdd97, 0xa399, 0x2754, 0xcccc, 0xd175, 0x62b3, },
    },
};

struct vdsp_reg dst[] = {
    {
        .fixs64 = {0x037189af1ab7c4e3, 0xdc128c21f9ef1b6e, },
        .fixs32 = {0x2c2070c7, 0xe2cd5066, 0xd002e032, 0xceab6031, },
        .fixs16 = {0xfe58, 0x7f73, 0xc99d, 0x63f7, 0x3ed1, 0xd08f, 0xb68c, 0x70a6, },
    },
    {
        .fixs64 = {0x38c2b863c5783c65, 0x2190774eb31f2272 },
        .fixs32 = {0x4234158b, 0xb092da6d, 0x1b1eddad, 0xb64f11b5, },
        .fixs16 = {0x5b99, 0x1bc6, 0xccfc, 0xc41b, 0x1f43, 0xc5dd, 0xd082, 0x6c82, },
    },
};

struct vdsp_reg res[2];

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vrcmulcna.t.e\n");

    test_vrcmulcna_s8_e(src[0].fixs8, res[0].fixs16);
    result_compare_s16(res[0].fixs16, dst[0].fixs16);
    result_compare_s16(res[1].fixs16, dst[1].fixs16);

    test_vrcmulcna_s16_e(src[0].fixs16, res[0].fixs32);
    result_compare_s32(res[0].fixs32, dst[0].fixs32);
    result_compare_s32(res[1].fixs32, dst[1].fixs32);

    test_vrcmulcna_s32_e(src[0].fixs32, res[0].fixs64);
    result_compare_s64(res[0].fixs64, dst[0].fixs64);
    result_compare_s64(res[1].fixs64, dst[1].fixs64);

    return done_testing();
}
