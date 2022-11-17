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

   .file   "dspv3_insn.S"
#undef TEST_FUNC
#define TEST_FUNC(name) TEST_FUNC_M name
    .macro TEST_FUNC_M name
    .text
    .align  2
    .global \name
    .type   \name, @function
\name:
    .endm
/* vabs.t */
TEST_FUNC(test_vabs_s8)
        vldm.32         vr0-vr0, (a0)
        vabs.s8         vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vabs_s8, .-test_vabs_s8

TEST_FUNC(test_vabs_s16)
        vldm.32         vr0-vr0, (a0)
        vabs.s16        vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vabs_s16, .-test_vabs_s16

TEST_FUNC(test_vabs_s32)
        vldm.32         vr0-vr0, (a0)
        vabs.s32        vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vabs_s32, .-test_vabs_s32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vabs_f32)
        vldm.32         vr0-vr0, (a0)
        vabs.f32        vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vabs_f32, .-test_vabs_f32

TEST_FUNC(test_vabs_f16)
        vldm.32         vr0-vr0, (a0)
        vabs.f16        vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vabs_f16, .-test_vabs_f16
#endif

/* vabs.t.s */
TEST_FUNC(test_vabs_s8_s)
        vldm.32         vr0-vr0, (a0)
        vabs.s8.s       vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vabs_s8_s, .-test_vabs_s8_s

TEST_FUNC(test_vabs_s16_s)
        vldm.32         vr0-vr0, (a0)
        vabs.s16.s      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vabs_s16_s, .-test_vabs_s16_s

TEST_FUNC(test_vabs_s32_s)
        vldm.32         vr0-vr0, (a0)
        vabs.s32.s      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vabs_s32_s, .-test_vabs_s32_s


/* vneg */
TEST_FUNC(test_vneg_s8)
        vldm.32         vr0-vr0, (a0)
        vneg.s8         vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vneg_s8, .-test_vneg_s8

TEST_FUNC(test_vneg_s16)
        vldm.32         vr0-vr0, (a0)
        vneg.s16        vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vneg_s16, .-test_vneg_s16

TEST_FUNC(test_vneg_s32)
        vldm.32         vr0-vr0, (a0)
        vneg.s32        vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vneg_s32, .-test_vneg_s32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vneg_f32)
        vldm.32         vr0-vr0, (a0)
        vneg.f32        vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vneg_f32, .-test_vneg_f32

TEST_FUNC(test_vneg_f16)
        vldm.32         vr0-vr0, (a0)
        vneg.f16        vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vneg_f16, .-test_vneg_f16
#endif

TEST_FUNC(test_vneg_s8_s)
        vldm.32         vr0-vr0, (a0)
        vneg.s8.s       vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vneg_s8_s, .-test_vneg_s8_s

TEST_FUNC(test_vneg_s16_s)
        vldm.32         vr0-vr0, (a0)
        vneg.s16.s      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vneg_s16_s, .-test_vneg_s16_s

TEST_FUNC(test_vneg_s32_s)
        vldm.32         vr0-vr0, (a0)
        vneg.s32.s      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vneg_s32_s, .-test_vneg_s32_s

/* cls */
TEST_FUNC(test_vcls_s8)
        vldm.32         vr0-vr0, (a0)
        vcls.s8         vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcls_s8, .-test_vcls_s8

TEST_FUNC(test_vcls_s16)
        vldm.32         vr0-vr0, (a0)
        vcls.s16        vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcls_s16, .-test_vcls_s16

TEST_FUNC(test_vcls_s32)
        vldm.32         vr0-vr0, (a0)
        vcls.s32        vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcls_s32, .-test_vcls_s32

/* clz */
TEST_FUNC(test_vclz_8)
        vldm.32         vr0-vr0, (a0)
        vclz.8          vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vclz_8, .-test_vclz_8

TEST_FUNC(test_vclz_16)
        vldm.32         vr0-vr0, (a0)
        vclz.16         vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vclz_16, .-test_vclz_16

TEST_FUNC(test_vclz_32)
        vldm.32         vr0-vr0, (a0)
        vclz.32         vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vclz_32, .-test_vclz_32

TEST_FUNC(test_vclz_64)
        vldm.32         vr0-vr0, (a0)
        vclz.64         vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vclz_64, .-test_vclz_64

/* vnot */
TEST_FUNC(test_vnot_8)
        vldm.32         vr0-vr0, (a0)
        vnot.8          vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vnot_8, .-test_vnot_8

TEST_FUNC(test_vnot_16)
        vldm.32         vr0-vr0, (a0)
        vnot.16         vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vnot_16, .-test_vnot_16

TEST_FUNC(test_vnot_32)
        vldm.32         vr0-vr0, (a0)
        vnot.32         vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vnot_32, .-test_vnot_32

TEST_FUNC(test_vnot_64)
        vldm.32         vr0-vr0, (a0)
        vnot.64         vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vnot_64, .-test_vnot_64

/* vcnt1 */
TEST_FUNC(test_vcnt1_8)
        vldm.32         vr0-vr0, (a0)
        vcnt1.8         vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcnt1_8, .-test_vcnt1_8

TEST_FUNC(test_vcnt1_16)
        vldm.32         vr0-vr0, (a0)
        vcnt1.16        vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcnt1_16, .-test_vcnt1_16

TEST_FUNC(test_vcnt1_32)
        vldm.32         vr0-vr0, (a0)
        vcnt1.32        vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcnt1_32, .-test_vcnt1_32

TEST_FUNC(test_vcnt1_64)
        vldm.32         vr0-vr0, (a0)
        vcnt1.64        vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcnt1_64, .-test_vcnt1_64

/* vadd */
TEST_FUNC(test_vadd_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.s8         vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_s8, .-test_vadd_s8

TEST_FUNC(test_vadd_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.s16        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_s16, .-test_vadd_s16

TEST_FUNC(test_vadd_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.s32        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_s32, .-test_vadd_s32

TEST_FUNC(test_vadd_s64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.s64        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_s64, .-test_vadd_s64

TEST_FUNC(test_vadd_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.u8         vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_u8, .-test_vadd_u8

TEST_FUNC(test_vadd_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.u16        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_u16, .-test_vadd_u16

TEST_FUNC(test_vadd_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.u32        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_u32, .-test_vadd_u32

TEST_FUNC(test_vadd_u64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.u64        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_u64, .-test_vadd_u64

#ifdef VDSP_FLOAT
TEST_FUNC(test_vadd_f32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.f32        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_f32, .-test_vadd_f32

TEST_FUNC(test_vadd_f16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.f16        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_f16, .-test_vadd_f16
#endif

/* vaddh.t */
TEST_FUNC(test_vaddh_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vaddh.s8        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vaddh_s8, .-test_vaddh_s8

TEST_FUNC(test_vaddh_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vaddh.s16       vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vaddh_s16, .-test_vaddh_s16

TEST_FUNC(test_vaddh_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vaddh.s32       vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vaddh_s32, .-test_vaddh_s32

TEST_FUNC(test_vaddh_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vaddh.u8                vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vaddh_u8, .-test_vaddh_u8

TEST_FUNC(test_vaddh_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vaddh.u16       vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vaddh_u16, .-test_vaddh_u16

TEST_FUNC(test_vaddh_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vaddh.u32       vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vaddh_u32, .-test_vaddh_u32

/* vaddh.t.r */
TEST_FUNC(test_vaddh_s8_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vaddh.s8.r      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vaddh_s8_r, .-test_vaddh_s8_r

TEST_FUNC(test_vaddh_s16_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vaddh.s16.r     vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vaddh_s16_r, .-test_vaddh_s16_r

TEST_FUNC(test_vaddh_s32_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vaddh.s32.r     vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vaddh_s32_r, .-test_vaddh_s32_r

TEST_FUNC(test_vaddh_u8_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vaddh.u8.r      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vaddh_u8_r, .-test_vaddh_u8_r

TEST_FUNC(test_vaddh_u16_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vaddh.u16.r     vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vaddh_u16_r, .-test_vaddh_u16_r

TEST_FUNC(test_vaddh_u32_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vaddh.u32.r     vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vaddh_u32_r, .-test_vaddh_u32_r

/* vsubh.t.r */
TEST_FUNC(test_vsubh_s8_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsubh.s8.r      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsubh_s8_r, .-test_vsubh_s8_r

TEST_FUNC(test_vsubh_s16_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsubh.s16.r     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsubh_s16_r, .-test_vsubh_s16_r

TEST_FUNC(test_vsubh_s32_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsubh.s32.r     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsubh_s32_r, .-test_vsubh_s32_r

TEST_FUNC(test_vsubh_u8_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsubh.u8.r      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsubh_u8_r, .-test_vsubh_u8_r

TEST_FUNC(test_vsubh_u16_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsubh.u16.r     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsubh_u16_r, .-test_vsubh_u16_r

TEST_FUNC(test_vsubh_u32_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsubh.u32.r     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsubh_u32_r, .-test_vsubh_u32_r

/* vpadd.t */
TEST_FUNC(test_vpadd_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadd.s8        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpadd_s8, .-test_vpadd_s8

TEST_FUNC(test_vpadd_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadd.s16       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpadd_s16, .-test_vpadd_s16

TEST_FUNC(test_vpadd_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadd.s32       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpadd_s32, .-test_vpadd_s32

TEST_FUNC(test_vpadd_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadd.u8        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpadd_u8, .-test_vpadd_u8

TEST_FUNC(test_vpadd_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadd.u16       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpadd_u16, .-test_vpadd_u16

TEST_FUNC(test_vpadd_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadd.u32       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpadd_u32, .-test_vpadd_u32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vpadd_f32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadd.f32       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpadd_f32, .-test_vpadd_f32

TEST_FUNC(test_vpadd_f16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadd.f16       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpadd_f16, .-test_vpadd_f16
#endif


/* vpadd.t.s */
TEST_FUNC(test_vpadd_s8_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadd.s8.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpadd_s8_s, .-test_vpadd_s8_s

TEST_FUNC(test_vpadd_s16_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadd.s16.s     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpadd_s16_s, .-test_vpadd_s16_s

TEST_FUNC(test_vpadd_s32_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadd.s32.s     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpadd_s32_s, .-test_vpadd_s32_s

TEST_FUNC(test_vpadd_u8_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadd.u8.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpadd_u8_s, .-test_vpadd_u8_s

TEST_FUNC(test_vpadd_u16_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadd.u16.s     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpadd_u16_s, .-test_vpadd_u16_s

TEST_FUNC(test_vpadd_u32_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadd.u32.s     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpadd_u32_s, .-test_vpadd_u32_s

/* vpadd.t.e */
TEST_FUNC(test_vpadd_s8_e)
        vldm.32         vr0-vr0, (a0)
        vpadd.s8.e      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vpadd_s8_e, .-test_vpadd_s8_e

TEST_FUNC(test_vpadd_s16_e)
        vldm.32         vr0-vr0, (a0)
        vpadd.s16.e     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vpadd_s16_e, .-test_vpadd_s16_e

TEST_FUNC(test_vpadd_s32_e)
        vldm.32         vr0-vr0, (a0)
        vpadd.s32.e     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vpadd_s32_e, .-test_vpadd_s32_e

TEST_FUNC(test_vpadd_u8_e)
        vldm.32         vr0-vr0, (a0)
        vpadd.u8.e      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vpadd_u8_e, .-test_vpadd_u8_e

TEST_FUNC(test_vpadd_u16_e)
        vldm.32         vr0-vr0, (a0)
        vpadd.u16.e     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vpadd_u16_e, .-test_vpadd_u16_e

TEST_FUNC(test_vpadd_u32_e)
        vldm.32         vr0-vr0, (a0)
        vpadd.u32.e     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vpadd_u32_e, .-test_vpadd_u32_e

/* vpadda.t.e */
TEST_FUNC(test_vpadda_s8_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadda.s8.e     vr1, vr0
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vpadda_s8_e, .-test_vpadda_s8_e

TEST_FUNC(test_vpadda_s16_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadda.s16.e    vr1, vr0
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vpadda_s16_e, .-test_vpadda_s16_e

TEST_FUNC(test_vpadda_s32_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadda.s32.e    vr1, vr0
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vpadda_s32_e, .-test_vpadda_s32_e

TEST_FUNC(test_vpadda_u8_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadda.u8.e     vr1, vr0
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vpadda_u8_e, .-test_vpadda_u8_e

TEST_FUNC(test_vpadda_u16_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadda.u16.e    vr1, vr0
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vpadda_u16_e, .-test_vpadda_u16_e

TEST_FUNC(test_vpadda_u32_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpadda.u32.e    vr1, vr0
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vpadda_u32_e, .-test_vpadda_u32_e

/* vasx.t.s */
TEST_FUNC(test_vasx_s8_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vasx.s8.s       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vasx_s8_s, .-test_vasx_s8_s

TEST_FUNC(test_vasx_s16_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vasx.s16.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vasx_s16_s, .-test_vasx_s16_s

TEST_FUNC(test_vasx_s32_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vasx.s32.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vasx_s32_s, .-test_vasx_s32_s

TEST_FUNC(test_vasx_u8_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vasx.u8.s       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vasx_u8_s, .-test_vasx_u8_s

TEST_FUNC(test_vasx_u16_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vasx.u16.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vasx_u16_s, .-test_vasx_u16_s

TEST_FUNC(test_vasx_u32_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vasx.u32.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vasx_u32_s, .-test_vasx_u32_s

#ifdef VDSP_FLOAT
TEST_FUNC(test_vasx_f32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vasx.f32        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vasx_f32, .-test_vasx_f32

TEST_FUNC(test_vasx_f16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vasx.f16        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vasx_f16, .-test_vasx_f16
#endif


/* vsax.t.s */
TEST_FUNC(test_vsax_s8_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsax.s8.s       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsax_s8_s, .-test_vsax_s8_s

TEST_FUNC(test_vsax_s16_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsax.s16.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsax_s16_s, .-test_vsax_s16_s

TEST_FUNC(test_vsax_s32_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsax.s32.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsax_s32_s, .-test_vsax_s32_s

TEST_FUNC(test_vsax_u8_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsax.u8.s       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsax_u8_s, .-test_vsax_u8_s

TEST_FUNC(test_vsax_u16_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsax.u16.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsax_u16_s, .-test_vsax_u16_s

TEST_FUNC(test_vsax_u32_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsax.u32.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsax_u32_s, .-test_vsax_u32_s

#ifdef VDSP_FLOAT
TEST_FUNC(test_vsax_f32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsax.f32        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsax_f32, .-test_vsax_f32

TEST_FUNC(test_vsax_f16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsax.f16        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsax_f16, .-test_vsax_f16
#endif

/* vasxh.t */
TEST_FUNC(test_vasxh_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vasxh.s8        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vasxh_s8, .-test_vasxh_s8

TEST_FUNC(test_vasxh_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vasxh.s16       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vasxh_s16, .-test_vasxh_s16

TEST_FUNC(test_vasxh_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vasxh.s32       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vasxh_s32, .-test_vasxh_s32

TEST_FUNC(test_vasxh_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vasxh.u8        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vasxh_u8, .-test_vasxh_u8

TEST_FUNC(test_vasxh_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vasxh.u16       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vasxh_u16, .-test_vasxh_u16

TEST_FUNC(test_vasxh_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vasxh.u32       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vasxh_u32, .-test_vasxh_u32

/* vsaxh.t */
TEST_FUNC(test_vsaxh_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsaxh.s8        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsaxh_s8, .-test_vsaxh_s8

TEST_FUNC(test_vsaxh_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsaxh.s16       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsaxh_s16, .-test_vsaxh_s16

TEST_FUNC(test_vsaxh_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsaxh.s32       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsaxh_s32, .-test_vsaxh_s32

TEST_FUNC(test_vsaxh_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsaxh.u8        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsaxh_u8, .-test_vsaxh_u8

TEST_FUNC(test_vsaxh_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsaxh.u16       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsaxh_u16, .-test_vsaxh_u16

TEST_FUNC(test_vsaxh_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsaxh.u32       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsaxh_u32, .-test_vsaxh_u32

/* vadd.t.s */
TEST_FUNC(test_vadd_s8_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.s8.s       vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_s8_s, .-test_vadd_s8_s

TEST_FUNC(test_vadd_s16_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.s16.s      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_s16_s, .-test_vadd_s16_s

TEST_FUNC(test_vadd_s32_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.s32.s      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_s32_s, .-test_vadd_s32_s

TEST_FUNC(test_vadd_s64_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.s64.s      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_s64_s, .-test_vadd_s64_s

TEST_FUNC(test_vadd_u8_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.u8.s       vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_u8_s, .-test_vadd_u8_s

TEST_FUNC(test_vadd_u16_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.u16.s      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_u16_s, .-test_vadd_u16_s

TEST_FUNC(test_vadd_u32_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.u32.s      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_u32_s, .-test_vadd_u32_s

TEST_FUNC(test_vadd_u64_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.u64.s      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_u64_s, .-test_vadd_u64_s

/* vadd.t.h */
TEST_FUNC(test_vadd_s16_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.s16.h      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_s16_h, .-test_vadd_s16_h

TEST_FUNC(test_vadd_s32_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.s32.h      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_s32_h, .-test_vadd_s32_h

TEST_FUNC(test_vadd_s64_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.s64.h      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_s64_h, .-test_vadd_s64_h

TEST_FUNC(test_vadd_u16_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.u16.h      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_u16_h, .-test_vadd_u16_h

TEST_FUNC(test_vadd_u32_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.u32.h      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_u32_h, .-test_vadd_u32_h

TEST_FUNC(test_vadd_u64_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.u64.h      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_u64_h, .-test_vadd_u64_h

/* vadd.t.rh */
TEST_FUNC(test_vadd_s16_rh)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.s16.rh     vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_s16_rh, .-test_vadd_s16_rh

TEST_FUNC(test_vadd_s32_rh)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.s32.rh     vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_s32_rh, .-test_vadd_s32_rh

TEST_FUNC(test_vadd_s64_rh)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.s64.rh     vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_s64_rh, .-test_vadd_s64_rh

TEST_FUNC(test_vadd_u16_rh)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.u16.rh     vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_u16_rh, .-test_vadd_u16_rh

TEST_FUNC(test_vadd_u32_rh)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.u32.rh     vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_u32_rh, .-test_vadd_u32_rh

TEST_FUNC(test_vadd_u64_rh)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.u64.rh     vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vadd_u64_rh, .-test_vadd_u64_rh

/* vsub.t.h */
TEST_FUNC(test_vsub_s16_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.s16.h      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_s16_h, .-test_vsub_s16_h

TEST_FUNC(test_vsub_s32_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.s32.h      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_s32_h, .-test_vsub_s32_h

TEST_FUNC(test_vsub_s64_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.s64.h      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_s64_h, .-test_vsub_s64_h

TEST_FUNC(test_vsub_u16_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.u16.h      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_u16_h, .-test_vsub_u16_h

TEST_FUNC(test_vsub_u32_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.u32.h      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_u32_h, .-test_vsub_u32_h

TEST_FUNC(test_vsub_u64_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.u64.h      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_u64_h, .-test_vsub_u64_h

/* vsub.t.rh */
TEST_FUNC(test_vsub_s16_rh)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.s16.rh     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_s16_rh, .-test_vsub_s16_rh

TEST_FUNC(test_vsub_s32_rh)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.s32.rh     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_s32_rh, .-test_vsub_s32_rh

TEST_FUNC(test_vsub_s64_rh)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.s64.rh     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_s64_rh, .-test_vsub_s64_rh

TEST_FUNC(test_vsub_u16_rh)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.u16.rh     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_u16_rh, .-test_vsub_u16_rh

TEST_FUNC(test_vsub_u32_rh)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.u32.rh     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_u32_rh, .-test_vsub_u32_rh

TEST_FUNC(test_vsub_u64_rh)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.u64.rh     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_u64_rh, .-test_vsub_u64_rh

/* vadd.t.e */
TEST_FUNC(test_vadd_s8_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.s8.e       vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vadd_s8_e, .-test_vadd_s8_e

TEST_FUNC(test_vadd_s16_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.s16.e      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vadd_s16_e, .-test_vadd_s16_e

TEST_FUNC(test_vadd_s32_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.s32.e      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vadd_s32_e, .-test_vadd_s32_e

TEST_FUNC(test_vadd_u8_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.u8.e       vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vadd_u8_e, .-test_vadd_u8_e

TEST_FUNC(test_vadd_u16_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.u16.e      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vadd_u16_e, .-test_vadd_u16_e

TEST_FUNC(test_vadd_u32_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vadd.u32.e      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vadd_u32_e, .-test_vadd_u32_e

/* vsub.t.e */
TEST_FUNC(test_vsub_s8_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.s8.e       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsub_s8_e, .-test_vsub_s8_e

TEST_FUNC(test_vsub_s16_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.s16.e      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsub_s16_e, .-test_vsub_s16_e

TEST_FUNC(test_vsub_s32_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.s32.e      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsub_s32_e, .-test_vsub_s32_e

TEST_FUNC(test_vsub_u8_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.u8.e       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsub_u8_e, .-test_vsub_u8_e

TEST_FUNC(test_vsub_u16_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.u16.e      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsub_u16_e, .-test_vsub_u16_e

TEST_FUNC(test_vsub_u32_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.u32.e      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsub_u32_e, .-test_vsub_u32_e

/* vadd.t.x */
TEST_FUNC(test_vadd_s8_x)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vadd.s8.x       vr3, vr0, vr2
        vstm.32         vr3-vr3, (a3)
        addi            a3, 160
        vstm.32         vr4-vr4, (a3)
        rts
        .size   test_vadd_s8_x, .-test_vadd_s8_x

TEST_FUNC(test_vadd_s16_x)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vadd.s16.x      vr3, vr0, vr2
        vstm.32         vr3-vr3, (a3)
        addi            a3, 160
        vstm.32         vr4-vr4, (a3)
        rts
        .size   test_vadd_s16_x, .-test_vadd_s16_x

TEST_FUNC(test_vadd_s32_x)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vadd.s32.x      vr3, vr0, vr2
        vstm.32         vr3-vr3, (a3)
        addi            a3, 160
        vstm.32         vr4-vr4, (a3)
        rts
        .size   test_vadd_s32_x, .-test_vadd_s32_x

TEST_FUNC(test_vadd_u8_x)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vadd.u8.x       vr3, vr0, vr2
        vstm.32         vr3-vr3, (a3)
        addi            a3, 160
        vstm.32         vr4-vr4, (a3)
        rts
        .size   test_vadd_u8_x, .-test_vadd_u8_x

TEST_FUNC(test_vadd_u16_x)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vadd.u16.x      vr3, vr0, vr2
        vstm.32         vr3-vr3, (a3)
        addi            a3, 160
        vstm.32         vr4-vr4, (a3)
        rts
        .size   test_vadd_u16_x, .-test_vadd_u16_x

TEST_FUNC(test_vadd_u32_x)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vadd.u32.x      vr3, vr0, vr2
        vstm.32         vr3-vr3, (a3)
        addi            a3, 160
        vstm.32         vr4-vr4, (a3)
        rts
        .size   test_vadd_u32_x, .-test_vadd_u32_x

/* vsub.t.x */
TEST_FUNC(test_vsub_s8_x)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vsub.s8.x       vr3, vr0, vr2
        vstm.32         vr3-vr3, (a3)
        addi            a3, 160
        vstm.32         vr4-vr4, (a3)
        rts
        .size   test_vsub_s8_x, .-test_vsub_s8_x

TEST_FUNC(test_vsub_s16_x)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vsub.s16.x      vr3, vr0, vr2
        vstm.32         vr3-vr3, (a3)
        addi            a3, 160
        vstm.32         vr4-vr4, (a3)
        rts
        .size   test_vsub_s16_x, .-test_vsub_s16_x

TEST_FUNC(test_vsub_s32_x)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vsub.s32.x      vr3, vr0, vr2
        vstm.32         vr3-vr3, (a3)
        addi            a3, 160
        vstm.32         vr4-vr4, (a3)
        rts
        .size   test_vsub_s32_x, .-test_vsub_s32_x

TEST_FUNC(test_vsub_u8_x)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vsub.u8.x       vr3, vr0, vr2
        vstm.32         vr3-vr3, (a3)
        addi            a3, 160
        vstm.32         vr4-vr4, (a3)
        rts
        .size   test_vsub_u8_x, .-test_vsub_u8_x

TEST_FUNC(test_vsub_u16_x)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vsub.u16.x      vr3, vr0, vr2
        vstm.32         vr3-vr3, (a3)
        addi            a3, 160
        vstm.32         vr4-vr4, (a3)
        rts
        .size   test_vsub_u16_x, .-test_vsub_u16_x

TEST_FUNC(test_vsub_u32_x)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vsub.u32.x      vr3, vr0, vr2
        vstm.32         vr3-vr3, (a3)
        addi            a3, 160
        vstm.32         vr4-vr4, (a3)
        rts
        .size   test_vsub_u32_x, .-test_vsub_u32_x

/* vmul */
TEST_FUNC(test_vmul_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.s8         vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmul_s8, .-test_vmul_s8

TEST_FUNC(test_vmul_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.s16        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmul_s16, .-test_vmul_s16

TEST_FUNC(test_vmul_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.s32        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmul_s32, .-test_vmul_s32

TEST_FUNC(test_vmul_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.u8         vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmul_u8, .-test_vmul_u8

TEST_FUNC(test_vmul_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.u16        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmul_u16, .-test_vmul_u16

TEST_FUNC(test_vmul_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.u32        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmul_u32, .-test_vmul_u32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vmul_f32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.f32        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmul_f32, .-test_vmul_f32

TEST_FUNC(test_vmul_f16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.f16        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmul_f16, .-test_vmul_f16
#endif

/* vmuli */
TEST_FUNC(test_vmuli_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.s8        vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmuli_s8, .-test_vmuli_s8

TEST_FUNC(test_vmuli_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.s16       vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmuli_s16, .-test_vmuli_s16

TEST_FUNC(test_vmuli_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.s32       vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmuli_s32, .-test_vmuli_s32

TEST_FUNC(test_vmuli_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.u8        vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmuli_u8, .-test_vmuli_u8

TEST_FUNC(test_vmuli_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.u16       vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmuli_u16, .-test_vmuli_u16

TEST_FUNC(test_vmuli_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.u32       vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmuli_u32, .-test_vmuli_u32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vmuli_f32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.f32       vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmuli_f32, .-test_vmuli_f32

TEST_FUNC(test_vmuli_f16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.f16       vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmuli_f16, .-test_vmuli_f16
#endif

/* vmul.t.h */
TEST_FUNC(test_vmul_s8_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.s8.h       vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmul_s8_h, .-test_vmul_s8_h

TEST_FUNC(test_vmul_s16_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.s16.h      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmul_s16_h, .-test_vmul_s16_h

TEST_FUNC(test_vmul_s32_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.s32.h      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmul_s32_h, .-test_vmul_s32_h

TEST_FUNC(test_vmul_u8_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.u8.h       vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmul_u8_h, .-test_vmul_u8_h

TEST_FUNC(test_vmul_u16_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.u16.h      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmul_u16_h, .-test_vmul_u16_h

TEST_FUNC(test_vmul_u32_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.u32.h      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmul_u32_h, .-test_vmul_u32_h

/* vmuli.t.h */
TEST_FUNC(test_vmuli_s8_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.s8.h      vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmuli_s8_h, .-test_vmuli_s8_h

TEST_FUNC(test_vmuli_s16_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.s16.h     vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmuli_s16_h, .-test_vmuli_s16_h

TEST_FUNC(test_vmuli_s32_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.s32.h     vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmuli_s32_h, .-test_vmuli_s32_h

TEST_FUNC(test_vmuli_u8_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.u8.h      vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulh_u8_h, .-test_vmuli_u8_h

TEST_FUNC(test_vmuli_u16_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.u16.h     vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmuli_u16_h, .-test_vmuli_u16_h

TEST_FUNC(test_vmuli_u32_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.u32.h     vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmuli_u32_h, .-test_vmuli_u32_h

/* vmul.t.e */
TEST_FUNC(test_vmul_s8_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.s8.e       vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vmul_s8_e, .-test_vmul_s8_e

TEST_FUNC(test_vmul_s16_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.s16.e      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vmul_s16_e, .-test_vmul_s16_e

TEST_FUNC(test_vmul_s32_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.s32.e      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vmul_s32_e, .-test_vmul_s32_e

TEST_FUNC(test_vmul_u8_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.u8.e       vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vmul_u8_e, .-test_vmul_u8_e

TEST_FUNC(test_vmul_u16_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.u16.e      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vmul_u16_e, .-test_vmul_u16_e

TEST_FUNC(test_vmul_u32_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmul.u32.e      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vmul_u32_e, .-test_vmul_u32_e


/* vmuli.t.e */
TEST_FUNC(test_vmuli_s8_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.s8.e      vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vmuli_s8_e, .-test_vmuli_s8_e

TEST_FUNC(test_vmuli_s16_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.s16.e     vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vmuli_s16_e, .-test_vmuli_s16_e

TEST_FUNC(test_vmuli_s32_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.s32.e     vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vmuli_s32_e, .-test_vmuli_s32_e

TEST_FUNC(test_vmuli_u8_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.u8.e      vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vmuli_u8_e, .-test_vmuli_u8_e

TEST_FUNC(test_vmuli_u16_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.u16.e     vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vmuli_u16_e, .-test_vmuli_u16_e

TEST_FUNC(test_vmuli_u32_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmuli.u32.e     vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vmuli_u32_e, .-test_vmuli_u32_e

/* vmula */
TEST_FUNC(test_vmula_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmula.s8        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmula_s8, .-test_vmula_s8

TEST_FUNC(test_vmula_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmula.s16       vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmula_s16, .-test_vmula_s16

TEST_FUNC(test_vmula_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmula.s32       vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmula_s32, .-test_vmula_s32

TEST_FUNC(test_vmula_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmula.u8        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmula_u8, .-test_vmula_u8

TEST_FUNC(test_vmula_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmula.u16       vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmula_u16, .-test_vmula_u16

TEST_FUNC(test_vmula_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmula.u32       vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmula_u32, .-test_vmula_u32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vmula_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vmula.f32       vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vmula_f32, .-test_vmula_f32

TEST_FUNC(test_vmula_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vmula.f16       vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vmula_f16, .-test_vmula_f16
#endif

/* vmulai */
TEST_FUNC(test_vmulai_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulai.s8       vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulai_s8, .-test_vmulai_s8

TEST_FUNC(test_vmulai_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulai.s16      vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulai_s16, .-test_vmulai_s16

TEST_FUNC(test_vmulai_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulai.s32      vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulai_s32, .-test_vmulai_s32

TEST_FUNC(test_vmulai_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulai.u8       vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulai_u8, .-test_vmulai_u8

TEST_FUNC(test_vmulai_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulai.u16      vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulai_u16, .-test_vmulai_u16

TEST_FUNC(test_vmulai_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulai.u32      vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulai_u32, .-test_vmulai_u32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vmulai_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vmulai.f32      vr2, vr0, vr1, 0
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vmulai_f32, .-test_vmulai_f32

TEST_FUNC(test_vmulai_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vmulai.f16      vr2, vr0, vr1, 0
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vmulai_f16, .-test_vmulai_f16
#endif

/* vmula.t.e */
TEST_FUNC(test_vmula_s8_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmula.s8.e      vr2, vr1, vr0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmula_s8_e, .-test_vmula_s8_e

TEST_FUNC(test_vmula_s16_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmula.s16.e     vr2, vr1, vr0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmula_s16_e, .-test_vmula_s16_e

TEST_FUNC(test_vmula_s32_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmula.s32.e     vr2, vr1, vr0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmula_s32_e, .-test_vmula_s32_e

TEST_FUNC(test_vmula_u8_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmula.u8.e      vr2, vr1, vr0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmula_u8_e, .-test_vmula_u8_e

TEST_FUNC(test_vmula_u16_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmula.u16.e     vr2, vr1, vr0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmula_u16_e, .-test_vmula_u16_e

TEST_FUNC(test_vmula_u32_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmula.u32.e     vr2, vr1, vr0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmula_u32_e, .-test_vmula_u32_e

/* vmulai.t.e */
TEST_FUNC(test_vmulai_s8_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmulai.s8.e     vr2, vr0, vr1, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmulai_s8_e, .-test_vmulai_s8_e

TEST_FUNC(test_vmulai_s16_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmulai.s16.e    vr2, vr0, vr1, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmulai_s16_e, .-test_vmulai_s16_e

TEST_FUNC(test_vmulai_s32_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmulai.s32.e    vr2, vr0, vr1, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        rts
        .size   test_vmulai_s32_e, .-test_vmulai_s32_e

TEST_FUNC(test_vmulai_u8_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmulai.u8.e     vr2, vr0, vr1, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        rts
        .size   test_vmulai_u8_e, .-test_vmulai_u8_e

TEST_FUNC(test_vmulai_u16_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmulai.u16.e    vr2, vr0, vr1, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        rts
        .size   test_vmulai_u16_e, .-test_vmulai_u16_e

TEST_FUNC(test_vmulai_u32_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmulai.u32.e    vr2, vr0, vr1, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        rts
        .size   test_vmulai_u32_e, .-test_vmulai_u32_e

/* vmuls */
TEST_FUNC(test_vmuls_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmuls.s8        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmuls_s8, .-test_vmuls_s8

TEST_FUNC(test_vmuls_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmuls.s16       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmuls_s16, .-test_vmuls_s16

TEST_FUNC(test_vmuls_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmuls.s32       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmuls_s32, .-test_vmuls_s32

TEST_FUNC(test_vmuls_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmuls.u8        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmuls_u8, .-test_vmuls_u8

TEST_FUNC(test_vmuls_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmuls.u16       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmuls_u16, .-test_vmuls_u16

TEST_FUNC(test_vmuls_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmuls.u32       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmuls_u32, .-test_vmuls_u32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vmuls_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vmuls.f32       vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vmuls_f32, .-test_vmuls_f32

TEST_FUNC(test_vmuls_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vmuls.f16       vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vmuls_f16, .-test_vmuls_f16
#endif

/* vmulsi */
TEST_FUNC(test_vmulsi_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulsi.s8       vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulsi_s8, .-test_vmulsi_s8

TEST_FUNC(test_vmulsi_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulsi.s16      vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulsi_s16, .-test_vmulsi_s16

TEST_FUNC(test_vmulsi_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulsi.s32      vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulsi_s32, .-test_vmulsi_s32

TEST_FUNC(test_vmulsi_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulsi.u8       vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulsi_u8, .-test_vmulsi_u8

TEST_FUNC(test_vmulsi_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulsi.u16      vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulsi_u16, .-test_vmulsi_u16

TEST_FUNC(test_vmulsi_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulsi.u32      vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulsi_u32, .-test_vmulsi_u32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vmulsi_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vmulsi.f32      vr2, vr0, vr1, 0
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vmulsi_f32, .-test_vmulsi_f32

TEST_FUNC(test_vmulsi_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vmulsi.f16       vr2, vr0, vr1, 0
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vmulsi_f16, .-test_vmulsi_f16
#endif

/* vmuls.t.e */
TEST_FUNC(test_vmuls_s8_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmuls.s8.e      vr2, vr1, vr0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmuls_s8_e, .-test_vmuls_s8_e

TEST_FUNC(test_vmuls_s16_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmuls.s16.e     vr2, vr1, vr0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmuls_s16_e, .-test_vmuls_s16_e

TEST_FUNC(test_vmuls_s32_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmuls.s32.e     vr2, vr1, vr0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmuls_s32_e, .-test_vmuls_s32_e

TEST_FUNC(test_vmuls_u8_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmuls.u8.e      vr2, vr1, vr0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmuls_u8_e, .-test_vmuls_u8_e

TEST_FUNC(test_vmuls_u16_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmuls.u16.e     vr2, vr1, vr0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmuls_u16_e, .-test_vmuls_u16_e

TEST_FUNC(test_vmuls_u32_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmuls.u32.e     vr2, vr1, vr0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmuls_u32_e, .-test_vmuls_u32_e

/* vmulsi.t.e */
TEST_FUNC(test_vmulsi_s8_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmulsi.s8.e     vr2, vr0, vr1, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmulsi_s8_e, .-test_vmulsi_s8_e

TEST_FUNC(test_vmulsi_s16_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmulsi.s16.e    vr2, vr0, vr1, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmulsi_s16_e, .-test_vmulsi_s16_e

TEST_FUNC(test_vmulsi_s32_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmulsi.s32.e    vr2, vr0, vr1, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmulsi_s32_e, .-test_vmulsi_s32_e

TEST_FUNC(test_vmulsi_u8_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmulsi.u8.e     vr2, vr0, vr1, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmulsi_u8_e, .-test_vmulsi_u8_e

TEST_FUNC(test_vmulsi_u16_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmulsi.u16.e    vr2, vr0, vr1, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmulsi_u16_e, .-test_vmulsi_u16_e

TEST_FUNC(test_vmulsi_u32_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vmulsi.u32.e    vr2, vr0, vr1, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vmulsi_u32_e, .-test_vmulsi_u32_e

/* vmulaca */
TEST_FUNC(test_vmulaca_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmulaca.s8      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulaca_s8, .-test_vmulaca_s8

TEST_FUNC(test_vmulaca_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmulaca.s16     vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulaca_s16, .-test_vmulaca_s16

TEST_FUNC(test_vmulaca_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmulaca.u8      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulaca_u8, .-test_vmulaca_u8

TEST_FUNC(test_vmulaca_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmulaca.u16     vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulaca_u16, .-test_vmulaca_u16

/* vmulacaa */
TEST_FUNC(test_vmulacaa_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulacaa.s8     vr2, vr1, vr0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vmulacaa_s8, .-test_vmulacaa_s8

TEST_FUNC(test_vmulacaa_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulacaa.s16    vr2, vr1, vr0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vmulacaa_s16, .-test_vmulacaa_s16

TEST_FUNC(test_vmulacaa_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulacaa.u8     vr2, vr1, vr0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vmulacaa_u8, .-test_vmulacaa_u8

TEST_FUNC(test_vmulacaa_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulacaa.u16    vr2, vr1, vr0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vmulacaa_u16, .-test_vmulacaa_u16

/* vmulacai */
TEST_FUNC(test_vmulacai_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmulacai.s8     vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulacai_s8, .-test_vmulacai_s8

TEST_FUNC(test_vmulacai_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmulacai.s16    vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulacai_s16, .-test_vmulacai_s16

TEST_FUNC(test_vmulacai_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmulacai.u8     vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulacai_u8, .-test_vmulacai_u8

TEST_FUNC(test_vmulacai_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmulacai.u16    vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmulacai_u16, .-test_vmulacai_u16


/* vmulacaai */
TEST_FUNC(test_vmulacaai_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulacaai.s8    vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vmulacaai_s8, .-test_vmulacaai_s8

TEST_FUNC(test_vmulacaai_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulacaai.s16   vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vmulacaai_s16, .-test_vmulacaai_s16

TEST_FUNC(test_vmulacaai_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulacaai.u8    vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vmulacaai_u8, .-test_vmulacaai_u8

TEST_FUNC(test_vmulacaai_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vmulacaai.u16   vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vmulacaai_u16, .-test_vmulacaai_u16

/* vrmul.t.se */
TEST_FUNC(test_vrmul_s8_se)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmul.s8.se     vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vrmul_s8_se, .-test_vrmul_s8_se

TEST_FUNC(test_vrmul_s16_se)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmul.s16.se    vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vrmul_s16_se, .-test_vrmul_s16_se

TEST_FUNC(test_vrmul_s32_se)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmul.s32.se    vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vrmul_s32_se, .-test_vrmul_s32_se

/* vrmuli.t.se */
TEST_FUNC(test_vrmuli_s8_se)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmuli.s8.se    vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vrmuli_s8_se, .-test_vrmuli_s8_se

TEST_FUNC(test_vrmuli_s16_se)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmuli.s16.se   vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vrmuli_s16_se, .-test_vrmuli_s16_se

TEST_FUNC(test_vrmuli_s32_se)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmuli.s32.se   vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vrmuli_s32_se, .-test_vrmuli_s32_se

/* vrmulh.t.s */
TEST_FUNC(test_vrmulh_s8_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmulh.s8.s     vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrmulh_s16_s, .-test_vrmulh_s16_s

TEST_FUNC(test_vrmulh_s16_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmulh.s16.s    vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrmulh_s16_s, .-test_vrmulh_s16_s

TEST_FUNC(test_vrmulh_s32_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmulh.s32.s    vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrmulh_s32_s, .-test_vrmulh_s32_s

/* vrmulhi.t.s */
TEST_FUNC(test_vrmulhi_s8_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmulhi.s8.s    vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrmulhi_s16_s, .-test_vrmulhi_s16_s

TEST_FUNC(test_vrmulhi_s16_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmulhi.s16.s   vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrmulhi_s16_s, .-test_vrmulhi_s16_s

TEST_FUNC(test_vrmulhi_s32_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmulhi.s32.s   vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrmulhi_s32_s, .-test_vrmulhi_s32_s

/* vrmulh.t.rs */
TEST_FUNC(test_vrmulh_s8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmulh.s8.rs    vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrmulh_s16_rs, .-test_vrmulh_s16_rs

TEST_FUNC(test_vrmulh_s16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmulh.s16.rs   vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrmulh_s16_rs, .-test_vrmulh_s16_rs

TEST_FUNC(test_vrmulh_s32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmulh.s32.rs   vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrmulh_s32_rs, .-test_vrmulh_s32_rs

/* vrmulhi.t.rs */
TEST_FUNC(test_vrmulhi_s8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmulhi.s8.rs   vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrmulhi_s16_rs, .-test_vrmulhi_s16_rs

TEST_FUNC(test_vrmulhi_s16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmulhi.s16.rs  vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrmulhi_s16_rs, .-test_vrmulhi_s16_rs

TEST_FUNC(test_vrmulhi_s32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmulhi.s32.rs  vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrmulhi_s32_rs, .-test_vrmulhi_s32_rs

/* vrmulha.t.rs */
TEST_FUNC(test_vrmulha_s8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulha.s8.rs   vr2, vr1, vr0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulha_s16_rs, .-test_vrmulha_s16_rs

TEST_FUNC(test_vrmulha_s16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulha.s16.rs  vr2, vr1, vr0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulha_s16_rs, .-test_vrmulha_s16_rs

TEST_FUNC(test_vrmulha_s32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulha.s32.rs  vr2, vr1, vr0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulha_s32_rs, .-test_vrmulha_s32_rs

/* vrmulhs.t.rs */
TEST_FUNC(test_vrmulhs_s8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulhs.s8.rs   vr2, vr1, vr0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulhs_s16_rs, .-test_vrmulhs_s16_rs

TEST_FUNC(test_vrmulhs_s16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulhs.s16.rs  vr2, vr1, vr0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulhs_s16_rs, .-test_vrmulhs_s16_rs

TEST_FUNC(test_vrmulhs_s32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulhs.s32.rs  vr2, vr1, vr0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulhs_s32_rs, .-test_vrmulhs_s32_rs

/* vrmulhai.t.rs */
TEST_FUNC(test_vrmulhai_s8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulhai.s8.rs  vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulhai_s8_rs, .-test_vrmulhai_s8_rs

TEST_FUNC(test_vrmulhai_s16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulhai.s16.rs vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulhai_s16_rs, .-test_vrmulhai_s16_rs

TEST_FUNC(test_vrmulhai_s32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulhai.s32.rs vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulhai_s32_rs, .-test_vrmulhai_s32_rs

/* vrmulhsi.t.rs */
TEST_FUNC(test_vrmulhsi_s8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulhsi.s8.rs  vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulhsi_s8_rs, .-test_vrmulhsi_s8_rs

TEST_FUNC(test_vrmulhsi_s16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulhsi.s16.rs vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulhsi_s16_rs, .-test_vrmulhsi_s16_rs

TEST_FUNC(test_vrmulhsi_s32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulhsi.s32.rs vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulhsi_s32_rs, .-test_vrmulhsi_s32_rs

/* vrmulsa.t.e */
TEST_FUNC(test_vrmulsa_s8_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrmulsa.s8.e    vr2, vr0,  vr1, 1
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrmulsa_s8_e, .-test_vrmulsa_s8_e

TEST_FUNC(test_vrmulsa_s16_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrmulsa.s16.e   vr2, vr0,  vr1, 1
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrmulsa_s16_e, .-test_vrmulsa_s16_e

TEST_FUNC(test_vrmulsa_s32_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrmulsa.s32.e   vr2, vr0,  vr1, 1
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrmulsa_s32_e, .-test_vrmulsa_s32_e

/* vrmulsai.t.e */
TEST_FUNC(test_vrmulsai_s8_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrmulsai.s8.e   vr2, vr0, 1, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrmulsai_s8_e, .-test_vrmulsai_s8_e

TEST_FUNC(test_vrmulsai_s16_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrmulsai.s16.e  vr2, vr0, 1, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrmulsai_s16_e, .-test_vrmulsai_s16_e

TEST_FUNC(test_vrmulsai_s32_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrmulsai.s32.e  vr2, vr0, 1, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrmulsai_s32_e, .-test_vrmulsai_s32_e

/* vrmulss.t.e */
TEST_FUNC(test_vrmulss_s8_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrmulss.s8.e    vr2, vr0,  vr1, 1
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrmulss_s8_e, .-test_vrmulss_s8_e

TEST_FUNC(test_vrmulss_s16_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrmulss.s16.e   vr2, vr0,  vr1, 1
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrmulss_s16_e, .-test_vrmulss_s16_e

TEST_FUNC(test_vrmulss_s32_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrmulss.s32.e   vr2, vr0,  vr1, 1
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrmulss_s32_e, .-test_vrmulss_s32_e

/* vrmulssi.t.e */
TEST_FUNC(test_vrmulssi_s8_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrmulssi.s8.e   vr2, vr0, 1, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrmulssi_s8_e, .-test_vrmulssi_s8_e

TEST_FUNC(test_vrmulssi_s16_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrmulssi.s16.e  vr2, vr0, 1, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrmulssi_s16_e, .-test_vrmulssi_s16_e

TEST_FUNC(test_vrmulssi_s32_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrmulssi.s32.e  vr2, vr0, 1, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrmulssi_s32_e, .-test_vrmulssi_s32_e

/* vrmulshr.t.e */
TEST_FUNC(test_vrmulshr_s8_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmulshr.s8.e   vr2, vr0, vr1, 1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vrmulshr_s8_e, .-test_vrmulshr_s8_e

TEST_FUNC(test_vrmulshr_s16_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmulshr.s16.e  vr2, vr0, vr1, 1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vrmulshr_s16_e, .-test_vrmulshr_s16_e

TEST_FUNC(test_vrmulshr_s32_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmulshr.s32.e  vr2, vr0, vr1, 1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vrmulshr_s32_e, .-test_vrmulshr_s32_e

/* vrmulshri.t.e */
TEST_FUNC(test_vrmulshri_s8_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmulshri.s8.e  vr2, vr0, 1, 0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vrmulshri_s8_e, .-test_vrmulshri_s8_e

TEST_FUNC(test_vrmulshri_s16_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmulshri.s16.e vr2, vr0, 1, 0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vrmulshri_s16_e, .-test_vrmulshri_s16_e

TEST_FUNC(test_vrmulshri_s32_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrmulshri.s32.e vr2, vr0, 1, 0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vrmulshri_s32_e, .-test_vrmulshri_s32_e

/* vrmulxaa.t.rs */
TEST_FUNC(test_vrmulxaa_s8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxaa.s8.rs  vr2, vr0, vr1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxaa_s8_rs, .-test_vrmulxaa_s8_rs

TEST_FUNC(test_vrmulxaa_s16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxaa.s16.rs vr2, vr0, vr1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxaa_s16_rs, .-test_vrmulxaa_s16_rs

TEST_FUNC(test_vrmulxaa_s32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxaa.s32.rs vr2, vr0, vr1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxaa_s32_rs, .-test_vrmulxaa_s32_rs

/* vrmulxaai.t.rs */
TEST_FUNC(test_vrmulxaai_s8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxaai.s8.rs vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxaai_s8_rs, .-test_vrmulxaai_s8_rs

TEST_FUNC(test_vrmulxaai_s16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxaai.s16.rs    vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxaai_s16_rs, .-test_vrmulxaai_s16_rs

TEST_FUNC(test_vrmulxaai_s32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxaai.s32.rs    vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxaai_s32_rs, .-test_vrmulxaai_s32_rs

/* vrmulxas.t.rs */
TEST_FUNC(test_vrmulxas_s8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxas.s8.rs  vr2, vr0, vr1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxas_s8_rs, .-test_vrmulxas_s8_rs

TEST_FUNC(test_vrmulxas_s16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxas.s16.rs vr2, vr0, vr1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxas_s16_rs, .-test_vrmulxas_s16_rs

TEST_FUNC(test_vrmulxas_s32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxas.s32.rs vr2, vr0, vr1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxas_s32_rs, .-test_vrmulxas_s32_rs

/* vrmulxasi.t.rs */
TEST_FUNC(test_vrmulxasi_s8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxasi.s8.rs vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxasi_s8_rs, .-test_vrmulxasi_s8_rs

TEST_FUNC(test_vrmulxasi_s16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxasi.s16.rs    vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxasi_s16_rs, .-test_vrmulxasi_s16_rs

TEST_FUNC(test_vrmulxasi_s32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxasi.s32.rs    vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxasi_s32_rs, .-test_vrmulxasi_s32_rs

/* vrmulxss.t.rs */
TEST_FUNC(test_vrmulxss_s8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxss.s8.rs  vr2, vr0, vr1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxss_s8_rs, .-test_vrmulxas_s8_rs

TEST_FUNC(test_vrmulxss_s16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxss.s16.rs vr2, vr0, vr1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxss_s16_rs, .-test_vrmulxas_s16_rs

TEST_FUNC(test_vrmulxss_s32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxss.s32.rs vr2, vr0, vr1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxss_s32_rs, .-test_vrmulxas_s32_rs

/* vrmulxssi.t.rs */
TEST_FUNC(test_vrmulxssi_s8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxssi.s8.rs vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxssi_s8_rs, .-test_vrmulxasi_s8_rs

TEST_FUNC(test_vrmulxssi_s16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxssi.s16.rs    vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxssi_s16_rs, .-test_vrmulxasi_s16_rs

TEST_FUNC(test_vrmulxssi_s32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxssi.s32.rs    vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxssi_s32_rs, .-test_vrmulxasi_s32_rs

/* vrmulxsa.t.rs */
TEST_FUNC(test_vrmulxsa_s8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxsa.s8.rs  vr2, vr0, vr1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxsa_s8_rs, .-test_vrmulxsa_s8_rs

TEST_FUNC(test_vrmulxsa_s16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxsa.s16.rs vr2, vr0, vr1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxsa_s16_rs, .-test_vrmulxsa_s16_rs

TEST_FUNC(test_vrmulxsa_s32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxsa.s32.rs vr2, vr0, vr1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxsa_s32_rs, .-test_vrmulxsa_s32_rs

/* vrmulxsai.t.rs */
TEST_FUNC(test_vrmulxsai_s8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxsai.s8.rs vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxsai_s8_rs, .-test_vrmulxsai_s8_rs

TEST_FUNC(test_vrmulxsai_s16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxsai.s16.rs    vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxsai_s16_rs, .-test_vrmulxsai_s16_rs

TEST_FUNC(test_vrmulxsai_s32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vrmulxsai.s32.rs    vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vrmulxsai_s32_rs, .-test_vrmulxsai_s32_rs

/* vrcmul.t.rs */
TEST_FUNC(test_vrcmul_s8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrcmul.s8.rs    vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrcmul_s8_rs, .-test_vrcmul_s8_rs

TEST_FUNC(test_vrcmul_s16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrcmul.s16.rs   vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrcmul_s16_rs, .-test_vrcmul_s16_rs

TEST_FUNC(test_vrcmul_s32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrcmul.s32.rs   vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrcmul_s32_rs, .-test_vrcmul_s32_rs

/* vrcmula.t.e */
TEST_FUNC(test_vrcmula_s8_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrcmula.s8.e    vr2, vr0, vr1, 1
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrcmula_s8_e, .-test_vrcmula_s8_e

TEST_FUNC(test_vrcmula_s16_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrcmula.s16.e   vr2, vr0, vr1, 1
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrcmula_s16_e, .-test_vrcmula_s16_e

TEST_FUNC(test_vrcmula_s32_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrcmula.s32.e   vr2, vr0, vr1, 1
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrcmula_s32_e, .-test_vrcmula_s32_e

/* vrcmulc.t.rs */
TEST_FUNC(test_vrcmulc_s8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrcmulc.s8.rs   vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrcmulc_s8_rs, .-test_vrcmulc_s8_rs

TEST_FUNC(test_vrcmulc_s16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrcmulc.s16.rs  vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrcmulc_s16_rs, .-test_vrcmulc_s16_rs

TEST_FUNC(test_vrcmulc_s32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrcmulc.s32.rs  vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrcmulc_s32_rs, .-test_vrcmulc_s32_rs

/* vrcmulca.t.e */
TEST_FUNC(test_vrcmulca_s8_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrcmulca.s8.e   vr2, vr0, vr1, 1
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrcmulca_s8_e, .-test_vrcmulca_s8_e

TEST_FUNC(test_vrcmulca_s16_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrcmulca.s16.e  vr2, vr0, vr1, 1
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrcmulca_s16_e, .-test_vrcmulca_s16_e

TEST_FUNC(test_vrcmulca_s32_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrcmulca.s32.e  vr2, vr0, vr1, 1
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrcmulca_s32_e, .-test_vrcmulca_s32_e

/* vrcmuln.t.rs */
TEST_FUNC(test_vrcmuln_s8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrcmuln.s8.rs   vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrcmuln_s8_rs, .-test_vrcmuln_s8_rs

TEST_FUNC(test_vrcmuln_s16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrcmuln.s16.rs  vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrcmuln_s16_rs, .-test_vrcmuln_s16_rs

TEST_FUNC(test_vrcmuln_s32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrcmuln.s32.rs  vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrcmuln_s32_rs, .-test_vrcmuln_s32_rs

/* vrcmulna.t.e */
TEST_FUNC(test_vrcmulna_s8_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrcmulna.s8.e   vr2, vr0, vr1, 1
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrcmulna_s8_e, .-test_vrcmulna_s8_e

TEST_FUNC(test_vrcmulna_s16_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrcmulna.s16.e  vr2, vr0, vr1, 1
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrcmulna_s16_e, .-test_vrcmulna_s16_e

TEST_FUNC(test_vrcmulna_s32_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrcmulna.s32.e  vr2, vr0, vr1, 1
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrcmulna_s32_e, .-test_vrcmulna_s32_e

/* vrcmulcn.t.rs */
TEST_FUNC(test_vrcmulcn_s8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrcmulcn.s8.rs  vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrcmulcn_s8_rs, .-test_vrcmulcn_s8_rs

TEST_FUNC(test_vrcmulcn_s16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrcmulcn.s16.rs vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrcmulcn_s16_rs, .-test_vrcmulcn_s16_rs

TEST_FUNC(test_vrcmulcn_s32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrcmulcn.s32.rs vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrcmulcn_s32_rs, .-test_vrcmulcn_s32_rs

/* vrcmulcna.t.e */
TEST_FUNC(test_vrcmulcna_s8_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrcmulcna.s8.e  vr2, vr0, vr1, 1
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrcmulcna_s8_e, .-test_vrcmulcna_s8_e

TEST_FUNC(test_vrcmulcna_s16_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrcmulcna.s16.e vr2, vr0, vr1, 1
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrcmulcna_s16_e, .-test_vrcmulcna_s16_e

TEST_FUNC(test_vrcmulcna_s32_e)
        movi            t0, 160
        movi            t1, 160
        addi            t1, 16
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t1
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vrcmulcna.s32.e vr2, vr0, vr1, 1
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vrcmulcna_s32_e, .-test_vrcmulcna_s32_e

/* vrecpe.t */
TEST_FUNC(test_vrecpe_s8)
        vldm.8          vr0-vr0, (a0)
        vrecpe.s8       vr1, vr0
        vstm.8          vr1-vr1, (a1)
        rts
        .size   test_vrecpe_s8, .-test_vrecpe_s8

TEST_FUNC(test_vrecpe_s16)
        vldm.16         vr0-vr0, (a0)
        vrecpe.s16      vr1, vr0
        vstm.16         vr1-vr1, (a1)
        rts
        .size   test_vrecpe_s16, .-test_vrecpe_s16

TEST_FUNC(test_vrecpe_s32)
        vldm.32         vr0-vr0, (a0)
        vrecpe.s32      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vrecpe_s32, .-test_vrecpe_s32

TEST_FUNC(test_vrecpe_u8)
        vldm.8          vr0-vr0, (a0)
        vrecpe.u8       vr1, vr0
        vstm.8          vr1-vr1, (a1)
        rts
        .size   test_vrecpe_u8, .-test_vrecpe_u8

TEST_FUNC(test_vrecpe_u16)
        vldm.16         vr0-vr0, (a0)
        vrecpe.u16      vr1, vr0
        vstm.16         vr1-vr1, (a1)
        rts
        .size   test_vrecpe_u16, .-test_vrecpe_u16

TEST_FUNC(test_vrecpe_u32)
        vldm.32         vr0-vr0, (a0)
        vrecpe.u32      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vrecpe_u32, .-test_vrecpe_u32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vrecpe_f32)
        vldm.32         vr0-vr0, (a0)
        vrecpe.f32      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vrecpe_f32, .-test_vrecpe_f32

TEST_FUNC(test_vrecpe_f16)
        vldm.32         vr0-vr0, (a0)
        vrecpe.f16      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vrecpe_f16, .-test_vrecpe_f16
#endif

/* vrecps.t */
TEST_FUNC(test_vrecps_s8)
        vldm.8          vr0-vr0, (a0)
        vldm.8          vr1-vr1, (a1)
        vrecps.s8       vr2, vr0, vr1
        vstm.8          vr2-vr2, (a2)
        rts
        .size   test_vrecps_s8, .-test_vrecps_s8

TEST_FUNC(test_vrecps_s16)
        vldm.16         vr0-vr0, (a0)
        vldm.16         vr1-vr1, (a1)
        vrecps.s16      vr2, vr0, vr1
        vstm.16         vr2-vr2, (a2)
        rts
        .size   test_vrecps_s16, .-test_vrecps_s16

TEST_FUNC(test_vrecps_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrecps.s32      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrecps_s32, .-test_vrecps_s32

TEST_FUNC(test_vrecps_u8)
        vldm.8          vr0-vr0, (a0)
        vldm.8          vr1-vr1, (a1)
        vrecps.u8       vr2, vr0, vr1
        vstm.8          vr2-vr2, (a2)
        rts
        .size   test_vrecps_u8, .-test_vrecps_u8

TEST_FUNC(test_vrecps_u16)
        vldm.16         vr0-vr0, (a0)
        vldm.16         vr1-vr1, (a1)
        vrecps.u16      vr2, vr0, vr1
        vstm.16         vr2-vr2, (a2)
        rts
        .size   test_vrecps_u16, .-test_vrecps_u16

TEST_FUNC(test_vrecps_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrecps.u32      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrecps_u32, .-test_vrecps_u32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vrecps_f32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrecps.f32      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrecps_f32, .-test_vrecps_f32

TEST_FUNC(test_vrecps_f16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrecps.f16      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrecps_f16, .-test_vrecps_f16
#endif

/* vrsqrte.t */
TEST_FUNC(test_vrsqrte_s8)
        vldm.8          vr0-vr0, (a0)
        vrsqrte.s8      vr1, vr0
        vstm.8          vr1-vr1, (a1)
        rts
        .size   test_vrsqrte_s8, .-test_vrsqrte_s8

TEST_FUNC(test_vrsqrte_s16)
        vldm.16         vr0-vr0, (a0)
        vrsqrte.s16     vr1, vr0
        vstm.16         vr1-vr1, (a1)
        rts
        .size   test_vrsqrte_s16, .-test_vrsqrte_s16

TEST_FUNC(test_vrsqrte_s32)
        vldm.32         vr0-vr0, (a0)
        vrsqrte.s32     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vrsqrte_s32, .-test_vrsqrte_s32

TEST_FUNC(test_vrsqrte_u8)
        vldm.8          vr0-vr0, (a0)
        vrsqrte.u8      vr1, vr0
        vstm.8          vr1-vr1, (a1)
        rts
        .size   test_vrsqrte_u8, .-test_vrsqrte_u8

TEST_FUNC(test_vrsqrte_u16)
        vldm.16         vr0-vr0, (a0)
        vrsqrte.u16     vr1, vr0
        vstm.16         vr1-vr1, (a1)
        rts
        .size   test_vrsqrte_u16, .-test_vrsqrte_u16

TEST_FUNC(test_vrsqrte_u32)
        vldm.32         vr0-vr0, (a0)
        vrsqrte.u32     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vrsqrte_u32, .-test_vrsqrte_u32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vrsqrte_f32)
        vldm.32         vr0-vr0, (a0)
        vrsqrte.f32     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vrsqrte_f32, .-test_vrsqrte_f32

TEST_FUNC(test_vrsqrte_f16)
        vldm.32         vr0-vr0, (a0)
        vrsqrte.f16     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vrsqrte_f16, .-test_vrsqrte_f16
#endif

/* vrsqrts.t */
TEST_FUNC(test_vrsqrts_s8)
        vldm.8          vr0-vr0, (a0)
        vldm.8          vr1-vr1, (a1)
        vrsqrts.s8      vr2, vr0, vr1
        vstm.8          vr2-vr2, (a2)
        rts
        .size   test_vrsqrts_s8, .-test_vrsqrts_s8

TEST_FUNC(test_vrsqrts_s16)
        vldm.16         vr0-vr0, (a0)
        vldm.16         vr1-vr1, (a1)
        vrsqrts.s16     vr2, vr0, vr1
        vstm.16         vr2-vr2, (a2)
        rts
        .size   test_vrsqrts_s16, .-test_vrsqrts_s16

TEST_FUNC(test_vrsqrts_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrsqrts.s32     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrsqrts_s32, .-test_vrsqrts_s32

TEST_FUNC(test_vrsqrts_u8)
        vldm.8          vr0-vr0, (a0)
        vldm.8          vr1-vr1, (a1)
        vrsqrts.u8      vr2, vr0, vr1
        vstm.8          vr2-vr2, (a2)
        rts
        .size   test_vrsqrts_u8, .-test_vrsqrts_u8

TEST_FUNC(test_vrsqrts_u16)
        vldm.16         vr0-vr0, (a0)
        vldm.16         vr1-vr1, (a1)
        vrsqrts.u16     vr2, vr0, vr1
        vstm.16         vr2-vr2, (a2)
        rts
        .size   test_vrsqrts_u16, .-test_vrsqrts_u16

TEST_FUNC(test_vrsqrts_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrsqrts.u32     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrsqrts_u32, .-test_vrsqrts_u32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vrsqrts_f32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrsqrts.f32     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrsqrts_f32, .-test_vrsqrts_f32

TEST_FUNC(test_vrsqrts_f16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrsqrts.f16     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vrsqrts_f16, .-test_vrsqrts_f16
#endif

/* vexpe.t */
TEST_FUNC(test_vexpe_s8)
        vldm.8          vr0-vr0, (a0)
        vexpe.s8        vr1, vr0
        vstm.8          vr1-vr1, (a1)
        rts
        .size   test_vexpe_s8, .-test_vexpe_s8

TEST_FUNC(test_vexpe_s16)
        vldm.16         vr0-vr0, (a0)
        vexpe.s16       vr1, vr0
        vstm.16         vr1-vr1, (a1)
        rts
        .size   test_vexpe_s16, .-test_vexpe_s16

TEST_FUNC(test_vexpe_s32)
        vldm.32         vr0-vr0, (a0)
        vexpe.s32       vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vexpe_s32, .-test_vexpe_s32

TEST_FUNC(test_vexpe_u8)
        vldm.8          vr0-vr0, (a0)
        vexpe.u8        vr1, vr0
        vstm.8          vr1-vr1, (a1)
        rts
        .size   test_vexpe_u8, .-test_vexpe_u8

TEST_FUNC(test_vexpe_u16)
        vldm.16         vr0-vr0, (a0)
        vexpe.u16       vr1, vr0
        vstm.16         vr1-vr1, (a1)
        rts
        .size   test_vexpe_u16, .-test_vexpe_u16

TEST_FUNC(test_vexpe_u32)
        vldm.32         vr0-vr0, (a0)
        vexpe.u32       vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vexpe_u32, .-test_vexpe_u32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vexpe_f32)
        vldm.32         vr0-vr0, (a0)
        vexpe.f32       vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vexpe_f32, .-test_vexpe_f32

TEST_FUNC(test_vexpe_f16)
        vldm.32         vr0-vr0, (a0)
        vexpe.f16       vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vexpe_f16, .-test_vexpe_f16
#endif

/* vfmula.t */
#ifdef VDSP_FLOAT
TEST_FUNC(test_vfmula_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmula.f32      vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmula_f32, .-test_vfmula_f32

TEST_FUNC(test_vfmula_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmula.f16      vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmula_f16, .-test_vfmula_f16

/* vfmuls.t */
TEST_FUNC(test_vfmuls_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmuls.f32      vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmuls_f32, .-test_vfmuls_f32

TEST_FUNC(test_vfmuls_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmuls.f16      vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmuls_f16, .-test_vfmuls_f16

/* vfnmula.t */
TEST_FUNC(test_vfnmula_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfnmula.f32     vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfnmula_f32, .-test_vfnmula_f32

TEST_FUNC(test_vfnmula_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfnmula.f16     vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfnmula_f16, .-test_vfnmula_f16

/* vfnmuls.t */
TEST_FUNC(test_vfnmuls_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfnmuls.f32     vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfnmuls_f32, .-test_vfnmuls_f32

TEST_FUNC(test_vfnmuls_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfnmuls.f16     vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfnmuls_f16, .-test_vfnmuls_f16

TEST_FUNC(test_vfmula_f16_e)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmula.f16.e    vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmula_f16_e, .-test_vfmula_f16_e

TEST_FUNC(test_vfmulai_f16_e)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmulai.f16.e   vr2, vr0, vr1, 0
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmulai_f16_e, .-test_vfmulai_f16_e

TEST_FUNC(test_vfmuls_f16_e)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmuls.f16.e    vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmuls_f16_e, .-test_vfmuls_f16_e

TEST_FUNC(test_vfmulsi_f16_e)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmulsi.f16.e   vr2, vr0, vr1, 0
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmulsi_f16_e, .-test_vfmulsi_f16_e

TEST_FUNC(test_vfmulxaa_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmulxaa.f32    vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmulxaa_f32, .-test_vfmulxaa_f32

TEST_FUNC(test_vfmulxaa_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmulxaa.f16    vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmulxaa_f16, .-test_vfmulxaa_f16

TEST_FUNC(test_vfmulxaai_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmulxaai.f32   vr2, vr0, vr1, 0
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmulxaai_f32, .-test_vfmulxaai_f32

TEST_FUNC(test_vfmulxaai_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmulxaai.f16   vr2, vr0, vr1, 0
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmulxaai_f16, .-test_vfmulxaai_f16

TEST_FUNC(test_vfmulxas_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmulxas.f32    vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmulxas_f32, .-test_vfmulxas_f32

TEST_FUNC(test_vfmulxas_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmulxas.f16    vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmulxas_f16, .-test_vfmulxas_f16

TEST_FUNC(test_vfmulxasi_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmulxasi.f32   vr2, vr0, vr1, 0
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmulxasi_f32, .-test_vfmulxasi_f32

TEST_FUNC(test_vfmulxasi_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmulxasi.f16   vr2, vr0, vr1, 0
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmulxasi_f16, .-test_vfmulxasi_f16

TEST_FUNC(test_vfmulxss_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmulxss.f32    vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmulxss_f32, .-test_vfmulxss_f32

TEST_FUNC(test_vfmulxss_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmulxss.f16    vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmulxss_f16, .-test_vfmulxss_f16

TEST_FUNC(test_vfmulxssi_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmulxssi.f32   vr2, vr0, vr1, 0
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmulxssi_f32, .-test_vfmulxssi_f32

TEST_FUNC(test_vfmulxssi_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmulxssi.f16   vr2, vr0, vr1, 0
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmulxssi_f16, .-test_vfmulxssi_f16

TEST_FUNC(test_vfmulxsa_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmulxsa.f32    vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmulxsa_f32, .-test_vfmulxsa_f32

TEST_FUNC(test_vfmulxsa_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmulxsa.f16    vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmulxsa_f16, .-test_vfmulxsa_f16

TEST_FUNC(test_vfmulxsai_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmulxsai.f32   vr2, vr0, vr1, 0
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmulxsai_f32, .-test_vfmulxsai_f32

TEST_FUNC(test_vfmulxsai_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfmulxsai.f16   vr2, vr0, vr1, 0
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfmulxsai_f16, .-test_vfmulxsai_f16

TEST_FUNC(test_vfcmul_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vfcmul.f32      vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfcmul_f32, .-test_vfcmul_f32

TEST_FUNC(test_vfcmul_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfcmul.f16      vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfcmul_f16, .-test_vfcmul_f16

TEST_FUNC(test_vfcmula_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfcmula.f32     vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfcmula_f32, .-test_vfcmula_f32

TEST_FUNC(test_vfcmula_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfcmula.f16     vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfcmula_f16, .-test_vfcmula_f16

TEST_FUNC(test_vfcmulc_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfcmulc.f32     vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfcmulc_f32, .-test_vfcmulc_f32

TEST_FUNC(test_vfcmulc_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfcmulc.f16     vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfcmulc_f16, .-test_vfcmulc_f16

TEST_FUNC(test_vfcmulca_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfcmulca.f32    vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfcmulca_f32, .-test_vfcmulca_f32

TEST_FUNC(test_vfcmulca_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfcmulca.f16    vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfcmulca_f16, .-test_vfcmulca_f16

TEST_FUNC(test_vfcmuln_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfcmuln.f32     vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfcmuln_f32, .-test_vfcmuln_f32

TEST_FUNC(test_vfcmuln_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfcmuln.f16     vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfcmuln_f16, .-test_vfcmuln_f16

TEST_FUNC(test_vfcmulna_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfcmulna.f32    vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfcmulna_f32, .-test_vfcmulna_f32

TEST_FUNC(test_vfcmulna_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfcmulna.f16    vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfcmulna_f16, .-test_vfcmulna_f16

TEST_FUNC(test_vfcmulcn_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfcmulcn.f32    vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfcmulcn_f32, .-test_vfcmulcn_f32

TEST_FUNC(test_vfcmulcn_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfcmulcn.f16    vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfcmulcn_f16, .-test_vfcmulcn_f16

TEST_FUNC(test_vfcmulcna_f32)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfcmulcna.f32   vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfcmulcna_f32, .-test_vfcmulcna_f32

TEST_FUNC(test_vfcmulcna_f16)
   vldm.32         vr0-vr0, (a0)
   vldm.32         vr1-vr1, (a1)
   vldm.32         vr2-vr2, (a2)
   vfcmulcna.f16   vr2, vr0, vr1
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vfcmulcna_f16, .-test_vfcmulcna_f16

TEST_FUNC(test_vhtos_f16)
   vldm.32         vr0-vr0, (a0)
   vhtos.f16       vr1, vr0
   vstm.32         vr1-vr1, (a1)
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vhtos_f16, .-test_vhtos_f16

TEST_FUNC(test_vstoh_f32)
   vldm.32         vr0-vr0, (a0)
   vstoh.f32       vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vstoh_f32, .-test_vstoh_f32

TEST_FUNC(test_vdtos_f64)
   vldm.32         vr0-vr0, (a0)
   vdtos.f64       vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vdtos_f64, .-test_vdtos_f64

TEST_FUNC(test_vftox_f16_s16)
    mfcr            t0, cr<1, 2>
    movi            t1, 4
    mov             t2, t0
    ins             t0, t1, 19, 16
    mtcr            t0, cr<1, 2>
    vldm.32         vr0-vr0, (a0)
    vftox.f16.s16   vr1, vr0
    vstm.32         vr1-vr1, (a1)
    mtcr            t2, cr<1, 2>
    rts
    .size   test_vftox_f16_s16, .-test_vftox_f16_s16

TEST_FUNC(test_vftox_f16_u16)
    mfcr            t0, cr<1, 2>
    movi            t1, 4
    mov             t2, t0
    ins             t0, t1, 19, 16
    mtcr            t0, cr<1, 2>
    vldm.32         vr0-vr0, (a0)
    vftox.f16.u16   vr1, vr0
    vstm.32         vr1-vr1, (a1)
    mtcr            t2, cr<1, 2>
    rts
    .size   test_vftox_f16_u16, .-test_vftox_f16_u16

TEST_FUNC(test_vftox_f32_s32)
    mfcr            t0, cr<1, 2>
    movi            t1, 4
    mov             t2, t0
    ins             t0, t1, 20, 16
    mtcr            t0, cr<1, 2>
    vldm.32         vr0-vr0, (a0)
    vftox.f32.s32   vr1, vr0
    vstm.32         vr1-vr1, (a1)
    mtcr            t2, cr<1, 2>
    rts
    .size   test_vftox_f32_s32, .-test_vftox_f32_s32

TEST_FUNC(test_vftox_f32_u32)
    mfcr            t0, cr<1, 2>
    movi            t1, 4
    mov             t2, t0
    ins             t0, t1, 20, 16
    mtcr            t0, cr<1, 2>
    vldm.32         vr0-vr0, (a0)
    vftox.f32.u32   vr1, vr0
    vstm.32         vr1-vr1, (a1)
    mtcr            t2, cr<1, 2>
    rts
    .size   test_vftox_f32_u32, .-test_vftox_f32_u32

TEST_FUNC(test_vftox_f16_s32)
    mfcr            t0, cr<1, 2>
    movi            t1, 4
    mov             t2, t0
    ins             t0, t1, 20, 16
    mtcr            t0, cr<1, 2>
    vldm.32         vr0-vr0, (a0)
    vftox.f16.s32   vr1, vr0
    vstm.32         vr1-vr1, (a1)
    vstm.32         vr2-vr2, (a2)
    mtcr            t2, cr<1, 2>
    rts
    .size   test_vftox_f16_s32, .-test_vftox_f16_s32

TEST_FUNC(test_vftox_f16_u32)
    mfcr            t0, cr<1, 2>
    movi            t1, 4
    mov             t2, t0
    ins             t0, t1, 20, 16
    mtcr            t0, cr<1, 2>
    vldm.32         vr0-vr0, (a0)
    vftox.f16.u32   vr1, vr0
    vstm.32         vr1-vr1, (a1)
    vstm.32         vr2-vr2, (a2)
    mtcr            t2, cr<1, 2>
    rts
    .size   test_vftox_f16_u32, .-test_vftox_f16_u32

TEST_FUNC(test_vftox_f32_s16)
    mfcr            t0, cr<1, 2>
    movi            t1, 4
    mov             t2, t0
    ins             t0, t1, 19, 16
    mtcr            t0, cr<1, 2>
    vldm.32         vr0-vr0, (a0)
    vftox.f32.s16   vr1, vr0
    vstm.32         vr1-vr1, (a1)
    mtcr            t2, cr<1, 2>
    rts
    .size   test_vftox_f32_s16, .-test_vftox_f32_s16

TEST_FUNC(test_vftox_f32_u16)
    mfcr            t0, cr<1, 2>
    movi            t1, 4
    mov             t2, t0
    ins             t0, t1, 19, 16
    mtcr            t0, cr<1, 2>
    vldm.32         vr0-vr0, (a0)
    vftox.f32.u16   vr1, vr0
    vstm.32         vr1-vr1, (a1)
    mtcr            t2, cr<1, 2>
    rts
    .size   test_vftox_f32_u16, .-test_vftox_f32_u16

TEST_FUNC(test_vxtof_s16_f16)
    mfcr            t0, cr<1, 2>
    movi            t1, 4
    mov             t2, t0
    ins             t0, t1, 19, 16
    mtcr            t0, cr<1, 2>
    vldm.32         vr0-vr0, (a0)
    vxtof.s16.f16   vr1, vr0
    vstm.32         vr1-vr1, (a1)
    mtcr            t2, cr<1, 2>
    rts
    .size   test_vxtof_s16_f16, .-test_vxtof_s16_f16

TEST_FUNC(test_vxtof_u16_f16)
    mfcr            t0, cr<1, 2>
    movi            t1, 4
    mov             t2, t0
    ins             t0, t1, 19, 16
    mtcr            t0, cr<1, 2>
    vldm.32         vr0-vr0, (a0)
    vxtof.u16.f16   vr1, vr0
    vstm.32         vr1-vr1, (a1)
    mtcr            t2, cr<1, 2>
    rts
    .size   test_vxtof_u16_f16, .-test_vxtof_u16_f16

TEST_FUNC(test_vxtof_s32_f32)
    mfcr            t0, cr<1, 2>
    movi            t1, 4
    mov             t2, t0
    ins             t0, t1, 20, 16
    mtcr            t0, cr<1, 2>
    vldm.32         vr0-vr0, (a0)
    vxtof.s32.f32   vr1, vr0
    vstm.32         vr1-vr1, (a1)
    mtcr            t2, cr<1, 2>
    rts
    .size   test_vxtof_s32_f32, .-test_vxtof_s32_f32

TEST_FUNC(test_vxtof_u32_f32)
    mfcr            t0, cr<1, 2>
    movi            t1, 4
    mov             t2, t0
    ins             t0, t1, 20, 16
    mtcr            t0, cr<1, 2>
    vldm.32         vr0-vr0, (a0)
    vxtof.u32.f32   vr1, vr0
    vstm.32         vr1-vr1, (a1)
    mtcr            t2, cr<1, 2>
    rts
    .size   test_vxtof_u32_f32, .-test_vxtof_u32_f32

TEST_FUNC(test_vxtof_s16_f32)
    mfcr            t0, cr<1, 2>
    movi            t1, 4
    mov             t2, t0
    ins             t0, t1, 19, 16
    mtcr            t0, cr<1, 2>
    vldm.32         vr0-vr0, (a0)
    vxtof.s16.f32   vr1, vr0
    vstm.32         vr1-vr1, (a1)
    vstm.32         vr2-vr2, (a2)
    mtcr            t2, cr<1, 2>
    rts
    .size   test_vxtof_s16_f32, .-test_vxtof_s16_f32

TEST_FUNC(test_vxtof_u16_f32)
    mfcr            t0, cr<1, 2>
    movi            t1, 4
    mov             t2, t0
    ins             t0, t1, 19, 16
    mtcr            t0, cr<1, 2>
    vldm.32         vr0-vr0, (a0)
    vxtof.u16.f32   vr1, vr0
    vstm.32         vr1-vr1, (a1)
    vstm.32         vr2-vr2, (a2)
    mtcr            t2, cr<1, 2>
    rts
    .size   test_vxtof_u16_f32, .-test_vxtof_u16_f32

TEST_FUNC(test_vxtof_s32_f16)
    mfcr            t0, cr<1, 2>
    movi            t1, 4
    mov             t2, t0
    ins             t0, t1, 20, 16
    mtcr            t0, cr<1, 2>
    vldm.32         vr0-vr0, (a0)
    vxtof.s32.f16   vr1, vr0
    vstm.32         vr1-vr1, (a1)
    mtcr            t2, cr<1, 2>
    rts
    .size   test_vxtof_s32_f16, .-test_vxtof_s32_f16

TEST_FUNC(test_vxtof_u32_f16)
    mfcr            t0, cr<1, 2>
    movi            t1, 4
    mov             t2, t0
    ins             t0, t1, 20, 16
    mtcr            t0, cr<1, 2>
    vldm.32         vr0-vr0, (a0)
    vxtof.u32.f16   vr1, vr0
    vstm.32         vr1-vr1, (a1)
    mtcr            t2, cr<1, 2>
    rts
    .size   test_vxtof_u32_f16, .-test_vxtof_u32_f16


TEST_FUNC(test_vftoi_f16_s16)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.s16   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f16_s16, .-test_vftoi_f16_s16

TEST_FUNC(test_vftoi_f16_u16)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.u16   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f16_u16, .-test_vftoi_f16_u16

TEST_FUNC(test_vftoi_f32_s32)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.s32   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_s32, .-test_vftoi_f32_s32

TEST_FUNC(test_vftoi_f32_u32)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.u32   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_u32, .-test_vftoi_f32_u32

TEST_FUNC(test_vftoi_f16_s32)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.s32   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vftoi_f16_s32, .-test_vftoi_f16_s32

TEST_FUNC(test_vftoi_f16_u32)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.u32   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vftoi_f16_u32, .-test_vftoi_f16_u32

TEST_FUNC(test_vftoi_f32_s16)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.s16   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_s16, .-test_vftoi_f32_s16

TEST_FUNC(test_vftoi_f32_u16)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.u16   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_u16, .-test_vftoi_f32_u16


TEST_FUNC(test_vftoi_f16_s16_rn)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.s16.rn   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f16_s16_rn, .-test_vftoi_f16_s16_rn

TEST_FUNC(test_vftoi_f16_u16_rn)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.u16.rn   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f16_u16_rn, .-test_vftoi_f16_u16_rn

TEST_FUNC(test_vftoi_f32_s32_rn)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.s32.rn   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_s32_rn, .-test_vftoi_f32_s32_rn

TEST_FUNC(test_vftoi_f32_u32_rn)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.u32.rn   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_u32_rn, .-test_vftoi_f32_u32_rn

TEST_FUNC(test_vftoi_f16_s32_rn)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.s32.rn   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vftoi_f16_s32_rn, .-test_vftoi_f16_s32_rn

TEST_FUNC(test_vftoi_f16_u32_rn)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.u32.rn   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vftoi_f16_u32_rn, .-test_vftoi_f16_u32_rn

TEST_FUNC(test_vftoi_f32_s16_rn)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.s16.rn   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_s16_rn, .-test_vftoi_f32_s16_rn

TEST_FUNC(test_vftoi_f32_u16_rn)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.u16.rn   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_u16_rn, .-test_vftoi_f32_u16_rn

TEST_FUNC(test_vftofi_f32_rn)
   vldm.32         vr0-vr0, (a0)
   vftofi.f32.rn   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftofi_f32_rn, .-test_vftofi_f32_rn

TEST_FUNC(test_vftofi_f16_rn)
   vldm.32         vr0-vr0, (a0)
   vftofi.f16.rn   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftofi_f16_rn, .-test_vftofi_f16_rn

TEST_FUNC(test_vftoi_f16_s16_rz)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.s16.rz   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f16_s16_rz, .-test_vftoi_f16_s16_rz

TEST_FUNC(test_vftoi_f16_u16_rz)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.u16.rz   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f16_u16_rz, .-test_vftoi_f16_u16_rz

TEST_FUNC(test_vftoi_f32_s32_rz)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.s32.rz   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_s32_rz, .-test_vftoi_f32_s32_rz

TEST_FUNC(test_vftoi_f32_u32_rz)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.u32.rz   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_u32_rz, .-test_vftoi_f32_u32_rz

TEST_FUNC(test_vftoi_f16_s32_rz)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.s32.rz   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vftoi_f16_s32_rz, .-test_vftoi_f16_s32_rz

TEST_FUNC(test_vftoi_f16_u32_rz)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.u32.rz   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vftoi_f16_u32_rz, .-test_vftoi_f16_u32_rz

TEST_FUNC(test_vftoi_f32_s16_rz)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.s16.rz   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_s16_rz, .-test_vftoi_f32_s16_rz

TEST_FUNC(test_vftoi_f32_u16_rz)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.u16.rz   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_u16_rz, .-test_vftoi_f32_u16_rz

TEST_FUNC(test_vftofi_f16_rz)
   vldm.32         vr0-vr0, (a0)
   vftofi.f16.rz   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftofi_f16_rz, .-test_vftofi_f16_rz

TEST_FUNC(test_vftofi_f32_rz)
   vldm.32         vr0-vr0, (a0)
   vftofi.f32.rz   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftofi_f32_rz, .-test_vftofi_f32_rz


TEST_FUNC(test_vftoi_f16_s16_rni)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.s16.rni   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f16_s16_rni, .-test_vftoi_f16_s16_rni

TEST_FUNC(test_vftoi_f16_u16_rni)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.u16.rni   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f16_u16_rni, .-test_vftoi_f16_u16_rni

TEST_FUNC(test_vftoi_f32_s32_rni)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.s32.rni   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_s32_rni, .-test_vftoi_f32_s32_rni

TEST_FUNC(test_vftoi_f32_u32_rni)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.u32.rni   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_u32_rni, .-test_vftoi_f32_u32_rni

TEST_FUNC(test_vftoi_f16_s32_rni)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.s32.rni   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vftoi_f16_s32_rni, .-test_vftoi_f16_s32_rni

TEST_FUNC(test_vftoi_f16_u32_rni)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.u32.rni   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vftoi_f16_u32_rni, .-test_vftoi_f16_u32_rni

TEST_FUNC(test_vftoi_f32_s16_rni)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.s16.rni   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_s16_rni, .-test_vftoi_f32_s16_rni

TEST_FUNC(test_vftoi_f32_u16_rni)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.u16.rni   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_u16_rni, .-test_vftoi_f32_u16_rni

TEST_FUNC(test_vftofi_f16_rni)
   vldm.32         vr0-vr0, (a0)
   vftofi.f16.rni   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftofi_f16_rni, .-test_vftofi_f16_rni

TEST_FUNC(test_vftofi_f32_rni)
   vldm.32         vr0-vr0, (a0)
   vftofi.f32.rni   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftofi_f32_rni, .-test_vftofi_f32_rni

TEST_FUNC(test_vftoi_f16_s16_rpi)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.s16.rpi   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f16_s16_rpi, .-test_vftoi_f16_s16_rpi

TEST_FUNC(test_vftoi_f16_u16_rpi)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.u16.rpi   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f16_u16_rpi, .-test_vftoi_f16_u16_rpi

TEST_FUNC(test_vftoi_f32_s32_rpi)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.s32.rpi   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_s32_rpi, .-test_vftoi_f32_s32_rpi

TEST_FUNC(test_vftoi_f32_u32_rpi)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.u32.rpi   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_u32_rpi, .-test_vftoi_f32_u32_rpi

TEST_FUNC(test_vftoi_f16_s32_rpi)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.s32.rpi   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vftoi_f16_s32_rpi, .-test_vftoi_f16_s32_rpi

TEST_FUNC(test_vftoi_f16_u32_rpi)
   vldm.32         vr0-vr0, (a0)
   vftoi.f16.u32.rpi   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vftoi_f16_u32_rpi, .-test_vftoi_f16_u32_rpi

TEST_FUNC(test_vftoi_f32_s16_rpi)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.s16.rpi   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_s16_rpi, .-test_vftoi_f32_s16_rpi

TEST_FUNC(test_vftoi_f32_u16_rpi)
   vldm.32         vr0-vr0, (a0)
   vftoi.f32.u16.rpi   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftoi_f32_u16_rpi, .-test_vftoi_f32_u16_rpi

TEST_FUNC(test_vftofi_f16_rpi)
   vldm.32         vr0-vr0, (a0)
   vftofi.f16.rpi   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftofi_f16_rpi, .-test_vftofi_f16_rpi

TEST_FUNC(test_vftofi_f32_rpi)
   vldm.32         vr0-vr0, (a0)
   vftofi.f32.rpi   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vftofi_f32_rpi, .-test_vftofi_f32_rpi

TEST_FUNC(test_vitof_s16_f16)
   vldm.32         vr0-vr0, (a0)
   vitof.s16.f16   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vitof_s16_f16, .-test_vitof_s16_f16

TEST_FUNC(test_vitof_u16_f16)
   vldm.32         vr0-vr0, (a0)
   vitof.u16.f16   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vitof_u16_f16, .-test_vitof_u16_f16

TEST_FUNC(test_vitof_s32_f32)
   vldm.32         vr0-vr0, (a0)
   vitof.s32.f32   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vitof_s32_f32, .-test_vitof_s32_f32

TEST_FUNC(test_vitof_u32_f32)
   vldm.32         vr0-vr0, (a0)
   vitof.u32.f32   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vitof_u32_f32, .-test_vitof_u32_f32

TEST_FUNC(test_vitof_s16_f32)
   vldm.32         vr0-vr0, (a0)
   vitof.s16.f32   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vitof_s16_f32, .-test_vitof_s16_f32

TEST_FUNC(test_vitof_u16_f32)
   vldm.32         vr0-vr0, (a0)
   vitof.u16.f32   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   vstm.32         vr2-vr2, (a2)
   rts
   .size   test_vitof_u16_f32, .-test_vitof_u16_f32

TEST_FUNC(test_vitof_s32_f16)
   vldm.32         vr0-vr0, (a0)
   vitof.s32.f16   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vitof_s32_f16, .-test_vitof_s32_f16

TEST_FUNC(test_vitof_u32_f16)
   vldm.32         vr0-vr0, (a0)
   vitof.u32.f16   vr1, vr0
   vstm.32         vr1-vr1, (a1)
   rts
   .size   test_vitof_u32_f16, .-test_vitof_u32_f16

#endif

/* vswp */
TEST_FUNC(test_vswp_8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vswp.8          vr1, vr0
        vstm.32         vr0-vr0, (a2)
        vstm.32         vr1-vr1, (a3)
        rts
        .size   test_vswp_8, .-test_vswp_8

TEST_FUNC(test_vswp_16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vswp.16         vr1, vr0
        vstm.32         vr0-vr0, (a2)
        vstm.32         vr1-vr1, (a3)
        rts
        .size   test_vswp_16, .-test_vswp_16

TEST_FUNC(test_vswp_32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vswp.32         vr1, vr0
        vstm.32         vr0-vr0, (a2)
        vstm.32         vr1-vr1, (a3)
        rts
        .size   test_vswp_32, .-test_vswp_32

TEST_FUNC(test_vswp_64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vswp.64         vr1, vr0
        vstm.32         vr0-vr0, (a2)
        vstm.32         vr1-vr1, (a3)
        rts
        .size   test_vswp_64, .-test_vswp_64

/* vrevq/h/w/d */
TEST_FUNC(test_vrevq)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrevq           vr1, vr0
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vrevq, .-test_vrevq

TEST_FUNC(test_vrevh)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrevh           vr1, vr0
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vrevh, .-test_vrevh

TEST_FUNC(test_vrevw)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrevw           vr1, vr0
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vrevw, .-test_vrevw

TEST_FUNC(test_vrevd)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vrevd           vr1, vr0
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vrevd, .-test_vrevd

/* vexti.t */
TEST_FUNC(test_vexti_0x0)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vexti.8         vr2, vr0, vr1, 0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vexti_0x0, .-test_vexti_0x0

TEST_FUNC(test_vexti_0x21)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vexti.8         vr2, vr0, vr1, 0x21
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vexti_0x21, .-test_vexti_0x21

TEST_FUNC(test_vexti_0x16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vexti.8         vr2, vr0, vr1, 0x16
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vexti_0x16, .-test_vexti_0x16

TEST_FUNC(test_vexti_0x3e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vexti.8         vr2, vr0, vr1, 0x3e
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vexti_0x3e, .-test_vexti_0x3e

/* vext.t */
TEST_FUNC(test_vext)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vext.8          vr2, vr0, vr1, a2
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vext, .-test_vext

/* vtbl.t */
TEST_FUNC(test_vtbl_8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vtbl.8          vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vtbl_8, .-test_vtbl_8

/* vtbx.t */
TEST_FUNC(test_vtbx_8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vtbx.8          vr2, vr0, vr1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vtbx_8, .-test_vtbx_8

/* vmovi.t */
TEST_FUNC(test_vmovi_8)
        vmovi.8         vr0, 0xff
        vstm.32         vr0-vr0, (a0)
        rts
        .size   test_vmovi_8, .-test_vmovi_8

TEST_FUNC(test_vmovi_s16)
        vmovi.s16       vr0, 0x80, 1
        vstm.32         vr0-vr0, (a0)
        rts
        .size   test_vmovi_s16, .-test_vmovi_s16

TEST_FUNC(test_vmovi_s32)
        vmovi.s32       vr0, 0x12, 3
        vstm.32         vr0-vr0, (a0)
        rts
        .size   test_vmovi_s32, .-test_vmovi_s32

TEST_FUNC(test_vmovi_u16)
        vmovi.u16       vr0, 0x80, 0
        vstm.32         vr0-vr0, (a0)
        rts
        .size   test_vmovi_u16, .-test_vmovi_u16

TEST_FUNC(test_vmovi_u32)
        vmovi.u32       vr0, 0x12, 0
        vstm.32         vr0-vr0, (a0)
        rts
        .size   test_vmovi_u32, .-test_vmovi_u32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vmovi_f32)
        vmovi.f32       vr0, -1.5
        vstm.32         vr0-vr0, (a0)
        rts
        .size   test_vmovi_f32, .-test_vmovi_f32

TEST_FUNC(test_vmovi_f16)
        vmovi.f16       vr0, -1.5
        vstm.32         vr0-vr0, (a0)
        rts
        .size   test_vmovi_f16, .-test_vmovi_f16
#endif

/* vmaski.t */
TEST_FUNC(test_vmaski_8_l)
        vlrw.32.4       vr0, 0x12345678_12345678_12345678_12345678
        vmaski.8.l      vr0, 0x72
        vstm.32         vr0-vr0, (a0)
        rts
        .size   test_vmaski_8_l, .-test_vmaski_8_l

TEST_FUNC(test_vmaski_8_h)
        vlrw.32.4       vr0, 0x12345678_12345678_12345678_12345678
        vmaski.8.h      vr0, 0x0c
        vstm.32         vr0-vr0, (a0)
        rts
        .size   test_vmaski_8_h, .-test_vmaski_8_h

TEST_FUNC(test_vmaski_16)
        vmaski.16       vr0, 0xaa
        vstm.32         vr0-vr0, (a0)
        rts
        .size   test_vmaski_16, .-test_vmaski_16

/* vdupg */
TEST_FUNC(test_vdupg_8)
        vdupg.8         vr0, a0
        vstm.32         vr0-vr0, (a1)
        rts
        .size   test_vdupg_8, .-test_vdupg_8

TEST_FUNC(test_vdupg_16)
        vdupg.16        vr0, a0
        vstm.32         vr0-vr0, (a1)
        rts
        .size   test_vdupg_16, .-test_vdupg_16

TEST_FUNC(test_vdupg_32)
        vdupg.32        vr0, a0
        vstm.32         vr0-vr0, (a1)
        rts
        .size   test_vdupg_32, .-test_vdupg_32

/* vdup.t.1 */
TEST_FUNC(test_vdup_8_1)
        vldm.32         vr0-vr0, (a0)
        vdup.8.1        vr1, vr0, 0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vdup_8_1, .-test_vdup_8_1

TEST_FUNC(test_vdup_16_1)
        vldm.32         vr0-vr0, (a0)
        vdup.16.1       vr1, vr0, 0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vdup_16_1, .-test_vdup_16_1

TEST_FUNC(test_vdup_32_1)
        vldm.32         vr0-vr0, (a0)
        vdup.32.1       vr1, vr0, 0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vdup_32_1, .-test_vdup_32_1

/* vdup.t.2 */
TEST_FUNC(test_vdup_8_2)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vdup.8.2        vr1, vr0, 0
        vstm.32         vr1-vr1, (a2)
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vdup_8_2, .-test_vdup_8_2

TEST_FUNC(test_vdup_16_2)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vdup.16.2       vr1, vr0, 0
        vstm.32         vr1-vr1, (a2)
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vdup_16_2, .-test_vdup_16_2

TEST_FUNC(test_vdup_32_2)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vdup.32.2       vr1, vr0, 0
        vstm.32         vr1-vr1, (a2)
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vdup_32_2, .-test_vdup_32_2

/* vdup.t.3 */
TEST_FUNC(test_vdup_8_3)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vdup.8.3        vr1, vr0, 0
        vstru.32.4      vr1, (a2), a3
        vstru.32.4      vr2, (a2), a3
        vstru.32.4      vr3, (a2), a3
        rts
        .size   test_vdup_8_3, .-test_vdup_8_3

TEST_FUNC(test_vdup_16_3)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vdup.16.3       vr1, vr0, 0
        vstru.32.4      vr1, (a2), a3
        vstru.32.4      vr2, (a2), a3
        vstru.32.4      vr3, (a2), a3
        rts
        .size   test_vdup_16_3, .-test_vdup_16_3

TEST_FUNC(test_vdup_32_3)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vdup.32.3       vr1, vr0, 0
        vstru.32.4      vr1, (a2), a3
        vstru.32.4      vr2, (a2), a3
        vstru.32.4      vr3, (a2), a3
        rts
        .size   test_vdup_32_3, .-test_vdup_32_3

/* vdup.t.4 */
TEST_FUNC(test_vdup_8_4)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vdup.8.4        vr1, vr0, 0
        vstru.32.4      vr1, (a2), a3
        vstru.32.4      vr2, (a2), a3
        vstru.32.4      vr3, (a2), a3
        vstru.32.4      vr4, (a2), a3
        rts
        .size   test_vdup_8_4, .-test_vdup_8_4

TEST_FUNC(test_vdup_16_4)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vdup.16.4       vr1, vr0, 0
        vstru.32.4      vr1, (a2), a3
        vstru.32.4      vr2, (a2), a3
        vstru.32.4      vr3, (a2), a3
        vstru.32.4      vr4, (a2), a3
        rts
        .size   test_vdup_16_4, .-test_vdup_16_4

TEST_FUNC(test_vdup_32_4)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vdup.32.4       vr1, vr0, 0
        vstru.32.4      vr1, (a2), a3
        vstru.32.4      vr2, (a2), a3
        vstru.32.4      vr3, (a2), a3
        vstru.32.4      vr4, (a2), a3
        rts
        .size   test_vdup_32_4, .-test_vdup_32_4

/* vins.t.1 */
TEST_FUNC(test_vins_8_1)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vins.8.1        vr1, vr0, 0, 0
        vstru.32.4      vr1, (a1), t0
        rts
        .size   test_vins_8_1, .-test_vins_8_1

TEST_FUNC(test_vins_16_1)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vins.16.1       vr1, vr0, 0, 0
        vstru.32.4      vr1, (a1), t0
        rts
        .size   test_vins_16_1, .-test_vins_16_1

TEST_FUNC(test_vins_32_1)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vins.32.1       vr1, vr0, 0, 0
        vstru.32.4      vr1, (a1), t0
        rts
        .size   test_vins_32_1, .-test_vins_32_1

/* vins.t.2 */
TEST_FUNC(test_vins_8_2)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vins.8.2        vr2, vr0, 0, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vins_8_2, .-test_vins_8_2

TEST_FUNC(test_vins_16_2)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vins.16.2       vr2, vr0, 0, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vins_16_2, .-test_vins_16_2

TEST_FUNC(test_vins_32_2)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vins.32.2       vr2, vr0, 3, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vins_32_2, .-test_vins_32_2

/* vins.t.3 */
TEST_FUNC(test_vins_8_3)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vldru.32.4      vr4, (a0), t0
        vins.8.3        vr2, vr0, 0, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        vstru.32.4      vr4, (a1), t0
        rts
        .size   test_vins_8_3, .-test_vins_8_3

TEST_FUNC(test_vins_16_3)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vldru.32.4      vr4, (a0), t0
        vins.16.3       vr2, vr0, 0, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        vstru.32.4      vr4, (a1), t0
        rts
        .size   test_vins_16_3, .-test_vins_16_3

TEST_FUNC(test_vins_32_3)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vldru.32.4      vr4, (a0), t0
        vins.32.3       vr2, vr0, 0, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        vstru.32.4      vr4, (a1), t0
        rts
        .size   test_vins_32_3, .-test_vins_32_3

/* vins.t.4 */
TEST_FUNC(test_vins_8_4)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vldru.32.4      vr4, (a0), t0
        vldru.32.4      vr5, (a0), t0
        vins.8.4        vr2, vr0, 0, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        vstru.32.4      vr4, (a1), t0
        vstru.32.4      vr5, (a1), t0
        rts
        .size   test_vins_8_4, .-test_vins_8_4

TEST_FUNC(test_vins_16_4)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vldru.32.4      vr4, (a0), t0
        vldru.32.4      vr5, (a0), t0
        vins.16.4       vr2, vr0, 0, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        vstru.32.4      vr4, (a1), t0
        vstru.32.4      vr5, (a1), t0
        rts
        .size   test_vins_16_4, .-test_vins_16_4

TEST_FUNC(test_vins_32_4)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vldru.32.4      vr4, (a0), t0
        vldru.32.4      vr5, (a0), t0
        vins.32.4       vr2, vr0, 3, 0
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        vstru.32.4      vr4, (a1), t0
        vstru.32.4      vr5, (a1), t0
        rts
        .size   test_vins_32_4, .-test_vins_32_4

/* vpkg.t.2 */
TEST_FUNC(test_vpkg_8_2)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vpkg.8.2        vr2, vr0, 0, 15
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vpkg_8_2, .-test_vpkg_8_2

TEST_FUNC(test_vpkg_16_2)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vpkg.16.2       vr2, vr0, 0, 7
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vpkg_16_2, .-test_vpkg_16_2

TEST_FUNC(test_vpkg_32_2)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vpkg.32.2       vr2, vr0, 0, 3
        vstru.32.4      vr2, (a1), t0
        vstru.32.4      vr3, (a1), t0
        rts
        .size   test_vpkg_32_2, .-test_vpkg_32_2

/* vpkg.t.3 */
TEST_FUNC(test_vpkg_8_3)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vldru.32.4      vr4, (a0), t0
        vpkg.8.3        vr3, vr0, 0, 15
        vstru.32.4      vr3, (a1), t0
        vstru.32.4      vr4, (a1), t0
        rts
        .size   test_vpkg_8_3, .-test_vpkg_8_3

TEST_FUNC(test_vpkg_16_3)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vldru.32.4      vr4, (a0), t0
        vpkg.16.3       vr3, vr0, 0, 7
        vstru.32.4      vr3, (a1), t0
        vstru.32.4      vr4, (a1), t0
        rts
        .size   test_vpkg_16_3, .-test_vpkg_16_3

TEST_FUNC(test_vpkg_32_3)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vldru.32.4      vr4, (a0), t0
        vpkg.32.3       vr3, vr0, 0, 3
        vstru.32.4      vr3, (a1), t0
        vstru.32.4      vr4, (a1), t0
        rts
        .size   test_vpkg_32_3, .-test_vpkg_32_3

/* vpkg.t.4 */
TEST_FUNC(test_vpkg_8_4)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vldru.32.4      vr4, (a0), t0
        vldru.32.4      vr5, (a0), t0
        vpkg.8.4        vr4, vr0, 0, 15
        vstru.32.4      vr4, (a1), t0
        vstru.32.4      vr5, (a1), t0
        rts
        .size   test_vpkg_8_4, .-test_vpkg_8_4

TEST_FUNC(test_vpkg_16_4)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vldru.32.4      vr4, (a0), t0
        vldru.32.4      vr5, (a0), t0
        vpkg.16.4       vr4, vr0, 0, 7
        vstru.32.4      vr4, (a1), t0
        vstru.32.4      vr5, (a1), t0
        rts
        .size   test_vpkg_16_4, .-test_vpkg_16_4

TEST_FUNC(test_vpkg_32_4)
        movi            t0, 160
        vldru.32.4      vr0, (a0), t0
        vldru.32.4      vr1, (a0), t0
        vldru.32.4      vr2, (a0), t0
        vldru.32.4      vr3, (a0), t0
        vldru.32.4      vr4, (a0), t0
        vldru.32.4      vr5, (a0), t0
        vpkg.32.4       vr4, vr0, 0, 3
        vstru.32.4      vr4, (a1), t0
        vstru.32.4      vr5, (a1), t0
        rts
        .size   test_vpkg_32_4, .-test_vpkg_32_4

/* vsub.t */
TEST_FUNC(test_vsub_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.s8         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_s8, .-test_vsub_s8

TEST_FUNC(test_vsub_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.s16        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_s16, .-test_vsub_s16

TEST_FUNC(test_vsub_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.s32        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_s32, .-test_vsub_s32

TEST_FUNC(test_vsub_s64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.s64        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_s64, .-test_vsub_s64

TEST_FUNC(test_vsub_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.u8         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_u8, .-test_vsub_u8

TEST_FUNC(test_vsub_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.u16        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_u16, .-test_vsub_u16

TEST_FUNC(test_vsub_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.u32        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_u32, .-test_vsub_u32

TEST_FUNC(test_vsub_u64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.u64        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_u64, .-test_vsub_u64

#ifdef VDSP_FLOAT
TEST_FUNC(test_vsub_f32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.f32        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_f32, .-test_vsub_f32

TEST_FUNC(test_vsub_f16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.f16        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_f16, .-test_vsub_f16
#endif

/* vsubh.t */
TEST_FUNC(test_vsubh_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsubh.s8        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsubh_s8, .-test_vsubh_s8

TEST_FUNC(test_vsubh_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsubh.s16       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsubh_s16, .-test_vsubh_s16

TEST_FUNC(test_vsubh_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsubh.s32       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsubh_s32, .-test_vsubh_s32

TEST_FUNC(test_vsubh_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsubh.u8        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsubh_u8, .-test_vsubh_u8

TEST_FUNC(test_vsubh_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsubh.u16       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsubh_u16, .-test_vsubh_u16

TEST_FUNC(test_vsubh_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsubh.u32       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsubh_u32, .-test_vsubh_u32

/* vsub.t.s */
TEST_FUNC(test_vsub_s8_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.s8.s       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_s8_s, .-test_vsub_s8_s

TEST_FUNC(test_vsub_s16_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.s16.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_s16_s, .-test_vsub_s16_s

TEST_FUNC(test_vsub_s32_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.s32.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_s32_s, .-test_vsub_s32_s

TEST_FUNC(test_vsub_s64_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.s64.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_s64_s, .-test_vsub_s64_s

TEST_FUNC(test_vsub_u8_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.u8.s       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_u8_s, .-test_vsub_u8_s

TEST_FUNC(test_vsub_u16_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.u16.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_u16_s, .-test_vsub_u16_s

TEST_FUNC(test_vsub_u32_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.u32.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_u32_s, .-test_vsub_u32_s

TEST_FUNC(test_vsub_u64_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsub.u64.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsub_u64_s, .-test_vsub_u64_s

/* vcmpnez.t */
TEST_FUNC(test_vcmpnez_s8)
        vldm.32         vr0-vr0, (a0)
        vcmpnez.s8      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmpnez_s8, .-test_vcmpnez_s8

TEST_FUNC(test_vcmpnez_s16)
        vldm.32         vr0-vr0, (a0)
        vcmpnez.s16     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmpnez_s16, .-test_vcmpnez_s16

TEST_FUNC(test_vcmpnez_s32)
        vldm.32         vr0-vr0, (a0)
        vcmpnez.s32     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmpnez_s32, .-test_vcmpnez_s32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vcmpnez_f32)
        vldm.32         vr0-vr0, (a0)
        vcmpnez.f32     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmpnez_f32, .-test_vcmpnez_f32

TEST_FUNC(test_vcmpnez_f16)
        vldm.32         vr0-vr0, (a0)
        vcmpnez.f16     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmpnez_f16, .-test_vcmpnez_f16
#endif

/* vcmpne.t */
TEST_FUNC(test_vcmpne_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmpne.s8       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmpne_s8, .-test_vcmpne_s8

TEST_FUNC(test_vcmpne_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmpne.s16      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmpne_s16, .-test_vcmpne_s16

TEST_FUNC(test_vcmpne_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmpne.s32      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmpne_s32, .-test_vcmpne_s32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vcmpne_f32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmpne.f32      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmpne_f32, .-test_vcmpne_f32

TEST_FUNC(test_vcmpne_f16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmpne.f16      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmpne_f16, .-test_vcmpne_f16
#endif

/* vcmphsz.t */
TEST_FUNC(test_vcmphsz_s8)
        vldm.32         vr0-vr0, (a0)
        vcmphsz.s8      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmphsz_s8, .-test_vcmphsz_s8

TEST_FUNC(test_vcmphsz_s16)
        vldm.32         vr0-vr0, (a0)
        vcmphsz.s16     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmphsz_s16, .-test_vcmphsz_s16

TEST_FUNC(test_vcmphsz_s32)
        vldm.32         vr0-vr0, (a0)
        vcmphsz.s32     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmphsz_s32, .-test_vcmphsz_s32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vcmphsz_f32)
        vldm.32         vr0-vr0, (a0)
        vcmphsz.f32     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmphsz_f32, .-test_vcmphsz_f32

TEST_FUNC(test_vcmphsz_f16)
        vldm.32         vr0-vr0, (a0)
        vcmphsz.f16     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmphsz_f16, .-test_vcmphsz_f16
#endif

/* vcmphs.t */
TEST_FUNC(test_vcmphs_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmphs.s8       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmphs_s8, .-test_vcmphs_s8

TEST_FUNC(test_vcmphs_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmphs.s16      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmphs_s16, .-test_vcmphs_s16

TEST_FUNC(test_vcmphs_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmphs.s32      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmphs_s32, .-test_vcmphs_s32

TEST_FUNC(test_vcmphs_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmphs.u8       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmphs_u8, .-test_vcmphs_u8

TEST_FUNC(test_vcmphs_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmphs.u16      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmphs_u16, .-test_vcmphs_u16

TEST_FUNC(test_vcmphs_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmphs.u32      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmphs_u32, .-test_vcmphs_u32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vcmphs_f32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmphs.f32      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmphs_f32, .-test_vcmphs_f32

TEST_FUNC(test_vcmphs_f16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmphs.f16      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmphs_f16, .-test_vcmphs_f16
#endif

/* vcmpltz.t */
TEST_FUNC(test_vcmpltz_s8)
        vldm.32         vr0-vr0, (a0)
        vcmpltz.s8      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmpltz_s8, .-test_vcmpltz_s8

TEST_FUNC(test_vcmpltz_s16)
        vldm.32         vr0-vr0, (a0)
        vcmpltz.s16     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmpltz_s16, .-test_vcmpltz_s16

TEST_FUNC(test_vcmpltz_s32)
        vldm.32         vr0-vr0, (a0)
        vcmpltz.s32     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmpltz_s32, .-test_vcmpltz_s32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vcmpltz_f32)
        vldm.32         vr0-vr0, (a0)
        vcmpltz.f32     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmpltz_f32, .-test_vcmpltz_f32

TEST_FUNC(test_vcmpltz_f16)
        vldm.32         vr0-vr0, (a0)
        vcmpltz.f16     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmpltz_f16, .-test_vcmpltz_f16
#endif

/* vcmplt.t */
TEST_FUNC(test_vcmplt_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmplt.s8       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmplt_s8, .-test_vcmplt_s8

TEST_FUNC(test_vcmplt_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmplt.s16      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmplt_s16, .-test_vcmplt_s16

TEST_FUNC(test_vcmplt_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmplt.s32      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmplt_s32, .-test_vcmplt_s32

TEST_FUNC(test_vcmplt_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmplt.u8       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmplt_u8, .-test_vcmplt_u8

TEST_FUNC(test_vcmplt_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmplt.u16      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmplt_u16, .-test_vcmplt_u16

TEST_FUNC(test_vcmplt_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmplt.u32      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmplt_u32, .-test_vcmplt_u32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vcmplt_f32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmplt.f32      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmplt_f32, .-test_vcmplt_f32

TEST_FUNC(test_vcmplt_f16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vcmplt.f16      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vcmplt_f16, .-test_vcmplt_f16
#endif

/* vcmphz.t */
TEST_FUNC(test_vcmphz_s8)
        vldm.32         vr0-vr0, (a0)
        vcmphz.s8       vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmphz_s8, .-test_vcmphz_s8

TEST_FUNC(test_vcmphz_s16)
        vldm.32         vr0-vr0, (a0)
        vcmphz.s16      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmphz_s16, .-test_vcmphz_s16

TEST_FUNC(test_vcmphz_s32)
        vldm.32         vr0-vr0, (a0)
        vcmphz.s32      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmphz_s32, .-test_vcmphz_s32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vcmphz_f32)
        vldm.32         vr0-vr0, (a0)
        vcmphz.f32      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmphz_f32, .-test_vcmphz_f32

TEST_FUNC(test_vcmphz_f16)
        vldm.32         vr0-vr0, (a0)
        vcmphz.f16      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmphz_f16, .-test_vcmphz_f16
#endif

/* vcmplsz.t */
TEST_FUNC(test_vcmplsz_s8)
        vldm.32         vr0-vr0, (a0)
        vcmplsz.s8      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmplsz_s8, .-test_vcmplsz_s8

TEST_FUNC(test_vcmplsz_s16)
        vldm.32         vr0-vr0, (a0)
        vcmplsz.s16     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmplsz_s16, .-test_vcmplsz_s16

TEST_FUNC(test_vcmplsz_s32)
        vldm.32         vr0-vr0, (a0)
        vcmplsz.s32     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmplsz_s32, .-test_vcmplsz_s32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vcmplsz_f32)
        vldm.32         vr0-vr0, (a0)
        vcmplsz.f32     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmplsz_f32, .-test_vcmplsz_f32

TEST_FUNC(test_vcmplsz_f16)
        vldm.32         vr0-vr0, (a0)
        vcmplsz.f16     vr1, vr0
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vcmplsz_f16, .-test_vcmplsz_f16
#endif

/* vclip.t */
TEST_FUNC(test_vclip_s8)
        vldm.32         vr0-vr0, (a0)
        vclip.s8        vr1, vr0, 4
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vclip_s8, .-test_vclip_s8

TEST_FUNC(test_vclip_s16)
        vldm.32         vr0-vr0, (a0)
        vclip.s16       vr1, vr0, 8
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vclip_s16, .-test_vclip_s16

TEST_FUNC(test_vclip_s32)
        vldm.32         vr0-vr0, (a0)
        vclip.s32       vr1, vr0, 16
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vclip_s32, .-test_vclip_s32

TEST_FUNC(test_vclip_s64)
        vldm.32         vr0-vr0, (a0)
        vclip.s64       vr1, vr0, 32
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vclip_s64, .-test_vclip_s64

TEST_FUNC(test_vclip_u8)
        vldm.32         vr0-vr0, (a0)
        vclip.u8        vr1, vr0, 4
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vclip_u8, .-test_vclip_u8

TEST_FUNC(test_vclip_u16)
        vldm.32         vr0-vr0, (a0)
        vclip.u16       vr1, vr0, 8
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vclip_u16, .-test_vclip_u16

TEST_FUNC(test_vclip_u32)
        vldm.32         vr0-vr0, (a0)
        vclip.u32       vr1, vr0, 16
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vclip_u32, .-test_vclip_u32

TEST_FUNC(test_vclip_u64)
        vldm.32         vr0-vr0, (a0)
        vclip.u64       vr1, vr0, 32
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vclip_u64, .-test_vclip_u64

/* vtst.t */
TEST_FUNC(test_vtst_8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vtst.8          vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vtst_8, .-test_vtst_8

TEST_FUNC(test_vtst_16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vtst.16         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vtst_16, .-test_vtst_16

TEST_FUNC(test_vtst_32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vtst.32         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vtst_32, .-test_vtst_32

TEST_FUNC(test_vtst_64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vtst.64         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vtst_64, .-test_vtst_64

/* vsabs.t.s */
TEST_FUNC(test_vsabs_s8_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsabs.s8.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsabs_s8_s, .-test_vsabs_s8_s

TEST_FUNC(test_vsabs_s16_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsabs.s16.s     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsabs_s16_s, .-test_vsabs_s16_s

TEST_FUNC(test_vsabs_s32_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsabs.s32.s     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsabs_s32_s, .-test_vsabs_s32_s

TEST_FUNC(test_vsabs_u8_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsabs.u8.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsabs_u8_s, .-test_vsabs_u8_s

TEST_FUNC(test_vsabs_u16_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsabs.u16.s     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsabs_u16_s, .-test_vsabs_u16_s

TEST_FUNC(test_vsabs_u32_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsabs.u32.s     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsabs_u32_s, .-test_vsabs_u32_s

#ifdef VDSP_FLOAT
TEST_FUNC(test_vsabs_f32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsabs.f32       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsabs_f32, .-test_vsabs_f32

TEST_FUNC(test_vsabs_f16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsabs.f16       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsabs_f16, .-test_vsabs_f16
#endif

/* vmtvr.t.1 */
TEST_FUNC(test_vmtvr_8_1)
        vldm.32         vr0-vr0, (a0)
        vmtvr.8.1       vr0, a1, 0
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vmtvr_8_1, .-test_vmtvr_8_1

TEST_FUNC(test_vmtvr_16_1)
        vldm.32         vr0-vr0, (a0)
        vmtvr.16.1      vr0, a1, 0
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vmtvr_16_1, .-test_vmtvr_16_1

TEST_FUNC(test_vmtvr_32_1)
        vldm.32         vr0-vr0, (a0)
        vmtvr.32.1      vr0, a1, 0
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vmtvr_32_1, .-test_vmtvr_32_1

/* vmtvr.t.2 */
TEST_FUNC(test_vmtvr_8_2)
        vldm.32         vr0-vr0, (a0)
        vmtvr.8.2       vr0, a1, 0
        vstm.32         vr0-vr0, (a3)
        rts
        .size   test_vmtvr_8_2, .-test_vmtvr_8_2

TEST_FUNC(test_vmtvr_16_2)
        vldm.32         vr0-vr0, (a0)
        vmtvr.16.2      vr0, a1, 0
        vstm.32         vr0-vr0, (a3)
        rts
        .size   test_vmtvr_16_2, .-test_vmtvr_16_2

TEST_FUNC(test_vmtvr_32_2)
        vldm.32         vr0-vr0, (a0)
        vmtvr.32.2      vr0, a1, 0
        vstm.32         vr0-vr0, (a3)
        rts
        .size   test_vmtvr_32_2, .-test_vmtvr_32_2

/* vmfvr.t.1 */
TEST_FUNC(test_vmfvr_s8)
        vldm.32         vr0-vr0, (a0)
        vmfvr.s8        a1, vr0, 0
        mov             a0, a1
        rts
        .size   test_vmfvr_s8, .-test_vmfvr_s8

TEST_FUNC(test_vmfvr_s16)
        vldm.32         vr0-vr0, (a0)
        vmfvr.s16       a1, vr0, 0
        mov             a0, a1
        rts
        .size   test_vmfvr_s16, .-test_vmfvr_s16

TEST_FUNC(test_vmfvr_s32)
        vldm.32         vr0-vr0, (a0)
        vmfvr.s32       a1, vr0, 0
        mov             a0, a1
        rts
        .size   test_vmfvr_s32, .-test_vmfvr_s32

TEST_FUNC(test_vmfvr_u8)
        vldm.32         vr0-vr0, (a0)
        vmfvr.u8        a1, vr0, 0
        mov             a0, a1
        rts
        .size   test_vmfvr_u8, .-test_vmfvr_u8

TEST_FUNC(test_vmfvr_u16)
        vldm.32         vr0-vr0, (a0)
        vmfvr.u16       a1, vr0, 0
        mov             a0, a1
        rts
        .size   test_vmfvr_u16, .-test_vmfvr_u16

TEST_FUNC(test_vmfvr_u32)
        vldm.32         vr0-vr0, (a0)
        vmfvr.u32       a1, vr0, 0
        mov             a0, a1
        rts
        .size   test_vmfvr_u32, .-test_vmfvr_u32

/* vsext.t */
TEST_FUNC(test_vsext_8)
        vldm.32         vr0-vr0, (a0)
        vsext.8         a1, vr0
        mov             a0, a1
        rts
        .size   test_vsext_8, .-test_vsext_8

TEST_FUNC(test_vsext_16)
        vldm.32         vr0-vr0, (a0)
        vsext.16        a1, vr0
        mov             a0, a1
        rts
        .size   test_vsext_16, .-test_vsext_16

TEST_FUNC(test_vsext_32)
        vldm.32         vr0-vr0, (a0)
        vsext.32        a1, vr0
        mov             a0, a1
        rts
        .size   test_vsext_32, .-test_vsext_32

/* vmov.t.sl */
TEST_FUNC(test_vmov_s16_sl)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmov.s16.sl     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_s16_sl, .-test_vmov_s16_sl

TEST_FUNC(test_vmov_s32_sl)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmov.s32.sl     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_s32_sl, .-test_vmov_s32_sl

TEST_FUNC(test_vmov_s64_sl)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmov.s64.sl     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_s64_sl, .-test_vmov_s64_sl

TEST_FUNC(test_vmov_u16_sl)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmov.u16.sl     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_u16_sl, .-test_vmov_u16_sl

TEST_FUNC(test_vmov_u32_sl)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmov.u32.sl     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_u32_sl, .-test_vmov_u32_sl

TEST_FUNC(test_vmov_u64_sl)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmov.u64.sl     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_u64_sl, .-test_vmov_u64_sl

/* vmov.t.rh */
TEST_FUNC(test_vmov_s16_rh)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmov.s16.rh     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_s16_rh, .-test_vmov_s16_rh

TEST_FUNC(test_vmov_s32_rh)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmov.s32.rh     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_s32_rh, .-test_vmov_s32_rh

TEST_FUNC(test_vmov_s64_rh)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmov.s64.rh     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_s64_rh, .-test_vmov_s64_rh

TEST_FUNC(test_vmov_u16_rh)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmov.u16.rh     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_u16_rh, .-test_vmov_u16_rh

TEST_FUNC(test_vmov_u32_rh)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmov.u32.rh     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_u32_rh, .-test_vmov_u32_rh

TEST_FUNC(test_vmov_u64_rh)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmov.u64.rh     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_u64_rh, .-test_vmov_u64_rh

/* vldru.t.1 */
TEST_FUNC(test_vldru_8_1)
        vldm.32         vr0-vr0, (a1)
        vldru.8.1       vr0, (a0), a3
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldru_8_1, .-test_vldru_8_1

TEST_FUNC(test_vldru_16_1)
        vldm.32         vr0-vr0, (a1)
        vldru.16.1      vr0, (a0), a3
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldru_16_1, .-test_vldru_16_1

TEST_FUNC(test_vldru_32_1)
        vldm.32         vr0-vr0, (a1)
        vldru.32.1      vr0, (a0), a3
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldru_32_1, .-test_vldru_32_1

/* vldru.t.2 */
TEST_FUNC(test_vldru_8_2)
        vldm.32         vr0-vr0, (a1)
        vldru.8.2       vr0, (a0), a3
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldru_8_2, .-test_vldru_8_2

TEST_FUNC(test_vldru_16_2)
        vldm.32         vr0-vr0, (a1)
        vldru.16.2      vr0, (a0), a3
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldru_16_2, .-test_vldru_16_2

TEST_FUNC(test_vldru_32_2)
        vldm.32         vr0-vr0, (a1)
        vldru.32.2      vr0, (a0), a3
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldru_32_2, .-test_vldru_32_2

/* vldru.t.3 */
TEST_FUNC(test_vldru_8_3)
        vldm.32         vr0-vr0, (a1)
        vldru.8.3       vr0, (a0), a3
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldru_8_3, .-test_vldru_8_3

TEST_FUNC(test_vldru_16_3)
        vldm.32         vr0-vr0, (a1)
        vldru.16.3      vr0, (a0), a3
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldru_16_3, .-test_vldru_16_3

TEST_FUNC(test_vldru_32_3)
        vldm.32         vr0-vr0, (a1)
        vldru.32.3      vr0, (a0), a3
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldru_32_3, .-test_vldru_32_3

/* vldru.t.4 */
TEST_FUNC(test_vldru_8_4)
        vldm.32         vr0-vr0, (a1)
        vldru.8.4       vr0, (a0), a3
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldru_8_4, .-test_vldru_8_4

TEST_FUNC(test_vldru_16_4)
        vldm.32         vr0-vr0, (a1)
        vldru.16.4      vr0, (a0), a3
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldru_16_4, .-test_vldru_16_4

TEST_FUNC(test_vldru_32_4)
        vldm.32         vr0-vr0, (a1)
        vldru.32.4      vr0, (a0), a3
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldru_32_4, .-test_vldru_32_4

/* vldu.t.1 */
TEST_FUNC(test_vldu_8_1)
        vldm.32         vr0-vr0, (a1)
        vldu.8.1        vr0, (a0)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldu_8_1, .-test_vldu_8_1

TEST_FUNC(test_vldu_16_1)
        vldm.32         vr0-vr0, (a1)
        vldu.16.1       vr0, (a0)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldu_16_1, .-test_vldu_16_1

TEST_FUNC(test_vldu_32_1)
        vldm.32         vr0-vr0, (a1)
        vldu.32.1       vr0, (a0)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldu_32_1, .-test_vldu_32_1

/* vldu.t.2 */
TEST_FUNC(test_vldu_8_2)
        vldm.32         vr0-vr0, (a1)
        vldu.8.2        vr0, (a0)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldu_8_2, .-test_vldu_8_2

TEST_FUNC(test_vldu_16_2)
        vldm.32         vr0-vr0, (a1)
        vldu.16.2       vr0, (a0)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldu_16_2, .-test_vldu_16_2

TEST_FUNC(test_vldu_32_2)
        vldm.32         vr0-vr0, (a1)
        vldu.32.2       vr0, (a0)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldu_32_2, .-test_vldu_32_2

/* vldu.t.3 */
TEST_FUNC(test_vldu_8_3)
        vldm.32         vr0-vr0, (a1)
        vldu.8.3        vr0, (a0)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldu_8_3, .-test_vldu_8_3

TEST_FUNC(test_vldu_16_3)
        vldm.32         vr0-vr0, (a1)
        vldu.16.3       vr0, (a0)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldu_16_3, .-test_vldu_16_3

TEST_FUNC(test_vldu_32_3)
        vldm.32         vr0-vr0, (a1)
        vldu.32.3       vr0, (a0)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldu_32_3, .-test_vldu_32_3

/* vldu.t.4 */
TEST_FUNC(test_vldu_8_4)
        vldm.32         vr0-vr0, (a1)
        vldu.8.4        vr0, (a0)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldu_8_4, .-test_vldu_8_4

TEST_FUNC(test_vldu_16_4)
        vldm.32         vr0-vr0, (a1)
        vldu.16.4       vr0, (a0)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldu_16_4, .-test_vldu_16_4

TEST_FUNC(test_vldu_32_4)
        vldm.32         vr0-vr0, (a1)
        vldu.32.4       vr0, (a0)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vldu_32_4, .-test_vldu_32_4

/* vld.t.1 */
TEST_FUNC(test_vld_8_1)
        vldm.32         vr0-vr0, (a1)
        vld.8.1         vr0, (a0, 1)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vld_8_1, .-test_vld_8_1

TEST_FUNC(test_vld_16_1)
        vldm.32         vr0-vr0, (a1)
        vld.16.1        vr0, (a0, 2)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vld_16_1, .-test_vld_16_1

TEST_FUNC(test_vld_32_1)
        vldm.32         vr0-vr0, (a1)
        vld.32.1        vr0, (a0, 4)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vld_32_1, .-test_vld_32_1

/* vld.t.2 */
TEST_FUNC(test_vld_8_2)
        vldm.32         vr0-vr0, (a1)
        vld.8.2         vr0, (a0, 1)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vld_8_2, .-test_vld_8_2

TEST_FUNC(test_vld_16_2)
        vldm.32         vr0-vr0, (a1)
        vld.16.2        vr0, (a0, 2)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vld_16_2, .-test_vld_16_2

TEST_FUNC(test_vld_32_2)
        vldm.32         vr0-vr0, (a1)
        vld.32.2        vr0, (a0, 4)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vld_32_2, .-test_vld_32_2

/* vld.t.3 */
TEST_FUNC(test_vld_8_3)
        vldm.32         vr0-vr0, (a1)
        vld.8.3         vr0, (a0, 1)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vld_8_3, .-test_vld_8_3

TEST_FUNC(test_vld_16_3)
        vldm.32         vr0-vr0, (a1)
        vld.16.3        vr0, (a0, 2)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vld_16_3, .-test_vld_16_3

TEST_FUNC(test_vld_32_3)
        vldm.32         vr0-vr0, (a1)
        vld.32.3        vr0, (a0, 4)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vld_32_3, .-test_vld_32_3

/* vld.t.4 */
TEST_FUNC(test_vld_8_4)
        vldm.32         vr0-vr0, (a1)
        vld.8.4         vr0, (a0, 1)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vld_8_4, .-test_vld_8_4

TEST_FUNC(test_vld_16_4)
        vldm.32         vr0-vr0, (a1)
        vld.16.4        vr0, (a0, 2)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vld_16_4, .-test_vld_16_4

TEST_FUNC(test_vld_32_4)
        vldm.32         vr0-vr0, (a1)
        vld.32.4        vr0, (a0, 0)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vld_32_4, .-test_vld_32_4

/* vldx.t */
TEST_FUNC(test_vldx_8)
        vldm.32         vr0-vr0, (a1)
        vldx.8          vr0, (a0), a2
        vstm.32         vr0-vr0, (a3)
        rts
        .size   test_vldx_8, .-test_vldx_8

TEST_FUNC(test_vldx_16)
        vldm.32         vr0-vr0, (a1)
        vldx.16         vr0, (a0), a2
        vstm.32         vr0-vr0, (a3)
        rts
        .size   test_vldx_16, .-test_vldx_16

TEST_FUNC(test_vldx_32)
        vldm.32         vr0-vr0, (a1)
        vldx.32         vr0, (a0), a2
        vstm.32         vr0-vr0, (a3)
        rts
        .size   test_vldx_32, .-test_vldx_32

/* vlrw.t.1 */
TEST_FUNC(test_vlrw_32_1)
        vlrw.32.1       vr0, 0xcfe06686
        vstm.32         vr0-vr0, (a0)
        rts
        .size   test_vlrw_32_1, .-test_vlrw_32_1

/* vlrw.t.2 */
TEST_FUNC(test_vlrw_32_2)
        vlrw.32.2       vr0, 0x8262f661cfe06686
        vstm.32         vr0-vr0, (a0)
        rts
        .size   test_vlrw_32_2, .-test_vlrw_32_2

/* vlrw.t.3 */
TEST_FUNC(test_vlrw_32_3)
        vlrw.32.3       vr0, 0x15fc52218262f661cfe06686
        vstm.32         vr0-vr0, (a0)
        rts
        .size   test_vlrw_32_3, .-test_vlrw_32_3

/* vlrw.t.4 */
TEST_FUNC(test_vlrw_32_4)
        vlrw.32.4       vr0, 0xd6b9745a15fc52218262f661cfe06686
        vstm.32         vr0-vr0, (a0)
        rts
        .size   test_vlrw_32_4, .-test_vlrw_32_4

/* vldmu.t */
TEST_FUNC(test_vldmu_8)
    vldmu.8     vr0-vr3, (a0)
    vstm.32         vr0-vr0, (a1)
    add         a1, a2
    vstm.32         vr1-vr1, (a1)
    add         a1, a2
    vstm.32         vr2-vr2, (a1)
    add         a1, a2
    vstm.32         vr3-vr3, (a1)
    rts
    .size   test_vldmu_8, .-test_vldmu_8

TEST_FUNC(test_vldmu_16)
    vldmu.16    vr0-vr3, (a0)
    vstm.32         vr0-vr0, (a1)
    add         a1, a2
    vstm.32         vr1-vr1, (a1)
    add         a1, a2
    vstm.32         vr2-vr2, (a1)
    add         a1, a2
    vstm.32         vr3-vr3, (a1)
    rts
    .size   test_vldmu_16, .-test_vldmu_16

TEST_FUNC(test_vldmu_32)
    vldmu.32    vr0-vr3, (a0)
    vstm.32         vr0-vr0, (a1)
    add         a1, a2
    vstm.32         vr1-vr1, (a1)
    add         a1, a2
    vstm.32         vr2-vr2, (a1)
    add         a1, a2
    vstm.32         vr3-vr3, (a1)
    rts
    .size   test_vldmu_32, .-test_vldmu_32

/* vldmru.t */
TEST_FUNC(test_vldmru_8)
    movi        t1, 16
    vldmru.8    vr0-vr3, (a0), a1
    vstm.32         vr0-vr0, (a2)
    add         a2, t1
    vstm.32         vr1-vr1, (a2)
    add         a2, t1
    vstm.32         vr2-vr2, (a2)
    add         a2, t1
    vstm.32         vr3-vr3, (a2)
    rts
    .size   test_vldmru_8, .-test_vldmru_8

TEST_FUNC(test_vldmru_16)
    movi        t1, 16
    vldmru.16   vr0-vr3, (a0), a1
    vstm.32         vr0-vr0, (a2)
    add         a2, t1
    vstm.32         vr1-vr1, (a2)
    add         a2, t1
    vstm.32         vr2-vr2, (a2)
    add         a2, t1
    vstm.32         vr3-vr3, (a2)
    rts
    .size   test_vldmru_16, .-test_vldmru_16

TEST_FUNC(test_vldmru_32)
    movi        t1, 16
    vldmru.32   vr0-vr3, (a0), a1
    vstm.32         vr0-vr0, (a2)
    add         a2, t1
    vstm.32         vr1-vr1, (a2)
    add         a2, t1
    vstm.32         vr2-vr2, (a2)
    add         a2, t1
    vstm.32         vr3-vr3, (a2)
    rts
    .size   test_vldmru_32, .-test_vldmru_32

/* vldm.t */
TEST_FUNC(test_vldm_8)
    vldm.8      vr0-vr3, (a0)
    vstm.32         vr0-vr0, (a1)
    add         a1, a2
    vstm.32         vr1-vr1, (a1)
    add         a1, a2
    vstm.32         vr2-vr2, (a1)
    add         a1, a2
    vstm.32         vr3-vr3, (a1)
    rts
    .size   test_vldm_8, .-test_vldm_8

TEST_FUNC(test_vldm_16)
    vldm.16     vr0-vr3, (a0)
    vstm.32         vr0-vr0, (a1)
    add         a1, a2
    vstm.32         vr1-vr1, (a1)
    add         a1, a2
    vstm.32         vr2-vr2, (a1)
    add         a1, a2
    vstm.32         vr3-vr3, (a1)
    rts
    .size   test_vldm_16, .-test_vldm_16

TEST_FUNC(test_vldm_32)
    vldm.32     vr0-vr3, (a0)
    vstm.32         vr0-vr0, (a1)
    add         a1, a2
    vstm.32         vr1-vr1, (a1)
    add         a1, a2
    vstm.32         vr2-vr2, (a1)
    add         a1, a2
    vstm.32         vr3-vr3, (a1)
    rts
    .size   test_vldm_32, .-test_vldm_32

#ifdef CK803
/* vlde.t */
TEST_FUNC(test_vlde_8)
        vldm.32         vr0-vr0, (a1)
        vlde.8          vr0, (a0, vr0)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vlde_8, .-test_vlde_8

TEST_FUNC(test_vlde_16)
        vldm.32         vr0-vr0, (a1)
        vlde.16         vr0, (a0, vr0)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vlde_16, .-test_vlde_16

TEST_FUNC(test_vlde_32)
        vldm.32         vr0-vr0, (a1)
        vlde.32         vr0, (a0, vr0)
        vstm.32         vr0-vr0, (a2)
        rts
        .size   test_vlde_32, .-test_vlde_32
#endif

/* vstru.t.1 */
TEST_FUNC(test_vstru_8_1)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstru.8.1       vr0, (a2), a3
        mov             a0, a2
        rts
        .size   test_vstru_8_1, .-test_vstru_8_1

TEST_FUNC(test_vstru_16_1)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstru.16.1      vr0, (a2), a3
        mov             a0, a2
        rts
        .size   test_vstru_16_1, .-test_vstru_16_1

TEST_FUNC(test_vstru_32_1)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstru.32.1      vr0, (a2), a3
        mov             a0, a2
        rts
        .size   test_vstru_32_1, .-test_vstru_32_1

/* vstru.t.2 */
TEST_FUNC(test_vstru_8_2)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstru.8.2       vr0, (a2), a3
        mov             a0, a2
        rts
        .size   test_vstru_8_2, .-test_vstru_8_2

TEST_FUNC(test_vstru_16_2)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstru.16.2      vr0, (a2), a3
        mov             a0, a2
        rts
        .size   test_vstru_16_2, .-test_vstru_16_2

TEST_FUNC(test_vstru_32_2)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstru.32.2      vr0, (a2), a3
        mov             a0, a2
        rts
        .size   test_vstru_32_2, .-test_vstru_32_2

/* vstru.t.3 */
TEST_FUNC(test_vstru_8_3)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstru.8.3       vr0, (a2), a3
        mov             a0, a2
        rts
        .size   test_vstru_8_3, .-test_vstru_8_3

TEST_FUNC(test_vstru_16_3)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstru.16.3      vr0, (a2), a3
        mov             a0, a2
        rts
        .size   test_vstru_16_3, .-test_vstru_16_3

TEST_FUNC(test_vstru_32_3)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstru.32.3      vr0, (a2), a3
        mov             a0, a2
        rts
        .size   test_vstru_32_3, .-test_vstru_32_3

/* vstru.t.4 */
TEST_FUNC(test_vstru_8_4)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstru.8.4       vr0, (a2), a3
        mov             a0, a2
        rts
        .size   test_vstru_8_4, .-test_vstru_8_4

TEST_FUNC(test_vstru_16_4)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstru.16.4      vr0, (a2), a3
        mov             a0, a2
        rts
        .size   test_vstru_16_4, .-test_vstru_16_4

TEST_FUNC(test_vstru_32_4)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstru.32.4      vr0, (a2), a3
        mov             a0, a2
        rts
        .size   test_vstru_32_4, .-test_vstru_32_4

/* vstu.t.1 */
TEST_FUNC(test_vstu_8_1)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstu.8.1        vr0, (a2)
        mov             a0, a2
        rts
        .size   test_vstu_8_1, .-test_vstu_8_1

TEST_FUNC(test_vstu_16_1)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstu.16.1       vr0, (a2)
        mov             a0, a2
        rts
        .size   test_vstu_16_1, .-test_vstu_16_1

TEST_FUNC(test_vstu_32_1)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstu.32.1       vr0, (a2)
        mov             a0, a2
        rts
        .size   test_vstu_32_1, .-test_vstu_32_1

/* vstu.t.2 */
TEST_FUNC(test_vstu_8_2)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstu.8.2        vr0, (a2)
        mov             a0, a2
        rts
        .size   test_vstu_8_2, .-test_vstu_8_2

TEST_FUNC(test_vstu_16_2)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstu.16.2       vr0, (a2)
        mov             a0, a2
        rts
        .size   test_vstu_16_2, .-test_vstu_16_2

TEST_FUNC(test_vstu_32_2)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstu.32.2       vr0, (a2)
        mov             a0, a2
        rts
        .size   test_vstu_32_2, .-test_vstu_32_2

/* vstu.t.3 */
TEST_FUNC(test_vstu_8_3)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstu.8.3        vr0, (a2)
        mov             a0, a2
        rts
        .size   test_vstu_8_3, .-test_vstu_8_3

TEST_FUNC(test_vstu_16_3)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstu.16.3       vr0, (a2)
        mov             a0, a2
        rts
        .size   test_vstu_16_3, .-test_vstu_16_3

TEST_FUNC(test_vstu_32_3)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstu.32.3       vr0, (a2)
        mov             a0, a2
        rts
        .size   test_vstu_32_3, .-test_vstu_32_3

/* vstu.t.4 */
TEST_FUNC(test_vstu_8_4)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstu.8.4        vr0, (a2)
        mov             a0, a2
        rts
        .size   test_vstu_8_4, .-test_vstu_8_4

TEST_FUNC(test_vstu_16_4)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstu.16.4       vr0, (a2)
        mov             a0, a2
        rts
        .size   test_vstu_16_4, .-test_vstu_16_4

TEST_FUNC(test_vstu_32_4)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vstu.32.4       vr0, (a2)
        mov             a0, a2
        rts
        .size   test_vstu_32_4, .-test_vstu_32_4

/* vst.t.1 */
TEST_FUNC(test_vst_8_1)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vst.8.1         vr0, (a2, 1)
        rts
        .size   test_vst_8_1, .-test_vst_8_1

TEST_FUNC(test_vst_16_1)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vst.16.1        vr0, (a2, 2)
        rts
        .size   test_vst_16_1, .-test_vst_16_1

TEST_FUNC(test_vst_32_1)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vst.32.1        vr0, (a2, 4)
        rts
        .size   test_vst_32_1, .-test_vst_32_1

/* vst.t.2 */
TEST_FUNC(test_vst_8_2)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vst.8.2         vr0, (a2, 1)
        rts
        .size   test_vst_8_2, .-test_vst_8_2

TEST_FUNC(test_vst_16_2)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vst.16.2        vr0, (a2, 2)
        rts
        .size   test_vst_16_2, .-test_vst_16_2

TEST_FUNC(test_vst_32_2)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vst.32.2        vr0, (a2, 4)
        rts
        .size   test_vst_32_2, .-test_vst_32_2

/* vst.t.3 */
TEST_FUNC(test_vst_8_3)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vst.8.3         vr0, (a2, 1)
        rts
        .size   test_vst_8_3, .-test_vst_8_3

TEST_FUNC(test_vst_16_3)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vst.16.3        vr0, (a2, 2)
        rts
        .size   test_vst_16_3, .-test_vst_16_3

TEST_FUNC(test_vst_32_3)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vst.32.3        vr0, (a2, 4)
        rts
        .size   test_vst_32_3, .-test_vst_32_3

/* vst.t.4 */
TEST_FUNC(test_vst_8_4)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vst.8.4         vr0, (a2, 1)
        rts
        .size   test_vst_8_4, .-test_vst_8_4

TEST_FUNC(test_vst_16_4)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vst.16.4        vr0, (a2, 2)
        rts
        .size   test_vst_16_4, .-test_vst_16_4

TEST_FUNC(test_vst_32_4)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a2)
        vst.32.4        vr0, (a2, 0)
        rts
        .size   test_vst_32_4, .-test_vst_32_4

/* vstx.t */
TEST_FUNC(test_vstx_8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a3)
        vstx.8          vr0, (a3), a2
        rts
        .size   test_vstx_8, .-test_vstx_8

TEST_FUNC(test_vstx_16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a3)
        vstx.16         vr0, (a3), a2
        rts
        .size   test_vstx_16, .-test_vstx_16

TEST_FUNC(test_vstx_32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vstm.32         vr1-vr1, (a3)
        vstx.32         vr0, (a3), a2
        rts
        .size   test_vstx_32, .-test_vstx_32

/* vstmu.t */
TEST_FUNC(test_vstmu_8)
        vldm.32         vr0-vr0, (a0)
    add         a0, a2
    vldm.32         vr1-vr1, (a0)
    add         a0, a2
    vldm.32         vr2-vr2, (a0)
    add         a0, a2
    vldm.32         vr3-vr3, (a0)
    vstmu.8     vr0-vr3, (a1)
    mov         a0, a1
    rts
    .size   test_vstmu_8, .-test_vstmu_8

TEST_FUNC(test_vstmu_16)
        vldm.32         vr0-vr0, (a0)
    add         a0, a2
    vldm.32         vr1-vr1, (a0)
    add         a0, a2
    vldm.32         vr2-vr2, (a0)
    add         a0, a2
    vldm.32         vr3-vr3, (a0)
    vstmu.16    vr0-vr3, (a1)
    mov         a0, a1
    rts
    .size   test_vstmu_16, .-test_vstmu_16

TEST_FUNC(test_vstmu_32)
        vldm.32         vr0-vr0, (a0)
    add         a0, a2
    vldm.32         vr1-vr1, (a0)
    add         a0, a2
    vldm.32         vr2-vr2, (a0)
    add         a0, a2
    vldm.32         vr3-vr3, (a0)
    vstmu.32    vr0-vr3, (a1)
    mov         a0, a1
    rts
    .size   test_vstmu_32, .-test_vstmu_32

/* vstmru.t */
TEST_FUNC(test_vstmru_8)
    movi        t1, 16
        vldm.32         vr0-vr0, (a0)
    add         a0, t1
    vldm.32         vr1-vr1, (a0)
    add         a0, t1
    vldm.32         vr2-vr2, (a0)
    add         a0, t1
    vldm.32         vr3-vr3, (a0)
    vstmru.8    vr0-vr3, (a1), a2
    mov         a0, a1
    rts
    .size   test_vstmru_8, .-test_vstmru_8

TEST_FUNC(test_vstmru_16)
    movi        t1, 16
        vldm.32         vr0-vr0, (a0)
    add         a0, t1
    vldm.32         vr1-vr1, (a0)
    add         a0, t1
    vldm.32         vr2-vr2, (a0)
    add         a0, t1
    vldm.32         vr3-vr3, (a0)
    vstmru.16   vr0-vr3, (a1), a2
    mov         a0, a1
    rts
    .size   test_vstmru_16, .-test_vstmru_16

TEST_FUNC(test_vstmru_32)
    movi        t1, 16
        vldm.32         vr0-vr0, (a0)
    add         a0, t1
    vldm.32         vr1-vr1, (a0)
    add         a0, t1
    vldm.32         vr2-vr2, (a0)
    add         a0, t1
    vldm.32         vr3-vr3, (a0)
    vstmru.32   vr0-vr3, (a1), a2
    mov         a0, a1
    rts
    .size   test_vstmru_32, .-test_vstmru_32

/* vstm.t */
TEST_FUNC(test_vstm_8)
        vldm.32         vr0-vr0, (a0)
    add         a0, a2
    vldm.32         vr1-vr1, (a0)
    add         a0, a2
    vldm.32         vr2-vr2, (a0)
    add         a0, a2
    vldm.32         vr3-vr3, (a0)
    vstm.8      vr0-vr3, (a1)
    rts
    .size   test_vstm_8, .-test_vstm_8

TEST_FUNC(test_vstm_16)
        vldm.32         vr0-vr0, (a0)
    add         a0, a2
    vldm.32         vr1-vr1, (a0)
    add         a0, a2
    vldm.32         vr2-vr2, (a0)
    add         a0, a2
    vldm.32         vr3-vr3, (a0)
    vstm.16     vr0-vr3, (a1)
    rts
    .size   test_vstm_16, .-test_vstm_16

TEST_FUNC(test_vstm_32)
        vldm.32         vr0-vr0, (a0)
    add         a0, a2
    vldm.32         vr1-vr1, (a0)
    add         a0, a2
    vldm.32         vr2-vr2, (a0)
    add         a0, a2
    vldm.32         vr3-vr3, (a0)
    vstm.32     vr0-vr3, (a1)
    rts
    .size   test_vstm_32, .-test_vstm_32

/* vmax.t */
TEST_FUNC(test_vmax_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmax.s8         vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmax_s8, .-test_vmax_s8

TEST_FUNC(test_vmax_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmax.s16        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmax_s16, .-test_vmax_s16

TEST_FUNC(test_vmax_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmax.s32        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmax_s32, .-test_vmax_s32

TEST_FUNC(test_vmax_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmax.u8         vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmax_u8, .-test_vmax_u8

TEST_FUNC(test_vmax_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmax.u16        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmax_u16, .-test_vmax_u16

TEST_FUNC(test_vmax_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmax.u32        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmax_u32, .-test_vmax_u32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vmax_f32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmax.f32        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmax_f32, .-test_vmax_f32

TEST_FUNC(test_vmax_f16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmax.f16        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmax_f16, .-test_vmax_f16

TEST_FUNC(test_vmaxnm_f32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmaxnm.f32      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmaxnm_f32, .-test_vmaxnm_f32

TEST_FUNC(test_vmaxnm_f16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmaxnm.f16      vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmaxnm_f16, .-test_vmaxnm_f16

#endif

/* vmin.t */
TEST_FUNC(test_vmin_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmin.s8         vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmin_s8, .-test_vmin_s8

TEST_FUNC(test_vmin_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmin.s16        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmin_s16, .-test_vmin_s16

TEST_FUNC(test_vmin_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmin.s32        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmin_s32, .-test_vmin_s32

TEST_FUNC(test_vmin_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmin.u8         vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmin_u8, .-test_vmin_u8

TEST_FUNC(test_vmin_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmin.u16        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmin_u16, .-test_vmin_u16

TEST_FUNC(test_vmin_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmin.u32        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmin_u32, .-test_vmin_u32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vmin_f32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmin.f32        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmin_f32, .-test_vmin_f32

TEST_FUNC(test_vmin_f16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmin.f16        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmin_f16, .-test_vmin_f16

TEST_FUNC(test_vminnm_f32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vminnm.f32        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vminnm_f32, .-test_vminnm_f32

TEST_FUNC(test_vminnm_f16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vminnm.f16        vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vminnm_f16, .-test_vminnm_f16

#endif

/* vpmax.t */
TEST_FUNC(test_vpmax_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpmax.s8        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpmax_s8, .-test_vpmax_s8

TEST_FUNC(test_vpmax_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpmax.s16       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpmax_s16, .-test_vpmax_s16

TEST_FUNC(test_vpmax_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpmax.s32       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpmax_s32, .-test_vpmax_s32

TEST_FUNC(test_vpmax_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpmax.u8        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpmax_u8, .-test_vpmax_u8

TEST_FUNC(test_vpmax_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpmax.u16       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpmax_u16, .-test_vpmax_u16

TEST_FUNC(test_vpmax_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpmax.u32       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpmax_u32, .-test_vpmax_u32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vpmax_f32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpmax.f32       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpmax_f32, .-test_vpmax_f32

TEST_FUNC(test_vpmax_f16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpmax.f16       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpmax_f16, .-test_vpmax_f16
#endif

/* vpmin.t */
TEST_FUNC(test_vpmin_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpmin.s8        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpmin_s8, .-test_vpmin_s8

TEST_FUNC(test_vpmin_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpmin.s16       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpmin_s16, .-test_vpmin_s16

TEST_FUNC(test_vpmin_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpmin.s32       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpmin_s32, .-test_vpmin_s32

TEST_FUNC(test_vpmin_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpmin.u8        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpmin_u8, .-test_vpmin_u8

TEST_FUNC(test_vpmin_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpmin.u16       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpmin_u16, .-test_vpmin_u16

TEST_FUNC(test_vpmin_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpmin.u32       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpmin_u32, .-test_vpmin_u32

#ifdef VDSP_FLOAT
TEST_FUNC(test_vpmin_f32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpmin.f32       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpmin_f32, .-test_vpmin_f32

TEST_FUNC(test_vpmin_f16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vpmin.f16       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vpmin_f16, .-test_vpmin_f16
#endif

/* vsht.t */
TEST_FUNC(test_vsht_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.s8         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_s8, .-test_vsht_s8

TEST_FUNC(test_vsht_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.s16        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_s16, .-test_vsht_s16

TEST_FUNC(test_vsht_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.s32        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_s32, .-test_vsht_s32

TEST_FUNC(test_vsht_s64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.s64        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_s64, .-test_vsht_s64

TEST_FUNC(test_vsht_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.u8         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_u8, .-test_vsht_u8

TEST_FUNC(test_vsht_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.u16        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_u16, .-test_vsht_u16

TEST_FUNC(test_vsht_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.u32        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_u32, .-test_vsht_u32

TEST_FUNC(test_vsht_u64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.u64        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_u64, .-test_vsht_u64

/* vshl.t */
TEST_FUNC(test_vshl_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshl.s8         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshl_s8, .-test_vshl_s8

TEST_FUNC(test_vshl_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshl.s16        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshl_s16, .-test_vshl_s16

TEST_FUNC(test_vshl_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshl.s32        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshl_s32, .-test_vshl_s32

TEST_FUNC(test_vshl_s64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshl.s64        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshl_s64, .-test_vshl_s64

TEST_FUNC(test_vshl_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshl.u8         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshl_u8, .-test_vshl_u8

TEST_FUNC(test_vshl_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshl.u16        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshl_u16, .-test_vshl_u16

TEST_FUNC(test_vshl_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshl.u32        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshl_u32, .-test_vshl_u32

TEST_FUNC(test_vshl_u64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshl.u64        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshl_u64, .-test_vshl_u64

/* vshr.t */
TEST_FUNC(test_vshr_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshr.s8         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshr_s8, .-test_vshr_s8

TEST_FUNC(test_vshr_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshr.s16        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshr_s16, .-test_vshr_s16

TEST_FUNC(test_vshr_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshr.s32        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshr_s32, .-test_vshr_s32

TEST_FUNC(test_vshr_s64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshr.s64        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshr_s64, .-test_vshr_s64

TEST_FUNC(test_vshr_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshr.u8         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshr_u8, .-test_vshr_u8

TEST_FUNC(test_vshr_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshr.u16        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshr_u16, .-test_vshr_u16

TEST_FUNC(test_vshr_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshr.u32        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshr_u32, .-test_vshr_u32

TEST_FUNC(test_vshr_u64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshr.u64        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshr_u64, .-test_vshr_u64

/* vshr.t.r */
TEST_FUNC(test_vshr_s8_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshr.s8.r       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshr_s8_r, .-test_vshr_s8_r

TEST_FUNC(test_vshr_s16_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshr.s16.r      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshr_s16_r, .-test_vshr_s16_r

TEST_FUNC(test_vshr_s32_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshr.s32.r      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshr_s32_r, .-test_vshr_s32_r

TEST_FUNC(test_vshr_s64_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshr.s64.r      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshr_s64_r, .-test_vshr_s64_r

TEST_FUNC(test_vshr_u8_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshr.u8.r       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshr_u8_r, .-test_vshr_u8_r

TEST_FUNC(test_vshr_u16_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshr.u16.r      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshr_u16_r, .-test_vshr_u16_r

TEST_FUNC(test_vshr_u32_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshr.u32.r      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshr_u32_r, .-test_vshr_u32_r

TEST_FUNC(test_vshr_u64_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshr.u64.r      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshr_u64_r, .-test_vshr_u64_r

/* vshri.t */
TEST_FUNC(test_vshri_s8)
        vldm.32         vr0-vr0, (a0)
        vshri.s8        vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshri_s8, .-test_vshri_s8

TEST_FUNC(test_vshri_s16)
        vldm.32         vr0-vr0, (a0)
        vshri.s16       vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshri_s16, .-test_vshri_s16

TEST_FUNC(test_vshri_s32)
        vldm.32         vr0-vr0, (a0)
        vshri.s32       vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshri_s32, .-test_vshri_s32

TEST_FUNC(test_vshri_s64)
        vldm.32         vr0-vr0, (a0)
        vshri.s64       vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshri_s64, .-test_vshri_s64

TEST_FUNC(test_vshri_u8)
        vldm.32         vr0-vr0, (a0)
        vshri.u8        vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshri_u16, .-test_vshri_u16

TEST_FUNC(test_vshri_u16)
        vldm.32         vr0-vr0, (a0)
        vshri.u16       vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshri_u16, .-test_vshri_u16

TEST_FUNC(test_vshri_u32)
        vldm.32         vr0-vr0, (a0)
        vshri.u32       vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshri_u32, .-test_vshri_u32

TEST_FUNC(test_vshri_u64)
        vldm.32         vr0-vr0, (a0)
        vshri.u64       vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshri_u64, .-test_vshri_u64

/* vshri.t.r */
TEST_FUNC(test_vshri_s8_r)
        vldm.32         vr0-vr0, (a0)
        vshri.s8.r      vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshri_s8_r, .-test_vshri_s8_r

TEST_FUNC(test_vshri_s16_r)
        vldm.32         vr0-vr0, (a0)
        vshri.s16.r     vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshri_s16_r, .-test_vshri_s16_r

TEST_FUNC(test_vshri_s32_r)
        vldm.32         vr0-vr0, (a0)
        vshri.s32.r     vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshri_s32_r, .-test_vshri_s32_r

TEST_FUNC(test_vshri_s64_r)
        vldm.32         vr0-vr0, (a0)
        vshri.s64.r     vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshri_s64_r, .-test_vshri_s64_r

TEST_FUNC(test_vshri_u8_r)
        vldm.32         vr0-vr0, (a0)
        vshri.u8.r      vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshri_u16_r, .-test_vshri_u16_r

TEST_FUNC(test_vshri_u16_r)
        vldm.32         vr0-vr0, (a0)
        vshri.u16.r     vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshri_u16_r, .-test_vshri_u16_r

TEST_FUNC(test_vshri_u32_r)
        vldm.32         vr0-vr0, (a0)
        vshri.u32.r     vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshri_u32_r, .-test_vshri_u32_r

TEST_FUNC(test_vshri_u64_r)
        vldm.32         vr0-vr0, (a0)
        vshri.u64.r     vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshri_u64_r, .-test_vshri_u64_r

/* vshri.t.l */
TEST_FUNC(test_vshri_s16_l)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.s16.l     vr1, vr0, 8
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_s16_l, .-test_vshri_s16_l

TEST_FUNC(test_vshri_s32_l)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.s32.l     vr1, vr0, 16
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_s32_l, .-test_vshri_s32_l

TEST_FUNC(test_vshri_s64_l)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.s64.l     vr1, vr0,32
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_s64_l, .-test_vshri_s64_l

TEST_FUNC(test_vshri_u16_l)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.u16.l     vr1, vr0, 8
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_u16_l, .-test_vshri_u16_l

TEST_FUNC(test_vshri_u32_l)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.u32.l     vr1, vr0, 16
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_u32_l, .-test_vshri_u32_l

TEST_FUNC(test_vshri_u64_l)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.u64.l     vr1, vr0, 32
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_u64_l, .-test_vshri_u64_l

/* vshri.t.lr */
TEST_FUNC(test_vshri_s16_lr)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.s16.lr    vr1, vr0, 8
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_s16_lr, .-test_vshri_s16_lr

TEST_FUNC(test_vshri_s32_lr)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.s32.lr    vr1, vr0, 16
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_s32_lr, .-test_vshri_s32_lr

TEST_FUNC(test_vshri_s64_lr)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.s64.lr    vr1, vr0,32
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_s64_lr, .-test_vshri_s64_lr

TEST_FUNC(test_vshri_u16_lr)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.u16.lr    vr1, vr0, 8
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_u16_lr, .-test_vshri_u16_lr

TEST_FUNC(test_vshri_u32_lr)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.u32.lr    vr1, vr0, 16
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_u32_lr, .-test_vshri_u32_lr

TEST_FUNC(test_vshri_u64_lr)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.u64.lr    vr1, vr0, 32
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_u64_lr, .-test_vshri_u64_lr

/* vshri.t.ls */
TEST_FUNC(test_vshri_s16_ls)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.s16.ls    vr1, vr0, 4
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_s16_ls, .-test_vshri_s16_ls

TEST_FUNC(test_vshri_s32_ls)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.s32.ls    vr1, vr0, 12
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_s32_ls, .-test_vshri_s32_ls

TEST_FUNC(test_vshri_s64_ls)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.s64.ls    vr1, vr0, 28
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_s64_ls, .-test_vshri_s64_ls

TEST_FUNC(test_vshri_u16_ls)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.u16.ls    vr1, vr0, 4
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_u16_ls, .-test_vshri_u16_ls

TEST_FUNC(test_vshri_u32_ls)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.u32.ls    vr1, vr0, 12
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_u32_ls, .-test_vshri_u32_ls

TEST_FUNC(test_vshri_u64_ls)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.u64.ls    vr1, vr0, 28
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_u64_ls, .-test_vshri_u64_ls

/* vshri.t.lrs */
TEST_FUNC(test_vshri_s16_lrs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.s16.lrs   vr1, vr0, 4
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_s16_lrs, .-test_vshri_s16_lrs

TEST_FUNC(test_vshri_s32_lrs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.s32.lrs   vr1, vr0, 12
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_s32_lrs, .-test_vshri_s32_lrs

TEST_FUNC(test_vshri_s64_lrs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.s64.lrs   vr1, vr0, 28
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_s64_lrs, .-test_vshri_s64_lrs

TEST_FUNC(test_vshri_u16_lrs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.u16.lrs   vr1, vr0, 4
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_u16_lrs, .-test_vshri_u16_lrs

TEST_FUNC(test_vshri_u32_lrs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.u32.lrs   vr1, vr0, 12
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_u32_lrs, .-test_vshri_u32_lrs

TEST_FUNC(test_vshri_u64_lrs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshri.u64.lrs   vr1, vr0, 28
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshri_u64_lrs, .-test_vshri_u64_lrs

/* vshria.t */
TEST_FUNC(test_vshria_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshria.s8       vr1, vr0, 3
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshria_s16, .-test_vshria_s16

TEST_FUNC(test_vshria_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshria.s16      vr1, vr0, 3
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshria_s16, .-test_vshria_s16

TEST_FUNC(test_vshria_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshria.s32      vr1, vr0, 3
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshria_s32, .-test_vshria_s32

TEST_FUNC(test_vshria_s64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshria.s64      vr1, vr0, 3
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshria_s64, .-test_vshria_s64

TEST_FUNC(test_vshria_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshria.u16      vr1, vr0, 3
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshria_u16, .-test_vshria_u16

TEST_FUNC(test_vshria_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshria.u8       vr1, vr0, 3
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshria_u8, .-test_vshria_u8

TEST_FUNC(test_vshria_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshria.u32      vr1, vr0, 3
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshria_u32, .-test_vshria_u32

TEST_FUNC(test_vshria_u64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshria.u64      vr1, vr0, 3
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshria_u64, .-test_vshria_u64

/* vshria.t.r */
TEST_FUNC(test_vshria_s8_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshria.s8.r     vr1, vr0, 3
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshria_s16_r, .-test_vshria_s16_r

TEST_FUNC(test_vshria_s16_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshria.s16.r    vr1, vr0, 3
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshria_s16_r, .-test_vshria_s16_r

TEST_FUNC(test_vshria_s32_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshria.s32.r    vr1, vr0, 3
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshria_s32_r, .-test_vshria_s32_r

TEST_FUNC(test_vshria_s64_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshria.s64.r    vr1, vr0, 3
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshria_s64_r, .-test_vshria_s64_r

TEST_FUNC(test_vshria_u16_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshria.u16.r    vr1, vr0, 3
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshria_u16_r, .-test_vshria_u16_r

TEST_FUNC(test_vshria_u8_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshria.u8.r    vr1, vr0, 3
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshria_u8_r, .-test_vshria_u8_r

TEST_FUNC(test_vshria_u32_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshria.u32.r    vr1, vr0, 3
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshria_u32_r, .-test_vshria_u32_r

TEST_FUNC(test_vshria_u64_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshria.u64.r    vr1, vr0, 3
        vstm.32         vr1-vr1, (a2)
        rts
        .size   test_vshria_u64_r, .-test_vshria_u64_r

/* vexh.t */
TEST_FUNC(test_vexh_8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr2-vr2, (a2)
        vexh.8          vr2, vr0, a1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vexh_8, .-test_vexh_8

TEST_FUNC(test_vexh_16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr2-vr2, (a2)
        vexh.16         vr2, vr0, a1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vexh_16, .-test_vexh_16

TEST_FUNC(test_vexh_32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr2-vr2, (a2)
        vexh.32         vr2, vr0, a1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vexh_32, .-test_vexh_32

TEST_FUNC(test_vexh_64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr2-vr2, (a2)
        vexh.64         vr2, vr0, a1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vexh_64, .-test_vexh_64

/* vexl.t */
TEST_FUNC(test_vexl_8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr2-vr2, (a2)
        vexl.8          vr2, vr0, a1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vexl_8, .-test_vexl_8

TEST_FUNC(test_vexl_16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr2-vr2, (a2)
        vexl.16         vr2, vr0, a1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vexl_16, .-test_vexl_16

TEST_FUNC(test_vexl_32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr2-vr2, (a2)
        vexl.32         vr2, vr0, a1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vexl_32, .-test_vexl_32

TEST_FUNC(test_vexl_64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr2-vr2, (a2)
        vexl.64         vr2, vr0, a1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vexl_64, .-test_vexl_64

/* vshli.t */
TEST_FUNC(test_vshli_s8)
        vldm.32         vr0-vr0, (a0)
        vshli.s8        vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshli_s8, .-test_vshli_s8

TEST_FUNC(test_vshli_s16)
        vldm.32         vr0-vr0, (a0)
        vshli.s16       vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshli_s16, .-test_vshli_s16

TEST_FUNC(test_vshli_s32)
        vldm.32         vr0-vr0, (a0)
        vshli.s32       vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshli_s32, .-test_vshli_s32

TEST_FUNC(test_vshli_s64)
        vldm.32         vr0-vr0, (a0)
        vshli.s64       vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshli_s64, .-test_vshli_s64

TEST_FUNC(test_vshli_u8)
        vldm.32         vr0-vr0, (a0)
        vshli.u8        vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshli_u8, .-test_vshli_u8

TEST_FUNC(test_vshli_u16)
        vldm.32         vr0-vr0, (a0)
        vshli.u16       vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshli_u16, .-test_vshli_u16

TEST_FUNC(test_vshli_u32)
        vldm.32         vr0-vr0, (a0)
        vshli.u32       vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshli_u32, .-test_vshli_u32

TEST_FUNC(test_vshli_u64)
        vldm.32         vr0-vr0, (a0)
        vshli.u64       vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshli_u64, .-test_vshli_u64

/* vshli.t.s */
TEST_FUNC(test_vshli_s8_s)
        vldm.32         vr0-vr0, (a0)
        vshli.s8.s      vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshli_s8_s, .-test_vshli_s8_s

TEST_FUNC(test_vshli_s16_s)
        vldm.32         vr0-vr0, (a0)
        vshli.s16.s     vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshli_s16_s, .-test_vshli_s16_s

TEST_FUNC(test_vshli_s32_s)
        vldm.32         vr0-vr0, (a0)
        vshli.s32.s     vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshli_s32_s, .-test_vshli_s32_s

TEST_FUNC(test_vshli_s64_s)
        vldm.32         vr0-vr0, (a0)
        vshli.s64.s     vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshli_s64_s, .-test_vshli_s64_s

TEST_FUNC(test_vshli_u8_s)
        vldm.32         vr0-vr0, (a0)
        vshli.u8.s      vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshli_u8_s, .-test_vshli_u8_s

TEST_FUNC(test_vshli_u16_s)
        vldm.32         vr0-vr0, (a0)
        vshli.u16.s     vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshli_u16_s, .-test_vshli_u16_s

TEST_FUNC(test_vshli_u32_s)
        vldm.32         vr0-vr0, (a0)
        vshli.u32.s     vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshli_u32_s, .-test_vshli_u32_s

TEST_FUNC(test_vshli_u64_s)
        vldm.32         vr0-vr0, (a0)
        vshli.u64.s     vr1, vr0, 3
        vstm.32         vr1-vr1, (a1)
        rts
        .size   test_vshli_u64_s, .-test_vshli_u64_s

/* vshli.t.e */
TEST_FUNC(test_vshli_s8_e)
        vldm.32         vr0-vr0, (a0)
        vshli.s8.e      vr1, vr0, 4
        vstm.32         vr1-vr1, (a1)
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshli_s8_e, .-test_vshli_s8_e

TEST_FUNC(test_vshli_s16_e)
        vldm.32         vr0-vr0, (a0)
        vshli.s16.e     vr1, vr0, 4
        vstm.32         vr1-vr1, (a1)
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshli_s16_e, .-test_vshli_s16_e

TEST_FUNC(test_vshli_s32_e)
        vldm.32         vr0-vr0, (a0)
        vshli.s32.e     vr1, vr0, 4
        vstm.32         vr1-vr1, (a1)
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshli_s32_e, .-test_vshli_s32_e

TEST_FUNC(test_vshli_u8_e)
        vldm.32         vr0-vr0, (a0)
        vshli.u8.e      vr1, vr0, 4
        vstm.32         vr1-vr1, (a1)
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshli_u8_e, .-test_vshli_u8_e

TEST_FUNC(test_vshli_u16_e)
        vldm.32         vr0-vr0, (a0)
        vshli.u16.e     vr1, vr0, 4
        vstm.32         vr1-vr1, (a1)
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshli_u16_e, .-test_vshli_u16_e

TEST_FUNC(test_vshli_u32_e)
        vldm.32         vr0-vr0, (a0)
        vshli.u32.e     vr1, vr0, 4
        vstm.32         vr1-vr1, (a1)
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshli_u32_e, .-test_vshli_u32_e

/* vshl.t.s */
TEST_FUNC(test_vshl_s8_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshl.s8.s       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshl_s8_s, .-test_vshl_s8_s

TEST_FUNC(test_vshl_s16_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshl.s16.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshl_s16_s, .-test_vshl_s16_s

TEST_FUNC(test_vshl_s32_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshl.s32.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshl_s32_s, .-test_vshl_s32_s

TEST_FUNC(test_vshl_s64_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshl.s64.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshl_s64_s, .-test_vshl_s64_s

TEST_FUNC(test_vshl_u8_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshl.u8.s       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshl_u8_s, .-test_vshl_u8_s

TEST_FUNC(test_vshl_u16_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshl.u16.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshl_u16_s, .-test_vshl_u16_s

TEST_FUNC(test_vshl_u32_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshl.u32.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshl_u32_s, .-test_vshl_u32_s

TEST_FUNC(test_vshl_u64_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vshl.u64.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vshl_u64_s, .-test_vshl_u64_s


/* vsht.t.r */
TEST_FUNC(test_vsht_s8_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.s8.r       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_s8_r, .-test_vsht_s8_r

TEST_FUNC(test_vsht_s16_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.s16.r      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_s16_r, .-test_vsht_s16_r

TEST_FUNC(test_vsht_s32_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.s32.r      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_s32_r, .-test_vsht_s32_r

TEST_FUNC(test_vsht_s64_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.s64.r      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_s64_r, .-test_vsht_s64_r

TEST_FUNC(test_vsht_u8_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.u8.r       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_u8_r, .-test_vsht_u8_r

TEST_FUNC(test_vsht_u16_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.u16.r      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_u16_r, .-test_vsht_u16_r

TEST_FUNC(test_vsht_u32_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.u32.r      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_u32_r, .-test_vsht_u32_r

TEST_FUNC(test_vsht_u64_r)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.u64.r      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_u64_r, .-test_vsht_u64_r

/* vsht.t.s */
TEST_FUNC(test_vsht_s8_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.s8.s       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_s8_s, .-test_vsht_s8_s

TEST_FUNC(test_vsht_s16_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.s16.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_s16_s, .-test_vsht_s16_s

TEST_FUNC(test_vsht_s32_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.s32.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_s32_s, .-test_vsht_s32_s

TEST_FUNC(test_vsht_s64_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.s64.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_s64_s, .-test_vsht_s64_s

TEST_FUNC(test_vsht_u8_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.u8.s       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_u8_s, .-test_vsht_u8_s

TEST_FUNC(test_vsht_u16_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.u16.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_u16_s, .-test_vsht_u16_s

TEST_FUNC(test_vsht_u32_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.u32.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_u32_s, .-test_vsht_u32_s

TEST_FUNC(test_vsht_u64_s)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.u64.s      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_u64_s, .-test_vsht_u64_s

/* vsht.t.rs */
TEST_FUNC(test_vsht_s8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.s8.rs      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_s8_rs, .-test_vsht_s8_rs

TEST_FUNC(test_vsht_s16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.s16.rs     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_s16_rs, .-test_vsht_s16_rs

TEST_FUNC(test_vsht_s32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.s32.rs     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_s32_rs, .-test_vsht_s32_rs

TEST_FUNC(test_vsht_s64_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.s64.rs     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_s64_rs, .-test_vsht_s64_rs

TEST_FUNC(test_vsht_u8_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.u8.rs      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_u8_rs, .-test_vsht_u8_rs

TEST_FUNC(test_vsht_u16_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.u16.rs     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_u16_rs, .-test_vsht_u16_rs

TEST_FUNC(test_vsht_u32_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.u32.rs     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_u32_rs, .-test_vsht_u32_rs

TEST_FUNC(test_vsht_u64_rs)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsht.u64.rs     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vsht_u64_rs, .-test_vsht_u64_rs

/* vmov.t.e */
TEST_FUNC(test_vmov_s8_e)
        vldm.32         vr0-vr0, (a0)
        vmov.s8.e       vr1, vr0
        vstm.32         vr1-vr1, (a1)
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_s8_e, .-test_vmov_s8_e

TEST_FUNC(test_vmov_s16_e)
        vldm.32         vr0-vr0, (a0)
        vmov.s16.e      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_s16_e, .-test_vmov_s16_e

TEST_FUNC(test_vmov_s32_e)
        vldm.32         vr0-vr0, (a0)
        vmov.s32.e      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_s32_e, .-test_vmov_s32_e

TEST_FUNC(test_vmov_u8_e)
        vldm.32         vr0-vr0, (a0)
        vmov.u8.e       vr1, vr0
        vstm.32         vr1-vr1, (a1)
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_u8_e, .-test_vmov_u8_e

TEST_FUNC(test_vmov_u16_e)
        vldm.32         vr0-vr0, (a0)
        vmov.u16.e      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_u16_e, .-test_vmov_u16_e

TEST_FUNC(test_vmov_u32_e)
        vldm.32         vr0-vr0, (a0)
        vmov.u32.e      vr1, vr0
        vstm.32         vr1-vr1, (a1)
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_u32_e, .-test_vmov_u32_e

/* vmov.t.l */
TEST_FUNC(test_vmov_16_l)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmov.16.l       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_16_l, .-test_vmov_16_l

TEST_FUNC(test_vmov_32_l)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmov.32.l       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_32_l, .-test_vmov_32_l

TEST_FUNC(test_vmov_64_l)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmov.64.l       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_64_l, .-test_vmov_64_l

/* vmov.t.h */
TEST_FUNC(test_vmov_16_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmov.16.h       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_16_h, .-test_vmov_16_h

TEST_FUNC(test_vmov_32_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmov.32.h       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_32_h, .-test_vmov_32_h

TEST_FUNC(test_vmov_64_h)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vmov.64.h       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vmov_64_h, .-test_vmov_64_h

/* vand.t */
TEST_FUNC(test_vand_8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vand.8          vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vand_8, .-test_vand_8

TEST_FUNC(test_vand_16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vand.16         vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vand_16, .-test_vand_16

TEST_FUNC(test_vand_32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vand.32         vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vand_32, .-test_vand_32

TEST_FUNC(test_vand_64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vand.64         vr2, vr1, vr0
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vand_64, .-test_vand_64

/* vandn.t */
TEST_FUNC(test_vandn_8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vandn.8         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vandn_8, .-test_vandn_8

TEST_FUNC(test_vandn_16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vandn.16        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vandn_16, .-test_vandn_16

TEST_FUNC(test_vandn_32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vandn.32        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vandn_32, .-test_vandn_32

TEST_FUNC(test_vandn_64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vandn.64        vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vandn_64, .-test_vandn_64

/* vor.t */
TEST_FUNC(test_vor_8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vor.8           vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vor_8, .-test_vor_8

TEST_FUNC(test_vor_16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vor.16          vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vor_16, .-test_vor_16

TEST_FUNC(test_vor_32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vor.32          vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vor_32, .-test_vor_32

TEST_FUNC(test_vor_64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vor.64          vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vor_64, .-test_vor_64

/* vxor.t */
TEST_FUNC(test_vxor_8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vxor.8          vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vxor_8, .-test_vxor_8

TEST_FUNC(test_vxor_16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vxor.16         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vxor_16, .-test_vxor_16

TEST_FUNC(test_vxor_32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vxor.32         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vxor_32, .-test_vxor_32

TEST_FUNC(test_vxor_64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vxor.64         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vxor_64, .-test_vxor_64

/* vorn.t */
TEST_FUNC(test_vorn_8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vorn.8          vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vorn_8, .-test_vorn_8

TEST_FUNC(test_vorn_16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vorn.16         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vorn_16, .-test_vorn_16

TEST_FUNC(test_vorn_32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vorn.32         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vorn_32, .-test_vorn_32

TEST_FUNC(test_vorn_64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vorn.64         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        rts
        .size   test_vorn_64, .-test_vorn_64

/* vsabs.t.e */
TEST_FUNC(test_vsabs_s8_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsabs.s8.e              vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsabs_s8_e, .-test_vsabs_s8_e

TEST_FUNC(test_vsabs_s16_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsabs.s16.e     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsabs_s16_e, .-test_vsabs_s16_e

TEST_FUNC(test_vsabs_s32_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsabs.s32.e     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsabs_s32_e, .-test_vsabs_s32_e

TEST_FUNC(test_vsabs_u8_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsabs.u8.e              vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsabs_u8_e, .-test_vsabs_u8_e

TEST_FUNC(test_vsabs_u16_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsabs.u16.e     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsabs_u16_e, .-test_vsabs_u16_e

TEST_FUNC(test_vsabs_u32_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vsabs.u32.e     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsabs_u32_e, .-test_vsabs_u32_e

/* vsabsa.t */
TEST_FUNC(test_vsabsa_s8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vsabsa.s8       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vsabsa_s8, .-test_vsabsa_s8

TEST_FUNC(test_vsabsa_s16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vsabsa.s16      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vsabsa_s16, .-test_vsabsa_s16

TEST_FUNC(test_vsabsa_s32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vsabsa.s32      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vsabsa_s32, .-test_vsabsa_s32

TEST_FUNC(test_vsabsa_u8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vsabsa.u8       vr2, vr0, vr1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vsabsa_u8, .-test_vsabsa_u8

TEST_FUNC(test_vsabsa_u16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vsabsa.u16      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vsabsa_u16, .-test_vsabsa_u16

TEST_FUNC(test_vsabsa_u32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vsabsa.u32      vr2, vr0, vr1
        vstm.32         vr2-vr2, (a3)
        rts
        .size   test_vsabsa_u32, .-test_vsabsa_u32

/* vsabsa.t.e */
TEST_FUNC(test_vsabsa_s8_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vldm.32         vr3-vr3, (a3)
        vsabsa.s8.e     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsabsa_s8_e, .-test_vsabsa_s8_e

TEST_FUNC(test_vsabsa_s16_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vldm.32         vr3-vr3, (a3)
        vsabsa.s16.e    vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsabsa_s16_e, .-test_vsabsa_s16_e

TEST_FUNC(test_vsabsa_s32_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vldm.32         vr3-vr3, (a3)
        vsabsa.s32.e    vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsabsa_s32_e, .-test_vsabsa_s32_e

TEST_FUNC(test_vsabsa_u8_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vldm.32         vr3-vr3, (a3)
        vsabsa.u8.e     vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsabsa_u8_e, .-test_vsabsa_u8_e

TEST_FUNC(test_vsabsa_u16_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vldm.32         vr3-vr3, (a3)
        vsabsa.u16.e    vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsabsa_u16_e, .-test_vsabsa_u16_e

TEST_FUNC(test_vsabsa_u32_e)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vldm.32         vr3-vr3, (a3)
        vsabsa.u32.e    vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsabsa_u32_e, .-test_vsabsa_u32_e

/* vsel.t */
TEST_FUNC(test_vsel_8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vsel.8          vr3, vr0, vr1, vr2
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsel_8, .-test_vsel_8

TEST_FUNC(test_vsel_16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vsel.16         vr3, vr0, vr1, vr2
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsel_16, .-test_vsel_16

TEST_FUNC(test_vsel_32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vsel.32         vr3, vr0, vr1, vr2
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsel_32, .-test_vsel_32

TEST_FUNC(test_vsel_64)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vldm.32         vr2-vr2, (a2)
        vsel.64         vr3, vr0, vr1, vr2
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vsel_64, .-test_vsel_64

/* vtrn.t */
TEST_FUNC(test_vtrn_8)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vtrn.8          vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vtrn_8, .-test_vtrn_8

TEST_FUNC(test_vtrn_16)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vtrn.16         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vtrn_16, .-test_vtrn_16

TEST_FUNC(test_vtrn_32)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vtrn.32         vr2, vr0, vr1
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vtrn_32, .-test_vtrn_32

/* vitl.t.2 */
TEST_FUNC(test_vitl_8_2)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vitl.8.2        vr2, vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vitl_8_2, .-test_vitl_8_2

TEST_FUNC(test_vitl_16_2)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vitl.16.2       vr2,  vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vitl_16_2, .-test_vitl_16_2

TEST_FUNC(test_vitl_32_2)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vitl.32.2       vr2,  vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vitl_32_2, .-test_vitl_32_2

/* vdtl.t.2 */
TEST_FUNC(test_vdtl_8_2)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vdtl.8.2        vr2, vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vdtl_8_2, .-test_vdtl_8_2

TEST_FUNC(test_vdtl_16_2)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vdtl.16.2       vr2,  vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vdtl_16_2, .-test_vdtl_16_2

TEST_FUNC(test_vdtl_32_2)
        vldm.32         vr0-vr0, (a0)
        vldm.32         vr1-vr1, (a1)
        vdtl.32.2       vr2,  vr0
        vstm.32         vr2-vr2, (a2)
        vstm.32         vr3-vr3, (a3)
        rts
        .size   test_vdtl_32_2, .-test_vdtl_32_2


