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
#include "rvv_insn.h"

struct rvv_reg src0[] = {
    {
        .float64 = {
            {0x7fefffffffffffff, 0xffefffffffffffff,},
            {0x40154afd6a012e31, 0xc0417456836cfe7b,},
        },
        .float32 = {
            {0x483471f7, 0x46f2e02b, 0xc785dc35, 0x47ad69d9, },
            {0x483471f7, 0x46f2e02b, 0xff7fffff, 0x47ad69d9, },
        },
        .float16 = {
            {0x4aee, 0x40aa, 0xc524, 0x46a9, 0x4a65, 0x404e, 0xc4bf, 0x4626, },
            {0x4aee, 0x40aa, 0xc524, 0x46a9, 0x4a65, 0x404e, 0xc4bf, 0x4626, },
        },
    },
};

struct rvv_reg src1[] = {
    {
        .float64 = {
            {0x402b982fa8cba1c2, 0xc0371fb2129cb102},
            {0x402b982fa8cba1c2, 0xc0371fb2129cb102},
        },
        .float32 = {
            {0xc843ca22, 0x483c7bbf, 0xc73b64a7, 0x7f7fffff, },
            {0xc843ca22, 0x483c7bbf, 0xc73b64a7, 0x481eefee, },
        },
        .float16 = {
            {0xcb85, 0x4b3d, 0xc332, 0x4a1a, 0xcaf1, 0x4aae, 0xc2a4, 0x49a2, },
            {0x7bff, 0x4b3d, 0xfbff, 0x4a1a, 0xcaf1, 0x4aae, 0xc2a4, 0x49a2, },
        },
    },
};

struct rvv_reg dst[] = {
    {
        .float64 = {
            {0x7fb28def9bdf57c0, 0x7fa62445141b1068,},
            {0x3fd8b140d0108eb6, 0xc0371fb2129cb102,},
        },
        .float32 = {
            {0xbf6befd1, 0x3e24f025, 0x3fb6de33, 0x07ad69da,},
            {0xbf6befd1, 0x3e24f025, 0x77aedcbf, 0x483c7bbf,},
        },
        .float16 = {
            {0xbb5f, 0x3128, 0x3db7, 0x385e, 0xbb5f, 0x3128, 0x3db8, 0x385e,},
            {0x0aef, 0x3128, 0x0525, 0x385e, 0xbb5f, 0x3128, 0x3db8, 0x49a2,},
        },
    },
};

struct rvv_reg dst_vl[] = {
    {
        .float64 = {
            {0xfc93111855607f00, 0xfc8f32674847dcc0,},
            {0x3caf2f553d859050, 0x0000000000000000,},
        },
        .float32 = {
            {0x3b70f0f8, 0xb9e794d8, 0x3b2fbe8a, 0xbb252c4c,},
            {0x3b70f0f8, 0xb9e794d8, 0x73233932, 0x00000000,},
        },
        .float16 = {
            {0x194a, 0x9110, 0x9108, 0x9630, 0x98de, 0x8cc0, 0x1380, 0x95f0,},
            {0x9444, 0x9110, 0x15b6, 0x9630, 0x98de, 0x8cc0, 0x1380, 0x0000,},
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .float64 = {
            {0xfc93111855607f00, 0x7fa62445141b1068,},
            {0x3caf2f553d859050, 0xc0371fb2129cb102,},
        },
        .float32 = {
            {0x3b70f0f8, 0x3e24f025, 0x3b2fbe8a, 0x07ad69da,},
            {0x3b70f0f8, 0x3e24f025, 0x73233932, 0x483c7bbf,},
        },
        .float16 = {
            {0x194a, 0x3128, 0x9108, 0x385e, 0x98de, 0x3128, 0x1380, 0x385e,},
            {0x9444, 0x3128, 0x15b6, 0x385e, 0x98de, 0x3128, 0x1380, 0x49a2,},
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .float64 = {
            {0x7fb28def9bdf57c0, 0xfc8f32674847dcc0,},
            {0x3fd8b140d0108eb6, 0xc081ccf4c7db0d0c,},
        },
        .float32 = {
            {0xbf6befd1, 0xb9e794d8, 0x3fb6de33, 0xbb252c4c,},
            {0xbf6befd1, 0xb9e794d8, 0x77aedcbf, 0xd0ea09e2,},
        },
        .float16 = {
            {0xbb5f, 0x9110, 0x3db7, 0x9630, 0xbb5f, 0x8cc0, 0x3db8, 0x95f0,},
            {0x0aef, 0x9110, 0x0525, 0x9630, 0xbb5f, 0x8cc0, 0x3db8, 0xd78c,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vfnmsub.vv\n");


    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfnmsub_vv_16(vlmax_16 - 1, src0[i].float16[0],
                src1[i].float16[0], res.float16[0], dst[i].float16[0]);
        result_compare_s16_lmul(res.float16[0], dst_vl[i].float16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfnmsub_vv_16_vm(src0[i].float16[0], src1[i].float16[0],
                res.float16[0], vmo.fixu16, dst[i].float16[0]);
        result_compare_s16_lmul(res.float16[0], dst_odd[i].float16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfnmsub_vv_16_vm(src0[i].float16[0], src1[i].float16[0],
                res.float16[0], vme.fixu16, dst[i].float16[0]);
        result_compare_s16_lmul(res.float16[0], dst_even[i].float16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfnmsub_vv_32(vlmax_32 - 1, src0[i].float32[0],
                src1[i].float32[0], res.float32[0], dst[i].float32[0]);
        result_compare_s32_lmul(res.float32[0], dst_vl[i].float32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfnmsub_vv_32_vm(src0[i].float32[0], src1[i].float32[0],
                res.float32[0], vme.fixu32, dst[i].float32[0]);
        result_compare_s32_lmul(res.float32[0], dst_even[i].float32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfnmsub_vv_32_vm(src0[i].float32[0], src1[i].float32[0],
                res.float32[0], vmo.fixu32, dst[i].float32[0]);
        result_compare_s32_lmul(res.float32[0], dst_odd[i].float32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfnmsub_vv_64(vlmax_64 - 1, src0[i].float64[0],
                src1[i].float64[0], res.float64[0], dst[i].float64[0]);
        result_compare_s64_lmul(res.float64[0], dst_vl[i].float64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfnmsub_vv_64_vm(src0[i].float64[0], src1[i].float64[0],
                res.float64[0], vmo.fixu64, dst[i].float64[0]);
        result_compare_s64_lmul(res.float64[0], dst_odd[i].float64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfnmsub_vv_64_vm(src0[i].float64[0], src1[i].float64[0],
                res.float64[0], vme.fixu64, dst[i].float64[0]);
        result_compare_s64_lmul(res.float64[0], dst_even[i].float64[0]);
    }

    return done_testing();
}
