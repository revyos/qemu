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

   .file   "dspv2_insn.S"
#undef TEST_FUNC
#define TEST_FUNC(name) TEST_FUNC_M name
    .macro TEST_FUNC_M name
    .text
    .align  2
    .global \name
    .type   \name, @function
\name:
    .endm

TEST_FUNC(test_psub_8)
    psub.8    a0, a0, a1
    rts
    .size   test_psub_8, .-test_psub_8

TEST_FUNC(test_psub_16)
    psub.16    a0, a0, a1
    rts
    .size   test_psub_16, .-test_psub_16

TEST_FUNC(test_padd_8)
    padd.8    a0, a0, a1
    rts
    .size   test_padd_8, .-test_padd_8

TEST_FUNC(test_padd_16)
    padd.16    a0, a0, a1
    rts
    .size   test_padd_16, .-test_padd_16

TEST_FUNC(test_pasx_16)
    pasx.16    a0, a0, a1
    rts
    .size   test_pasx_16, .-test_pasx_16

TEST_FUNC(test_psax_16)
    psax.16    a0, a0, a1
    rts
    .size   test_psax_16, .-test_psax_16

TEST_FUNC(test_padd_u8_s)
    padd.u8.s    a0, a0, a1
    rts
    .size   test_padd_u8_s, .-test_padd_u8_s

TEST_FUNC(test_padd_s8_s)
    padd.s8.s    a0, a0, a1
    rts
    .size   test_padd_s8_s, .-test_padd_s8_s

TEST_FUNC(test_padd_u16_s)
    padd.u16.s    a0, a0, a1
    rts
    .size   test_padd_u16_s, .-test_padd_u16_s

TEST_FUNC(test_padd_s16_s)
    padd.s16.s    a0, a0, a1
    rts
    .size   test_padd_s16_s, .-test_padd_s16_s

TEST_FUNC(test_add_u32_s)
    add.u32.s    a0, a0, a1
    rts
    .size   test_add_u32_s, .-test_add_u32_s

TEST_FUNC(test_add_s32_s)
    add.s32.s    a0, a0, a1
    rts
    .size   test_add_s32_s, .-test_add_s32_s

TEST_FUNC(test_psub_u8_s)
    psub.u8.s    a0, a0, a1
    rts
    .size   test_psub_u8_s, .-test_psub_u8_s

TEST_FUNC(test_psub_s8_s)
    psub.s8.s    a0, a0, a1
    rts
    .size   test_psub_s8_s, .-test_psub_s8_s

TEST_FUNC(test_psub_u16_s)
    psub.u16.s    a0, a0, a1
    rts
    .size   test_psub_u16_s, .-test_psub_u16_s

TEST_FUNC(test_psub_s16_s)
    psub.s16.s    a0, a0, a1
    rts
    .size   test_psub_s16_s, .-test_psub_s16_s

TEST_FUNC(test_sub_u32_s)
    sub.u32.s    a0, a0, a1
    rts
    .size   test_sub_u32_s, .-test_sub_u32_s

TEST_FUNC(test_sub_s32_s)
    sub.s32.s    a0, a0, a1
    rts
    .size   test_sub_s32_s, .-test_sub_s32_s

TEST_FUNC(test_addh_u32)
    addh.u32    a0, a0, a1
    rts
    .size   test_addh_u32, .-test_addh_u32

TEST_FUNC(test_addh_s32)
    addh.s32    a0, a0, a1
    rts
    .size   test_addh_s32, .-test_addh_s32

TEST_FUNC(test_paddh_u8)
    paddh.u8    a0, a0, a1
    rts
    .size   test_paddh_u8, .-test_paddh_u8

TEST_FUNC(test_paddh_s8)
    paddh.s8    a0, a0, a1
    rts
    .size   test_paddh_s8, .-test_paddh_s8

TEST_FUNC(test_paddh_u16)
    paddh.u16    a0, a0, a1
    rts
    .size   test_paddh_u16, .-test_paddh_u16

TEST_FUNC(test_paddh_s16)
    paddh.s16    a0, a0, a1
    rts
    .size   test_paddh_s16, .-test_paddh_s16

TEST_FUNC(test_subh_u32)
    subh.u32    a0, a0, a1
    rts
    .size   test_subh_u32, .-test_subh_u32

TEST_FUNC(test_subh_s32)
    subh.s32    a0, a0, a1
    rts
    .size   test_subh_s32, .-test_subh_s32

TEST_FUNC(test_psubh_u8)
    psubh.u8    a0, a0, a1
    rts
    .size   test_psubh_u8, .-test_psubh_u8

TEST_FUNC(test_psubh_s8)
    psubh.s8    a0, a0, a1
    rts
    .size   test_psubh_s8, .-test_psubh_s8

TEST_FUNC(test_psubh_u16)
    psubh.u16    a0, a0, a1
    rts
    .size   test_psubh_u16, .-test_psubh_u16

TEST_FUNC(test_psubh_s16)
    psubh.s16    a0, a0, a1
    rts
    .size   test_psubh_s16, .-test_psubh_s16

TEST_FUNC(test_pasx_u16_s)
    pasx.u16.s    a0, a0, a1
    rts
    .size   test_pasx_u16_s, .-test_pasx_u16_s

TEST_FUNC(test_pasx_s16_s)
    pasx.s16.s    a0, a0, a1
    rts
    .size   test_pasx_s16_s, .-test_pasx_s16_s

TEST_FUNC(test_psax_u16_s)
    psax.u16.s    a0, a0, a1
    rts
    .size   test_psax_u16_s, .-test_psax_u16_s

TEST_FUNC(test_psax_s16_s)
    psax.s16.s    a0, a0, a1
    rts
    .size   test_psax_s16_s, .-test_psax_s16_s

TEST_FUNC(test_pasxh_u16)
    pasxh.u16    a0, a0, a1
    rts
    .size   test_pasxh_u16, .-test_pasxh_u16

TEST_FUNC(test_pasxh_s16)
    pasxh.s16    a0, a0, a1
    rts
    .size   test_pasxh_s16, .-test_pasxh_s16

TEST_FUNC(test_psaxh_u16)
    psaxh.u16    a0, a0, a1
    rts
    .size   test_psaxh_u16, .-test_psaxh_u16

TEST_FUNC(test_psaxh_s16)
    psaxh.s16    a0, a0, a1
    rts
    .size   test_psaxh_s16, .-test_psaxh_s16

TEST_FUNC(test_add_64)
    add.64    a0, a0, a2
    rts
    .size   test_add_64, .-test_add_64

TEST_FUNC(test_add_u64_s)
    add.u64.s    a0, a0, a2
    rts
    .size   test_add_u64_s, .-test_add_u64_s

TEST_FUNC(test_add_s64_s)
    mov r31, a0
    mov a0, a1
    add.s64.s    a0, r31, a2
    rts
    .size   test_add_s64_s, .-test_add_s64_s

TEST_FUNC(test_sub_64)
    sub.64    a0, a0, a2
    rts
    .size   test_sub_64, .-test_sub_64

TEST_FUNC(test_sub_u64_s)
    sub.u64.s    a0, a0, a2
    rts
    .size   test_sub_u64_s, .-test_sub_u64_s

TEST_FUNC(test_sub_s64_s)
    sub.s64.s    a0, a0, a2
    rts
    .size   test_sub_s64_s, .-test_sub_s64_s

TEST_FUNC(test_asri_s32_r_32)
    asri.s32.r    a0, a0, 32
    rts
    .size   test_asri_s32_r_32, .-test_asri_s32_r_32

TEST_FUNC(test_asri_s32_r_1)
    asri.s32.r    a0, a0, 1
    rts
    .size   test_asri_s32_1, .-test_asri_s32_r_1

TEST_FUNC(test_asri_s32_r_2)
    asri.s32.r    a0, a0, 2
    rts
    .size   test_asri_s32_2, .-test_asri_s32_r_2

TEST_FUNC(test_asri_s32_r_31)
    asri.s32.r    a0, a0, 31
    rts
    .size   test_asri_s32_31, .-test_asri_s32_r_31

TEST_FUNC(test_asr_s32_r)
    asr.s32.r    a0, a0, a1
    rts
    .size   test_asr_s32_r, .-test_asr_s32_r

TEST_FUNC(test_lsri_u32_r_32)
    lsri.u32.r    a0, a0, 32
    rts
    .size   test_lsri_u32_r_32, .-test_lsri_u32_r_32

TEST_FUNC(test_lsri_u32_r_1)
    lsri.u32.r    a0, a0, 1
    rts
    .size   test_lsri_u32_r_1, .-test_lsri_u32_r_1

TEST_FUNC(test_lsri_u32_r_2)
    lsri.u32.r    a0, a0, 2
    rts
    .size   test_lsri_u32_r_2, .-test_lsri_u32_r_2

TEST_FUNC(test_lsri_u32_r_31)
    lsri.u32.r    a0, a0, 31
    rts
    .size   test_lsri_u32_r_31, .-test_lsri_u32_r_31

TEST_FUNC(test_lsr_u32_r)
    lsr.u32.r    a0, a0, a1
    rts
    .size   test_lsr_u32_r, .-test_lsr_u32_r

TEST_FUNC(test_lsli_u32_s_32)
    lsli.u32.s    a0, a0, 32
    rts
    .size   test_lsli_u32_s_32, .-test_lsli_u32_s_32

TEST_FUNC(test_lsli_u32_s_2)
    lsli.u32.s    a0, a0, 2
    rts
    .size   test_lsli_u32_s_2, .-test_lsli_u32_s_2

TEST_FUNC(test_lsli_u32_s_4)
    lsli.u32.s    a0, a0, 4
    rts
    .size   test_lsli_u32_s_4, .-test_lsli_u32_s_4

TEST_FUNC(test_lsli_u32_s_31)
    lsli.u32.s    a0, a0, 31
    rts
    .size   test_lsli_u32_s_31, .-test_lsli_u32_s_31

TEST_FUNC(test_lsli_s32_s_32)
    lsli.s32.s    a0, a0, 32
    rts
    .size   test_lsli_s32_s_32, .-test_lsli_s32_s_32

TEST_FUNC(test_lsli_s32_s_2)
    lsli.s32.s    a0, a0, 2
    rts
    .size   test_lsli_s32_s_2, .-test_lsli_s32_s_2

TEST_FUNC(test_lsli_s32_s_4)
    lsli.s32.s    a0, a0, 4
    rts
    .size   test_lsli_s32_s_4, .-test_lsli_s32_s_4

TEST_FUNC(test_lsli_s32_s_31)
    lsli.s32.s    a0, a0, 31
    rts
    .size   test_lsli_s32_s_31, .-test_lsli_s32_s_31

TEST_FUNC(test_lsl_u32_s)
    lsl.u32.s    a0, a0, a1
    rts
    .size   test_lsl_u32_s, .-test_lsl_u32_s

TEST_FUNC(test_lsl_s32_s)
    lsl.s32.s    a0, a0, a1
    rts
    .size   test_lsl_s32_s, .-test_lsl_s32_s

TEST_FUNC(test_pasri_s16_1)
    pasri.s16    a0, a0, 1
    rts
    .size   test_pasri_s16_1, .-test_pasri_s16_1

TEST_FUNC(test_pasri_s16_2)
    pasri.s16    a0, a0, 2
    rts
    .size   test_pasri_s16_2, .-test_pasri_s16_2

TEST_FUNC(test_pasri_s16_15)
    pasri.s16    a0, a0, 15
    rts
    .size   test_pasri_s16_15, .-test_pasri_s16_15

TEST_FUNC(test_pasri_s16_16)
    pasri.s16    a0, a0, 16
    rts
    .size   test_pasri_s16_16, .-test_pasri_s16_16

TEST_FUNC(test_pasr_s16)
    pasr.s16    a0, a0, a1
    rts
    .size   test_pasr_s16, .-test_pasr_s16

TEST_FUNC(test_pasri_s16_r_1)
    pasri.s16.r    a0, a0, 1
    rts
    .size   test_pasri_s16_r_1, .-test_pasri_s16_r_1

TEST_FUNC(test_pasri_s16_r_2)
    pasri.s16.r    a0, a0, 2
    rts
    .size   test_pasri_s16_r_2, .-test_pasri_s16_r_2

TEST_FUNC(test_pasri_s16_r_15)
    pasri.s16.r    a0, a0, 15
    rts
    .size   test_pasri_s16_r_15, .-test_pasri_s16_r_15

TEST_FUNC(test_pasr_s16_r)
    pasr.s16.r    a0, a0, a1
    rts
    .size   test_pasr_s16_r, .-test_pasr_s16_r

TEST_FUNC(test_plsri_u16_1)
    plsri.u16    a0, a0, 0x1
    rts
    .size   test_plsri_u16_1, .-test_plsri_u16_1

TEST_FUNC(test_plsri_u16_2)
    plsri.u16    a0, a0, 0x2
    rts
    .size   test_plsri_u16_2, .-test_plsri_u16_2

TEST_FUNC(test_plsri_u16_3)
    plsri.u16    a0, a0, 0x3
    rts
    .size   test_plsri_u16_3, .-test_plsri_u16_3

TEST_FUNC(test_plsri_u16_f)
    plsri.u16    a0, a0, 0xf
    rts
    .size   test_plsri_u16_f, .-test_plsri_u16_f

TEST_FUNC(test_plsri_u16_10)
    plsri.u16    a0, a0, 0x10
    rts
    .size   test_plsri_u16_10, .-test_plsri_u16_10

TEST_FUNC(test_plsr_u16)
    plsr.u16    a0, a0, a1
    rts
    .size   test_plsr_u16, .-test_plsr_u16

TEST_FUNC(test_plsri_u16_r_1)
    plsri.u16.r    a0, a0, 0x1
    rts
    .size   test_plsri_u16_r_1, .-test_plsri_u16_r_1

TEST_FUNC(test_plsri_u16_r_2)
    plsri.u16.r    a0, a0, 0x2
    rts
    .size   test_plsri_u16_r_2, .-test_plsri_u16_r_2

TEST_FUNC(test_plsri_u16_r_3)
    plsri.u16.r    a0, a0, 0x3
    rts
    .size   test_plsri_u16_r_3, .-test_plsri_u16_r_3

TEST_FUNC(test_plsri_u16_r_f)
    plsri.u16.r    a0, a0, 0xf
    rts
    .size   test_plsri_u16_r_f, .-test_plsri_u16_r_f

TEST_FUNC(test_plsri_u16_r_10)
    plsri.u16.r    a0, a0, 0x10
    rts
    .size   test_plsri_u16_r_10, .-test_plsri_u16_r_10

TEST_FUNC(test_plsr_u16_r)
    plsr.u16.r    a0, a0, a1
    rts
    .size   test_plsr_u16_r, .-test_plsr_u16_r

TEST_FUNC(test_plsli_u16_1)
    plsli.16    a0, a0, 1
    rts
    .size   test_plsli_u16_1, .-test_plsli_u16_1

TEST_FUNC(test_plsli_u16_9)
    plsli.16    a0, a0, 9
    rts
    .size   test_plsli_u16_9, .-test_plsli_u16_9

TEST_FUNC(test_plsli_u16_16)
    plsli.16    a0, a0, 16
    rts
    .size   test_plsli_u16_16, .-test_plsli_u16_16

TEST_FUNC(test_plsl_u16)
    plsl.16    a0, a0, a1
    rts
    .size   test_plsl_u16, .-test_plsl_u16

TEST_FUNC(test_plsli_u16_s_1)
    plsli.u16.s    a0, a0, 1
    rts
    .size   test_plsli_u16_s_1, .-test_plsli_u16_s_1

TEST_FUNC(test_plsli_u16_s_2)
    plsli.u16.s    a0, a0, 2
    rts
    .size   test_plsli_u16_s_2, .-test_plsli_u16_s_2

TEST_FUNC(test_plsli_u16_s_9)
    plsli.u16.s    a0, a0, 9
    rts
    .size   test_plsli_u16_s_9, .-test_plsli_u16_s_9

TEST_FUNC(test_plsli_u16_s_16)
    plsli.u16.s    a0, a0, 16
    rts
    .size   test_plsli_u16_s_16, .-test_plsli_u16_s_16

TEST_FUNC(test_plsl_u16_s)
    plsl.u16.s    a0, a0, a1
    rts
    .size   test_plsl_u16_s, .-test_plsl_u16_s

TEST_FUNC(test_plsli_s16_s_1)
    plsli.s16.s    a0, a0, 1
    rts
    .size   test_plsli_s16_s_1, .-test_plsli_s16_s_1

TEST_FUNC(test_plsli_s16_s_2)
    plsli.s16.s    a0, a0, 2
    rts
    .size   test_plsli_s16_s_2, .-test_plsli_s16_s_2

TEST_FUNC(test_plsli_s16_s_9)
    plsli.s16.s    a0, a0, 9
    rts
    .size   test_plsli_s16_s_9, .-test_plsli_s16_s_9

TEST_FUNC(test_plsli_s16_s_16)
    plsli.s16.s    a0, a0, 16
    rts
    .size   test_plsli_s16_s_16, .-test_plsli_s16_s_16

TEST_FUNC(test_plsl_s16_s)
    plsl.s16.s    a0, a0, a1
    rts
    .size   test_plsl_s16_s, .-test_plsl_s16_s

TEST_FUNC(test_pcmpne_8)
    pcmpne.8    a0, a0, a1
    rts
    .size   test_pcmpne_8, .-test_pcmpne_8

TEST_FUNC(test_pcmpne_16)
    pcmpne.16    a0, a0, a1
    rts
    .size   test_pcmpne_16, .-test_pcmpne_16

TEST_FUNC(test_pcmphs_u8)
    pcmphs.u8    a0, a0, a1
    rts
    .size   test_pcmphs_u8, .-test_pcmphs_u8

TEST_FUNC(test_pcmphs_s8)
    pcmphs.s8    a0, a0, a1
    rts
    .size   test_pcmphs_s8, .-test_pcmphs_s8

TEST_FUNC(test_pcmphs_u16)
    pcmphs.u16    a0, a0, a1
    rts
    .size   test_pcmphs_u16, .-test_pcmphs_u16

TEST_FUNC(test_pcmphs_s16)
    pcmphs.s16    a0, a0, a1
    rts
    .size   test_pcmphs_s16, .-test_pcmphs_s16

TEST_FUNC(test_pcmplt_u8)
    pcmplt.u8    a0, a0, a1
    rts
    .size   test_pcmplt_u8, .-test_pcmplt_u8

TEST_FUNC(test_pcmplt_s8)
    pcmplt.s8    a0, a0, a1
    rts
    .size   test_pcmplt_s8, .-test_pcmplt_s8

TEST_FUNC(test_pcmplt_u16)
    pcmplt.u16    a0, a0, a1
    rts
    .size   test_pcmplt_u16, .-test_pcmplt_u16

TEST_FUNC(test_pcmplt_s16)
    pcmplt.s16    a0, a0, a1
    rts
    .size   test_pcmplt_s16, .-test_pcmplt_s16

TEST_FUNC(test_pmax_u8)
    pmax.u8    a0, a0, a1
    rts
    .size   test_pmax_u8, .-test_pmax_u8

TEST_FUNC(test_pmax_s8)
    pmax.s8    a0, a0, a1
    rts
    .size   test_pmax_s8, .-test_pmax_s8

TEST_FUNC(test_pmax_u16)
    pmax.u16    a0, a0, a1
    rts
    .size   test_pmax_u16, .-test_pmax_u16

TEST_FUNC(test_pmax_s16)
    pmax.s16    a0, a0, a1
    rts
    .size   test_pmax_s16, .-test_pmax_s16

TEST_FUNC(test_max_u32)
    max.u32    a0, a0, a1
    rts
    .size   test_max_u32, .-test_max_u32

TEST_FUNC(test_max_s32)
    max.s32    a0, a0, a1
    rts
    .size   test_max_s32, .-test_max_s32

TEST_FUNC(test_pmin_u8)
    pmin.u8    a0, a0, a1
    rts
    .size   test_pmin_u8, .-test_pmin_u8

TEST_FUNC(test_pmin_s8)
    pmin.s8    a0, a0, a1
    rts
    .size   test_pmin_s8, .-test_pmin_s8

TEST_FUNC(test_pmin_u16)
    pmin.u16    a0, a0, a1
    rts
    .size   test_pmin_u16, .-test_pmin_u16

TEST_FUNC(test_pmin_s16)
    pmin.s16    a0, a0, a1
    rts
    .size   test_pmin_s16, .-test_pmin_s16

TEST_FUNC(test_min_u32)
    min.u32    a0, a0, a1
    rts
    .size   test_min_u32, .-test_min_u32

TEST_FUNC(test_min_s32)
    min.s32    a0, a0, a1
    rts
    .size   test_min_s32, .-test_min_s32

TEST_FUNC(test_pkgll)
    pkgll    a0, a0, a1
    rts
    .size   test_pkgll, .-test_pkgll

TEST_FUNC(test_pkghh)
    pkghh    a0, a0, a1
    rts
    .size   test_pkghh, .-test_pkghh

TEST_FUNC(test_narl)
    narl    a0, a0, a1
    rts
    .size   test_narl, .-test_narl

TEST_FUNC(test_narh)
    narh    a0, a0, a1
    rts
    .size   test_narh, .-test_narh

TEST_FUNC(test_narlx)
    narlx    a0, a0, a1
    rts
    .size   test_narlx, .-test_narlx

TEST_FUNC(test_narhx)
    narhx    a0, a0, a1
    rts
    .size   test_narhx, .-test_narhx

TEST_FUNC(test_clipi_u32_0)
    clipi.u32    a0, a0, 0
    rts
    .size   test_clipi_u32_0, .-test_clipi_u32_0

TEST_FUNC(test_clipi_u32_1)
    clipi.u32    a0, a0, 1
    rts
    .size   test_clipi_u32_1, .-test_clipi_u32_1

TEST_FUNC(test_clipi_u32_5)
    clipi.u32    a0, a0, 5
    rts
    .size   test_clipi_u32_5, .-test_clipi_u32_5

TEST_FUNC(test_clipi_u32_2)
    clipi.u32    a0, a0, 2
    rts
    .size   test_clipi_u32_2, .-test_clipi_u32_2

TEST_FUNC(test_clipi_u32_31)
    clipi.u32    a0, a0, 31
    rts
    .size   test_clipi_u32_31, .-test_clipi_u32_31

TEST_FUNC(test_clipi_s32_1)
    clipi.s32    a0, a0, 1
    rts
    .size   test_clipi_s32_1, .-test_clipi_s32_1

TEST_FUNC(test_clipi_s32_2)
    clipi.s32    a0, a0, 2
    rts
    .size   test_clipi_s32_2, .-test_clipi_s32_2

TEST_FUNC(test_clipi_s32_5)
    clipi.s32    a0, a0, 5
    rts
    .size   test_clipi_s32_5, .-test_clipi_s32_5

TEST_FUNC(test_clipi_s32_6)
    clipi.s32    a0, a0, 6
    rts
    .size   test_clipi_s32_6, .-test_clipi_s32_6

TEST_FUNC(test_clipi_s32_31)
    clipi.s32    a0, a0, 31
    rts
    .size   test_clipi_s32_31, .-test_clipi_s32_31

TEST_FUNC(test_clipi_s32_32)
    clipi.s32    a0, a0, 32
    rts
    .size   test_clipi_s32_32, .-test_clipi_s32_32

TEST_FUNC(test_clip_u32)
    clip.u32    a0, a0, a1
    rts
    .size   test_clip_u32, .-test_clip_u32

TEST_FUNC(test_clip_s32)
    clip.s32    a0, a0, a1
    rts
    .size   test_clip_s32, .-test_clip_s32

TEST_FUNC(test_pclipi_u16_0)
    pclipi.u16    a0, a0, 0
    rts
    .size   test_pclipi_u16_0, .-test_pclipi_u16_0

TEST_FUNC(test_pclipi_u16_1)
    pclipi.u16    a0, a0, 1
    rts
    .size   test_pclipi_u16_1, .-test_pclipi_u16_1

TEST_FUNC(test_pclipi_u16_2)
    pclipi.u16    a0, a0, 2
    rts
    .size   test_pclipi_u16_2, .-test_pclipi_u16_2

TEST_FUNC(test_pclipi_u16_7)
    pclipi.u16    a0, a0, 7
    rts
    .size   test_pclipi_u16_7, .-test_pclipi_u16_7

TEST_FUNC(test_pclipi_u16_15)
    pclipi.u16    a0, a0, 15
    rts
    .size   test_pclipi_u16_15, .-test_pclipi_u16_15

TEST_FUNC(test_pclip_u16)
    pclip.u16    a0, a0, a1
    rts
    .size   test_pclip_u16, .-test_pclip_u16

TEST_FUNC(test_pclipi_s16_1)
    pclipi.s16    a0, a0, 1
    rts
    .size   test_pclipi_s16_1, .-test_pclipi_s16_1

TEST_FUNC(test_pclipi_s16_2)
    pclipi.s16    a0, a0, 2
    rts
    .size   test_pclipi_s16_2, .-test_pclipi_s16_2

TEST_FUNC(test_pclipi_s16_9)
    pclipi.s16    a0, a0, 9
    rts
    .size   test_pclipi_s16_9, .-test_pclipi_s16_9

TEST_FUNC(test_pclipi_s16_15)
    pclipi.s16    a0, a0, 15
    rts
    .size   test_pclipi_s16_15, .-test_pclipi_s16_15

TEST_FUNC(test_pclipi_s16_16)
    pclipi.s16    a0, a0, 16
    rts
    .size   test_pclipi_s16_16, .-test_pclipi_s16_16

TEST_FUNC(test_pclip_s16)
    pclip.s16    a0, a0, a1
    rts
    .size   test_pclip_s16, .-test_pclip_s16

TEST_FUNC(test_dup_8_0)
    dup.8    a0, a0, 0
    rts
    .size   test_dup_8_0, .-test_dup_8_0

TEST_FUNC(test_dup_8_1)
    dup.8    a0, a0, 1
    rts
    .size   test_dup_8_1, .-test_dup_8_1

TEST_FUNC(test_dup_8_2)
    dup.8    a0, a0, 2
    rts
    .size   test_dup_8_2, .-test_dup_8_2

TEST_FUNC(test_dup_8_3)
    dup.8    a0, a0, 3
    rts
    .size   test_dup_8_3, .-test_dup_8_3

TEST_FUNC(test_dup_16_0)
    dup.16    a0, a0, 0
    rts
    .size   test_dup_16_0, .-test_dup_16_0

TEST_FUNC(test_dup_16_1)
    dup.16    a0, a0, 1
    rts
    .size   test_dup_16_1, .-test_dup_16_1

TEST_FUNC(test_psabsa_u8)
    psabsa.u8    a0, a0, a1
    rts
    .size   test_psabsa_u8, .-test_psabsa_u8

TEST_FUNC(test_mulaca_s8)
    mulaca.s8    a0, a0, a1
    rts
    .size   test_mulaca_s8, .-test_mulaca_s8

TEST_FUNC(test_pabs_s8_s)
    pabs.s8.s    a0,a0
    rts
    .size   test_pabs_s8_s, .-test_pabs_s8_s

TEST_FUNC(test_pabs_s16_s)
    pabs.s16.s    a0,a0
    rts
    .size   test_pabs_s16_s, .-test_pabs_s16_s

TEST_FUNC(test_abs_s32_s)
    abs.s32.s    a0,a0
    rts
    .size   test_abs_s32_s, .-test_abs_s32_s

TEST_FUNC(test_pneg_s8_s)
    pneg.s8.s    a0,a0
    rts
    .size   test_pneg_s8_s, .-test_pneg_s8_s

TEST_FUNC(test_pneg_s16_s)
    pneg.s16.s    a0,a0
    rts
    .size   test_pneg_s16_s, .-test_pneg_s16_s

TEST_FUNC(test_neg_s32_s)
    neg.s32.s    a0,a0
    rts
    .size   test_neg_s32_s, .-test_neg_s32_s

TEST_FUNC(test_pext_u8_e)
    pext.u8.e    a0,a0
    rts
    .size   test_pext_u8_e, .-test_pext_u8_e

TEST_FUNC(test_pext_s8_e)
    pext.s8.e    a0,a0
    rts
    .size   test_pext_s8_e, .-test_pext_s8_e

TEST_FUNC(test_pextx_u8_e)
    pextx.u8.e    a0,a0
    rts
    .size   test_pextx_u8_e, .-test_pextx_u8_e

TEST_FUNC(test_pextx_s8_e)
    pextx.s8.e    a0,a0
    rts
    .size   test_pextx_s8_e, .-test_pextx_s8_e

TEST_FUNC(test_sel)
    sel    a3, a0, a1, a2
    mov    a0, a3
    rts
    .size   test_sel, .-test_sel

TEST_FUNC(test_dexti_0)
    dexti    a2, a0, a1, 0
    mov    a0, a2
    rts
    .size   test_dexti_0, .-test_dexti_0

TEST_FUNC(test_dexti_2)
    dexti    a2, a0, a1, 2
    mov    a0, a2
    rts
    .size   test_dexti_2, .-test_dexti_2

TEST_FUNC(test_dexti_5)
    dexti    a2, a0, a1, 5
    mov    a0, a2
    rts
    .size   test_dexti_5, .-test_dexti_5

TEST_FUNC(test_dexti_31)
    dexti    a2, a0, a1, 31
    mov    a0, a2
    rts
    .size   test_dexti_31, .-test_dexti_31

TEST_FUNC(test_dext)
    dext    a3, a0, a1, a2
    mov    a0, a3
    rts
    .size   test_dext, .-test_dext

TEST_FUNC(test_psabsaa_u8)
    psabsaa.u8    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_psabsaa_u8, .-test_psabsaa_u8

TEST_FUNC(test_divul)
    divul    a0,a0,a2
    rts
    .size   test_divul, .-test_divul

TEST_FUNC(test_divsl)
    divsl    a0,a0,a2
    rts
    .size   test_divsl, .-test_divsl

TEST_FUNC(test_pkg_4_16)
    pkg    a0, a0, 4, a1, 16
    rts
    .size   test_pkg_4_16, .-test_pkg_4_16

TEST_FUNC(test_pkg_2_3)
    pkg    a0, a0, 2, a1, 3
    rts
    .size   test_pkg_2_13, .-test_pkg_2_3

TEST_FUNC(test_pkg_4_4)
    pkg    a0, a0, 4, a1, 4
    rts
    .size   test_pkg_4_4, .-test_pkg_4_4

TEST_FUNC(test_pkg_8_8)
    pkg    a0, a0, 8, a1, 8
    rts
    .size   test_pkg_8_8, .-test_pkg_8_8

TEST_FUNC(test_pkg_0_15)
    pkg    a0, a0, 0, a1, 15
    rts
    .size   test_pkg_0_15, .-test_pkg_0_15

TEST_FUNC(test_pkg_15_15)
    pkg    a0, a0, 15, a1, 15
    rts
    .size   test_pkg_15_15, .-test_pkg_15_15

TEST_FUNC(test_muls_u32)
    muls.u32    a2, a0, a1
    mov    a0, a2
    mov    a1, a3
    rts
    .size   test_muls_u32, .-test_muls_u32

TEST_FUNC(test_muls_s32)
    muls.s32    a2, a0, a1
    mov    a0, a2
    mov    a1, a3
    rts
    .size   test_muls_s32, .-test_muls_s32

TEST_FUNC(test_mula_u32_s)
    mula.u32.s    a2, a0, a1
    mov    a0, a2
    mov    a1, a3
    rts
    .size   test_mula_u32_s, .-test_mula_u32_s

TEST_FUNC(test_mula_s32_s)
    mula.s32.s    a2, a0, a1
    mov    a0, a2
    mov    a1, a3
    rts
    .size   test_mula_s32_s, .-test_mula_s32_s

TEST_FUNC(test_muls_u32_s)
    muls.u32.s    a2, a0, a1
    mov    a0, a2
    mov    a1, a3
    rts
    .size   test_muls_u32_s, .-test_muls_u32_s

TEST_FUNC(test_muls_s32_s)
    muls.s32.s    a2, a0, a1
    mov    a0, a2
    mov    a1, a3
    rts
    .size   test_muls_s32_s, .-test_muls_s32_s

TEST_FUNC(test_rmul_s32_h)
    rmul.s32.h    a0, a0, a1
    rts
    .size   test_rmul_s32_h, .-test_rmul_s32_h

TEST_FUNC(test_rmul_s32_rh)
    rmul.s32.rh    a0, a0, a1
    rts
    .size   test_rmul_s32_rh, .-test_rmul_s32_rh

TEST_FUNC(test_mula_s32_hs)
    mula.s32.hs    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_mula_s32_hs, .-test_mula_s32_hs

TEST_FUNC(test_muls_s32_hs)
    muls.s32.hs    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_muls_s32_hs, .-test_muls_s32_hs

TEST_FUNC(test_mula_s32_rhs)
    mula.s32.rhs    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_mula_s32_rhs, .-test_mula_s32_rhs

TEST_FUNC(test_muls_s32_rhs)
    muls.s32.rhs    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_muls_s32_rhs, .-test_muls_s32_rhs

TEST_FUNC(test_mulxl_s32)
    mulxl.s32    a0, a0, a1
    rts
    .size   test_mulxl_s32, .-test_mulxl_s32

TEST_FUNC(test_mulxl_s32_r)
    mulxl.s32.r    a0, a0, a1
    rts
    .size   test_mulxl_s32_r, .-test_mulxl_s32_r

TEST_FUNC(test_mulxh_s32)
    mulxh.s32    a0, a0, a1
    rts
    .size   test_mulxh_s32, .-test_mulxh_s32

TEST_FUNC(test_mulxh_s32_r)
    mulxh.s32.r    a0, a0, a1
    rts
    .size   test_mulxh_s32_r, .-test_mulxh_s32_r

TEST_FUNC(test_rmulxl_s32)
    rmulxl.s32    a0, a0, a1
    rts
    .size   test_rmulxl_s32, .-test_rmulxl_s32

TEST_FUNC(test_rmulxl_s32_r)
    rmulxl.s32.r    a0, a0, a1
    rts
    .size   test_rmulxl_s32_r, .-test_rmulxl_s32_r

TEST_FUNC(test_rmulxh_s32)
    rmulxh.s32    a0, a0, a1
    rts
    .size   test_rmulxh_s32, .-test_rmulxh_s32

TEST_FUNC(test_rmulxh_s32_r)
    rmulxh.s32.r    a0, a0, a1
    rts
    .size   test_rmulxh_s32_r, .-test_rmulxh_s32_r

TEST_FUNC(test_mulaxl_s32_s)
    mulaxl.s32.s    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_mulaxl_s32_s, .-test_mulaxl_s32_s

TEST_FUNC(test_mulaxl_s32_rs)
    mulaxl.s32.rs    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_mulaxl_s32_rs, .-test_mulaxl_s32_rs

TEST_FUNC(test_mulaxh_s32_s)
    mulaxh.s32.s    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_mulaxh_s32_s, .-test_mulaxh_s32_s

TEST_FUNC(test_mulaxh_s32_rs)
    mulaxh.s32.rs    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_mulaxh_s32_rs, .-test_mulaxh_s32_rs

TEST_FUNC(test_rmulll_s16)
    rmulll.s16    a0, a0, a1
    rts
    .size   test_rmulll_s16, .-test_rmulll_s16

TEST_FUNC(test_rmulhh_s16)
    rmulhh.s16    a0, a0, a1
    rts
    .size   test_rmulhh_s16, .-test_rmulhh_s16

TEST_FUNC(test_rmulhl_s16)
    rmulhl.s16    a0, a0, a1
    rts
    .size   test_rmulhl_s16, .-test_rmulhl_s16

TEST_FUNC(test_mulall_s16_s)
    mulall.s16.s    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_mulall_s16_s, .-test_mulall_s16_s

TEST_FUNC(test_mulahh_s16_s)
    mulahh.s16.s    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_mulahh_s16_s, .-test_mulahh_s16_s

TEST_FUNC(test_mulahl_s16_s)
    mulahl.s16.s    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_mulahl_s16_s, .-test_mulahl_s16_s

TEST_FUNC(test_mulall_s16_e)
    mulall.s16.e    a2, a0, a1
    mov    a0, a2
    mov    a1, a3
    rts
    .size   test_mulall_s16_e, .-test_mulall_s16_e

TEST_FUNC(test_mulahl_s16_e)
    mulahl.s16.e    a2, a0, a1
    mov    a0, a2
    mov    a1, a3
    rts
    .size   test_mulahl_s16_e, .-test_mulahl_s16_e

TEST_FUNC(test_mulahh_s16_e)
    mulahh.s16.e    a2, a0, a1
    mov    a0, a2
    mov    a1, a3
    rts
    .size   test_mulahh_s16_e, .-test_mulahh_s16_e

TEST_FUNC(test_pmul_s16)
    pmul.s16    a0, a0, a1
    rts
    .size   test_pmul_s16, .-test_pmul_s16

TEST_FUNC(test_pmul_u16)
    pmul.u16    a0, a0, a1
    rts
    .size   test_pmul_u16, .-test_pmul_u16

TEST_FUNC(test_pmulx_s16)
    pmulx.s16    a0, a0, a1
    rts
    .size   test_pmulx_s16, .-test_pmulx_s16

TEST_FUNC(test_pmulx_u16)
    pmulx.u16    a0, a0, a1
    rts
    .size   test_pmulx_u16, .-test_pmulx_u16

TEST_FUNC(test_prmul_s16)
    prmul.s16    a0, a0, a1
    rts
    .size   test_prmul_s16, .-test_prmul_s16

TEST_FUNC(test_prmulx_s16)
    prmulx.s16    a0, a0, a1
    rts
    .size   test_prmulx_s16, .-test_prmulx_s16

TEST_FUNC(test_prmul_s16_h)
    prmul.s16.h    a0, a0, a1
    rts
    .size   test_prmul_s16_h, .-test_prmul_s16_h

TEST_FUNC(test_prmul_s16_rh)
    prmul.s16.rh    a0, a0, a1
    rts
    .size   test_prmul_s16_rh, .-test_prmul_s16_rh

TEST_FUNC(test_prmulx_s16_h)
    prmulx.s16.h    a0, a0, a1
    rts
    .size   test_prmulx_s16_h, .-test_prmulx_s16_h

TEST_FUNC(test_prmulx_s16_rh)
    prmulx.s16.rh    a0, a0, a1
    rts
    .size   test_prmulx_s16_rh, .-test_prmulx_s16_rh

TEST_FUNC(test_mulca_s16_s)
    mulca.s16.s    a0, a0, a1
    rts
    .size   test_mulca_s16_s, .-test_mulca_s16_s

TEST_FUNC(test_mulcax_s16_s)
    mulcax.s16.s    a0, a0, a1
    rts
    .size   test_mulcax_s16_s, .-test_mulcax_s16_s

TEST_FUNC(test_mulcs_s16)
    mulcs.s16    a0, a0, a1
    rts
    .size   test_mulcs_s16, .-test_mulcs_s16

TEST_FUNC(test_mulcsr_s16)
    mulcsr.s16    a0, a0, a1
    rts
    .size   test_mulcsr_s16, .-test_mulcsr_s16

TEST_FUNC(test_mulcsx_s16)
    mulcsx.s16    a0, a0, a1
    rts
    .size   test_mulcsx_s16, .-test_mulcsx_s16

TEST_FUNC(test_mulaca_s16_s)
    mulaca.s16.s    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_mulaca_s16_s, .-test_mulaca_s16_s

TEST_FUNC(test_mulacax_s16_s)
    mulacax.s16.s    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_mulacax_s16_s, .-test_mulacax_s16_s

TEST_FUNC(test_mulacs_s16_s)
    mulacs.s16.s    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_mulacs_s16_s, .-test_mulacs_s16_s

TEST_FUNC(test_mulacsr_s16_s)
    mulacsr.s16.s    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_mulacsr_s16_s, .-test_mulacsr_s16_s

TEST_FUNC(test_mulacsx_s16_s)
    mulacsx.s16.s    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_mulacsx_s16_s, .-test_mulacsx_s16_s

TEST_FUNC(test_mulsca_s16_s)
    mulsca.s16.s    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_mulsca_s16_s, .-test_mulsca_s16_s

TEST_FUNC(test_mulscax_s16_s)
    mulscax.s16.s    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_mulscax_s16_s, .-test_mulscax_s16_s

TEST_FUNC(test_mulaca_s16_e)
    mulaca.s16.e    a2, a0, a1
    mov    a0, a2
    mov    a1, a3
    rts
    .size   test_mulaca_s16_e, .-test_mulaca_s16_e

TEST_FUNC(test_mulacax_s16_e)
    mulacax.s16.e    a2, a0, a1
    mov    a0, a2
    mov    a1, a3
    rts
    .size   test_mulacax_s16_e, .-test_mulacax_s16_e

TEST_FUNC(test_mulacs_s16_e)
    mulacs.s16.e    a2, a0, a1
    mov    a0, a2
    mov    a1, a3
    rts
    .size   test_mulacs_s16_e, .-test_mulacs_s16_e

TEST_FUNC(test_mulacsr_s16_e)
    mulacsr.s16.e    a2, a0, a1
    mov    a0, a2
    mov    a1, a3
    rts
    .size   test_mulacsr_s16_e, .-test_mulacsr_s16_e

TEST_FUNC(test_mulacsx_s16_e)
    mulacsx.s16.e    a2, a0, a1
    mov    a0, a2
    mov    a1, a3
    rts
    .size   test_mulacsx_s16_e, .-test_mulacsx_s16_e

TEST_FUNC(test_mulsca_s16_e)
    mulsca.s16.e    a2, a0, a1
    mov    a0, a2
    mov    a1, a3
    rts
    .size   test_mulsca_s16_e, .-test_mulsca_s16_e

TEST_FUNC(test_mulscax_s16_e)
    mulscax.s16.e    a2, a0, a1
    mov    a0, a2
    mov    a1, a3
    rts
    .size   test_mulscax_s16_e, .-test_mulscax_s16_e

TEST_FUNC(test_mul_u32)
    mul.u32    a0, a0, a1
    rts
    .size   test_mul_u32, .-test_mul_u32

TEST_FUNC(test_mul_s32)
    mul.s32    a0, a0, a1
    rts
    .size   test_mul_s32, .-test_mul_s32

TEST_FUNC(test_mula_u32)
    mula.u32    a2, a0, a1
    mov    a0, a2
    mov    a1, a3
    rts
    .size   test_mula_u32, .-test_mula_u32

TEST_FUNC(test_mula_s32)
    mula.s32    a2, a0, a1
    mov    a0, a2
    mov    a1, a3
    rts
    .size   test_mula_s32, .-test_mula_s32

TEST_FUNC(test_mula_32_l)
    mula.32.l    a2, a0, a1
    mov    a0, a2
    rts
    .size   test_mula_32_l, .-test_mula_32_l

TEST_FUNC(test_mul_s32_h)
    mul.s32.h    a0, a0, a1
    rts
    .size   test_mul_s32_h, .-test_mul_s32_h

TEST_FUNC(test_mul_s32_rh)
    mul.s32.rh    a0, a0, a1
    rts
    .size   test_mul_s32_rh, .-test_mul_s32_rh

TEST_FUNC(test_mulll_s16)
    mulll.s16    a0, a0, a1
    rts
    .size   test_mulll_s16, .-test_mulll_s16

TEST_FUNC(test_mulhh_s16)
    mulhh.s16    a0, a0, a1
    rts
    .size   test_mulhh_s16, .-test_mulhh_s16

TEST_FUNC(test_mulhl_s16)
    mulhl.s16    a0, a0, a1
    rts
    .size   test_mulhl_s16, .-test_mulhl_s16

    .text
    .align 2
LD_DATA:
    .long  0xC0C0C0C0
    .long  0x00010001

TEST_FUNC(test_ldbi_w)
    grs a2, LD_DATA
    mov a3, a2
    ldbi.w a0, (a3)
    subi a3, a3, 4
    cmpne a2, a3
    bf l_ldbi_w
    movi a0, 0
l_ldbi_w:
    rts
    .size  test_ldbi_w, .-test_ldbi_w

TEST_FUNC(test_ldbi_h)
    grs a2, LD_DATA
    mov a3, a2
    ldbi.h a0, (a3)
    subi a3, a3, 2
    cmpne a2, a3
    bf l_ldbi_h
    movi a0, 0
l_ldbi_h:
    rts
    .size  test_ldbi_h, .-test_ldbi_h

TEST_FUNC(test_ldbi_hs)
    grs a2, LD_DATA
    mov a3, a2
    ldbi.hs a0, (a3)
    subi a3, a3, 2
    cmpne a2, a3
    bf l_ldbi_hs
    movi a0, 0
l_ldbi_hs:
    rts
    .size  test_ldbi_hs, .-test_ldbi_hs

TEST_FUNC(test_ldbi_b)
    grs a2, LD_DATA
    mov a3, a2
    ldbi.b a0, (a3)
    subi a3, a3, 1
    cmpne a2, a3
    bf l_ldbi_b
    movi a0, 0
l_ldbi_b:
    rts
    .size  test_ldbi_b, .-test_ldbi_b

TEST_FUNC(test_ldbi_bs)
    grs a2, LD_DATA
    mov a3, a2
    ldbi.bs a0, (a3)
    subi a3, a3, 1
    cmpne a2, a3
    bf l_ldbi_bs
    movi a0, 0
l_ldbi_bs:
    rts
    .size  test_ldbi_bs, .-test_ldbi_bs

TEST_FUNC(test_pldbi_d)
    grs a2, LD_DATA
    mov a3, a2
    pldbi.d a0, (a3)
    subi a3, a3, 8
    cmpne a2, a3
    bf l_pldbi_d
    movi a0, 0
l_pldbi_d:
    rts
    .size  test_pdbi_d, .-test_pldbi_d

TEST_FUNC(test_ldbir_w)
    mov a2, a0
    grs a3, LD_DATA
    ldbir.w a0, (a3), a2
    sub a2, a3, a2
    grs a3, LD_DATA
    cmpne a2, a3
    bf l_ldbir_w
    movi a0, 0
l_ldbir_w:
    rts
    .size  test_ldbir_w, .-test_ldbir_w

TEST_FUNC(test_ldbir_h)
    mov a2, a0
    grs a3, LD_DATA
    ldbir.h a0, (a3), a2
    sub a2, a3, a2
    grs a3, LD_DATA
    cmpne a2, a3
    bf l_ldbir_h
    movi a0, 0
l_ldbir_h:
    rts
    .size  test_ldbir_h, .-test_ldbir_h

TEST_FUNC(test_ldbir_hs)
    mov a2, a0
    grs a3, LD_DATA
    ldbir.hs a0, (a3), a2
    sub a2, a3, a2
    grs a3, LD_DATA
    cmpne a2, a3
    bf l_ldbir_hs
    movi a0, 0
l_ldbir_hs:
    rts
    .size  test_ldbir_hs, .-test_ldbir_hs

TEST_FUNC(test_ldbir_b)
    mov a2, a0
    grs a3, LD_DATA
    ldbir.b a0, (a3), a2
    sub a2, a3, a2
    grs a3, LD_DATA
    cmpne a2, a3
    bf l_ldbir_b
    movi a0, 0
l_ldbir_b:
    rts
    .size  test_ldbir_b, .-test_ldbir_b

TEST_FUNC(test_ldbir_bs)
    mov a2, a0
    grs a3, LD_DATA
    ldbir.bs a0, (a3), a2
    sub a2, a3, a2
    grs a3, LD_DATA
    cmpne a2, a3
    bf l_ldbir_bs
    movi a0, 0
l_ldbir_bs:
    rts
    .size  test_ldbir_bs, .-test_ldbir_bs

TEST_FUNC(test_pldbir_d)
    mov a2, a0
    grs a3, LD_DATA
    pldbir.d a0, (a3), a2
    add a2, a2, a2
    sub a2, a3, a2
    grs a3, LD_DATA
    cmpne a2, a3
    bf l_pldbir_d
    movi a0, 0
l_pldbir_d:
    rts
    .size  test_pdbi_d, .-test_pldbir_d

TEST_FUNC(test_stbi_w)
    mov a2, a0
    stbi.w a1, (a0)
    subi a0, a0, 4
    cmpne a2, a0
    bf l_stbi_w
    movi a0, 0
l_stbi_w:
    rts
    .size  test_stbi_w, .-test_stbi_w

TEST_FUNC(test_stbi_h)
    mov a2, a0
    stbi.h a1, (a0)
    subi a0, a0, 2
    cmpne a2, a0
    bf l_stbi_h
    movi a0, 0
l_stbi_h:
    rts
    .size  test_stbi_h, .-test_stbi_h

TEST_FUNC(test_stbi_b)
    mov a2, a0
    stbi.b a1, (a0)
    subi a0, a0, 1
    cmpne a2, a0
    bf l_stbi_b
    movi a0, 0
l_stbi_b:
    rts
    .size  test_stbi_b, .-test_stbi_b

TEST_FUNC(test_stbir_w)
    mov a3, a0
    stbir.w a2, (a0), a1
    sub a0, a0, a1
    cmpne a3, a0
    bf l_stbir_w
    movi a0, 0
l_stbir_w:
    rts
    .size  test_stbir_w, .-test_stbir_w

TEST_FUNC(test_stbir_h)
    mov a3, a0
    stbir.h a2, (a0), a1
    sub a0, a0, a1
    cmpne a3, a0
    bf l_stbir_h
    movi a0, 0
l_stbir_h:
    rts
    .size  test_stbir_h, .-test_stbir_h

TEST_FUNC(test_stbir_b)
    mov a3, a0
    stbir.b a2, (a0), a1
    sub a0, a0, a1
    cmpne a3, a0
    bf l_stbir_b
    movi a0, 0
l_stbir_b:
    rts
    .size  test_stbir_b, .-test_stbir_b
TEST_FUNC(test_bloop)
l_bloop_begin:
    subu a3,a2
l_bloop_end:
    bloop a0, l_bloop_begin, l_bloop_end
    cmpne a3, a1
    bf l_bloop_exit
    mov a0,a3
l_bloop_exit:
    rts
    .size  test_bloop, .-test_bloop
