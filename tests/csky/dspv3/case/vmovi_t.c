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

struct vdsp_reg dst[] = {
    {
        .float32 = {0xbfc00000, 0xbfc00000, 0xbfc00000, 0xbfc00000, },
        .float16 = {0xbe00, 0xbe00, 0xbe00, 0xbe00, 0xbe00, 0xbe00, 0xbe00, 0xbe00, },
        /* vmovi.s32 vz, 0x12, 3 */
        .fixs32 = {0xedffffff, 0xedffffff, 0xedffffff, 0xedffffff, },
        /* vmovi.s16 vz, 0x80, 1 */
        .fixs16 = {0x7fff, 0x7fff, 0x7fff, 0x7fff, 0x7fff, 0x7fff, 0x7fff, 0x7fff, },
        /* vmovi.8 vz, 0xff */
        .fixs8 = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
        /* vmovi.u32 vz, 0x12, 0 */
        .fixu32 = {0x12, 0x12, 0x12, 0x12, },
        /* vmovi.u16 vz, 0x80, 0 */
        .fixu16 = {0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, },
        /* vmovi.8 vz, 0xff */
        .fixu8 = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vmovi.t\n");

    for (i = 0; i < sizeof(dst) / sizeof(struct vdsp_reg); i++) {
        test_vmovi_8(res.fixs8);
        result_compare_s8(res.fixs8, dst[i].fixs8);
    }

    for (i = 0; i < sizeof(dst) / sizeof(struct vdsp_reg); i++) {
        test_vmovi_s16(res.fixs16);
        result_compare_s16(res.fixs16, dst[i].fixs16);
    }

    for (i = 0; i < sizeof(dst) / sizeof(struct vdsp_reg); i++) {
        test_vmovi_s32(res.fixs32);
        result_compare_s32(res.fixs32, dst[i].fixs32);
    }

    for (i = 0; i < sizeof(dst) / sizeof(struct vdsp_reg); i++) {
        test_vmovi_8(res.fixu8);
        result_compare_u8(res.fixu8, dst[i].fixu8);
    }

    for (i = 0; i < sizeof(dst) / sizeof(struct vdsp_reg); i++) {
        test_vmovi_u16(res.fixu16);
        result_compare_u16(res.fixu16, dst[i].fixu16);
    }

    for (i = 0; i < sizeof(dst) / sizeof(struct vdsp_reg); i++) {
        test_vmovi_u32(res.fixu32);
        result_compare_u32(res.fixu32, dst[i].fixu32);
    }
#ifdef VDSP_FLOAT
    for (i = 0; i < sizeof(dst) / sizeof(struct vdsp_reg); i++) {
        test_vmovi_f32(res.float32);
        result_compare_f32(res.float32, dst[i].float32);
    }

    for (i = 0; i < sizeof(dst) / sizeof(struct vdsp_reg); i++) {
        test_vmovi_f16(res.float16);
        result_compare_f16(res.float16, dst[i].float16);
    }
#endif
    return done_testing();
}
