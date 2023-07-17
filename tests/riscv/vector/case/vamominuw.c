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
 * Lesser General Public License  *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include "testsuite.h"
#include "rvv_insn.h"
#include <string.h>
struct rvv_reg src0[] = {
    {
        .fixu32 = {
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        },
    },
};

struct rvv_reg src_bak[] = {
    {
        .fixu32 = {
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        },
    },
};


struct rvv_reg src1[] = {
    {
        .fixu32 = {
            {0x00000000, 0x00000004, 0x00000008, 0x0000000c, },
            {0x00000010, 0x00000014, 0x00000018, 0x0000001c, },
        },
        .fixu64 = {
            {0x0000000000000000, 0x0000000000000004, },
            {0x0000000000000008, 0x000000000000000c, },
        },
    },
};

struct rvv_reg dst_vl[] = {
    /* src0 */
    {
        .fixu32 = {
            {0x00000000, 0x00000004, 0x00000008, 0x0000000c, },
            {0x00000010, 0x00000014, 0x00000018, 0xd6b9745a, },
        },
    },
    {
        .fixu32 = {
            {0x00000000, 0x00000004, 0x00000008, 0xd6b9745a, },
            {0x00000010, 0x00000014, 0x00000018, 0xd6b9745a, },
        },
    },
    /* result */
    {
        .fixu64 = {
            {0xffffffffcfe06686, 0xffffffff8262f661, },
            {0x0000000015fc5221, 0x0000000000000000, },
        },
        .fixu32 = {
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0x00000000 },
        },
    },
};


struct rvv_reg dst_even[] = {
    /* src0 */
    {
        .fixu32 = {
            {0x00000000, 0x8262f661, 0x00000008, 0xd6b9745a, },
            {0x00000010, 0x8262f661, 0x00000018, 0xd6b9745a, },
        },
    },
    /* result */
    {
        .fixu64 = {
            {0xffffffffcfe06686, 0x0000000000000004, },
            {0x0000000015fc5221, 0x000000000000000c, },
        },
        .fixu32 = {
            {0xcfe06686, 0x00000004, 0x15fc5221, 0x0000000c, },
            {0xcfe06686, 0x00000014, 0x15fc5221, 0x0000001c, },
        },

    },
};

struct rvv_reg dst_odd[] = {
    /* src0 */
    {
        .fixu32 = {
            {0xcfe06686, 0x00000004, 0x15fc5221, 0x0000000c,},
            {0xcfe06686, 0x00000014, 0x15fc5221, 0x0000001c, },
        },
    },
    /* result */
    {
        .fixu64 = {
            {0x0000000000000000, 0xffffffff8262f661, },
            {0x0000000000000008, 0xffffffffd6b9745a, },
        },
        .fixu32 = {
            {0x00000000, 0x8262f661, 0x00000008, 0xd6b9745a, },
            {0x00000010, 0x8262f661, 0x00000018, 0xd6b9745a, },
        },
    },
};
struct rvv_reg res0;

void restore_src(void)
{
    memcpy(&src0[0].fixu32[0][0], &src_bak[0].fixu32[0][0], 64);
    return;
}


int main(void)
{
    init_testsuite("Testing insn vamominuw\n");

    /* sew 32 */
    test_vamominuw_32(vlmax_32 - 1, &pad.fixu32[0], src0[0].fixu32[0], src1[0].fixu32[0], res0.fixu32[0]);
    result_compare_u32_lmul(res0.fixu32[0], dst_vl[2].fixu32[0]);
    result_compare_u32_lmul(src0[0].fixu32[0], dst_vl[0].fixu32[0]);
    restore_src();
    test_vamominuw_32_vm(&vme.fixu32, &pad.fixu32[0], src0[0].fixu32[0], src1[0].fixu32[0], res0.fixu32[0]);
    result_compare_u32_lmul(res0.fixu32[0], dst_even[1].fixu32[0]);
    result_compare_u32_lmul(src0[0].fixu32[0], dst_even[0].fixu32[0]);

    restore_src();
    test_vamominuw_32_vm(&vmo.fixu32, &pad.fixu32[0], src0[0].fixu32[0], src1[0].fixu32[0], res0.fixu32[0]);
    result_compare_u32_lmul(res0.fixu32[0], dst_odd[1].fixu32[0]);
    result_compare_u32_lmul(src0[0].fixu32[0], dst_odd[0].fixu32[0]);

    restore_src();
    /* sew 64 */
    test_vamominuw_64(vlmax_64 - 1, &pad.fixu64[0], src0[0].fixu32[0], src1[0].fixu64[0], res0.fixu64[0]);
    result_compare_u64_lmul(res0.fixu64[0], dst_vl[2].fixu64[0]);
    result_compare_u32(src0[0].fixu32[0], dst_vl[1].fixu32[0]);

    restore_src();
    test_vamominuw_64_vm(&vme.fixu64, &pad.fixu64[0], src0[0].fixu32[0], src1[0].fixu64[0], res0.fixu64[0]);
    result_compare_u64_lmul(res0.fixu64[0], dst_even[1].fixu64[0]);
    result_compare_u32(src0[0].fixu32[0], dst_even[0].fixu32[0]);

    restore_src();
    test_vamominuw_64_vm(&vmo.fixu64, &pad.fixu64[0], src0[0].fixu32[0], src1[0].fixu64[0], res0.fixu64[0]);
    result_compare_u64_lmul(res0.fixu64[0], dst_odd[1].fixu64[0]);
    result_compare_u32(src0[0].fixu32[0], dst_odd[0].fixu32[0]);
    return done_testing();
}

