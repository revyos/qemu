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


struct matrix_operates src0[] = {
    {
        .matrix_int32_s4x4 = { 
                {0x00007FFF, 0x00007FFF, 0x00007FFF, 0x00007FFF},
                {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF},
                {0x00000001, 0x00000002, 0x00000003, 0x00000004},
                {0x00000005, 0x00000006, 0x00000007, 0x00000008},
            },
        .matrix_int32_s3x3 = {
                {0xFFFFFFFF, 0x00000000, 0x00000001, 0x00000000},
                {0x80000000, 0x00000000, 0x7FFFFFFF, 0x00000000},
                {0x00000000, 0x00000001, 0x00000000, 0x00000001},
                {0x00000008, 0x00000007, 0x00000006, 0x00000005},
            },
        
        .matrix_int64_s4x4 = { 
                {0x0000000000007FFF, 0x0000000000007FFF, 0x0000000000007FFF, 0x0000000000007FFF},
                {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF},
                {0x0000000000000001, 0x0000000000000002, 0x0000000000000003, 0x0000000000000004},
                {0x0000000000000005, 0x0000000000000006, 0x0000000000000007, 0x0000000000000008},
            },
        .matrix_int64_s3x3 = {
                {0xFFFFFFFFFFFFFFFF, 0x0000000000000000, 0x0000000000000001, 0x0000000000000000},
                {0xFFFFFFFF80000000, 0x0000000000000000, 0x000000007FFFFFFF, 0x0000000000000000},
                {0x0000000000000000, 0x0000000000000001, 0x0000000000000000, 0x0000000000000001},
                {0x0000000000000008, 0x0000000000000007, 0x0000000000000006, 0x0000000000000005},
            },


    },
};

struct matrix_operates src1[] = {
    {
        .matrix_int32_s4x4 = {
                {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF},
                {0x00007FFF, 0x00007FFF, 0x00007FFF, 0x00007FFF},
                {0x00000008, 0x00000007, 0x00000006, 0x00000005},
                {0x00000004, 0x00000003, 0x00000002, 0x00000001},
            },
        .matrix_int32_s3x3 = {
                {0x00000001, 0x00000002, 0x00000003, 0x00000000},
                {0x00000002, 0x00000003, 0x00000000, 0x00000000},
                {0x00000003, 0x00000004, 0x00000005, 0x00000000},
                {0x00000000, 0x12345532, 0x00000000, 0x12345532},
        },
        .matrix_int64_s4x4 = {
                {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF},
                {0x0000000000007FFF, 0x0000000000007FFF, 0x0000000000007FFF, 0x0000000000007FFF},
                {0x0000000000000008, 0x0000000000000007, 0x0000000000000006, 0x0000000000000005},
                {0x0000000000000004, 0x0000000000000003, 0x0000000000000002, 0x0000000000000001},
            },
        .matrix_int64_s3x3 = {
                {0x0000000000000001, 0x0000000000000002, 0x0000000000000003, 0x0000000000000000},
                {0x0000000000000002, 0x0000000000000003, 0x0000000000000000, 0x0000000000000000},
                {0x0000000000000003, 0x0000000000000004, 0x0000000000000005, 0x0000000000000000},
                {0x0000000000000000, 0x0000000012345532, 0x0000000000000000, 0x0000000012345532},
        },


    },
};
struct matrix_operates src2[] = {
    {
        .matrix_int32_s4x4 = {
                {0x00000000, 0x00000001, 0x00000002, 0x00000003},
                {0x00000004, 0x00000005, 0x00000006, 0x00000007},
                {0x00000008, 0x00000009, 0x0000000A, 0x0000000B},
                {0x0000000C, 0x0000000D, 0x0000000E, 0x0000000F},
            },
        .matrix_int32_s3x3 = {
                {0x00000001, 0x00000002, 0x00000003, 0x00000000},
                {0x00000002, 0x00000003, 0x00000004, 0x00000000},
                {0x00000003, 0x00000004, 0x00000005, 0x00000000},
                {0x00000000, 0x12345532, 0x00000000, 0x12345532},
        },
        .matrix_int64_s4x4 = {
                {0x0000000000000000, 0x0000000000000001, 0x0000000000000002, 0x0000000000000003},
                {0x0000000000000004, 0x0000000000000005, 0x0000000000000006, 0x0000000000000007},
                {0x0000000000000008, 0x0000000000000009, 0x000000000000000A, 0x000000000000000B},
                {0x000000000000000C, 0x000000000000000D, 0x000000000000000E, 0x000000000000000F},
            },
        .matrix_int64_s3x3 = {
                {0x0000000000000001, 0x0000000000000002, 0x0000000000000003, 0x0000000000000000},
                {0x0000000000000002, 0x0000000000000003, 0x0000000000000004, 0x0000000000000000},
                {0x0000000000000003, 0x0000000000000004, 0x0000000000000005, 0x0000000000000000},
                {0x0000000000000000, 0x0000000012345532, 0x0000000000000000, 0x0000000012345532},
        },


    },
};

struct matrix_operates dst0[] = {
    {
        .matrix_int32_s4x4 = {
                {0x00007FFE, 0x00007FFE, 0x00007ffe, 0x00007ffe},
                {0x00007FFE, 0x00007FFE, 0x00007ffe, 0x00007ffe},
                {0x00000009, 0x00000009, 0x00000009, 0x00000009},
                {0x00000009, 0x00000009, 0x00000009, 0x00000009},
            },
        .matrix_int32_s3x3 = {
                {0x00000000, 0x00000002, 0x00000004, 0x00000000},
                {0x80000002, 0x00000003, 0x7FFFFFFF, 0x00000000},
                {0x00000003, 0x00000005, 0x00000005, 0x00000001},
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
        },
        .matrix_int64_s4x4 = {
                {0x0000000000007FFE, 0x0000000000007FFE, 0x0000000000000000, 0x0000000000000000},
                {0x0000000000007FFE, 0x0000000000007FFE, 0x0000000000000000, 0x0000000000000000},
                {0x0000000000000009, 0x0000000000000009, 0x0000000000000000, 0x0000000000000000},
                {0x0000000000000009, 0x0000000000000009, 0x0000000000000000, 0x0000000000000000},
            },
        .matrix_int64_s3x3 = {
                {0x0000000000000000, 0x0000000000000002, 0x0000000000000004, 0x0000000000000000},
                {0xFFFFFFFF80000002, 0x0000000000000003, 0x0000000000000000, 0x0000000000000000},
                {0x0000000000000003, 0x0000000000000005, 0x0000000000000000, 0x0000000000000001},
                {0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
            },


    },
};

struct matrix_operates res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn madds_mm\n");

        printf("madd.s.mm \n");
        test_madds_mm(
            src0[0].matrix_int32_s4x4, 
            src1[0].matrix_int32_s4x4, 
            src2[0].matrix_int32_s4x4, 
            res.matrix_int32_s4x4);
        result_compare_madds(dst0[0].matrix_int32_s4x4, res.matrix_int32_s4x4);
    printf("madd.s.mm nfull\n");
	test_madds_mm_nfull(
            src0[0].matrix_int32_s3x3, 
            src1[0].matrix_int32_s3x3, 
            src2[0].matrix_int32_s3x3, 
            res.matrix_int32_s3x3);
        result_compare_madds_nfull(dst0[0].matrix_int32_s3x3, res.matrix_int32_s3x3);
    
    printf("madd.s.mm I64\n");
    // test_madds_mm_I64(
    //         src0[0].matrix_int64_s4x4, 
    //         src1[0].matrix_int64_s4x4, 
    //         src2[0].matrix_int64_s4x4, 
    //         res.matrix_int64_s4x4);
    //     result_compare_matrix_operations_I64(dst0[0].matrix_int64_s4x4, res.matrix_int64_s4x4);

    // printf("madd.s.mm I64 nfull\n");
    // test_madds_mm_nfull_I64(
    //         src0[0].matrix_int64_s3x3, 
    //         src1[0].matrix_int64_s3x3, 
    //         src2[0].matrix_int64_s3x3, 
    //         res.matrix_int64_s3x3);
    //     result_compare_matrix_operations_nfull_I64(dst0[0].matrix_int64_s3x3, res.matrix_int64_s3x3);

    return done_testing();
}
