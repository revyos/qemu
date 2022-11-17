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
        .float16 = {0x4aee, 0x40aa, 0xc524, 0x46a9, 0x4a65, 0x404e, 0xc4bf, 0x4626, },
    },
};

struct vdsp_reg src1[] = {
    {
        .float16 = {0xcb85, 0x4b3d, 0xc332, 0x4a1a, 0xcaf1, 0x4aae, 0xc2a4, 0x49a2, },
    },
};

struct vdsp_reg src2[] = {
    {
        .float16 = {0x4684, 0x4633, 0xc5bd, 0xc984, 0x4604, 0x45b9,  0xc54c, 0xc918,},
    },
};

struct vdsp_reg dst0[] = {
    {
        .float16 = {0x883e, 0x4636, 0xc6cb, 0xc984, 0xb210, 0x45b8, 0xca60, 0xc918, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vfmuls.t.e\n");

#ifdef VDSP_FLOAT
    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vfmuls_f16_e(src0[i].float16, src1[i].float16, src2[i].float16);
        result_compare_f16(src2[i].float16, dst0[i].float16);
    }
#endif
    return done_testing();
}
