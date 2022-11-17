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

   .file   "fpu_insn.S"
#undef TEST_FUNC
#define TEST_FUNC(name) TEST_FUNC_M name
    .macro TEST_FUNC_M name
    .text
    .align  2
    .global \name
    .type   \name, @function
\name:
    .endm

TEST_FUNC(test_ide)
    lrw     r0, 0x20008000
    lrw     r1, 0x0000ffff
    stw     r1, (r0, 0)
    flds    vr1, (r0, 0)
    movi    r0, 0
    mtcr    r0, cr<2, 2>
    fstosi.rz   vr1, vr1
    mfcr    r0, cr<2, 2>
    rts
    .size   test_ide, .-test_ide

TEST_FUNC(test_ioe)
    lrw     r0, 0x20008000
    lrw     r1, 0xff800000
    lrw     r2, 0x7f800000
    stw     r1, (r0, 0)
    stw     r2, (r0, 4)
    flds    vr1, (r0, 0)
    flds    vr2, (r0, 4)
    movi    r0, 0
    mtcr    r0, cr<2, 2>
    fadds   vr1, vr1, vr2
    mfcr    r0, cr<2, 2>
    rts
    .size   test_ioe, .-test_ioe

TEST_FUNC(test_dze)
    lrw     r0, 0x20008000
    lrw     r1, 0x00000000
    stw     r1, (r0, 0)
    flds    vr1, (r0, 0)
    fmovis  vr2, -1.5
    movi    r0, 0
    mtcr    r0, cr<2, 2>
    fdivs   vr1, vr2, vr1
    mfcr    r0, cr<2, 2>
    rts
    .size   test_dze, .-test_dze

TEST_FUNC(test_ofe)
    lrw     r0, 0x20008000
    lrw     r1, 0x7f7fffff
    stw     r1, (r0, 0)
    flds    vr1, (r0, 0)
    fmovis  vr2, 2
    movi    r0, 0
    mtcr    r0, cr<2, 2>
    fmuls   vr1, vr2, vr1
    mfcr    r0, cr<2, 2>
    rts
    .size   test_ofe, .-test_ofe

TEST_FUNC(test_ufe)
    lrw     r0, 0x20008000
    lrw     r1, 0x00800001
    stw     r1, (r0, 0)
    flds    vr1, (r0, 0)
    fmovis  vr2, 2
    movi    r0, 0
    mtcr    r0, cr<2, 2>
    mfcr    r0, cr<1, 2>
    lrw     r1, 0x08000000
    or      r1, r0, r1
    mtcr    r1, cr<1, 2>
    fdivs   vr1, vr1, vr2
    mtcr    r0, cr<1, 2>
    mfcr    r0, cr<2, 2>
    rts
    .size   test_ufe, .-test_ufe

TEST_FUNC(test_ixe)
    lrw     r0, 0x20008000
    lrw     r1, 0x7f7fffff
    stw     r1, (r0, 0)
    flds    vr1, (r0, 0)
    fmovis  vr2, 1.5
    movi    r0, 0
    mtcr    r0, cr<2, 2>
    fadds   vr1, vr2, vr1
    mfcr    r0, cr<2, 2>
    rts
    .size   test_ixe, .-test_ixe






