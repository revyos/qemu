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
        .fixs64 = {0x3fe0000000000000, 0xbfe0000000000000, },
    },
};

struct vdsp_reg src2[] = {
    {
        .float32 = {0x47a9ac4e, 0x47a16b54, 0xc79573cb, 0xc80fabbd, },
    },
};

struct vdsp_reg dst0[] = {
    {
        .float32 = {0x3f000000, 0xbf000000, 0x0, 0x0, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vdtos\n");

#ifdef VDSP_FLOAT
    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vdtos_f64(src0[i].fixs64, src2[i].float32);
        result_compare_f32(src2[i].float32, dst0[i].float32);
    }
#endif
    return done_testing();
}
