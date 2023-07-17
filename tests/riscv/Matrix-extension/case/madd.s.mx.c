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
        .matrix_mx = 0x00007FFF

                       
    },
};

struct matrix_operates src1[] = {
    {
        .matrix_int32_s4x4 = {
            
                {0x80000000, 0x00000000, 0x80000000, 0x00000000},
                {0x00000008, 0x00000007, 0x00000006, 0x00000005},
                {0x00000004, 0x00000003, 0x00000002, 0x00000001},
                {0xFFFF8001, 0xFFFF8001, 0xFFFF8001, 0xFFFF8001},
            },
        .matrix_int32_s3x3 = {
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
                {0x00000008, 0x00000007, 0x00000006, 0x00000005},
                {0x00000004, 0x00000003, 0x00000002, 0x00000001},
                {0xFFFF8001, 0xFFFF8001, 0xFFFF8001, 0xFFFF8001},
        },
        .matrix_int64_s4x4 = {
            
                {0x80000000, 0x00000000, 0x80000000, 0x00000000},
                {0x00000008, 0x00000007, 0x00000006, 0x00000005},
                {0x00000004, 0x00000003, 0x00000002, 0x00000001},
                {0xFFFF8001, 0xFFFF8001, 0xFFFF8001, 0xFFFF8001},
            },
        .matrix_int64_s3x3 = {
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
                {0x00000008, 0x00000007, 0x00000006, 0x00000005},
                {0x00000004, 0x00000003, 0x00000002, 0x00000001},
                {0xFFFF8001, 0xFFFF8001, 0xFFFF8001, 0xFFFF8001},
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
            
                {0x80007fff, 0x00007FFF, 0x80007FFF, 0x00007FFF},
                {0x00008007, 0x00008006, 0x00008005, 0x00008004},
                {0x00008003, 0x00008002, 0x00008001, 0x00008000},
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
            },
        .matrix_int32_s3x3 = {
                {0x00007FFF, 0x00007FFF, 0x00007FFF, 0x00007FFF},
                {0x00008007, 0x00008006, 0x00008005, 0x00008004},
                {0x00008003, 0x00008002, 0x00008001, 0x00008000},
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
        },
        .matrix_int64_s4x4 = {
            
                {0x80007fff, 0x00007FFF, 0x80007FFF, 0x00007FFF},
                {0x00008007, 0x00008006, 0x00008005, 0x00008004},
                {0x00008003, 0x00008002, 0x00008001, 0x00008000},
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
            },
        .matrix_int64_s3x3 = {
                {0x00007FFF, 0x00007FFF, 0x00007FFF, 0x00007FFF},
                {0x00008007, 0x00008006, 0x00008005, 0x00008004},
                {0x00008003, 0x00008002, 0x00008001, 0x00008000},
                {0x00000000, 0x00000000, 0x00000000, 0x00000000},
        },
    },
};

struct matrix_operates res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn madd.s.mx\n");

    test_madds_mx(
            src0[0].matrix_mx, 
            src1[i].matrix_int32_s4x4, 
            src2[i].matrix_int32_s4x4, 
            res.matrix_int32_s4x4);
        result_compare_madds(dst0[i].matrix_int32_s4x4, res.matrix_int32_s4x4);

    test_madds_mx_nfull(
            src0[0].matrix_mx, 
            src1[i].matrix_int32_s3x3, 
            src2[i].matrix_int32_s3x3, 
            res.matrix_int32_s3x3);
    result_compare_madds_nfull(dst0[i].matrix_int32_s3x3, res.matrix_int32_s3x3);
    
    // test_madds_mx_I64(
    //         src0[0].matrix_mx, 
    //         src1[0].matrix_int64_s4x4, 
    //         src2[0].matrix_int64_s4x4, 
    //         res.matrix_int64_s4x4);
    //      result_compare_matrix_operations_I64(dst0[0].matrix_int64_s4x4, res.matrix_int64_s4x4);
  
    // test_madds_mx_nfull_I64(
    //         src0[0].matrix_mx, 
    //         src1[0].matrix_int64_s3x3, 
    //         src2[0].matrix_int64_s3x3, 
    //         res.matrix_int64_s3x3);
    //      result_compare_matrix_operations_nfull_I64(dst0[0].matrix_int64_s3x3, res.matrix_int64_s3x3);

    return done_testing();
}
