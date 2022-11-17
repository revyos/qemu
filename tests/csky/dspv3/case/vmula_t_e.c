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
        .fixu32 = {0xc5cf5eb9, 0x75bc7c30, 0xf0bec11d, 0x683e0475, },
        .fixu16 = {0xfe56, 0x4b63, 0xf166, 0x08bc, 0x6f16, 0x0ddb, 0xdeb9, 0xafbe, },
        .fixu8 = {0xc2, 0x29, 0x99, 0x3e, 0xe3, 0x82, 0x47, 0x89, 0xcd, 0xfb, 0xad, 0x9e, 0xe6, 0x27, 0x14, 0xc9, },
    },
    {
        .fixs32 = {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
        .fixs16 = {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
        .fixs8 = {0x21, 0xb6, 0x8d, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
        .fixu32 = {0xe391e1de, 0xb2c0dd9f, 0x888fed5e, 0x1c3b70fe, },
        .fixu16 = {0x6371, 0x3b45, 0x49ed, 0x7e26, 0x9ea1, 0xd612, 0x5c92, 0xfc48, },
        .fixu8 = {0x1c, 0x42, 0xd3, 0x53, 0x94, 0x57, 0x7b, 0xa3, 0xae, 0x96, 0x41, 0x28, 0x3a, 0x59, 0x9b, 0x70, },
    },
    {
        .fixs64 = {0xfbb347d0ca9ab8e0, 0xfabff89db877b21d, },
        .fixs32 = {0x2ef3c1ca, 0xd167753f, 0xd345a93c, 0xcb8a4543, },
        .fixs16 = {0xf0f6, 0x8940, 0xf0cf, 0x70e1, 0x43dc, 0xd684, 0xd39d, 0x86d3, },
        .fixu64 = {0xd6bc23efd20235bb, 0xdb7e4b2f588d9bbf, },
        .fixu32 = {0xd6bc23ef, 0xd20235bb, 0xdb7e4b2f, 0x588d9bbf, },
        .fixu16 = {0x5d85, 0xab10, 0xc750, 0xab2a, 0xa9ae, 0xf97c, 0x415e, 0x882d, },
    },
    {
        .fixs64 = {0x3bb347d0ca9ab8e0, 0x2abff89db877b21d, },
        .fixs32 = {0x3bb347d0, 0xca9ab8e0, 0x2abff89d, 0xb877b21d, },
        .fixs16 = {0x64c6, 0x1d30, 0xdd97, 0xa399, 0x2754, 0xcccc, 0xd175, 0x62b3, },
        .fixu64 = {0x3bb347d0ca9ab8e0, 0x2abff89db877b21d, },
        .fixu32 = {0x5499e15d, 0x7bcc175b, 0x61113f55, 0x85854e35, },
        .fixu16 = {0xe37b, 0x3ac3, 0xc756, 0x3a26, 0x3464, 0xc827, 0x1c07, 0x950b, },
    },
};

struct vdsp_reg dst0[] = {
    {
        .fixs64 = {0xe5389d1dd75a3ee6, 0x01be1f940b7e1412,},
        .fixs32 = {0x2222359a, 0xe3dfa375, 0xda1a51b8, 0xcb3b2edb, },
        .fixs16 = {0xe53b, 0x7a38, 0x24eb, 0x8b29, 0x49d6, 0xdaa1, 0x03bd, 0x90d5,  },
        .fixu64 = {0x8693bde94fdff329, 0x2db40cd2b3d42d8f,},
        .fixu32 = {0x3987a9e5, 0xe376586a, 0x2133dc9d, 0x5cdb6fa7,  },
        .fixu16 = {0x72bd, 0xb5a2, 0x456b, 0xbf44, 0x2cea, 0x25aa, 0x637b, 0xdf68,},
    },
    {
        .fixs64 = {0x449f5b033a778a3f, 0x27b5044552dfd9b5, },
        .fixs32 = {0x4da04d99, 0xabac17a3, 0x382936c9, 0xca50a9d1, },
        .fixs16 = {0x7546, 0x1f0b, 0xc9e7, 0xd87f, 0x26dc, 0xdd66, 0xdc42, 0x59ce, },
        .fixu64 = {0xbc1ff82f10a07a86, 0x363ef5681aea4e33, },
        .fixu32 = {0x996f5233, 0x876222c1, 0xb19ac0d7, 0x32b5c3a5, },
        .fixu16 = {0x6ed1, 0xcdd5, 0xf343, 0x52d6, 0x6880, 0xd5b6, 0x2823, 0xecfb,},
    },
};

struct vdsp_reg res[2];

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vmula.t.e\n");

    test_vmula_s8_e(src[0].fixs8, res[0].fixs16);
    result_compare_s16(res[0].fixs16, dst0[0].fixs16);
    result_compare_s16(res[1].fixs16, dst0[1].fixs16);

    test_vmula_s16_e(src[0].fixs16, res[0].fixs32);
    result_compare_s32(res[0].fixs32, dst0[0].fixs32);
    result_compare_s32(res[1].fixs32, dst0[1].fixs32);

    test_vmula_s32_e(src[0].fixs32, res[0].fixs64);
    result_compare_s64(res[0].fixs64, dst0[0].fixs64);
    result_compare_s64(res[1].fixs64, dst0[1].fixs64);

    test_vmula_u8_e(src[0].fixu8, res[0].fixu16);
    result_compare_u16(res[0].fixu16, dst0[0].fixu16);
    result_compare_u16(res[1].fixu16, dst0[1].fixu16);

    test_vmula_u16_e(src[0].fixu16, res[0].fixu32);
    result_compare_u32(res[0].fixu32, dst0[0].fixu32);
    result_compare_u32(res[1].fixu32, dst0[1].fixu32);

    test_vmula_u32_e(src[0].fixu32, res[0].fixu64);
    result_compare_u64(res[0].fixu64, dst0[0].fixu64);
    result_compare_u64(res[1].fixu64, dst0[1].fixu64);

    return done_testing();
}
