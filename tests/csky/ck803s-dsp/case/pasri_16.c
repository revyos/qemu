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
    init_testsuite("Testing insn PASRI.16 \n");

    /*
     * PASRI.16
     * rz = {rx[31:16] << imm4, rx[15:0] << imm4, arithmetic shift
     */
    struct unary_calculation sample[TEST_TIMES] = {
        {0Xffff0000, 0xffff0000}, /* imm = 0 */
        {0X12345678, 0x091A2B3C}, /* imm = 1 */
        {0X0001ffff, 0x0000ffff}, /* imm = 9 */
        {0X80007fff, 0xffff0000}, /* imm = 15 */
    };

    TEST(test_pasri_16_0(sample[0].op1) == sample[0].result);
    TEST(test_pasri_16_1(sample[1].op1) == sample[1].result);
    TEST(test_pasri_16_9(sample[2].op1) == sample[2].result);
    TEST(test_pasri_16_15(sample[3].op1) == sample[3].result);
    return done_testing();
}

