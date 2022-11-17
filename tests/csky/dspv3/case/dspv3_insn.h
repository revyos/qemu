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

#ifndef DSPV3_INSN_H
#define DSPV3_INSN_H
union VDSP {
    uint64_t udspl[2];
    int64_t  dspl[2];
    uint32_t udspi[4];
    int32_t  dspi[4];
    uint16_t udsps[8];
    int16_t  dsps[8];
    uint8_t  udspc[16];
    int8_t   dspc[16];
};


struct vdsp_reg {
    int8_t   fixs8[16];
    int16_t  fixs16[8];
    int32_t  fixs32[4];
    int64_t  fixs64[2];
    uint8_t  fixu8[16];
    uint16_t fixu16[8];
    uint32_t fixu32[4];
    uint64_t fixu64[2];
    uint32_t float32[4];
    uint16_t float16[8];
};

//#define DEBUG
static inline void result_compare_s8(int8_t *dst, int8_t *ref)
{
    int i;
    for (i = 0; i < 16; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%02hhx, ",dst[i]);
    }
    for (i = 0; i < 16; i++) {
        printf("0x%02hhx, ",dst[i]);
#endif
    }
}

static inline void result_compare_s16(int16_t *dst, int16_t *ref)
{
    int i;
    for (i = 0; i < 8; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%04hx, ",dst[i]);
    }
    for (i = 0; i < 8; i++) {
        printf("0x%04hx, ",dst[i]);
#endif
    }
}

static inline void result_compare_s32(int32_t *dst, int32_t *ref)
{
    int i;
    for (i = 0; i < 4; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%x, ",dst[i]);
    }
    for (i = 0; i < 4; i++) {
        printf("0x%x, ",dst[i]);
#endif
    }
}

static inline void result_compare_s64(int64_t *dst, int64_t *ref)
{
    int i;
    for (i = 0; i < 2; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%16llx, ",dst[i]);
    }
    for (i = 0; i < 2; i++) {
        printf("0x%16llx, ",dst[i]);
#endif
    }
}

static inline void result_compare_u8(uint8_t *dst, uint8_t *ref)
{
    int i;
    for (i = 0; i < 16; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%02hhx, ",dst[i]);
    }
    for (i = 0; i < 16; i++) {
        printf("0x%02hhx, ",dst[i]);
#endif
    }
}

static inline void result_compare_u16(uint16_t *dst, uint16_t *ref)
{
    int i;
    for (i = 0; i < 8; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%04hx, ",dst[i]);
    }
    for (i = 0; i < 8; i++) {
        printf("0x%04hx, ",dst[i]);
#endif
    }
}

static inline void result_compare_u32(uint32_t *dst, uint32_t *ref)
{
    int i;
    for (i = 0; i < 4; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%x, ",dst[i]);
    }
    for (i = 0; i < 4; i++) {
        printf("0x%x, ",dst[i]);
#endif
    }
}

static inline void result_compare_u64(uint64_t *dst, uint64_t *ref)
{
    int i;
    for (i = 0; i < 2; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%16llx, ",dst[i]);
    }
    for (i = 0; i < 2; i++) {
        printf("0x%16llx, ",dst[i]);
#endif
    }
}

inline void result_compare_f32(uint32_t *dst, uint32_t *ref)
{
    int i;
#ifdef DEBUG
    for (i = 0; i < 4; i++) {
        TEST(dst[i] == ref[i]);
        printf("0x%x, ",dst[i]);
    }
    printf("\n");
    for (i = 0; i < 4; i++) {
        printf("0x%x, ",ref[i]);
    }
    printf("\n");
#else
    for (i = 0; i < 4; i++) {
        TEST(dst[i] == ref[i]);
    }
#endif
}

inline void result_compare_f16(uint16_t *dst, uint16_t *ref)
{
    int i;
#ifdef DEBUG
    for (i = 0; i < 8; i++) {
        TEST(dst[i] == ref[i]);
        printf("0x%x, ",dst[i]);
    }
    printf("\n");
    for (i = 0; i < 8; i++) {
        printf("0x%x, ",ref[i]);
    }
    printf("\n");
#else
    for (i = 0; i < 8; i++) {
        TEST(dst[i] == ref[i]);
    }
#endif
}

void test_vabs_s8(void *a, void *b);
void test_vabs_s16(void *a, void *b);
void test_vabs_s32(void *a, void *b);
void test_vabs_f32(void *a, void *b);
void test_vabs_f16(void *a, void *b);
void test_vabs_s8_s(void *a, void *b);
void test_vabs_s16_s(void *a, void *b);
void test_vabs_s32_s(void *a, void *b);
void test_vneg_s8(void *a, void *b);
void test_vneg_s16(void *a, void *b);
void test_vneg_s32(void *a, void *b);
void test_vneg_f32(void *a, void *b);
void test_vneg_f16(void *a, void *b);
void test_vneg_s8_s(void *a, void *b);
void test_vneg_s16_s(void *a, void *b);
void test_vneg_s32_s(void *a, void *b);
void test_vcls_s8(void *a, void *b);
void test_vcls_s16(void *a, void *b);
void test_vcls_s32(void *a, void *b);
void test_vclz_8(void *a, void *b);
void test_vclz_16(void *a, void *b);
void test_vclz_32(void *a, void *b);
void test_vclz_64(void *a, void *b);
void test_vnot_8(void *a, void *b);
void test_vnot_16(void *a, void *b);
void test_vnot_32(void *a, void *b);
void test_vnot_64(void *a, void *b);
void test_vcnt1_8(void *a, void *b);
void test_vcnt1_16(void *a, void *b);
void test_vcnt1_32(void *a, void *b);
void test_vcnt1_64(void *a, void *b);
void test_vadd_s8(void *a, void *b, void *c);
void test_vadd_s16(void *a, void *b, void *c);
void test_vadd_s32(void *a, void *b, void *c);
void test_vadd_s64(void *a, void *b, void *c);
void test_vadd_u8(void *a, void *b, void *c);
void test_vadd_u16(void *a, void *b, void *c);
void test_vadd_u32(void *a, void *b, void *c);
void test_vadd_u64(void *a, void *b, void *c);
void test_vadd_f32(void *a, void *b, void *c);
void test_vadd_f16(void *a, void *b, void *c);
void test_vaddh_s8(void *a, void *b, void *c);
void test_vaddh_s16(void *a, void *b, void *c);
void test_vaddh_s32(void *a, void *b, void *c);
void test_vaddh_u8(void *a, void *b, void *c);
void test_vaddh_u16(void *a, void *b, void *c);
void test_vaddh_u32(void *a, void *b, void *c);
void test_vaddh_s8_r(void *a, void *b, void *c);
void test_vaddh_s16_r(void *a, void *b, void *c);
void test_vaddh_s32_r(void *a, void *b, void *c);
void test_vaddh_u8_r(void *a, void *b, void *c);
void test_vaddh_u16_r(void *a, void *b, void *c);
void test_vaddh_u32_r(void *a, void *b, void *c);
void test_vsubh_s8_r(void *a, void *b, void *c);
void test_vsubh_s16_r(void *a, void *b, void *c);
void test_vsubh_s32_r(void *a, void *b, void *c);
void test_vsubh_u8_r(void *a, void *b, void *c);
void test_vsubh_u16_r(void *a, void *b, void *c);
void test_vsubh_u32_r(void *a, void *b, void *c);
void test_vpadd_s8(void *a, void *b, void *c);
void test_vpadd_s16(void *a, void *b, void *c);
void test_vpadd_s32(void *a, void *b, void *c);
void test_vpadd_u8(void *a, void *b, void *c);
void test_vpadd_u16(void *a, void *b, void *c);
void test_vpadd_u32(void *a, void *b, void *c);
void test_vpadd_f32(void *a, void *b, void *c);
void test_vpadd_f16(void *a, void *b, void *c);
void test_vpadd_s8_s(void *a, void *b, void *c);
void test_vpadd_s16_s(void *a, void *b, void *c);
void test_vpadd_s32_s(void *a, void *b, void *c);
void test_vpadd_u8_s(void *a, void *b, void *c);
void test_vpadd_u16_s(void *a, void *b, void *c);
void test_vpadd_u32_s(void *a, void *b, void *c);
void test_vpadd_s8_e(void *a, void *b);
void test_vpadd_s16_e(void *a, void *b);
void test_vpadd_s32_e(void *a, void *b);
void test_vpadd_u8_e(void *a, void *b);
void test_vpadd_u16_e(void *a, void *b);
void test_vpadd_u32_e(void *a, void *b);
void test_vpadda_s8_e(void *a, void *b, void *c);
void test_vpadda_s16_e(void *a, void *b, void *c);
void test_vpadda_s32_e(void *a, void *b, void *c);
void test_vpadda_u8_e(void *a, void *b, void *c);
void test_vpadda_u16_e(void *a, void *b, void *c);
void test_vpadda_u32_e(void *a, void *b, void *c);
void test_vasx_s8_s(void *a, void *b, void *c);
void test_vasx_s16_s(void *a, void *b, void *c);
void test_vasx_s32_s(void *a, void *b, void *c);
void test_vasx_u8_s(void *a, void *b, void *c);
void test_vasx_u16_s(void *a, void *b, void *c);
void test_vasx_u32_s(void *a, void *b, void *c);
void test_vasx_f32(void *a, void *b, void *c);
void test_vasx_f16(void *a, void *b, void *c);
void test_vsax_s8_s(void *a, void *b, void *c);
void test_vsax_s16_s(void *a, void *b, void *c);
void test_vsax_s32_s(void *a, void *b, void *c);
void test_vsax_u8_s(void *a, void *b, void *c);
void test_vsax_u16_s(void *a, void *b, void *c);
void test_vsax_u32_s(void *a, void *b, void *c);
void test_vsax_f32(void *a, void *b, void *c);
void test_vsax_f16(void *a, void *b, void *c);
void test_vasxh_s8(void *a, void *b, void *c);
void test_vasxh_s16(void *a, void *b, void *c);
void test_vasxh_s32(void *a, void *b, void *c);
void test_vasxh_u8(void *a, void *b, void *c);
void test_vasxh_u16(void *a, void *b, void *c);
void test_vasxh_u32(void *a, void *b, void *c);
void test_vsaxh_s8(void *a, void *b, void *c);
void test_vsaxh_s16(void *a, void *b, void *c);
void test_vsaxh_s32(void *a, void *b, void *c);
void test_vsaxh_u8(void *a, void *b, void *c);
void test_vsaxh_u16(void *a, void *b, void *c);
void test_vsaxh_u32(void *a, void *b, void *c);
void test_vadd_s8_s(void *a, void *b, void *c);
void test_vadd_s16_s(void *a, void *b, void *c);
void test_vadd_s32_s(void *a, void *b, void *c);
void test_vadd_s64_s(void *a, void *b, void *c);
void test_vadd_u8_s(void *a, void *b, void *c);
void test_vadd_u16_s(void *a, void *b, void *c);
void test_vadd_u32_s(void *a, void *b, void *c);
void test_vadd_u64_s(void *a, void *b, void *c);
void test_vadd_s16_h(void *a, void *b, void *c);
void test_vadd_s32_h(void *a, void *b, void *c);
void test_vadd_s64_h(void *a, void *b, void *c);
void test_vadd_u16_h(void *a, void *b, void *c);
void test_vadd_u32_h(void *a, void *b, void *c);
void test_vadd_u64_h(void *a, void *b, void *c);
void test_vadd_s16_rh(void *a, void *b, void *c);
void test_vadd_s32_rh(void *a, void *b, void *c);
void test_vadd_s64_rh(void *a, void *b, void *c);
void test_vadd_u16_rh(void *a, void *b, void *c);
void test_vadd_u32_rh(void *a, void *b, void *c);
void test_vadd_u64_rh(void *a, void *b, void *c);
void test_vsub_s16_h(void *a, void *b, void *c);
void test_vsub_s32_h(void *a, void *b, void *c);
void test_vsub_s64_h(void *a, void *b, void *c);
void test_vsub_u16_h(void *a, void *b, void *c);
void test_vsub_u32_h(void *a, void *b, void *c);
void test_vsub_u64_h(void *a, void *b, void *c);
void test_vsub_s16_rh(void *a, void *b, void *c);
void test_vsub_s32_rh(void *a, void *b, void *c);
void test_vsub_s64_rh(void *a, void *b, void *c);
void test_vsub_u16_rh(void *a, void *b, void *c);
void test_vsub_u32_rh(void *a, void *b, void *c);
void test_vsub_u64_rh(void *a, void *b, void *c);
void test_vadd_s8_e(void *a, void *b, void *c, void *d);
void test_vadd_s16_e(void *a, void *b, void *c, void *d);
void test_vadd_s32_e(void *a, void *b, void *c, void *d);
void test_vadd_u8_e(void *a, void *b, void *c, void *d);
void test_vadd_u16_e(void *a, void *b, void *c, void *d);
void test_vadd_u32_e(void *a, void *b, void *c, void *d);
void test_vsub_s8_e(void *a, void *b, void *c, void *d);
void test_vsub_s16_e(void *a, void *b, void *c, void *d);
void test_vsub_s32_e(void *a, void *b, void *c, void *d);
void test_vsub_u8_e(void *a, void *b, void *c, void *d);
void test_vsub_u16_e(void *a, void *b, void *c, void *d);
void test_vsub_u32_e(void *a, void *b, void *c, void *d);
void test_vadd_s8_x(void *a, void *b, void *c, void *d);
void test_vadd_s16_x(void *a, void *b, void *c, void *d);
void test_vadd_s32_x(void *a, void *b, void *c, void *d);
void test_vadd_u8_x(void *a, void *b, void *c, void *d);
void test_vadd_u16_x(void *a, void *b, void *c, void *d);
void test_vadd_u32_x(void *a, void *b, void *c, void *d);
void test_vsub_s8_x(void *a, void *b, void *c, void *d);
void test_vsub_s16_x(void *a, void *b, void *c, void *d);
void test_vsub_s32_x(void *a, void *b, void *c, void *d);
void test_vsub_u8_x(void *a, void *b, void *c, void *d);
void test_vsub_u16_x(void *a, void *b, void *c, void *d);
void test_vsub_u32_x(void *a, void *b, void *c, void *d);
void test_vmul_s8(void *a, void *b, void *c);
void test_vmul_s16(void *a, void *b, void *c);
void test_vmul_s32(void *a, void *b, void *c);
void test_vmul_u8(void *a, void *b, void *c);
void test_vmul_u16(void *a, void *b, void *c);
void test_vmul_u32(void *a, void *b, void *c);
void test_vmul_f32(void *a, void *b, void *c);
void test_vmul_f16(void *a, void *b, void *c);
void test_vmuli_s8(void *a, void *b, void *c);
void test_vmuli_s16(void *a, void *b, void *c);
void test_vmuli_s32(void *a, void *b, void *c);
void test_vmuli_u8(void *a, void *b, void *c);
void test_vmuli_u16(void *a, void *b, void *c);
void test_vmuli_u32(void *a, void *b, void *c);
void test_vmuli_f32(void *a, void *b, void *c);
void test_vmuli_f16(void *a, void *b, void *c);
void test_vmul_s8_h(void *a, void *b, void *c);
void test_vmul_s16_h(void *a, void *b, void *c);
void test_vmul_s32_h(void *a, void *b, void *c);
void test_vmul_u8_h(void *a, void *b, void *c);
void test_vmul_u16_h(void *a, void *b, void *c);
void test_vmul_u32_h(void *a, void *b, void *c);
void test_vmuli_s8_h(void *a, void *b, void *c);
void test_vmuli_s16_h(void *a, void *b, void *c);
void test_vmuli_s32_h(void *a, void *b, void *c);
void test_vmuli_u8_h(void *a, void *b, void *c);
void test_vmuli_u16_h(void *a, void *b, void *c);
void test_vmuli_u32_h(void *a, void *b, void *c);
void test_vmul_s8_e(void *a, void *b, void *c, void *d);
void test_vmul_s16_e(void *a, void *b, void *c, void *d);
void test_vmul_s32_e(void *a, void *b, void *c, void *d);
void test_vmul_u8_e(void *a, void *b, void *c, void *d);
void test_vmul_u16_e(void *a, void *b, void *c, void *d);
void test_vmul_u32_e(void *a, void *b, void *c, void *d);
void test_vmuli_s8_e(void *a, void *b, void *c, void *d);
void test_vmuli_s16_e(void *a, void *b, void *c, void *d);
void test_vmuli_s32_e(void *a, void *b, void *c, void *d);
void test_vmuli_u8_e(void *a, void *b, void *c, void *d);
void test_vmuli_u16_e(void *a, void *b, void *c, void *d);
void test_vmuli_u32_e(void *a, void *b, void *c, void *d);
void test_vmula_s8(void *a, void *b, void *c);
void test_vmula_s16(void *a, void *b, void *c);
void test_vmula_s32(void *a, void *b, void *c);
void test_vmula_u8(void *a, void *b, void *c);
void test_vmula_u16(void *a, void *b, void *c);
void test_vmula_u32(void *a, void *b, void *c);
void test_vmula_f32(void *a, void *b, void *c);
void test_vmula_f16(void *a, void *b, void *c);
void test_vmulai_s8(void *a, void *b, void *c);
void test_vmulai_s16(void *a, void *b, void *c);
void test_vmulai_s32(void *a, void *b, void *c);
void test_vmulai_u8(void *a, void *b, void *c);
void test_vmulai_u16(void *a, void *b, void *c);
void test_vmulai_u32(void *a, void *b, void *c);
void test_vmulai_f32(void *a, void *b, void *c);
void test_vmulai_f16(void *a, void *b, void *c);
void test_vmula_s8_e(void *a, void *b);
void test_vmula_s16_e(void *a, void *b);
void test_vmula_s32_e(void *a, void *b);
void test_vmula_u8_e(void *a, void *b);
void test_vmula_u16_e(void *a, void *b);
void test_vmula_u32_e(void *a, void *b);
void test_vmulai_s8_e(void *a, void *b);
void test_vmulai_s16_e(void *a, void *b);
void test_vmulai_s32_e(void *a, void *b);
void test_vmulai_u8_e(void *a, void *b);
void test_vmulai_u16_e(void *a, void *b);
void test_vmulai_u32_e(void *a, void *b);
void test_vmuls_s8(void *a, void *b, void *c);
void test_vmuls_s16(void *a, void *b, void *c);
void test_vmuls_s32(void *a, void *b, void *c);
void test_vmuls_u8(void *a, void *b, void *c);
void test_vmuls_u16(void *a, void *b, void *c);
void test_vmuls_u32(void *a, void *b, void *c);
void test_vmuls_f32(void *a, void *b, void *c);
void test_vmuls_f16(void *a, void *b, void *c);
void test_vmulsi_s8(void *a, void *b, void *c);
void test_vmulsi_s16(void *a, void *b, void *c);
void test_vmulsi_s32(void *a, void *b, void *c);
void test_vmulsi_u8(void *a, void *b, void *c);
void test_vmulsi_u16(void *a, void *b, void *c);
void test_vmulsi_u32(void *a, void *b, void *c);
void test_vmulsi_f32(void *a, void *b, void *c);
void test_vmulsi_f16(void *a, void *b, void *c);
void test_vmuls_s8_e(void *a, void *b);
void test_vmuls_s16_e(void *a, void *b);
void test_vmuls_s32_e(void *a, void *b);
void test_vmuls_u8_e(void *a, void *b);
void test_vmuls_u16_e(void *a, void *b);
void test_vmuls_u32_e(void *a, void *b);
void test_vmulsi_s8_e(void *a, void *b);
void test_vmulsi_s16_e(void *a, void *b);
void test_vmulsi_s32_e(void *a, void *b);
void test_vmulsi_u8_e(void *a, void *b);
void test_vmulsi_u16_e(void *a, void *b);
void test_vmulsi_u32_e(void *a, void *b);
void test_vmulaca_s8(void *a, void *b, void *c);
void test_vmulaca_s16(void *a, void *b, void *c);
void test_vmulaca_u8(void *a, void *b, void *c);
void test_vmulaca_u16(void *a, void *b, void *c);
void test_vmulacaa_s8(void *a, void *b, void *c, void *d);
void test_vmulacaa_s16(void *a, void *b, void *c, void *d);
void test_vmulacaa_u8(void *a, void *b, void *c, void *d);
void test_vmulacaa_u16(void *a, void *b, void *c, void *d);
void test_vmulacai_s8(void *a, void *b, void *c);
void test_vmulacai_s16(void *a, void *b, void *c);
void test_vmulacai_u8(void *a, void *b, void *c);
void test_vmulacai_u16(void *a, void *b, void *c);
void test_vmulacaai_s8(void *a, void *b, void *c, void *d);
void test_vmulacaai_s16(void *a, void *b, void *c, void *d);
void test_vmulacaai_u8(void *a, void *b, void *c, void *d);
void test_vmulacaai_u16(void *a, void *b, void *c, void *d);
void test_vrmul_s8_se(void *a, void *b, void *c, void *d);
void test_vrmul_s16_se(void *a, void *b, void *c, void *d);
void test_vrmul_s32_se(void *a, void *b, void *c, void *d);
void test_vrmuli_s8_se(void *a, void *b, void *c, void *d);
void test_vrmuli_s16_se(void *a, void *b, void *c, void *d);
void test_vrmuli_s32_se(void *a, void *b, void *c, void *d);
void test_vrmulh_s8_s(void *a, void *b, void *c);
void test_vrmulh_s16_s(void *a, void *b, void *c);
void test_vrmulh_s32_s(void *a, void *b, void *c);
void test_vrmulhi_s8_s(void *a, void *b, void *c);
void test_vrmulhi_s16_s(void *a, void *b, void *c);
void test_vrmulhi_s32_s(void *a, void *b, void *c);
void test_vrmulh_s8_rs(void *a, void *b, void *c);
void test_vrmulh_s16_rs(void *a, void *b, void *c);
void test_vrmulh_s32_rs(void *a, void *b, void *c);
void test_vrmulhi_s8_rs(void *a, void *b, void *c);
void test_vrmulhi_s16_rs(void *a, void *b, void *c);
void test_vrmulhi_s32_rs(void *a, void *b, void *c);
void test_vrmulha_s8_rs(void *a, void *b, void *c, void *d);
void test_vrmulha_s16_rs(void *a, void *b, void *c, void *d);
void test_vrmulha_s32_rs(void *a, void *b, void *c, void *d);
void test_vrmulhs_s8_rs(void *a, void *b, void *c, void *d);
void test_vrmulhs_s16_rs(void *a, void *b, void *c, void *d);
void test_vrmulhs_s32_rs(void *a, void *b, void *c, void *d);
void test_vrmulhai_s8_rs(void *a, void *b, void *c, void *d);
void test_vrmulhai_s16_rs(void *a, void *b, void *c, void *d);
void test_vrmulhai_s32_rs(void *a, void *b, void *c, void *d);
void test_vrmulhsi_s8_rs(void *a, void *b, void *c, void *d);
void test_vrmulhsi_s16_rs(void *a, void *b, void *c, void *d);
void test_vrmulhsi_s32_rs(void *a, void *b, void *c, void *d);
void test_vrmulshr_s8_e(void *a, void *b, void *c, void *d);
void test_vrmulshr_s16_e(void *a, void *b, void *c, void *d);
void test_vrmulshr_s32_e(void *a, void *b, void *c, void *d);
void test_vrmulshri_s8_e(void *a, void *b, void *c, void *d);
void test_vrmulshri_s16_e(void *a, void *b, void *c, void *d);
void test_vrmulshri_s32_e(void *a, void *b, void *c, void *d);
void test_vrmulsa_s8_e(void *a, void *b);
void test_vrmulsa_s16_e(void *a, void *b);
void test_vrmulsa_s32_e(void *a, void *b);
void test_vrmulsai_s8_e(void *a, void *b);
void test_vrmulsai_s16_e(void *a, void *b);
void test_vrmulsai_s32_e(void *a, void *b);
void test_vrmulss_s8_e(void *a, void *b);
void test_vrmulss_s16_e(void *a, void *b);
void test_vrmulss_s32_e(void *a, void *b);
void test_vrmulssi_s8_e(void *a, void *b);
void test_vrmulssi_s16_e(void *a, void *b);
void test_vrmulssi_s32_e(void *a, void *b);
void test_vrmulxaa_s8_rs(void *a, void *b, void *c, void *d);
void test_vrmulxaa_s16_rs(void *a, void *b, void *c, void *d);
void test_vrmulxaa_s32_rs(void *a, void *b, void *c, void *d);
void test_vrmulxaai_s8_rs(void *a, void *b, void *c, void *d);
void test_vrmulxaai_s16_rs(void *a, void *b, void *c, void *d);
void test_vrmulxaai_s32_rs(void *a, void *b, void *c, void *d);
void test_vrmulxas_s8_rs(void *a, void *b, void *c, void *d);
void test_vrmulxas_s16_rs(void *a, void *b, void *c, void *d);
void test_vrmulxas_s32_rs(void *a, void *b, void *c, void *d);
void test_vrmulxasi_s8_rs(void *a, void *b, void *c, void *d);
void test_vrmulxasi_s16_rs(void *a, void *b, void *c, void *d);
void test_vrmulxasi_s32_rs(void *a, void *b, void *c, void *d);
void test_vrmulxss_s8_rs(void *a, void *b, void *c, void *d);
void test_vrmulxss_s16_rs(void *a, void *b, void *c, void *d);
void test_vrmulxss_s32_rs(void *a, void *b, void *c, void *d);
void test_vrmulxssi_s8_rs(void *a, void *b, void *c, void *d);
void test_vrmulxssi_s16_rs(void *a, void *b, void *c, void *d);
void test_vrmulxssi_s32_rs(void *a, void *b, void *c, void *d);
void test_vrmulxsa_s8_rs(void *a, void *b, void *c, void *d);
void test_vrmulxsa_s16_rs(void *a, void *b, void *c, void *d);
void test_vrmulxsa_s32_rs(void *a, void *b, void *c, void *d);
void test_vrmulxsai_s8_rs(void *a, void *b, void *c, void *d);
void test_vrmulxsai_s16_rs(void *a, void *b, void *c, void *d);
void test_vrmulxsai_s32_rs(void *a, void *b, void *c, void *d);
void test_vrcmul_s8_rs(void *a, void *b, void *c);
void test_vrcmul_s16_rs(void *a, void *b, void *c);
void test_vrcmul_s32_rs(void *a, void *b, void *c);
void test_vrcmula_s8_e(void *a, void *b);
void test_vrcmula_s16_e(void *a, void *b);
void test_vrcmula_s32_e(void *a, void *b);
void test_vrcmulc_s8_rs(void *a, void *b, void *c);
void test_vrcmulc_s16_rs(void *a, void *b, void *c);
void test_vrcmulc_s32_rs(void *a, void *b, void *c);
void test_vrcmulca_s8_e(void *a, void *b);
void test_vrcmulca_s16_e(void *a, void *b);
void test_vrcmulca_s32_e(void *a, void *b);
void test_vrcmuln_s8_rs(void *a, void *b, void *c);
void test_vrcmuln_s16_rs(void *a, void *b, void *c);
void test_vrcmuln_s32_rs(void *a, void *b, void *c);
void test_vrcmulna_s8_e(void *a, void *b);
void test_vrcmulna_s16_e(void *a, void *b);
void test_vrcmulna_s32_e(void *a, void *b);
void test_vrcmulcn_s8_rs(void *a, void *b, void *c);
void test_vrcmulcn_s16_rs(void *a, void *b, void *c);
void test_vrcmulcn_s32_rs(void *a, void *b, void *c);
void test_vrcmulcna_s8_e(void *a, void *b);
void test_vrcmulcna_s16_e(void *a, void *b);
void test_vrcmulcna_s32_e(void *a, void *b);
void test_vrecpe_s8(void *a, void *b);
void test_vrecpe_s16(void *a, void *b);
void test_vrecpe_s32(void *a, void *b);
void test_vrecpe_u8(void *a, void *b);
void test_vrecpe_u16(void *a, void *b);
void test_vrecpe_u32(void *a, void *b);
void test_vrecpe_f16(void *a, void *b);
void test_vrecpe_f32(void *a, void *b);
void test_vrecps_s8(void *a, void *b, void *c);
void test_vrecps_s16(void *a, void *b, void *c);
void test_vrecps_s32(void *a, void *b, void *c);
void test_vrecps_u8(void *a, void *b, void *c);
void test_vrecps_u16(void *a, void *b, void *c);
void test_vrecps_u32(void *a, void *b, void *c);
void test_vrecps_f16(void *a, void *b, void *c);
void test_vrecps_f32(void *a, void *b, void *c);
void test_vrsqrte_s8(void *a, void *b);
void test_vrsqrte_s16(void *a, void *b);
void test_vrsqrte_s32(void *a, void *b);
void test_vrsqrte_u8(void *a, void *b);
void test_vrsqrte_u16(void *a, void *b);
void test_vrsqrte_u32(void *a, void *b);
void test_vrsqrte_f16(void *a, void *b);
void test_vrsqrte_f32(void *a, void *b);
void test_vrsqrts_s8(void *a, void *b, void *c);
void test_vrsqrts_s16(void *a, void *b, void *c);
void test_vrsqrts_s32(void *a, void *b, void *c);
void test_vrsqrts_u8(void *a, void *b, void *c);
void test_vrsqrts_u16(void *a, void *b, void *c);
void test_vrsqrts_u32(void *a, void *b, void *c);
void test_vrsqrts_f16(void *a, void *b, void *c);
void test_vrsqrts_f32(void *a, void *b, void *c);
void test_vexpe_s8(void *a, void *b);
void test_vexpe_s16(void *a, void *b);
void test_vexpe_s32(void *a, void *b);
void test_vexpe_u8(void *a, void *b);
void test_vexpe_u16(void *a, void *b);
void test_vexpe_u32(void *a, void *b);
void test_vexpe_f16(void *a, void *b);
void test_vexpe_f32(void *a, void *b);
void test_vfmula_f32(void *a, void *b, void *c);
void test_vfmula_f16(void *a, void *b, void *c);
void test_vfmuls_f32(void *a, void *b, void *c);
void test_vfmuls_f16(void *a, void *b, void *c);
void test_vfmula_f32_e(void *a, void *b, void *c);
void test_vfmula_f16_e(void *a, void *b, void *c);
void test_vfmuls_f32_e(void *a, void *b, void *c);
void test_vfmuls_f16_e(void *a, void *b, void *c);
void test_vfmulai_f32_e(void *a, void *b, void *c);
void test_vfmulai_f16_e(void *a, void *b, void *c);
void test_vfmulsi_f32_e(void *a, void *b, void *c);
void test_vfmulsi_f16_e(void *a, void *b, void *c);
void test_vfnmula_f32(void *a, void *b, void *c);
void test_vfnmula_f16(void *a, void *b, void *c);
void test_vfnmuls_f32(void *a, void *b, void *c);
void test_vfnmuls_f16(void *a, void *b, void *c);
void test_vfmulxaa_f32(void *a, void *b, void *c);
void test_vfmulxaa_f16(void *a, void *b, void *c);
void test_vfmulxaai_f32(void *a, void *b, void *c);
void test_vfmulxaai_f16(void *a, void *b, void *c);
void test_vfmulxsa_f32(void *a, void *b, void *c);
void test_vfmulxsa_f16(void *a, void *b, void *c);
void test_vfmulxsai_f32(void *a, void *b, void *c);
void test_vfmulxsai_f16(void *a, void *b, void *c);
void test_vfmulxss_f32(void *a, void *b, void *c);
void test_vfmulxss_f16(void *a, void *b, void *c);
void test_vfmulxssi_f32(void *a, void *b, void *c);
void test_vfmulxssi_f16(void *a, void *b, void *c);
void test_vfmulxas_f32(void *a, void *b, void *c);
void test_vfmulxas_f16(void *a, void *b, void *c);
void test_vfmulxasi_f32(void *a, void *b, void *c);
void test_vfmulxasi_f16(void *a, void *b, void *c);
void test_vfcmul_f32(void *a, void *b, void *c);
void test_vfcmul_f16(void *a, void *b, void *c);
void test_vfcmula_f32(void *a, void *b, void *c);
void test_vfcmula_f16(void *a, void *b, void *c);
void test_vfcmulc_f32(void *a, void *b, void *c);
void test_vfcmulc_f16(void *a, void *b, void *c);
void test_vfcmulca_f32(void *a, void *b, void *c);
void test_vfcmulca_f16(void *a, void *b, void *c);
void test_vfcmuln_f32(void *a, void *b, void *c);
void test_vfcmuln_f16(void *a, void *b, void *c);
void test_vfcmulna_f32(void *a, void *b, void *c);
void test_vfcmulna_f16(void *a, void *b, void *c);
void test_vfcmulcn_f32(void *a, void *b, void *c);
void test_vfcmulcn_f16(void *a, void *b, void *c);
void test_vfcmulcna_f32(void *a, void *b, void *c);
void test_vfcmulcna_f16(void *a, void *b, void *c);
void test_vswp_8(void *a, void *b, void *c, void *d);
void test_vswp_16(void *a, void *b, void *c, void *d);
void test_vswp_32(void *a, void *b, void *c, void *d);
void test_vswp_64(void *a, void *b, void *c, void *d);
void test_vrevq(void *a, void *b, void *c);
void test_vrevh(void *a, void *b, void *c);
void test_vrevw(void *a, void *b, void *c);
void test_vrevd(void *a, void *b, void *c);
void test_vexti_0x0(void *a, void *b, void *c);
void test_vexti_0x21(void *a, void *b, void *c);
void test_vexti_0x16(void *a, void *b, void *c);
void test_vexti_0x3e(void *a, void *b, void *c);
void test_vext(void *a, void *b, int c, void *d);
void test_vtbl_8(void *a, void *b, void *c);
void test_vtbx_8(void *a, void *b, void *c, void *d);
void test_vmovi_8(void *a);
void test_vmovi_s16(void *a);
void test_vmovi_s32(void *a);
void test_vmovi_u16(void *a);
void test_vmovi_u32(void *a);
void test_vmovi_f16(void *a);
void test_vmovi_f32(void *a);
void test_vmaski_8_l(void *a);
void test_vmaski_8_h(void *a);
void test_vmaski_16(void *a);
void test_vdupg_8(int a, void *b);
void test_vdupg_16(int a, void *b);
void test_vdupg_32(int a, void *b);
void test_vdup_8_1(void *a, void *b);
void test_vdup_16_1(void *a, void *b);
void test_vdup_32_1(void *a, void *b);
void test_vdup_8_2(void *a, void *b, void *c, void *d);
void test_vdup_16_2(void *a, void *b, void *c, void *d);
void test_vdup_32_2(void *a, void *b, void *c, void *d);
void test_vdup_8_3(void *a, void *b, void *c, int d);
void test_vdup_16_3(void *a, void *b, void *c, int d);
void test_vdup_32_3(void *a, void *b, void *c, int d);
void test_vdup_8_4(void *a, void *b, void *c, int d);
void test_vdup_16_4(void *a, void *b, void *c, int d);
void test_vdup_32_4(void *a, void *b, void *c, int d);
void test_vins_8_1(void *a, void *b);
void test_vins_16_1(void *a, void *b);
void test_vins_32_1(void *a, void *b);
void test_vins_8_2(void *a, void *b);
void test_vins_16_2(void *a, void *b);
void test_vins_32_2(void *a, void *b);
void test_vins_8_3(void *a, void *b);
void test_vins_16_3(void *a, void *b);
void test_vins_32_3(void *a, void *b);
void test_vins_8_4(void *a, void *b);
void test_vins_16_4(void *a, void *b);
void test_vins_32_4(void *a, void *b);
void test_vpkg_8_2(void *a, void *b);
void test_vpkg_16_2(void *a, void *b);
void test_vpkg_32_2(void *a, void *b);
void test_vpkg_8_3(void *a, void *b);
void test_vpkg_16_3(void *a, void *b);
void test_vpkg_32_3(void *a, void *b);
void test_vpkg_8_4(void *a, void *b);
void test_vpkg_16_4(void *a, void *b);
void test_vpkg_32_4(void *a, void *b);
void test_vsub_s8(void *a, void *b, void *c);
void test_vsub_s16(void *a, void *b, void *c);
void test_vsub_s32(void *a, void *b, void *c);
void test_vsub_s64(void *a, void *b, void *c);
void test_vsub_u8(void *a, void *b, void *c);
void test_vsub_u16(void *a, void *b, void *c);
void test_vsub_u32(void *a, void *b, void *c);
void test_vsub_u64(void *a, void *b, void *c);
void test_vsub_f32(void *a, void *b, void *c);
void test_vsub_f16(void *a, void *b, void *c);
void test_vsubh_s8(void *a, void *b, void *c);
void test_vsubh_s16(void *a, void *b, void *c);
void test_vsubh_s32(void *a, void *b, void *c);
void test_vsubh_u8(void *a, void *b, void *c);
void test_vsubh_u16(void *a, void *b, void *c);
void test_vsubh_u32(void *a, void *b, void *c);
void test_vsub_s8_s(void *a, void *b, void *c);
void test_vsub_s16_s(void *a, void *b, void *c);
void test_vsub_s32_s(void *a, void *b, void *c);
void test_vsub_s64_s(void *a, void *b, void *c);
void test_vsub_u8_s(void *a, void *b, void *c);
void test_vsub_u16_s(void *a, void *b, void *c);
void test_vsub_u32_s(void *a, void *b, void *c);
void test_vsub_u64_s(void *a, void *b, void *c);
void test_vcmpnez_s8(void *a, void *b);
void test_vcmpnez_s16(void *a, void *b);
void test_vcmpnez_s32(void *a, void *b);
void test_vcmpnez_f32(void *a, void *b);
void test_vcmpnez_f16(void *a, void *b);
void test_vcmpne_s8(void *a, void *b, void *c);
void test_vcmpne_s16(void *a, void *b, void *c);
void test_vcmpne_s32(void *a, void *b, void *c);
void test_vcmpne_f32(void *a, void *b, void *c);
void test_vcmpne_f16(void *a, void *b, void *c);
void test_vcmphsz_s8(void *a, void *b);
void test_vcmphsz_s16(void *a, void *b);
void test_vcmphsz_s32(void *a, void *b);
void test_vcmphsz_f32(void *a, void *b);
void test_vcmphsz_f16(void *a, void *b);
void test_vcmphs_s8(void *a, void *b, void *c);
void test_vcmphs_s16(void *a, void *b, void *c);
void test_vcmphs_s32(void *a, void *b, void *c);
void test_vcmphs_u8(void *a, void *b, void *c);
void test_vcmphs_u16(void *a, void *b, void *c);
void test_vcmphs_u32(void *a, void *b, void *c);
void test_vcmphs_f32(void *a, void *b, void *c);
void test_vcmphs_f16(void *a, void *b, void *c);
void test_vcmpltz_s8(void *a, void *b);
void test_vcmpltz_s16(void *a, void *b);
void test_vcmpltz_s32(void *a, void *b);
void test_vcmpltz_f32(void *a, void *b);
void test_vcmpltz_f16(void *a, void *b);
void test_vcmplt_s8(void *a, void *b, void *c);
void test_vcmplt_s16(void *a, void *b, void *c);
void test_vcmplt_s32(void *a, void *b, void *c);
void test_vcmplt_u8(void *a, void *b, void *c);
void test_vcmplt_u16(void *a, void *b, void *c);
void test_vcmplt_u32(void *a, void *b, void *c);
void test_vcmplt_f32(void *a, void *b, void *c);
void test_vcmplt_f16(void *a, void *b, void *c);
void test_vcmphz_s8(void *a, void *b);
void test_vcmphz_s16(void *a, void *b);
void test_vcmphz_s32(void *a, void *b);
void test_vcmphz_f32(void *a, void *b);
void test_vcmphz_f16(void *a, void *b);
void test_vcmplsz_s8(void *a, void *b);
void test_vcmplsz_s16(void *a, void *b);
void test_vcmplsz_s32(void *a, void *b);
void test_vcmplsz_f32(void *a, void *b);
void test_vcmplsz_f16(void *a, void *b);
void test_vclip_s8(void *a, void *b);
void test_vclip_s16(void *a, void *b);
void test_vclip_s32(void *a, void *b);
void test_vclip_s64(void *a, void *b);
void test_vclip_u8(void *a, void *b);
void test_vclip_u16(void *a, void *b);
void test_vclip_u32(void *a, void *b);
void test_vclip_u64(void *a, void *b);
void test_vtst_8(void *a, void *b, void *c);
void test_vtst_16(void *a, void *b, void *c);
void test_vtst_32(void *a, void *b, void *c);
void test_vtst_64(void *a, void *b, void *c);
void test_vsabs_s8_s(void *a, void *b, void *c);
void test_vsabs_s16_s(void *a, void *b, void *c);
void test_vsabs_s32_s(void *a, void *b, void *c);
void test_vsabs_u8_s(void *a, void *b, void *c);
void test_vsabs_u16_s(void *a, void *b, void *c);
void test_vsabs_u32_s(void *a, void *b, void *c);
void test_vsabs_f32(void *a, void *b, void *c);
void test_vsabs_f16(void *a, void *b, void *c);
void test_vmtvr_8_1(void *a, unsigned b, void *c);
void test_vmtvr_16_1(void *a, unsigned b, void *c);
void test_vmtvr_32_1(void *a, unsigned b, void *c);
void test_vmtvr_8_2(void *a, unsigned b, unsigned c, void *d);
void test_vmtvr_16_2(void *a, unsigned b, unsigned c, void *d);
void test_vmtvr_32_2(void *a, unsigned b, unsigned c, void *d);
unsigned int test_vmfvr_s8(void *a);
unsigned int test_vmfvr_s16(void *a);
unsigned int test_vmfvr_s32(void *a);
unsigned int test_vmfvr_u8(void *a);
unsigned int test_vmfvr_u16(void *a);
unsigned int test_vmfvr_u32(void *a);
unsigned int test_vsext_8(void *a);
unsigned int test_vsext_16(void *a);
unsigned int test_vsext_32(void *a);
void test_vmov_s16_sl(void *a, void *b, void *c);
void test_vmov_s32_sl(void *a, void *b, void *c);
void test_vmov_s64_sl(void *a, void *b, void *c);
void test_vmov_u16_sl(void *a, void *b, void *c);
void test_vmov_u32_sl(void *a, void *b, void *c);
void test_vmov_u64_sl(void *a, void *b, void *c);
void test_vmov_s16_rh(void *a, void *b, void *c);
void test_vmov_s32_rh(void *a, void *b, void *c);
void test_vmov_s64_rh(void *a, void *b, void *c);
void test_vmov_u16_rh(void *a, void *b, void *c);
void test_vmov_u32_rh(void *a, void *b, void *c);
void test_vmov_u64_rh(void *a, void *b, void *c);
uint32_t test_vldru_8_1(void *a, void *b, void *c, int d);
uint32_t test_vldru_16_1(void *a, void *b, void *c, int d);
uint32_t test_vldru_32_1(void *a, void *b, void *c, int d);
uint32_t test_vldru_8_2(void *a, void *b, void *c, int d);
uint32_t test_vldru_16_2(void *a, void *b, void *c, int d);
uint32_t test_vldru_32_2(void *a, void *b, void *c, int d);
uint32_t test_vldru_8_3(void *a, void *b, void *c, int d);
uint32_t test_vldru_16_3(void *a, void *b, void *c, int d);
uint32_t test_vldru_32_3(void *a, void *b, void *c, int d);
uint32_t test_vldru_8_4(void *a, void *b, void *c, int d);
uint32_t test_vldru_16_4(void *a, void *b, void *c, int d);
uint32_t test_vldru_32_4(void *a, void *b, void *c, int d);
uint32_t test_vldu_8_1(void *a, void *b, void *c);
uint32_t test_vldu_16_1(void *a, void *b, void *c);
uint32_t test_vldu_32_1(void *a, void *b, void *c);
uint32_t test_vldu_8_2(void *a, void *b, void *c);
uint32_t test_vldu_16_2(void *a, void *b, void *c);
uint32_t test_vldu_32_2(void *a, void *b, void *c);
uint32_t test_vldu_8_3(void *a, void *b, void *c);
uint32_t test_vldu_16_3(void *a, void *b, void *c);
uint32_t test_vldu_32_3(void *a, void *b, void *c);
uint32_t test_vldu_8_4(void *a, void *b, void *c);
uint32_t test_vldu_16_4(void *a, void *b, void *c);
uint32_t test_vldu_32_4(void *a, void *b, void *c);
void test_vld_8_1(void *a, void *b, void *c);
void test_vld_16_1(void *a, void *b, void *c);
void test_vld_32_1(void *a, void *b, void *c);
void test_vld_8_2(void *a, void *b, void *c);
void test_vld_16_2(void *a, void *b, void *c);
void test_vld_32_2(void *a, void *b, void *c);
void test_vld_8_3(void *a, void *b, void *c);
void test_vld_16_3(void *a, void *b, void *c);
void test_vld_32_3(void *a, void *b, void *c);
void test_vld_8_4(void *a, void *b, void *c);
void test_vld_16_4(void *a, void *b, void *c);
void test_vld_32_4(void *a, void *b, void *c);
void test_vldx_8(void *a, void *b, int c, void *d);
void test_vldx_16(void *a, void *b, int c, void *d);
void test_vldx_32(void *a, void *b, int c, void *d);
void test_vlrw_32_1(void *a);
void test_vlrw_32_2(void *a);
void test_vlrw_32_3(void *a);
void test_vlrw_32_4(void *a);
void *test_vldmu_8(void *a, void *b, int c);
void *test_vldmu_16(void *a, void *b, int c);
void *test_vldmu_32(void *a, void *b, int c);
void *test_vldmru_8(void *a,  int b, void *c);
void *test_vldmru_16(void *a, int b, void *c);
void *test_vldmru_32(void *a, int b, void *c);
void test_vldm_8(void *a, void *b, int c);
void test_vldm_16(void *a, void *b, int c);
void test_vldm_32(void *a, void *b, int c);
#ifdef CK803
void test_vlde_8(void *a, void *b, void *c);
void test_vlde_16(void *a, void *b, void *c);
void test_vlde_32(void *a, void *b, void *c);
#endif
unsigned int test_vstru_8_1(void *a, void *b, void *c, unsigned d);
unsigned int test_vstru_16_1(void *a, void *b, void *c, unsigned d);
unsigned int test_vstru_32_1(void *a, void *b, void *c, unsigned d);
unsigned int test_vstru_8_2(void *a, void *b, void *c, unsigned d);
unsigned int test_vstru_16_2(void *a, void *b, void *c, unsigned d);
unsigned int test_vstru_32_2(void *a, void *b, void *c, unsigned d);
unsigned int test_vstru_8_3(void *a, void *b, void *c, unsigned d);
unsigned int test_vstru_16_3(void *a, void *b, void *c, unsigned d);
unsigned int test_vstru_32_3(void *a, void *b, void *c, unsigned d);
unsigned int test_vstru_8_4(void *a, void *b, void *c, unsigned d);
unsigned int test_vstru_16_4(void *a, void *b, void *c, unsigned d);
unsigned int test_vstru_32_4(void *a, void *b, void *c, unsigned d);
unsigned int test_vstu_8_1(void *a, void *b, void *c);
unsigned int test_vstu_16_1(void *a, void *b, void *c);
unsigned int test_vstu_32_1(void *a, void *b, void *c);
unsigned int test_vstu_8_2(void *a, void *b, void *c);
unsigned int test_vstu_16_2(void *a, void *b, void *c);
unsigned int test_vstu_32_2(void *a, void *b, void *c);
unsigned int test_vstu_8_3(void *a, void *b, void *c);
unsigned int test_vstu_16_3(void *a, void *b, void *c);
unsigned int test_vstu_32_3(void *a, void *b, void *c);
unsigned int test_vstu_8_4(void *a, void *b, void *c);
unsigned int test_vstu_16_4(void *a, void *b, void *c);
unsigned int test_vstu_32_4(void *a, void *b, void *c);
void test_vst_8_1(void *a, void *b, void *c);
void test_vst_16_1(void *a, void *b, void *c);
void test_vst_32_1(void *a, void *b, void *c);
void test_vst_8_2(void *a, void *b, void *c);
void test_vst_16_2(void *a, void *b, void *c);
void test_vst_32_2(void *a, void *b, void *c);
void test_vst_8_3(void *a, void *b, void *c);
void test_vst_16_3(void *a, void *b, void *c);
void test_vst_32_3(void *a, void *b, void *c);
void test_vst_8_4(void *a, void *b, void *c);
void test_vst_16_4(void *a, void *b, void *c);
void test_vst_32_4(void *a, void *b, void *c);
void test_vstx_8(void *a, void *b, int c, void *d);
void test_vstx_16(void *a, void *b, int c, void *d);
void test_vstx_32(void *a, void *b, int c, void *d);
unsigned int test_vstmu_8(void *a, void *b, unsigned c);
unsigned int test_vstmu_16(void *a, void *b, unsigned c);
unsigned int test_vstmu_32(void *a, void *b, unsigned c);
unsigned int test_vstmru_8(void *a, void *b, unsigned c);
unsigned int test_vstmru_16(void *a, void *b, unsigned c);
unsigned int test_vstmru_32(void *a, void *b, unsigned c);
void test_vstm_8(void *a, void *b, unsigned c);
void test_vstm_16(void *a, void *b, unsigned c);
void test_vstm_32(void *a, void *b, unsigned c);
void test_vmax_s8(void *a, void *b, void *c);
void test_vmax_s16(void *a, void *b, void *c);
void test_vmax_s32(void *a, void *b, void *c);
void test_vmax_u8(void *a, void *b, void *c);
void test_vmax_u16(void *a, void *b, void *c);
void test_vmax_u32(void *a, void *b, void *c);
void test_vmax_f32(void *a, void *b, void *c);
void test_vmax_f16(void *a, void *b, void *c);
void test_vmaxnm_f32(void *a, void *b, void *c);
void test_vmaxnm_f16(void *a, void *b, void *c);
void test_vmin_s8(void *a, void *b, void *c);
void test_vmin_s16(void *a, void *b, void *c);
void test_vmin_s32(void *a, void *b, void *c);
void test_vmin_u8(void *a, void *b, void *c);
void test_vmin_u16(void *a, void *b, void *c);
void test_vmin_u32(void *a, void *b, void *c);
void test_vmin_f32(void *a, void *b, void *c);
void test_vmin_f16(void *a, void *b, void *c);
void test_vminnm_f32(void *a, void *b, void *c);
void test_vminnm_f16(void *a, void *b, void *c);
void test_vpmax_s8(void *a, void *b, void *c);
void test_vpmax_s16(void *a, void *b, void *c);
void test_vpmax_s32(void *a, void *b, void *c);
void test_vpmax_u8(void *a, void *b, void *c);
void test_vpmax_u16(void *a, void *b, void *c);
void test_vpmax_u32(void *a, void *b, void *c);
void test_vpmax_f32(void *a, void *b, void *c);
void test_vpmax_f16(void *a, void *b, void *c);
void test_vpmin_s8(void *a, void *b, void *c);
void test_vpmin_s16(void *a, void *b, void *c);
void test_vpmin_s32(void *a, void *b, void *c);
void test_vpmin_u8(void *a, void *b, void *c);
void test_vpmin_u16(void *a, void *b, void *c);
void test_vpmin_u32(void *a, void *b, void *c);
void test_vpmin_f32(void *a, void *b, void *c);
void test_vpmin_f16(void *a, void *b, void *c);
void test_vsht_s8(void *a, void *b, void *c);
void test_vsht_s16(void *a, void *b, void *c);
void test_vsht_s32(void *a, void *b, void *c);
void test_vsht_s64(void *a, void *b, void *c);
void test_vsht_u8(void *a, void *b, void *c);
void test_vsht_u16(void *a, void *b, void *c);
void test_vsht_u32(void *a, void *b, void *c);
void test_vsht_u64(void *a, void *b, void *c);
void test_vshl_s8(void *a, void *b, void *c);
void test_vshl_s16(void *a, void *b, void *c);
void test_vshl_s32(void *a, void *b, void *c);
void test_vshl_s64(void *a, void *b, void *c);
void test_vshl_u8(void *a, void *b, void *c);
void test_vshl_u16(void *a, void *b, void *c);
void test_vshl_u32(void *a, void *b, void *c);
void test_vshl_u64(void *a, void *b, void *c);
void test_vshr_s8(void *a, void *b, void *c);
void test_vshr_s16(void *a, void *b, void *c);
void test_vshr_s32(void *a, void *b, void *c);
void test_vshr_s64(void *a, void *b, void *c);
void test_vshr_u8(void *a, void *b, void *c);
void test_vshr_u16(void *a, void *b, void *c);
void test_vshr_u32(void *a, void *b, void *c);
void test_vshr_u64(void *a, void *b, void *c);
void test_vshr_s8_r(void *a, void *b, void *c);
void test_vshr_s16_r(void *a, void *b, void *c);
void test_vshr_s32_r(void *a, void *b, void *c);
void test_vshr_s64_r(void *a, void *b, void *c);
void test_vshr_u8_r(void *a, void *b, void *c);
void test_vshr_u16_r(void *a, void *b, void *c);
void test_vshr_u32_r(void *a, void *b, void *c);
void test_vshr_u64_r(void *a, void *b, void *c);
void test_vshri_s8(void *a, void *b);
void test_vshri_s16(void *a, void *b);
void test_vshri_s32(void *a, void *b);
void test_vshri_s64(void *a, void *b);
void test_vshri_u8(void *a, void *b);
void test_vshri_u16(void *a, void *b);
void test_vshri_u32(void *a, void *b);
void test_vshri_u64(void *a, void *b);
void test_vshri_s8_r(void *a, void *b);
void test_vshri_s16_r(void *a, void *b);
void test_vshri_s32_r(void *a, void *b);
void test_vshri_s64_r(void *a, void *b);
void test_vshri_u8_r(void *a, void *b);
void test_vshri_u16_r(void *a, void *b);
void test_vshri_u32_r(void *a, void *b);
void test_vshri_u64_r(void *a, void *b);
void test_vshri_s16_l(void *a, void *b, void *c);
void test_vshri_s32_l(void *a, void *b, void *c);
void test_vshri_s64_l(void *a, void *b, void *c);
void test_vshri_u16_l(void *a, void *b, void *c);
void test_vshri_u32_l(void *a, void *b, void *c);
void test_vshri_u64_l(void *a, void *b, void *c);
void test_vshri_s16_lr(void *a, void *b, void *c);
void test_vshri_s32_lr(void *a, void *b, void *c);
void test_vshri_s64_lr(void *a, void *b, void *c);
void test_vshri_u16_lr(void *a, void *b, void *c);
void test_vshri_u32_lr(void *a, void *b, void *c);
void test_vshri_u64_lr(void *a, void *b, void *c);
void test_vshri_s16_ls(void *a, void *b, void *c);
void test_vshri_s32_ls(void *a, void *b, void *c);
void test_vshri_s64_ls(void *a, void *b, void *c);
void test_vshri_u16_ls(void *a, void *b, void *c);
void test_vshri_u32_ls(void *a, void *b, void *c);
void test_vshri_u64_ls(void *a, void *b, void *c);
void test_vshri_s16_lrs(void *a, void *b, void *c);
void test_vshri_s32_lrs(void *a, void *b, void *c);
void test_vshri_s64_lrs(void *a, void *b, void *c);
void test_vshri_u16_lrs(void *a, void *b, void *c);
void test_vshri_u32_lrs(void *a, void *b, void *c);
void test_vshri_u64_lrs(void *a, void *b, void *c);
void test_vshria_s8_r(void *a, void *b, void *c);
void test_vshria_s16_r(void *a, void *b, void *c);
void test_vshria_s32_r(void *a, void *b, void *c);
void test_vshria_s64_r(void *a, void *b, void *c);
void test_vshria_u8_r(void *a, void *b, void *c);
void test_vshria_u16_r(void *a, void *b, void *c);
void test_vshria_u32_r(void *a, void *b, void *c);
void test_vshria_u64_r(void *a, void *b, void *c);
void test_vshria_s8(void *a, void *b, void *c);
void test_vshria_s16(void *a, void *b, void *c);
void test_vshria_s32(void *a, void *b, void *c);
void test_vshria_s64(void *a, void *b, void *c);
void test_vshria_u8(void *a, void *b, void *c);
void test_vshria_u16(void *a, void *b, void *c);
void test_vshria_u32(void *a, void *b, void *c);
void test_vshria_u64(void *a, void *b, void *c);
void test_vexh_8 (void *a, int b, void *c, void *d);
void test_vexh_16(void *a, int b, void *c, void *d);
void test_vexh_32(void *a, int b, void *c, void *d);
void test_vexh_64(void *a, int b, void *c, void *d);
void test_vexl_8 (void *a, int b, void *c, void *d);
void test_vexl_16(void *a, int b, void *c, void *d);
void test_vexl_32(void *a, int b, void *c, void *d);
void test_vexl_64(void *a, int b, void *c, void *d);
void test_vshli_s8(void *a, void *b);
void test_vshli_s16(void *a, void *b);
void test_vshli_s32(void *a, void *b);
void test_vshli_s64(void *a, void *b);
void test_vshli_u8(void *a, void *b);
void test_vshli_u16(void *a, void *b);
void test_vshli_u32(void *a, void *b);
void test_vshli_u64(void *a, void *b);
void test_vshli_s8_s(void *a, void *b);
void test_vshli_s16_s(void *a, void *b);
void test_vshli_s32_s(void *a, void *b);
void test_vshli_s64_s(void *a, void *b);
void test_vshli_u8_s(void *a, void *b);
void test_vshli_u16_s(void *a, void *b);
void test_vshli_u32_s(void *a, void *b);
void test_vshli_u64_s(void *a, void *b);
void test_vshli_s8_e(void *a, void *b, void *c);
void test_vshli_s16_e(void *a, void *b, void *c);
void test_vshli_s32_e(void *a, void *b, void *c);
void test_vshli_u8_e(void *a, void *b, void *c);
void test_vshli_u16_e(void *a, void *b, void *c);
void test_vshli_u32_e(void *a, void *b, void *c);
void test_vshl_s8_s(void *a, void *b, void *c);
void test_vshl_s16_s(void *a, void *b, void *c);
void test_vshl_s32_s(void *a, void *b, void *c);
void test_vshl_s64_s(void *a, void *b, void *c);
void test_vshl_u8_s(void *a, void *b, void *c);
void test_vshl_u16_s(void *a, void *b, void *c);
void test_vshl_u32_s(void *a, void *b, void *c);
void test_vshl_u64_s(void *a, void *b, void *c);
void test_vsht_s8_r(void *a, void *b, void *c);
void test_vsht_s16_r(void *a, void *b, void *c);
void test_vsht_s32_r(void *a, void *b, void *c);
void test_vsht_s64_r(void *a, void *b, void *c);
void test_vsht_u8_r(void *a, void *b, void *c);
void test_vsht_u16_r(void *a, void *b, void *c);
void test_vsht_u32_r(void *a, void *b, void *c);
void test_vsht_u64_r(void *a, void *b, void *c);
void test_vsht_s8_s(void *a, void *b, void *c);
void test_vsht_s16_s(void *a, void *b, void *c);
void test_vsht_s32_s(void *a, void *b, void *c);
void test_vsht_s64_s(void *a, void *b, void *c);
void test_vsht_u8_s(void *a, void *b, void *c);
void test_vsht_u16_s(void *a, void *b, void *c);
void test_vsht_u32_s(void *a, void *b, void *c);
void test_vsht_u64_s(void *a, void *b, void *c);
void test_vsht_s8_rs(void *a, void *b, void *c);
void test_vsht_s16_rs(void *a, void *b, void *c);
void test_vsht_s32_rs(void *a, void *b, void *c);
void test_vsht_s64_rs(void *a, void *b, void *c);
void test_vsht_u8_rs(void *a, void *b, void *c);
void test_vsht_u16_rs(void *a, void *b, void *c);
void test_vsht_u32_rs(void *a, void *b, void *c);
void test_vsht_u64_rs(void *a, void *b, void *c);
void test_vmov_s8_e(void *a, void *b, void *c);
void test_vmov_s16_e(void *a, void *b, void *c);
void test_vmov_s32_e(void *a, void *b, void *c);
void test_vmov_u8_e(void *a, void *b, void *c);
void test_vmov_u16_e(void *a, void *b, void *c);
void test_vmov_u32_e(void *a, void *b, void *c);
void test_vmov_16_l(void *a, void *b, void *c);
void test_vmov_32_l(void *a, void *b, void *c);
void test_vmov_64_l(void *a, void *b, void *c);
void test_vmov_16_h(void *a, void *b, void *c);
void test_vmov_32_h(void *a, void *b, void *c);
void test_vmov_64_h(void *a, void *b, void *c);
void test_vand_8(void *a, void *b, void *c);
void test_vand_16(void *a, void *b, void *c);
void test_vand_32(void *a, void *b, void *c);
void test_vand_64(void *a, void *b, void *c);
void test_vandn_8(void *a, void *b, void *c);
void test_vandn_16(void *a, void *b, void *c);
void test_vandn_32(void *a, void *b, void *c);
void test_vandn_64(void *a, void *b, void *c);
void test_vorn_8(void *a, void *b, void *c);
void test_vorn_16(void *a, void *b, void *c);
void test_vorn_32(void *a, void *b, void *c);
void test_vorn_64(void *a, void *b, void *c);
void test_vor_8(void *a, void *b, void *c);
void test_vor_16(void *a, void *b, void *c);
void test_vor_32(void *a, void *b, void *c);
void test_vor_64(void *a, void *b, void *c);
void test_vxor_8(void *a, void *b, void *c);
void test_vxor_16(void *a, void *b, void *c);
void test_vxor_32(void *a, void *b, void *c);
void test_vxor_64(void *a, void *b, void *c);
void test_vsabs_s8_e(void *a, void *b, void *c, void *d);
void test_vsabs_s16_e(void *a, void *b, void *c, void *d);
void test_vsabs_s32_e(void *a, void *b, void *c, void *d);
void test_vsabs_u8_e(void *a, void *b, void *c, void *d);
void test_vsabs_u16_e(void *a, void *b, void *c, void *d);
void test_vsabs_u32_e(void *a, void *b, void *c, void *d);
void test_vsabsa_s8(void *a, void *b, void *c, void *d);
void test_vsabsa_s16(void *a, void *b, void *c, void *d);
void test_vsabsa_s32(void *a, void *b, void *c, void *d);
void test_vsabsa_u8(void *a, void *b, void *c, void *d);
void test_vsabsa_u16(void *a, void *b, void *c, void *d);
void test_vsabsa_u32(void *a, void *b, void *c, void *d);
void test_vsabsa_s8_e(void *a, void *b, void *c, void *d);
void test_vsabsa_s16_e(void *a, void *b, void *c, void *d);
void test_vsabsa_s32_e(void *a, void *b, void *c, void *d);
void test_vsabsa_u8_e(void *a, void *b, void *c, void *d);
void test_vsabsa_u16_e(void *a, void *b, void *c, void *d);
void test_vsabsa_u32_e(void *a, void *b, void *c, void *d);
void test_vsel_8(void *a, void *b, void *c, void *d);
void test_vsel_16(void *a, void *b, void *c, void *d);
void test_vsel_32(void *a, void *b, void *c, void *d);
void test_vsel_64(void *a, void *b, void *c, void *d);
void test_vtrn_8(void *a, void *b, void *c, void *d);
void test_vtrn_16(void *a, void *b, void *c, void *d);
void test_vtrn_32(void *a, void *b, void *c, void *d);
void test_vitl_8_2(void *a, void *b, void *c, void *d);
void test_vitl_16_2(void *a, void *b, void *c, void *d);
void test_vitl_32_2(void *a, void *b, void *c, void *d);
void test_vitl_8_3(void *a, void *b);
void test_vitl_16_3(void *a, void *b);
void test_vitl_32_3(void *a, void *b);
void test_vitl_8_4(void *a, void *b);
void test_vitl_16_4(void *a, void *b);
void test_vitl_32_4(void *a, void *b);
void test_vdtl_8_2(void *a, void *b, void *c, void *d);
void test_vdtl_16_2(void *a, void *b, void *c, void *d);
void test_vdtl_32_2(void *a, void *b, void *c, void *d);
void test_vdtl_8_3(void *a, void *b);
void test_vdtl_16_3(void *a, void *b);
void test_vdtl_32_3(void *a, void *b);
void test_vdtl_8_4(void *a, void *b);
void test_vdtl_16_4(void *a, void *b);
void test_vdtl_32_4(void *a, void *b);
void test_vhtos_f16(void *a, void *b, void *c);
void test_vstoh_f32(void *a, void *b);
void test_vdtos_f64(void *a, void *b);
void test_vftox_f32_s32(void *a, void *b);
void test_vftox_f32_u32(void *a, void *b);
void test_vftox_f16_s16(void *a, void *b);
void test_vftox_f16_u16(void *a, void *b);
void test_vftox_f32_s16(void *a, void *b);
void test_vftox_f32_u16(void *a, void *b);
void test_vftox_f16_s32(void *a, void *b, void *c);
void test_vftox_f16_u32(void *a, void *b, void *c);
void test_vxtof_u32_f32(void *a, void *b);
void test_vxtof_s32_f32(void *a, void *b);
void test_vxtof_u16_f16(void *a, void *b);
void test_vxtof_s16_f16(void *a, void *b);
void test_vxtof_u32_f16(void *a, void *b);
void test_vxtof_s32_f16(void *a, void *b);
void test_vxtof_u16_f32(void *a, void *b, void *c);
void test_vxtof_s16_f32(void *a, void *b, void *c);
void test_vftoi_f32_s32(void *a, void *b);
void test_vftoi_f32_u32(void *a, void *b);
void test_vftoi_f16_s16(void *a, void *b);
void test_vftoi_f16_u16(void *a, void *b);
void test_vftoi_f32_s16(void *a, void *b);
void test_vftoi_f32_u16(void *a, void *b);
void test_vftoi_f16_s32(void *a, void *b, void *c);
void test_vftoi_f16_u32(void *a, void *b, void *c);
void test_vitof_u32_f32(void *a, void *b);
void test_vitof_s32_f32(void *a, void *b);
void test_vitof_u16_f16(void *a, void *b);
void test_vitof_s16_f16(void *a, void *b);
void test_vitof_u32_f16(void *a, void *b);
void test_vitof_s32_f16(void *a, void *b);
void test_vitof_u16_f32(void *a, void *b, void *c);
void test_vitof_s16_f32(void *a, void *b, void *c);

void test_vftoi_f32_s32_rn(void *a, void *b);
void test_vftoi_f32_u32_rn(void *a, void *b);
void test_vftoi_f16_s16_rn(void *a, void *b);
void test_vftoi_f16_u16_rn(void *a, void *b);
void test_vftoi_f32_s16_rn(void *a, void *b);
void test_vftoi_f32_u16_rn(void *a, void *b);
void test_vftoi_f16_s32_rn(void *a, void *b, void *c);
void test_vftoi_f16_u32_rn(void *a, void *b, void *c);
void test_vftofi_f16_rn(void *a, void *b);
void test_vftofi_f32_rn(void *a, void *b);
void test_vftoi_f32_s32_rz(void *a, void *b);
void test_vftoi_f32_u32_rz(void *a, void *b);
void test_vftoi_f16_s16_rz(void *a, void *b);
void test_vftoi_f16_u16_rz(void *a, void *b);
void test_vftoi_f32_s16_rz(void *a, void *b);
void test_vftoi_f32_u16_rz(void *a, void *b);
void test_vftoi_f16_s32_rz(void *a, void *b, void *c);
void test_vftoi_f16_u32_rz(void *a, void *b, void *c);
void test_vftofi_f16_rz(void *a, void *b);
void test_vftofi_f32_rz(void *a, void *b);
void test_vftoi_f32_s32_rni(void *a, void *b);
void test_vftoi_f32_u32_rni(void *a, void *b);
void test_vftoi_f16_s16_rni(void *a, void *b);
void test_vftoi_f16_u16_rni(void *a, void *b);
void test_vftoi_f32_s16_rni(void *a, void *b);
void test_vftoi_f32_u16_rni(void *a, void *b);
void test_vftoi_f16_s32_rni(void *a, void *b, void *c);
void test_vftoi_f16_u32_rni(void *a, void *b, void *c);
void test_vftofi_f16_rni(void *a, void *b);
void test_vftofi_f32_rni(void *a, void *b);
void test_vftoi_f32_s32_rpi(void *a, void *b);
void test_vftoi_f32_u32_rpi(void *a, void *b);
void test_vftoi_f16_s16_rpi(void *a, void *b);
void test_vftoi_f16_u16_rpi(void *a, void *b);
void test_vftoi_f32_s16_rpi(void *a, void *b);
void test_vftoi_f32_u16_rpi(void *a, void *b);
void test_vftoi_f16_s32_rpi(void *a, void *b, void *c);
void test_vftoi_f16_u32_rpi(void *a, void *b, void *c);
void test_vftofi_f16_rpi(void *a, void *b);
void test_vftofi_f32_rpi(void *a, void *b);

#endif
