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
#include "test_device.h"
#include "dsp_insn.h"
#define TEST_TIMES      4
int main(void)
{
    init_testsuite("Testing insn PKG \n");

    /*
     * PKG
     * rz = {(ry >> oimm4)[15:0], (rx >> imm4)[15:0], logical shift
     */
    struct binary_calculation bin_sample[TEST_TIMES] = {
        {0Xffff0000, 0X0000ffff, 0x00000000}, /* imm = 0,  oimm = 16 */
        {0X00007fff, 0X0001fffe, 0xffff0000}, /* imm = 15, oimm = 1  */
        {0Xffff0000, 0X0000ffff, 0x7fff0000}, /* imm = 0,  oimm = 1  */
        {0X00007fff, 0X0001fffe, 0x00010000}, /* imm = 15, oimm = 16 */
    };

    TEST(test_pkg_0_16(bin_sample[0].op1, bin_sample[0].op2)
         == bin_sample[0].result);
    TEST(test_pkg_15_1(bin_sample[1].op1, bin_sample[1].op2)
         == bin_sample[1].result);
    TEST(test_pkg_0_1(bin_sample[2].op1, bin_sample[2].op2)
         == bin_sample[2].result);
    TEST(test_pkg_15_16(bin_sample[3].op1, bin_sample[3].op2)
         == bin_sample[3].result);
    return done_testing();
}

