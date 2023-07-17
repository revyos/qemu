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

struct rvv_reg src0[] = {
    {
        .fixs64 = {
            {0xfff0e92e56fe196a, 0x1c626bcd2715a031, },
            {0x7ff0e92e56fe196a, 0x1c626bcd2715a031, },
        },
        .fixs32 = {
            {0xc5cf5eb9, 0x75bc7c30, 0xf0bec11d, 0x683e0475, },
            {0x35cf5eb9, 0x75bc7c30, 0xf0bec11d, 0x683e0475, },
        },
        .fixs16 = {
            {0xfe56, 0x4b63, 0xf166, 0x08bc, 0x6f16, 0x0ddb, 0xdeb9, 0xafbe, },
            {0x2e56, 0x4b63, 0xf166, 0x08bc, 0x6f16, 0x0ddb, 0xdeb9, 0xafbe, },
        },
    },
};

uint64_t dst[8] = {0xfffffffffffffe56, 0xffffffffffff2e56, 0xffffffffc5cf5eb9, 0xffffffff35cf5eb9,
                   0xfff0e92e56fe196a, 0x7ff0e92e56fe196a,};
uint64_t res[6];

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vfmv.f.s\n");

    res[0] = test_vfmv_f_s_16(src0[i].fixs16[0]);
    res[1] = test_vfmv_f_s_16(src0[i].fixs16[1]);

    res[2] = test_vfmv_f_s_32(src0[i].fixs32[0]);
    res[3] = test_vfmv_f_s_32(src0[i].fixs32[1]);

    res[4] = test_vfmv_f_s_64(src0[i].fixs64[0]);
    res[5] = test_vfmv_f_s_64(src0[i].fixs64[1]);

    for (i = 0; i < 6; i++) {
        TEST(dst[i] == res[i]);
#ifdef DEBUG
        printf("0x%llx, 0x%llx,\n", dst[i], res[i]);
#endif
    }

    return done_testing();
}
