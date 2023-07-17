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
                {0xFF, 0x0F, 0xF0, 0x70 },
                {0x80, 0x01, 0x80, 0x01 },
                {0x00, 0x00, 0x70, 0x80 },
        },
        .move_int16 = {
            {0xFFFF, 0x0000, 0x0FFf, 0x0f0F},
            {0x8000, 0x7000, 0x0FFf, 0xF00f},
            {0x0000, 0x0001, 0xFFFF, 0x0001},
        },
        .move_int32 = {
            {0x00000000, 0x80000000, 0xFFFFFfff, 0xFFFFfff0},
            {0x70000000, 0x00000001, 0x80000001, 0x0f0000ff},
            {0x00001111, 0x7FFFFFFF, 0xFFFFFFFF, 0x80000000},
        },
        .move_int64 = {
            {0x0000000011111111, 0x8000000000000000},
            {0x00FFFFFFFfffffff, 0xFFFFFFFFFfffffff},
            {0x0000000000000001, 0x7000000000000000},
            {0x0fffffffffffffff, 0x000000000fffffff},
        },
    }
};

struct matrix_ld_st res;

int main(void)
{

    int i = 0, length = sizeof(src0) / sizeof(struct matrix_ld_st);
    init_testsuite("Testing insn mld and mst\n");

    for (i = 0; i < length; i++) {
        test_mldb(src0[i].move_int8, res.move_int8);
        result_compare_ld_and_st8((void *)res.move_int8, (void *)src0[i].move_int8);
    }
    for (i = 0; i < length; i++) {
        test_mldh(src0[i].move_int16, res.move_int16);
        result_compare_ld_and_st16((void *)res.move_int16, (void *)src0[i].move_int16);
    }
    for (i = 0; i < length; i++) {
        test_mldw(src0[i].move_int32,  res.move_int32);
        result_compare_ld_and_st32((void *)res.move_int32, (void *)src0[i].move_int32);
    }
    for (i = 0; i < length; i++) {
        test_mldd(src0[i].move_int64, res.move_int64);
        result_compare_ld_and_st((void *)res.move_int64,(void *) src0[i].move_int64);
    }

    return done_testing();
}
