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
        
        .matrix_mx = 0xfffffffe
    },
};

                
struct matrix_operates src1[] = {
    {
        .matrix_int32_s4x4 = {
            
                {0x00000001, 0x00000002, 0x00000003, 0x00000004},
                {0xffffffff, 0xfffffffe, 0xfffffffd, 0xfffffffc},
                {0x7ffff000, 0x7fff0001, 0x7ffff002, 0x7ffff003},
                {0x7ffff004, 0x7fff0005, 0x7ffff006, 0x7ffff007},
        },
        .matrix_int32_s3x3 = {
                {0x00000001, 0x00000002, 0x00000003, 0x00000004},
                {0xffffffff, 0xfffffffe, 0xfffffffd, 0xfffffffc},
                {0x7ffff000, 0x7fff0001, 0x7ffff002, 0x7ffff003},
                {0x7ffff004, 0x7fff0005, 0x7ffff006, 0x7ffff007},
        },
    },
};

struct matrix_operates src2[] = {
    {
        .matrix_int32_s4x4 = {
            
                {0x00000000, 0x00000001, 0x00000002, 0x00000003},
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
    },
};

struct matrix_operates dst0[] = {
    {
        .matrix_int32_s4x4 = {
                {0x00000003, 0x00000004, 0x00000005, 0x00000006},
                {0x00000001, 0x00000000, 0xffffffff, 0xfffffffe},
                {0x7ffff002, 0x7fff0003, 0x7ffff004, 0x7ffff005},
                {0x7ffff006, 0x7fff0007, 0x7ffff008, 0x7ffff009},
        },
        .matrix_int32_s3x3 = {
                {0x00000003, 0x00000004, 0x00000005, 0x00000006},
                {0x00000001, 0x00000000, 0xffffffff, 0xfffffffe},
                {0x7ffff002, 0x7fff0003, 0x7ffff004, 0x7ffff005},
                {0x7ffff006, 0x7fff0007, 0x7ffff008, 0x7ffff009},
        },
    },
};

struct matrix_operates res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn msub.s.mx\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct matrix_operates); i++) {
        test_msubs_mx(
            src0[i].matrix_mx, 
            src1[i].matrix_int32_s4x4, 
            src2[i].matrix_int32_s4x4, 
            res.matrix_int32_s4x4);
        result_compare_msubs(dst0[0].matrix_int32_s4x4, res.matrix_int32_s4x4);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct matrix_operates); i++) {
        test_msubs_mx_nfull(
            src0[i].matrix_mx, 
            src1[i].matrix_int32_s3x3, 
            src2[i].matrix_int32_s3x3, 
            res.matrix_int32_s3x3);
        result_compare_msubs_nfull(dst0[0].matrix_int32_s3x3, res.matrix_int32_s3x3);
    }
    

    return done_testing();
}



