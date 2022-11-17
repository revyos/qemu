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
   .file   "micfunc.S"
#undef TEST_FUNC
#define TEST_FUNC(name) TEST_FUNC_M name
    .macro TEST_FUNC_M name
    .text
    .align  2
    .global \name
    .type   \name, @function
\name:
    .endm

TEST_FUNC(enable_irq)
	lrw	a3, 0x80000150
    mtcr a3, psr
    rts
    .size enable_irq, .-enable_irq 
TEST_FUNC(get_mpid)
    mfcr a0, cr<30, 0>
    rts
    .size get_mpid, .-get_mpid
TEST_FUNC(enable_ptim)
    movi a0, 1
    mtcr a0, cr<0, 14>
    rts
    .size enable_ptim, .-enable_ptim
TEST_FUNC(set_lvr)
    mtcr a0, cr<6, 14>
    rts
    .size set_lvr, .-set_lvr
TEST_FUNC(test_movi)
    movi a0, 160
    rts
    .size test_movi, .-test_movi
TEST_FUNC(mptimer_clear_irq)
    mfcr a0, cr<1, 14>
    rts
    .size mptimer_clear_irq, .-mptimer_clear_irq 
