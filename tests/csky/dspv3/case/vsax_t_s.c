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

/* src reg 0 */
struct vdsp_reg src0[] = {
    {
        .fixs32 = {0x22222222, 0x22222222, 0x70000000, 0x80222222, },
        .fixs16 = {0x2222, 0x2222, 0x2222, 0x2222, 0x2222, 0x2222, 0x8222, 0x2222, },
        .fixs8 = {0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x72, 0x81, },
        .fixu32 = {0x22222222, 0x22222222, 0x02222222, 0x22222222, },
        .fixu16 = {0x2222, 0x2222, 0x2222, 0x2222, 0x2222, 0x2222, 0xf222, 0xf222, },
        .fixu8 = {0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, },
    },
};
/* src reg 1 */
struct vdsp_reg src1[] = {
    {
        .fixs32 = {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
        .fixs16 = {0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x8001, 0x8111, },
        .fixs8 = {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x31, 0x11, },
        .fixu32 = {0x11111111, 0x11111111, 0x31111111, 0xf1111111, },
        .fixu16 = {0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
        .fixu8 = {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0xf1, },
    },
};
/* dst reg 0 */
struct vdsp_reg dst0[] = {
    {
        .fixs32 = {0x33333333, 0x11111111, 0x7fffffff, 0x80000000, },
        .fixs16 = {0x3333, 0x1111, 0x3333, 0x1111, 0x3333, 0x1111, 0x8000, 0x7fff, },
        .fixs8 = {0x33, 0x11, 0x33, 0x11, 0x33, 0x11, 0x33, 0x11, 0x33, 0x11, 0x33, 0x11, 0x33, 0x11, 0x7f, 0x80, },
        .fixu32 = {0x33333333, 0x11111111, 0xf3333333, 0x00000000, },
        .fixu16 = {0x3333, 0x1111, 0x3333, 0x1111, 0x3333, 0x1111, 0xffff, 0xe111, },
        .fixu8 = {0x33, 0x11, 0x33, 0x11, 0x33, 0x11, 0x33, 0x11, 0x33, 0x11, 0x33, 0x11, 0x33, 0x11, 0xff, 0x00, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vsax.t.s\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vsax_s8_s(src0[i].fixs8, src1[i].fixs8, res.fixs8);
        result_compare_s8(res.fixs8, dst0[i].fixs8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vsax_s16_s(src0[i].fixs16, src1[i].fixs16, res.fixs16);
        result_compare_s16(res.fixs16, dst0[i].fixs16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vsax_s32_s(src0[i].fixs32, src1[i].fixs32, res.fixs32);
        result_compare_s32(res.fixs32, dst0[i].fixs32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vsax_u8_s(src0[i].fixu8, src1[i].fixu8, res.fixu8);
        result_compare_u8(res.fixu8, dst0[i].fixu8);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vsax_u16_s(src0[i].fixu16, src1[i].fixu16, res.fixu16);
        result_compare_u16(res.fixu16, dst0[i].fixu16);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vsax_u32_s(src0[i].fixu32, src1[i].fixu32, res.fixu32);
        result_compare_u32(res.fixu32, dst0[i].fixu32);
    }

    return done_testing();
}
