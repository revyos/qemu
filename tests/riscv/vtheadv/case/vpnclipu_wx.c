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

uint64_t src0 = 0x84;

struct rvv_reg src1[] =
{
    {
        .fixu16 =
        {
            {
                0x2211, 0x2211, 0x2211, 0x2211,
                0x2211, 0x2211, 0x2211, 0x2211,
            },{
                0x9988, 0x9988, 0x9988, 0x9988,
                0x9988, 0x9988, 0x9988, 0x9988,
            },
        },
    },
};

struct rvv_reg dst_vl[] = {
    {
        .fixu8 = {
            {
                0xf1, 0xf1, 0xf1, 0xf1,
                0xf1, 0xf1, 0xf1, 0xf1,
                0xf8, 0xf8, 0xf8, 0xf8,
                0xf8, 0xf8, 0xf8, 0x11,
            },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixu8 = {
            {
                0xf1, 0x11, 0xf1, 0x11,
                0xf1, 0x11, 0xf1, 0x11,
                0xf8, 0x11, 0xf8, 0x11,
                0xf8, 0x11, 0xf8, 0x11,
            },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixu8 = {
            {
                0x11, 0xf1, 0x11, 0xf1,
                0x11, 0xf1, 0x11, 0xf1,
                0x11, 0xf8, 0x11, 0xf8,
                0x11, 0xf8, 0x11, 0xf8,
            },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    init_testsuite("Testing insn vpnclipu.wx\n");

    /* vpnclipu.wx */
    test_vpnclipu_wx(src0, src1[0].fixu16[0], res.fixu8[0], &vma8, pad.fixu8[0]);
    result_compare_u8(res.fixu8[0], dst_vl[0].fixu8[0]);

    test_vpnclipu_wx(src0, src1[0].fixu16[0], res.fixu8[0], &vme8, pad.fixu8[0]);
    result_compare_u8(res.fixu8[0], dst_even[0].fixu8[0]);

    test_vpnclipu_wx(src0, src1[0].fixu16[0], res.fixu8[0], &vmo8, pad.fixu8[0]);
    result_compare_u8(res.fixu8[0], dst_odd[0].fixu8[0]);

    return done_testing();
}
