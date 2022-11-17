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


uint32_t src0 = 0x11223344;
struct vdsp_reg dst0[] = {
    {
        .fixs32 = {0x11223344, 0x11223344, 0x11223344, 0x11223344, },
        .fixs16 = {0x3344, 0x3344, 0x3344, 0x3344, 0x3344, 0x3344, 0x3344, 0x3344, },
        .fixs8 = {0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, },
    },
};

struct vdsp_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vdupg.t\n");

    test_vdupg_8(src0, res.fixs8);
    result_compare_s8(res.fixs8, dst0[i].fixs8);

    test_vdupg_16(src0, res.fixs16);
    result_compare_s16(res.fixs16, dst0[i].fixs16);

    test_vdupg_32(src0, res.fixs32);
    result_compare_s32(res.fixs32, dst0[i].fixs32);

    return done_testing();
}
