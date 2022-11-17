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

#ifndef _INST_DSPV2_H
#define _INST_DSPV2_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE    1
#define FALSE   0
#define SIGNBIT64  0x8000000000000000
#define DSPV2_HELPER(name) dspv2_helper_##name 
typedef unsigned long long uint64_t;
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;


uint32_t DSPV2_HELPER(add_s32_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(add_u32_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(padd_s8_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(padd_u8_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(padd_s16_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(padd_u16_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(sub_s32_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(sub_u32_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(psub_s8_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(psub_u8_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(psub_s16_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(psub_u16_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(paddh_s8)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(paddh_u8)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(paddh_s16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(paddh_u16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(psubh_s8)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(psubh_u8)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(psubh_s16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(psubh_u16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pasx_s16_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pasx_u16_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(psax_s16_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(psax_u16_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pasxh_s16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pasxh_u16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(psaxh_s16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(psaxh_u16)(uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(add_s64_s)(uint64_t x, uint64_t y);
uint64_t DSPV2_HELPER(add_u64_s)(uint64_t x, uint64_t y);
uint64_t DSPV2_HELPER(sub_s64_s)(uint64_t x, uint64_t y);
uint64_t DSPV2_HELPER(sub_u64_s)(uint64_t x, uint64_t y);
uint32_t DSPV2_HELPER(lsli_32_s)(uint32_t x, uint32_t imm);
uint32_t DSPV2_HELPER(lsl_32_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(plsli_u16_s)(uint32_t x, uint32_t imm);
uint32_t DSPV2_HELPER(plsl_u16_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pcmpne_8)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pcmpne_16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pcmphs_u8)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pcmphs_s8)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pcmphs_u16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pcmphs_s16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pcmplt_u8)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pcmplt_s8)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pcmplt_u16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pcmplt_s16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pmax_s8)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pmax_u8)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pmin_s8)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pmin_u8)(uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(pext_u8_e)(uint32_t x);
uint64_t DSPV2_HELPER(pext_s8_e)(uint32_t x);
uint64_t DSPV2_HELPER(pextx_u8_e)(uint32_t x);
uint64_t DSPV2_HELPER(pextx_s8_e)(uint32_t x);
uint32_t DSPV2_HELPER(narl)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(narh)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(narlx)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(narhx)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(clipi_u32)(uint32_t x, uint32_t imm);
uint32_t DSPV2_HELPER(clipi_s32)(uint32_t x, uint32_t imm);
uint32_t DSPV2_HELPER(clip_u32)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(clip_s32)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pclipi_u16)(uint32_t x, uint32_t imm);
uint32_t DSPV2_HELPER(pclipi_s16)(uint32_t x, uint32_t imm);
uint32_t DSPV2_HELPER(pclip_u16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pclip_s16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(pabs_s8_s)(uint32_t x);
uint32_t DSPV2_HELPER(pabs_s16_s)(uint32_t x);
uint32_t DSPV2_HELPER(abs_s32_s)(uint32_t x);
uint32_t DSPV2_HELPER(pneg_s8_s)(uint32_t x);
uint32_t DSPV2_HELPER(pneg_s16_s)(uint32_t x);
uint32_t DSPV2_HELPER(neg_s32_s)(uint32_t x);
uint32_t DSPV2_HELPER(rmul_s32_h)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(rmul_s32_rh)(uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(mula_s32_s)(uint32_t z, uint32_t z1,
                                  uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(mula_u32_s)(uint32_t z, uint32_t z1,
                                    uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(muls_s32_s)(uint32_t z, uint32_t z1,
                                  uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(muls_u32_s)(uint32_t z, uint32_t z1,
                                    uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mula_32_l)(uint32_t z, uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mula_s32_hs)(uint32_t z, uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(muls_s32_hs)(uint32_t z, uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mula_s32_rhs)(uint32_t z, uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(muls_s32_rhs)(uint32_t z, uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(rmulxl_s32)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(rmulxl_s32_r)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(rmulxh_s32)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(rmulxh_s32_r)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulaxl_s32_s)(uint32_t z, uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulaxl_s32_rs)(uint32_t z, uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulaxh_s32_s)(uint32_t z, uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulaxh_s32_rs)(uint32_t z, uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(rmulll_s16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(rmulhh_s16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(rmulhl_s16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulall_s16)(uint32_t z, uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulall_s16_s)(uint32_t z, uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulahh_s16_s)(uint32_t z, uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulahl_s16_s)(uint32_t z, uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(mulall_s16_e)(uint32_t z, uint32_t z1,
                                    uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(mulahh_s16_e)(uint32_t z, uint32_t z1,
                                    uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(mulahl_s16_e)(uint32_t z, uint32_t z1,
                                    uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(prmul_s16)(uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(prmulx_s16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(prmul_s16_h)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(prmul_s16_rh)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(prmulx_s16_h)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(prmulx_s16_rh)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulca_s16_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulcax_s16_s)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulaca_s16_s)(uint32_t z, uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulacax_s16_s)(uint32_t z, uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulacs_s16_s)(uint32_t z, uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulacsr_s16_s)(uint32_t z, uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulacsx_s16_s)(uint32_t z, uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulsca_s16_s)(uint32_t z, uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulscax_s16_s)(uint32_t z, uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(psabsa_u8)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(psabsaa_u8)(uint32_t z, uint32_t x, uint32_t y);

/* tcg instructions */
uint64_t DSPV2_HELPER(muls_u32)(uint32_t z, uint32_t z1,
                                uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(muls_s32)(uint32_t z, uint32_t z1,
                                uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulxl_s32)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulxl_s32_r)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulxh_s32)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulxh_s32_r)(uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(pmul_s16)(uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(pmul_u16)(uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(pmulx_s16)(uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(pmulx_u16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulcs_s16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulcsr_s16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulcsx_s16)(uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(mulaca_s16_e)(uint32_t z, uint32_t z1,
                                  uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(mulacax_s16_e)(uint32_t z, uint32_t z1,
                                  uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(mulacs_s16_e)(uint32_t z, uint32_t z1,
                                  uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(mulacsr_s16_e)(uint32_t z, uint32_t z1,
                                  uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(mulacsx_s16_e)(uint32_t z, uint32_t z1,
                                  uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(mulsca_s16_e)(uint32_t z, uint32_t z1,
                                  uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(mulscax_s16_e)(uint32_t z, uint32_t z1,
                                  uint32_t x, uint32_t y);
uint64_t DSPV2_HELPER(mul_u32)(uint32_t x, u_int32_t y);
uint64_t DSPV2_HELPER(mul_s32)(uint32_t x, u_int32_t y);
uint64_t DSPV2_HELPER(mula_u32)(uint32_t z, u_int32_t z1,
                                uint32_t x, u_int32_t y);
uint64_t DSPV2_HELPER(mula_s32)(uint32_t z, u_int32_t z1,
                                uint32_t x, u_int32_t y);
uint32_t DSPV2_HELPER(mul_s32_h)(uint32_t x, u_int32_t y);
uint32_t DSPV2_HELPER(mul_s32_rh)(uint32_t x, u_int32_t y);
uint32_t DSPV2_HELPER(mulll_s16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulhh_s16)(uint32_t x, uint32_t y);
uint32_t DSPV2_HELPER(mulhl_s16)(uint32_t x, uint32_t y);
#endif
