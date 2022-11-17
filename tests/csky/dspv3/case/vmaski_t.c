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
        /* vmaski.16 vz, 0xaa */
        .fixs16 = {0x0, 0xffff, 0x0, 0xffff, 0x0, 0xffff, 0x0, 0xffff, },
        /* vmaski.8.h vz, 0x0c */
        .fixs8 = {0x78, 0x56, 0x34, 0x12, 0x78, 0x56, 0x34, 0x12, 0x0, 0x0, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, },
        /* vmaski.8.l vz, 0x72 */
        .fixu8 = {0x0, 0xff, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vmaski.t\n");

    for (i = 0; i < sizeof(dst) / sizeof(struct vdsp_reg); i++) {
        test_vmaski_8_h(res.fixs8);
        result_compare_s8(res.fixs8, dst[i].fixs8);
    }

    for (i = 0; i < sizeof(dst) / sizeof(struct vdsp_reg); i++) {
        test_vmaski_8_l(res.fixu8);
        result_compare_u8(res.fixu8, dst[i].fixu8);
    }

    for (i = 0; i < sizeof(dst) / sizeof(struct vdsp_reg); i++) {
        test_vmaski_16(res.fixs16);
        result_compare_s16(res.fixs16, dst[i].fixs16);
    }

    return done_testing();
}
