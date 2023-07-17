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
#include "matrix_insn.h"



struct matrix_ld_st src0[] = {
    {
        .move_int8 = {
                {0x7, 0x3, 0x8, 0x7 },
                {0x7, 0x2, 0x7, 0x7 },
                {0x7, 0x1, 0x6, 0x7 },
        },
        .move_int16 = {
            {0x70, 0x56, 0x7f, 0x7f},
            {0x70, 0x56, 0x7f, 0x7f},
            {0x70, 0x56, 0x7f, 0x7f},
        },
        .move_int32 = {
            {0x7000, 0x5600, 0x7fff, 0x7fff},
            {0x7000, 0x5600, 0x7fff, 0x7fff},
            {0x7000, 0x5600, 0x7fff, 0x7fff},
        },
        .move_int64 = {
                {0x70000000, 0x56000000, 0x60ffffff, 0x5000ffff},
                {0x70000000, 0x56000000, 0x7fffffff, 0x7fff0000},
                {0x70000000, 0x56000000, 0x56000000, 0x7fffffff},
        },
    }
};

struct matrix_ld_st res;


int main(void)
{

    
int i = 0, length;
    init_testsuite("Testing insn msld and msst\n");

    length = sizeof(src0) / sizeof(struct matrix_ld_st);

    for (i = 0; i < length; i++) {
        test_msldd(src0[i].move_int64, res.move_int64);
        result_compare_ld_and_st((void *)res.move_int64,(void *) src0[i].move_int64);
    }



    return done_testing();
}
