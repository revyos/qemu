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
        .fixs32 = {
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        },
    },
};

struct rvv_reg src_bak[] = {
    {
        .fixs32 = {
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        },
    },
};


struct rvv_reg src1[] = {
    {
        .fixs32 = {
            {0x00000000, 0x00000004, 0x00000008, 0x0000000c, },
            {0x00000010, 0x00000014, 0x00000018, 0x0000001c, },
        },
        .fixs64 = {
            {0x0000000000000000, 0x0000000000000004, },
            {0x0000000000000008, 0x000000000000000c, },
        },
    },
};

struct rvv_reg dst_vl[] = {
    /* src0 */
    {
        .fixs32 = {
            {0xcfe06686, 0x8262f661, 0x00000008, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x00000018, 0xd6b9745a, },
        },
    },
    {
        .fixs32 = {
            {0xcfe06686, 0x8262f661, 0x00000008, 0xd6b9745a, },
            {0x00000010, 0x00000014, 0x00000018, 0xd6b9745a, },
        },
    },
    /* result */
    {
        .fixs64 = {
            {0xffffffffcfe06686, 0xffffffff8262f661, },
            {0x0000000015fc5221, 0x0000000000000000, },
        },
        .fixs32 = {
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0x00000000 },
        },
    },
};


struct rvv_reg dst_even[] = {
    /* src0 */
    {
        .fixs32 = {
            {0xcfe06686, 0x8262f661, 0x00000008, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x00000018, 0xd6b9745a, },
        },
    },
    /* result */
    {
        .fixs64 = {
            {0xffffffffcfe06686, 0x0000000000000004, },
            {0x0000000015fc5221, 0x000000000000000c, },
        },
        .fixs32 = {
            {0xcfe06686, 0x00000004, 0x15fc5221, 0x0000000c, },
            {0xcfe06686, 0x00000014, 0x15fc5221, 0x0000001c, },
        },

    },
};

struct rvv_reg dst_odd[] = {
    /* src0 */
    {
        .fixs32 = {
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        },
    },
    /* result */
    {
        .fixs64 = {
            {0x0000000000000000, 0xffffffff8262f661, },
            {0x0000000000000008, 0xffffffffd6b9745a, },
        },
        .fixs32 = {
            {0x00000000, 0x8262f661, 0x00000008, 0xd6b9745a, },
            {0x00000010, 0x8262f661, 0x00000018, 0xd6b9745a, },
        },
    },
};
struct rvv_reg res0;

void restore_src(void)
{
    memcpy(&src0[0].fixs32[0][0], &src_bak[0].fixs32[0][0], 64);
    return;
}


int main(void)
{
    init_testsuite("Testing insn vamominw\n");

    /* sew 32 */
    test_vamominw_32(vlmax_32 - 1, &pad.fixs32[0], src0[0].fixs32[0], src1[0].fixs32[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst_vl[2].fixs32[0]);
    result_compare_s32_lmul(src0[0].fixs32[0], dst_vl[0].fixs32[0]);
    restore_src();
    test_vamominw_32_vm(&vme.fixs32, &pad.fixs32[0], src0[0].fixs32[0], src1[0].fixs32[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst_even[1].fixs32[0]);
    result_compare_s32_lmul(src0[0].fixs32[0], dst_even[0].fixs32[0]);

    restore_src();
    test_vamominw_32_vm(&vmo.fixs32, &pad.fixs32[0], src0[0].fixs32[0], src1[0].fixs32[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst_odd[1].fixs32[0]);
    result_compare_s32_lmul(src0[0].fixs32[0], dst_odd[0].fixs32[0]);

    restore_src();
    /* sew 64 */
    test_vamominw_64(vlmax_64 - 1, &pad.fixs64[0], src0[0].fixs32[0], src1[0].fixs64[0], res0.fixs64[0]);
    result_compare_s64_lmul(res0.fixs64[0], dst_vl[2].fixs64[0]);
    result_compare_s32(src0[0].fixs32[0], dst_vl[1].fixs32[0]);

    restore_src();
    test_vamominw_64_vm(&vme.fixs64, &pad.fixs64[0], src0[0].fixs32[0], src1[0].fixs64[0], res0.fixs64[0]);
    result_compare_s64_lmul(res0.fixs64[0], dst_even[1].fixs64[0]);
    result_compare_s32(src0[0].fixs32[0], dst_even[0].fixs32[0]);

    restore_src();
    test_vamominw_64_vm(&vmo.fixs64, &pad.fixs64[0], src0[0].fixs32[0], src1[0].fixs64[0], res0.fixs64[0]);
    result_compare_s64_lmul(res0.fixs64[0], dst_odd[1].fixs64[0]);
    result_compare_s32(src0[0].fixs32[0], dst_odd[0].fixs32[0]);
    return done_testing();
}

