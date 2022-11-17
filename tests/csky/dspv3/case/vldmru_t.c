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


union VDSP src0[] = {
    {
        .dspl = {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
    },
    {
        .dspi = {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
    },
    {
        .dsps = {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
    },
    {
        .dspc = {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
    },
};

union VDSP dst0[] = {
    {
        .dspl = {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
    },
    {
        .dspi = {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
    },
    {
        .dsps = {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
    },
    {
        .dspc = {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
    },
};

union VDSP res[4];

int main(void)
{
    init_testsuite("Testing insn vldmru.t\n");
    void *a;
    a = test_vldmru_32(src0[0].dspi, 16, res[0].dspi);
    TEST( a == ((void *)&src0[0] + 64));
    result_compare_s32(res[0].dspi, dst0[0].dspi);
    result_compare_s32(res[1].dspi, dst0[1].dspi);
    result_compare_s32(res[2].dspi, dst0[2].dspi);
    result_compare_s32(res[3].dspi, dst0[3].dspi);

    a = test_vldmru_16(src0[0].dsps, 16, res[0].dsps);
    TEST( a == ((void *)&src0[0] + 64));
    result_compare_s16(res[0].dsps, dst0[0].dsps);
    result_compare_s16(res[1].dsps, dst0[1].dsps);
    result_compare_s16(res[2].dsps, dst0[2].dsps);
    result_compare_s16(res[3].dsps, dst0[3].dsps);

    a = test_vldmru_8(src0[0].dspc, 16, res[0].dspc);
    TEST( a == ((void *)&src0[0] + 64));
    result_compare_s8(res[0].dspc, dst0[0].dspc);
    result_compare_s8(res[1].dspc, dst0[1].dspc);
    result_compare_s8(res[2].dspc, dst0[2].dspc);
    result_compare_s8(res[3].dspc, dst0[3].dspc);

    return done_testing();
}
