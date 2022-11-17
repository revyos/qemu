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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arm_neon.h>

#define FLOAT_SCALE	10000.0
#define FIX16_SCALE	0x10000
#define FIX8_SCALE	0x100

#define RAND_SEED	2019

#define FIXS8		1
#define FIXS16		2
#define FIXS32		4
#define FIXS64		8
#define FIXU8		16
#define FIXU16		32
#define FIXU32		64
#define FIXU64		128
#define FLOAT32		256

#define INST_T0         (FIXS8 | FIXS16 | FIXS32 | FIXS64 | FIXU8 | \
                         FIXU16 | FIXU32 | FIXU64 |FLOAT32)
#define INST_T1         (FIXS8 | FIXS16 | FIXS32 | FIXU8 | FIXU16 | FIXU32)
#define INST_T2         (FIXS8 | FIXS16 | FIXS32 | FIXS64 | FIXU8 | FIXU16 | \
                         FIXU32 | FIXU64)
#define INST_T3         (FIXS8 | FIXS16 | FIXS32 | FIXU8 | FIXU16 | FIXU32 | \
                         FLOAT32)
#define INST_T4         (FIXS16 | FIXS32)
#define INST_T5         (FLOAT32)
#define INST_T6         (FIXS8 | FIXS16 | FIXS32 | FLOAT32)
#define INST_T7         (FIXS8 | FIXS16 | FIXS32)
#define INST_T8         (FIXS8 | FIXU8)
#define INST_T9         (FIXS8 | FIXS16 | FIXU8 | FIXU16)
#define INST_T10        (FIXS16 | FIXS32 | FIXU16 | FIXU32 | FLOAT32)
#define INST_T11        (FIXS8 | FIXS16 | FIXS32 | FIXS64)
#define INST_T12        (FIXS16 | FIXS32 | FIXS64 | FIXU16 | FIXU32 | FIXU64)
#define INST_T13        (FIXS8 | FIXS16 | FIXS32 | FIXS64)

struct sreg64 {
    int8x8_t        fixs8;
    int16x4_t       fixs16;
    int32x2_t       fixs32;
    int64x1_t       fixs64;
    uint8x8_t       fixu8;
    uint16x4_t      fixu16;
    uint32x2_t      fixu32;
    uint64x1_t      fixu64;
    float32x2_t     float32;
};

struct sreg128 {
    int8x16_t       fixs8;
    int16x8_t       fixs16;
    int32x4_t       fixs32;
    int64x2_t       fixs64;
    uint8x16_t      fixu8;
    uint16x8_t      fixu16;
    uint32x4_t      fixu32;
    uint64x2_t      fixu64;
    float32x4_t     float32;
};

struct sreg128x2 {
    int8x16x2_t     fixs8;
    int16x8x2_t     fixs16;
    int32x4x2_t     fixs32;
    int64x2x2_t     fixs64;
    uint8x16x2_t    fixu8;
    uint16x8x2_t    fixu16;
    uint32x4x2_t    fixu32;
    uint64x2x2_t    fixu64;
    float32x4x2_t   float32;
};

struct neon_handler_1_1 {
    void (*handler)(struct sreg128 *a);
};

struct neon_handler_1_2 {
    void (*handler)(struct sreg128 *a, struct sreg128 *b);
};

struct neon_handler_1_3 {
    void (*handler)(struct sreg128 *a, struct sreg128 *b, struct sreg128 *c);
};

struct neon_handler_1_4 {
    void (*handler)(struct sreg128 *a, struct sreg128 *b, struct sreg128 *c,
                    struct sreg128 *d);
};

struct neon_handler_2_2 {
    void (*handler)(struct sreg128 *a, struct sreg128 *b);
};

struct neon_handler_2_3 {
    void (*handler)(struct sreg128 *a, struct sreg128 *b, struct sreg128 *c);
};

struct neon_handler_2_4 {
    void (*handler)(struct sreg128 *z0, struct sreg128 *z1,
                    struct sreg128 *a, struct sreg128 *b);
};

void print_one_reg(struct sreg128 *s0, int type)
{
    int i;
    if (type & FLOAT32) {
        printf("        .float32 = {");
        for (i = 0; i < 4; i++) {
            printf("0x%.8x, ", *(unsigned int *)&(s0->float32[i]));
        }
        printf("},\n");
    }

    if (type & FIXS64) {
        printf("        .fixs64 = {");
        for (i = 0; i < 2; i++) {
            printf("0x%.16llx, ", *(unsigned long long *)&(s0->fixs64[i]));
        }
        printf("},\n");
    }

    if (type & FIXS32) {
        printf("        .fixs32 = {");
        for (i = 0; i < 4; i++) {
            printf("0x%.8x, ", s0->fixs32[i]);
        }
        printf("},\n");
    }

    if (type & FIXS16) {
        printf("        .fixs16 = {");
        for (i = 0; i < 8; i++) {
            printf("0x%.4x, ", (unsigned short)s0->fixs16[i]);
        }
        printf("},\n");
    }

    if (type & FIXS8) {
        printf("        .fixs8 = {");
        for (i = 0; i < 16; i++) {
            printf("0x%.2x, ", (unsigned char)s0->fixs8[i]);
        }
        printf("},\n");
    }

    if (type & FIXU64) {
        printf("        .fixu64 = {");
        for (i = 0; i < 2; i++) {
            printf("0x%.16llx, ", *(unsigned long long *)&(s0->fixu64[i]));
        }
        printf("},\n");
    }

    if (type & FIXU32) {
        printf("        .fixu32 = {");
        for (i = 0; i < 4; i++) {
            printf("0x%.8x, ", s0->fixu32[i]);
        }
        printf("},\n");
    }

    if (type & FIXU16) {
        printf("        .fixu16 = {");
        for (i = 0; i < 8; i++) {
            printf("0x%.4x, ", (unsigned short)s0->fixu16[i]);
        }
        printf("},\n");
    }

    if (type & FIXU8) {
        printf("        .fixu8 = {");
        for (i = 0; i < 16; i++) {
            printf("0x%.2x, ", (unsigned char)s0->fixu8[i]);
        }
        printf("},\n");
    }

}

void print_x2_reg(struct sreg128x2 *s0, int type)
{
    int i;

    printf("/* dst reg 0 */\n");
    printf("struct vdsp_reg dst0[] = {\n    {\n");
    if (type & FLOAT32) {
        printf("        .float32 = {");
        for (i = 0; i < 4; i++) {
            printf("0x%.8x, ", *(unsigned int *)&(s0->float32.val[0][i]));
        }
        printf("},\n");
    }

    if (type & FIXS64) {
        printf("        .fixs64 = {");
        for (i = 0; i < 2; i++) {
            printf("0x%.16llx, ",
                   *(unsigned long long *)&(s0->fixs64.val[0][i]));
        }
        printf("},\n");
    }

    if (type & FIXS32) {
        printf("        .fixs32 = {");
        for (i = 0; i < 4; i++) {
            printf("0x%.8x, ", s0->fixs32.val[0][i]);
        }
        printf("},\n");
    }

    if (type & FIXS16) {
        printf("        .fixs16 = {");
        for (i = 0; i < 8; i++) {
            printf("0x%.4x, ", (unsigned short)s0->fixs16.val[0][i]);
        }
        printf("},\n");
    }

    if (type & FIXS8) {
        printf("        .fixs8 = {");
        for (i = 0; i < 16; i++) {
            printf("0x%.2x, ", (unsigned char)s0->fixs8.val[0][i]);
        }
        printf("},\n");
    }

    if (type & FIXU64) {
        printf("        .fixu64 = {");
        for (i = 0; i < 2; i++) {
            printf("0x%.16llx, ",
                   *(unsigned long long *)&(s0->fixu64.val[0][i]));
        }
        printf("i},\n");
    }

    if (type & FIXU32) {
        printf("        .fixu32 = {");
        for (i = 0; i < 4; i++) {
            printf("0x%.8x, ", s0->fixu32.val[0][i]);
        }
        printf("},\n");
    }

    if (type & FIXU16) {
        printf("        .fixu16 = {");
        for (i = 0; i < 8; i++) {
            printf("0x%.4x, ", (unsigned short)s0->fixu16.val[0][i]);
        }
        printf("},\n");
    }

    if (type & FIXU8) {
        printf("        .fixu8 = {");
        for (i = 0; i < 16; i++) {
            printf("0x%.2x, ", (unsigned char)s0->fixu8.val[0][i]);
        }
        printf("},\n");
    }
    printf("    },\n};\n");

    printf("/* dst reg 1 */\n");
    printf("struct vdsp_reg dst1[] = {\n    {\n");
    if (type & FLOAT32) {
        printf("        .float32 = {");
        for (i = 0; i < 4; i++) {
            printf("0x%.8x, ", *(unsigned int *)&(s0->float32.val[1][i]));
        }
        printf("},\n");
    }

    if (type & FIXS64) {
        printf("        .fixs64 = {");
        for (i = 0; i < 2; i++) {
            printf("0x%.16llx, ",
                   *(unsigned long long *)&(s0->fixs64.val[1][i]));
        }
        printf("},\n");
    }

    if (type & FIXS32) {
        printf("        .fixs32 = {");
        for (i = 0; i < 4; i++) {
            printf("0x%.8x, ", s0->fixs32.val[1][i]);
        }
        printf("},\n");
    }

    if (type & FIXS16) {
        printf("        .fixs16 = {");
        for (i = 0; i < 8; i++) {
            printf("0x%.4x, ", (unsigned short)s0->fixs16.val[1][i]);
        }
        printf("},\n");
    }

    if (type & FIXS8) {
        printf("        .fixs8 = {");
        for (i = 0; i < 16; i++) {
            printf("0x%.2x, ", (unsigned char)s0->fixs8.val[1][i]);
        }
        printf("},\n");
    }

    if (type & FIXU64) {
        printf("        .fixu64 = {");
        for (i = 0; i < 2; i++) {
            printf("0x%.16llx, ",
                   *(unsigned long long *)&(s0->fixu64.val[1][i]));
        }
        printf("i},\n");
    }

    if (type & FIXU32) {
        printf("        .fixu32 = {");
        for (i = 0; i < 4; i++) {
            printf("0x%.8x, ", s0->fixu32.val[1][i]);
        }
        printf("},\n");
    }

    if (type & FIXU16) {
        printf("        .fixu16 = {");
        for (i = 0; i < 8; i++) {
            printf("0x%.4x, ", (unsigned short)s0->fixu16.val[1][i]);
        }
        printf("},\n");
    }

    if (type & FIXU8) {
        printf("        .fixu8 = {");
        for (i = 0; i < 16; i++) {
            printf("0x%.2x, ", (unsigned char)s0->fixu8.val[1][i]);
        }
        printf("},\n");
    }
    printf("    },\n};\n");

}

void print_type(int type)
{
    if (type == INST_T0) {
        printf("/* float32/fixs64/fixs32/fixs16/fixs8"
               "/fixu64/fixu32/fixu16/fixu8 */\n\n");
    } else if (type == INST_T1) {
        printf("/* fixs32/fixs16/fixs8/fixu32/fixu16/fixu8 */\n\n");
    } else if (type == INST_T2) {
        printf("/* fixs64/fixs32/fixs16/fixs8/fixu64"
               "/fixu32/fixu16/fixu8 */\n\n");
    } else if (type == INST_T3) {
        printf("/* float32/fixs32/fixs16/fixs8/fixu32/fixu16/fixu8 */\n\n");
    } else if (type == INST_T4) {
        printf("/* fixs32/fixs16 */\n\n");
    } else if (type == INST_T5) {
        printf("/* float32 */\n\n");
    } else if (type == INST_T6) {
        printf("/* float32/fixs32/fixs16/fixs8 */\n\n");
    } else if (type == INST_T7) {
        printf("/* fixs32/fixs16/fixs8 */\n\n");
    } else if (type == INST_T8) {
        printf("/* fixs8/fixu8 */\n\n");
    } else if (type == INST_T9) {
        printf("/* fixs16/fixs8/fixu16/fixu8 */\n\n");
    } else if (type == INST_T10) {
        printf("/* float32/fixs32/fixs16/fixu32/fixu16 */\n\n");
    } else if (type == INST_T11) {
        printf("/* fixs64/fixs32/fixs16/fixs8 */\n\n");
    } else if (type == INST_T12) {
        printf("/* fixs64/fixs32/fixs16/fixu64/fixu32/fixu16 */\n\n");
    }

}

char ref_inst[32];
void print_1_1(const char *func, struct sreg128 *res,
               struct sreg128 *s0, int type)
{
    int i;
    printf("\n%s\n", ref_inst);
    print_type(type);

    printf("/* src reg 0 */\n");
    printf("struct vdsp_reg src[] = {\n    {\n");
    print_one_reg(s0, type);
    printf("    },\n};\n");

    printf("/* dst reg 0 */\n");
    printf("struct vdsp_reg dst[] = {\n    {\n");
    print_one_reg(res, type);
    printf("    },\n};\n");
}

void print_1_2(const char *func, struct sreg128 *res,
               struct sreg128 *s0, struct sreg128 *s1, int type)
{
    int i;
    printf("\n%s\n", ref_inst);
    print_type(type);

    printf("/* src reg 0 */\n");
    printf("struct vdsp_reg src0[] = {\n    {\n");
    print_one_reg(s0, type);
    printf("    },\n};\n");

    printf("/* src reg 1 */\n");
    printf("struct vdsp_reg src1[] = {\n    {\n");
    print_one_reg(s1, type);
    printf("    },\n};\n");

    printf("/* dst reg 0 */\n");
    printf("struct vdsp_reg dst0[] = {\n    {\n");
    print_one_reg(res, type);
    printf("    },\n};\n");
}

void print_1_3(const char *func, struct sreg128 *res, struct sreg128 *s0,
               struct sreg128 *s1, struct sreg128 *s2, int type)
{
    int i;
    printf("\n%s\n", ref_inst);
    print_type(type);

    printf("/* src reg 0 */\n");
    printf("struct vdsp_reg src0[] = {\n    {\n");
    print_one_reg(s0, type);
    printf("    },\n};\n");

    printf("/* src reg 1 */\n");
    printf("struct vdsp_reg src1[] = {\n    {\n");
    print_one_reg(s1, type);
    printf("    },\n};\n");

    printf("/* src reg 2 */\n");
    printf("struct vdsp_reg src2[] = {\n    {\n");
    print_one_reg(s2, type);
    printf("    },\n};\n");

    printf("/* dst reg 0 */\n");
    printf("struct vdsp_reg dst0[] = {\n    {\n");
    print_one_reg(res, type);
    printf("    },\n};\n");
}

void print_1_4(const char *func, struct sreg128 *res, struct sreg128 *s0,
               struct sreg128 *s1, struct sreg128 *s2, struct sreg128 *s3,
               int type)
{
    int i;
    printf("\n%s\n", ref_inst);
    print_type(type);

    printf("/* src reg 0 */\n");
    printf("struct vdsp_reg src0[] = {\n    {\n");
    print_one_reg(s0, type);
    printf("    },\n};\n");

    printf("/* src reg 1 */\n");
    printf("struct vdsp_reg src1[] = {\n    {\n");
    print_one_reg(s1, type);
    printf("    },\n};\n");

    printf("/* src reg 2 */\n");
    printf("struct vdsp_reg src2[] = {\n    {\n");
    print_one_reg(s2, type);
    printf("    },\n};\n");

    printf("/* src reg 3 */\n");
    printf("struct vdsp_reg src3[] = {\n    {\n");
    print_one_reg(s3, type);
    printf("    },\n};\n");

    printf("/* dst reg 0 */\n");
    printf("struct vdsp_reg dst0[] = {\n    {\n");
    print_one_reg(res, type);
    printf("    },\n};\n");
}

void print_2_2(const char *func, struct sreg128x2 *res,
               struct sreg128 *s0, struct sreg128 *s1, int type)
{
    int i;
    printf("\n%s\n", ref_inst);
    print_type(type);

    printf("/* src reg 0 */\n");
    printf("struct vdsp_reg src0[] = {\n    {\n");
    print_one_reg(s0, type);
    printf("    },\n};\n");

    printf("/* src reg 1 */\n");
    printf("struct vdsp_reg src1[] = {\n    {\n");
    print_one_reg(s1, type);
    printf("    },\n};\n");

    /* dst reg 0 */
    print_x2_reg(res, type);
}

void print_2_3(const char *func, struct sreg128x2 *res,
               struct sreg128 *s0, struct sreg128 *s1,
               struct sreg128 *s2, int type)
{
    int i;
    printf("\n%s\n", ref_inst);
    print_type(type);

    printf("/* src reg 0 */\n");
    printf("struct vdsp_reg src0[] = {\n    {\n");
    print_one_reg(s0, type);
    printf("    },\n};\n");

    printf("/* src reg 1 */\n");
    printf("struct vdsp_reg src1[] = {\n    {\n");
    print_one_reg(s1, type);
    printf("    },\n};\n");

    printf("/* src reg 2 */\n");
    printf("struct vdsp_reg src2[] = {\n    {\n");
    print_one_reg(s2, type);
    printf("    },\n};\n");

    /* dst reg 0 */
    print_x2_reg(res, type);
}

void print_2_4(const char *func, struct sreg128x2 *res,
               struct sreg128 *s0, struct sreg128 *s1,
               struct sreg128 *s2, struct sreg128 *s3, int type)
{
    int i;
    printf("\n%s\n", ref_inst);
    print_type(type);

    printf("/* src reg 0 */\n");
    printf("struct vdsp_reg src0[] = {\n    {\n");
    print_one_reg(s0, type);
    printf("    },\n};\n");

    printf("/* src reg 1 */\n");
    printf("struct vdsp_reg src1[] = {\n    {\n");
    print_one_reg(s1, type);
    printf("    },\n};\n");

    printf("/* src reg 2 */\n");
    printf("struct vdsp_reg src2[] = {\n    {\n");
    print_one_reg(s2, type);
    printf("    },\n};\n");

    printf("/* src reg 3 */\n");
    printf("struct vdsp_reg src3[] = {\n    {\n");
    print_one_reg(s3, type);
    printf("    },\n};\n");

    /* dst reg 0 */
    print_x2_reg(res, type);
}

/* ############################################# */
/* ADD/SUB/CMP */
void vadd(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T0;

    res.fixs8   = vaddq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = vaddq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vaddq_s32(a->fixs32,  b->fixs32);
    res.fixs64  = vaddq_s64(a->fixs64,  b->fixs64);
    res.fixu8   = vaddq_u8 (a->fixu8,   b->fixu8);
    res.fixu16  = vaddq_u16(a->fixu16,  b->fixu16);
    res.fixu32  = vaddq_u32(a->fixu32,  b->fixu32);
    res.fixu64  = vaddq_u64(a->fixu64,  b->fixu64);
    res.float32 = vaddq_f32(a->float32, b->float32);

    sprintf(ref_inst, "/* %s - vadd.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vsub(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T0;

    res.fixs8   = vsubq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = vsubq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vsubq_s32(a->fixs32,  b->fixs32);
    res.fixs64  = vsubq_s64(a->fixs64,  b->fixs64);
    res.fixu8   = vsubq_u8 (a->fixu8,   b->fixu8);
    res.fixu16  = vsubq_u16(a->fixu16,  b->fixu16);
    res.fixu32  = vsubq_u32(a->fixu32,  b->fixu32);
    res.fixu64  = vsubq_u64(a->fixu64,  b->fixu64);
    res.float32 = vsubq_f32(a->float32, b->float32);

    sprintf(ref_inst, "/* %s - vsub.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vqadd(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T2;

    res.fixs8   = vqaddq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = vqaddq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vqaddq_s32(a->fixs32,  b->fixs32);
    res.fixs64  = vqaddq_s64(a->fixs64,  b->fixs64);
    res.fixu8   = vqaddq_u8 (a->fixu8,   b->fixu8);
    res.fixu16  = vqaddq_u16(a->fixu16,  b->fixu16);
    res.fixu32  = vqaddq_u32(a->fixu32,  b->fixu32);
    res.fixu64  = vqaddq_u64(a->fixu64,  b->fixu64);

    sprintf(ref_inst, "/* %s - vadd.t.s */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vqsub(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T2;

    res.fixs8   = vqsubq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = vqsubq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vqsubq_s32(a->fixs32,  b->fixs32);
    res.fixs64  = vqsubq_s64(a->fixs64,  b->fixs64);
    res.fixu8   = vqsubq_u8 (a->fixu8,   b->fixu8);
    res.fixu16  = vqsubq_u16(a->fixu16,  b->fixu16);
    res.fixu32  = vqsubq_u32(a->fixu32,  b->fixu32);
    res.fixu64  = vqsubq_u64(a->fixu64,  b->fixu64);

    sprintf(ref_inst, "/* %s - vsub.t.s */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vaddhn(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    struct sreg64 tmp;
    int type = INST_T12;

    tmp.fixs8  = vaddhn_s16(a->fixs16,  b->fixs16);
    tmp.fixs16 = vaddhn_s32(a->fixs32,  b->fixs32);
    tmp.fixs32 = vaddhn_s64(a->fixs64,  b->fixs64);
    tmp.fixu8  = vaddhn_u16(a->fixu16,  b->fixu16);
    tmp.fixu16 = vaddhn_u32(a->fixu32,  b->fixu32);
    tmp.fixu32 = vaddhn_u64(a->fixu64,  b->fixu64);

    memset(&res, 0, sizeof(struct sreg128));
    memcpy(&res.fixs16, &tmp.fixs8,  8);
    memcpy(&res.fixs32, &tmp.fixs16, 8);
    memcpy(&res.fixs64, &tmp.fixs32, 8);
    memcpy(&res.fixu16, &tmp.fixu8,  8);
    memcpy(&res.fixu32, &tmp.fixu16, 8);
    memcpy(&res.fixu64, &tmp.fixu32, 8);

    sprintf(ref_inst, "/* %s - vadd.t.h */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vsubhn(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    struct sreg64 tmp;
    int type = INST_T12;

    tmp.fixs8  = vsubhn_s16(a->fixs16,  b->fixs16);
    tmp.fixs16 = vsubhn_s32(a->fixs32,  b->fixs32);
    tmp.fixs32 = vsubhn_s64(a->fixs64,  b->fixs64);
    tmp.fixu8  = vsubhn_u16(a->fixu16,  b->fixu16);
    tmp.fixu16 = vsubhn_u32(a->fixu32,  b->fixu32);
    tmp.fixu32 = vsubhn_u64(a->fixu64,  b->fixu64);

    memset(&res, 0, sizeof(struct sreg128));
    memcpy(&res.fixs16, &tmp.fixs8,  8);
    memcpy(&res.fixs32, &tmp.fixs16, 8);
    memcpy(&res.fixs64, &tmp.fixs32, 8);
    memcpy(&res.fixu16, &tmp.fixu8,  8);
    memcpy(&res.fixu32, &tmp.fixu16, 8);
    memcpy(&res.fixu64, &tmp.fixu32, 8);

    sprintf(ref_inst, "/* %s - vsub.t.h */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vraddhn(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    struct sreg64 tmp;
    int type = INST_T12;

    tmp.fixs8  = vraddhn_s16(a->fixs16,  b->fixs16);
    tmp.fixs16 = vraddhn_s32(a->fixs32,  b->fixs32);
    tmp.fixs32 = vraddhn_s64(a->fixs64,  b->fixs64);
    tmp.fixu8  = vraddhn_u16(a->fixu16,  b->fixu16);
    tmp.fixu16 = vraddhn_u32(a->fixu32,  b->fixu32);
    tmp.fixu32 = vraddhn_u64(a->fixu64,  b->fixu64);

    memset(&res, 0, sizeof(struct sreg128));
    memcpy(&res.fixs16, &tmp.fixs8,  8);
    memcpy(&res.fixs32, &tmp.fixs16, 8);
    memcpy(&res.fixs64, &tmp.fixs32, 8);
    memcpy(&res.fixu16, &tmp.fixu8,  8);
    memcpy(&res.fixu32, &tmp.fixu16, 8);
    memcpy(&res.fixu64, &tmp.fixu32, 8);

    sprintf(ref_inst, "/* %s - vadd.t.rh */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vrsubhn(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    struct sreg64 tmp;
    int type = INST_T12;

    tmp.fixs8  = vrsubhn_s16(a->fixs16,  b->fixs16);
    tmp.fixs16 = vrsubhn_s32(a->fixs32,  b->fixs32);
    tmp.fixs32 = vrsubhn_s64(a->fixs64,  b->fixs64);
    tmp.fixu8  = vrsubhn_u16(a->fixu16,  b->fixu16);
    tmp.fixu16 = vrsubhn_u32(a->fixu32,  b->fixu32);
    tmp.fixu32 = vrsubhn_u64(a->fixu64,  b->fixu64);

    memset(&res, 0, sizeof(struct sreg128));
    memcpy(&res.fixs16, &tmp.fixs8,  8);
    memcpy(&res.fixs32, &tmp.fixs16, 8);
    memcpy(&res.fixs64, &tmp.fixs32, 8);
    memcpy(&res.fixu16, &tmp.fixu8,  8);
    memcpy(&res.fixu32, &tmp.fixu16, 8);
    memcpy(&res.fixu64, &tmp.fixu32, 8);

    sprintf(ref_inst, "/* %s - vsub.t.rh */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vaddl(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128x2 res;
    struct sreg128 tmp_res;
    struct sreg64 half_a, half_b;
    int type = INST_T1;

    memcpy(&half_a.fixs8,  &a->fixs8,  8);
    memcpy(&half_a.fixs16, &a->fixs16, 8);
    memcpy(&half_a.fixs32, &a->fixs32, 8);
    memcpy(&half_a.fixu8,  &a->fixu8,  8);
    memcpy(&half_a.fixu16, &a->fixu16, 8);
    memcpy(&half_a.fixu32, &a->fixu32, 8);

    memcpy(&half_b.fixs8,  &b->fixs8,  8);
    memcpy(&half_b.fixs16, &b->fixs16, 8);
    memcpy(&half_b.fixs32, &b->fixs32, 8);
    memcpy(&half_b.fixu8,  &b->fixu8,  8);
    memcpy(&half_b.fixu16, &b->fixu16, 8);
    memcpy(&half_b.fixu32, &b->fixu32, 8);

    tmp_res.fixs16 = vaddl_s8 (half_a.fixs8,  half_b.fixs8);
    tmp_res.fixs32 = vaddl_s16(half_a.fixs16, half_b.fixs16);
    tmp_res.fixs64 = vaddl_s32(half_a.fixs32, half_b.fixs32);
    tmp_res.fixu16 = vaddl_u8 (half_a.fixu8,  half_b.fixu8);
    tmp_res.fixu32 = vaddl_u16(half_a.fixu16, half_b.fixu16);
    tmp_res.fixu64 = vaddl_u32(half_a.fixu32, half_b.fixu32);

    memcpy(&res.fixs8,  &tmp_res.fixs16, 16);
    memcpy(&res.fixs16, &tmp_res.fixs32, 16);
    memcpy(&res.fixs32, &tmp_res.fixs64, 16);
    memcpy(&res.fixu8,  &tmp_res.fixu16, 16);
    memcpy(&res.fixu16, &tmp_res.fixu32, 16);
    memcpy(&res.fixu32, &tmp_res.fixu64, 16);

    memcpy(&half_a.fixs8,  (&a->fixs8[8]),  8);
    memcpy(&half_a.fixs16, (&a->fixs16[4]), 8);
    memcpy(&half_a.fixs32, (&a->fixs32[2]), 8);
    memcpy(&half_a.fixu8,  (&a->fixu8[8]),  8);
    memcpy(&half_a.fixu16, (&a->fixu16[4]), 8);
    memcpy(&half_a.fixu32, (&a->fixu32[2]), 8);

    memcpy(&half_b.fixs8,  (&b->fixs8[8]),  8);
    memcpy(&half_b.fixs16, (&b->fixs16[4]), 8);
    memcpy(&half_b.fixs32, (&b->fixs32[2]), 8);
    memcpy(&half_b.fixu8,  (&b->fixu8[8]),  8);
    memcpy(&half_b.fixu16, (&b->fixu16[4]), 8);
    memcpy(&half_b.fixu32, (&b->fixu32[2]), 8);

    tmp_res.fixs16 = vaddl_s8 (half_a.fixs8,  half_b.fixs8);
    tmp_res.fixs32 = vaddl_s16(half_a.fixs16, half_b.fixs16);
    tmp_res.fixs64 = vaddl_s32(half_a.fixs32, half_b.fixs32);
    tmp_res.fixu16 = vaddl_u8 (half_a.fixu8,  half_b.fixu8);
    tmp_res.fixu32 = vaddl_u16(half_a.fixu16, half_b.fixu16);
    tmp_res.fixu64 = vaddl_u32(half_a.fixu32, half_b.fixu32);

    memcpy(&res.fixs8.val[1],  &tmp_res.fixs16, 16);
    memcpy(&res.fixs16.val[1], &tmp_res.fixs32, 16);
    memcpy(&res.fixs32.val[1], &tmp_res.fixs64, 16);
    memcpy(&res.fixu8.val[1],  &tmp_res.fixu16, 16);
    memcpy(&res.fixu16.val[1], &tmp_res.fixu32, 16);
    memcpy(&res.fixu32.val[1], &tmp_res.fixu64, 16);

    sprintf(ref_inst, "/* %s - vadd.t.e */", __FUNCTION__);
    print_2_2(__FUNCTION__, &res, a, b, type);
}

void vsubl(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128x2 res;
    struct sreg128 tmp_res;
    struct sreg64 half_a, half_b;
    int type = INST_T1;

    memcpy(&half_a.fixs8,  &a->fixs8,  8);
    memcpy(&half_a.fixs16, &a->fixs16, 8);
    memcpy(&half_a.fixs32, &a->fixs32, 8);
    memcpy(&half_a.fixu8,  &a->fixu8,  8);
    memcpy(&half_a.fixu16, &a->fixu16, 8);
    memcpy(&half_a.fixu32, &a->fixu32, 8);

    memcpy(&half_b.fixs8,  &b->fixs8,  8);
    memcpy(&half_b.fixs16, &b->fixs16, 8);
    memcpy(&half_b.fixs32, &b->fixs32, 8);
    memcpy(&half_b.fixu8,  &b->fixu8,  8);
    memcpy(&half_b.fixu16, &b->fixu16, 8);
    memcpy(&half_b.fixu32, &b->fixu32, 8);

    tmp_res.fixs16 = vsubl_s8 (half_a.fixs8,  half_b.fixs8);
    tmp_res.fixs32 = vsubl_s16(half_a.fixs16, half_b.fixs16);
    tmp_res.fixs64 = vsubl_s32(half_a.fixs32, half_b.fixs32);
    tmp_res.fixu16 = vsubl_u8 (half_a.fixu8,  half_b.fixu8);
    tmp_res.fixu32 = vsubl_u16(half_a.fixu16, half_b.fixu16);
    tmp_res.fixu64 = vsubl_u32(half_a.fixu32, half_b.fixu32);

    memcpy(&res.fixs8,  &tmp_res.fixs16, 16);
    memcpy(&res.fixs16, &tmp_res.fixs32, 16);
    memcpy(&res.fixs32, &tmp_res.fixs64, 16);
    memcpy(&res.fixu8,  &tmp_res.fixu16, 16);
    memcpy(&res.fixu16, &tmp_res.fixu32, 16);
    memcpy(&res.fixu32, &tmp_res.fixu64, 16);

    memcpy(&half_a.fixs8,  (&a->fixs8[8]),  8);
    memcpy(&half_a.fixs16, (&a->fixs16[4]), 8);
    memcpy(&half_a.fixs32, (&a->fixs32[2]), 8);
    memcpy(&half_a.fixu8,  (&a->fixu8[8]),  8);
    memcpy(&half_a.fixu16, (&a->fixu16[4]), 8);
    memcpy(&half_a.fixu32, (&a->fixu32[2]), 8);

    memcpy(&half_b.fixs8,  (&b->fixs8[8]),  8);
    memcpy(&half_b.fixs16, (&b->fixs16[4]), 8);
    memcpy(&half_b.fixs32, (&b->fixs32[2]), 8);
    memcpy(&half_b.fixu8,  (&b->fixu8[8]),  8);
    memcpy(&half_b.fixu16, (&b->fixu16[4]), 8);
    memcpy(&half_b.fixu32, (&b->fixu32[2]), 8);

    tmp_res.fixs16 = vsubl_s8 (half_a.fixs8,  half_b.fixs8);
    tmp_res.fixs32 = vsubl_s16(half_a.fixs16, half_b.fixs16);
    tmp_res.fixs64 = vsubl_s32(half_a.fixs32, half_b.fixs32);
    tmp_res.fixu16 = vsubl_u8 (half_a.fixu8,  half_b.fixu8);
    tmp_res.fixu32 = vsubl_u16(half_a.fixu16, half_b.fixu16);
    tmp_res.fixu64 = vsubl_u32(half_a.fixu32, half_b.fixu32);

    memcpy(&res.fixs8.val[1],  &tmp_res.fixs16, 16);
    memcpy(&res.fixs16.val[1], &tmp_res.fixs32, 16);
    memcpy(&res.fixs32.val[1], &tmp_res.fixs64, 16);
    memcpy(&res.fixu8.val[1],  &tmp_res.fixu16, 16);
    memcpy(&res.fixu16.val[1], &tmp_res.fixu32, 16);
    memcpy(&res.fixu32.val[1], &tmp_res.fixu64, 16);

    sprintf(ref_inst, "/* %s - vsub.t.e */", __FUNCTION__);
    print_2_2(__FUNCTION__, &res, a, b, type);
}

void vaddw(struct sreg128 *a, struct sreg128 *b, struct sreg128 *c)
{
    struct sreg128x2 res;
    struct sreg128 tmp_res, tmp_a;
    struct sreg64 tmp_c;
    int type = INST_T1;

    memcpy(&tmp_a.fixs16, &a->fixs8,  16);
    memcpy(&tmp_a.fixs32, &a->fixs16, 16);
    memcpy(&tmp_a.fixs64, &a->fixs32, 16);
    memcpy(&tmp_a.fixu16, &a->fixu8,  16);
    memcpy(&tmp_a.fixu32, &a->fixu16, 16);
    memcpy(&tmp_a.fixu64, &a->fixu32, 16);

    memcpy(&tmp_c.fixs8,  &c->fixs8,  8);
    memcpy(&tmp_c.fixs16, &c->fixs16, 8);
    memcpy(&tmp_c.fixs32, &c->fixs32, 8);
    memcpy(&tmp_c.fixu8,  &c->fixu8,  8);
    memcpy(&tmp_c.fixu16, &c->fixu16, 8);
    memcpy(&tmp_c.fixu32, &c->fixu32, 8);

    tmp_res.fixs16 = vaddw_s8 (tmp_a.fixs16, tmp_c.fixs8);
    tmp_res.fixs32 = vaddw_s16(tmp_a.fixs32, tmp_c.fixs16);
    tmp_res.fixs64 = vaddw_s32(tmp_a.fixs64, tmp_c.fixs32);
    tmp_res.fixu16 = vaddw_u8 (tmp_a.fixu16, tmp_c.fixu8);
    tmp_res.fixu32 = vaddw_u16(tmp_a.fixu32, tmp_c.fixu16);
    tmp_res.fixu64 = vaddw_u32(tmp_a.fixu64, tmp_c.fixu32);

    memcpy(&res.fixs8.val[0],  &tmp_res.fixs16, 16);
    memcpy(&res.fixs16.val[0], &tmp_res.fixs32, 16);
    memcpy(&res.fixs32.val[0], &tmp_res.fixs64, 16);
    memcpy(&res.fixu8.val[0],  &tmp_res.fixu16, 16);
    memcpy(&res.fixu16.val[0], &tmp_res.fixu32, 16);
    memcpy(&res.fixu32.val[0], &tmp_res.fixu64, 16);

    memcpy(&tmp_a.fixs16, &b->fixs8,  16);
    memcpy(&tmp_a.fixs32, &b->fixs16, 16);
    memcpy(&tmp_a.fixs64, &b->fixs32, 16);
    memcpy(&tmp_a.fixu16, &b->fixu8,  16);
    memcpy(&tmp_a.fixu32, &b->fixu16, 16);
    memcpy(&tmp_a.fixu64, &b->fixu32, 16);

    memcpy(&tmp_c.fixs8,  &c->fixs8[8],  8);
    memcpy(&tmp_c.fixs16, &c->fixs16[4], 8);
    memcpy(&tmp_c.fixs32, &c->fixs32[2], 8);
    memcpy(&tmp_c.fixu8,  &c->fixu8[8],  8);
    memcpy(&tmp_c.fixu16, &c->fixu16[4], 8);
    memcpy(&tmp_c.fixu32, &c->fixu32[2], 8);

    tmp_res.fixs16 = vaddw_s8 (tmp_a.fixs16, tmp_c.fixs8);
    tmp_res.fixs32 = vaddw_s16(tmp_a.fixs32, tmp_c.fixs16);
    tmp_res.fixs64 = vaddw_s32(tmp_a.fixs64, tmp_c.fixs32);
    tmp_res.fixu16 = vaddw_u8 (tmp_a.fixu16, tmp_c.fixu8);
    tmp_res.fixu32 = vaddw_u16(tmp_a.fixu32, tmp_c.fixu16);
    tmp_res.fixu64 = vaddw_u32(tmp_a.fixu64, tmp_c.fixu32);

    memcpy(&res.fixs8.val[1],  &tmp_res.fixs16, 16);
    memcpy(&res.fixs16.val[1], &tmp_res.fixs32, 16);
    memcpy(&res.fixs32.val[1], &tmp_res.fixs64, 16);
    memcpy(&res.fixu8.val[1],  &tmp_res.fixu16, 16);
    memcpy(&res.fixu16.val[1], &tmp_res.fixu32, 16);
    memcpy(&res.fixu32.val[1], &tmp_res.fixu64, 16);

    sprintf(ref_inst, "/* %s - vadd.t.x */", __FUNCTION__);
    print_2_3(__FUNCTION__, &res, a, b, c, type);
}

void vsubw(struct sreg128 *a, struct sreg128 *b, struct sreg128 *c)
{
    struct sreg128x2 res;
    struct sreg128 tmp_res, tmp_a;
    struct sreg64 tmp_c;
    int type = INST_T1;

    memcpy(&tmp_a.fixs16, &a->fixs8,  16);
    memcpy(&tmp_a.fixs32, &a->fixs16, 16);
    memcpy(&tmp_a.fixs64, &a->fixs32, 16);
    memcpy(&tmp_a.fixu16, &a->fixu8,  16);
    memcpy(&tmp_a.fixu32, &a->fixu16, 16);
    memcpy(&tmp_a.fixu64, &a->fixu32, 16);

    memcpy(&tmp_c.fixs8,  &c->fixs8,  8);
    memcpy(&tmp_c.fixs16, &c->fixs16, 8);
    memcpy(&tmp_c.fixs32, &c->fixs32, 8);
    memcpy(&tmp_c.fixu8,  &c->fixu8,  8);
    memcpy(&tmp_c.fixu16, &c->fixu16, 8);
    memcpy(&tmp_c.fixu32, &c->fixu32, 8);

    tmp_res.fixs16 = vsubw_s8 (tmp_a.fixs16, tmp_c.fixs8);
    tmp_res.fixs32 = vsubw_s16(tmp_a.fixs32, tmp_c.fixs16);
    tmp_res.fixs64 = vsubw_s32(tmp_a.fixs64, tmp_c.fixs32);
    tmp_res.fixu16 = vsubw_u8 (tmp_a.fixu16, tmp_c.fixu8);
    tmp_res.fixu32 = vsubw_u16(tmp_a.fixu32, tmp_c.fixu16);
    tmp_res.fixu64 = vsubw_u32(tmp_a.fixu64, tmp_c.fixu32);

    memcpy(&res.fixs8.val[0],  &tmp_res.fixs16, 16);
    memcpy(&res.fixs16.val[0], &tmp_res.fixs32, 16);
    memcpy(&res.fixs32.val[0], &tmp_res.fixs64, 16);
    memcpy(&res.fixu8.val[0],  &tmp_res.fixu16, 16);
    memcpy(&res.fixu16.val[0], &tmp_res.fixu32, 16);
    memcpy(&res.fixu32.val[0], &tmp_res.fixu64, 16);

    memcpy(&tmp_a.fixs16, &b->fixs8,  16);
    memcpy(&tmp_a.fixs32, &b->fixs16, 16);
    memcpy(&tmp_a.fixs64, &b->fixs32, 16);
    memcpy(&tmp_a.fixu16, &b->fixu8,  16);
    memcpy(&tmp_a.fixu32, &b->fixu16, 16);
    memcpy(&tmp_a.fixu64, &b->fixu32, 16);

    memcpy(&tmp_c.fixs8,  &c->fixs8[8],  8);
    memcpy(&tmp_c.fixs16, &c->fixs16[4], 8);
    memcpy(&tmp_c.fixs32, &c->fixs32[2], 8);
    memcpy(&tmp_c.fixu8,  &c->fixu8[8],  8);
    memcpy(&tmp_c.fixu16, &c->fixu16[4], 8);
    memcpy(&tmp_c.fixu32, &c->fixu32[2], 8);

    tmp_res.fixs16 = vsubw_s8 (tmp_a.fixs16, tmp_c.fixs8);
    tmp_res.fixs32 = vsubw_s16(tmp_a.fixs32, tmp_c.fixs16);
    tmp_res.fixs64 = vsubw_s32(tmp_a.fixs64, tmp_c.fixs32);
    tmp_res.fixu16 = vsubw_u8 (tmp_a.fixu16, tmp_c.fixu8);
    tmp_res.fixu32 = vsubw_u16(tmp_a.fixu32, tmp_c.fixu16);
    tmp_res.fixu64 = vsubw_u32(tmp_a.fixu64, tmp_c.fixu32);

    memcpy(&res.fixs8.val[1],  &tmp_res.fixs16, 16);
    memcpy(&res.fixs16.val[1], &tmp_res.fixs32, 16);
    memcpy(&res.fixs32.val[1], &tmp_res.fixs64, 16);
    memcpy(&res.fixu8.val[1],  &tmp_res.fixu16, 16);
    memcpy(&res.fixu16.val[1], &tmp_res.fixu32, 16);
    memcpy(&res.fixu32.val[1], &tmp_res.fixu64, 16);

    sprintf(ref_inst, "/* %s - vsub.t.x */", __FUNCTION__);
    print_2_3(__FUNCTION__, &res, a, b, c, type);
}

void vhadd(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T1;

    res.fixs8   = vhaddq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = vhaddq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vhaddq_s32(a->fixs32,  b->fixs32);
    res.fixu8   = vhaddq_u8 (a->fixu8,   b->fixu8);
    res.fixu16  = vhaddq_u16(a->fixu16,  b->fixu16);
    res.fixu32  = vhaddq_u32(a->fixu32,  b->fixu32);

    sprintf(ref_inst, "/* %s - vaddh.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vhsub(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T1;

    res.fixs8   = vhsubq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = vhsubq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vhsubq_s32(a->fixs32,  b->fixs32);
    res.fixu8   = vhsubq_u8 (a->fixu8,   b->fixu8);
    res.fixu16  = vhsubq_u16(a->fixu16,  b->fixu16);
    res.fixu32  = vhsubq_u32(a->fixu32,  b->fixu32);

    sprintf(ref_inst, "/* %s - vsubh.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vrhadd(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T1;

    res.fixs8   = vrhaddq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = vrhaddq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vrhaddq_s32(a->fixs32,  b->fixs32);
    res.fixu8   = vrhaddq_u8 (a->fixu8,   b->fixu8);
    res.fixu16  = vrhaddq_u16(a->fixu16,  b->fixu16);
    res.fixu32  = vrhaddq_u32(a->fixu32,  b->fixu32);

    sprintf(ref_inst, "/* %s - vaddh.t.r */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vrhsub(struct sreg128 *a, struct sreg128 *b)
{
    /* FIXME: can not use arm_neon builtin func. */
    struct sreg128 res;
    int type = INST_T1;
#if 0
    res.fixs8   = myvsubh_s8_r (a->fixs8,   b.fixs8);
    res.fixs16  = myvsubh_s16_r(a->fixs16,  b.fixs16);
    res.fixs32  = myvsubh_s32_r(a->fixs32,  b.fixs32);
    res.fixu8   = myvsubh_u8_r (a->fixu8,   b.fixu8);
    res.fixu16  = myvsubh_u16_r(a->fixu16,  b.fixu16);
    res.fixu32  = myvsubh_u32_r(a->fixu32,  b.fixu32);
#endif
    sprintf(ref_inst, "/* %s - vsubh.t.r */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vpadd(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    struct sreg64 tmp1, tmp2, tmp_res;
    int type = INST_T1;

    memcpy(&tmp1.fixs8,  &a->fixs8,  8);
    memcpy(&tmp1.fixs16, &a->fixs16, 8);
    memcpy(&tmp1.fixs32, &a->fixs32, 8);
    memcpy(&tmp1.fixu8,  &a->fixu8,  8);
    memcpy(&tmp1.fixu16, &a->fixu16, 8);
    memcpy(&tmp1.fixu32, &a->fixu32, 8);
    memcpy(&tmp2.fixs8,  &a->fixs8[8],  8);
    memcpy(&tmp2.fixs16, &a->fixs16[4], 8);
    memcpy(&tmp2.fixs32, &a->fixs32[2], 8);
    memcpy(&tmp2.fixu8,  &a->fixu8[8],  8);
    memcpy(&tmp2.fixu16, &a->fixu16[4], 8);
    memcpy(&tmp2.fixu32, &a->fixu32[2], 8);

    tmp_res.fixs8   = vpadd_s8 (tmp1.fixs8,   tmp2.fixs8);
    tmp_res.fixs16  = vpadd_s16(tmp1.fixs16,  tmp2.fixs16);
    tmp_res.fixs32  = vpadd_s32(tmp1.fixs32,  tmp2.fixs32);
    tmp_res.fixu8   = vpadd_u8 (tmp1.fixu8,   tmp2.fixu8);
    tmp_res.fixu16  = vpadd_u16(tmp1.fixu16,  tmp2.fixu16);
    tmp_res.fixu32  = vpadd_u32(tmp1.fixu32,  tmp2.fixu32);

    memcpy(&res.fixs8,  &tmp_res.fixs8,  8);
    memcpy(&res.fixs16, &tmp_res.fixs16, 8);
    memcpy(&res.fixs32, &tmp_res.fixs32, 8);
    memcpy(&res.fixu8,  &tmp_res.fixu8,  8);
    memcpy(&res.fixu16, &tmp_res.fixu16, 8);
    memcpy(&res.fixu32, &tmp_res.fixu32, 8);

    memcpy(&tmp1.fixs8,  &b->fixs8,  8);
    memcpy(&tmp1.fixs16, &b->fixs16, 8);
    memcpy(&tmp1.fixs32, &b->fixs32, 8);
    memcpy(&tmp1.fixu8,  &b->fixu8,  8);
    memcpy(&tmp1.fixu16, &b->fixu16, 8);
    memcpy(&tmp1.fixu32, &b->fixu32, 8);
    memcpy(&tmp2.fixs8,  &b->fixs8[8],  8);
    memcpy(&tmp2.fixs16, &b->fixs16[4], 8);
    memcpy(&tmp2.fixs32, &b->fixs32[2], 8);
    memcpy(&tmp2.fixu8,  &b->fixu8[8],  8);
    memcpy(&tmp2.fixu16, &b->fixu16[4], 8);
    memcpy(&tmp2.fixu32, &b->fixu32[2], 8);

    tmp_res.fixs8   = vpadd_s8 (tmp1.fixs8,   tmp2.fixs8);
    tmp_res.fixs16  = vpadd_s16(tmp1.fixs16,  tmp2.fixs16);
    tmp_res.fixs32  = vpadd_s32(tmp1.fixs32,  tmp2.fixs32);
    tmp_res.fixu8   = vpadd_u8 (tmp1.fixu8,   tmp2.fixu8);
    tmp_res.fixu16  = vpadd_u16(tmp1.fixu16,  tmp2.fixu16);
    tmp_res.fixu32  = vpadd_u32(tmp1.fixu32,  tmp2.fixu32);

    memcpy(&res.fixs8[8],  &tmp_res.fixs8,  8);
    memcpy(&res.fixs16[4], &tmp_res.fixs16, 8);
    memcpy(&res.fixs32[2], &tmp_res.fixs32, 8);
    memcpy(&res.fixu8[8],  &tmp_res.fixu8,  8);
    memcpy(&res.fixu16[4], &tmp_res.fixu16, 8);
    memcpy(&res.fixu32[2], &tmp_res.fixu32, 8);

    sprintf(ref_inst, "/* %s - vpadd.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vpadd_e(struct sreg128 *a)
{
    struct sreg128 res;
    int type = INST_T1;

    res.fixs16  = vpaddlq_s8 (a->fixs8  );
    res.fixs32  = vpaddlq_s16(a->fixs16 );
    res.fixs64  = vpaddlq_s32(a->fixs32 );
    res.fixu16  = vpaddlq_u8 (a->fixu8  );
    res.fixu32  = vpaddlq_u16(a->fixu16 );
    res.fixu64  = vpaddlq_u32(a->fixu32 );

    memcpy(&res.fixs8,  &res.fixs16, 16);
    memcpy(&res.fixs16, &res.fixs32, 16);
    memcpy(&res.fixs32, &res.fixs64, 16);
    memcpy(&res.fixu8,  &res.fixu16, 16);
    memcpy(&res.fixu16, &res.fixu32, 16);
    memcpy(&res.fixu32, &res.fixu64, 16);

    sprintf(ref_inst, "/* %s - vpadd.t.e */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vpadda_e(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res, tmp_a;
    int type = INST_T1;

    memcpy(&tmp_a.fixs16, &a->fixs8,  16);
    memcpy(&tmp_a.fixs32, &a->fixs16, 16);
    memcpy(&tmp_a.fixs64, &a->fixs32, 16);
    memcpy(&tmp_a.fixu16, &a->fixu8,  16);
    memcpy(&tmp_a.fixu32, &a->fixu16, 16);
    memcpy(&tmp_a.fixu64, &a->fixu32, 16);

    res.fixs16  = vpadalq_s8 (tmp_a.fixs16, b->fixs8 );
    res.fixs32  = vpadalq_s16(tmp_a.fixs32, b->fixs16);
    res.fixs64  = vpadalq_s32(tmp_a.fixs64, b->fixs32);
    res.fixu16  = vpadalq_u8 (tmp_a.fixu16, b->fixu8 );
    res.fixu32  = vpadalq_u16(tmp_a.fixu32, b->fixu16);
    res.fixu64  = vpadalq_u32(tmp_a.fixu64, b->fixu32);

    memcpy(&res.fixs8,  &res.fixs16, 16);
    memcpy(&res.fixs16, &res.fixs32, 16);
    memcpy(&res.fixs32, &res.fixs64, 16);
    memcpy(&res.fixu8,  &res.fixu16, 16);
    memcpy(&res.fixu16, &res.fixu32, 16);
    memcpy(&res.fixu32, &res.fixu64, 16);

    sprintf(ref_inst, "/* %s - vpadda.t.e */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vabs(struct sreg128 *a)
{
    struct sreg128 res;
    int type = INST_T6;

    res.fixs8   = vabsq_s8 (a->fixs8  );
    res.fixs16  = vabsq_s16(a->fixs16 );
    res.fixs32  = vabsq_s32(a->fixs32 );
    res.float32 = vabsq_f32(a->float32);

    sprintf(ref_inst, "/* %s - vabs.t */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vqabs(struct sreg128 *a)
{
    struct sreg128 res;
    int type = INST_T7;

    res.fixs8   = vqabsq_s8 (a->fixs8  );
    res.fixs16  = vqabsq_s16(a->fixs16 );
    res.fixs32  = vqabsq_s32(a->fixs32 );

    sprintf(ref_inst, "/* %s - vabs.t.s */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vabd(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T3;

    res.fixs8   = vabdq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = vabdq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vabdq_s32(a->fixs32,  b->fixs32);
    res.fixu8   = vabdq_u8 (a->fixu8,   b->fixu8);
    res.fixu16  = vabdq_u16(a->fixu16,  b->fixu16);
    res.fixu32  = vabdq_u32(a->fixu32,  b->fixu32);
    res.float32 = vabdq_f32(a->float32, b->float32);

    sprintf(ref_inst, "/* %s - vsabs.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vsabs_t_e(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128x2 res;
    struct sreg64 tmp1, tmp2;
    int type = INST_T1;

    memcpy(&tmp1.fixs8,  &a->fixs8,  8);
    memcpy(&tmp1.fixs16, &a->fixs16, 8);
    memcpy(&tmp1.fixs32, &a->fixs32, 8);
    memcpy(&tmp1.fixu8,  &a->fixu8,  8);
    memcpy(&tmp1.fixu16, &a->fixu16, 8);
    memcpy(&tmp1.fixu32, &a->fixu32, 8);
    memcpy(&tmp2.fixs8,  &b->fixs8,  8);
    memcpy(&tmp2.fixs16, &b->fixs16, 8);
    memcpy(&tmp2.fixs32, &b->fixs32, 8);
    memcpy(&tmp2.fixu8,  &b->fixu8,  8);
    memcpy(&tmp2.fixu16, &b->fixu16, 8);
    memcpy(&tmp2.fixu32, &b->fixu32, 8);

    res.fixs16.val[0] = vabdl_s8 (tmp1.fixs8,  tmp2.fixs8);
    res.fixs32.val[0] = vabdl_s16(tmp1.fixs16, tmp2.fixs16);
    res.fixs64.val[0] = vabdl_s32(tmp1.fixs32, tmp2.fixs32);
    res.fixu16.val[0] = vabdl_u8 (tmp1.fixu8,  tmp2.fixu8);
    res.fixu32.val[0] = vabdl_u16(tmp1.fixu16, tmp2.fixu16);
    res.fixu64.val[0] = vabdl_u32(tmp1.fixu32, tmp2.fixu32);

    memcpy(&res.fixs8.val[0] , &res.fixs16.val[0], 16);
    memcpy(&res.fixs16.val[0], &res.fixs32.val[0], 16);
    memcpy(&res.fixs32.val[0], &res.fixs64.val[0], 16);
    memcpy(&res.fixu8.val[0] , &res.fixu16.val[0], 16);
    memcpy(&res.fixu16.val[0], &res.fixu32.val[0], 16);
    memcpy(&res.fixu32.val[0], &res.fixu64.val[0], 16);

    memcpy(&tmp1.fixs8 , &a->fixs8[8] , 8);
    memcpy(&tmp1.fixs16, &a->fixs16[4], 8);
    memcpy(&tmp1.fixs32, &a->fixs32[2], 8);
    memcpy(&tmp1.fixu8 , &a->fixu8[8] , 8);
    memcpy(&tmp1.fixu16, &a->fixu16[4], 8);
    memcpy(&tmp1.fixu32, &a->fixu32[2], 8);
    memcpy(&tmp2.fixs8 , &b->fixs8[8] , 8);
    memcpy(&tmp2.fixs16, &b->fixs16[4], 8);
    memcpy(&tmp2.fixs32, &b->fixs32[2], 8);
    memcpy(&tmp2.fixu8 , &b->fixu8[8] , 8);
    memcpy(&tmp2.fixu16, &b->fixu16[4], 8);
    memcpy(&tmp2.fixu32, &b->fixu32[2], 8);

    res.fixs16.val[1] = vabdl_s8 (tmp1.fixs8,  tmp2.fixs8);
    res.fixs32.val[1] = vabdl_s16(tmp1.fixs16, tmp2.fixs16);
    res.fixs64.val[1] = vabdl_s32(tmp1.fixs32, tmp2.fixs32);
    res.fixu16.val[1] = vabdl_u8 (tmp1.fixu8,  tmp2.fixu8);
    res.fixu32.val[1] = vabdl_u16(tmp1.fixu16, tmp2.fixu16);
    res.fixu64.val[1] = vabdl_u32(tmp1.fixu32, tmp2.fixu32);

    memcpy(&res.fixs8.val[1] , &res.fixs16.val[1], 16);
    memcpy(&res.fixs16.val[1], &res.fixs32.val[1], 16);
    memcpy(&res.fixs32.val[1], &res.fixs64.val[1], 16);
    memcpy(&res.fixu8.val[1] , &res.fixu16.val[1], 16);
    memcpy(&res.fixu16.val[1], &res.fixu32.val[1], 16);
    memcpy(&res.fixu32.val[1], &res.fixu64.val[1], 16);

    sprintf(ref_inst, "/* %s - vsabs.t.e */", __FUNCTION__);
    print_2_2(__FUNCTION__, &res, a, b, type);
}

void vaba(struct sreg128 *a, struct sreg128 *b, struct sreg128 *c)
{
    struct sreg128 res;
    int type = INST_T1;

    res.fixs8   = vabdq_s8 (a->fixs8,   b->fixs8 );
    res.fixs16  = vabdq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vabdq_s32(a->fixs32,  b->fixs32);
    res.fixu8   = vabdq_u8 (a->fixu8,   b->fixu8 );
    res.fixu16  = vabdq_u16(a->fixu16,  b->fixu16);
    res.fixu32  = vabdq_u32(a->fixu32,  b->fixu32);

    res.fixs8   = vaddq_s8 (res.fixs8  , c->fixs8 );
    res.fixs16  = vaddq_s16(res.fixs16 , c->fixs16);
    res.fixs32  = vaddq_s32(res.fixs32 , c->fixs32);
    res.fixu8   = vaddq_u8 (res.fixu8  , c->fixu8 );
    res.fixu16  = vaddq_u16(res.fixu16 , c->fixu16);
    res.fixu32  = vaddq_u32(res.fixu32 , c->fixu32);



    sprintf(ref_inst, "/* %s - vsabsa.t */", __FUNCTION__);
    print_1_3(__FUNCTION__, &res, a, b, c, type);
}

void vsabsa_t_e(struct sreg128 *a, struct sreg128 *b,
                struct sreg128 *z0, struct sreg128 *z1)
{
    struct sreg128x2 res;
    struct sreg128 tmp_z;
    struct sreg64 tmp1, tmp2;
    int type = INST_T1;

    memcpy(&tmp1.fixs8,  &a->fixs8,  8);
    memcpy(&tmp1.fixs16, &a->fixs16, 8);
    memcpy(&tmp1.fixs32, &a->fixs32, 8);
    memcpy(&tmp1.fixu8,  &a->fixu8,  8);
    memcpy(&tmp1.fixu16, &a->fixu16, 8);
    memcpy(&tmp1.fixu32, &a->fixu32, 8);
    memcpy(&tmp2.fixs8,  &b->fixs8,  8);
    memcpy(&tmp2.fixs16, &b->fixs16, 8);
    memcpy(&tmp2.fixs32, &b->fixs32, 8);
    memcpy(&tmp2.fixu8,  &b->fixu8,  8);
    memcpy(&tmp2.fixu16, &b->fixu16, 8);
    memcpy(&tmp2.fixu32, &b->fixu32, 8);

    res.fixs16.val[0] = vabdl_s8 (tmp1.fixs8,  tmp2.fixs8);
    res.fixs32.val[0] = vabdl_s16(tmp1.fixs16, tmp2.fixs16);
    res.fixs64.val[0] = vabdl_s32(tmp1.fixs32, tmp2.fixs32);
    res.fixu16.val[0] = vabdl_u8 (tmp1.fixu8,  tmp2.fixu8);
    res.fixu32.val[0] = vabdl_u16(tmp1.fixu16, tmp2.fixu16);
    res.fixu64.val[0] = vabdl_u32(tmp1.fixu32, tmp2.fixu32);

    memcpy(&tmp_z.fixs16, &z0->fixs8 , 16);
    memcpy(&tmp_z.fixs32, &z0->fixs16, 16);
    memcpy(&tmp_z.fixs64, &z0->fixs32, 16);
    memcpy(&tmp_z.fixu16, &z0->fixu8 , 16);
    memcpy(&tmp_z.fixu32, &z0->fixu16, 16);
    memcpy(&tmp_z.fixu64, &z0->fixu32, 16);

    res.fixs16.val[0] = vaddq_s16(tmp_z.fixs16, res.fixs16.val[0]);
    res.fixs32.val[0] = vaddq_s32(tmp_z.fixs32, res.fixs32.val[0]);
    res.fixs64.val[0] = vaddq_s64(tmp_z.fixs64, res.fixs64.val[0]);
    res.fixu16.val[0] = vaddq_u16(tmp_z.fixu16, res.fixu16.val[0]);
    res.fixu32.val[0] = vaddq_u32(tmp_z.fixu32, res.fixu32.val[0]);
    res.fixu64.val[0] = vaddq_u64(tmp_z.fixu64, res.fixu64.val[0]);

    memcpy(&res.fixs8.val[0] , &res.fixs16.val[0], 16);
    memcpy(&res.fixs16.val[0], &res.fixs32.val[0], 16);
    memcpy(&res.fixs32.val[0], &res.fixs64.val[0], 16);
    memcpy(&res.fixu8.val[0] , &res.fixu16.val[0], 16);
    memcpy(&res.fixu16.val[0], &res.fixu32.val[0], 16);
    memcpy(&res.fixu32.val[0], &res.fixu64.val[0], 16);

    memcpy(&tmp1.fixs8 , &a->fixs8[8] , 8);
    memcpy(&tmp1.fixs16, &a->fixs16[4], 8);
    memcpy(&tmp1.fixs32, &a->fixs32[2], 8);
    memcpy(&tmp1.fixu8 , &a->fixu8[8] , 8);
    memcpy(&tmp1.fixu16, &a->fixu16[4], 8);
    memcpy(&tmp1.fixu32, &a->fixu32[2], 8);
    memcpy(&tmp2.fixs8 , &b->fixs8[8] , 8);
    memcpy(&tmp2.fixs16, &b->fixs16[4], 8);
    memcpy(&tmp2.fixs32, &b->fixs32[2], 8);
    memcpy(&tmp2.fixu8 , &b->fixu8[8] , 8);
    memcpy(&tmp2.fixu16, &b->fixu16[4], 8);
    memcpy(&tmp2.fixu32, &b->fixu32[2], 8);

    res.fixs16.val[1] = vabdl_s8 (tmp1.fixs8,  tmp2.fixs8);
    res.fixs32.val[1] = vabdl_s16(tmp1.fixs16, tmp2.fixs16);
    res.fixs64.val[1] = vabdl_s32(tmp1.fixs32, tmp2.fixs32);
    res.fixu16.val[1] = vabdl_u8 (tmp1.fixu8,  tmp2.fixu8);
    res.fixu32.val[1] = vabdl_u16(tmp1.fixu16, tmp2.fixu16);
    res.fixu64.val[1] = vabdl_u32(tmp1.fixu32, tmp2.fixu32);

    memcpy(&tmp_z.fixs16, &z1->fixs8 , 16);
    memcpy(&tmp_z.fixs32, &z1->fixs16, 16);
    memcpy(&tmp_z.fixs64, &z1->fixs32, 16);
    memcpy(&tmp_z.fixu16, &z1->fixu8 , 16);
    memcpy(&tmp_z.fixu32, &z1->fixu16, 16);
    memcpy(&tmp_z.fixu64, &z1->fixu32, 16);

    res.fixs16.val[1] = vaddq_s16(tmp_z.fixs16, res.fixs16.val[1]);
    res.fixs32.val[1] = vaddq_s32(tmp_z.fixs32, res.fixs32.val[1]);
    res.fixs64.val[1] = vaddq_s64(tmp_z.fixs64, res.fixs64.val[1]);
    res.fixu16.val[1] = vaddq_u16(tmp_z.fixu16, res.fixu16.val[1]);
    res.fixu32.val[1] = vaddq_u32(tmp_z.fixu32, res.fixu32.val[1]);
    res.fixu64.val[1] = vaddq_u64(tmp_z.fixu64, res.fixu64.val[1]);

    memcpy(&res.fixs8.val[1] , &res.fixs16.val[1], 16);
    memcpy(&res.fixs16.val[1], &res.fixs32.val[1], 16);
    memcpy(&res.fixs32.val[1], &res.fixs64.val[1], 16);
    memcpy(&res.fixu8.val[1] , &res.fixu16.val[1], 16);
    memcpy(&res.fixu16.val[1], &res.fixu32.val[1], 16);
    memcpy(&res.fixu32.val[1], &res.fixu64.val[1], 16);

    sprintf(ref_inst, "/* %s - vsabsa.t.e */", __FUNCTION__);
    print_2_4(__FUNCTION__, &res, a, b, z0, z1, type);
}

void vneg(struct sreg128 *a)
{
    struct sreg128 res;
    int type = INST_T6;

    res.fixs8   = vnegq_s8 (a->fixs8  );
    res.fixs16  = vnegq_s16(a->fixs16 );
    res.fixs32  = vnegq_s32(a->fixs32 );
    res.float32 = vnegq_f32(a->float32);

    sprintf(ref_inst, "/* %s - vneg.t */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vqneg(struct sreg128 *a)
{
    struct sreg128 res;
    int type = INST_T7;

    res.fixs8   = vqnegq_s8 (a->fixs8 );
    res.fixs16  = vqnegq_s16(a->fixs16);
    res.fixs32  = vqnegq_s32(a->fixs32);

    sprintf(ref_inst, "/* %s - vneg.t.s */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vmax(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T3;

    res.fixs8   = vmaxq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = vmaxq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vmaxq_s32(a->fixs32,  b->fixs32);
    res.fixu8   = vmaxq_u8 (a->fixu8,   b->fixu8);
    res.fixu16  = vmaxq_u16(a->fixu16,  b->fixu16);
    res.fixu32  = vmaxq_u32(a->fixu32,  b->fixu32);
    res.float32 = vmaxq_f32(a->float32, b->float32);

    sprintf(ref_inst, "/* %s - vmax.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vmin(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T3;

    res.fixs8   = vminq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = vminq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vminq_s32(a->fixs32,  b->fixs32);
    res.fixu8   = vminq_u8 (a->fixu8,   b->fixu8);
    res.fixu16  = vminq_u16(a->fixu16,  b->fixu16);
    res.fixu32  = vminq_u32(a->fixu32,  b->fixu32);
    res.float32 = vminq_f32(a->float32, b->float32);

    sprintf(ref_inst, "/* %s - vmin.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vpmax(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    struct sreg64 tmp_a, tmp_b, tmp_res;
    int type = INST_T3;

    memcpy(&tmp_a.fixs8,   &a->fixs8,   8);
    memcpy(&tmp_a.fixs16,  &a->fixs16,  8);
    memcpy(&tmp_a.fixs32,  &a->fixs32,  8);
    memcpy(&tmp_a.fixu8,   &a->fixu8,   8);
    memcpy(&tmp_a.fixu16,  &a->fixu16,  8);
    memcpy(&tmp_a.fixu32,  &a->fixu32,  8);
    memcpy(&tmp_a.float32, &a->float32, 8);

    memcpy(&tmp_b.fixs8,   &a->fixs8[8],   8);
    memcpy(&tmp_b.fixs16,  &a->fixs16[4],  8);
    memcpy(&tmp_b.fixs32,  &a->fixs32[2],  8);
    memcpy(&tmp_b.fixu8,   &a->fixu8[8],   8);
    memcpy(&tmp_b.fixu16,  &a->fixu16[4],  8);
    memcpy(&tmp_b.fixu32,  &a->fixu32[2],  8);
    memcpy(&tmp_b.float32, &a->float32[2], 8);

    tmp_res.fixs8   = vpmax_s8 (tmp_a.fixs8,   tmp_b.fixs8);
    tmp_res.fixs16  = vpmax_s16(tmp_a.fixs16,  tmp_b.fixs16);
    tmp_res.fixs32  = vpmax_s32(tmp_a.fixs32,  tmp_b.fixs32);
    tmp_res.fixu8   = vpmax_u8 (tmp_a.fixu8,   tmp_b.fixu8);
    tmp_res.fixu16  = vpmax_u16(tmp_a.fixu16,  tmp_b.fixu16);
    tmp_res.fixu32  = vpmax_u32(tmp_a.fixu32,  tmp_b.fixu32);
    tmp_res.float32 = vpmax_f32(tmp_a.float32, tmp_b.float32);

    memcpy(&res.fixs8[0],   &tmp_res.fixs8,   8);
    memcpy(&res.fixs16[0],  &tmp_res.fixs16,  8);
    memcpy(&res.fixs32[0],  &tmp_res.fixs32,  8);
    memcpy(&res.fixu8[0],   &tmp_res.fixu8,   8);
    memcpy(&res.fixu16[0],  &tmp_res.fixu16,  8);
    memcpy(&res.fixu32[0],  &tmp_res.fixu32,  8);
    memcpy(&res.float32[0], &tmp_res.float32, 8);

    memcpy(&tmp_a.fixs8,   &b->fixs8,   8);
    memcpy(&tmp_a.fixs16,  &b->fixs16,  8);
    memcpy(&tmp_a.fixs32,  &b->fixs32,  8);
    memcpy(&tmp_a.fixu8,   &b->fixu8,   8);
    memcpy(&tmp_a.fixu16,  &b->fixu16,  8);
    memcpy(&tmp_a.fixu32,  &b->fixu32,  8);
    memcpy(&tmp_a.float32, &b->float32, 8);

    memcpy(&tmp_b.fixs8,   &b->fixs8[8],   8);
    memcpy(&tmp_b.fixs16,  &b->fixs16[4],  8);
    memcpy(&tmp_b.fixs32,  &b->fixs32[2],  8);
    memcpy(&tmp_b.fixu8,   &b->fixu8[8],   8);
    memcpy(&tmp_b.fixu16,  &b->fixu16[4],  8);
    memcpy(&tmp_b.fixu32,  &b->fixu32[2],  8);
    memcpy(&tmp_b.float32, &b->float32[2], 8);

    tmp_res.fixs8   = vpmax_s8 (tmp_a.fixs8,   tmp_b.fixs8);
    tmp_res.fixs16  = vpmax_s16(tmp_a.fixs16,  tmp_b.fixs16);
    tmp_res.fixs32  = vpmax_s32(tmp_a.fixs32,  tmp_b.fixs32);
    tmp_res.fixu8   = vpmax_u8 (tmp_a.fixu8,   tmp_b.fixu8);
    tmp_res.fixu16  = vpmax_u16(tmp_a.fixu16,  tmp_b.fixu16);
    tmp_res.fixu32  = vpmax_u32(tmp_a.fixu32,  tmp_b.fixu32);
    tmp_res.float32 = vpmax_f32(tmp_a.float32, tmp_b.float32);

    memcpy(&res.fixs8[8],   &tmp_res.fixs8,   8);
    memcpy(&res.fixs16[4],  &tmp_res.fixs16,  8);
    memcpy(&res.fixs32[2],  &tmp_res.fixs32,  8);
    memcpy(&res.fixu8[8],   &tmp_res.fixu8,   8);
    memcpy(&res.fixu16[4],  &tmp_res.fixu16,  8);
    memcpy(&res.fixu32[2],  &tmp_res.fixu32,  8);
    memcpy(&res.float32[2], &tmp_res.float32, 8);

    sprintf(ref_inst, "/* %s - vpmax.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vpmin(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    struct sreg64 tmp_a, tmp_b, tmp_res;
    int type = INST_T3;

    memcpy(&tmp_a.fixs8,   &a->fixs8,   8);
    memcpy(&tmp_a.fixs16,  &a->fixs16,  8);
    memcpy(&tmp_a.fixs32,  &a->fixs32,  8);
    memcpy(&tmp_a.fixu8,   &a->fixu8,   8);
    memcpy(&tmp_a.fixu16,  &a->fixu16,  8);
    memcpy(&tmp_a.fixu32,  &a->fixu32,  8);
    memcpy(&tmp_a.float32, &a->float32, 8);

    memcpy(&tmp_b.fixs8,   &a->fixs8[8],   8);
    memcpy(&tmp_b.fixs16,  &a->fixs16[4],  8);
    memcpy(&tmp_b.fixs32,  &a->fixs32[2],  8);
    memcpy(&tmp_b.fixu8,   &a->fixu8[8],   8);
    memcpy(&tmp_b.fixu16,  &a->fixu16[4],  8);
    memcpy(&tmp_b.fixu32,  &a->fixu32[2],  8);
    memcpy(&tmp_b.float32, &a->float32[2], 8);

    tmp_res.fixs8   = vpmin_s8 (tmp_a.fixs8,   tmp_b.fixs8);
    tmp_res.fixs16  = vpmin_s16(tmp_a.fixs16,  tmp_b.fixs16);
    tmp_res.fixs32  = vpmin_s32(tmp_a.fixs32,  tmp_b.fixs32);
    tmp_res.fixu8   = vpmin_u8 (tmp_a.fixu8,   tmp_b.fixu8);
    tmp_res.fixu16  = vpmin_u16(tmp_a.fixu16,  tmp_b.fixu16);
    tmp_res.fixu32  = vpmin_u32(tmp_a.fixu32,  tmp_b.fixu32);
    tmp_res.float32 = vpmin_f32(tmp_a.float32, tmp_b.float32);

    memcpy(&res.fixs8[0],   &tmp_res.fixs8,   8);
    memcpy(&res.fixs16[0],  &tmp_res.fixs16,  8);
    memcpy(&res.fixs32[0],  &tmp_res.fixs32,  8);
    memcpy(&res.fixu8[0],   &tmp_res.fixu8,   8);
    memcpy(&res.fixu16[0],  &tmp_res.fixu16,  8);
    memcpy(&res.fixu32[0],  &tmp_res.fixu32,  8);
    memcpy(&res.float32[0], &tmp_res.float32, 8);

    memcpy(&tmp_a.fixs8,   &b->fixs8,   8);
    memcpy(&tmp_a.fixs16,  &b->fixs16,  8);
    memcpy(&tmp_a.fixs32,  &b->fixs32,  8);
    memcpy(&tmp_a.fixu8,   &b->fixu8,   8);
    memcpy(&tmp_a.fixu16,  &b->fixu16,  8);
    memcpy(&tmp_a.fixu32,  &b->fixu32,  8);
    memcpy(&tmp_a.float32, &b->float32, 8);

    memcpy(&tmp_b.fixs8,   &b->fixs8[8],   8);
    memcpy(&tmp_b.fixs16,  &b->fixs16[4],  8);
    memcpy(&tmp_b.fixs32,  &b->fixs32[2],  8);
    memcpy(&tmp_b.fixu8,   &b->fixu8[8],   8);
    memcpy(&tmp_b.fixu16,  &b->fixu16[4],  8);
    memcpy(&tmp_b.fixu32,  &b->fixu32[2],  8);
    memcpy(&tmp_b.float32, &b->float32[2], 8);

    tmp_res.fixs8   = vpmin_s8 (tmp_a.fixs8,   tmp_b.fixs8);
    tmp_res.fixs16  = vpmin_s16(tmp_a.fixs16,  tmp_b.fixs16);
    tmp_res.fixs32  = vpmin_s32(tmp_a.fixs32,  tmp_b.fixs32);
    tmp_res.fixu8   = vpmin_u8 (tmp_a.fixu8,   tmp_b.fixu8);
    tmp_res.fixu16  = vpmin_u16(tmp_a.fixu16,  tmp_b.fixu16);
    tmp_res.fixu32  = vpmin_u32(tmp_a.fixu32,  tmp_b.fixu32);
    tmp_res.float32 = vpmin_f32(tmp_a.float32, tmp_b.float32);

    memcpy(&res.fixs8[8],   &tmp_res.fixs8,   8);
    memcpy(&res.fixs16[4],  &tmp_res.fixs16,  8);
    memcpy(&res.fixs32[2],  &tmp_res.fixs32,  8);
    memcpy(&res.fixu8[8],   &tmp_res.fixu8,   8);
    memcpy(&res.fixu16[4],  &tmp_res.fixu16,  8);
    memcpy(&res.fixu32[2],  &tmp_res.fixu32,  8);
    memcpy(&res.float32[2], &tmp_res.float32, 8);

    sprintf(ref_inst, "/* %s - vpmin.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vcmpnez(struct sreg128 *a)
{
    struct sreg128 res, b;
    int type = INST_T6;

    memset(&b, 0, sizeof(struct sreg128));

    res.fixs8   = (int8x16_t)vceqq_s8 (a->fixs8,   b.fixs8);
    res.fixs16  = (int16x8_t)vceqq_s16(a->fixs16,  b.fixs16);
    res.fixs32  = (int32x4_t)vceqq_s32(a->fixs32,  b.fixs32);
    res.float32 = (float32x4_t)vceqq_f32(a->float32, b.float32);

    sprintf(ref_inst, "/* %s - vcmpnez.t */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vceq(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T6;

    res.fixs8   = (int8x16_t)vceqq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = (int16x8_t)vceqq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = (int32x4_t)vceqq_s32(a->fixs32,  b->fixs32);
    res.fixu8   = vceqq_u8 (a->fixu8,   b->fixu8);
    res.fixu16  = vceqq_u16(a->fixu16,  b->fixu16);
    res.fixu32  = vceqq_u32(a->fixu32,  b->fixu32);
    res.float32 = (float32x4_t)vceqq_f32(a->float32, b->float32);

    sprintf(ref_inst, "/* %s - vcmpne.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vcmphsz(struct sreg128 *a)
{
    struct sreg128 res, b;
    int type = INST_T6;

    memset(&b, 0, sizeof(struct sreg128));

    res.fixs8   = (int8x16_t)vcgeq_s8 (a->fixs8,   b.fixs8);
    res.fixs16  = (int16x8_t)vcgeq_s16(a->fixs16,  b.fixs16);
    res.fixs32  = (int32x4_t)vcgeq_s32(a->fixs32,  b.fixs32);
    res.float32 = (float32x4_t)vcgeq_f32(a->float32, b.float32);

    sprintf(ref_inst, "/* %s - vcmphsz.t */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vcge(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T3;

    res.fixs8   = (int8x16_t)vcgeq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = (int16x8_t)vcgeq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = (int32x4_t)vcgeq_s32(a->fixs32,  b->fixs32);
    res.fixu8   = vcgeq_u8 (a->fixu8,   b->fixu8);
    res.fixu16  = vcgeq_u16(a->fixu16,  b->fixu16);
    res.fixu32  = vcgeq_u32(a->fixu32,  b->fixu32);
    res.float32 = (float32x4_t)vcgeq_f32(a->float32, b->float32);

    sprintf(ref_inst, "/* %s - vcmphs.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

//void vcle(struct sreg128 *a, struct sreg128 *b)
//{
//    struct sreg128 res;
//    int type = INST_T3;
//
//    res.fixs8   = (int8x16_t)vcleq_s8 (a->fixs8,   b->fixs8);
//    res.fixs16  = (int16x8_t)vcleq_s16(a->fixs16,  b->fixs16);
//    res.fixs32  = (int32x4_t)vcleq_s32(a->fixs32,  b->fixs32);
//    res.fixu8   = vcleq_u8 (a->fixu8,   b->fixu8);
//    res.fixu16  = vcleq_u16(a->fixu16,  b->fixu16);
//    res.fixu32  = vcleq_u32(a->fixu32,  b->fixu32);
//    res.float32 = (float32x4_t)vcleq_f32(a->float32, b->float32);
//
//    print_1_2(__FUNCTION__, &res, a, b, type);
//}
//
//void vcgt(struct sreg128 *a, struct sreg128 *b)
//{
//    struct sreg128 res;
//    int type = INST_T3;
//
//    res.fixs8   = (int8x16_t)vcgtq_s8 (a->fixs8,   b->fixs8);
//    res.fixs16  = (int16x8_t)vcgtq_s16(a->fixs16,  b->fixs16);
//    res.fixs32  = (int32x4_t)vcgtq_s32(a->fixs32,  b->fixs32);
//    res.fixu8   = vcgtq_u8 (a->fixu8,   b->fixu8);
//    res.fixu16  = vcgtq_u16(a->fixu16,  b->fixu16);
//    res.fixu32  = vcgtq_u32(a->fixu32,  b->fixu32);
//    res.float32 = (float32x4_t)vcgtq_f32(a->float32, b->float32);
//
//    print_1_2(__FUNCTION__, &res, a, b, type);
//}

void vcmpltz(struct sreg128 *a)
{
    struct sreg128 res, b;
    int type = INST_T6;

    memset(&b, 0, sizeof(struct sreg128));

    res.fixs8   = (int8x16_t)vcltq_s8 (a->fixs8,   b.fixs8);
    res.fixs16  = (int16x8_t)vcltq_s16(a->fixs16,  b.fixs16);
    res.fixs32  = (int32x4_t)vcltq_s32(a->fixs32,  b.fixs32);
    res.float32 = (float32x4_t)vcltq_f32(a->float32, b.float32);

    sprintf(ref_inst, "/* %s - vcmpltz.t */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vclt(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T3;

    res.fixs8   = (int8x16_t)vcltq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = (int16x8_t)vcltq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = (int32x4_t)vcltq_s32(a->fixs32,  b->fixs32);
    res.fixu8   = vcltq_u8 (a->fixu8,   b->fixu8);
    res.fixu16  = vcltq_u16(a->fixu16,  b->fixu16);
    res.fixu32  = vcltq_u32(a->fixu32,  b->fixu32);
    res.float32 = (float32x4_t)vcltq_f32(a->float32, b->float32);

    sprintf(ref_inst, "/* %s - vcmplt.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vcmphz(struct sreg128 *a)
{
    struct sreg128 res, b;
    int type = INST_T6;

    memset(&b, 0, sizeof(struct sreg128));

    res.fixs8   = (int8x16_t)vcgtq_s8 (a->fixs8,   b.fixs8);
    res.fixs16  = (int16x8_t)vcgtq_s16(a->fixs16,  b.fixs16);
    res.fixs32  = (int32x4_t)vcgtq_s32(a->fixs32,  b.fixs32);
    res.float32 = (float32x4_t)vcgtq_f32(a->float32, b.float32);

    sprintf(ref_inst, "/* %s - vcmphz.t */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vcmplsz(struct sreg128 *a)
{
    struct sreg128 res, b;
    int type = INST_T6;

    memset(&b, 0, sizeof(struct sreg128));

    res.fixs8   = (int8x16_t)vcleq_s8 (a->fixs8,   b.fixs8);
    res.fixs16  = (int16x8_t)vcleq_s16(a->fixs16,  b.fixs16);
    res.fixs32  = (int32x4_t)vcleq_s32(a->fixs32,  b.fixs32);
    res.float32 = (float32x4_t)vcleq_f32(a->float32, b.float32);

    sprintf(ref_inst, "/* %s - vcmplsz.t */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}


/* MUL/DIV instructions. */
void vmul(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T3;

    res.fixs8   = vmulq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = vmulq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vmulq_s32(a->fixs32,  b->fixs32);
    res.fixu8   = vmulq_u8 (a->fixu8,   b->fixu8);
    res.fixu16  = vmulq_u16(a->fixu16,  b->fixu16);
    res.fixu32  = vmulq_u32(a->fixu32,  b->fixu32);
    res.float32 = vmulq_f32(a->float32, b->float32);

    sprintf(ref_inst, "/* %s - vmul.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vmulq_n(struct sreg128 *a)
{
    struct sreg128 res;
    int type = INST_T10;

    res.fixs16 = vmulq_n_s16(a->fixs16, 3);
    res.fixs32 = vmulq_n_s32(a->fixs32, 3);
    res.fixu16 = vmulq_n_u16(a->fixu16, 3);
    res.fixu32 = vmulq_n_u32(a->fixu32, 3);
    res.float32 = vmulq_n_f32(a->float32, 3);

    sprintf(ref_inst, "/* %s - vmuli.t */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vmla(struct sreg128 *a, struct sreg128 *b, struct sreg128 *c)
{
    struct sreg128 res;
    int type = INST_T3;

    res.fixs8   = vmlaq_s8 (a->fixs8,   b->fixs8  , c->fixs8);
    res.fixs16  = vmlaq_s16(a->fixs16,  b->fixs16 , c->fixs16);
    res.fixs32  = vmlaq_s32(a->fixs32,  b->fixs32 , c->fixs32);
    res.fixu8   = vmlaq_u8 (a->fixu8,   b->fixu8  , c->fixu8);
    res.fixu16  = vmlaq_u16(a->fixu16,  b->fixu16 , c->fixu16);
    res.fixu32  = vmlaq_u32(a->fixu32,  b->fixu32 , c->fixu32);
    res.float32 = vmlaq_f32(a->float32, b->float32, c->float32);

    sprintf(ref_inst, "/* %s - vmula.t */", __FUNCTION__);
    print_1_3(__FUNCTION__, &res, a, b, c, type);
}

void vmla_lane(struct sreg128 *a, struct sreg128 *b, struct sreg128 *c)
{
    struct sreg128 res;
    int type = INST_T10;

    res.fixs16  = vmlaq_lane_s16(a->fixs16, b->fixs16,
                                 *(int16x4_t *)&c->fixs16,
                                 1);
    res.fixs32  = vmlaq_lane_s32(a->fixs32, b->fixs32,
                                 *(int32x2_t *)&c->fixs32,
                                 1);
    res.fixu16  = vmlaq_lane_u16(a->fixu16, b->fixu16,
                                 *(uint16x4_t *)&c->fixu16,
                                 1);
    res.fixu32  = vmlaq_lane_u32(a->fixu32, b->fixu32,
                                 *(uint32x2_t *)&c->fixu32,
                                 1);
    res.float32 = vmlaq_lane_f32(a->float32, b->float32,
                                 *(float32x2_t *)&c->float32,
                                 1);

    sprintf(ref_inst, "/* %s - vmulai.t */", __FUNCTION__);
    print_1_3(__FUNCTION__, &res, a, b, c, type);
}
//void vmul_lane(struct sreg128 *a, struct sreg128 *b, struct sreg128 *c)
//{
//    struct sreg128 res;
//    int type = INST_T10;
//
//    res.fixs16  = vmulq_lane_s16(a->fixs16, b->fixs16, (const int)c->fixs16[0]);
//    res.fixs32  = vmulq_lane_s32(a->fixs32, b->fixs32, (const int)c->fixs32[0]);
//    res.fixu16  = vmulq_lane_u16(a->fixu16, b->fixu16, (const int)c->fixu16[0]);
//    res.fixu32  = vmulq_lane_u32(a->fixu32, b->fixu32, (const int)c->fixu32[0]);
//    res.float32 = vmulq_lane_f32(a->float32, b->float32,
//                                 (const int)c->float32[0]);
//
//    sprintf(ref_inst, "/* %s - vmuli.t.r */", __FUNCTION__);
//    print_1_3(__FUNCTION__, &res, a, b, c, type);
//}

//void vmla_n(struct sreg128 *a, struct sreg128 *b, struct sreg128 *c)
//{
//    struct sreg128 res;
//    int type = INST_T10;
//
//    res.fixs16  = vmlaq_n_s16(a->fixs16, b->fixs16, (const int)c->fixs16[0]);
//    res.fixs32  = vmlaq_n_s32(a->fixs32, b->fixs32, (const int)c->fixs32[0]);
//    res.fixu16  = vmlaq_n_u16(a->fixu16, b->fixu16, (const int)c->fixu16[0]);
//    res.fixu32  = vmlaq_n_u32(a->fixu32, b->fixu32, (const int)c->fixu32[0]);
//    res.float32 = vmlaq_n_f32(a->float32, b->float32,
//                                 (const int)c->float32[0]);
//
//    sprintf(ref_inst, "/* %s - vmulai.t */", __FUNCTION__);
//    print_1_3(__FUNCTION__, &res, a, b, c, type);
//}

void vmls(struct sreg128 *a, struct sreg128 *b, struct sreg128 *c)
{
    struct sreg128 res;
    int type = INST_T3;

    res.fixs8   = vmlsq_s8 (a->fixs8,   b->fixs8  , c->fixs8);
    res.fixs16  = vmlsq_s16(a->fixs16,  b->fixs16 , c->fixs16);
    res.fixs32  = vmlsq_s32(a->fixs32,  b->fixs32 , c->fixs32);
    res.fixu8   = vmlsq_u8 (a->fixu8,   b->fixu8  , c->fixu8);
    res.fixu16  = vmlsq_u16(a->fixu16,  b->fixu16 , c->fixu16);
    res.fixu32  = vmlsq_u32(a->fixu32,  b->fixu32 , c->fixu32);
    res.float32 = vmlsq_f32(a->float32, b->float32, c->float32);

    sprintf(ref_inst, "/* %s - vmuls.t */", __FUNCTION__);
    print_1_3(__FUNCTION__, &res, a, b, c, type);
}

void vmls_lane(struct sreg128 *a, struct sreg128 *b, struct sreg128 *c)
{
    struct sreg128 res;
    int type = INST_T10;

    res.fixs16  = vmlsq_lane_s16(a->fixs16, b->fixs16,
                                *(int16x4_t *)&c->fixs16,
                                1);
    res.fixs32  = vmlsq_lane_s32(a->fixs32, b->fixs32,
                                *(int32x2_t *)&c->fixs32,
                                1);
    res.fixu16  = vmlsq_lane_u16(a->fixu16, b->fixu16,
                                *(uint16x4_t *)&c->fixu16,
                                1);
    res.fixu32  = vmlsq_lane_u32(a->fixu32, b->fixu32,
                                 *(uint32x2_t *)&c->fixu32,
                                1);
    res.float32 = vmlsq_lane_f32(a->float32, b->float32,
                                 *(float32x2_t *)&c->float32,
                                 1);

    sprintf(ref_inst, "/* %s - vmulsi.t */", __FUNCTION__);
    print_1_3(__FUNCTION__, &res, a, b, c, type);
}

//void vmls_n(struct sreg128 *a, struct sreg128 *b, struct sreg128 *c)
//{
//    struct sreg128 res;
//    int type = INST_T10;
//
//    res.fixs16  = vmlsq_n_s16(a->fixs16, b->fixs16, (const int)c->fixs16[0]);
//    res.fixs32  = vmlsq_n_s32(a->fixs32, b->fixs32, (const int)c->fixs32[0]);
//    res.fixu16  = vmlsq_n_u16(a->fixu16, b->fixu16, (const int)c->fixu16[0]);
//    res.fixu32  = vmlsq_n_u32(a->fixu32, b->fixu32, (const int)c->fixu32[0]);
//    res.float32 = vmlsq_n_f32(a->float32, b->float32,
//                                 (const int)c->float32[0]);
//
//    sprintf(ref_inst, "/* %s - vmulsi.t */", __FUNCTION__);
//    print_1_3(__FUNCTION__, &res, a, b, c, type);
//}

void vqdmulh(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T4;

    res.fixs16  = vqdmulhq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vqdmulhq_s32(a->fixs32,  b->fixs32);

    sprintf(ref_inst, "/* %s - vrmulh.t.s */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vqrdmulh(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T4;

    res.fixs16  = vqrdmulhq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vqrdmulhq_s32(a->fixs32,  b->fixs32);

    sprintf(ref_inst, "/* %s - vrmulh.t.rs */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vfma(struct sreg128 *a, struct sreg128 *b, struct sreg128 *c)
{
    struct sreg128 res;
    int type = INST_T5;

    sprintf(ref_inst, "/* %s - vfmula.t */", __FUNCTION__);
    res.float32 = vfmaq_f32(a->float32, b->float32, c->float32);

    print_1_3(__FUNCTION__, &res, a, b, c, type);
}

void vfms(struct sreg128 *a, struct sreg128 *b, struct sreg128 *c)
{
    struct sreg128 res;
    int type = INST_T5;

    res.float32 = vfmsq_f32(a->float32, b->float32, c->float32);

    sprintf(ref_inst, "/* %s - vfmuls.t */", __FUNCTION__);
    print_1_3(__FUNCTION__, &res, a, b, c, type);
}

/* SHIFT instructions. */
void vshl(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T2;

    res.fixs8   = vshlq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = vshlq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vshlq_s32(a->fixs32,  b->fixs32);
    res.fixs64  = vshlq_s64(a->fixs64,  b->fixs64);
    res.fixu8   = vshlq_u8 (a->fixu8,   (int8x16_t)b->fixu8);
    res.fixu16  = vshlq_u16(a->fixu16,  (int16x8_t)b->fixu16);
    res.fixu32  = vshlq_u32(a->fixu32,  (int32x4_t)b->fixu32);
    res.fixu64  = vshlq_u64(a->fixu64,  (int64x2_t)b->fixu64);

    sprintf(ref_inst, "/* %s - vsht.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vqshl(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T2;

    res.fixs8   = vqshlq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = vqshlq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vqshlq_s32(a->fixs32,  b->fixs32);
    res.fixs64  = vqshlq_s64(a->fixs64,  b->fixs64);
    res.fixu8   = vqshlq_u8 (a->fixu8,   (int8x16_t)b->fixu8);
    res.fixu16  = vqshlq_u16(a->fixu16,  (int16x8_t)b->fixu16);
    res.fixu32  = vqshlq_u32(a->fixu32,  (int32x4_t)b->fixu32);
    res.fixu64  = vqshlq_u64(a->fixu64,  (int64x2_t)b->fixu64);

    sprintf(ref_inst, "/* %s - vsht.t.s */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vrshl(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T2;

    res.fixs8   = vrshlq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = vrshlq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vrshlq_s32(a->fixs32,  b->fixs32);
    res.fixs64  = vrshlq_s64(a->fixs64,  b->fixs64);
    res.fixu8   = vrshlq_u8 (a->fixu8,   (int8x16_t)b->fixu8);
    res.fixu16  = vrshlq_u16(a->fixu16,  (int16x8_t)b->fixu16);
    res.fixu32  = vrshlq_u32(a->fixu32,  (int32x4_t)b->fixu32);
    res.fixu64  = vrshlq_u64(a->fixu64,  (int64x2_t)b->fixu64);

    sprintf(ref_inst, "/* %s - vsht.t.r */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vqrshl(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T2;

    res.fixs8   = vqrshlq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = vqrshlq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vqrshlq_s32(a->fixs32,  b->fixs32);
    res.fixs64  = vqrshlq_s64(a->fixs64,  b->fixs64);
    res.fixu8   = vqrshlq_u8 (a->fixu8,   (int8x16_t)b->fixu8);
    res.fixu16  = vqrshlq_u16(a->fixu16,  (int16x8_t)b->fixu16);
    res.fixu32  = vqrshlq_u32(a->fixu32,  (int32x4_t)b->fixu32);
    res.fixu64  = vqrshlq_u64(a->fixu64,  (int64x2_t)b->fixu64);

    sprintf(ref_inst, "/* %s - vsht.t.rs */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

//void vshr(struct sreg128 *a, struct sreg128 *b)
//{
//	struct sreg128 res;
//	int type = INST_T2;
//
//	res.fixs8   = vshrq_s8 (a->fixs8,   b->fixs8);
//	res.fixs16  = vshrq_s16(a->fixs16,  b->fixs16);
//	res.fixs32  = vshrq_s32(a->fixs32,  b->fixs32);
//	res.fixs64  = vshrq_s64(a->fixs64,  b->fixs64);
//	res.fixu8   = vshrq_u8 (a->fixu8,   b->fixu8);
//	res.fixu16  = vshrq_u16(a->fixu16,  b->fixu16);
//	res.fixu32  = vshrq_u32(a->fixu32,  b->fixu32);
//	res.fixu64  = vshrq_u64(a->fixu64,  b->fixu64);
//
//	print_1_2(__FUNCTION__, &res, a, b, type);
//}

void vshl_n(struct sreg128 *a)
{
    struct sreg128 res;
    int type = INST_T2;

    res.fixs8  = vshlq_n_s8 (a->fixs8,  3);
    res.fixs16 = vshlq_n_s16(a->fixs16, 3);
    res.fixs32 = vshlq_n_s32(a->fixs32, 3);
    res.fixs64 = vshlq_n_s64(a->fixs64, 3);
    res.fixu8  = vshlq_n_u8 (a->fixu8,  3);
    res.fixu16 = vshlq_n_u16(a->fixu16, 3);
    res.fixu32 = vshlq_n_u32(a->fixu32, 3);
    res.fixu64 = vshlq_n_u64(a->fixu64, 3);

    sprintf(ref_inst, "/* %s - vshli.t */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vqshl_n(struct sreg128 *a)
{
    struct sreg128 res;
    int type = INST_T2;

    res.fixs8  = vqshlq_n_s8 (a->fixs8,  3);
    res.fixs16 = vqshlq_n_s16(a->fixs16, 3);
    res.fixs32 = vqshlq_n_s32(a->fixs32, 3);
    res.fixs64 = vqshlq_n_s64(a->fixs64, 3);
    res.fixu8  = vqshlq_n_u8 (a->fixu8,  3);
    res.fixu16 = vqshlq_n_u16(a->fixu16, 3);
    res.fixu32 = vqshlq_n_u32(a->fixu32, 3);
    res.fixu64 = vqshlq_n_u64(a->fixu64, 3);

    sprintf(ref_inst, "/* %s - vshli.t.s */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vqshlu_n(struct sreg128 *a)
{
    struct sreg128 res;
    int type = INST_T11;

    res.fixs8  = (int8x16_t)vqshluq_n_s8 (a->fixs8,  3);
    res.fixs16 = (int16x8_t)vqshluq_n_s16(a->fixs16, 3);
    res.fixs32 = (int32x4_t)vqshluq_n_s32(a->fixs32, 3);
    res.fixs64 = (int64x2_t)vqshluq_n_s64(a->fixs64, 3);

    sprintf(ref_inst, "/* %s - vshli.t.s */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vshr_n(struct sreg128 *a)
{
    struct sreg128 res;
    int type = INST_T2;

    res.fixs8  = vshrq_n_s8 (a->fixs8,  3);
    res.fixs16 = vshrq_n_s16(a->fixs16, 3);
    res.fixs32 = vshrq_n_s32(a->fixs32, 3);
    res.fixs64 = vshrq_n_s64(a->fixs64, 3);
    res.fixu8  = vshrq_n_u8 (a->fixu8,  3);
    res.fixu16 = vshrq_n_u16(a->fixu16, 3);
    res.fixu32 = vshrq_n_u32(a->fixu32, 3);
    res.fixu64 = vshrq_n_u64(a->fixu64, 3);
    sprintf(ref_inst, "/* %s - vshri.t */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vrshr_n(struct sreg128 *a)
{
    struct sreg128 res;
    int type = INST_T2;

    res.fixs8  = vrshrq_n_s8 (a->fixs8,  3);
    res.fixs16 = vrshrq_n_s16(a->fixs16, 3);
    res.fixs32 = vrshrq_n_s32(a->fixs32, 3);
    res.fixs64 = vrshrq_n_s64(a->fixs64, 3);
    res.fixu8  = vrshrq_n_u8 (a->fixu8,  3);
    res.fixu16 = vrshrq_n_u16(a->fixu16, 3);
    res.fixu32 = vrshrq_n_u32(a->fixu32, 3);
    res.fixu64 = vrshrq_n_u64(a->fixu64, 3);

    sprintf(ref_inst, "/* %s - vshri.t.r */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vsra_n(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T2;

    res.fixs8  = vsraq_n_s8 (a->fixs8,  b->fixs8,  3);
    res.fixs16 = vsraq_n_s16(a->fixs16, b->fixs16, 3);
    res.fixs32 = vsraq_n_s32(a->fixs32, b->fixs32, 3);
    res.fixs64 = vsraq_n_s64(a->fixs64, b->fixs64, 3);
    res.fixu8  = vsraq_n_u8 (a->fixu8,  b->fixu8,  3);
    res.fixu16 = vsraq_n_u16(a->fixu16, b->fixu16, 3);
    res.fixu32 = vsraq_n_u32(a->fixu32, b->fixu32, 3);
    res.fixu64 = vsraq_n_u64(a->fixu64, b->fixu64, 3);

    sprintf(ref_inst, "/* %s - vshria.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vrsra_n(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T2;

    res.fixs8  = vrsraq_n_s8 (a->fixs8,  b->fixs8,  3);
    res.fixs16 = vrsraq_n_s16(a->fixs16, b->fixs16, 3);
    res.fixs32 = vrsraq_n_s32(a->fixs32, b->fixs32, 3);
    res.fixs64 = vrsraq_n_s64(a->fixs64, b->fixs64, 3);
    res.fixu8  = vrsraq_n_u8 (a->fixu8,  b->fixu8,  3);
    res.fixu16 = vrsraq_n_u16(a->fixu16, b->fixu16, 3);
    res.fixu32 = vrsraq_n_u32(a->fixu32, b->fixu32, 3);
    res.fixu64 = vrsraq_n_u64(a->fixu64, b->fixu64, 3);

    sprintf(ref_inst, "/* %s - vshria.t.r */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vext(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T2;

    res.fixs8  = vextq_s8 (a->fixs8,  b->fixs8,  1);
    res.fixs16 = vextq_s16(a->fixs16, b->fixs16, 1);
    res.fixs32 = vextq_s32(a->fixs32, b->fixs32, 1);
    res.fixs64 = vextq_s64(a->fixs64, b->fixs64, 1);
    res.fixu8  = vextq_u8 (a->fixu8,  b->fixu8,  1);
    res.fixu16 = vextq_u16(a->fixu16, b->fixu16, 1);
    res.fixu32 = vextq_u32(a->fixu32, b->fixu32, 1);
    res.fixu64 = vextq_u64(a->fixu64, b->fixu64, 1);
    res.float32 = vextq_f32(a->float32, b->float32, 1);

    sprintf(ref_inst, "/* %s - vext.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

/* MOVE/SWAP/BIT instructions. */
void vtrn(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128x2 res;
    int type = INST_T3;

    res.fixs8   = vtrnq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = vtrnq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vtrnq_s32(a->fixs32,  b->fixs32);
    res.fixu8   = vtrnq_u8 (a->fixu8,   b->fixu8);
    res.fixu16  = vtrnq_u16(a->fixu16,  b->fixu16);
    res.fixu32  = vtrnq_u32(a->fixu32,  b->fixu32);
    res.float32 = vtrnq_f32(a->float32, b->float32);

    sprintf(ref_inst, "/* %s - vtrn.t */", __FUNCTION__);
    print_2_2(__FUNCTION__, &res, a, b, type);
}

void vrev16(struct sreg128 *a)
{
    struct sreg128 res;
    int type = INST_T8;

    res.fixs8   = vrev16q_s8 (a->fixs8);
    res.fixu8   = vrev16q_u8 (a->fixu8);

    sprintf(ref_inst, "/* %s - vrevh.t */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vrev32(struct sreg128 *a)
{
    struct sreg128 res;
    int type = INST_T9;

    res.fixs8   = vrev32q_s8 (a->fixs8);
    res.fixs16  = vrev32q_s16(a->fixs16);
    res.fixu8   = vrev32q_u8 (a->fixu8);
    res.fixu16  = vrev32q_u16(a->fixu16);

    sprintf(ref_inst, "/* %s - vrevw.t */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vrev64(struct sreg128 *a)
{
    struct sreg128 res;
    int type = INST_T3;

    res.fixs8   = vrev64q_s8 (a->fixs8);
    res.fixs16  = vrev64q_s16(a->fixs16);
    res.fixs32  = vrev64q_s32(a->fixs32);
    res.fixu8   = vrev64q_u8 (a->fixu8);
    res.fixu16  = vrev64q_u16(a->fixu16);
    res.fixu32  = vrev64q_u32(a->fixu32);
    res.float32 = vrev64q_f32(a->float32);

    sprintf(ref_inst, "/* %s - vrevd.t */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vand(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T2;

    res.fixs8  = vandq_s8 (a->fixs8,  b->fixs8);
    res.fixs16 = vandq_s16(a->fixs16, b->fixs16);
    res.fixs32 = vandq_s32(a->fixs32, b->fixs32);
    res.fixs64 = vandq_s64(a->fixs64, b->fixs64);
    res.fixu8  = vandq_u8 (a->fixu8,  b->fixu8);
    res.fixu16 = vandq_u16(a->fixu16, b->fixu16);
    res.fixu32 = vandq_u32(a->fixu32, b->fixu32);
    res.fixu64 = vandq_u64(a->fixu64, b->fixu64);

    sprintf(ref_inst, "/* %s - vand.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vbic(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T2;

    res.fixs8  = vbicq_s8 (a->fixs8,  b->fixs8);
    res.fixs16 = vbicq_s16(a->fixs16, b->fixs16);
    res.fixs32 = vbicq_s32(a->fixs32, b->fixs32);
    res.fixs64 = vbicq_s64(a->fixs64, b->fixs64);
    res.fixu8  = vbicq_u8 (a->fixu8,  b->fixu8);
    res.fixu16 = vbicq_u16(a->fixu16, b->fixu16);
    res.fixu32 = vbicq_u32(a->fixu32, b->fixu32);
    res.fixu64 = vbicq_u64(a->fixu64, b->fixu64);

    sprintf(ref_inst, "/* %s - vandn.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void veor(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T2;

    res.fixs8  = veorq_s8 (a->fixs8,  b->fixs8);
    res.fixs16 = veorq_s16(a->fixs16, b->fixs16);
    res.fixs32 = veorq_s32(a->fixs32, b->fixs32);
    res.fixs64 = veorq_s64(a->fixs64, b->fixs64);
    res.fixu8  = veorq_u8 (a->fixu8,  b->fixu8);
    res.fixu16 = veorq_u16(a->fixu16, b->fixu16);
    res.fixu32 = veorq_u32(a->fixu32, b->fixu32);
    res.fixu64 = veorq_u64(a->fixu64, b->fixu64);

    sprintf(ref_inst, "/* %s - vxor.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vmvn(struct sreg128 *a)
{
    struct sreg128 res;
    int type = INST_T13;

    res.fixs8   = vmvnq_s8 (a->fixs8);
    res.fixs16  = vmvnq_s16(a->fixs16);
    res.fixs32  = vmvnq_s32(a->fixs32);
    //res.fixs64  = vmvnq_s64(a->fixs64);

    sprintf(ref_inst, "/* %s - vnot.t */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vorr(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T2;

    res.fixs8  = vorrq_s8 (a->fixs8,  b->fixs8);
    res.fixs16 = vorrq_s16(a->fixs16, b->fixs16);
    res.fixs32 = vorrq_s32(a->fixs32, b->fixs32);
    res.fixs64 = vorrq_s64(a->fixs64, b->fixs64);
    res.fixu8  = vorrq_u8 (a->fixu8,  b->fixu8);
    res.fixu16 = vorrq_u16(a->fixu16, b->fixu16);
    res.fixu32 = vorrq_u32(a->fixu32, b->fixu32);
    res.fixu64 = vorrq_u64(a->fixu64, b->fixu64);

    sprintf(ref_inst, "/* %s - vor.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vorn(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T2;

    res.fixs8  = vornq_s8 (a->fixs8,  b->fixs8);
    res.fixs16 = vornq_s16(a->fixs16, b->fixs16);
    res.fixs32 = vornq_s32(a->fixs32, b->fixs32);
    res.fixs64 = vornq_s64(a->fixs64, b->fixs64);
    res.fixu8  = vornq_u8 (a->fixu8,  b->fixu8);
    res.fixu16 = vornq_u16(a->fixu16, b->fixu16);
    res.fixu32 = vornq_u32(a->fixu32, b->fixu32);
    res.fixu64 = vornq_u64(a->fixu64, b->fixu64);

    sprintf(ref_inst, "/* %s - vorn.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vbsl(struct sreg128 *a, struct sreg128 *b, struct sreg128 *c)
{
    struct sreg128 res;
    int type = INST_T13;

    res.fixs8   = vbslq_s8 ((uint8x16_t)c->fixs8,   a->fixs8,   b->fixs8);
    res.fixs16  = vbslq_s16((uint16x8_t)c->fixs16,  a->fixs16,  b->fixs16);
    res.fixs32  = vbslq_s32((uint32x4_t)c->fixs32,  a->fixs32,  b->fixs32);
    res.fixs64  = vbslq_s64((uint64x2_t)c->fixs64,  a->fixs64,  b->fixs64);

    sprintf(ref_inst, "/* %s - vsel.t */", __FUNCTION__);
    print_1_3(__FUNCTION__, &res, a, b, c, type);
}

void vcls(struct sreg128 *a)
{
    struct sreg128 res;
    int type = INST_T7;

    res.fixs8   = vclsq_s8 (a->fixs8 );
    res.fixs16  = vclsq_s16(a->fixs16);
    res.fixs32  = vclsq_s32(a->fixs32);

    sprintf(ref_inst, "/* %s - vcls.t */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vclz(struct sreg128 *a)
{
    struct sreg128 res;
    int type = INST_T13;

    res.fixs8   = vclzq_s8 (a->fixs8);
    res.fixs16  = vclzq_s16(a->fixs16);
    res.fixs32  = vclzq_s32(a->fixs32);
    //res.fixs64  = vclzq_s64(a->fixs64);

     sprintf(ref_inst, "/* %s - vclz.t */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vcnt(struct sreg128 *a)
{
    struct sreg128 res;
    int type = INST_T8;

    res.fixs8   = vcntq_s8(a->fixs8);
    res.fixu8   = vcntq_u8(a->fixu8);

    sprintf(ref_inst, "/* %s - vcnt1.t */", __FUNCTION__);
    print_1_1(__FUNCTION__, &res, a, type);
}

void vtst(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128 res;
    int type = INST_T1;

    res.fixs8   = (int8x16_t)vtstq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = (int16x8_t)vtstq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = (int32x4_t)vtstq_s32(a->fixs32,  b->fixs32);
    res.fixu8   = vtstq_u8 (a->fixu8,   b->fixu8);
    res.fixu16  = vtstq_u16(a->fixu16,  b->fixu16);
    res.fixu32  = vtstq_u32(a->fixu32,  b->fixu32);

    sprintf(ref_inst, "/* %s - vtst.t */", __FUNCTION__);
    print_1_2(__FUNCTION__, &res, a, b, type);
}

void vzip(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128x2 res;
    int type = INST_T3;

    res.fixs8   = vzipq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = vzipq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vzipq_s32(a->fixs32,  b->fixs32);
    res.fixu8   = vzipq_u8 (a->fixu8,   b->fixu8);
    res.fixu16  = vzipq_u16(a->fixu16,  b->fixu16);
    res.fixu32  = vzipq_u32(a->fixu32,  b->fixu32);
    res.float32 = vzipq_f32(a->float32, b->float32);

    sprintf(ref_inst, "/* %s - vitl.t */", __FUNCTION__);
    print_2_2(__FUNCTION__, &res, a, b, type);
}

void vuzp(struct sreg128 *a, struct sreg128 *b)
{
    struct sreg128x2 res;
    int type = INST_T3;

    res.fixs8   = vuzpq_s8 (a->fixs8,   b->fixs8);
    res.fixs16  = vuzpq_s16(a->fixs16,  b->fixs16);
    res.fixs32  = vuzpq_s32(a->fixs32,  b->fixs32);
    res.fixu8   = vuzpq_u8 (a->fixu8,   b->fixu8);
    res.fixu16  = vuzpq_u16(a->fixu16,  b->fixu16);
    res.fixu32  = vuzpq_u32(a->fixu32,  b->fixu32);
    res.float32 = vuzpq_f32(a->float32, b->float32);

    sprintf(ref_inst, "/* %s - vdtl.t */", __FUNCTION__);
    print_2_2(__FUNCTION__, &res, a, b, type);
}

/* LOAD/STORE instructions. */

/* ############################################# */
//void vqrdmlah(struct sreg128 *a, struct sreg128 *b, struct sreg128 *c)
//{
//	struct sreg128 res;
//	int type = INST_T4;
//
//	res.fixs16  = vqrdmlahq_s16(a->fixs16,  b->fixs16, c->fixs16);
//	res.fixs32  = vqrdmlahq_s32(a->fixs32,  b->fixs32, c->fixs32);
//
//	print_1_3(__FUNCTION__, &res, a, b, c, type);
//}
//
//void vqrdmlsh(struct sreg128 *a, struct sreg128 *b, struct sreg128 *c)
//{
//	struct sreg128 res;
//	int type = INST_T4;
//
//	res.fixs16  = vqrdmlshq_s16(a->fixs16,  b->fixs16,  c->fixs16);
//	res.fixs32  = vqrdmlshq_s32(a->fixs32,  b->fixs32,  c->fixs32);
//
//	print_1_3(__FUNCTION__, &res, a, b, c, type);
//}

/* ################################## */

struct neon_handler_1_1 neon_inst_1_1[] = {
    {vpadd_e},
    {vabs},
    {vqabs},
    {vneg},
    {vqneg},
    {vcmpnez},
    {vcmphsz},
    {vcmpltz},
    {vcmphz},
    {vcmplsz},
    {vmvn},
    {vcls},
    {vclz},
    {vcnt},
    {vrev64},
    {vrev32},
    {vrev16},

    /* imm */
    {vshr_n},
    {vrshr_n},
    {vshl_n},
    {vqshl_n},
    {vqshlu_n},
    {vmulq_n},
};

struct neon_handler_1_2 neon_inst_1_2[] = {
    {vadd},
    {vhadd},
    {vrhadd},
    {vrhsub},
    {vqadd},
    {vaddhn},
    {vraddhn},
    {vsubhn},
    {vrsubhn},
    {vpadd},
    {vpadda_e},
    {vmul},
    {vqdmulh},
    {vqrdmulh},
    {vsub},
    {vhsub},
    {vqsub},
    {vceq},
    {vcge},
//    {vcle},
//    {vcgt},
    {vclt},
    {vtst},
    {vabd},
    {vmax},
    {vmin},
    {vpmax},
    {vpmin},
    {vshl},
    {vrshl},
    {vqshl},
    {vqrshl},
    {vand},
    {vorr},
    {veor},
    {vbic},
    {vorn},

    /* imm */
    {vsra_n},
    {vrsra_n},
    {vext},
};

struct neon_handler_1_3 neon_inst_1_3[] = {
    {vmla},
    {vmls},
    {vfma},
    {vfms},
    {vaba},
    {vbsl},

    /* imm */
//    {vmla_n},
//    {vmls_n},
    {vmla_lane},
    {vmls_lane},
};

struct neon_handler_1_4 neon_inst_1_4[] = {
    /* imm */
};

struct neon_handler_2_2 neon_inst_2_2[] = {
    {vtrn},
    {vzip},
    {vuzp},
    {vaddl},
    {vsubl},
    {vsabs_t_e},
};

struct neon_handler_2_3 neon_inst_2_3[] = {
    {vaddw},
    {vsubw},
};

struct neon_handler_2_4 neon_inst_2_4[] = {
    {vsabsa_t_e},
};

void gen_sreg_value(struct sreg128 *sreg)
{
    int i;
    unsigned int el;
    unsigned int sign;
    float fel;

    for (i = 0; i < 16; i++) {
        sreg->fixs8[i] = rand() % FIX8_SCALE;
        sreg->fixu8[i] = rand() % FIX8_SCALE;
    }

    for (i = 0; i < 8; i++) {
        sreg->fixs16[i] = rand() % FIX16_SCALE;
        sreg->fixu16[i] = rand() % FIX16_SCALE;
    }

    for (i = 0; i < 4; i++) {
        el = rand();
        sign = rand() % 2;
        sreg->fixs32[i] = el | (sign << 31);
        el = rand();
        sign = rand() % 2;
        sreg->fixu32[i] = el | (sign << 31);
        fel = rand() / FLOAT_SCALE;
        sign = rand() % 2;
        if (sign == 1) {
            sreg->float32[i] = -fel;
        } else {
            sreg->float32[i] = fel;
        }
    }

    for (i = 0; i < 2; i++) {
        sreg->fixs64[i] = rand() % FIX16_SCALE;
        sreg->fixs64[i] |= (long long)(rand() % FIX16_SCALE) << 16;
        sreg->fixs64[i] |= (long long)(rand() % FIX16_SCALE) << 32;
        sreg->fixs64[i] |= (long long)(rand() % FIX16_SCALE) << 48;
        sreg->fixu64[i] = rand() % FIX16_SCALE;
        sreg->fixu64[i] |= (unsigned long long)(rand() % FIX16_SCALE) << 16;
        sreg->fixu64[i] |= (unsigned long long)(rand() % FIX16_SCALE) << 32;
        sreg->fixu64[i] |= (unsigned long long)(rand() % FIX16_SCALE) << 48;
    }
}

int main()
{
    struct sreg128 reg0;
    struct sreg128 reg1;
    struct sreg128 reg2;
    struct sreg128 reg3;
    int i;

    srand(RAND_SEED);
    gen_sreg_value(&reg0);
    gen_sreg_value(&reg1);
    gen_sreg_value(&reg2);
    gen_sreg_value(&reg3);

    for (i = 0; i < sizeof(neon_inst_1_1) / sizeof(struct neon_handler_1_1 *);
         i++) {
        (neon_inst_1_1[i].handler)(&reg0);
    }

    for (i = 0; i < sizeof(neon_inst_1_2) / sizeof(struct neon_handler_1_2 *);
         i++) {
        (neon_inst_1_2[i].handler)(&reg0, &reg1);
    }

    for (i = 0; i < sizeof(neon_inst_1_3) / sizeof(struct neon_handler_1_3 *);
         i++) {
        (neon_inst_1_3[i].handler)(&reg0, &reg1, &reg2);
    }

    for (i = 0; i < sizeof(neon_inst_1_4) / sizeof(struct neon_handler_1_4 *);
         i++) {
        (neon_inst_1_4[i].handler)(&reg0, &reg1, &reg2, &reg3);
    }

    for (i = 0; i < sizeof(neon_inst_2_2) / sizeof(struct neon_handler_2_2 *);
         i++) {
        (neon_inst_2_2[i].handler)(&reg0, &reg1);
    }

    for (i = 0; i < sizeof(neon_inst_2_3) / sizeof(struct neon_handler_2_3 *);
         i++) {
        (neon_inst_2_3[i].handler)(&reg0, &reg1, &reg2);
    }

    for (i = 0; i < sizeof(neon_inst_2_4) / sizeof(struct neon_handler_2_4 *);
         i++) {
        (neon_inst_2_4[i].handler)(&reg0, &reg1, &reg2, &reg3);
    }

    return 0;
}
