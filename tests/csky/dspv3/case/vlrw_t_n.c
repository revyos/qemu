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

struct vdsp_reg dst0[] = {
    {
        .fixs32 = {0xcfe06686, 0x00000000, 0x00000000, 0x00000000, },
        .fixs16 = {0xd6d6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, },
        .fixs8 = {0xa5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    },
    {
        .fixs32 = {0xcfe06686, 0x8262f661, 0x00000000, 0x00000000, },
        .fixs16 = {0xd6d6, 0x51f2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, },
        .fixs8 = {0xa5, 0x34, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    },
    {
        .fixs32 = {0xcfe06686, 0x8262f661, 0x15fc5221, 0x00000000, },
        .fixs16 = {0xd6d6, 0x51f2, 0x10ef, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, },
        .fixs8 = {0xa5, 0x34, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    },
    {
        .fixs32 = {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        .fixs16 = {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0x0000, 0x0000, 0x0000, 0x0000, },
        .fixs8 = {0xa5, 0x34, 0x8c, 0x74, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    },
};

struct vdsp_reg res;

int main(void)
{
    init_testsuite("Testing insn vlrw.t.n\n");

    test_vlrw_32_1(res.fixs32);
    result_compare_s32(res.fixs32, dst0[0].fixs32);

    test_vlrw_32_2(res.fixs32);
    result_compare_s32(res.fixs32, dst0[1].fixs32);

    test_vlrw_32_3(res.fixs32);
    result_compare_s32(res.fixs32, dst0[2].fixs32);

    test_vlrw_32_4(res.fixs32);
    result_compare_s32(res.fixs32, dst0[3].fixs32);

    return done_testing();
}
