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
        .fixs64 = {0x2222222218111111, 0x2222222211111111, },
        .fixs32 = {0xffff1811, 0xffff1111, 0x22221111, 0x22221111,  },
        .fixs16 = {0xff18, 0x2211, 0x8111, 0x8211, 0x2211, 0x2211, 0x2211, 0x2211, },
        .fixu64 = {0x2222222211111111, 0x2222222211111111, },
        .fixu32 = {0x0fff1111, 0x0fff1811, 0x22221111, 0x22221111,  },
        .fixu16 = {0xff18, 0x2211, 0x0218, 0x0211, 0x2211, 0x2211, 0x2211, 0x2211, },
    },
};

struct vdsp_reg src1[] = {
    {
        .fixs64 = {0x3333333333333333, 0x3333333333333333, },
        .fixs32 = {0x33333333, 0x33333333, 0x33333333, 0x33333333, },
        .fixs16 = {0x3333, 0x3333, 0x3333, 0x3333, 0x3333, 0x3333, 0x3333, 0x3333, },
        .fixu64 = {0x3333333333333333, 0x3333333333333333, },
        .fixu32 = {0x33333333, 0x33333333, 0x33333333, 0x33333333, },
        .fixu16 = {0x3333, 0x3333, 0x3333, 0x3333, 0x3333, 0x3333, 0x3333, 0x3333, },
    },
};


struct vdsp_reg dst0[] = {
    {
        .fixs64 = {0x7fffffff7fffffff, 0x3333333333333333, },
        .fixs32 = {0xfff1fff2, 0x7fff7fff, 0x33333333, 0x33333333, },
        .fixs16 = {0x7ff2, 0x8080, 0x7f7f, 0x7f7f, 0x3333, 0x3333, 0x3333, 0x3333, },
        .fixu64 = {0xffffffffffffffff, 0x3333333333333333, },
        .fixu32 = {0xfff2fff1, 0xffffffff, 0x33333333, 0x33333333, },
        .fixu16 = {0xffff, 0x2122, 0xffff, 0xffff, 0x3333, 0x3333, 0x3333, 0x3333, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vshri.t.lrs\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshri_s16_lrs(src0[i].fixs16, src1[i].fixs16, res.fixs16);
        result_compare_s16(res.fixs16, dst0[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshri_s32_lrs(src0[i].fixs32, src1[i].fixs32, res.fixs32);
        result_compare_s32(res.fixs32, dst0[i].fixs32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshri_s64_lrs(src0[i].fixs64, src1[i].fixs64, res.fixs64);
        result_compare_s64(res.fixs64, dst0[i].fixs64);
    }


    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshri_u16_lrs(src0[i].fixu16, src1[i].fixu16, res.fixu16);
        result_compare_u16(res.fixu16, dst0[i].fixu16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshri_u32_lrs(src0[i].fixu32, src1[i].fixu32, res.fixu32);
        result_compare_u32(res.fixu32, dst0[i].fixu32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vshri_u64_lrs(src0[i].fixu64, src1[i].fixu64, res.fixu64);
        result_compare_u64(res.fixu64, dst0[i].fixu64);
    }

    return done_testing();
}
