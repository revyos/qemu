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

struct matrix_fmmacc src0[] = {
    {
        .matrix_float16_s4x8 = {
                { 0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, },
                { 1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0, },
                {-1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, },
                { 2.0,  2.0,  2.0,  2.0,  2.0,  2.0,  2.0,  2.0, },
            },
    }
};

struct matrix_fmmacc src1[] = {
    {
        .matrix_float16_s4x8 = {
                {-1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, },
                { 2.0,  2.0,  2.0,  2.0,  2.0,  2.0,  2.0,  2.0, },
                { 0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, },
                { 1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0, },
            },
    }
};

struct matrix_fmmacc src2[] = {
    {
        .matrix_float16_s4x8 = {
                {-1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, },
                { 2.0,  2.0,  2.0,  2.0,  2.0,  2.0,  2.0,  2.0, },
                { 1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0, },
                { 0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, },
            },
    }
};

struct matrix_fmmacc src3[] = {
    {
        .matrix_float16_s4x8 = {
                { 1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0, },
                { 1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0, },
                { 1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0, },
                { 1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0, },
            },
    }
};

struct matrix_fmmacc dst0[] = {
    {
        .matrix_float16_s4x8 = {
                {  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0, },
                { -7.0, 17.0,  1.0,  9.0, -7.0, 17.0,  9.0,  1.0, },
                {  9.0,-15.0,  1.0, -7.0,  9.0,-15.0, -7.0,  1.0, },
                {-15.0, 33.0,  1.0, 17.0,-15.0, 33.0, 17.0,  1.0, },
            },
        .matrix_float16_s2x4 = {
                { 1.0,  1.0,  1.0,  1.0},
                {-3.0,  9.0, -3.0,  9.0},
            },
    }
};

struct matrix_fmmacc res;

int main(void)
{
    init_testsuite("Testing insn fmmacc.h\n");

    test_fmmacc_h_4x8(src0[0].matrix_float16_s4x8,
                      src1[0].matrix_float16_s4x8,
                      src2[0].matrix_float16_s4x8,
                      src3[0].matrix_float16_s4x8,
                      res.matrix_float16_s4x8);
    result_compare_fmmacc_h_4x8(dst0[0].matrix_float16_s4x8,
                                res.matrix_float16_s4x8);


    // test_fmmacc_h_2x4(src0[0].matrix_float16_s4x8,
    //                   src1[0].matrix_float16_s4x8,
    //                   src2[0].matrix_float16_s4x8,
    //                   src3[0].matrix_float16_s4x8,
    //                   res.matrix_float16_s2x4);
    // result_compare_fmmacc_h_2x4(dst0[0].matrix_float16_s2x4, 
    //                             res.matrix_float16_s2x4);

    return done_testing();
}
