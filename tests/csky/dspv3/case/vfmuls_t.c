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
        .float32 = {0x483471f7, 0x46f2e02b, 0xc785dc35, 0x47ad69d9, },
        .float16 = {0x4aee, 0x40aa, 0xc524, 0x46a9, 0x4a65, 0x404e, 0xc4bf, 0x4626, },
    },
};

struct vdsp_reg src1[] = {
    {
        .float32 = {0xc843ca22, 0x483c7bbf, 0xc73b64a7, 0x481eefee, },
        .float16 = {0xcb85, 0x4b3d, 0xc332, 0x4a1a, 0xcaf1, 0x4aae, 0xc2a4, 0x49a2, },
    },
};

struct vdsp_reg src2[] = {
    {
        .float32 = {0x47a9ac4e, 0x47a16b54, 0xc79573cb, 0xc80fabbd, },
        .float16 = {0x4684, 0x4633, 0xc5bd, 0xc984, 0x4604, 0x45b9,  0xc54c, 0xc918,},
    },
};

struct vdsp_reg dst0[] = {
    {
        .float32 = {0x510a015e, 0xcfb2d165, 0xcf43fa23, 0xd0575446, },
        .float16 = {0x5ab8, 0xcee4, 0xce0f, 0xd5c5, 0x59bd, 0xcdc2, 0xcd44, 0xd4f7, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vfmuls\n");

#ifdef VDSP_FLOAT
    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vfmuls_f32(src0[i].float32, src1[i].float32, src2[i].float32);
        result_compare_f32(src2[i].float32, dst0[i].float32);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct vdsp_reg); i++) {
        test_vfmuls_f16(src0[i].float16, src1[i].float16, src2[i].float16);
        result_compare_f16(src2[i].float16, dst0[i].float16);
    }
#endif
    return done_testing();
}
