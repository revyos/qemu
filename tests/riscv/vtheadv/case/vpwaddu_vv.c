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

struct rvv_reg src0[] =
{
    {
        .fixu8 =
        {
            {
                0x44, 0x44, 0x44, 0x44,
                0x88, 0x88, 0x88, 0x88,
                0x44, 0x44, 0x44, 0x44,
                0x88, 0x88, 0x88, 0x88,
            },
        },
    },
};

struct rvv_reg src1[] =
{
    {
        .fixu8 =
        {
            {
                0x44, 0x44, 0x44, 0x44,
                0x88, 0x88, 0x88, 0x88,
                0x44, 0x44, 0x44, 0x44,
                0x88, 0x88, 0x88, 0x88,
            },
        },
    },
};

struct rvv_reg dst_vl[] = {
    {
        .fixu16 = {
            {
              0x0808, 0x0808, 0x0808, 0x0808,
              0x1010, 0x1010, 0x1010, 0x1010,
            }, {
              0x0808, 0x0808, 0x0808, 0x0808,
              0x1010, 0x1010, 0x1010, 0x1111,
            },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixu16 = {
            {
              0x0808, 0x1111, 0x0808, 0x1111,
              0x1010, 0x1111, 0x1010, 0x1111,
            }, {
              0x0808, 0x1111, 0x0808, 0x1111,
              0x1010, 0x1111, 0x1010, 0x1111,
            },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixu16 = {
            {
              0x1111, 0x0808, 0x1111, 0x0808,
              0x1111, 0x1010, 0x1111, 0x1010,
            }, {
              0x1111, 0x0808, 0x1111, 0x0808,
              0x1111, 0x1010, 0x1111, 0x1010,
            },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    init_testsuite("Testing insn vpwaddu.vv\n");

    /* vpwaddu.vv */
    test_vpwaddu_vv(src0[0].fixu8[0], src1[0].fixu8[0], res.fixu16[0], &vma8, pad.fixu16[0]);
    result_compare_u16(res.fixu16[0], dst_vl[0].fixu16[0]);
    result_compare_u16(res.fixu16[1], dst_vl[0].fixu16[1]);

    test_vpwaddu_vv(src0[0].fixu8[0], src1[0].fixu8[0], res.fixu16[0], &vme8, pad.fixu16[0]);
    result_compare_u16(res.fixu16[0], dst_even[0].fixu16[0]);
    result_compare_u16(res.fixu16[1], dst_even[0].fixu16[1]);

    test_vpwaddu_vv(src0[0].fixu8[0], src1[0].fixu8[0], res.fixu16[0], &vmo8, pad.fixu16[0]);
    result_compare_u16(res.fixu16[0], dst_odd[0].fixu16[0]);
    result_compare_u16(res.fixu16[1], dst_odd[0].fixu16[1]);

    return done_testing();
}
