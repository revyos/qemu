/*
 * RISC-V translation routines for the T-Head Extend Instruction Set.
 *
 * Copyright (c) 2020 T-Head Limited, ltd
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2 or later, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define GET_GPR_DS_R(EXT_MODE)             \
    TCGv src1, src2, src3, dst;            \
    src1 = get_gpr(ctx, a->rs1, EXT_MODE); \
    src2 = get_gpr(ctx, a->rs2, EXT_MODE); \
    src3 = get_gpr(ctx, a->rd, EXT_MODE);  \
    dst = dest_gpr(ctx, a->rd);

#define GET_GPR_R(EXT_MODE)                \
    TCGv src1, src2, dst;                  \
    src1 = get_gpr(ctx, a->rs1, EXT_MODE); \
    src2 = get_gpr(ctx, a->rs2, EXT_MODE); \
    dst = dest_gpr(ctx, a->rd);

#define GET_GPR_R2(EXT_MODE)               \
    TCGv src1, dst;                        \
    src1 = get_gpr(ctx, a->rs1, EXT_MODE); \
    dst = dest_gpr(ctx, a->rd);

static bool trans_addsl(DisasContext *ctx, arg_addsl *a)
{
    TCGv t2 = temp_new(ctx);
    GET_GPR_R(EXT_ZERO);

    tcg_gen_shli_tl(t2, src2, a->imm2);
    tcg_gen_add_tl(dst, src1, t2);
    gen_set_gpr(ctx, a->rd, dst);
    return true;
}

static bool trans_srri(DisasContext *ctx, arg_srri *a)
{
    TCGv imm = tcg_constant_tl(a->imm6);
    GET_GPR_R2(EXT_ZERO);
    gen_helper_srri(dst, src1, imm, tcg_constant_tl(ctx->xl));
    gen_set_gpr(ctx, a->rd, dst);
    return true;
}

static bool trans_tstnbz(DisasContext *ctx, arg_tstnbz *a)
{
    GET_GPR_R2(EXT_ZERO);
    gen_helper_tstnbz(dst, src1, tcg_constant_tl(ctx->xl));
    gen_set_gpr(ctx, a->rd, dst);
    return true;
}

static bool trans_rev(DisasContext *ctx, arg_rev *a)
{
    GET_GPR_R2(EXT_ZERO);
    if (ctx->xl == MXL_RV32) {
        tcg_gen_bswap32_tl(dst, src1, TCG_BSWAP_OS);
    } else {
        tcg_gen_bswap_tl(dst, src1);
    }
    gen_set_gpr(ctx, a->rd, dst);
    return true;
}

static bool trans_ff0(DisasContext *ctx, arg_ff0 *a)
{
    GET_GPR_R2(EXT_ZERO);
    gen_helper_ff0(dst, src1, tcg_constant_tl(ctx->xl));
    gen_set_gpr(ctx, a->rd, dst);
    return true;
}

static bool trans_ff1(DisasContext *ctx, arg_ff1 *a)
{
    GET_GPR_R2(EXT_ZERO);
    gen_helper_ff1(dst, src1, tcg_constant_tl(ctx->xl));
    gen_set_gpr(ctx, a->rd, dst);
    return true;
}

static bool trans_tst(DisasContext *ctx, arg_tst *a)
{
    TCGv imm = tcg_constant_tl(a->imm6);
    GET_GPR_R2(EXT_NONE);
    gen_helper_tst(dst, src1, imm);
    gen_set_gpr(ctx, a->rd, dst);
    return true;
}

static bool trans_mveqz(DisasContext *ctx, arg_mveqz *a)
{
    GET_GPR_DS_R(EXT_NONE);
    tcg_gen_movcond_tl(TCG_COND_EQ, dst, src2, ctx->zero, src1, src3);
    gen_set_gpr(ctx, a->rd, dst);
    return true;
}

static bool trans_mvnez(DisasContext *ctx, arg_mvnez *a)
{
    GET_GPR_DS_R(EXT_NONE);
    tcg_gen_movcond_tl(TCG_COND_NE, dst, src2, ctx->zero, src1, src3);
    gen_set_gpr(ctx, a->rd, dst);
    return true;
}

static bool gen_mulx_tl(DisasContext *ctx, arg_r *a,
                        void (*func)(TCGv, TCGv, TCGv))
{
    TCGv t1, t2, d1;
    GET_GPR_R(EXT_NONE);
    d1 = get_gpr(ctx, a->rd, EXT_NONE);
    t1 = tcg_temp_new();
    t2 = tcg_temp_new();

    tcg_gen_mulu2_tl(t1, t2, src1, src2);
    func(dst, d1, t1);
    gen_set_gpr(ctx, a->rd, dst);
    tcg_temp_free(t1);
    tcg_temp_free(t2);
    return true;
}

static bool trans_mula(DisasContext *ctx, arg_mula *a)
{
    return gen_mulx_tl(ctx, a, tcg_gen_add_tl);
}

static bool trans_muls(DisasContext *ctx, arg_muls *a)
{
    return gen_mulx_tl(ctx, a, tcg_gen_sub_tl);
}

static bool trans_mulah(DisasContext *ctx, arg_mulah *a)
{
    TCGv d1;
    GET_GPR_R(EXT_NONE);
    d1 = get_gpr(ctx, a->rd, EXT_NONE);
    gen_helper_mulah(dst, src1, src2, d1);
    gen_set_gpr(ctx, a->rd, dst);
    return true;
}

static bool trans_mulsh(DisasContext *ctx, arg_mulsh *a)
{
    TCGv d1;
    GET_GPR_R(EXT_NONE);
    d1 = get_gpr(ctx, a->rd, EXT_NONE);
    gen_helper_mulsh(dst, src1, src2, d1);
    gen_set_gpr(ctx, a->rd, dst);
    return true;
}

static bool trans_ext(DisasContext *ctx, arg_ext *a)
{
    GET_GPR_R2(EXT_NONE);
    if (a->msb < a->lsb) {
        tcg_gen_movi_tl(dst, 0);
    } else {
        tcg_gen_sextract_tl(dst, src1, a->lsb, a->msb - a->lsb + 1);
    }
    gen_set_gpr(ctx, a->rd, dst);
    return true;
}

static bool trans_extu(DisasContext *ctx, arg_extu *a)
{
    GET_GPR_R2(EXT_NONE);
    if (a->msb < a->lsb) {
        tcg_gen_movi_tl(dst, 0);
    } else {
        tcg_gen_extract_tl(dst, src1, a->lsb, a->msb - a->lsb + 1);
    }
    gen_set_gpr(ctx, a->rd, dst);
    return true;
}

static bool gen_lrx(DisasContext *ctx, arg_r_imm2 *a, MemOp memop)
{
    TCGv t1, t2;
    t1 = tcg_temp_new();
    t2 = tcg_temp_new();
    GET_GPR_R(EXT_ZERO);

    tcg_gen_shli_tl(t2, src2, a->imm2);
    tcg_gen_add_tl(t1, src1, t2);
    if (ctx->xl == MXL_RV32) {
        tcg_gen_andi_tl(t1, t1, UINT32_MAX);
    }
    tcg_gen_qemu_ld_tl(dst, t1, ctx->mem_idx, memop);
    if (a->rd) {
        gen_load_internal(ctx, memop, dst, t1);
    }
    gen_set_gpr(ctx, a->rd, dst);
    tcg_temp_free(t1);
    tcg_temp_free(t2);
    return true;
}

static bool trans_lrb(DisasContext *ctx, arg_lrb *a)
{
    return gen_lrx(ctx, a, MO_SB);
}

static bool trans_lrh(DisasContext *ctx, arg_lrh *a)
{
    return gen_lrx(ctx, a, MO_TESW);
}

static bool trans_lrw(DisasContext *ctx, arg_lrw *a)
{
    return gen_lrx(ctx, a, MO_TESL);
}

static bool trans_lrbu(DisasContext *ctx, arg_lrbu *a)
{
    return gen_lrx(ctx, a, MO_UB);
}

static bool trans_lrhu(DisasContext *ctx, arg_lrhu *a)
{
    return gen_lrx(ctx, a, MO_TEUW);
}

static inline target_long sign_ext(int imm, int len)
{
    target_long temp = imm;
    int width = sizeof(target_long) * 8 - len;

    return (temp << width) >> width;
}

static bool gen_lxib(DisasContext *ctx, arg_r2_imm2_5 *a, MemOp memop)
{
    TCGv t1 = temp_new(ctx);
    GET_GPR_R2(EXT_ZERO);

    tcg_gen_addi_tl(t1, src1, sign_ext(a->imm5, 5) << a->imm2);
    if (ctx->xl == MXL_RV32) {
        tcg_gen_andi_tl(t1, t1, UINT32_MAX);
    }
    tcg_gen_qemu_ld_tl(dst, t1, ctx->mem_idx, memop);
    if (a->rd) {
        gen_load_internal(ctx, memop, dst, t1);
    }
    gen_set_gpr(ctx, a->rd, dst);
    gen_set_gpr(ctx, a->rs1, t1);
    return true;
}

static bool trans_lbib(DisasContext *ctx, arg_lbib *a)
{
    return gen_lxib(ctx, a, MO_SB);
}

static bool trans_lhib(DisasContext *ctx, arg_lhib *a)
{
    return gen_lxib(ctx, a, MO_TESW);
}

static bool trans_lwib(DisasContext *ctx, arg_lwib *a)
{
    return gen_lxib(ctx, a, MO_TESL);
}

static bool trans_lbuib(DisasContext *ctx, arg_lbuib *a)
{
    return gen_lxib(ctx, a, MO_UB);
}

static bool trans_lhuib(DisasContext *ctx, arg_lhuib *a)
{
    return gen_lxib(ctx, a, MO_TEUW);
}

static bool gen_lxia(DisasContext *ctx, arg_r2_imm2_5 *a, MemOp memop)
{
    TCGv t1 = temp_new(ctx);
    GET_GPR_R2(EXT_ZERO);

    tcg_gen_qemu_ld_tl(dst, src1, ctx->mem_idx, memop);
    if (a->rd) {
        gen_load_internal(ctx, memop, dst, src1);
    }
    tcg_gen_addi_tl(t1, src1, sign_ext(a->imm5, 5) << a->imm2);
    if (ctx->xl == MXL_RV32) {
        tcg_gen_andi_tl(t1, t1, UINT32_MAX);
    }
    gen_set_gpr(ctx, a->rd, dst);
    gen_set_gpr(ctx, a->rs1, t1);
    return true;
}

static bool trans_lbia(DisasContext *ctx, arg_lbia *a)
{
    return gen_lxia(ctx, a, MO_SB);
}

static bool trans_lhia(DisasContext *ctx, arg_lhia *a)
{
    return gen_lxia(ctx, a, MO_TESW);
}

static bool trans_lwia(DisasContext *ctx, arg_lwia *a)
{
    return gen_lxia(ctx, a, MO_TESL);
}

static bool trans_lbuia(DisasContext *ctx, arg_lbuia *a)
{
    return gen_lxia(ctx, a, MO_UB);
}

static bool trans_lhuia(DisasContext *ctx, arg_lhuia *a)
{
    return gen_lxia(ctx, a, MO_TEUW);
}

static bool trans_lwd(DisasContext *ctx, arg_lwd *a)
{
    uint8_t offset = a->imm2 << 3;
    TCGv t1, src1, dst1, dst2;
    src1 = get_gpr(ctx, a->rs1, EXT_ZERO);
    dst1 = dest_gpr(ctx, a->rd1);
    dst2 = dest_gpr(ctx, a->rd2);
    t1 = temp_new(ctx);

    tcg_gen_addi_tl(t1, src1, offset);
    if (ctx->xl == MXL_RV32) {
        tcg_gen_andi_tl(t1, t1, UINT32_MAX);
    }
    tcg_gen_qemu_ld_tl(dst1, t1, ctx->mem_idx, MO_TESL);
    if (a->rd1) {
        gen_load_internal(ctx, MO_TESL, dst1, t1);
    }
    tcg_gen_addi_tl(t1, t1, 4);
    if (ctx->xl == MXL_RV32) {
        tcg_gen_andi_tl(t1, t1, UINT32_MAX);
    }
    tcg_gen_qemu_ld_tl(dst2, t1, ctx->mem_idx, MO_TESL);
    if (a->rd2) {
        gen_load_internal(ctx, MO_TESL, dst2, t1);
    }
    gen_set_gpr(ctx, a->rd1, dst1);
    gen_set_gpr(ctx, a->rd2, dst2);
    return true;
}

static bool gen_srx(DisasContext *ctx, arg_srb *a, MemOp memop)
{
    TCGv src1, src2, t1, t2, d1;
    d1 = get_gpr(ctx, a->rd, EXT_ZERO);
    src1 = get_gpr(ctx, a->rs1, EXT_ZERO);
    src2 = get_gpr(ctx, a->rs2, EXT_ZERO);
    t1 = tcg_temp_new();
    t2 = tcg_temp_new();

    tcg_gen_shli_tl(t2, src2, a->imm2);
    tcg_gen_add_tl(t1, src1, t2);
    if (ctx->xl == MXL_RV32) {
        tcg_gen_andi_tl(t1, t1, UINT32_MAX);
    }
    tcg_gen_qemu_st_tl(d1, t1, ctx->mem_idx, memop);
    gen_store_internal(ctx, memop, d1, t1);
    tcg_temp_free(t1);
    tcg_temp_free(t2);
    return true;
}

static bool trans_srb(DisasContext *ctx, arg_srb *a)
{
    return gen_srx(ctx, a, MO_SB);
}

static bool trans_srh(DisasContext *ctx, arg_srh *a)
{
    return gen_srx(ctx, a, MO_TESW);
}

static bool trans_srw(DisasContext *ctx, arg_srw *a)
{
    return gen_srx(ctx, a, MO_TESL);
}

static bool gen_sxia(DisasContext *ctx, arg_sbia *a, MemOp memop)
{
    TCGv t1, d1, src1;
    t1 = temp_new(ctx);
    src1 = get_gpr(ctx, a->rs1, EXT_ZERO);
    d1 = get_gpr(ctx, a->rd, EXT_ZERO);

    tcg_gen_qemu_st_tl(d1, src1, ctx->mem_idx, memop);
    gen_store_internal(ctx, memop, d1, src1);
    tcg_gen_addi_tl(t1, src1, sign_ext(a->imm5, 5) << a->imm2);
    if (ctx->xl == MXL_RV32) {
        tcg_gen_andi_tl(t1, t1, UINT32_MAX);
    }
    gen_set_gpr(ctx, a->rs1, t1);
    return true;
}

static bool trans_sbia(DisasContext *ctx, arg_sbia *a)
{
    return gen_sxia(ctx, a, MO_SB);
}

static bool trans_shia(DisasContext *ctx, arg_shia *a)
{
    return gen_sxia(ctx, a, MO_TESW);
}

static bool trans_swia(DisasContext *ctx, arg_swia *a)
{
    return gen_sxia(ctx, a, MO_TESL);
}

static bool gen_sxib(DisasContext *ctx, arg_sbib *a, MemOp memop)
{
    TCGv t1, src1, d1;
    t1 = temp_new(ctx);
    src1 = get_gpr(ctx, a->rs1, EXT_ZERO);
    d1 = get_gpr(ctx, a->rd, EXT_ZERO);

    tcg_gen_addi_tl(t1, src1, sign_ext(a->imm5, 5) << a->imm2);
    if (ctx->xl == MXL_RV32) {
        tcg_gen_andi_tl(t1, t1, UINT32_MAX);
    }
    tcg_gen_qemu_st_tl(d1, t1, ctx->mem_idx, memop);
    gen_store_internal(ctx, memop, d1, t1);
    gen_set_gpr(ctx, a->rs1, t1);
    return true;
}

static bool trans_sbib(DisasContext *ctx, arg_sbib *a)
{
    return gen_sxib(ctx, a, MO_SB);
}

static bool trans_shib(DisasContext *ctx, arg_shib *a)
{
    return gen_sxib(ctx, a, MO_TESW);
}

static bool trans_swib(DisasContext *ctx, arg_swib *a)
{
    return gen_sxib(ctx, a, MO_TESL);
}

static bool trans_swd(DisasContext *ctx, arg_swd *a)
{
    uint8_t offset = a->imm2 << 3;
    TCGv t1, src1, d1, d2;
    t1 = temp_new(ctx);
    src1 = get_gpr(ctx, a->rs1, EXT_ZERO);
    d1 = get_gpr(ctx, a->rd1, EXT_NONE);
    d2 = get_gpr(ctx, a->rd2, EXT_NONE);

    tcg_gen_addi_tl(t1, src1, offset);
    if (ctx->xl == MXL_RV32) {
        tcg_gen_andi_tl(t1, t1, UINT32_MAX);
    }
    tcg_gen_qemu_st_tl(d1, t1, ctx->mem_idx, MO_TESL);
    gen_store_internal(ctx, MO_TESL, d1, t1);
    tcg_gen_addi_tl(t1, t1, 4);
    if (ctx->xl == MXL_RV32) {
        tcg_gen_andi_tl(t1, t1, UINT32_MAX);
    }
    tcg_gen_qemu_st_tl(d2, t1, ctx->mem_idx, MO_TESL);
    gen_store_internal(ctx, MO_TESL, d2, t1);
    return true;
}

static void gen_flrx(DisasContext *ctx, arg_r_imm2 *a, MemOp memop)
{
    TCGv t1, t2, src1, src2, data;
    if (ctx->mstatus_fs == 0) {
        gen_exception_illegal(ctx);
    }
    t1 = tcg_temp_new();
    t2 = tcg_temp_new();
    src1 = get_gpr(ctx, a->rs1, EXT_ZERO);
    src2 = get_gpr(ctx, a->rs2, EXT_ZERO);
    data = temp_new(ctx);

    tcg_gen_shli_tl(t2, src2, a->imm2);
    tcg_gen_add_tl(t1, src1, t2);
    if (ctx->xl == MXL_RV32) {
        tcg_gen_andi_tl(t1, t1, UINT32_MAX);
    }
    tcg_gen_qemu_ld_i64(cpu_fpr[a->rd], t1, ctx->mem_idx, memop);
    tcg_gen_trunc_i64_tl(data, cpu_fpr[a->rd]);
    gen_load_internal(ctx, memop, data, t1);
    tcg_temp_free(t1);
    tcg_temp_free(t2);
}

static bool trans_flrw(DisasContext *ctx, arg_flrw *a)
{
    gen_flrx(ctx, a, MO_TEUL);
    gen_nanbox_s(cpu_fpr[a->rd], cpu_fpr[a->rd]);
    mark_fs_dirty(ctx);
    return true;
}

static bool trans_flrd(DisasContext *ctx, arg_flrd *a)
{
    gen_flrx(ctx, a, MO_TEQ);
    mark_fs_dirty(ctx);
    return true;
}

static bool gen_fsrx(DisasContext *ctx, arg_r_imm2 *a, MemOp memop)
{
    TCGv t1, t2, src1, src2, data;
    if (ctx->mstatus_fs == 0) {
        gen_exception_illegal(ctx);
    }
    t1 = tcg_temp_new();
    t2 = tcg_temp_new();
    src1 = get_gpr(ctx, a->rs1, EXT_ZERO);
    src2 = get_gpr(ctx, a->rs2, EXT_ZERO);
    data = temp_new(ctx);

    tcg_gen_shli_tl(t2, src2, a->imm2);
    tcg_gen_add_tl(t1, src1, t2);
    if (ctx->xl == MXL_RV32) {
        tcg_gen_andi_tl(t1, t1, UINT32_MAX);
    }
    tcg_gen_qemu_st_i64(cpu_fpr[a->rd], t1, ctx->mem_idx, memop);
    tcg_gen_trunc_i64_tl(data, cpu_fpr[a->rd]);
    gen_store_internal(ctx, memop, data, t1);
    tcg_temp_free(t1);
    tcg_temp_free(t2);
    return true;
}

static bool trans_fsrw(DisasContext *ctx, arg_fsrw *a)
{
    return gen_fsrx(ctx, a, MO_TEUL);
}

static bool trans_fsrd(DisasContext *ctx, arg_fsrd *a)
{
    return gen_fsrx(ctx, a, MO_TEQ);
}

static bool trans_ignore(DisasContext *ctx, arg_ignore *a)
{
    tcg_gen_movi_tl(cpu_pc, ctx->pc_succ_insn);
    exit_tb(ctx);
    ctx->base.is_jmp = DISAS_NORETURN;
    return true;
}

static bool trans_srriw(DisasContext *ctx, arg_srriw *a)
{
    REQUIRE_64BIT(ctx);
    GET_GPR_R2(EXT_NONE);
    gen_helper_srriw(dst, src1, tcg_constant_tl(a->imm5));
    gen_set_gpr(ctx, a->rd, dst);
    return true;
}

static bool trans_revw(DisasContext *ctx, arg_revw *a)
{
    REQUIRE_64BIT(ctx);
    GET_GPR_R2(EXT_NONE);
    tcg_gen_bswap32_tl(dst, src1, TCG_BSWAP_OS);
    gen_set_gpr(ctx, a->rd, dst);
    return true;
}

static bool trans_mulaw(DisasContext *ctx, arg_mulaw *a)
{
    REQUIRE_64BIT(ctx);
    ctx->ol = MXL_RV32;
    return gen_mulx_tl(ctx, a, tcg_gen_add_tl);
}

static bool trans_mulsw(DisasContext *ctx, arg_mulsw *a)
{
    REQUIRE_64BIT(ctx);
    ctx->ol = MXL_RV32;
    return gen_mulx_tl(ctx, a, tcg_gen_sub_tl);
}

static bool gen_lr64(DisasContext *ctx, arg_r_imm2 *a, MemOp memop)
{
    TCGv t1, t2;
    t1 = tcg_temp_new();
    t2 = tcg_temp_new();
    GET_GPR_R(EXT_NONE);

    tcg_gen_shli_tl(t2, src2, a->imm2);
    tcg_gen_add_tl(t1, src1, t2);
    tcg_gen_qemu_ld_tl(dst, t1, ctx->mem_idx, memop);
    if (a->rd) {
        gen_load_internal(ctx, memop, dst, t1);
    }
    gen_set_gpr(ctx, a->rd, dst);
    tcg_temp_free(t1);
    tcg_temp_free(t2);
    return true;
}

static bool trans_lrd(DisasContext *ctx , arg_lrd *a)
{
    REQUIRE_64BIT(ctx);
    return gen_lr64(ctx, a, MO_TEQ);
}

static bool trans_lrwu(DisasContext *ctx, arg_lrwu *a)
{
    REQUIRE_64BIT(ctx);
    return gen_lr64(ctx, a, MO_TEUL);
}

static bool gen_lurx(DisasContext *ctx, arg_r_imm2 *a, MemOp memop)
{
    TCGv t1, t2;
    t1 = tcg_temp_new();
    t2 = tcg_temp_new();
    GET_GPR_R(EXT_NONE);

    tcg_gen_ext32u_tl(t2, src2);
    tcg_gen_shli_tl(t2, t2, a->imm2);
    tcg_gen_add_tl(t1, src1, t2);
    tcg_gen_qemu_ld_tl(dst, t1, ctx->mem_idx, memop);
    if (a->rd) {
        gen_load_internal(ctx, memop, dst, t1);
    }
    gen_set_gpr(ctx, a->rd, dst);
    tcg_temp_free(t1);
    tcg_temp_free(t2);
    return true;
}

static bool trans_lurb(DisasContext *ctx, arg_lurb *a)
{
    REQUIRE_64BIT(ctx);
    return gen_lurx(ctx, a, MO_SB);
}

static bool trans_lurh(DisasContext *ctx, arg_lurh *a)
{
    REQUIRE_64BIT(ctx);
    return gen_lurx(ctx, a, MO_TESW);
}

static bool trans_lurw(DisasContext *ctx, arg_lurw *a)
{
    REQUIRE_64BIT(ctx);
    return gen_lurx(ctx, a, MO_TESL);
}

static bool trans_lurd(DisasContext *ctx, arg_lurd *a)
{
    REQUIRE_64BIT(ctx);
    return gen_lurx(ctx, a, MO_TEQ);
}

static bool trans_lurbu(DisasContext *ctx, arg_lurbu *a)
{
    REQUIRE_64BIT(ctx);
    return gen_lurx(ctx, a, MO_UB);
}

static bool trans_lurhu(DisasContext *ctx, arg_lurhu *a)
{
    REQUIRE_64BIT(ctx);
    return gen_lurx(ctx, a, MO_TEUW);
}

static bool trans_lurwu(DisasContext *ctx, arg_lurwu *a)
{
    REQUIRE_64BIT(ctx);
    return gen_lurx(ctx, a, MO_TEUL);
}

static bool gen_lxia64(DisasContext *ctx, arg_r2_imm2_5 *a, MemOp memop)
{
    TCGv t1 = temp_new(ctx);
    GET_GPR_R2(EXT_NONE);

    tcg_gen_qemu_ld_tl(dst, src1, ctx->mem_idx, memop);
    gen_set_gpr(ctx, a->rd, dst);
    if (a->rd) {
        gen_load_internal(ctx, memop, dst, src1);
    }
    tcg_gen_addi_tl(t1, src1, sign_ext(a->imm5, 5) << a->imm2);
    gen_set_gpr(ctx, a->rs1, t1);
    return true;
}

static bool trans_ldia(DisasContext *ctx, arg_ldia *a)
{
    REQUIRE_64BIT(ctx);
    return gen_lxia64(ctx, a, MO_TEQ);
}

static bool gen_lxib64(DisasContext *ctx, arg_r2_imm2_5 *a, MemOp memop)
{
    TCGv t1 = temp_new(ctx);
    GET_GPR_R2(EXT_NONE);

    tcg_gen_addi_tl(t1, src1, sign_ext(a->imm5, 5) << a->imm2);
    tcg_gen_qemu_ld_tl(dst, t1, ctx->mem_idx, memop);
    gen_set_gpr(ctx, a->rd, dst);
    if (a->rd) {
        gen_load_internal(ctx, memop, dst, t1);
    }
    gen_set_gpr(ctx, a->rs1, t1);
    return true;
}

static bool trans_ldib(DisasContext *ctx, arg_ldib *a)
{
    REQUIRE_64BIT(ctx);
    return gen_lxib64(ctx, a, MO_TEQ);
}

static bool trans_lwuia(DisasContext *ctx, arg_lwuia *a)
{
    REQUIRE_64BIT(ctx);
    return gen_lxia64(ctx, a, MO_TEUL);
}

static bool trans_lwuib(DisasContext *ctx, arg_lwuib *a)
{
    REQUIRE_64BIT(ctx);
    return gen_lxib64(ctx, a, MO_TEUL);
}

static bool gen_lxd64(DisasContext *ctx, arg_rd_imm2 *a, MemOp memop,
                      uint8_t offset)
{
    TCGv t1, src1, dst1, dst2;
    src1 = get_gpr(ctx, a->rs1, EXT_NONE);
    dst1 = dest_gpr(ctx, a->rd1);
    dst2 = dest_gpr(ctx, a->rd2);
    t1 = temp_new(ctx);
    tcg_gen_addi_tl(t1, src1, offset);
    tcg_gen_qemu_ld_tl(dst1, t1, ctx->mem_idx, memop);
    gen_set_gpr(ctx, a->rd1, dst1);
    if (a->rd1) {
        gen_load_internal(ctx, memop, dst1, t1);
    }
    tcg_gen_addi_tl(t1, t1, memop == MO_TEUL ? 4 : 8);
    tcg_gen_qemu_ld_tl(dst2, t1, ctx->mem_idx, memop);
    gen_set_gpr(ctx, a->rd2, dst2);
    if (a->rd2) {
        gen_load_internal(ctx, memop, dst2, t1);
    }
    return true;
}

static bool trans_lwud(DisasContext *ctx, arg_lwud *a)
{
    REQUIRE_64BIT(ctx);
    return gen_lxd64(ctx, a, MO_TEUL, a->imm2 << 3);
}

static bool trans_ldd(DisasContext *ctx, arg_ldd *a)
{
    REQUIRE_64BIT(ctx);
    return gen_lxd64(ctx, a, MO_TEQ, a->imm2 << 4);
}

static bool trans_srd(DisasContext *ctx, arg_srd *a)
{
    REQUIRE_64BIT(ctx);
    TCGv t1, t2, src1, src2, d1;
    int memop = MO_TEQ;
    src1 = get_gpr(ctx, a->rs1, EXT_NONE);
    src2 = get_gpr(ctx, a->rs2, EXT_NONE);
    d1 = get_gpr(ctx, a->rd, EXT_NONE);
    t1 = tcg_temp_new();
    t2 = tcg_temp_new();
    tcg_gen_shli_tl(t2, src2, a->imm2);
    tcg_gen_add_tl(t1, src1, t2);
    tcg_gen_qemu_st_tl(d1, t1, ctx->mem_idx, memop);
    gen_store_internal(ctx, memop, d1, t1);
    tcg_temp_free(t1);
    tcg_temp_free(t2);
    return true;
}

static bool gen_surx64(DisasContext *ctx, arg_r_imm2 *a, MemOp memop)
{
    REQUIRE_64BIT(ctx);
    TCGv t1, t2, src1, src2, d1;
    src1 = get_gpr(ctx, a->rs1, EXT_NONE);
    src2 = get_gpr(ctx, a->rs2, EXT_NONE);
    d1 = get_gpr(ctx, a->rd, EXT_NONE);
    t1 = tcg_temp_new();
    t2 = tcg_temp_new();

    tcg_gen_ext32u_tl(t2, src2);
    tcg_gen_shli_tl(t2, t2, a->imm2);
    tcg_gen_add_tl(t1, src1, t2);
    tcg_gen_qemu_st_tl(d1, t1, ctx->mem_idx, memop);
    gen_store_internal(ctx, memop, d1, t1);
    tcg_temp_free(t1);
    tcg_temp_free(t2);
    return true;
}

static bool trans_surb(DisasContext *ctx, arg_surb *a)
{
    REQUIRE_64BIT(ctx);
    return gen_surx64(ctx, a, MO_SB);
}

static bool trans_surh(DisasContext *ctx, arg_surh *a)
{
    REQUIRE_64BIT(ctx);
    return gen_surx64(ctx, a, MO_TESW);
}

static bool trans_surw(DisasContext *ctx, arg_surw *a)
{
    REQUIRE_64BIT(ctx);
    return gen_surx64(ctx, a, MO_TESL);
}

static bool trans_surd(DisasContext *ctx, arg_surd *a)
{
    REQUIRE_64BIT(ctx);
    return gen_surx64(ctx, a, MO_TEQ);
}

static bool trans_sdia(DisasContext *ctx, arg_sdia *a)
{
    REQUIRE_64BIT(ctx);
    int memop = MO_TEQ;
    TCGv t1, src1, d1;
    t1 = temp_new(ctx);
    d1 = get_gpr(ctx, a->rd, EXT_NONE);
    src1 = get_gpr(ctx, a->rs1, EXT_NONE);

    tcg_gen_qemu_st_tl(d1, src1, ctx->mem_idx, memop);
    gen_store_internal(ctx, memop, d1, src1);
    tcg_gen_addi_tl(t1, src1, sign_ext(a->imm5, 5) << a->imm2);
    gen_set_gpr(ctx, a->rs1, t1);
    return true;
}

static bool trans_sdib(DisasContext *ctx, arg_sdib *a)
{
    REQUIRE_64BIT(ctx);
    int memop = MO_TEQ;
    TCGv t1, src1, d1;
    t1 = temp_new(ctx);
    d1 = get_gpr(ctx, a->rd, EXT_NONE);
    src1 = get_gpr(ctx, a->rs1, EXT_NONE);

    tcg_gen_addi_tl(t1, src1, sign_ext(a->imm5, 5) << a->imm2);
    tcg_gen_qemu_st_tl(d1, t1, ctx->mem_idx, memop);
    gen_store_internal(ctx, memop, d1, t1);
    gen_set_gpr(ctx, a->rs1, t1);
    return true;
}

static bool trans_sdd(DisasContext *ctx, arg_sdd *a)
{
    REQUIRE_64BIT(ctx);
    uint8_t offset = a->imm2 << 4;
    TCGv t1, src1, d1, d2;
    src1 = get_gpr(ctx, a->rs1, EXT_NONE);
    d1 = get_gpr(ctx, a->rd1, EXT_NONE);
    d2 = get_gpr(ctx, a->rd2, EXT_NONE);
    t1 = temp_new(ctx);

    tcg_gen_addi_tl(t1, src1, offset);
    tcg_gen_qemu_st_tl(d1, t1, ctx->mem_idx, MO_TEQ);
    gen_store_internal(ctx, MO_TEQ, d1, t1);
    tcg_gen_addi_tl(t1, t1, 8);
    tcg_gen_qemu_st_tl(d2, t1, ctx->mem_idx, MO_TEQ);
    gen_store_internal(ctx, MO_TEQ, d2, t1);
    return true;
}

static void gen_flurx(DisasContext *ctx, arg_r_imm2 *a, MemOp memop)
{
    TCGv t1, t2, src1, src2, data;
    if (ctx->mstatus_fs == 0) {
        gen_exception_illegal(ctx);
    }
    src1 = get_gpr(ctx, a->rs1, EXT_NONE);
    src2 = get_gpr(ctx, a->rs2, EXT_NONE);
    t1 = temp_new(ctx);
    t2 = temp_new(ctx);
    data = tcg_temp_new();

    tcg_gen_ext32u_tl(t2, src2);
    tcg_gen_shli_tl(t2, t2, a->imm2);
    tcg_gen_add_tl(t1, src1, t2);
    tcg_gen_qemu_ld_i64(cpu_fpr[a->rd], t1, ctx->mem_idx, memop);
    tcg_gen_trunc_i64_tl(data, cpu_fpr[a->rd]);
    gen_load_internal(ctx, memop, data, t1);

    tcg_temp_free(data);
}

static bool trans_flurw(DisasContext *ctx, arg_flurw *a)
{
    REQUIRE_64BIT(ctx);
    gen_flurx(ctx, a, MO_TEUL);
    gen_nanbox_s(cpu_fpr[a->rd], cpu_fpr[a->rd]);
    mark_fs_dirty(ctx);
    return true;
}

static bool trans_flurd(DisasContext *ctx, arg_flurd *a)
{
    REQUIRE_64BIT(ctx);
    gen_flurx(ctx, a, MO_TEQ);
    mark_fs_dirty(ctx);
    return true;
}

static bool gen_fsurx(DisasContext *ctx, arg_r_imm2 *a, MemOp memop)
{
    TCGv t1, t2, src1, src2, data;
    if (ctx->mstatus_fs == 0) {
        gen_exception_illegal(ctx);
    }
    src1 = get_gpr(ctx, a->rs1, EXT_NONE);
    src2 = get_gpr(ctx, a->rs2, EXT_NONE);
    t1 = temp_new(ctx);
    t2 = temp_new(ctx);
    data = tcg_temp_new();

    tcg_gen_ext32u_tl(t2, src2);
    tcg_gen_shli_tl(t2, t2, a->imm2);
    tcg_gen_add_tl(t1, src1, t2);
    tcg_gen_qemu_st_i64(cpu_fpr[a->rd], t1, ctx->mem_idx, memop);
    tcg_gen_trunc_i64_tl(data, cpu_fpr[a->rd]);
    gen_store_internal(ctx, memop, data, t1);

    tcg_temp_free(data);
    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fsurw(DisasContext *ctx, arg_fsurw *a)
{
    REQUIRE_64BIT(ctx);
    return gen_fsurx(ctx, a, MO_TEUL);
}

static bool trans_fsurd(DisasContext *ctx, arg_fsurd *a)
{
    REQUIRE_64BIT(ctx);
    return gen_fsurx(ctx, a, MO_TEQ);
}

static bool trans_flh(DisasContext *ctx, arg_flh *a)
{
    REQUIRE_FPU;
    TCGv t1, data;

    data = temp_new(ctx);
    t1 = get_address(ctx, a->rs1, a->imm);

    tcg_gen_qemu_ld_i64(cpu_fpr[a->rd], t1, ctx->mem_idx, MO_TEUW);
    gen_nanbox_h(cpu_fpr[a->rd], cpu_fpr[a->rd]);
    tcg_gen_trunc_i64_tl(data, cpu_fpr[a->rd]);
    gen_load_internal(ctx, MO_TEUW, data, t1);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fsh(DisasContext *ctx, arg_fsh *a)
{
    REQUIRE_FPU;

    TCGv t1, data;
    data = temp_new(ctx);

    t1 = get_address(ctx, a->rs1, a->imm);
    tcg_gen_qemu_st_i64(cpu_fpr[a->rs2], t1, ctx->mem_idx, MO_TEUW);
    tcg_gen_trunc_i64_tl(data, cpu_fpr[a->rs2]);
    gen_store_internal(ctx, MO_TEUW, data, t1);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fmadd_h(DisasContext *ctx, arg_fmadd_h *a)
{
    REQUIRE_FPU;

    gen_set_rm(ctx, a->rm);
    gen_helper_fmadd_h(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1],
                       cpu_fpr[a->rs2], cpu_fpr[a->rs3]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fmsub_h(DisasContext *ctx, arg_fmsub_h *a)
{
    REQUIRE_FPU;

    gen_set_rm(ctx, a->rm);
    gen_helper_fmsub_h(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1],
                       cpu_fpr[a->rs2], cpu_fpr[a->rs3]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fnmsub_h(DisasContext *ctx, arg_fnmsub_h *a)
{
    REQUIRE_FPU;

    gen_set_rm(ctx, a->rm);
    gen_helper_fnmsub_h(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1],
                        cpu_fpr[a->rs2], cpu_fpr[a->rs3]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fnmadd_h(DisasContext *ctx, arg_fnmadd_h *a)
{
    REQUIRE_FPU;

    gen_set_rm(ctx, a->rm);
    gen_helper_fnmadd_h(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1],
                        cpu_fpr[a->rs2], cpu_fpr[a->rs3]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fadd_h(DisasContext *ctx, arg_fadd_h *a)
{
    REQUIRE_FPU;

    gen_set_rm(ctx, a->rm);
    gen_helper_fadd_h(cpu_fpr[a->rd], cpu_env,
                      cpu_fpr[a->rs1], cpu_fpr[a->rs2]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fsub_h(DisasContext *ctx, arg_fsub_h *a)
{
    REQUIRE_FPU;

    gen_set_rm(ctx, a->rm);
    gen_helper_fsub_h(cpu_fpr[a->rd], cpu_env,
                      cpu_fpr[a->rs1], cpu_fpr[a->rs2]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fmul_h(DisasContext *ctx, arg_fmul_h *a)
{
    REQUIRE_FPU;

    gen_set_rm(ctx, a->rm);
    gen_helper_fmul_h(cpu_fpr[a->rd], cpu_env,
                      cpu_fpr[a->rs1], cpu_fpr[a->rs2]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fdiv_h(DisasContext *ctx, arg_fdiv_h *a)
{
    REQUIRE_FPU;

    gen_set_rm(ctx, a->rm);
    gen_helper_fdiv_h(cpu_fpr[a->rd], cpu_env,
                      cpu_fpr[a->rs1], cpu_fpr[a->rs2]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fsqrt_h(DisasContext *ctx, arg_fsqrt_h *a)
{
    REQUIRE_FPU;

    gen_set_rm(ctx, a->rm);
    gen_helper_fsqrt_h(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fmv_x_h(DisasContext *ctx, arg_fmv_x_h *a)
{
    REQUIRE_FPU;
    TCGv_i64 t_64 = tcg_temp_new_i64();
    TCGv t = temp_new(ctx);

    tcg_gen_ext16s_i64(t_64, cpu_fpr[a->rs1]);
    tcg_gen_trunc_i64_tl(t, t_64);

    gen_set_gpr(ctx, a->rd, t);
    tcg_temp_free_i64(t_64);
    return true;
}

static bool trans_fmv_h_x(DisasContext *ctx, arg_fmv_h_x *a)
{
    REQUIRE_FPU;
    TCGv src1 = get_gpr(ctx, a->rs1, EXT_NONE);

    tcg_gen_extu_tl_i64(cpu_fpr[a->rd], src1);
    gen_nanbox_h(cpu_fpr[a->rd], cpu_fpr[a->rd]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fsgnj_h(DisasContext *ctx, arg_fsgnj_h *a)
{
    REQUIRE_FPU;

    if (a->rs1 == a->rs2) { /* FMOV */
        if (ctx->bf16) {
            gen_check_nanbox_bh(cpu_fpr[a->rd], cpu_fpr[a->rs1]);
        } else {
            gen_check_nanbox_h(cpu_fpr[a->rd], cpu_fpr[a->rs1]);
        }
    } else { /* FSGNJ */
        TCGv_i64 rs1 = tcg_temp_new_i64();
        TCGv_i64 rs2 = tcg_temp_new_i64();

        if (ctx->bf16) {
            gen_check_nanbox_bh(rs1, cpu_fpr[a->rs1]);
            gen_check_nanbox_bh(rs2, cpu_fpr[a->rs2]);
        } else {
            gen_check_nanbox_h(rs1, cpu_fpr[a->rs1]);
            gen_check_nanbox_h(rs2, cpu_fpr[a->rs2]);
        }

        /* This formulation retains the nanboxing of rs2. */
        tcg_gen_deposit_i64(cpu_fpr[a->rd], rs2, rs1, 0, 15);
        tcg_temp_free_i64(rs1);
        tcg_temp_free_i64(rs2);
    }

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fsgnjn_h(DisasContext *ctx, arg_fsgnjn_h *a)
{
    TCGv_i64 rs1, rs2, mask;
    REQUIRE_FPU;

    rs1 = tcg_temp_new_i64();
    if (ctx->bf16) {
        gen_check_nanbox_bh(rs1, cpu_fpr[a->rs1]);
    } else {
        gen_check_nanbox_h(rs1, cpu_fpr[a->rs1]);
    }

    if (a->rs1 == a->rs2) { /* FNEG */
        tcg_gen_xori_i64(cpu_fpr[a->rd], rs1, MAKE_64BIT_MASK(15, 1));
    } else {
        rs2 = tcg_temp_new_i64();
        if (ctx->bf16) {
            gen_check_nanbox_bh(rs2, cpu_fpr[a->rs2]);
        } else {
            gen_check_nanbox_h(rs2, cpu_fpr[a->rs2]);
        }

        /*
         * Replace bit 15 in rs1 with inverse in rs2.
         * This formulation retains the nanboxing of rs1.
         */
        mask = tcg_const_i64(~MAKE_64BIT_MASK(15, 1));
        tcg_gen_nor_i64(rs2, rs2, mask);
        tcg_gen_and_i64(rs1, mask, rs1);
        tcg_gen_or_i64(cpu_fpr[a->rd], rs1, rs2);

        tcg_temp_free_i64(mask);
        tcg_temp_free_i64(rs2);
    }
    tcg_temp_free_i64(rs1);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fsgnjx_h(DisasContext *ctx, arg_fsgnjx_h *a)
{
    TCGv_i64 rs1, rs2;
    REQUIRE_FPU;

    rs1 = tcg_temp_new_i64();
    if (ctx->bf16) {
        gen_check_nanbox_bh(rs1, cpu_fpr[a->rs1]);
    } else {
        gen_check_nanbox_h(rs1, cpu_fpr[a->rs1]);
    }

    if (a->rs1 == a->rs2) { /* FABS */
        tcg_gen_andi_i64(cpu_fpr[a->rd], rs1, ~MAKE_64BIT_MASK(15, 1));
    } else {
        rs2 = tcg_temp_new_i64();
        if (ctx->bf16) {
            gen_check_nanbox_bh(rs2, cpu_fpr[a->rs2]);
        } else {
            gen_check_nanbox_h(rs2, cpu_fpr[a->rs2]);
        }

        /*
         * Xor bit 15 in rs1 with that in rs2.
         * This formulation retains the nanboxing of rs1.
         */
        tcg_gen_andi_i64(rs2, rs2, MAKE_64BIT_MASK(15, 1));
        tcg_gen_xor_i64(cpu_fpr[a->rd], rs1, rs2);

        tcg_temp_free_i64(rs2);
    }
    tcg_temp_free_i64(rs1);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fmin_h(DisasContext *ctx, arg_fmin_h *a)
{
    REQUIRE_FPU;

    gen_helper_fmin_h(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1],
                      cpu_fpr[a->rs2]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fmax_h(DisasContext *ctx, arg_fmax_h *a)
{
    REQUIRE_FPU;

    gen_helper_fmax_h(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1],
                      cpu_fpr[a->rs2]);

    mark_fs_dirty(ctx);
    return true;
}

static bool gen_fcvt_x_h(DisasContext *ctx, arg_r2_rm *a,
                         void (*func)(TCGv, TCGv_env, TCGv_i64))
{
    REQUIRE_FPU;
    TCGv dst1;
    dst1 = dest_gpr(ctx, a->rd);

    gen_set_rm(ctx, a->rm);
    func(dst1, cpu_env, cpu_fpr[a->rs1]);
    gen_set_gpr(ctx, a->rd, dst1);
    return true;
}

static bool trans_fcvt_w_h(DisasContext *ctx, arg_fcvt_w_h *a)
{
    return gen_fcvt_x_h(ctx, a, gen_helper_fcvt_w_h);
}

static bool trans_fcvt_wu_h(DisasContext *ctx, arg_fcvt_wu_h *a)
{
    return gen_fcvt_x_h(ctx, a, gen_helper_fcvt_wu_h);
}

static bool gen_cmp_h(DisasContext *ctx, arg_r *a,
                      void (*func)(TCGv, TCGv_env, TCGv_i64, TCGv_i64))
{
    REQUIRE_FPU;
    TCGv dst1;
    dst1 = dest_gpr(ctx, a->rd);

    func(dst1, cpu_env, cpu_fpr[a->rs1], cpu_fpr[a->rs2]);
    gen_set_gpr(ctx, a->rd, dst1);
    return true;
}

static bool trans_feq_h(DisasContext *ctx, arg_feq_h *a)
{
    return gen_cmp_h(ctx, a, gen_helper_feq_h);
}

static bool trans_flt_h(DisasContext *ctx, arg_flt_h *a)
{
    return gen_cmp_h(ctx, a, gen_helper_flt_h);
}

static bool trans_fle_h(DisasContext *ctx, arg_fle_h *a)
{
    return gen_cmp_h(ctx, a, gen_helper_fle_h);
}

static bool trans_fclass_h(DisasContext *ctx, arg_fclass_h *a)
{
    REQUIRE_FPU;
    TCGv t0 = temp_new(ctx);

    if (ctx->bf16) {
        gen_helper_fclass_bh(t0, cpu_fpr[a->rs1]);
    } else {
        gen_helper_fclass_h(t0, cpu_fpr[a->rs1]);
    }
    gen_set_gpr(ctx, a->rd, t0);
    return true;
}

static bool gen_fcvt_h_x(DisasContext *ctx, arg_r2_rm *a,
                         void (*func)(TCGv_i64, TCGv_env, TCGv))
{
    REQUIRE_FPU;
    TCGv src1 = get_gpr(ctx, a->rs1, EXT_NONE);

    gen_set_rm(ctx, a->rm);
    func(cpu_fpr[a->rd], cpu_env, src1);
    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fcvt_h_w(DisasContext *ctx, arg_fcvt_h_w *a)
{
    return gen_fcvt_h_x(ctx, a, gen_helper_fcvt_h_w);
}

static bool trans_fcvt_h_wu(DisasContext *ctx, arg_fcvt_h_wu *a)
{
    return gen_fcvt_h_x(ctx, a, gen_helper_fcvt_h_wu);
}

static bool trans_fcvt_l_h(DisasContext *ctx, arg_fcvt_l_h *a)
{
    REQUIRE_64BIT(ctx);

    return gen_fcvt_x_h(ctx, a, gen_helper_fcvt_l_h);
}

static bool trans_fcvt_lu_h(DisasContext *ctx, arg_fcvt_lu_h *a)
{
    REQUIRE_64BIT(ctx);
    return gen_fcvt_x_h(ctx, a, gen_helper_fcvt_lu_h);
}

static bool trans_fcvt_h_l(DisasContext *ctx, arg_fcvt_h_l *a)
{
    REQUIRE_64BIT(ctx);
    return gen_fcvt_h_x(ctx, a, gen_helper_fcvt_h_l);
}

static bool trans_fcvt_h_lu(DisasContext *ctx, arg_fcvt_h_lu *a)
{
    REQUIRE_64BIT(ctx);
    return gen_fcvt_h_x(ctx, a, gen_helper_fcvt_h_lu);
}

static bool trans_fcvt_s_h(DisasContext *ctx, arg_fcvt_s_h *a)
{
    REQUIRE_FPU;

    gen_set_rm(ctx, a->rm);
    gen_helper_fcvt_s_h(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fcvt_h_s(DisasContext *ctx, arg_fcvt_h_s *a)
{
    REQUIRE_FPU;

    gen_set_rm(ctx, a->rm);
    gen_helper_fcvt_h_s(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fcvt_h_d(DisasContext *ctx, arg_fcvt_h_d *a)
{
    REQUIRE_FPU;

    gen_set_rm(ctx, a->rm);
    gen_helper_fcvt_h_d(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fcvt_d_h(DisasContext *ctx, arg_fcvt_d_h *a)
{
    REQUIRE_FPU;

    gen_set_rm(ctx, a->rm);
    gen_helper_fcvt_d_h(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_ipush(DisasContext *ctx, arg_ipush *a)
{
#ifndef CONFIG_USER_ONLY
    gen_helper_ipush(cpu_env);
    return true;
#else
    return false;
#endif
}

static bool trans_ipop(DisasContext *ctx, arg_ipop *a)
{
#ifndef CONFIG_USER_ONLY
    tcg_gen_movi_tl(cpu_pc, ctx->base.pc_next);
    gen_helper_ipop(cpu_pc, cpu_env, cpu_pc);
    exit_tb(ctx); /* no chaining */
    ctx->base.is_jmp = DISAS_NORETURN;
    return true;
#else
    return false;
#endif
}

static bool trans_fmv_hw_x(DisasContext *ctx, arg_fmv_hw_x *a)
{
    REQUIRE_32BIT(ctx);
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVD);

    TCGv src1 = get_gpr(ctx, a->rs1, EXT_ZERO);
    TCGv_i64 t1 = tcg_temp_new_i64();

    tcg_gen_extu_tl_i64(t1, src1);
    tcg_gen_deposit_i64(cpu_fpr[a->rd], cpu_fpr[a->rd], t1, 32, 32);
    tcg_temp_free_i64(t1);
    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fmv_x_hw(DisasContext *ctx, arg_fmv_x_hw *a)
{
    REQUIRE_32BIT(ctx);
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVD);
    TCGv dst;
    TCGv_i64 t1;

    dst = dest_gpr(ctx, a->rd);
    t1 = tcg_temp_new_i64();

    tcg_gen_extract_i64(t1, cpu_fpr[a->rs1], 32, 32);
    tcg_gen_trunc_i64_tl(dst, t1);
    gen_set_gpr(ctx, a->rd, dst);
    tcg_temp_free_i64(t1);
    mark_fs_dirty(ctx);
    return true;
}
