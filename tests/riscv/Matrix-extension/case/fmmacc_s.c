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
        .matrix_float32_s4x4 = {
                { 1.0,  1.0,  1.0,  1.0},
                { 2.0,  2.0,  2.0,  2.0 },
                { 1.0,  1.0,  1.0,  1.0 },
                { 1.0,  1.0,  1.0,  1.0 },
            },
    }
};

struct matrix_fmmacc src1[] = {
    {
        .matrix_float32_s4x4 = {
                { 1.0,  1.0,  1.0,  1.0 },
                { 1.0,  1.0,  1.0,  1.0 },
                { 1.0,  1.0,  1.0,  1.0 },
                { 1.0,  1.0,  1.0,  1.0 },
            },
    }
};

struct matrix_fmmacc src2[] = {
    {
        .matrix_float32_s4x4 = {
                { 1.0,  1.0,  1.0,  1.0 },
                { 1.0,  1.0,  1.0,  1.0 },
                { 1.0,  1.0,  1.0,  1.0 },
                { 1.0,  1.0,  1.0,  1.0 },
            },
    }
};
struct matrix_fmmacc dst0[] = {
    {
        .matrix_float32_s4x4 = {
                { 5.0,  5.0,  5.0,  5.0 },
                { 9.0,  9.0,  9.0,  9.0 },
                { 5.0,  5.0,  5.0,  5.0 },
                { 5.0,  5.0,  5.0,  5.0 },
            },
        .matrix_float32_s2x2 = {
                { 3.0, 3.0, 0.0, 0.0},
                { 5.0, 5.0, 0.0, 0.0},
                { 0.0, 0.0, 0.0, 0.0},
                { 0.0, 0.0, 0.0, 0.0},

            },
    }
};

struct matrix_fmmacc res;

int main(void)
{
    init_testsuite("Testing insn fmmacc.s\n");

    test_fmmacc_s_4x4(src0[0].matrix_float32_s4x4,
                      src1[0].matrix_float32_s4x4,
                      src1[0].matrix_float32_s4x4,
                      res.matrix_float32_s4x4);
    result_compare_fmmacc_s_4x4(dst0[0].matrix_float32_s4x4,
                                    res.matrix_float32_s4x4);

    
    return done_testing();
}
