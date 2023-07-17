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

int64_t src0 = 0x84;

struct rvv_reg src1[] =
{
    {
        .fixs16 =
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
        .fixs8 = {
            {
                0x71, 0x71, 0x71, 0x71,
                0x71, 0x71, 0x71, 0x71,
                0x88, 0x88, 0x88, 0x88,
                0x88, 0x88, 0x88, 0x11,
            },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs8 = {
            {
                0x71, 0x11, 0x71, 0x11,
                0x71, 0x11, 0x71, 0x11,
                0x88, 0x11, 0x88, 0x11,
                0x88, 0x11, 0x88, 0x11,
            },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs8 = {
            {
                0x11, 0x71, 0x11, 0x71,
                0x11, 0x71, 0x11, 0x71,
                0x11, 0x88, 0x11, 0x88,
                0x11, 0x88, 0x11, 0x88,
            },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    init_testsuite("Testing insn vpnclip.wx\n");

    /* vpnclip.wx */
    test_vpnclip_wx(src0, src1[0].fixs16[0], res.fixs8[0], &vma8, pad.fixs8[0]);
    result_compare_s8(res.fixs8[0], dst_vl[0].fixs8[0]);

    test_vpnclip_wx(src0, src1[0].fixs16[0], res.fixs8[0], &vme8, pad.fixs8[0]);
    result_compare_s8(res.fixs8[0], dst_even[0].fixs8[0]);

    test_vpnclip_wx(src0, src1[0].fixs16[0], res.fixs8[0], &vmo8, pad.fixs8[0]);
    result_compare_s8(res.fixs8[0], dst_odd[0].fixs8[0]);

    return done_testing();
}
