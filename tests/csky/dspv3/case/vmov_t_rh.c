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
        .fixu64 = {0x7ff0e92e56fe196a, 0x1c626bcd2715a031, },
        .fixu32 = {0xc5cf5eb9, 0x75bc7c30, 0xf0bec11d, 0x683e0475, },
        .fixu16 = {0xfe56, 0x4b63, 0xf166, 0x08bc, 0x6f16, 0x0ddb, 0xdeb9, 0xafbe, },
    },
};

struct vdsp_reg src1[] = {
    {
        .fixs64 = {0x07d215928aa0d7b6, 0x0000000012345678, },
        .fixs32 = {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
        .fixs16 = {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
        .fixu64 = {0x00000000e547e732, 0x0afd8a490d762d5e, },
        .fixu32 = {0xe391e1de, 0xb2c0dd9f, 0x888fed5e, 0x000070fe, },
        .fixu16 = {0x6371, 0x3b45, 0x49ed, 0x7e26, 0x9ea1, 0xd612, 0x5c92, 0x0048, },
    },
};

struct vdsp_reg dst0[] = {
    {
        .fixs64 = {0xc6a630b33970b599, 0x0000000007d21593, },
        .fixs32 = {0x8263cfe0, 0xd6b915fc, 0xf1c07795, 0x12df67e4, },
        .fixs16 = {0x52d7, 0x0f11, 0x4da3, 0xa147, 0x3a50, 0xfb67, 0x99cf, 0xd030, },
        .fixu64 = {0x1c626bcd7ff0e92e, 0x0afd8a4900000001, },
        .fixu32 = {0x75bcc5cf, 0x683ef0bf, 0xb2c1e392, 0x00008890, },
        .fixu16 = {0x4bfe, 0x09f1, 0x0e6f, 0xb0df, 0x3b63, 0x7e4a, 0xd69f, 0x005d, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vmov.t.rh\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmov_s16_rh(src0[i].fixs16, src1[i].fixs16, res.fixs16);
        result_compare_s16(res.fixs16, dst0[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmov_s32_rh(src0[i].fixs32, src1[i].fixs32, res.fixs32);
        result_compare_s32(res.fixs32, dst0[i].fixs32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmov_s64_rh(src0[i].fixs64, src1[i].fixs64, res.fixs64);
        result_compare_s64(res.fixs64, dst0[i].fixs64);
    }


    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmov_u16_rh(src0[i].fixu16, src1[i].fixu16, res.fixu16);
        result_compare_u16(res.fixu16, dst0[i].fixu16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmov_u32_rh(src0[i].fixu32, src1[i].fixu32, res.fixu32);
        result_compare_u32(res.fixu32, dst0[i].fixu32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vmov_u64_rh(src0[i].fixu64, src1[i].fixu64, res.fixu64);
        result_compare_u64(res.fixu64, dst0[i].fixu64);
    }

    return done_testing();
}
