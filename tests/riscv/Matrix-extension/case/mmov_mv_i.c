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


struct mmov src0[] = {
    {
       .matrix_uint64_4x2 = {{0x0000000000000001, 0x0000000000000002},
                             {0x0000000000000003, 0x0000000000000004},
                             {0x0000000000000005, 0x0000000000000006},
                             {0x0000000000000007, 0x0000000000000008}}
    }
};

struct mmov src1[] = {
    {
       .matrix_uint64_4x2 = {{0x000000000000000F, 0x000000000000000E},
                             {0x000000000000000D, 0x000000000000000C},
                             {0x000000000000000B, 0x000000000000000A},
                             {0x0000000000000007, 0x0000000000000008}}
    }
};

struct mmov dst0[] = {
    {
        .matrix_uint64_4x2 = {{0x0000000000000003, 0x0000000000000004},
                              {0x0000000000000003, 0x0000000000000004},
                              {0x0000000000000003, 0x0000000000000004},
                              {0x0000000000000003, 0x0000000000000004}}
    },
};

struct mmov res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn mmov.mv.i\n");

    test_mmov_mv_i(src0[i].matrix_uint64_4x2,
                   src1[i].matrix_uint64_4x2,
                   res.matrix_uint64_4x2);
    result_compare_mmov(dst0[i].matrix_uint64_4x2, res.matrix_uint64_4x2);

    return done_testing();
}
