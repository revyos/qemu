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
/* 0x7 0xf8 */
/*
/* src reg 0 */
struct vdsp_reg src[] = {
    {
        .fixs64 = {0x7ffffffe, 0xffffffff80000001, },
        .fixs32 = {0x7fff, 0x8000, 0xffff8000, 0xffff7fff, },
        .fixs16 = {0x7f, 0x71, 0x81, 0x7fff, 0x8000, 0xff80, 0xff81, 0xff7f},
        .fixs8 = {0xf, 0x1, 0x2, 0x3, 0x11, 0x12, 0x13, 0x7f, 0x80, 0xf8, 0xf1, 0xf2, 0xf3, 0xfa, 0xfb, 0xfc },
        .fixu64 = {0x7ffffffe, 0xffffffff80000001, },
        .fixu32 = {0x7fff, 0x7ffe, 0xffff8000, 0xffff8001 },
        .fixu16 = {0x7f, 0x71, 0x81, 0xff, 0x8000, 0xff80, 0xff81, 0xff7f},
        .fixu8 = {0xf, 0x1, 0x2, 0x3, 0x11, 0x12, 0x13, 0x1f, 0x80, 0xf8, 0xf1, 0xf2, 0xf3, 0xfa, 0xfb, 0xfc },
    },
};
/* dst reg 0 */
struct vdsp_reg dst[] = {
    {
        .fixs64 = {0x7ffffffe, 0xffffffff80000001, },
        .fixs32 = {0x7fff, 0x7fff, 0xffff8000, 0xffff8000, },
        .fixs16 = {0x7f, 0x71, 0x7f, 0x7f, 0xff80, 0xff80, 0xff81, 0xff80 },
        .fixs8 = {0x7, 0x1, 0x2, 0x03, 0x7, 0x07, 0x7, 0x07, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xfa, 0xfb, 0xfc },
        .fixu64 = {0x7ffffffe, 0x0, },
        .fixu32 = {0x7fff, 0x7ffe, 0x0, 0x0, },
        .fixu16 = {0x7f, 0x71, 0x81, 0xff, 0x0, 0x0, 0x0, 0x0 },
        .fixu8 = {0xf, 0x1, 0x2, 0x3, 0xf, 0xf, 0xf, 0x0f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vclipt.t\n");

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vclip_s8(src[i].fixs8, res.fixs8);
        result_compare_s8(res.fixs8, dst[i].fixs8);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vclip_s16(src[i].fixs16, res.fixs16);
        result_compare_s16(res.fixs16, dst[i].fixs16);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vclip_s32(src[i].fixs32, res.fixs32);
        result_compare_s32(res.fixs32, dst[i].fixs32);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vclip_s64(src[i].fixs64, res.fixs64);
        result_compare_s64(res.fixs64, dst[i].fixs64);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vclip_u8(src[i].fixu8, res.fixu8);
        result_compare_u8(res.fixu8, dst[i].fixu8);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vclip_u16(src[i].fixu16, res.fixu16);
        result_compare_u16(res.fixu16, dst[i].fixu16);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vclip_u32(src[i].fixu32, res.fixu32);
        result_compare_u32(res.fixu32, dst[i].fixu32);
    }

    for (i = 0; i < sizeof(src) / sizeof(struct vdsp_reg); i++) {
        test_vclip_u64(src[i].fixu64, res.fixu64);
        result_compare_u64(res.fixu64, dst[i].fixu64);
    }
    return done_testing();
}
