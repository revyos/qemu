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

#ifndef RVP_INSN_H
#define RVP_INSN_H
#include <stdint.h>
#include "width.h"

target_ulong test_add16(target_ulong a, target_ulong b);
target_ulong test_radd16(target_ulong a, target_ulong b);
target_ulong test_uradd16(target_ulong a, target_ulong b);
target_ulong test_kadd16(target_ulong a, target_ulong b);
target_ulong test_ukadd16(target_ulong a, target_ulong b);

target_ulong test_sub16(target_ulong a, target_ulong b);
target_ulong test_rsub16(target_ulong a, target_ulong b);
target_ulong test_ursub16(target_ulong a, target_ulong b);
target_ulong test_ksub16(target_ulong a, target_ulong b);
target_ulong test_uksub16(target_ulong a, target_ulong b);

target_ulong test_cras16(target_ulong a, target_ulong b);
target_ulong test_rcras16(target_ulong a, target_ulong b);
target_ulong test_urcras16(target_ulong a, target_ulong b);
target_ulong test_kcras16(target_ulong a, target_ulong b);
target_ulong test_ukcras16(target_ulong a, target_ulong b);

target_ulong test_crsa16(target_ulong a, target_ulong b);
target_ulong test_rcrsa16(target_ulong a, target_ulong b);
target_ulong test_urcrsa16(target_ulong a, target_ulong b);
target_ulong test_kcrsa16(target_ulong a, target_ulong b);
target_ulong test_ukcrsa16(target_ulong a, target_ulong b);

target_ulong test_stas16(target_ulong a, target_ulong b);
target_ulong test_rstas16(target_ulong a, target_ulong b);
target_ulong test_urstas16(target_ulong a, target_ulong b);
target_ulong test_kstas16(target_ulong a, target_ulong b);
target_ulong test_ukstas16(target_ulong a, target_ulong b);

target_ulong test_stsa16(target_ulong a, target_ulong b);
target_ulong test_rstsa16(target_ulong a, target_ulong b);
target_ulong test_urstsa16(target_ulong a, target_ulong b);
target_ulong test_kstsa16(target_ulong a, target_ulong b);
target_ulong test_ukstsa16(target_ulong a, target_ulong b);

target_ulong test_add8(target_ulong a, target_ulong b);
target_ulong test_radd8(target_ulong a, target_ulong b);
target_ulong test_uradd8(target_ulong a, target_ulong b);
target_ulong test_kadd8(target_ulong a, target_ulong b);
target_ulong test_ukadd8(target_ulong a, target_ulong b);

target_ulong test_sub8(target_ulong a, target_ulong b);
target_ulong test_rsub8(target_ulong a, target_ulong b);
target_ulong test_ursub8(target_ulong a, target_ulong b);
target_ulong test_ksub8(target_ulong a, target_ulong b);
target_ulong test_uksub8(target_ulong a, target_ulong b);

target_ulong test_sra16(target_ulong a, target_ulong b);
target_ulong test_srai16_1(target_ulong a);
target_ulong test_srai16_2(target_ulong a);
target_ulong test_srai16_15(target_ulong a);
target_ulong test_sra16_u(target_ulong a, target_ulong b);
target_ulong test_srai16_u_1(target_ulong a);
target_ulong test_srai16_u_2(target_ulong a);
target_ulong test_srl16(target_ulong a, target_ulong b);
target_ulong test_srli16_1(target_ulong a);
target_ulong test_srli16_2(target_ulong a);
target_ulong test_srli16_3(target_ulong a);
target_ulong test_srli16_15(target_ulong a);
target_ulong test_srl16_u(target_ulong a, target_ulong b);
target_ulong test_srli16_u_1(target_ulong a);
target_ulong test_srli16_u_2(target_ulong a);
target_ulong test_srli16_u_3(target_ulong a);
target_ulong test_srli16_u_15(target_ulong a);
target_ulong test_sll16(target_ulong a, target_ulong b);
target_ulong test_slli16_1(target_ulong a);
target_ulong test_slli16_9(target_ulong a);
target_ulong test_ksll16(target_ulong a, target_ulong b);
target_ulong test_kslli16_1(target_ulong a);
target_ulong test_kslli16_2(target_ulong a);
target_ulong test_kslli16_9(target_ulong a);
target_ulong test_kslra16(target_ulong a, target_ulong b);
target_ulong test_kslra16_u(target_ulong a, target_ulong b);

target_ulong test_sra8(target_ulong a, target_ulong b);
target_ulong test_srai8_1(target_ulong a);
target_ulong test_srai8_2(target_ulong a);
target_ulong test_srai8_3(target_ulong a);
target_ulong test_srai8_4(target_ulong a);
target_ulong test_srai8_7(target_ulong a);
target_ulong test_sra8_u(target_ulong a, target_ulong b);
target_ulong test_srai8_u_1(target_ulong a);
target_ulong test_srai8_u_2(target_ulong a);
target_ulong test_srai8_u_3(target_ulong a);
target_ulong test_srai8_u_4(target_ulong a);
target_ulong test_srai8_u_7(target_ulong a);
target_ulong test_srl8(target_ulong a, target_ulong b);
target_ulong test_srli8_1(target_ulong a);
target_ulong test_srli8_2(target_ulong a);
target_ulong test_srli8_3(target_ulong a);
target_ulong test_srli8_4(target_ulong a);
target_ulong test_srli8_7(target_ulong a);
target_ulong test_srl8_u(target_ulong a, target_ulong b);
target_ulong test_srli8_u_1(target_ulong a);
target_ulong test_srli8_u_2(target_ulong a);
target_ulong test_srli8_u_3(target_ulong a);
target_ulong test_srli8_u_4(target_ulong a);
target_ulong test_srli8_u_7(target_ulong a);
target_ulong test_sll8(target_ulong a, target_ulong b);
target_ulong test_slli8_1(target_ulong a);
target_ulong test_slli8_2(target_ulong a);
target_ulong test_slli8_3(target_ulong a);
target_ulong test_slli8_4(target_ulong a);
target_ulong test_slli8_7(target_ulong a);
target_ulong test_ksll8(target_ulong a, target_ulong b);
target_ulong test_kslli8_1(target_ulong a);
target_ulong test_kslli8_2(target_ulong a);
target_ulong test_kslli8_3(target_ulong a);
target_ulong test_kslli8_4(target_ulong a);
target_ulong test_kslli8_7(target_ulong a);
target_ulong test_kslra8(target_ulong a, target_ulong b);
target_ulong test_kslra8_u(target_ulong a, target_ulong b);

target_ulong test_cmpeq16(target_ulong a, target_ulong b);
target_ulong test_scmplt16(target_ulong a, target_ulong b);
target_ulong test_scmple16(target_ulong a, target_ulong b);
target_ulong test_ucmplt16(target_ulong a, target_ulong b);
target_ulong test_ucmple16(target_ulong a, target_ulong b);

target_ulong test_cmpeq8(target_ulong a, target_ulong b);
target_ulong test_scmplt8(target_ulong a, target_ulong b);
target_ulong test_scmple8(target_ulong a, target_ulong b);
target_ulong test_ucmplt8(target_ulong a, target_ulong b);
target_ulong test_ucmple8(target_ulong a, target_ulong b);

long long int test_smul16(target_ulong a, target_ulong b);
long long int test_smulx16(target_ulong a, target_ulong b);
long long int test_umul16(target_ulong a, target_ulong b);
long long int test_umulx16(target_ulong a, target_ulong b);
target_ulong test_khm16(target_ulong a, target_ulong b);
target_ulong test_khmx16(target_ulong a, target_ulong b);

long long int test_smul8(target_ulong a, target_ulong b);
long long int test_smulx8(target_ulong a, target_ulong b);
long long int test_umul8(target_ulong a, target_ulong b);
long long int test_umulx8(target_ulong a, target_ulong b);
target_ulong test_khm8(target_ulong a, target_ulong b);
target_ulong test_khmx8(target_ulong a, target_ulong b);

target_ulong test_smin16(target_ulong a, target_ulong b);
target_ulong test_umin16(target_ulong a, target_ulong b);
target_ulong test_smax16(target_ulong a, target_ulong b);
target_ulong test_umax16(target_ulong a, target_ulong b);
target_ulong test_sclip16_1(target_ulong a);
target_ulong test_sclip16_2(target_ulong a);
target_ulong test_sclip16_8(target_ulong a);
target_ulong test_sclip16_14(target_ulong a);
target_ulong test_sclip16_15(target_ulong a);
target_ulong test_uclip16_1(target_ulong a);
target_ulong test_uclip16_2(target_ulong a);
target_ulong test_uclip16_8(target_ulong a);
target_ulong test_uclip16_14(target_ulong a);
target_ulong test_uclip16_15(target_ulong a);
target_ulong test_kabs16(target_ulong a);
target_ulong test_clrs16(target_ulong a);
target_ulong test_clz16(target_ulong a);
target_ulong test_clo16(target_ulong a);

target_ulong test_smin8(target_ulong a, target_ulong b);
target_ulong test_umin8(target_ulong a, target_ulong b);
target_ulong test_smax8(target_ulong a, target_ulong b);
target_ulong test_umax8(target_ulong a, target_ulong b);
target_ulong test_sclip8_1(target_ulong a);
target_ulong test_sclip8_2(target_ulong a);
target_ulong test_sclip8_3(target_ulong a);
target_ulong test_sclip8_6(target_ulong a);
target_ulong test_sclip8_7(target_ulong a);
target_ulong test_uclip8_1(target_ulong a);
target_ulong test_uclip8_2(target_ulong a);
target_ulong test_uclip8_3(target_ulong a);
target_ulong test_uclip8_6(target_ulong a);
target_ulong test_uclip8_7(target_ulong a);
target_ulong test_kabs8(target_ulong a);
target_ulong test_clrs8(target_ulong a);
target_ulong test_clz8(target_ulong a);
target_ulong test_clo8(target_ulong a);

target_ulong test_sunpkd810(target_ulong a);
target_ulong test_sunpkd820(target_ulong a);
target_ulong test_sunpkd830(target_ulong a);
target_ulong test_sunpkd831(target_ulong a);
target_ulong test_sunpkd832(target_ulong a);
target_ulong test_zunpkd810(target_ulong a);
target_ulong test_zunpkd820(target_ulong a);
target_ulong test_zunpkd830(target_ulong a);
target_ulong test_zunpkd831(target_ulong a);
target_ulong test_zunpkd832(target_ulong a);

target_ulong test_pkbb16(target_ulong a, target_ulong b);
target_ulong test_pkbt16(target_ulong a, target_ulong b);
target_ulong test_pktt16(target_ulong a, target_ulong b);
target_ulong test_pktb16(target_ulong a, target_ulong b);

target_ulong test_smmul(target_ulong a, target_ulong b);
target_ulong test_smmul_u(target_ulong a, target_ulong b);
target_ulong test_kmmac(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmmac_u(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmmsb(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmmsb_u(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kwmmul(target_ulong a, target_ulong b);
target_ulong test_kwmmul_u(target_ulong a, target_ulong b);

target_ulong test_smmwb(target_ulong a, target_ulong b);
target_ulong test_smmwb_u(target_ulong a, target_ulong b);
target_ulong test_smmwt(target_ulong a, target_ulong b);
target_ulong test_smmwt_u(target_ulong a, target_ulong b);
target_ulong test_kmmawb(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmmawb_u(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmmawt(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmmawt_u(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmmwb2(target_ulong a, target_ulong b);
target_ulong test_kmmwb2_u(target_ulong a, target_ulong b);
target_ulong test_kmmwt2(target_ulong a, target_ulong b);
target_ulong test_kmmwt2_u(target_ulong a, target_ulong b);
target_ulong test_kmmawb2(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmmawb2_u(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmmawt2(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmmawt2_u(target_ulong a, target_ulong b, target_ulong c);

target_ulong test_add32(target_ulong a, target_ulong b);
target_ulong test_radd32(target_ulong a, target_ulong b);
target_ulong test_uradd32(target_ulong a, target_ulong b);
target_ulong test_kadd32(target_ulong a, target_ulong b);
target_ulong test_ukadd32(target_ulong a, target_ulong b);
target_ulong test_sub32(target_ulong a, target_ulong b);
target_ulong test_rsub32(target_ulong a, target_ulong b);
target_ulong test_ursub32(target_ulong a, target_ulong b);
target_ulong test_ksub32(target_ulong a, target_ulong b);
target_ulong test_uksub32(target_ulong a, target_ulong b);

target_ulong test_cras32(target_ulong a, target_ulong b);
target_ulong test_rcras32(target_ulong a, target_ulong b);
target_ulong test_urcras32(target_ulong a, target_ulong b);
target_ulong test_kcras32(target_ulong a, target_ulong b);
target_ulong test_ukcras32(target_ulong a, target_ulong b);

target_ulong test_crsa32(target_ulong a, target_ulong b);
target_ulong test_rcrsa32(target_ulong a, target_ulong b);
target_ulong test_urcrsa32(target_ulong a, target_ulong b);
target_ulong test_kcrsa32(target_ulong a, target_ulong b);
target_ulong test_ukcrsa32(target_ulong a, target_ulong b);
target_ulong test_stas32(target_ulong a, target_ulong b);
target_ulong test_rstas32(target_ulong a, target_ulong b);
target_ulong test_urstas32(target_ulong a, target_ulong b);
target_ulong test_kstas32(target_ulong a, target_ulong b);
target_ulong test_ukstas32(target_ulong a, target_ulong b);
target_ulong test_stsa32(target_ulong a, target_ulong b);
target_ulong test_rstsa32(target_ulong a, target_ulong b);
target_ulong test_urstsa32(target_ulong a, target_ulong b);
target_ulong test_kstsa32(target_ulong a, target_ulong b);
target_ulong test_ukstsa32(target_ulong a, target_ulong b);
target_ulong test_sra32(target_ulong a, target_ulong b);
target_ulong test_srai32_0(target_ulong a);
target_ulong test_srai32_1(target_ulong a);
target_ulong test_srai32_2(target_ulong a);
target_ulong test_srai32_31(target_ulong a);
target_ulong test_sra32_u(target_ulong a, target_ulong b);
target_ulong test_srai32_u_0(target_ulong a);
target_ulong test_srai32_u_1(target_ulong a);
target_ulong test_srai32_u_2(target_ulong a);
target_ulong test_srai32_u_31(target_ulong a);
target_ulong test_srl32(target_ulong a, target_ulong b);
target_ulong test_srli32_0(target_ulong a);
target_ulong test_srli32_1(target_ulong a);
target_ulong test_srli32_2(target_ulong a);
target_ulong test_srli32_31(target_ulong a);
target_ulong test_srl32_u(target_ulong a, target_ulong b);
target_ulong test_srli32_u_0(target_ulong a);
target_ulong test_srli32_u_1(target_ulong a);
target_ulong test_srli32_u_2(target_ulong a);
target_ulong test_srli32_u_31(target_ulong a);
target_ulong test_sll32(target_ulong a, target_ulong b);
target_ulong test_slli32_0(target_ulong a);
target_ulong test_slli32_1(target_ulong a);
target_ulong test_slli32_2(target_ulong a);
target_ulong test_slli32_4(target_ulong a);
target_ulong test_slli32_9(target_ulong a);
target_ulong test_slli32_31(target_ulong a);
target_ulong test_ksll32(target_ulong a, target_ulong b);
target_ulong test_kslli32_0(target_ulong a);
target_ulong test_kslli32_1(target_ulong a);
target_ulong test_kslli32_2(target_ulong a);
target_ulong test_kslli32_9(target_ulong a);
target_ulong test_kslli32_31(target_ulong a);
target_ulong test_kslra32(target_ulong a, target_ulong b);
target_ulong test_kslra32_u(target_ulong a, target_ulong b);
target_ulong test_smin32(target_ulong a, target_ulong b);
target_ulong test_umin32(target_ulong a, target_ulong b);
target_ulong test_smax32(target_ulong a, target_ulong b);
target_ulong test_umax32(target_ulong a, target_ulong b);
target_ulong test_kabs32(target_ulong a);
target_ulong test_khmbb16(target_ulong a, target_ulong b);
target_ulong test_khmbt16(target_ulong a, target_ulong b);
target_ulong test_khmtt16(target_ulong a, target_ulong b);
target_ulong test_kdmbb16(target_ulong a, target_ulong b);
target_ulong test_kdmbt16(target_ulong a, target_ulong b);
target_ulong test_kdmtt16(target_ulong a, target_ulong b);
target_ulong test_kdmabb16(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kdmabt16(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kdmatt16(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_smbt32(target_ulong a, target_ulong b);
target_ulong test_smtt32(target_ulong a, target_ulong b);
target_ulong test_kmabb32(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmabt32(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmatt32(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmda32(target_ulong a, target_ulong b);
target_ulong test_kmxda32(target_ulong a, target_ulong b);
target_ulong test_kmada32(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmaxda32(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmads32(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmadrs32(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmaxds32(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmsda32(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmsxda32(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_smds32(target_ulong a, target_ulong b);
target_ulong test_smdrs32(target_ulong a, target_ulong b);
target_ulong test_smxds32(target_ulong a, target_ulong b);
target_ulong test_sraiw_u_0(target_ulong a);
target_ulong test_sraiw_u_1(target_ulong a);
target_ulong test_sraiw_u_2(target_ulong a);
target_ulong test_sraiw_u_31(target_ulong a);
target_ulong test_pkbb32(target_ulong a, target_ulong b);
target_ulong test_pkbt32(target_ulong a, target_ulong b);
target_ulong test_pktt32(target_ulong a, target_ulong b);
target_ulong test_pktb32(target_ulong a, target_ulong b);

target_ulong test_smbb16(target_ulong a, target_ulong b);
target_ulong test_smbt16(target_ulong a, target_ulong b);
target_ulong test_smtt16(target_ulong a, target_ulong b);
target_ulong test_kmda(target_ulong a, target_ulong b);
target_ulong test_kmxda(target_ulong a, target_ulong b);
target_ulong test_smds(target_ulong a, target_ulong b);
target_ulong test_smdrs(target_ulong a, target_ulong b);
target_ulong test_smxds(target_ulong a, target_ulong b);
target_ulong test_kmabb(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmabt(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmatt(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmada(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmaxda(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmads(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmadrs(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmaxds(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmsda(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kmsxda(target_ulong a, target_ulong b, target_ulong c);

long long int test_smal(long long int a, target_ulong b);

target_ulong test_sclip32_0(target_ulong a);
target_ulong test_sclip32_1(target_ulong a);
target_ulong test_sclip32_5(target_ulong a);
target_ulong test_sclip32_30(target_ulong a);
target_ulong test_sclip32_31(target_ulong a);
target_ulong test_uclip32_0(target_ulong a);
target_ulong test_uclip32_1(target_ulong a);
target_ulong test_uclip32_2(target_ulong a);
target_ulong test_uclip32_6(target_ulong a);
target_ulong test_uclip32_31(target_ulong a);
target_ulong test_clrs32(target_ulong a);
target_ulong test_clz32(target_ulong a);
target_ulong test_clo32(target_ulong a);
target_ulong test_pbsad(target_ulong a, target_ulong b);
target_ulong test_pbsada(target_ulong a, target_ulong b, target_ulong c);

target_ulong test_smaqa(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_umaqa(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_smaqa_su(target_ulong a, target_ulong b, target_ulong c);

long long int test_add64(long long int a, long long int b);
long long int test_radd64(long long int a, long long int b);
long long int test_uradd64(long long int a, long long int b);
long long int test_kadd64(long long a, long long b);
long long int test_ukadd64(long long int a, long long int b);
long long int test_sub64(long long int a, long long int b);
long long int test_rsub64(long long int a, long long int b);
long long int test_ursub64(long long int a, long long int b);
long long int test_ksub64(long long int a, long long int b);
long long int test_uksub64(long long int a, long long int b);

long long int test_smar64(target_ulong a, target_ulong b, long long int c);
long long int test_smsr64(target_ulong a, target_ulong b, long long int c);
long long int test_umar64(target_ulong a, target_ulong b, long long int c);
long long int test_umsr64(target_ulong a, target_ulong b, long long int c);
long long int test_kmar64(target_ulong a, target_ulong b, long long int c);
long long int test_kmsr64(target_ulong a, target_ulong b, long long int c);
long long int test_ukmar64(target_ulong a, target_ulong b, long long int c);
long long int test_ukmsr64(target_ulong a, target_ulong b, long long int c);

long long int test_smalbb(target_ulong a, target_ulong b, long long int c);
long long int test_smalbt(target_ulong a, target_ulong b, long long int c);
long long int test_smaltt(target_ulong a, target_ulong b, long long int c);
long long int test_smalda(target_ulong a, target_ulong b, long long int c);
long long int test_smalxda(target_ulong a, target_ulong b, long long int c);
long long int test_smalds(target_ulong a, target_ulong b, long long int c);
long long int test_smaldrs(target_ulong a, target_ulong b, long long int c);
long long int test_smalxds(target_ulong a, target_ulong b, long long int c);
long long int test_smslda(target_ulong a, target_ulong b, long long int c);
long long int test_smslxda(target_ulong a, target_ulong b, long long int c);

target_ulong test_kaddh(target_ulong a, target_ulong b);
target_ulong test_ukaddh(target_ulong a, target_ulong b);
target_ulong test_ksubh(target_ulong a, target_ulong b);
target_ulong test_uksubh(target_ulong a, target_ulong b);
target_ulong test_khmbb(target_ulong a, target_ulong b);
target_ulong test_khmbt(target_ulong a, target_ulong b);
target_ulong test_khmtt(target_ulong a, target_ulong b);

target_ulong test_kaddw(target_ulong a, target_ulong b);
target_ulong test_ukaddw(target_ulong a, target_ulong b);
target_ulong test_ksubw(target_ulong a, target_ulong b);
target_ulong test_uksubw(target_ulong a, target_ulong b);
target_ulong test_kdmbb(target_ulong a, target_ulong b);
target_ulong test_kdmbt(target_ulong a, target_ulong b);
target_ulong test_kdmtt(target_ulong a, target_ulong b);
target_ulong test_kslraw(target_ulong a, target_ulong b);
target_ulong test_kslraw_u(target_ulong a, target_ulong b);
target_ulong test_ksllw(target_ulong a, target_ulong b);
target_ulong test_kslliw_1(target_ulong a);
target_ulong test_kslliw_2(target_ulong a);
target_ulong test_kslliw_9(target_ulong a);
target_ulong test_kslliw_31(target_ulong a);
target_ulong test_kdmabb(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kdmabt(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kdmatt(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_kabsw(target_ulong a);

target_ulong test_raddw(target_ulong a, target_ulong b);
target_ulong test_uraddw(target_ulong a, target_ulong b);
target_ulong test_rsubw(target_ulong a, target_ulong b);
target_ulong test_ursubw(target_ulong a, target_ulong b);
target_ulong test_maxw(target_ulong a, target_ulong b);
target_ulong test_minw(target_ulong a, target_ulong b);
target_ulong test_mulr64(target_ulong a, target_ulong b);
target_ulong test_mulsr64(target_ulong a, target_ulong b);

target_ulong test_ave(target_ulong a, target_ulong b);
target_ulong test_sra_u(target_ulong a, target_ulong b);
target_ulong test_srai_u_0(target_ulong a);
target_ulong test_srai_u_1(target_ulong a);
target_ulong test_srai_u_2(target_ulong a);
target_ulong test_srai_u_16(target_ulong a);
target_ulong test_srai_u_31(target_ulong a);
#ifdef RV64
target_ulong test_srai_u_63(target_ulong a);
#endif
target_ulong test_bitrev(target_ulong a, target_ulong b);
target_ulong test_bitrevi_0(target_ulong a);
target_ulong test_bitrevi_1(target_ulong a);
target_ulong test_bitrevi_2(target_ulong a);
target_ulong test_bitrevi_16(target_ulong a);
target_ulong test_bitrevi_31(target_ulong a);
#ifdef RV64
target_ulong test_bitrevi_63(target_ulong a);
#endif
target_ulong test_wext(long long int, target_ulong b);

target_ulong test_wexti_2(long long int a);
target_ulong test_wexti_4(long long int a);
target_ulong test_wexti_8(long long int a);
target_ulong test_wexti_31(long long int a);

target_ulong test_bpick(target_ulong a, target_ulong b, target_ulong c);
target_ulong test_insb_0(target_ulong a, target_ulong b);
target_ulong test_insb_1(target_ulong a, target_ulong b);
target_ulong test_insb_2(target_ulong a, target_ulong b);
target_ulong test_insb_3(target_ulong a, target_ulong b);
target_ulong test_insb_4(target_ulong a, target_ulong b);
target_ulong test_insb_5(target_ulong a, target_ulong b);
target_ulong test_insb_6(target_ulong a, target_ulong b);
target_ulong test_insb_7(target_ulong a, target_ulong b);
target_ulong test_maddr32(target_ulong a, target_ulong b, target_ulong c);
#endif
