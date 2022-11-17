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


struct matrix_pmmaqa_b src0[] = {
    {
        .matrix_int4_s4x32 = {

                {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
                {0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F},
                {0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80},
                {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
        },
    },
};

struct matrix_pmmaqa_b src1[] = {
    {
        .matrix_int4_s4x32 = {

                {0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80},
                {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
                {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
                {0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F},

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

struct matrix_pmmaqa_b dst0[] = {
    {
        .matrix_int32_s4x4 = {

                {0x00000011, 0x00000001, 0x00000021, 0x00000001},
                {0xFFFFFC91, 0xFFFFFFB1, 0x00000001, 0x00000331},
                {0x00000411, 0x00000091, 0x00000011, 0xFFFFFC91},
                {0x00000091, 0x00000031, 0x00000001, 0xFFFFFFB1},
        },
    },{
        .matrix_int32_s4x4 = {

                {0x00000011, 0x00000009, 0x00000019, 0x00000000},
                {0xFFFFFE51, 0xFFFFFFE1, 0x00000009, 0x00000000},
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
        },
    },
};

struct matrix_pmmaqa_b res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn pmmaqa.b\n");

    test_pmmaqa_4x4(src0[0].matrix_int4_s4x32,
                    src1[0].matrix_int4_s4x32,
                    src2[0].matrix_int32_s4x4,
                    res.matrix_int32_s4x4);
    result_compare_mmaqa_4x4(dst0[0].matrix_int32_s4x4, res.matrix_int32_s4x4);

    memset(&res, 0, sizeof(dst0[0]));
    
    test_pmmaqa_2x3(src0[0].matrix_int4_s4x32,
                    src1[0].matrix_int4_s4x32,
                    src2[0].matrix_int32_s4x4,
                    res.matrix_int32_s4x4);
    result_compare_mmaqa_4x4(dst0[1].matrix_int32_s4x4, res.matrix_int32_s4x4);


    return done_testing();
}
