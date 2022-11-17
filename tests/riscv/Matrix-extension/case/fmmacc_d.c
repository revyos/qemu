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
        .matrix_float64_s4x2 = {
                {0.0, 1.0},
                {2.0, 3.0},
                {4.0, 5.0},
                {6.0, 7.0},
            },

    }
};


struct matrix_fmmacc src1[] = {
    {
        .matrix_float64_s4x2 = {
                { 1.0, -1.0},
                { 0.0,  1.0},
                { 2.0,  2.0},
                {-2.0, -2.0},
                
            },

    }
};


struct matrix_fmmacc src2[] = {
    {
        .matrix_float64_s4x4 = {
                { 1.0, -1.0, -2, 2},
                { 0.0,  0.0, -10 ,0},
                { 2.0,  2.0, -8  ,9},
                { 1.0,  1.0, -9, 10},
                
            },
        .matrix_float64_s4x2_pair = {
                {{ 1.0, -1.0},
                { 0.0,  0.0},
                { 2.0,  2.0},
                { 1.0,  1.0},},

                {{ -2, 2},
                { -10 ,0},
                { -8  ,9},
                { -9, 10},},
        },

    }
};

struct matrix_fmmacc dst0[] = {
    {
    .matrix_float64_s4x2_pair = {
                {{ 0.0, 0.0},
                {-1.0, 3.0},
                { 1.0, 7.0},
                { 0.0, 8.0},},

                {{  0.0,  0.0 },
                { 0.0,   -10 },
                { 10.0,  -9.0 },
                { 17.0,  -16.0},}
        },
    .matrix_float64_s2x1_pair = {
                    {{0.0, 0.0},
                    { -1.0, 0.0},
                    { 0.0, 0.0},
                    { 0.0, 0.0},},

                    {{0.0,  0.0 },
                    { 0.0,  0.0 },
                    { 0.0,  0.0 },
                    { 0.0,  0.0},}
                },
    },
};

struct matrix_fmmacc res;

float main(void)
{
    init_testsuite("Testing insn fmmacc.d\n");



    test_fmmacc_d_4x2(src0[0].matrix_float64_s4x2,
                         src1[0].matrix_float64_s4x2,
                         src2[0].matrix_float64_s4x2_pair,
                         res.matrix_float64_s4x2_pair);
    result_compare_fmmacc_d_4x2(dst0[0].matrix_float64_s4x2_pair, 
                           res.matrix_float64_s4x2_pair);


    test_fmmacc_d_2x1(src0[0].matrix_float64_s4x2,
                      src1[0].matrix_float64_s4x2,
                      src2[0].matrix_float64_s4x2_pair,
                      res.matrix_float64_s2x1_pair);
    result_compare_fmmacc_d_4x2(dst0[0].matrix_float64_s2x1_pair,
                               res.matrix_float64_s2x1_pair);

    


    /* Todo: Not full calculation */
    return done_testing();
}
