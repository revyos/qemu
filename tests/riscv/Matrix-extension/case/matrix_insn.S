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

    .file   "matrix_insn.S"
#undef TEST_FUNC
#define TEST_FUNC(name) TEST_FUNC_M name
    .macro TEST_FUNC_M name
    .text
    .align  2
    .global \name
    .type   \name, @function
\name:
    .endm

/*------------------------------------------------------------------------------------------*/
/* mmaqa.b      mlen = 128    full physical memory & not full    */

TEST_FUNC(test_mmaqa_4x4)
    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3
    li t6, 0x00000006
    csrw xmcsr,t6
    mldb     m0,  t0,(a0)
    mldb     m1,  t0,(a1)
    mldw     m2,  t0,(a2)


    mmaqa.b   m2, m1, m0

    mstw  m2, t0,(a3)


    ret
        .size   test_mmaqa_4x4, .-test_mmaqa_4x4


TEST_FUNC(test_mmaqa_2x3)
    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3

    mldb     m0,  t0,(a0)
    mldb     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000006
    csrw xmcsr,t6

    addi t0,x0,0x8

    li t3, 0x00080302
    mcfg x0, t3

    mmaqa.b   m2, m1, m0

    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3
    mstw  m2, t0,(a3)


    ret
        .size   test_mmaqa_2x3, .-test_mmaqa_2x3



/* mmaqau.b      mlen = 128    full physical memory & not full    */
TEST_FUNC(test_mmaqau_2x3)
    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3

    mldb     m0,  t0,(a0)
    mldb     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000006
    csrw xmcsr,t6

    addi t0,x0,0x8

    li t3, 0x00080302
    mcfg x0, t3

    mmaqau.b   m2, m1, m0

    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3
    mstw  m2, t0,(a3)

    ret
        .size   test_mmaqau_2x3, .-test_mmaqau_2x3



TEST_FUNC(test_mmaqau_4x4)
    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3

    mldb     m0,  t0,(a0)
    mldb     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000006
    csrw xmcsr,t6


    mmaqau.b   m2, m1, m0

    mstw  m2, t0,(a3)

    ret
        .size   test_mmaqau_4x4, .-test_mmaqau_4x4



/*------------------------------------------------------------------------------------------*/
/* mmaqaus.b      mlen = 128    full physical memory & not full    */

TEST_FUNC(test_mmaqaus_4x4)
    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3

    mldb     m0,  t0,(a0)
    mldb     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000006
    csrw xmcsr,t6


    mmaqaus.b   m2, m1, m0

    mstw  m2, t0,(a3)


    ret
        .size   test_mmaqaus_4x4, .-test_mmaqaus_4x4


TEST_FUNC(test_mmaqaus_2x3)
    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3

    mldb     m0,  t0,(a0)
    mldb     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000006
    csrw xmcsr,t6

    addi t0,x0,0x8

    li t3, 0x00080302
    mcfg x0, t3

    mmaqaus.b   m2, m1, m0

    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3
    mstw  m2, t0,(a3)

    ret
        .size   test_mmaqaus_2x3, .-test_mmaqaus_2x3


/*------------------------------------------------------------------------------------------*/
/* mmaqasu.b      mlen = 128    full physical memory & not full    */

TEST_FUNC(test_mmaqasu_4x4)
    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3

    mldb     m0,  t0,(a0)
    mldb     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000006
    csrw xmcsr,t6


    mmaqasu.b   m2, m1, m0

    mstw  m2, t0,(a3)


    ret
        .size   test_mmaqa_4x4, .-test_mmaqa_4x4



TEST_FUNC(test_mmaqasu_2x3)
    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3

    mldb     m0,  t0,(a0)
    mldb     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000006
    csrw xmcsr,t6

    addi t0,x0,0x8

    li t3, 0x00080302
    mcfg x0, t3

    mmaqasu.b   m2, m1, m0

    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3
    mstw  m2, t0,(a3)

    ret
        .size   test_mmaqasu_2x3, .-test_mmaqasu_2x3


/* mmaqa.h      mlen = 128    full physical memory & not full    */

TEST_FUNC(test_mmaqa_full_h128)
    addi     t0,  x0,  0x10

    li       t3,  0x00100404
    mcfg x0,    t3

    mldh     m0,  t0,  (a0)
    mldh     m1,  t0,  (a1)
    mldd    m2,  t0,  (a2)     # initialize the first pair

    addi     a2,  a2,  64
    mldd    m3,  t0,  (a2)     # initialize the second pair

    li       t6,  0x00000002
    csrw xmcsr, t6

    mmaqa.h   m2, m1, m0
    mstd     m2, t0, (a3)

    addi      a3, a3, 64
    mstd     m3, t0, (a3)

    ret
        .size   test_mmaqa_full_h128, .-test_mmaqa_full_h128


TEST_FUNC(test_mmaqa_nfull_h128)

    addi t0,x0,0x10

    li t3 , 0x00080403
    mcfg x0, t3

    mldh     m0,  t0,(a0)
    mldh     m1,  t0,(a1)

    li t6, 0x00000004
    csrw xmcsr,t6

    li t3 , 0x00100402
    mcfg x0, t3
    mmaqa.h   m2, m1, m0

    mstw  m2, t0,(a2)


    ret
        .size   test_mmaqa_nfull_h128, .-test_mmaqa_nfull_h128



/* mmaqau.h      mlen = 128    full physical memory & not full    */
TEST_FUNC(test_mmaqau_nfull_h128)

    addi t0,x0,0x10

    li t3 , 0x00100403
    mcfg x0, t3

    mldh     m0,  t0,(a0)
    mldh     m1,  t0,(a1)


    li t3 , 0x00100403
    mcfg x0, t3
    li t6, 0x00000002
    csrw xmcsr,t6

    mmaqau.h   m2, m1, m0

    mstd  m2, t0,(a2)


    ret
        .size   test_mmaqau_nfull_h128, .-test_mmaqau_nfull_h128




TEST_FUNC(test_mmaqau_full_h128)
    addi t0,x0,0x10
    li t3,  0x00100404
    mcfg x0, t3

    mldh     m0,  t0,  (a0)
    mldh     m1,  t0,  (a1)
    mldd    m2,  t0,  (a2)     # initialize the first pair

    addi     a2,  a2,  64
    mldd    m3,  t0,  (a2)     # initialize the second pair

    li       t6,  0x00000002
    csrw xmcsr, t6

    mmaqau.h   m2, m1, m0
    mstd     m2, t0, (a3)

    addi      a3, a3, 64
    mstd     m3, t0, (a3)

    ret
        .size   test_mmaqau_full_h128, .-test_mmaqau_full_h128



/*------------------------------------------------------------------------------------------*/
/* mmaqaus.h      mlen = 128    full physical memory & not full    */

TEST_FUNC(test_mmaqaus_full_h128)
    addi t0,x0,0x10

    li t3,  0x00100404
    mcfg x0, t3

    mldh     m0,  t0,(a0)
    mldh     m1,  t0,(a1)
    mldd    m2,  t0,  (a2)     # initialize the first pair

    addi     a2,  a2,  64
    mldd    m3,  t0,  (a2)     # initialize the second pair

    li t6, 0x00000002
    csrw xmcsr,t6

    mmaqaus.h   m2, m1, m0
    mstd     m2, t0, (a3)

    addi      a3, a3, 64
    mstd     m3, t0, (a3)

    ret
        .size   test_mmaqaus_full_h128, .-test_mmaqaus_full_h128


/*------------------------------------------------------------------------------------------*/
/* mmaqasu.h      mlen = 128    full physical memory & not full    */

TEST_FUNC(test_mmaqasu_full_h128)
    addi  t0, x0, 0x10

    li t3,  0x00100404
    mcfg x0, t3

    mldh     m0,  t0, (a0)
    mldh     m1,  t0, (a1)
    mldd    m2,  t0,  (a2)     # initialize the first pair

    addi     a2,  a2,  64
    mldd    m3,  t0,  (a2)     # initialize the second pair

    li t6, 0x00000002
    csrw xmcsr, t6

    mmaqasu.h   m2, m1, m0
    mstd     m2, t0, (a3)
    addi      a3, a3, 64
    mstd     m3, t0, (a3)

    ret
        .size   test_mmaqasu_full_h128, .-test_mmaqasu_full_h128


TEST_FUNC(test_mmaqasu_nfull_h128)

    addi t0,x0,0x10

    li t3 , 0x00100403
    mcfg x0, t3

    mldh     m0,  t0,(a0)
    mldh     m1,  t0,(a1)

    li t6, 0x00000002
    csrw xmcsr,t6

    mmaqasu.h   m2, m1, m0

    mstd  m2, t0,(a2)


    ret
        .size   test_mmaqasu_nfull_h128, .-test_mmaqasu_nfull_h128


        /* pmmaqa.b      mlen = 128    full physical memory & not full    */

TEST_FUNC(test_pmmaqa_4x4)
    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3

    mldb     m0,  t0,(a0)
    mldb     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000001
    csrw xmcsr,t6


    pmmaqa.b   m2, m1, m0

    mstw  m2, t0,(a3)


    ret
        .size   test_pmmaqa_4x4, .-test_pmmaqa_4x4


TEST_FUNC(test_pmmaqa_2x3)
    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3

    mldb     m0,  t0,(a0)
    mldb     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000001
    csrw xmcsr,t6

    addi t0,x0,0x8

    li t3, 0x00080302
    mcfg x0, t3

    pmmaqa.b   m2, m1, m0

    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3
    mstw  m2, t0,(a3)

    ret
        .size   test_pmmaqa_2x3, .-test_pmmaqa_2x3


/* pmmaqau.b      mlen = 128    full physical memory & not full    */
TEST_FUNC(test_pmmaqau_2x3)
    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3

    mldb     m0,  t0,(a0)
    mldb     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000001
    csrw xmcsr,t6

    addi t0,x0,0x8

    li t3, 0x00080302
    mcfg x0, t3

    pmmaqau.b   m2, m1, m0

    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3
    mstw  m2, t0,(a3)


    ret
        .size   test_pmmaqau_2x3, .-test_pmmaqau_2x3

TEST_FUNC(test_pmmaqau_4x4)
    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3

    mldb     m0,  t0,(a0)
    mldb     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000001
    csrw xmcsr,t6


    pmmaqau.b   m2, m1, m0

    mstw  m2, t0,(a3)


    ret
        .size   test_pmmaqau_4x4, .-test_pmmaqau_4x4



/*------------------------------------------------------------------------------------------*/
/* pmmaqaus.b      mlen = 128    full physical memory & not full    */

TEST_FUNC(test_pmmaqaus_4x4)
    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3

    mldb     m0,  t0,(a0)
    mldb     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000001
    csrw xmcsr,t6


    pmmaqaus.b   m2, m1, m0

    mstw  m2, t0,(a3)


    ret
        .size   test_pmmaqaus_4x4, .-test_pmmaqaus_4x4


TEST_FUNC(test_pmmaqaus_2x3)
    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3

    mldb     m0,  t0,(a0)
    mldb     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000001
    csrw xmcsr,t6

    addi t0,x0,0x8

    li t3, 0x00080302
    mcfg x0, t3

    pmmaqaus.b   m2, m1, m0

    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3
    mstw  m2, t0,(a3)

    ret
        .size   test_pmmaqaus_2x3, .-test_pmmaqaus_2x3


/*------------------------------------------------------------------------------------------*/
/* pmmaqasu.b      mlen = 128    full physical memory & not full    */

TEST_FUNC(test_pmmaqasu_4x4)
    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3

    mldb     m0,  t0,(a0)
    mldb     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000001
    csrw xmcsr,t6


    pmmaqasu.b   m2, m1, m0

    mstw  m2, t0,(a3)


    ret
        .size   test_pmmaqasu_4x4, .-test_pmmaqasu_4x4


TEST_FUNC(test_pmmaqasu_2x3)
    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3

    mldb     m0,  t0,(a0)
    mldb     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000001
    csrw xmcsr,t6

    addi t0,x0,0x8

    li t3, 0x00080302
    mcfg x0, t3

    pmmaqasu.b   m2, m1, m0

    addi t0,x0,0x10

    li t3, 0x00100404
    mcfg x0, t3
    mstw  m2, t0,(a3)

    ret
        .size   test_pmmaqasu_2x3, .-test_pmmaqasu_2x3


/*------------------------------------------------------------------------------------------*/
/* mmov.mm */

TEST_FUNC(test_mmov_mm)

    addi	t0,  x0, 0x10	# set stride
    li t6, 0x00000080
    csrw xmcsr,t6
    li t3, 0x00100404
    mcfg x0,t3
    mldd     	m0,  t0, (a0)
    mldd     	m1,  t0, (a1)

    mmov.mm  	m1,  m0
    mstd  	m1,  t0, (a2)

    ret
        .size   test_mmov_mm, .-test_mmov_mm

/*------------------------------------------------------------------------------------------*/
/* mmov.mv.x */

TEST_FUNC(test_mmov_mv_x)

    addi	t0,  x0, 0x10
    add 	s1,  x0, a3
    li t6, 0x00000080
    csrw xmcsr,t6
    li t3, 0x00100404
    mcfg x0,t3
    mldd     	m0,  t0, (a0)
    mldd     	m1,  t0, (a1)

    mmov.mv.x  	m1,  m0[s1]

    mstd  	m1,  t0, (a2)

    ret
        .size   test_mmov_mv_x, .-test_mmov_mv_x

# /*------------------------------------------------------------------------------------------*/
# /* mmov.mv.i*/

TEST_FUNC(test_mmov_mv_i)

    addi	t0,  x0, 0x10
    li t6, 0x00000080
    csrw xmcsr,t6
    li t3, 0x00100404
    mcfg x0,t3
    mldd     	m0,  t0, (a0)
    mldd     	m1,  t0, (a1)

    mmov.mv.i  	m1,  m0[0b001]

    mstd  	m1,  t0, (a2)

    ret
        .size   test_mmov_mv_i, .-test_mmov_mv_i

TEST_FUNC(test_fmmacc_h_4x8)

    addi  t0,x0,0x10

    li t3, 0x00100804
    mcfg x0, t3
    mldh m1, t0, (a0)
    mldh m2, t0, (a1)
    mldh m3, t0, (a2)
    mldh m4, t0, (a3)
    li t6, 0x00000008
    csrw xmcsr,t6
    li t3, 0x00100804
    mcfg x0, t3

    fmmacc.h m4, m2, m1

    msth m4, t0, (a4)

    ret
        .size   test_fmmacc_h_4x8, .-test_fmmacc_h_4x8


TEST_FUNC(test_fmmacc_h_2x4)

    addi  t0,x0,0x10

    li t3, 0x00100402
    mcfg x0, t3
    mldh m1, t0, (a0)
    mldh m2, t0, (a1)
    mldh m3, t0, (a2)
    mldh m4, t0, (a3)

    li t3, 0x00100402
    mcfg x0, t3
    li       t6,  0x00000008
    csrw xmcsr,t6
    fmmacc.h m4, m2, m1

    msth m4, t0, (a4)

    ret
        .size   test_fmmacc_h_2x4, .-test_fmmacc_h_2x4



TEST_FUNC(test_fmmacc_s_2x2)

    addi  t0,x0,0x10
    li t3, 0x00100404
    mcfg x0, t3

    mldw m0, t0, (a0)
    mldw m1, t0, (a1)
    mldw m2, t0, (a2)

    li       t6,  0x00000010
    csrw xmcsr,t6

    addi t0,x0,0x8

    li t3, 0x00020202
    mcfg x0, t3
    fmmacc.s m2, m1, m0

    li t3, 0x00100404
    mcfg x0, t3

    mstw m3, t0, (a3)

    ret
        .size   test_fmmacc_s_2x2, .-test_fmmacc_s_2x2

TEST_FUNC(test_fmmacc_s_4x4)

    addi  t0,x0,0x10
    li t3, 0x00100404
    mcfg x0, t3

    mldw m0, t0, (a0)
    mldw m1, t0, (a1)
    mldw m2, t0, (a2)

    li       t6,  0x00000010
    csrw xmcsr,t6

    fmmacc.s m2, m1, m0

    mstw m2, t0, (a3)

    ret
        .size   test_fmmacc_s_4x4, .-test_fmmacc_s_4x4

TEST_FUNC(test_fmmacc_d_2x1)

    addi  t0,x0,0x10
    li t3, 0x000100202
    mcfg x0, t3
    li t6,  0x00000020
    csrw xmcsr,t6

    mldd    m0, t0, (a0)
    mldd    m1, t0, (a1)
    mldd    m2,  t0,  (a2)  # initialize the first pair

    addi    a2,  a2,  64
    mldd    m3, t0, (a2)    # initialize the second pair

    li t3, 0x000100102
    mcfg x0, t3

    fmmacc.d   m2, m1, m0
    mstd     m2, t0, (a3)

    addi      a3, a3, 64
    mstd     m3, t0, (a3)

    ret
        .size   test_fmmacc_d_2x1, .-test_fmmacc_d_2x1

TEST_FUNC(test_fmmacc_d_4x2)
    addi     t0,  x0,  0x10

    li       t3,  0x00100404
    mcfg x0,    t3
    li       t6,  0x00000020
    csrw xmcsr,t6
    mldh     m0,  t0,  (a0)
    mldh     m1,  t0,  (a1)
    mldd    m2,  t0,  (a2)     # initialize the first pair

    addi     a2,  a2,  64
    mldd    m3,  t0,  (a2)     # initialize the second pair


    li       t3,  0x00100404
    mcfg x0,    t3


    fmmacc.d   m2, m1, m0
    mstd     m2, t0, (a3)

    addi      a3, a3, 64
    mstd     m3, t0, (a3)

    ret
        .size   test_fmmacc_d_4x2, .-test_fmmacc_d_4x2








/*------------------------------------------------------------------------------------------*/
/* mn4clip.s.mm*/

TEST_FUNC(test_mn4clip_s_mm)

    addi	t0,  x0, 0x10

    li   t3,  0x00100404
    mcfg x0, 	t3
    li t6, 0x00000080
    csrw xmcsr,t6
    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)
    mldd     	m2,  t0, (a2)

    mn4clip.s.mm m2, m0, m1

    mstd  	m2,  t0, (a3)

    ret
        .size   test_mn4clip_s_mm, .-test_mn4clip_s_mm


TEST_FUNC(test_mn4clip_s_mm_3x3)

    addi	t0,  x0, 0x10

    li   t3,  0x00100404
    mcfg x0, 	t3
    li t6, 0x00000080
    csrw xmcsr,t6
    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)
    mldd     	m2,  t0, (a2)
    li   t3,  0x000c0303
    mcfg x0, 	t3

    mn4clip.s.mm m2, m0, m1

    mstd  	m2,  t0, (a3)

    ret
        .size   test_mn4clip_s_mm_3x3, .-test_mn4clip_s_mm_3x3


/*------------------------------------------------------------------------------------------*/
/* mn4clip.s.mv.i*/

TEST_FUNC(test_mn4clip_s_mv_i)

    addi	t0,  x0, 0x10

    li   t3,  0x00100404
    mcfg x0, 	t3
    li t6, 0x00000080
    csrw xmcsr,t6
    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)
    mldd     	m2,  t0, (a2)

    mn4clip.s.mv.i m2, m0, m1[0b001]

    mstd  	m2,  t0, (a3)

    ret
        .size   test_mn4clip_s_mv_i, .-test_mn4clip_s_mv_i


TEST_FUNC(test_mn4clip_s_mv_i_3x3)

    addi	t0,  x0, 0x10


    li   t3,  0x00100404
    mcfg x0, 	t3
    li t6, 0x00000080
    csrw xmcsr,t6
    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)
    mldd     	m2,  t0, (a2)
    li   t3,  0x000C0303
    mcfg x0, 	t3
    mn4clip.s.mv.i m2, m0, m1[0b001]

    mstd  	m2,  t0, (a3)

    ret
        .size   test_mn4clip_s_mv_i_3x3, .-test_mn4clip_s_mv_i_3x3


/*------------------------------------------------------------------------------------------*/
/* mn4clip.s.mv.x*/

TEST_FUNC(test_mn4clip_s_mv_x)

    addi	t0,  x0, 0x10

    li   t3,  0x00100404
    mcfg x0, 	t3

    add         s1,  x0, a4
    li t6, 0x00000080
    csrw xmcsr,t6
    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)
    mldd     	m2,  t0, (a2)

    mn4clip.s.mv.x m2, m0, m1[s1]

    mstd  	m2,  t0, (a3)

    ret
        .size   test_mn4clip_s_mv_x, .-test_mn4clip_s_mv_x


TEST_FUNC(test_mn4clip_s_mv_x_3x3)

    addi	t0,  x0, 0x10


    li   t3,  0x00100404
    mcfg x0, 	t3
    add         s1,  x0, a4
    li t6, 0x00000080
    csrw xmcsr,t6
    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)
    mldd     	m2,  t0, (a2)
    li   t3,  0x000C0303
    mcfg x0, 	t3
    mn4clip.s.mv.x m2, m0, m1[s1]

    mstd  	m2,  t0, (a3)

    ret
        .size   test_mn4clip_s_mv_x_3x3, .-test_mn4clip_s_mv_x_3x3


/*------------------------------------------------------------------------------------------*/
/* mn4clip.s.mx*/

TEST_FUNC(test_mn4clip_s_mx)

    addi	t0,  x0, 0x10

    li   t3,  0x00100404
    mcfg x0, 	t3
    li t6, 0x00000080
    csrw xmcsr,t6
    add         s1,  x0, a3

    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)

    mn4clip.s.mx m1, m0, s1

    mstd  	m1,  t0, (a2)

    ret
        .size   test_mn4clip_s_mx, .-test_mn4clip_s_mx


TEST_FUNC(test_mn4clip_s_mx_3x3)

    addi	t0,  x0, 0x10


    li   t3,  0x00100404
    mcfg x0, 	t3
    li t6, 0x00000080
    csrw xmcsr,t6
    add         s1,  x0, a3

    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)
    li   t3,  0x000C0303
    mcfg x0, 	t3
    mn4clip.s.mx m1, m0, s1

    mstd  	m1,  t0, (a2)

    ret
        .size   test_mn4clip_s_mx_3x3, .-test_mn4clip_s_mx_3x3

# # /*------------------------------------------------------------------------------------------*/
# # /* mn4clipu.s.mm*/

TEST_FUNC(test_mn4clipu_s_mm)

    addi	t0,  x0, 0x10

    li   t3,  0x00100404
    mcfg x0, 	t3
    li t6, 0x00000080
    csrw xmcsr,t6
    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)
    mldd     	m2,  t0, (a2)
    mn4clipu.s.mm m2, m0, m1
    mstd  	m2,  t0, (a3)
    ret
        .size   test_mn4clipu_s_mm, .-test_mn4clipu_s_mm


TEST_FUNC(test_mn4clipu_s_mm_3x3)

    addi	t0,  x0, 0x10


    li   t3,  0x00100404
    mcfg x0, 	t3
    li t6, 0x00000080
    csrw xmcsr,t6
    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)
    mldd     	m2,  t0, (a2)
    li   t3,  0x000C0303
    mcfg x0, 	t3
    mn4clipu.s.mm m2, m0, m1

    mstd  	m2,  t0, (a3)

    ret
        .size   test_mn4clipu_s_mm_3x3, .-test_mn4clipu_s_mm_3x3

# # /*------------------------------------------------------------------------------------------*/
# # /* mn4clipu.s.mv.i*/

TEST_FUNC(test_mn4clipu_s_mv_i)

    addi	t0,  x0, 0x10

    li   t3,  0x00100404
    mcfg x0, 	t3
    li t6, 0x00000080
    csrw xmcsr,t6
    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)
    mldd     	m2,  t0, (a2)

    mn4clipu.s.mv.i m2, m0, m1[0b001]

    mstd  	m2,  t0, (a3)

    ret
        .size   test_mn4clipu_s_mv_i, .-test_mn4clipu_s_mv_i


TEST_FUNC(test_mn4clipu_s_mv_i_3x3)

    addi	t0,  x0, 0x10


    li   t3,  0x00100404
    mcfg x0, 	t3
    li t6, 0x00000080
    csrw xmcsr,t6
    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)
    mldd     	m2,  t0, (a2)
    li   t3,  0x000C0303
    mcfg x0, 	t3
    mn4clipu.s.mv.i m2, m0, m1[0b001]

    mstd  	m2,  t0, (a3)

    ret
        .size   test_mn4clipu_s_mv_i_3x3, .-test_mn4clipu_s_mv_i_3x3

/*------------------------------------------------------------------------------------------*/
/* mn4clipu.s.mv.x*/

TEST_FUNC(test_mn4clipu_s_mv_x)

    addi	t0,  x0, 0x10

    li   t3,  0x00100404
    mcfg x0, 	t3

    add         s1,  x0, a4
    li t6, 0x00000080
    csrw xmcsr,t6
    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)
    mldd     	m2,  t0, (a2)

    mn4clipu.s.mv.x m2, m0, m1[s1]

    mstd  	m2,  t0, (a3)

    ret
        .size   test_mn4clipu_s_mv_x, .-test_mn4clipu_s_mv_x


TEST_FUNC(test_mn4clipu_s_mv_x_3x3)

    addi	t0,  x0, 0x10


    li   t3,  0x00100404
    mcfg x0, 	t3
    add         s1,  x0, a4
    li t6, 0x00000080
    csrw xmcsr,t6
    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)
    mldd     	m2,  t0, (a2)
    li   t3,  0x000C0303
    mcfg x0, 	t3
    mn4clipu.s.mv.x m2, m0, m1[s1]

    mstd  	m2,  t0, (a3)

    ret
        .size   test_mn4clipu_s_mv_x_3x3, .-test_mn4clipu_s_mv_x_3x3


/*------------------------------------------------------------------------------------------*/
/* mn4clipu.s.mx*/

TEST_FUNC(test_mn4clipu_s_mx)

    addi	t0,  x0, 0x10

    li   t3,  0x00100404
    mcfg x0, 	t3

    add         s1,  x0, a3
    li t6, 0x00000080
    csrw xmcsr,t6
    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)

    mn4clipu.s.mx m1, m0, s1

    mstd  	m1,  t0, (a2)

    ret
        .size   test_mn4clipu_s_mx, .-test_mn4clipu_s_mx


TEST_FUNC(test_mn4clipu_s_mx_3x3)

    addi	t0,  x0, 0x10


    li   t3,  0x00100404
    mcfg x0, 	t3
    li t6, 0x00000080
    csrw xmcsr,t6
    add         s1,  x0, a3

    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)
    li   t3,  0x000C0303
    mcfg x0, 	t3
    mn4clipu.s.mx m1, m0, s1

    mstd  	m1,  t0, (a2)

    ret
        .size   test_mn4clipu_s_mx_3x3, .-test_mn4clipu_s_mx_3x3



/*------------------------------------------------------------------------------------------*/
/* msubs      mlen = 128        */

TEST_FUNC(test_msubs_mm)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)
    li t6, 0x00000080
    csrw xmcsr,t6

    msub.s.mm   m2, m1, m0

    mstw  m2, t0,(a3)


    ret
        .size   test_msubs_mm, .-test_msubs_mm

TEST_FUNC(test_msubs_mv_x)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)
    li t6, 0x00000080
    csrw xmcsr,t6

    msub.s.mv.x   m2, m1, m0[a4]

    mstw  m2, t0,(a3)


    ret
        .size   test_msubs_mv_x, .-test_msubs_mv_x

TEST_FUNC(test_msubs_mv_i)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)
    li t6, 0x00000080
    csrw xmcsr,t6

    msub.s.mv.i   m2, m1, m0[0x1]

    mstw  m2, t0,(a3)


    ret
        .size   test_msubs_mv_i, .-test_msubs_mv_i




/*------------------------------------------------------------------------------------------*/
/* msubs      mlen = 96        */

TEST_FUNC(test_msubs_mm_nfull)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000080
    csrw xmcsr,t6

    li t3, 0x00100303
	mcfg x0,t3

    msub.s.mm   m2, m1, m0

    mstw  m2, t0,(a3)


    ret
        .size   test_msubs_mm_nfull, .-test_msubs_mm_nfull

TEST_FUNC(test_msubs_mv_x_nfull)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000080
    csrw xmcsr,t6

    li t3, 0x00100303
	mcfg x0,t3

    msub.s.mv.x   m2, m1, m0[a4]

    mstw  m2, t0,(a3)


    ret
        .size   test_msubs_mv_x_nfull, .-test_msubs_mv_x_nfull

TEST_FUNC(test_msubs_mv_i_nfull)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000080
    csrw xmcsr,t6

    li t3, 0x00100303
	mcfg x0,t3

    msub.s.mv.i   m2, m1, m0[0x1]

    mstw  m2, t0,(a3)


    ret
        .size   test_msubs_mv_i_nfull, .-test_msubs_mv_i_nfull

TEST_FUNC(test_msubs_mx)

        addi t0,x0,0x10

        li t3 , 0x00100404
        mcfg x0, t3
        li t6, 0x00000080
        csrw xmcsr,t6


        mldw     m1,  t0,(a1)
        mldw     m2,  t0,(a2)


        msub.s.mx   m2, m1,a0

        mstw  m2, t0,(a3)


        ret
            .size   test_msubs_mx, .-test_msubs_mx

TEST_FUNC(test_msubs_mx_nfull)

        addi t0,x0,0x10

        li t3 , 0x00100404
        mcfg x0, t3
        li t6, 0x00000080
        csrw xmcsr,t6

        mldw     m1,  t0,(a1)
        mldw     m2,  t0,(a2)

        li t3, 0x00100303
        mcfg x0,t3

        msub.s.mx   m2, m1,a0

        mstw  m2, t0,(a3)


        ret
            .size   test_msubs_mx_nfull, .-test_msubs_mx_nfull







/*------------------------------------------------------------------------------------------*/
/* madds      mlen = 128        */

TEST_FUNC(test_madds_mm)

    addi t0,x0,0x10
    li t6, 0x00000080
    csrw xmcsr,t6
    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    madd.s.mm   m2, m1, m0

    mstw  m2, t0,(a3)


    ret
        .size   test_madds_mm, .-test_madds_mm

TEST_FUNC(test_madds_mv_x)

    addi t0,x0,0x10
    li t6, 0x00000080
    csrw xmcsr,t6
    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)


    madd.s.mv.x   m2, m1, m0[a4]

    mstw  m2, t0,(a3)


    ret
        .size   test_madds_mv_x, .-test_madds_mv_x

TEST_FUNC(test_madds_mv_i)

    addi t0,x0,0x10
    li t6, 0x00000080
    csrw xmcsr,t6
    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)


    madd.s.mv.i   m2, m1, m0[0x1]

    mstw  m2, t0,(a3)


    ret
        .size   test_madds_mv_i, .-test_madds_mv_i

TEST_FUNC(test_madds_mx)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000080
    csrw xmcsr,t6

    madd.s.mx   m2, m1, a0

    mstw  m2, t0,(a3)


    ret
                    .size   test_madds_mx, .-test_madds_mx

/*------------------------------------------------------------------------------------------*/
/* madds      mlen = 96        */

TEST_FUNC(test_madds_mm_nfull)

  addi t0,x0,0x10

  li t3 , 0x00100404
  mcfg x0, t3

  mldw     m0,  t0,(a0)
  mldw     m1,  t0,(a1)
  mldw     m2,  t0,(a2)

  li t6, 0x00000080
  csrw xmcsr,t6

  li t3, 0x00100303
  mcfg x0,t3

  madd.s.mm   m2, m1, m0

  mstw  m2, t0,(a3)


  ret
      .size   test_madds_mm_nfull, .-test_madds_mm_nfull

TEST_FUNC(test_madds_mv_x_nfull)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000080
    csrw xmcsr,t6

    li t3, 0x00100303
	mcfg x0,t3

    madd.s.mv.x   m2, m1, m0[a4]

    mstw  m2, t0,(a3)


    ret
        .size   test_madds_mv_x_nfull, .-test_madds_mv_x_nfull

TEST_FUNC(test_madds_mv_i_nfull)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000080
    csrw xmcsr,t6

    li t3, 0x00100303
	mcfg x0,t3

    madd.s.mv.i   m2, m1, m0[0x1]

    mstw  m2, t0,(a3)


    ret
        .size   test_madds_mv_i_nfull, .-test_madds_mv_i_nfull

TEST_FUNC(test_madds_mx_nfull)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a1)
    mldw     m1,  t0,(a2)

    li t6, 0x00000080
    csrw xmcsr,t6

    li t3, 0x00100303
	mcfg x0,t3

    madd.s.mx   m1, m0, a0

    mstw  m1, t0,(a3)


    ret
                    .size   test_madds_mx_nfull, .-test_madds_mx_nfull



/*------------------------------------------------------------------------------------------*/
/* madds      mlen = 256        */

TEST_FUNC(test_madds_mm_I64)

    addi t0,x0,0x20
    li t6, 0x00000040
    csrw xmcsr,t6
    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    madd.s.mm   m2, m1, m0

    mstw  m2, t0,(a3)


    ret
        .size   test_madds_mm_I64, .-test_madds_mm_I64

TEST_FUNC(test_madds_mv_x_I64)

    addi t0,x0,0x20
    li t6, 0x00000040
    csrw xmcsr,t6
    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)


    madd.s.mv.x   m2, m1, m0[a4]

    mstw  m2, t0,(a3)


    ret
        .size   test_madds_mv_x_I64, .-test_madds_mv_x_I64

TEST_FUNC(test_madds_mv_i_I64)

    addi t0,x0,0x20
    li t6, 0x00000040
    csrw xmcsr,t6
    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)


    madd.s.mv.i   m2, m1, m0[0x1]

    mstw  m2, t0,(a3)


    ret
        .size   test_madds_mv_i_I64, .-test_madds_mv_i_I64

TEST_FUNC(test_madds_mx_I64)

    addi t0,x0,0x20

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000040
    csrw xmcsr,t6

    madd.s.mx   m2, m1, a0

    mstw  m2, t0,(a3)


    ret
                    .size   test_madds_mx_I64, .-test_madds_mx_I64

/*------------------------------------------------------------------------------------------*/
/* madds      mlen = 192        */

TEST_FUNC(test_madds_mm_nfull_I64)

    addi t0,x0,0x20

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000040
    csrw xmcsr,t6

    li t3, 0x00100303
	mcfg x0,t3

    madd.s.mm   m2, m1, m0

    mstw  m2, t0,(a3)


    ret
        .size   test_madds_mm_nfull_I64, .-test_madds_mm_nfull_I64

TEST_FUNC(test_madds_mv_x_nfull_I64)

    addi t0,x0,0x20

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000040
    csrw xmcsr,t6

    li t3, 0x00100303
	mcfg x0,t3

    madd.s.mv.x   m2, m1, m0[a4]

    mstw  m2, t0,(a3)


    ret
        .size   test_madds_mv_x_nfull_I64, .-test_madds_mv_x_nfull_I64

TEST_FUNC(test_madds_mv_i_nfull_I64)

    addi t0,x0,0x20

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000040
    csrw xmcsr,t6

    li t3, 0x00100303
	mcfg x0,t3

    madd.s.mv.i   m2, m1, m0[0x1]

    mstw  m2, t0,(a3)


    ret
        .size   test_madds_mv_i_nfull_I64, .-test_madds_mv_i_nfull_I64

TEST_FUNC(test_madds_mx_nfull_I64)

    addi t0,x0,0x20

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a1)
    mldw     m1,  t0,(a2)

    li t6, 0x00000040
    csrw xmcsr,t6

    li t3, 0x00100303
	mcfg x0,t3

    madd.s.mx   m1, m0, a0

    mstw  m1, t0,(a3)


    ret
                    .size   test_madds_mx_nfull_I64, .-test_madds_mx_nfull_I64
/*------------------------------------------------------------------------------------------*/
/* mmuls      mlen = 128        */

TEST_FUNC(test_mmuls_mm)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)
    li t6, 0x00000080
    csrw xmcsr,t6

    mmul.s.mm   m2, m1, m0

    mstw  m2, t0,(a3)


    ret
        .size   test_mmuls_mm, .-test_mmuls_mm

TEST_FUNC(test_mmuls_mv_x)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)
    li t6, 0x00000080
    csrw xmcsr,t6

    mmul.s.mv.x   m2, m1, m0[a4]

    mstw  m2, t0,(a3)


    ret
        .size   test_mmuls_mv_x, .-test_mmuls_mv_x

TEST_FUNC(test_mmuls_mv_i)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)
    li t6, 0x00000080
    csrw xmcsr,t6

    mmul.s.mv.i   m2, m1, m0[0x1]

    mstw  m2, t0,(a3)


    ret
        .size   test_mmuls_mv_i, .-test_mmuls_mv_i

TEST_FUNC(test_mmuls_mx)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000080
    csrw xmcsr,t6

    mmul.s.mx   m2, m1, a0

    mstw  m2, t0,(a3)


    ret
                    .size   test_mmuls_mx, .-test_mmuls_mx

/*------------------------------------------------------------------------------------------*/
/* mmuls      mlen = 96        */

TEST_FUNC(test_mmuls_mm_nfull)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000080
    csrw xmcsr,t6

    li t3, 0x00100303
	mcfg x0,t3

    mmul.s.mm   m2, m1, m0

    mstw  m2, t0,(a3)


    ret
        .size   test_mmuls_mm_nfull, .-test_mmuls_mm_nfull

TEST_FUNC(test_mmuls_mv_x_nfull)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000080
    csrw xmcsr,t6

    li t3, 0x00100303
	mcfg x0,t3

    mmul.s.mv.x   m2, m1, m0[a4]

    mstw  m2, t0,(a3)


    ret
        .size   test_mmuls_mv_x_nfull, .-test_mmuls_mv_x_nfull

TEST_FUNC(test_mmuls_mv_i_nfull)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000080
    csrw xmcsr,t6

    li t3, 0x00100303
	mcfg x0,t3

    mmul.s.mv.i   m2, m1, m0[0x1]

    mstw  m2, t0,(a3)


    ret
        .size   test_mmuls_mv_i_nfull, .-test_mmuls_mv_i_nfull

TEST_FUNC(test_mmuls_mx_nfull)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a1)
    mldw     m1,  t0,(a2)

    li t6, 0x00000080
    csrw xmcsr,t6

    li t3, 0x00100303
	mcfg x0,t3

    mmul.s.mx   m1, m0, a0

    mstw  m1, t0,(a3)


    ret
                    .size   test_mmuls_mx_nfull, .-test_mmuls_mx_nfull


/*------------------------------------------------------------------------------------------*/
/* mmulhs      mlen = 128        */

TEST_FUNC(test_mmulhs_mm)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)
    li t6, 0x00000080
    csrw xmcsr,t6

    mmulh.s.mm   m2, m1, m0

    mstw  m2, t0,(a3)


    ret
        .size   test_mmulhs_mm, .-test_mmulhs_mm

TEST_FUNC(test_mmulhs_mv_x)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)
    li t6, 0x00000080
    csrw xmcsr,t6

    mmulh.s.mv.x   m2, m1, m0[a4]

    mstw  m2, t0,(a3)


    ret
        .size   test_mmulhs_mv_x, .-test_mmulhs_mv_x

TEST_FUNC(test_mmulhs_mv_i)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)
    li t6, 0x00000080
    csrw xmcsr,t6

    mmulh.s.mv.i   m2, m1, m0[0x1]

    mstw  m2, t0,(a3)


    ret
        .size   test_mmulhs_mv_i, .-test_mmulhs_mv_i

TEST_FUNC(test_mmulhs_mx)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000080
    csrw xmcsr,t6

    mmulh.s.mx   m2, m1, a0

    mstw  m2, t0,(a3)


    ret
                    .size   test_mmulhs_mx, .-test_mmulhs_mx

/*------------------------------------------------------------------------------------------*/
/* mmulhs      mlen = 96        */

TEST_FUNC(test_mmulhs_mm_nfull)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000080
    csrw xmcsr,t6

    li t3, 0x00100303
	mcfg x0,t3

    mmulh.s.mm   m2, m1, m0

    mstw  m2, t0,(a3)


    ret
        .size   test_mmulhs_mm_nfull, .-test_mmulhs_mm_nfull

TEST_FUNC(test_mmulhs_mv_x_nfull)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000080
    csrw xmcsr,t6

    li t3, 0x00100303
	mcfg x0,t3

    mmulh.s.mv.x   m2, m1, m0[a4]

    mstw  m2, t0,(a3)


    ret
        .size   test_mmulhs_mv_x_nfull, .-test_mmulhs_mv_x_nfull

TEST_FUNC(test_mmulhs_mv_i_nfull)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldw     m2,  t0,(a2)

    li t6, 0x00000080
    csrw xmcsr,t6

    li t3, 0x00100303
	mcfg x0,t3

    mmulh.s.mv.i   m2, m1, m0[0x1]

    mstw  m2, t0,(a3)


    ret
        .size   test_mmulhs_mv_i_nfull, .-test_mmulhs_mv_i_nfull

TEST_FUNC(test_mmulhs_mx_nfull)

    addi t0,x0,0x10

    li t3 , 0x00100404
    mcfg x0, t3

    mldw     m0,  t0,(a1)
    mldw     m1,  t0,(a2)

    li t6, 0x00000080
    csrw xmcsr,t6

    li t3, 0x00100303
	mcfg x0,t3

    mmulh.s.mx   m1, m0, a0

    mstw  m1, t0,(a3)


    ret
                    .size   test_mmulhs_mx_nfull, .-test_mmulhs_mx_nfull


/*------------------------------------------------------------------------------------------*/
/*msar.s     */


TEST_FUNC(test_msra_s_mm)

    addi t0,x0, 0x10

    li t3 , 0x00100404
    mcfg x0, t3

    li t6, 0x00000080
    csrw xmcsr,t6

    mldw     m0,  t0,(a0)
    mldw     m1,  t0,(a1)
    mldd    m2,  t0, (a2)


    msra.s.mm   m2, m0, m1

    mstw  m2, t0,(a3)


    ret
        .size   test_msra_s_mm, .-test_msra_s_mm

TEST_FUNC(test_msra_s_mm_3x3)

    addi	t0,  x0, 0x10

    li   t3,  0x00100404
    mcfg x0, 	t3

    li t6, 0x00000080
    csrw xmcsr,t6
    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)
    mldd     	m2,  t0, (a2)
    li   t3,  0x00100303
    mcfg x0, 	t3
    msra.s.mm m2, m0, m1

    mstd  	m2,  t0, (a3)

    ret
        .size   test_msra_s_mm_3x3, .-test_msra_s_mm_3x3

/*------------------------------------------------------------------------------------------*/
/* msra.s.mv.i*/

TEST_FUNC(test_msra_s_mv_i)

    addi	t0,  x0, 0x10

    li   t3,  0x00100404
    mcfg x0, 	t3
    li t6, 0x00000080
    csrw xmcsr,t6
    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)
    mldd     	m2,  t0, (a2)

    msra.s.mv.i m2, m0, m1[0b001]

    mstd  	m2,  t0, (a3)

    ret
        .size   test_msra_s_mv_i, .-test_msra_s_mv_i


TEST_FUNC(test_msra_s_mv_i_3x3)

    addi	t0,  x0, 0x10


    li   t3,  0x00100404
    mcfg x0, 	t3
    li t6, 0x00000080
    csrw xmcsr,t6
    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)
    mldd     	m2,  t0, (a2)
    li   t3,  0x00100303
    mcfg x0, 	t3
    msra.s.mv.i m2, m0, m1[0b001]

    mstd  	m2,  t0, (a3)

    ret
        .size   test_msra_s_mv_i_3x3, .-test_msra_s_mv_i_3x3


/*------------------------------------------------------------------------------------------*/
/* msra.s.mv.x*/

TEST_FUNC(test_msra_s_mv_x)

    addi	t0,  x0, 0x10

    li   t3,  0x00100404
    mcfg x0, 	t3

    add         s1,  x0, a4
    li t6, 0x00000080
    csrw xmcsr,t6
    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)
    mldd     	m2,  t0, (a2)

    msra.s.mv.x m2, m0, m1[s1]

    mstd  	m2,  t0, (a3)

    ret
        .size   test_msra_s_mv_x, .-test_msra_s_mv_x


TEST_FUNC(test_msra_s_mv_x_3x3)

    addi	t0,  x0, 0x10

    li   t3,  0x00100404
    mcfg x0, 	t3
    add         s1,  x0, a4
    li t6, 0x00000080
    csrw xmcsr,t6
    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)
    mldd     	m2,  t0, (a2)

    li   t3,  0x00100303
    mcfg x0, 	t3

    msra.s.mv.x m2, m0, m1[s1]

    mstd  	m2,  t0, (a3)

    ret
        .size   test_msra_s_mv_x_3x3, .-test_msra_s_mv_x_3x3


TEST_FUNC(test_msra_s_mx)

    addi	t0,  x0, 0x10

    li   t3,  0x00100404
    mcfg x0, 	t3
    li t6, 0x00000080
    csrw xmcsr,t6
    add         s1,  x0, a3

    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)

    msra.s.mx m1, m0, s1

    mstd  	m1,  t0, (a2)

    ret
        .size   test_msra_s_mx, .-test_msra_s_mx


TEST_FUNC(test_msra_s_mx_3x3)

    addi	t0,  x0, 0x10


    li   t3,  0x00100404
    mcfg x0, 	t3
    li t6, 0x00000080
    csrw xmcsr,t6
    add         s1,  x0, a3

    mldd       m0,  t0, (a0)
    mldd       m1,  t0, (a1)

    li   t3,  0x00100303
    mcfg x0, 	t3

    msra.s.mx m1, m0, s1

    mstd  	m1,  t0, (a2)

    ret
        .size   test_msra_s_mx_3x3, .-test_msra_s_mx_3x3




/*------------------------------------------------------------------------------------------*/
/*mld mst   msld  msst    */



TEST_FUNC(test_mldb)
    addi t0, x0, 0x10
    li t3 , 0x00100403
    mcfg x0, t3
    mldb m1, t0, (a0)
    mstb m1, t0, (a1)

            ret
        .size   test_mldb, .-test_mldb

TEST_FUNC(test_mldh)
    addi t0, x0, 0x10
    li       t3,  0x00100403
    mcfg x0,    t3
    mldh m1, t0, (a0)
    msth m1, t0, (a1)

            ret
        .size   test_mldh, .-test_mldh

TEST_FUNC(test_mldw)
    addi t0, x0, 0x10
    li       t3,  0x00100403
    mcfg x0,    t3
    mldw m1, t0, (a0)
    mstw m1, t0, (a1)

            ret
        .size   test_mldw, .-test_mldw

TEST_FUNC(test_mldd)
    addi t0, x0, 0x10
    li   t3, 0x00100204
    mcfg x0, t3
    mldd m1, t0, (a0)
    mstd m1, t0, (a1)
    li   t3, 0x00100203
    mcfg x0, t3
    mldd m1, t0, (a0)
    mstd m1, t0, (a1)
    ret
.size   test_mldd, .-test_mldd

TEST_FUNC(test_msldb)
    addi t0, x0, 0x10
    li       t3,  0x00100403
    mcfg x0,    t3
    msldb m1, t0, (a0)
    msstb m1, t0, (a1)

            ret
        .size   test_msldb, .-test_msldb

TEST_FUNC(test_msldh)
    addi t0, x0, 0x10
    li       t3,  0x00100403
    mcfg x0,    t3
    msldh m1, t0, (a0)
    mssth m1, t0, (a1)

            ret
        .size   test_msldh, .-test_msldh

TEST_FUNC(test_msldw)
    addi t0, x0, 0x10
    li       t3,  0x00100403
    mcfg x0,    t3
    msldw m1, t0, (a0)
    msstw m1, t0, (a1)

            ret
        .size   test_msldw, .-test_msldw



TEST_FUNC(test_msldd)
    addi t0, x0, 0x10
    li       t3,  0x00100203
    mcfg x0,    t3
    msldd m1, t0, (a0)
    msstd m1, t0, (a1)

            ret
        .size   test_msldd, .-test_msldd



/*------------------------------------------------------------------------------------------*/
/* mlmd   msmt    */
/*
TEST_FUNC(test_mldm1b)
    addi t0, x0, 0x10
    li       t3,  0x00100404
    mcfg x0,    t3
    mldm1b m1, (a0)
    mstm1b m1, (a1)

            ret
        .size   test_mldm1b, .-test_mldm1b

TEST_FUNC(test_mldm1h)
    addi t0, x0, 0x10
    li       t3,  0x00100404
    mcfg x0,    t3
    mldm1h m1,  (a0)
    mstm1h m1,  (a1)

            ret
        .size   test_mldm1h, .-test_mldm1h

TEST_FUNC(test_mldm1w)
    addi t0, x0, 0x10
    li       t3,  0x00100404
    mcfg x0,    t3
    mldm1w m1, (a0)
    mstm1w m1, (a1)

            ret
        .size   test_mldm1w, .-test_mldm1w



TEST_FUNC(test_mldm1d)
    addi t0, x0, 0x10
    li       t3,  0x00100404
    mcfg x0,    t3
    mldm1d m1, (a0)
    mstm1d m1, (a1)

            ret
        .size   test_mldm1d, .-test_mldm1d




TEST_FUNC(test_mldm2b)
    addi t0, x0, 0x10
    li       t3,  0x00100404
    mcfg x0,    t3
    mldm2b m1, (a0)
    mstm2b m1, (a1)

            ret
        .size   test_mldm2b, .-test_mldm2b

TEST_FUNC(test_mldm2h)
    addi t0, x0, 0x10
    li       t3,  0x00100404
    mcfg x0,    t3
    mldm2h m1,  (a0)
    mstm2h m1,  (a1)

            ret
        .size   test_mldm2h, .-test_mldm2h

TEST_FUNC(test_mldm2w)
    addi t0, x0, 0x10
    li       t3,  0x00100404
    mcfg x0,    t3
    mldm2w m1, (a0)
    mstm2w m1, (a1)

            ret
        .size   test_mldm2w, .-test_mldm2w



TEST_FUNC(test_mldm2d)
    addi t0, x0, 0x10
    li       t3,  0x00100404
    mcfg x0,    t3
    mldm2d m1, (a0)
    mstm2d m1, (a1)

            ret
        .size   test_mldm2d, .-test_mldm2d


TEST_FUNC(test_mldm4b)
    addi t0, x0, 0x10
    li       t3,  0x00100403
    mcfg x0,    t3
    mldm4b m1, (a0)
    mstm4b m1, (a1)

            ret
        .size   test_mldm4b, .-test_mldm4b

TEST_FUNC(test_mldm4h)
    addi t0, x0, 0x10
    li       t3,  0x00100304
    mcfg x0,    t3
    mldm4h m1, (a0)
    mstm4h m1, (a1)

            ret
        .size   test_mldm4h, .-test_mldm4h

TEST_FUNC(test_mldm4w)
    addi t0, x0, 0x10
    li       t3,  0x00100403
    mcfg x0,    t3
    mldm4w m1, (a0)
    mstm4w m1, (a1)

            ret
        .size   test_mldm4w, .-test_mldm4w



TEST_FUNC(test_mldm4d)
    addi t0, x0, 0x10
    li       t3,  0x00100403
    mcfg x0,    t3
    mldm4d m1, (a0)
    mstm4d m1, (a1)

            ret
        .size   test_mldm4d, .-test_mldm4d

TEST_FUNC(test_mldm8b)
    addi t0, x0, 0x10
    li       t3,  0x00100403
    mcfg x0,    t3
    mldm8b m1, (a0)
    mstm8b m1, (a1)

            ret
        .size   test_mldm8b, .-test_mldm8b

TEST_FUNC(test_mldm8h)
    addi t0, x0, 0x10
    li       t3,  0x00100404
    mcfg x0,    t3
    mldm8h m1, (a0)
    mstm8h m1, (a1)

            ret
        .size   test_mldm8h, .-test_mldm8h

TEST_FUNC(test_mldm8w)
    addi t0, x0, 0x10
    li       t3,  0x00100403
    mcfg x0,    t3
    mldm8w m1, (a0)
    mstm8w m1, (a1)

            ret
        .size   test_mldm8w, .-test_mldm8w



TEST_FUNC(test_mldm8d)
    addi t0, x0, 0x10
    li       t3,  0x00100403
    mcfg x0,    t3
    mldm8d m1, (a0)
    mstm8d m1, (a1)

            ret
        .size   test_mldm8d, .-test_mldm8d

*/
