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



#include "matrix_insn.h"
#include "testsuite.h"


struct matrix_operates src0[] = {
    {
        .matrix_int32_s4x4 = { 
            
                {0x00000001, 0x00000002, 0x00000003, 0x00000004},
                {0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFFD, 0xFFFFFFFC},
                {0xFFFFFFFE, 0xFFFFFFFE, 0xFFFFFFFE, 0xFFFFFFFE},
                {0xFFFFFFFE, 0xFFFFFFFD, 0xFFFFFFFC, 0xFFFFFFFB},
                
            },
        .matrix_int32_s3x3 = {
            
                {0x00000001, 0x00000001, 0x00000001, 0x00000000},
                {0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFFD, 0x00000000},
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
                {0x00000008, 0x00000007, 0x00000006, 0x00000005},
               
            },
        .matrix_int64_s4x4 = { 
                {0x00000001, 0x00000002, 0x00000003, 0x00000004},
                {0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFFD, 0xFFFFFFFC},
                {0xFFFFFFFE, 0xFFFFFFFE, 0xFFFFFFFE, 0xFFFFFFFE},
                {0xFFFFFFFE, 0xFFFFFFFD, 0xFFFFFFFC, 0xFFFFFFFB},
            },
        .matrix_int64_s3x3 = {
                {0x00000001, 0x00000001, 0x00000001, 0x00000000},
                {0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFFD, 0x00000000},
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
                {0x00000008, 0x00000007, 0x00000006, 0x00000005},
            },
        
    },
};

struct matrix_operates src1[] = {
    {
        .matrix_int32_s4x4 = {
            
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
                {0x00000008, 0x00000007, 0x00000006, 0x00000005},
                {0x00000004, 0x00000003, 0x00000002, 0x00000001},
                {0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF},
            },
        .matrix_int32_s3x3 = {
                {0x00000001, 0x00000002, 0x00000003, 0x00000000},
                {0x00007FFF, 0x00007FFF, 0x00007FFF, 0x00000000},
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
                {0x00000008, 0x00000007, 0x00000006, 0x00000005},

        },
        .matrix_int64_s4x4 = {
            
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
                {0x00000008, 0x00000007, 0x00000006, 0x00000005},
                {0x00000004, 0x00000003, 0x00000002, 0x00000001},
                {0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF},
            },
        .matrix_int64_s3x3 = {
                {0x00000001, 0x00000002, 0x00000003, 0x00000000},
                {0x00007FFF, 0x00007FFF, 0x00007FFF, 0x00000000},
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
                {0x00000008, 0x00000007, 0x00000006, 0x00000005},

        },
    },
};

struct matrix_operates src2[] = {
    {
        .matrix_int32_s4x4 = {
            
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
                {0x00000008, 0x00000007, 0x00000006, 0x00000005},
                {0x00000004, 0x00000003, 0x00000002, 0x00000001},
                {0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF},
            },
        .matrix_int32_s3x3 = {
                {0x00000001, 0x00000002, 0x00000003, 0x00000000},
                {0x00007FFF, 0x00007FFF, 0x00007FFF, 0x00000000},
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
                {0x00000008, 0x00000007, 0x00000006, 0x00000005},

        },
        .matrix_int64_s4x4 = {
            
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
                {0x00000008, 0x00000007, 0x00000006, 0x00000005},
                {0x00000004, 0x00000003, 0x00000002, 0x00000001},
                {0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF},
            },
        .matrix_int64_s3x3 = {
                {0x00000001, 0x00000002, 0x00000003, 0x00000000},
                {0x00007FFF, 0x00007FFF, 0x00007FFF, 0x00000000},
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
                {0x00000008, 0x00000007, 0x00000006, 0x00000005},

        },
    },
};

struct matrix_operates dst0[] = {
    {
        .matrix_int32_s4x4 = {
            
                {0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFFD, 0xFFFFFFFC},
                {0x00000007, 0x00000005, 0x00000003, 0x00000001},
                {0x00000003, 0x00000001, 0xFFFFFFFF, 0xFFFFFFFD},
                {0x7FFFFFFE, 0x7FFFFFFD, 0x7FFFFFFC, 0x7FFFFFFB},

            },
        .matrix_int32_s3x3 = {
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
                {0x00007FFE, 0x00007FFD, 0x00007FFC, 0x00000000},
                {0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFFD, 0x00000000},
                {0x00000008, 0x00000007, 0x00000006, 0x00000005},
        },
        .matrix_int64_s4x4 = {
            
                {0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFFD, 0xFFFFFFFC},
                {0x00000007, 0x00000005, 0x00000003, 0x00000001},
                {0x00000003, 0x00000001, 0xFFFFFFFF, 0xFFFFFFFD},
                {0x7FFFFFFE, 0x7FFFFFFD, 0x7FFFFFFC, 0x7FFFFFFB},

            },
        .matrix_int64_s3x3 = {
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
                {0x00007FFE, 0x00007FFD, 0x00007FFC, 0x00000000},
                {0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFFD, 0x00000000},
                {0x00000008, 0x00000007, 0x00000006, 0x00000005},
        },
    },
};

struct matrix_operates res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn madds_mv.i\n");
    
        test_madds_mv_i(
            src0[0].matrix_int32_s4x4, 
            src1[0].matrix_int32_s4x4, 
            src1[0].matrix_int32_s4x4, 
            res.matrix_int32_s4x4);
         result_compare_madds(dst0[0].matrix_int32_s4x4, res.matrix_int32_s4x4);

        test_madds_mv_i_nfull(
            src0[0].matrix_int32_s3x3, 
            src1[0].matrix_int32_s3x3, 
            src1[0].matrix_int32_s3x3, 
            res.matrix_int32_s3x3);
         result_compare_madds_nfull(dst0[0].matrix_int32_s3x3, res.matrix_int32_s3x3);
    


    // test_madds_mv_i_I64(
    //         src0[0].matrix_int64_s4x4, 
    //         src1[0].matrix_int64_s4x4, 
    //         src1[0].matrix_int64_s4x4, 
    //         res.matrix_int64_s4x4);
    //      result_compare_matrix_operations_I64(dst0[0].matrix_int64_s4x4, res.matrix_int64_s4x4);
         
    //     test_madds_mv_i_nfull_I64(
    //         src0[i].matrix_int64_s3x3, 
    //         src1[i].matrix_int64_s3x3, 
    //         src1[0].matrix_int64_s3x3, 
    //         res.matrix_int64_s3x3);
    //      result_compare_matrix_operations_nfull_I64(dst0[i].matrix_int64_s3x3, res.matrix_int64_s3x3);

    return done_testing();
}
