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

   .file   "dsp_insn.S"

#undef  TEST_FUNC
#define TEST_FUNC(name) TEST_FUNC_M name
    .macro TEST_FUNC_M name
    .text
    .align  2
    .global \name
    .type   \name, @function
\name:
    .endm

TEST_FUNC(test_add_s32_s)
    add.s32.s   a0, a0, a1
    rts
    .size   test_add_s32_s, .-test_add_s32_s

TEST_FUNC(test_addx_u32)
    addx.u32    a0, a0, a1
    rts
    .size   test_addx_u32, .-test_addx_u32

TEST_FUNC(test_addx_s32)
    addx.s32    a0, a0, a1
    rts
    .size   test_addx_s32, .-test_addx_s32

TEST_FUNC(test_padd_s16_s)
    mov         a2, a0
    padd.s16.s  a0, a2, a1
    rts
    .size   test_padd_s16_s, .-test_padd_s16_s

TEST_FUNC(test_padd_s16)
    mov         a2, a0
    padd.s16  a3, a2, a1
    mov         a0, a3
    rts
    .size   test_padd_s16, .-test_padd_s16

TEST_FUNC(test_paddh_s16)
    paddh.s16    a0, a0, a1
    rts
    .size   test_paddh_s16, .-test_paddh_s16

TEST_FUNC(test_pmul_s16)
    pmul.s16    a0, a1, a0, a1
    rts
    .size   test_pmul_s16, .-test_pmul_s16

TEST_FUNC(test_pmul_s16_f)
    pmul.s16.f  a0, a1, a0, a1
    rts
    .size   test_pmul_s16_f, .-test_pmul_s16_f

TEST_FUNC(test_mul_32_l)
    mul.32.l    a0, a0, a1
    rts
    .size   test_mul_32_l, .-test_mul_32_l

TEST_FUNC(test_mul_32_lf)
    mul.32.lf   a0, a0, a1
    rts
    .size   test_mul_32_lf, .-test_mul_32_lf

TEST_FUNC(test_mulll_s16)
    mulll.s16   a0, a0, a1
    rts
    .size   test_mulll_s16, .-test_mulll_s16

TEST_FUNC(test_mulll_s16_f)
    mulll.s16.f a0, a0, a1
    rts
    .size   test_mulll_s16_f, .-test_mulll_s16_f

TEST_FUNC(test_mulhl_s16)
    mulhl.s16   a0, a0, a1
    rts
    .size   test_mulhl_s16, .-test_mulhl_s16

TEST_FUNC(test_mulhl_s16_f)
    mulhl.s16.f a0, a0, a1
    rts
    .size   test_mulhl_s16_f, .-test_mulhl_s16_f

TEST_FUNC(test_mulhh_s16)
    mulhh.s16   a0, a0, a1
    rts
    .size   test_mulhh_s16, .-test_mulhh_s16

TEST_FUNC(test_mulhh_s16_f)
    mulhh.s16.f a0, a0, a1
    rts
    .size   test_mulhh_s16_f, .-test_mulhh_s16_f

TEST_FUNC(test_mulca_s16)
    mulca.s16   a0, a0, a1
    rts
    .size   test_mulca_s16, .-test_mulca_s16

TEST_FUNC(test_mulca_s16_f)
    mulca.s16.f a0, a0, a1
    rts
    .size   test_mulca_s16_f, .-test_mulca_s16_f

TEST_FUNC(test_mulcax_s16)
    mulcax.s16   a0, a0, a1
    rts
    .size   test_mulcax_s16, .-test_mulcax_s16

TEST_FUNC(test_mulcax_s16_f)
    mulcax.s16.f a0, a0, a1
    rts
    .size   test_mulcax_s16_f, .-test_mulcax_s16_f

TEST_FUNC(test_mulcs_s16)
    mulcs.s16   a0, a0, a1
    rts
    .size   test_mulcs_s16, .-test_mulcs_s16

TEST_FUNC(test_mulcs_s16_f)
    mulcs.s16.f a0, a0, a1
    rts
    .size   test_mulcs_s16_f, .-test_mulcs_s16_f

TEST_FUNC(test_mulcsx_s16)
    mulcsx.s16   a0, a0, a1
    rts
    .size   test_mulcsx_s16, .-test_mulcsx_s16

TEST_FUNC(test_mulcsx_s16_f)
    mulcsx.s16.f a0, a0, a1
    rts
    .size   test_mulcsx_s16_f, .-test_mulcsx_s16_f

TEST_FUNC(test_max_u32)
    max.u32 a0, a0, a1
    rts
    .size   test_max_u32, .-test_max_u32

TEST_FUNC(test_max_s32)
    max.s32 a0, a0, a1
    rts
    .size   test_max_s32, .-test_max_s32

TEST_FUNC(test_min_u32)
    min.u32 a0, a0, a1
    rts
    .size   test_min_u32, .-test_min_u32

TEST_FUNC(test_min_s32)
    min.s32 a0, a0, a1
    rts
    .size   test_min_s32, .-test_min_s32

TEST_FUNC(test_pmax_u16)
    pmax.u16 a0, a0, a1
    rts
    .size   test_pmax_u16, .-test_pmax_u16

TEST_FUNC(test_pmax_s16)
    pmax.s16 a0, a0, a1
    rts
    .size   test_pmax_s16, .-test_pmax_s16

TEST_FUNC(test_pmin_u16)
    pmin.u16 a0, a0, a1
    rts
    .size   test_pmin_u16, .-test_pmin_u16

TEST_FUNC(test_pmin_s16)
    pmin.s16 a0, a0, a1
    rts
    .size   test_pmin_s16, .-test_pmin_s16

TEST_FUNC(test_plsli_16)
    plsli.16 a0, a0, 0
    rts
    .size   test_plsli_16, .-test_plsli_16

TEST_FUNC(test_pasri_16)
    pasri.16 a0, a0, 0
    rts
    .size   test_pasri_16, .-test_pasri_16

TEST_FUNC(test_plsli_32)
    plsli.32 a0, a0, 16
    rts
    .size   test_plsli_32, .-test_plsli_32

TEST_FUNC(test_pasri_32)
    pasri.32 a0, a0, 16
    rts
    .size   test_pasri_32, .-test_pasri_32

TEST_FUNC(test_divsr)
    divsr a0, a1, a0, a1
    rts
    .size   test_divsr, .-test_divsr

TEST_FUNC(test_divur)
    divur a0, a1, a0, a1
    rts
    .size   test_divur, .-test_divur

TEST_FUNC(test_mula_32_l)
    mula.32.l a0, a0, a1, a2
    rts
    .size   test_mula_32_l, .-test_mula_32_l

TEST_FUNC(test_mula_32_lf)
    mula.32.lf a0, a0, a1, a2
    rts
    .size   test_mula_32_lf, .-test_mula_32_lf

TEST_FUNC(test_muls_32_l)
    muls.32.l a0, a0, a1, a2
    rts
    .size   test_muls_32_l, .-test_muls_32_l

TEST_FUNC(test_muls_32_lf)
    muls.32.lf a0, a0, a1, a2
    rts
    .size   test_muls_32_lf, .-test_muls_32_lf

TEST_FUNC(test_mul_u32)
    mul.u32 a0, a1, a0, a1
    rts
    .size   test_mul_u32, .-test_mul_u32

TEST_FUNC(test_mul_s32)
    mul.s32 a0, a1, a0, a1
    rts
    .size   test_mul_s32, .-test_mul_s32

TEST_FUNC(test_mul_s32_f)
    mul.s32.f a0, a1, a0, a1
    rts
    .size   test_mul_s32_f, .-test_mul_s32_f

TEST_FUNC(test_mula_u32)
    mula.u32 a2, a3, a0, a1
    mov       a0, a2
    mov       a1, a3
    rts
    .size   test_mula_u32, .-test_mula_u32

TEST_FUNC(test_mula_s32)
    mula.s32 a2, a3, a0, a1
    mov       a0, a2
    mov       a1, a3
    rts
    .size   test_mula_s32, .-test_mula_s32

TEST_FUNC(test_mula_s32_f)
    mula.s32.f a2, a3, a0, a1
    mov       a0, a2
    mov       a1, a3
    rts
    .size   test_mula_s32_f, .-test_mula_s32_f

TEST_FUNC(test_mulaca_s16_e)
    mulaca.s16.e a2, a3, a0, a1
    mov       a0, a2
    mov       a1, a3
    rts
    .size   test_mulaca_s16_e, .-test_mulaca_s16_e

TEST_FUNC(test_mulacax_s16_e)
    mulacax.s16.e a2, a3, a0, a1
    mov       a0, a2
    mov       a1, a3
    rts
    .size   test_mulacax_s16_e, .-test_mulaca_s16_e

TEST_FUNC(test_mulall_s16)
    mulall.s16 a0, a0, a1, a2
    rts
    .size   test_mulall_s16, .-test_mulaca_s16

TEST_FUNC(test_mulall_s16_f)
    mulall.s16.f a0, a0, a1, a2
    rts
    .size   test_mulall_s16_f, .-test_mulaca_s16_f

TEST_FUNC(test_mulall_s16_e)
    mulall.s16.e a2, a3, a0, a1
    mov       a0, a2
    mov       a1, a3
    rts
    .size   test_mulall_s16_e, .-test_mulaca_s16_e

TEST_FUNC(test_sub_s32_s)
    sub.s32.s   a0, a0, a1
    rts
    .size   test_sub_s32_s, .-test_sub_s32_s

TEST_FUNC(test_psub_s16_s)
    mov         a2, a0
    psub.s16.s  a0, a2, a1
    rts
    .size   test_psub_s16_s, .-test_psub_s16_s

TEST_FUNC(test_psub_s16)
    mov         a2, a0
    psub.s16  a3, a2, a1
    mov         a0, a3
    rts
    .size   test_psub_s16, .-test_psub_s16

TEST_FUNC(test_psubh_s16)
    psubh.s16    a0, a0, a1
    rts
    .size   test_psubh_s16, .-test_psubh_s16

TEST_FUNC(test_paddx_s32)
    paddx.s32 a0, a0, a1, a2
    rts
    .size   test_paddx_s32, .-test_mulaca_s16_e

TEST_FUNC(test_psubx_s32)
    psubx.s32 a0, a0, a1, a2
    rts
    .size   test_psubx_s32, .-test_mulaca_s16_e

TEST_FUNC(test_pabs_s16_s)
    pabs.s16.s a0, a0
    rts
    .size   test_pabs_s16_s, .-test_pabs_s16_s

TEST_FUNC(test_pneg_s16_s)
    pneg.s16.s a0, a0
    rts
    .size   test_pneg_s16_s, .-test_pneg_s16_s

TEST_FUNC(test_sel_32)
    cmpne a0, a2
    sel.32 a0, a0, a1
    rts
    .size   test_sel_32, .-test_sel_32

TEST_FUNC(test_pkg_0_16)
    pkg a0, a0, 0, a1, 16
    rts
    .size   test_pkg_0_16, .-test_pkg_0_16

TEST_FUNC(test_pkg_15_1)
    pkg a0, a0, 15, a1, 1
    rts
    .size   test_pkg_15_1, .-test_pkg_15_1

TEST_FUNC(test_pkg_0_1)
    pkg a0, a0, 0, a1, 1
    rts
    .size   test_pkg_0_1, .-test_pkg_0_1

TEST_FUNC(test_pkg_15_16)
    pkg a0, a0, 15, a1, 16
    rts
    .size   test_pkg_15_16, .-test_pkg_15_16

TEST_FUNC(test_pkgll)
    pkgll a0, a0, a1
    rts
    .size   test_pkgll, .-test_pkgll

TEST_FUNC(test_pkghh)
    pkghh a0, a0, a1
    rts
    .size   test_pkghh, .-test_pkghh

TEST_FUNC(test_dext_16)
    dext a0, a0, a1, 16
    rts
    .size   test_dext_16, .-test_dext_16

TEST_FUNC(test_dext_0)
    dext a0, a0, a1, 0
    rts
    .size   test_dext_0, .-test_dext_0

TEST_FUNC(test_dext_31)
    dext a0, a0, a1, 31
    rts
    .size   test_dext_31, .-test_dext_31

TEST_FUNC(test_pmula_s16)
    pmula.s16 a2, a3, a0, a1
    mov       a0, a2
    mov       a1, a3
    rts
    .size   test_pmula_s16, .-test_pmula_s16

TEST_FUNC(test_pmula_s16_f)
    pmula.s16.f a2, a3, a0, a1
    mov       a0, a2
    mov       a1, a3
    rts
    .size   test_pmula_s16_f, .-test_pmula_s16_f

TEST_FUNC(test_pmulwh_s16)
    pmulwh.s16    a0, a1, a0, a1
    rts
    .size   test_pmulwh_s16, .-test_pmulwh_s16

TEST_FUNC(test_pmulwh_s16_f)
    pmulwh.s16.f    a0, a1, a0, a1
    rts
    .size   test_pmulwh_s16_f, .-test_pmulwh_s16_f

TEST_FUNC(test_pmulwl_s16)
    pmulwl.s16    a0, a1, a0, a1
    rts
    .size   test_pmulwl_s16, .-test_pmulwl_s16

TEST_FUNC(test_pmulwl_s16_f)
    pmulwl.s16.f    a0, a1, a0, a1
    rts
    .size   test_pmulwl_s16_f, .-test_pmulwl_s16_f

TEST_FUNC(test_pmulawh_s16)
    pmulawh.s16 a2, a3, a0, a1
    mov       a0, a2
    mov       a1, a3
    rts
    .size   test_pmulawh_s16, .-test_pmulawh_s16

TEST_FUNC(test_pmulawh_s16_f)
    pmulawh.s16.f a2, a3, a0, a1
    mov       a0, a2
    mov       a1, a3
    rts
    .size   test_pmulawh_s16_f, .-test_pmulawh_s16_f

TEST_FUNC(test_pmulawl_s16)
    pmulawl.s16 a2, a3, a0, a1
    mov       a0, a2
    mov       a1, a3
    rts
    .size   test_pmulawl_s16, .-test_pmulawl_s16

TEST_FUNC(test_pmulawl_s16_f)
    pmulawl.s16.f a2, a3, a0, a1
    mov       a0, a2
    mov       a1, a3
    rts
    .size   test_pmulawl_s16_f, .-test_pmulawl_s16_f

TEST_FUNC(test_plsli_16_0)
    plsli.16 a0, a0, 0
    rts
    .size  test_plsli_16_0, .-test_plsli_16_0

TEST_FUNC(test_plsli_16_1)
    plsli.16 a0, a0, 1
    rts
    .size  test_plsli_16_1, .-test_plsli_16_1

TEST_FUNC(test_plsli_16_9)
    plsli.16 a0, a0, 9
    rts
    .size  test_plsli_16_9, .-test_plsli_16_9

TEST_FUNC(test_plsli_16_15)
    plsli.16 a0, a0, 15
    rts
    .size  test_plsli_16_15, .-test_plsli_16_15

TEST_FUNC(test_pasri_16_0)
    pasri.16 a0, a0, 0
    rts
    .size  test_pasri_16_0, .-test_pasri_16_0

TEST_FUNC(test_pasri_16_1)
    pasri.16 a0, a0, 1
    rts
    .size  test_pasri_16_1, .-test_pasri_16_1

TEST_FUNC(test_pasri_16_9)
    pasri.16 a0, a0, 9
    rts
    .size  test_pasri_16_9, .-test_pasri_16_9

TEST_FUNC(test_pasri_16_15)
    pasri.16 a0, a0, 15
    rts
    .size  test_pasri_16_15, .-test_pasri_16_15

TEST_FUNC(test_plsli_32_0)
    plsli.32 a0, a0, 0
    rts
    .size  test_plsli_32_0, .-test_plsli_32_0

TEST_FUNC(test_plsli_32_1)
    plsli.32 a0, a0, 1
    rts
    .size  test_plsli_32_1, .-test_plsli_32_1

TEST_FUNC(test_plsli_32_20)
    plsli.32 a0, a0, 20
    rts
    .size  test_plsli_32_20, .-test_plsli_32_20

TEST_FUNC(test_plsli_32_31)
    plsli.32 a0, a0, 31
    rts
    .size  test_plsli_32_31, .-test_plsli_32_31

TEST_FUNC(test_pasri_32_0)
    pasri.32 a0, a0, 0
    rts
    .size  test_pasri_32_0, .-test_pasri_32_0

TEST_FUNC(test_pasri_32_1)
    pasri.32 a0, a0, 1
    rts
    .size  test_pasri_32_1, .-test_pasri_32_1

TEST_FUNC(test_pasri_32_20)
    pasri.32 a0, a0, 20
    rts
    .size  test_pasri_32_20, .-test_pasri_32_20

TEST_FUNC(test_pasri_32_31)
    pasri.32 a0, a0, 31
    rts
    .size  test_pasri_32_31, .-test_pasri_32_31

    .text
    .align 2
LD_DATA:
    .long  0x0001ffff
    .long  0x80007fff

TEST_FUNC(test_ldhe_h_1)
    grs a1, LD_DATA
    movi a0, 0
    ldhe.h a0, (a1, 0)
    rts
    .size  test_ldhe_h_1, .-test_ldhe_h_1

TEST_FUNC(test_ldhe_h_2)
    grs a1, LD_DATA
    movi a0, 0
    ldhe.h a0, (a1, 4)
    rts
    .size  test_ldhe_h_2, .-test_ldhe_h_2

TEST_FUNC(test_ldle_h_1)
    grs a1, LD_DATA
    movi a0, 0
    ldle.h a0, (a1, 0)
    rts
    .size  test_ldle_h_1, .-test_ldle_h_1

TEST_FUNC(test_ldle_h_2)
    grs a1, LD_DATA
    movi a0, 0
    ldle.h a0, (a1, 4)
    rts
    .size  test_ldle_h_2, .-test_ldle_h_2

TEST_FUNC(test_ldxe_h_1)
    grs a2, LD_DATA
    movi a0, 0
    movi a1, 0
    ldxe.h a0, (a2, 0)
    rts
    .size  test_ldxe_h_1, .-test_ldxe_h_1

TEST_FUNC(test_ldxe_h_2)
    grs a2, LD_DATA
    movi a0, 0
    movi a1, 0
    ldxe.h a0, (a2, 4)
    rts
    .size  test_ldxe_h_2, .-test_ldxe_h_2

TEST_FUNC(test_ldrhe_h)
    grs a1, LD_DATA
    movi a2, 0
    ldrhe.h a2, (a1, a0)
    mov  a0, a2
    rts
    .size  test_ldrhe_h, .-test_ldrhe_h

TEST_FUNC(test_ldrle_h)
    grs a1, LD_DATA
    movi a2, 0
    ldrle.h a2, (a1, a0)
    mov  a0, a2
    rts
    .size  test_ldrle_h, .-test_ldrle_h


TEST_FUNC(test_ldrxe_h)
    grs a1, LD_DATA
    movi a2, 0
    movi a3, 0
    ldrxe.h a2, (a1, a0)
    mov  a0, a2
    mov  a1, a3
    rts
    .size  test_ldrxe_h, .-test_ldrxe_h

TEST_FUNC(test_mul_s32_h)
    mul.s32.h a0, a0, a1
    rts
    .size   test_mul_s32_h, .-test_mul_s32_h

TEST_FUNC(test_mul_u32_h)
    mul.u32.h a0, a0, a1
    rts
    .size   test_mul_u32_h, .-test_mul_u32_h

TEST_FUNC(test_mul_s32_rh)
    mul.s32.rh a0, a0, a1
    rts
    .size   test_mul_s32_rh, .-test_mul_s32_rh

TEST_FUNC(test_mul_u32_rh)
    mul.u32.rh a0, a0, a1
    rts
    .size   test_mul_u32_rh, .-test_mul_u32_rh

TEST_FUNC(test_mula_s32_h)
    mula.s32.h a2, a0, a1
    mov a0, a2
    rts
    .size   test_mula_s32_h, .-test_mula_s32_h

TEST_FUNC(test_mula_u32_h)
    mula.u32.h a2, a0, a1
    mov a0, a2
    rts
    .size   test_mula_u32_h, .-test_mula_u32_h

TEST_FUNC(test_mula_s32_rh)
    mula.s32.rh a2, a0, a1
    mov a0, a2
    rts
    .size   test_mula_s32_rh, .-test_mula_s32_rh

TEST_FUNC(test_mula_u32_rh)
    mula.u32.rh a2, a0, a1
    mov a0, a2
    rts
    .size   test_mula_u32_rh, .-test_mula_u32_rh

TEST_FUNC(test_muls_s32_h)
    muls.s32.h a2, a0, a1
    mov a0, a2
    rts
    .size   test_muls_s32_h, .-test_muls_s32_h

TEST_FUNC(test_muls_u32_h)
    muls.u32.h a2, a0, a1
    mov a0, a2
    rts
    .size   test_muls_u32_h, .-test_muls_u32_h

TEST_FUNC(test_muls_s32_rh)
    muls.s32.rh a2, a0, a1
    mov a0, a2
    rts
    .size   test_muls_s32_rh, .-test_muls_s32_rh

TEST_FUNC(test_muls_u32_rh)
    muls.u32.rh a2, a0, a1
    mov a0, a2
    rts
    .size   test_muls_u32_rh, .-test_muls_u32_rh

TEST_FUNC(test_divsl)
    divsl a0, a0, a1
    rts
    .size   test_divsl, .-test_divsl

TEST_FUNC(test_divul)
    divul a0, a0, a1
    rts
    .size   test_divul, .-test_divul
