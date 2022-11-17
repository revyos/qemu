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

#ifndef DSP_INSN_H
#define DSP_INSN_H

int32_t test_add_s32_s(int32_t a, int32_t b);
int32_t test_addx_u32(int32_t a, int32_t b);
int32_t test_addx_s32(int32_t a, int32_t b);
int32_t test_padd_s16_s(int32_t a, int32_t b);
int32_t test_padd_s16(int32_t a, int32_t b);
int32_t test_paddh_s16(int32_t a, int32_t b);
int64_t test_pmul_s16(int32_t a, int32_t b);
int64_t test_pmul_s16_f(int32_t a, int32_t b);
int32_t test_mul_32_l(int32_t a, int32_t b);
int32_t test_mul_32_lf(int32_t a, int32_t b);
int32_t test_mulll_s16(int32_t a, int32_t b);
int32_t test_mulll_s16_f(int32_t a, int32_t b);
int32_t test_mulhl_s16(int32_t a, int32_t b);
int32_t test_mulhl_s16_f(int32_t a, int32_t b);
int32_t test_mulhh_s16(int32_t a, int32_t b);
int32_t test_mulhh_s16_f(int32_t a, int32_t b);
int32_t test_mulca_s16(int32_t a, int32_t b);
int32_t test_mulca_s16_f(int32_t a, int32_t b);
int32_t test_mulcax_s16(int32_t a, int32_t b);
int32_t test_mulcax_s16_f(int32_t a, int32_t b);
int32_t test_mulcs_s16(int32_t a, int32_t b);
int32_t test_mulcs_s16_f(int32_t a, int32_t b);
int32_t test_mulcsx_s16(int32_t a, int32_t b);
int32_t test_mulcsx_s16_f(int32_t a, int32_t b);
int32_t test_max_u32(int32_t a, int32_t b);
int32_t test_max_s32(int32_t a, int32_t b);
int32_t test_min_u32(int32_t a, int32_t b);
int32_t test_min_s32(int32_t a, int32_t b);
int32_t test_pmax_u16(int32_t a, int32_t b);
int32_t test_pmax_s16(int32_t a, int32_t b);
int32_t test_pmin_u16(int32_t a, int32_t b);
int32_t test_pmin_s16(int32_t a, int32_t b);
int64_t test_divsr(int32_t a, int32_t b);
int64_t test_divur(int32_t a, int32_t b);
int32_t test_mula_32_l(int32_t a, int32_t b, int32_t c);
int32_t test_mula_32_lf(int32_t a, int32_t b, int32_t c);
int32_t test_muls_32_l(int32_t a, int32_t b, int32_t c);
int32_t test_muls_32_lf(int32_t a, int32_t b, int32_t c);
int64_t test_mul_u32(int32_t a, int32_t b);
int64_t test_mul_s32(int32_t a, int32_t b);
int64_t test_mul_s32_f(int32_t a, int32_t b);
int64_t test_mula_u32(int32_t a, int32_t b, int64_t c);
int64_t test_mula_s32(int32_t a, int32_t b, int64_t c);
int64_t test_mula_s32_f(int32_t a, int32_t b, int64_t c);
int64_t test_mulaca_s16_e(int32_t a, int32_t b, int64_t c);
int64_t test_mulacax_s16_e(int32_t a, int32_t b, int64_t c);
int32_t test_mulall_s16(int32_t a, int32_t b, int32_t c);
int32_t test_mulall_s16_f(int32_t a, int32_t b, int32_t c);
int64_t test_mulall_s16_e(int32_t a, int32_t b, int64_t c);
int32_t test_sub_s32_s(int32_t a, int32_t b);
int32_t test_psub_s16_s(int32_t a, int32_t b);
int32_t test_psub_s16(int32_t a, int32_t b);
int32_t test_psubh_s16(int32_t a, int32_t b);
int64_t test_paddx_s32(int32_t a, int32_t b, int64_t c);
int64_t test_psubx_s32(int32_t a, int32_t b, int64_t c);
int32_t test_pabs_s16_s(int32_t a);
int32_t test_pneg_s16_s(int32_t a);
int32_t test_sel_32(int32_t a, int32_t b, int32_t equ_a);
int32_t test_pkg_0_16(int32_t a, int32_t b);
int32_t test_pkg_15_1(int32_t a, int32_t b);
int32_t test_pkg_0_1(int32_t a, int32_t b);
int32_t test_pkg_15_16(int32_t a, int32_t b);
int32_t test_pkgll(int32_t a, int32_t b);
int32_t test_pkghh(int32_t a, int32_t b);
int32_t test_dext_16(int32_t a, int32_t b);
int32_t test_dext_0(int32_t a, int32_t b);
int32_t test_dext_31(int32_t a, int32_t b);
int64_t test_pmula_s16(int32_t a, int32_t b, int64_t c);
int64_t test_pmula_s16_f(int32_t a, int32_t b, int64_t c);
int64_t test_pmulwh_s16(int32_t a, int32_t b);
int64_t test_pmulwh_s16_f(int32_t a, int32_t b);
int64_t test_pmulwl_s16(int32_t a, int32_t b);
int64_t test_pmulwl_s16_f(int32_t a, int32_t b);
int64_t test_pmulawh_s16(int32_t a, int32_t b, int64_t c);
int64_t test_pmulawh_s16_f(int32_t a, int32_t b, int64_t c);
int64_t test_pmulawl_s16(int32_t a, int32_t b, int64_t c);
int64_t test_pmulawl_s16_f(int32_t a, int32_t b, int64_t c);
int32_t test_plsli_16_0(int32_t a);
int32_t test_plsli_16_1(int32_t a);
int32_t test_plsli_16_9(int32_t a);
int32_t test_plsli_16_15(int32_t a);
int32_t test_pasri_16_0(int32_t a);
int32_t test_pasri_16_1(int32_t a);
int32_t test_pasri_16_9(int32_t a);
int32_t test_pasri_16_15(int32_t a);
int64_t test_plsli_32_0(int32_t a, int32_t b);
int64_t test_plsli_32_1(int32_t a, int32_t b);
int64_t test_plsli_32_20(int32_t a, int32_t b);
int64_t test_plsli_32_31(int32_t a, int32_t b);
int64_t test_pasri_32_0(int32_t a, int32_t b);
int64_t test_pasri_32_1(int32_t a, int32_t b);
int64_t test_pasri_32_20(int32_t a, int32_t b);
int64_t test_pasri_32_31(int32_t a, int32_t b);
int32_t test_ldhe_h_1(void);
int32_t test_ldhe_h_2(void);
int32_t test_ldle_h_1(void);
int32_t test_ldle_h_2(void);
int64_t test_ldxe_h_1(void);
int64_t test_ldxe_h_2(void);
int32_t test_ldrhe_h(int32_t a);
int32_t test_ldrle_h(int32_t a);
int64_t test_ldrxe_h(int32_t a);
int32_t test_mul_s32_h(int32_t a, int32_t b);
int32_t test_mul_u32_h(int32_t a, int32_t b);
int32_t test_mul_s32_rh(int32_t a, int32_t b);
int32_t test_mul_u32_rh(int32_t a, int32_t b);
int32_t test_mula_s32_h(int32_t a, int32_t b, int32_t c);
int32_t test_mula_u32_h(int32_t a, int32_t b, int32_t c);
int32_t test_mula_s32_rh(int32_t a, int32_t b, int32_t c);
int32_t test_mula_u32_rh(int32_t a, int32_t b, int32_t c);
int32_t test_muls_s32_h(int32_t a, int32_t b, int32_t c);
int32_t test_muls_u32_h(int32_t a, int32_t b, int32_t c);
int32_t test_muls_s32_rh(int32_t a, int32_t b, int32_t c);
int32_t test_muls_u32_rh(int32_t a, int32_t b, int32_t c);
int32_t test_divsl(int32_t a, int32_t b);
int32_t test_divul(int32_t a, int32_t b);

#endif /* DSP_INSN_H */
