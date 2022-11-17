/*
 * Copyright (c) 2011-2019 C-SKY Limited. All rights reserved.
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
#include "matrix_insn.h"

struct matrix_mmaqa_b src0[] = {
    {
        .matrix_uint8_s4x16 = {
                {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
                {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
                {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
                {0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80},
            },
    }
};

struct matrix_mmaqa_b src1[] = {
    {
        .matrix_int8_s4x16 = {
                {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
                {0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80},
                {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
                {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        },
    },
};

struct matrix_mmaqa_b src2[] = {
    {
        .matrix_int32_s4x4 = {
                {0x11, 0x11, 0x11, 0x11},
                {0x11, 0x11, 0x11, 0x11},
                {0x11, 0x11, 0x11, 0x11},
                {0x11, 0x11, 0x11, 0x11},
        },
    },
};

struct matrix_mmaqa_b dst0[] = {
    {
        .matrix_int32_s4x4 = {
            {0X00001001, 0XFFF80811, 0XFFFFF021, 0X00000011},
            {0X00000011, 0X00000011, 0X00000011, 0X00000011},
            {0X00000021, 0XFFFFF811, 0X00000001, 0X00000011},
            {0X00000811, 0XFFFC0011, 0XFFFFF811, 0x00000011},
        },
    },
    {
        .matrix_int32_s4x4 = {
            {0x00000809, 0xFFFC0411, 0xFFFFF819, 0x00000000},
            {0x00000011, 0x00000011, 0x00000011, 0x00000000},
            {0x00000000, 0x00000000, 0x00000000, 0x00000000},
            {0x00000000, 0x00000000, 0x00000000, 0x00000000},
        },
    },
};

struct matrix_mmaqa_b res;

int main(void)
{
    init_testsuite("Testing insn mmaqaus.b\n");

    test_mmaqaus_4x4(src0[0].matrix_uint8_s4x16,
                     src1[0].matrix_int8_s4x16,
                     src2[0].matrix_int32_s4x4,
                     res.matrix_int32_s4x4);
    result_compare_mmaqa_4x4(dst0[0].matrix_int32_s4x4,
                            res.matrix_int32_s4x4);


    memset(&res, 0, sizeof(dst0[0]));

    test_mmaqaus_2x3(src0[0].matrix_uint8_s4x16,
                     src1[0].matrix_int8_s4x16,
                     src2[0].matrix_int32_s4x4,
                     res.matrix_int32_s4x4);
    result_compare_mmaqa_4x4(dst0[1].matrix_int32_s4x4,
                             res.matrix_int32_s4x4);

    return done_testing();
}
