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

   .file   "nvic_insn.S"

#undef  TEST_FUNC
#define TEST_FUNC(name) TEST_FUNC_M name
    .macro TEST_FUNC_M name
    .text
    .align  2
    .global \name
    .type   \name, @function
\name:
    .endm

TEST_FUNC(test_ipop)
    push    r4-r11, r15
    lrw     r4, 0x00000000
    lrw     r5, 0x00000001
    lrw     r6, 0x12345678
    lrw     r7, 0x7fffffff
    lrw     r8, 0x80000000
    lrw     r9, 0xffffffff
    push    r4-r9
    ipop
    cmpne   r0, r4
    bt      ipop_false
    cmpne   r1, r5
    bt      ipop_false
    cmpne   r2, r6
    bt      ipop_false
    cmpne   r3, r7
    bt      ipop_false
    cmpne   r12, r8
    bt      ipop_false
    cmpne   r13, r9
    bt      ipop_false
    movi    a0, 0
    br      ipop_end
ipop_false:
    movi    a0, 1
ipop_end:
    pop r4-r11, r15
    rts
    .size   test_ipop, .-test_ipop

TEST_FUNC(test_ipush)
    push    r4-r8
    lrw     r0, 0x00000000
    lrw     r1, 0x00000001
    lrw     r2, 0x12345678
    lrw     r3, 0x7fffffff
    lrw     r12, 0x80000000
    lrw     r13, 0xffffffff
    ipush
    mov     r8, sp
    ld.w    r4, (r8, 0)
    cmpne   r0, r4
    bt      ipush_false
    ld.w    r4, (r8, 4)
    cmpne   r1, r4
    bt      ipush_false
    ld.w    r4, (r8, 8)
    cmpne   r2, r4
    bt      ipush_false
    ld.w    r4, (r8, 12)
    cmpne   r3, r4
    bt      ipush_false
    ld.w    r4, (r8, 16)
    cmpne   r12, r4
    bt      ipush_false
    ld.w    r4, (r8, 20)
    cmpne   r13, r4
    bt      ipush_false
    movi    a0, 0
    br      ipush_end
ipush_false:
    movi    a0, 1
ipush_end:
    addi sp, sp, 24
    pop     r4-r8
    rts
    .size   test_ipush, .-test_ipush

TEST_FUNC(test_nie)
    push r4-r11, r15
    psrclr  ee, ie
    mfcr    r4, cr<2,0>   //epsr
    mfcr    r5, cr<4,0>   //epc
    nie
    mov     r8, sp
    ld.w    r6, (r8, 0)
    cmpne   r4, r6
    bt      nie_fail
    ld.w    r6, (r8, 4)
    cmpne   r5, r6
    bt      nie_fail
    mfcr    r4, cr<0,0>   //psr
    andi    r4, r4, 0x140 //psr{ee, ie} = 1
    cmpnei  r4, 0x140
    bt      nie_fail
    movi    a0, 0
    br      nie_end
nie_fail:
    movi    a0, 1
nie_end:
    addi sp, sp, 8
    pop r4-r11, r15
    rts
    .size   test_nie, .-test_nie

TEST_FUNC(test_sub_nir)
    mfcr    r4, cr<0,0>   //psr
    push    r4, r15
    mov     a0, r4
    nir
    .size   test_sub_nir, .-test_sub_nir

TEST_FUNC(test_nir)
    push r4, r15
    bsr test_sub_nir
    mfcr    r4, cr<0,0>   //psr
    cmpne   a0, r4
    bt      nir_fail
    movi    a0, 0
    br      nir_end
nir_fail:
    movi    a1, 1
nir_end:
    pop r4, r15
    .size   test_nir, .-test_nir

