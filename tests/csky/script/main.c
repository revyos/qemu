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

/*
 *  CSKY DSPv2 test case data generate.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "inst_dspv2.h"

FILE *fp;
FILE *fp_sample_h;
FILE *fp_dspv2_insn_s;
FILE *fp_dspv2_insn_h;
FILE *fp_case_c;
#define ISSPACE(c) (c == ' ' || c == '\t')

enum op_type {
    I_NO,
    I64,
    I32,
};
/* num = 1, op1 = rx                                    */
/* num = 2, op1 = rx, op2 = ry                          */
/* num = 3, op1 = rx, op2 = ry, op3 = rz,rz+1           */

struct _func_map {
    char *name;
    void *func;
    int ret_type;
    enum op_type op_num;
    enum op_type op1_type;
    enum op_type op2_type;
    enum op_type op3_type;
    enum op_type op4_type;
};

struct _func_map funcs[] = {
    {"padd.u8.s", &DSPV2_HELPER(padd_u8_s), I32, 2, I32, I32, I_NO, I_NO},
    {"padd.s8.s", &DSPV2_HELPER(padd_s8_s), I32, 2, I32, I32, I_NO, I_NO},
    {"padd.u16.s", &DSPV2_HELPER(padd_u16_s), I32, 2, I32, I32, I_NO, I_NO},
    {"padd.s16.s", &DSPV2_HELPER(padd_s16_s), I32, 2, I32, I32, I_NO, I_NO},
    {"add.u32.s", &DSPV2_HELPER(add_u32_s), I32, 2, I32, I32, I_NO, I_NO},
    {"add.s32.s", &DSPV2_HELPER(add_s32_s), I32, 2, I32, I32, I_NO, I_NO},
    {"psub.u8.s", &DSPV2_HELPER(psub_u8_s), I32, 2, I32, I32, I_NO, I_NO},
    {"psub.s8.s", &DSPV2_HELPER(psub_s8_s), I32, 2, I32, I32, I_NO, I_NO},
    {"psub.u16.s", &DSPV2_HELPER(psub_u16_s), I32, 2, I32, I32, I_NO, I_NO},
    {"psub.s16.s", &DSPV2_HELPER(psub_s16_s), I32, 2, I32, I32, I_NO, I_NO},
    {"sub.u32.s", &DSPV2_HELPER(sub_u32_s), I32, 2, I32, I32, I_NO, I_NO},
    {"sub.s32.s", &DSPV2_HELPER(sub_s32_s), I32, 2, I32, I32, I_NO, I_NO},
    {"paddh.u8", &DSPV2_HELPER(paddh_u8), I32, 2, I32, I32, I_NO, I_NO},
    {"paddh.s8", &DSPV2_HELPER(paddh_s8), I32, 2, I32, I32, I_NO, I_NO},
    {"paddh.u16", &DSPV2_HELPER(paddh_u16), I32, 2, I32, I32, I_NO, I_NO},
    {"paddh.s16", &DSPV2_HELPER(paddh_s16), I32, 2, I32, I32, I_NO, I_NO},
    {"psubh.u8", &DSPV2_HELPER(psubh_u8), I32, 2, I32, I32, I_NO, I_NO},
    {"psubh.s8", &DSPV2_HELPER(psubh_s8), I32, 2, I32, I32, I_NO, I_NO},
    {"psubh.u16", &DSPV2_HELPER(psubh_u16), I32, 2, I32, I32, I_NO, I_NO},
    {"psubh.s16", &DSPV2_HELPER(psubh_s16), I32, 2, I32, I32, I_NO, I_NO},
    {"add.u64.s", &DSPV2_HELPER(add_u64_s), I64, 2, I64, I64, I_NO, I_NO},
    {"add.s64.s", &DSPV2_HELPER(add_s64_s), I64, 2, I64, I64, I_NO, I_NO},
    {"sub.u64.s", &DSPV2_HELPER(sub_u64_s), I64, 2, I64, I64, I_NO, I_NO},
    {"sub.s64.s", &DSPV2_HELPER(sub_s64_s), I64, 2, I64, I64, I_NO, I_NO},
    {"pasx.u16.s", &DSPV2_HELPER(pasx_u16_s), I32, 2, I32, I32, I_NO, I_NO},
    {"pasx.s16.s", &DSPV2_HELPER(pasx_s16_s), I32, 2, I32, I32, I_NO, I_NO},
    {"psax.u16.s", &DSPV2_HELPER(psax_u16_s), I32, 2, I32, I32, I_NO, I_NO},
    {"psax.s16.s", &DSPV2_HELPER(psax_s16_s), I32, 2, I32, I32, I_NO, I_NO},
    {"pasxh.u16", &DSPV2_HELPER(pasxh_u16), I32, 2, I32, I32, I_NO, I_NO},
    {"pasxh.s16", &DSPV2_HELPER(pasxh_s16), I32, 2, I32, I32, I_NO, I_NO},
    {"psaxh.u16", &DSPV2_HELPER(psaxh_u16), I32, 2, I32, I32, I_NO, I_NO},
    {"psaxh.s16", &DSPV2_HELPER(psaxh_s16), I32, 2, I32, I32, I_NO, I_NO},
    {"pcmpne.8", &DSPV2_HELPER(pcmpne_8), I32, 2, I32, I32, I_NO, I_NO},
    {"pcmpne.16", &DSPV2_HELPER(pcmpne_16), I32, 2, I32, I32, I_NO, I_NO},
    {"pcmphs.u8", &DSPV2_HELPER(pcmphs_u8), I32, 2, I32, I32, I_NO, I_NO},
    {"pcmphs.s8", &DSPV2_HELPER(pcmphs_s8), I32, 2, I32, I32, I_NO, I_NO},
    {"pcmphs.u16", &DSPV2_HELPER(pcmphs_u16), I32, 2, I32, I32, I_NO, I_NO},
    {"pcmphs.s16", &DSPV2_HELPER(pcmphs_s16), I32, 2, I32, I32, I_NO, I_NO},
    {"pcmplt.u8", &DSPV2_HELPER(pcmplt_u8), I32, 2, I32, I32, I_NO, I_NO},
    {"pcmplt.s8", &DSPV2_HELPER(pcmplt_s8), I32, 2, I32, I32, I_NO, I_NO},
    {"pcmplt.u16", &DSPV2_HELPER(pcmplt_u16), I32, 2, I32, I32, I_NO, I_NO},
    {"pcmplt.s16", &DSPV2_HELPER(pcmplt_s16), I32, 2, I32, I32, I_NO, I_NO},
    {"pmax.u8", &DSPV2_HELPER(pmax_u8), I32, 2, I32, I32, I_NO, I_NO},
    {"pmax.s8", &DSPV2_HELPER(pmax_s8), I32, 2, I32, I32, I_NO, I_NO},
    {"pmin.u8", &DSPV2_HELPER(pmin_u8), I32, 2, I32, I32, I_NO, I_NO},
    {"pmin.s8", &DSPV2_HELPER(pmin_s8), I32, 2, I32, I32, I_NO, I_NO},
    {"psabsa.u8", &DSPV2_HELPER(psabsa_u8), I32, 2, I32, I32, I_NO, I_NO},
    {"psabsaa.u8", &DSPV2_HELPER(psabsaa_u8), I32, 3, I32, I32, I32, I_NO},
    {"lsli.32.s", &DSPV2_HELPER(lsli_32_s), I32, 2, I32, I32, I_NO, I_NO},
    {"lsl.32.s", &DSPV2_HELPER(lsl_32_s), I32, 2, I32, I32, I_NO, I_NO},
    {"plsli.u16.s", &DSPV2_HELPER(plsli_u16_s), I32, 2, I32, I32, I_NO, I_NO},
    {"plsl.u16.s", &DSPV2_HELPER(plsl_u16_s), I32, 2, I32, I32, I_NO, I_NO},
    {"pext.u8.e", &DSPV2_HELPER(pext_u8_e), I64, 1, I32, I_NO, I_NO, I_NO},
    {"pext.s8.e", &DSPV2_HELPER(pext_s8_e), I64, 1, I32, I_NO, I_NO, I_NO},
    {"pextx.u8.e", &DSPV2_HELPER(pextx_u8_e), I64, 1, I32, I_NO, I_NO, I_NO},
    {"pextx.s8.e", &DSPV2_HELPER(pextx_s8_e), I64, 1, I32, I_NO, I_NO, I_NO},
    {"narl", &DSPV2_HELPER(narl), I32, 2, I32, I32, I_NO, I_NO},
    {"narh", &DSPV2_HELPER(narh), I32, 2, I32, I32, I_NO, I_NO},
    {"narlx", &DSPV2_HELPER(narlx), I32, 2, I32, I32, I_NO, I_NO},
    {"narhx", &DSPV2_HELPER(narhx), I32, 2, I32, I32, I_NO, I_NO},
    {"clipi.u32", &DSPV2_HELPER(clipi_u32), I32, 2, I32, I32, I_NO, I_NO},
    {"clipi.s32", &DSPV2_HELPER(clipi_s32), I32, 2, I32, I32, I_NO, I_NO},
    {"clip.u32", &DSPV2_HELPER(clip_u32), I32, 2, I32, I32, I_NO, I_NO},
    {"clip.s32", &DSPV2_HELPER(clip_s32), I32, 2, I32, I32, I_NO, I_NO},
    {"pclipi.u16", &DSPV2_HELPER(pclipi_u16), I32, 2, I32, I32, I_NO, I_NO},
    {"pclipi.s16", &DSPV2_HELPER(pclipi_s16), I32, 2, I32, I32, I_NO, I_NO},
    {"pclip.u16", &DSPV2_HELPER(pclip_u16), I32, 2, I32, I32, I_NO, I_NO},
    {"pclip.s16", &DSPV2_HELPER(pclip_s16), I32, 2, I32, I32, I_NO, I_NO},
    {"pabs.s8.s", &DSPV2_HELPER(pabs_s8_s), I32, 1, I32, I_NO, I_NO},
    {"pabs.s16.s", &DSPV2_HELPER(pabs_s16_s), I32, 1, I32, I_NO, I_NO, I_NO},
    {"abs.s32.s", &DSPV2_HELPER(abs_s32_s), I32, 1, I32, I_NO, I_NO, I_NO},
    {"pneg.s8.s", &DSPV2_HELPER(pneg_s8_s), I32, 1, I32, I_NO, I_NO, I_NO},
    {"pneg.s16.s", &DSPV2_HELPER(pneg_s16_s), I32, 1, I32, I_NO, I_NO, I_NO},
    {"neg.s32.s", &DSPV2_HELPER(neg_s32_s), I32, 1, I32, I_NO, I_NO, I_NO},
    {"mula.u32.s", &DSPV2_HELPER(mula_u32_s), I64, 3, I32, I32, I64, I_NO},
    {"mula.s32.s", &DSPV2_HELPER(mula_s32_s), I64, 3, I32, I32, I64, I_NO},
    {"muls.u32.s", &DSPV2_HELPER(muls_u32_s), I64, 3, I32, I32, I64, I_NO},
    {"muls.s32.s", &DSPV2_HELPER(muls_s32_s), I64, 3, I32, I32, I64, I_NO},
    {"mula.32.l", &DSPV2_HELPER(mula_32_l), I32, 3, I32, I32, I32, I_NO},
    {"rmul.s32.h", &DSPV2_HELPER(rmul_s32_h), I32, 2, I32, I32, I_NO, I_NO},
    {"rmul.s32.rh", &DSPV2_HELPER(rmul_s32_rh), I32, 2, I32, I32, I_NO, I_NO},
    {"mula.s32.hs", &DSPV2_HELPER(mula_s32_hs), I32, 3, I32, I32, I32, I_NO},
    {"muls.s32.hs", &DSPV2_HELPER(muls_s32_hs), I32, 3, I32, I32, I32, I_NO},
    {"mula.s32.rhs", &DSPV2_HELPER(mula_s32_rhs), I32, 3, I32, I32, I32, I_NO},
    {"muls.s32.rhs", &DSPV2_HELPER(muls_s32_rhs), I32, 3, I32, I32, I32, I_NO},
    {"rmulll.s16", &DSPV2_HELPER(rmulll_s16), I32, 2, I32, I32, I_NO, I_NO},
    {"rmulhh.s16", &DSPV2_HELPER(rmulhh_s16), I32, 2, I32, I32, I_NO, I_NO},
    {"rmulhl.s16", &DSPV2_HELPER(rmulhl_s16), I32, 2, I32, I32, I_NO, I_NO},
    {"mulall.s16", &DSPV2_HELPER(mulall_s16), I32, 3, I32, I32, I32, I_NO},
    {"mulall.s16.s", &DSPV2_HELPER(mulall_s16_s), I32, 3, I32, I32, I32, I_NO},
    {"mulahh.s16.s", &DSPV2_HELPER(mulahh_s16_s), I32, 3, I32, I32, I32, I_NO},
    {"mulahl.s16.s", &DSPV2_HELPER(mulahl_s16_s), I32, 3, I32, I32, I32, I_NO},
    {"mulall.s16.e", &DSPV2_HELPER(mulall_s16_e), I64, 3, I32, I32, I64, I_NO},
    {"mulahh.s16.e", &DSPV2_HELPER(mulahh_s16_e), I64, 3, I32, I32, I64, I_NO},
    {"mulahl.s16.e", &DSPV2_HELPER(mulahl_s16_e), I64, 3, I32, I32, I64, I_NO},
    {"prmul.s16", &DSPV2_HELPER(prmul_s16), I64, 2, I32, I32, I_NO, I_NO},
    {"prmulx.s16", &DSPV2_HELPER(prmulx_s16), I64, 2, I32, I32, I_NO, I_NO},
    {"prmul.s16.h", &DSPV2_HELPER(prmul_s16_h), I32, 2, I32, I32, I_NO, I_NO},
    {"prmul.s16.rh", &DSPV2_HELPER(prmul_s16_rh), I32, 2, I32, I32, I_NO, I_NO},
    {"prmulx.s16.h", &DSPV2_HELPER(prmulx_s16_h), I32, 2, I32, I32, I_NO, I_NO},
    {"prmulx.s16.rh", &DSPV2_HELPER(prmulx_s16_rh), I32, 2, I32, I32, I_NO, I_NO},
    {"rmulxl.s32", &DSPV2_HELPER(rmulxl_s32), I32, 2, I32, I32, I_NO, I_NO},
    {"rmulxl.s32.r", &DSPV2_HELPER(rmulxl_s32_r), I32, 2, I32, I32, I_NO, I_NO},
    {"rmulxh.s32", &DSPV2_HELPER(rmulxh_s32), I32, 2, I32, I32, I_NO, I_NO},
    {"rmulxh.s32.r", &DSPV2_HELPER(rmulxh_s32_r), I32, 2, I32, I32, I_NO, I_NO},
    {"mulaxl.s32.s", &DSPV2_HELPER(mulaxl_s32_s), I32, 3, I32, I32, I32, I_NO},
    {"mulaxl.s32.rs", &DSPV2_HELPER(mulaxl_s32_rs), I32, 3, I32, I32, I32, I_NO},
    {"mulaxh.s32.s", &DSPV2_HELPER(mulaxh_s32_s), I32, 3, I32, I32, I32, I_NO},
    {"mulaxh.s32.rs", &DSPV2_HELPER(mulaxh_s32_rs), I32, 3, I32, I32, I32, I_NO},
    {"mulca.s16.s", &DSPV2_HELPER(mulca_s16_s), I32, 2, I32, I32, I_NO, I_NO},
    {"mulcax.s16.s", &DSPV2_HELPER(mulcax_s16_s), I32, 2, I32, I32, I_NO, I_NO},
    {"mulaca.s16.s", &DSPV2_HELPER(mulaca_s16_s), I32, 3, I32, I32, I32, I_NO},
    {"mulacax.s16.s", &DSPV2_HELPER(mulacax_s16_s), I32, 3, I32, I32, I32, I_NO},
    {"mulacs.s16.s", &DSPV2_HELPER(mulacs_s16_s), I32, 3, I32, I32, I32, I_NO},
    {"mulacsr.s16.s", &DSPV2_HELPER(mulacsr_s16_s), I32, 3, I32, I32, I32, I_NO},
    {"mulacsx.s16.s", &DSPV2_HELPER(mulacsx_s16_s), I32, 3, I32, I32, I32, I_NO},
    {"mulsca.s16.s", &DSPV2_HELPER(mulsca_s16_s), I32, 3, I32, I32, I32, I_NO},
    {"mulscax.s16.s", &DSPV2_HELPER(mulscax_s16_s), I32, 3, I32, I32, I32, I_NO},
    /* TCG instructions */
    {"muls.u32", &DSPV2_HELPER(muls_u32), I64, 3, I32, I32, I64, I_NO},
    {"muls.s32", &DSPV2_HELPER(muls_s32), I64, 3, I32, I32, I64, I_NO},
    {"mulxl.s32", &DSPV2_HELPER(mulxl_s32), I32, 2, I32, I32, I_NO, I_NO},
    {"mulxl.s32.r", &DSPV2_HELPER(mulxl_s32_r), I32, 2, I32, I32, I_NO, I_NO},
    {"mulxh.s32", &DSPV2_HELPER(mulxl_s32), I32, 2, I32, I32, I_NO, I_NO},
    {"mulxh.s32.r", &DSPV2_HELPER(mulxl_s32_r), I32, 2, I32, I32, I_NO, I_NO},
    {"pmul.s16", &DSPV2_HELPER(pmul_s16), I64, 2, I32, I32, I_NO, I_NO},
    {"pmul.u16", &DSPV2_HELPER(pmul_u16), I64, 2, I32, I32, I_NO, I_NO},
    {"pmulx.s16", &DSPV2_HELPER(pmulx_s16), I64, 2, I32, I32, I_NO, I_NO},
    {"pmulx.u16", &DSPV2_HELPER(pmulx_u16), I64, 2, I32, I32, I_NO, I_NO},
    {"mulcs.s16", &DSPV2_HELPER(mulcs_s16), I32, 2, I32, I32, I_NO, I_NO},
    {"mulcsr.s16", &DSPV2_HELPER(mulcsr_s16), I32, 2, I32, I32, I_NO, I_NO},
    {"mulcsx.s16", &DSPV2_HELPER(mulcsx_s16), I32, 2, I32, I32, I_NO, I_NO},
    {"mulaca.s16.e", &DSPV2_HELPER(mulaca_s16_e), I64, 3, I32, I32, I64, I_NO},
    {"mulacax.s16.e", &DSPV2_HELPER(mulacax_s16_e), I64, 3, I32, I32, I64, I_NO},
    {"mulacs.s16.e", &DSPV2_HELPER(mulacs_s16_e), I64, 3, I32, I32, I64, I_NO},
    {"mulacsr.s16.e", &DSPV2_HELPER(mulacsr_s16_e), I64, 3, I32, I32, I64, I_NO},
    {"mulacsx.s16.e", &DSPV2_HELPER(mulacsx_s16_e), I64, 3, I32, I32, I64, I_NO},
    {"mulsca.s16.e", &DSPV2_HELPER(mulsca_s16_e), I64, 3, I32, I32, I64, I_NO},
    {"mulscax.s16.e", &DSPV2_HELPER(mulscax_s16_e), I64, 3, I32, I32, I64, I_NO},
    {"mul.u32", &DSPV2_HELPER(mul_u32), I64, 2, I32, I32, I_NO, I_NO},
    {"mul.s32", &DSPV2_HELPER(mul_s32), I64, 2, I32, I32, I_NO, I_NO},
    {"mula.u32", &DSPV2_HELPER(mula_u32), I64, 3, I32, I32, I64, I_NO},
    {"mula.s32", &DSPV2_HELPER(mula_s32), I64, 3, I32, I32, I64, I_NO},
    {"mul.s32.h", &DSPV2_HELPER(mul_s32_h), I32, 2, I32, I32, I_NO, I_NO},
    {"mul.s32.rh", &DSPV2_HELPER(mul_s32_rh), I32, 2, I32, I32, I_NO, I_NO},
    {"mulll.s16", &DSPV2_HELPER(mulll_s16), I32, 2, I32, I32, I_NO, I_NO},
    {"mulhh.s16", &DSPV2_HELPER(mulhh_s16), I32, 2, I32, I32, I_NO, I_NO},
    {"mulhl.s16", &DSPV2_HELPER(mulhl_s16), I32, 2, I32, I32, I_NO, I_NO},
};

enum line_type {
    INSN,
    SAMPLE,
    NOTE,
    UNKOWN,
    EMPTY_LINE,
    IS_EOF,
};

struct CASE_DATA {
    char name[20];
    uint64_t case_op[4];
};

struct line {
    char str[100];
    char underline_name[20];
    enum line_type type;
    int is_find;
    int new_insn;
    int print_end;
    struct CASE_DATA test_data;
    struct _func_map *funcs_addr;
} line;

int get_a_line()
{
    int i = 0;
    if (fgets(line.str, 100, fp) == NULL)
    {
        line.type = IS_EOF;
        return;
    }
    char *c = line.str;
    while (ISSPACE(*c)) {
        c++;
    }

    if (*c == '#') {
        char *name_c = &line.test_data.name[0];
        line.type = INSN;
        line.is_find = FALSE;
        c++;
        while (!ISSPACE(*c) && *c != '\0' && *c != '\n' && i < 19) {
            *(name_c++) = *(c++);
            i++;
        }
        *name_c = '\0';
    } else if (*c == '/') {
        if (*c == '/') {
            line.type = NOTE;
        }
        else {
            line.type = UNKOWN;
        }
    } else if (*c == '\n') {
        line.type = EMPTY_LINE;
    } else {
        line.type = SAMPLE;
        char num[20];
        int j = 0;
        while (*c != '\0' && *c != '\n') {
            i = 0;
            while (!ISSPACE(*c) && *c != '\0' && *c != '\n' && i < 19) {
                num[i++] = *(c++);
            }
            num[i] = '\0';
            line.test_data.case_op[j++] = strtoull (num, NULL, 0);
            while (ISSPACE(*c)) {
                c++;
            }
        }
    }
    return 0;
}
void exchange_name(void)
{
    /* replace the '.' with '_' in insn name. */
    char *name_dst = line.underline_name;
    char *name_src = line.test_data.name;
    while (*name_src != '\0') {
        if (*name_src == '.') {
            *name_dst = '_';
        } else {
            *name_dst = *name_src;
        }
        name_src++;
        name_dst++;
    }
    *name_dst = '\0';
}

int find_insn()
{
    int i;
    for (i = 0; i < sizeof(funcs)/sizeof(struct _func_map); i++) {
        if (strcmp(line.test_data.name, funcs[i].name) == 0) {
            line.is_find = TRUE;
            line.new_insn = TRUE;
            line.funcs_addr = &funcs[i];
            break;
        }
    }
    if (line.is_find == TRUE) {
        exchange_name();
        if (line.print_end == TRUE){
            line.print_end = FALSE;
            fprintf(fp_sample_h, "};\n\n");
        }
        fprintf(fp_sample_h, "/* %s */\n", line.test_data.name);
    } else {
        printf("\nError: can not find %s\n", line.test_data.name);
    }
}

/* print casae xxxx.c head */
void print_case_head()
{
    fprintf(fp_case_c, "#include \"testsuite.h\"\n");
    fprintf(fp_case_c, "#include \"test_device.h\"\n");
    fprintf(fp_case_c, "#include \"dspv2_insn.h\"\n");
    fprintf(fp_case_c, "#include \"sample_array.h\"\n");
    fprintf(fp_case_c, "int main(void)\n");
    fprintf(fp_case_c, "{\n");
    fprintf(fp_case_c, "    int i = 0;\n");
    fprintf(fp_case_c, "    init_testsuite(\"Testing insn %s\\n\");\n\n",
            line.test_data.name);
}

int calc_case()
{
    uint32_t (*func_www)(uint32_t, uint32_t);
    uint32_t (*func_wwww)(uint32_t, uint32_t, uint32_t);
    uint64_t (*func_dww)(uint32_t, uint32_t);
    uint64_t (*func_dwwd)(uint32_t, uint32_t, int32_t, int32_t);
    uint32_t ret_w;
    uint64_t ret_d;
    char file_name[35] = "./case/";
    if (line.funcs_addr->op_num == 2
            && line.funcs_addr->ret_type == I32
            && line.funcs_addr->op1_type == I32
            && line.funcs_addr->op2_type == I32) {
        func_www = line.funcs_addr->func;
        ret_w = (*func_www)((uint32_t)(line.test_data.case_op[0]),
                (uint32_t)(line.test_data.case_op[1]));

        if (line.new_insn == TRUE) {
            fprintf(fp_sample_h, "struct binary_calculation samples_%s[] = {\n",
                    line.underline_name);
            fprintf(fp_dspv2_insn_s, "\nTEST_FUNC(test_%s)\n",
                    line.underline_name);
            fprintf(fp_dspv2_insn_s, "    %s    a0, a0, a1\n",
                    line.test_data.name);
            fprintf(fp_dspv2_insn_s, "    rts\n");
            fprintf(fp_dspv2_insn_s, "    .size   test_%s, .-test_%s\n",
                    line.underline_name, line.underline_name);
            fprintf(fp_dspv2_insn_h, "int32_t test_%s(int32_t a, int32_t b);\n",
                    line.underline_name);
            /* case file: xxxx.c */
            strcat(file_name, line.underline_name);
            strcat(file_name, ".c");
            fp_case_c = fopen(file_name, "w");
            print_case_head();
            fprintf(fp_case_c, "    for (i = 0;\n");
            fprintf(fp_case_c,
                    "         i < sizeof(samples_%s)/sizeof(struct binary_calculation);\n",
                    line.underline_name);
            fprintf(fp_case_c, "         i++) {\n");
            fprintf(fp_case_c,
                    "        TEST(test_%s(samples_%s[i].op1, samples_%s[i].op2)\n",
                    line.underline_name, line.underline_name,
                    line.underline_name);
            fprintf(fp_case_c, "                     == samples_%s[i].result);\n",
                    line.underline_name);
            fprintf(fp_case_c, "    }\n");
            fprintf(fp_case_c, "    return done_testing();\n");
            fprintf(fp_case_c, "}\n");
            fclose(fp_case_c);
            line.new_insn = FALSE;
            line.print_end = TRUE;
        }
        fprintf(fp_sample_h, "    {0x%08x, 0x%08x, 0x%08x},\n",
                (uint32_t)line.test_data.case_op[0],
                (uint32_t)line.test_data.case_op[1], ret_w);
    } else if (line.funcs_addr->op_num == 2
            && line.funcs_addr->ret_type == I64
            && line.funcs_addr->op1_type == I32
            && line.funcs_addr->op2_type == I32) {
        func_dww = line.funcs_addr->func;
        ret_d = (*func_dww)((uint32_t)(line.test_data.case_op[0]),
                (uint32_t)(line.test_data.case_op[1]));

        if (line.new_insn == TRUE) {
            fprintf(fp_sample_h, "struct binary64_calculation samples_%s[] = {\n",
                    line.underline_name);
            fprintf(fp_dspv2_insn_s, "\nTEST_FUNC(test_%s)\n",
                    line.underline_name);
            fprintf(fp_dspv2_insn_s, "    %s    a0, a0, a1\n",
                    line.test_data.name);
            fprintf(fp_dspv2_insn_s, "    rts\n");
            fprintf(fp_dspv2_insn_s, "    .size   test_%s, .-test_%s\n",
                    line.underline_name, line.underline_name);
            fprintf(fp_dspv2_insn_h, "int64_t test_%s(int32_t a, int32_t b);\n",
                    line.underline_name);
            /* case file: xxxx.c */
            strcat(file_name, line.underline_name);
            strcat(file_name, ".c");
            fp_case_c = fopen(file_name, "w");
            print_case_head();
            fprintf(fp_case_c, "    for (i = 0;\n");
            fprintf(fp_case_c,
                    "         i < sizeof(samples_%s)/sizeof(struct binary64_calculation);\n",
                    line.underline_name);
            fprintf(fp_case_c, "         i++) {\n");
            fprintf(fp_case_c,
                    "        TEST(test_%s(samples_%s[i].op1, samples_%s[i].op2)\n",
                    line.underline_name, line.underline_name,
                    line.underline_name);
            fprintf(fp_case_c, "                     == samples_%s[i].result);\n",
                    line.underline_name);
            fprintf(fp_case_c, "    }\n");
            fprintf(fp_case_c, "    return done_testing();\n");
            fprintf(fp_case_c, "}\n");
            fclose(fp_case_c);
            line.new_insn = FALSE;
            line.print_end = TRUE;
        }
        fprintf(fp_sample_h, "    {0x%08x, 0x%08x, 0x%016llx},\n",
                (uint32_t)line.test_data.case_op[0],
                (uint32_t)line.test_data.case_op[1], ret_d);
    } else  if (line.funcs_addr->op_num == 3
            && line.funcs_addr->ret_type == I32
            && line.funcs_addr->op1_type == I32
            && line.funcs_addr->op2_type == I32
            && line.funcs_addr->op3_type == I32) {
        func_wwww = line.funcs_addr->func;
        ret_w = (*func_wwww)((uint32_t)(line.test_data.case_op[2]),
                (uint32_t)(line.test_data.case_op[0]),
                (uint32_t)(line.test_data.case_op[1]));

        if (line.new_insn == TRUE) {
            fprintf(fp_sample_h,
                    "struct ternary_calculation samples_%s[] = {\n",
                    line.underline_name);
            fprintf(fp_dspv2_insn_s, "\nTEST_FUNC(test_%s)\n",
                    line.underline_name);
            fprintf(fp_dspv2_insn_s, "    %s    a2, a0, a1\n",
                    line.test_data.name);
            fprintf(fp_dspv2_insn_s, "    mov    a0, a2\n");
            fprintf(fp_dspv2_insn_s, "    rts\n");
            fprintf(fp_dspv2_insn_s, "    .size   test_%s, .-test_%s\n",
                    line.underline_name, line.underline_name);
            fprintf(fp_dspv2_insn_h,
                    "int32_t test_%s(int32_t a, int32_t b, int32_t c);\n",
                    line.underline_name);
            /* case file: xxxx.c */
            strcat(file_name, line.underline_name);
            strcat(file_name, ".c");
            fp_case_c = fopen(file_name, "w");
            print_case_head();
            fprintf(fp_case_c, "    for (i = 0;\n");
            fprintf(fp_case_c,
                    "         i < sizeof(samples_%s)/sizeof(struct ternary_calculation);\n",
                    line.underline_name);
            fprintf(fp_case_c, "         i++) {\n");
            fprintf(fp_case_c,
                    "        TEST(test_%s(samples_%s[i].op1, samples_%s[i].op2, samples_%s[i].op3)\n",
                    line.underline_name, line.underline_name,
                    line.underline_name, line.underline_name);
            fprintf(fp_case_c, "                     == samples_%s[i].result);\n",
                    line.underline_name);
            fprintf(fp_case_c, "    }\n");
            fprintf(fp_case_c, "    return done_testing();\n");
            fprintf(fp_case_c, "}\n");
            fclose(fp_case_c);
            line.new_insn = FALSE;
            line.print_end = TRUE;
        }
        fprintf(fp_sample_h, "    {0x%08x, 0x%08x, 0x%08x, 0x%08x},\n",
                (uint32_t)line.test_data.case_op[0],
                (uint32_t)line.test_data.case_op[1],
                (uint32_t)line.test_data.case_op[2], ret_w);
    } else if (line.funcs_addr->op_num == 3
            && line.funcs_addr->ret_type == I64
            && line.funcs_addr->op1_type == I32
            && line.funcs_addr->op2_type == I32
            && line.funcs_addr->op3_type == I64) {
        func_dwwd = line.funcs_addr->func;
        ret_d = (*func_dwwd)((uint32_t)(line.test_data.case_op[2] & 0xffffffff),
                (uint32_t)(line.test_data.case_op[2] >> 32),
                (uint32_t)(line.test_data.case_op[0]),
                (uint32_t)(line.test_data.case_op[1]));

        if (line.new_insn == TRUE) {
            fprintf(fp_sample_h, "struct ternary64_calculation samples_%s[] = {\n",
                    line.underline_name);
            fprintf(fp_dspv2_insn_s, "\nTEST_FUNC(test_%s)\n",
                    line.underline_name);
            fprintf(fp_dspv2_insn_s, "    %s    a2, a0, a1\n",
                    line.test_data.name);
            fprintf(fp_dspv2_insn_s, "    mov    a0, a2\n");
            fprintf(fp_dspv2_insn_s, "    mov    a1, a3\n");
            fprintf(fp_dspv2_insn_s, "    rts\n");
            fprintf(fp_dspv2_insn_s, "    .size   test_%s, .-test_%s\n",
                    line.underline_name, line.underline_name);
            fprintf(fp_dspv2_insn_h,
                    "int64_t test_%s(int32_t a, int32_t b, int64_t c);\n",
                    line.underline_name);
            /* case file: xxxx.c */
            strcat(file_name, line.underline_name);
            strcat(file_name, ".c");
            fp_case_c = fopen(file_name, "w");
            print_case_head();
            fprintf(fp_case_c, "    for (i = 0;\n");
            fprintf(fp_case_c,
                    "         i < sizeof(samples_%s)/sizeof(struct ternary64_calculation);\n",
                    line.underline_name);
            fprintf(fp_case_c, "         i++) {\n");
            fprintf(fp_case_c,
                    "        TEST(test_%s(samples_%s[i].op1, samples_%s[i].op2, samples_%s[i].op3)\n",
                    line.underline_name, line.underline_name,
                    line.underline_name, line.underline_name);
            fprintf(fp_case_c, "                     == samples_%s[i].result);\n",
                    line.underline_name);
            fprintf(fp_case_c, "    }\n");
            fprintf(fp_case_c, "    return done_testing();\n");
            fprintf(fp_case_c, "}\n");
            fclose(fp_case_c);
            line.new_insn = FALSE;
            line.print_end = TRUE;
        }
        fprintf(fp_sample_h, "    {0x%08x, 0x%08x, 0x%016llx, 0x%016llx},\n",
                (uint32_t)line.test_data.case_op[0],
                (uint32_t)line.test_data.case_op[1],
                line.test_data.case_op[2], ret_d);

    }
}

/* print head for files. */
void print_head(void)
{
    /* sample_array.h */
    fprintf(fp_sample_h, "#include \"test_device.h\"\n");
    fprintf(fp_sample_h, "#ifndef SAMPLE_ARRAY_H\n");
    fprintf(fp_sample_h, "#define SAMPLE_ARRAY_H\n");

    /* dspv2_insn.S*/
    fprintf(fp_dspv2_insn_s, "   .file   \"dspv2_insn.S\"\n");
    fprintf(fp_dspv2_insn_s, "#undef TEST_FUNC\n");
    fprintf(fp_dspv2_insn_s, "#define TEST_FUNC(name) TEST_FUNC_M name\n");
    fprintf(fp_dspv2_insn_s, "    .macro TEST_FUNC_M name\n");
    fprintf(fp_dspv2_insn_s, "    .text\n");
    fprintf(fp_dspv2_insn_s, "    .align  2\n");
    fprintf(fp_dspv2_insn_s, "    .global \\name\n");
    fprintf(fp_dspv2_insn_s, "    .type   \\name, @function\n");
    fprintf(fp_dspv2_insn_s, "\\name:\n");
    fprintf(fp_dspv2_insn_s, "    .endm\n");

    /* dspv2_insn.h */
    fprintf(fp_dspv2_insn_h, "#ifndef DSPV2_INSN_H\n");
    fprintf(fp_dspv2_insn_h, "#define DSPV2_INSN_H\n");
}

void print_tail(void)
{
    /* sample_array.h  */
    if (line.print_end == TRUE){
        line.print_end = FALSE;
        fprintf(fp_sample_h, "};\n\n");
    }
    fprintf(fp_sample_h, "#endif\n");

    /* dspv2_insn.h */
    fprintf(fp_dspv2_insn_h, "#endif\n");
}

uint32_t main(void)
{
    uint32_t i;
    printf("- - - Start generate test data...\n");

    fp = fopen("insn.dat", "r");
    fp_sample_h = fopen("./case/sample_array.h", "w");
    fp_dspv2_insn_s = fopen("./case/dspv2_insn.S", "w");
    fp_dspv2_insn_h = fopen("./case/dspv2_insn.h", "w");
    if(fp == NULL) {
        printf("- - - test.dat not exist.\n");
        return;
    }
    print_head();
    line.is_find = FALSE;
    line.new_insn = FALSE;
    line.print_end = FALSE;

    while (1) {
        get_a_line();
        if (line.type == NOTE || line.type == EMPTY_LINE) {
            continue;
        } else if (line.type == INSN) {
            find_insn();
            continue;
        } else if (line.type == SAMPLE) {
            calc_case();
        } else if (line.type == IS_EOF){
            break;
        } else {
            printf("Error: can not know this: %s", line.str);
        }
    }
    print_tail();
    fclose(fp);
    fclose(fp_sample_h);
    fclose(fp_dspv2_insn_s);
    fclose(fp_dspv2_insn_h);
    printf("- - - generate successly.\n");
    return 0;
}


