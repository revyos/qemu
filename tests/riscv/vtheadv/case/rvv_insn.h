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

#ifndef RVV_INSN_H
#define RVV_INSN_H
#include <stdint.h>
#define DEBUG
#define VLEN 128
#define LMUL 1 
struct rvv_reg {
    int8_t   fixs8[2 * LMUL][16];
    int16_t  fixs16[2 * LMUL][8];
    int32_t  fixs32[2 * LMUL][4];
    int64_t  fixs64[2 * LMUL][2];
    uint8_t  fixu8[2 * LMUL][16];
    uint16_t fixu16[2 * LMUL][8];
    uint32_t fixu32[2 * LMUL][4];
    uint64_t fixu64[2 * LMUL][2];
    uint64_t float64[2 * LMUL][2];
    uint32_t float32[2 * LMUL][4];
    uint16_t float16[2 * LMUL][8];
    int16_t  wfixs16[LMUL][16];
    int32_t  wfixs32[LMUL][8];
    int64_t  wfixs64[LMUL][4];
    uint16_t wfixu16[LMUL][16];
    uint32_t wfixu32[LMUL][8];
    uint64_t wfixu64[LMUL][4];
    uint64_t wfloat64[2 * LMUL][4];
    uint32_t wfloat32[2 * LMUL][8];
};


struct _vmreg {
    int64_t  mask[2];
};

struct _vmreg vmo4 = {
    .mask = {
        [0] = 0xaaaaaaaa,
    },
};

struct _vmreg vma4 = {
    .mask = {
        [0] = 0x7fffffff,
    },
};

struct _vmreg vme4 = {
    .mask = {
        [0] = 0x55555555,
    },
};


struct _vmreg vmo8 = {
    .mask = {
        [0] = 0xaaaa,
    },
};

struct _vmreg vma8 = {
    .mask = {
        [0] = 0x7fff,
    },
};

struct _vmreg vme8 = {
    .mask = {
        [0] = 0x5555,
    },
};

struct rvv_reg  pad = {
    .fixs8 = {
        {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
        {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
    },
    .fixs16 = {
        {0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
        {0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
    },
    .fixs32 = {
        {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
        {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
    },
    .fixs64 = {
        {0x1111111111111111, 0x1111111111111111, },
        {0x1111111111111111, 0x1111111111111111, },
    },
    .fixu8 = {
        {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
        {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
    },
    .fixu16 = {
        {0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
        {0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
    },
    .fixu32 = {
        {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
        {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
    },
    .fixu64 = {
        {0x1111111111111111, 0x1111111111111111, },
        {0x1111111111111111, 0x1111111111111111, },
    },
};

int vlmax_8 = (LMUL * VLEN) / (8 * 8);
int vlmax_16 = (LMUL * VLEN) / (8 * 16);
int vlmax_32 = (LMUL * VLEN) / 32;
int vlmax_64 = (LMUL * VLEN) / 64;

static inline void result_compare_s8_lmul(int8_t *dst, int8_t *ref)
{
    int i;
    for (i = 0; i < 16 * LMUL; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%02hhx, 0x%02hhx, ", dst[i], ref[i]);
#endif
    }
}

static inline void result_compare_s16_lmul(int16_t *dst, int16_t *ref)
{
    int i;
    for (i = 0; i < 8 * LMUL; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%04hx, 0x%04hx, ", dst[i], ref[i]);
#endif
    }
    printf("\n");
}

static inline void result_compare_s32_lmul(int32_t *dst, int32_t *ref)
{
    int i;
    for (i = 0; i < 4 * LMUL; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%08x, 0x%08x, ", dst[i], ref[i]);
#endif
    }
    printf("\n");
}

static inline void result_compare_s64_lmul(int64_t *dst, int64_t *ref)
{
    int i;
    for (i = 0; i < 2 * LMUL; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%016llx, 0x%016llx, ", dst[i], ref[i]);
#endif
    }
    printf("\n");
}
/* #define DEBUG */
static inline void result_compare_s8(int8_t *dst, int8_t *ref)
{
    int i;
    for (i = 0; i < 16; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%02hhx, 0x%02hhx, ", dst[i], ref[i]);
#endif
    }
    printf("\n");
}

static inline void result_compare_s16(int16_t *dst, int16_t *ref)
{
    int i;
    for (i = 0; i < 8; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%04hx, 0x%04hx, ", dst[i], ref[i]);
#endif
    }
    printf("\n");
}

static inline void result_compare_s32(int32_t *dst, int32_t *ref)
{
    int i;
    for (i = 0; i < 4; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%08x, 0x%08x, ", dst[i], ref[i]);
#endif
    }
    printf("\n");
}

static inline void result_compare_s64(int64_t *dst, int64_t *ref)
{
    int i;
    for (i = 0; i < 2; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%016llx, 0x%016llx, ", dst[i], ref[i]);
#endif
    }
    printf("\n");
}

static inline void result_compare_u8(uint8_t *dst, uint8_t *ref)
{
    int i;
    for (i = 0; i < 16; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("%#02hhx, ", dst[i]);
#endif
    }
#ifdef DEBUG
    for (i = 0; i < 16; i++) {
        printf("%#02hhx, ", dst[i]);
    }
    printf("\n");
#endif
}

static inline void result_compare_u16(uint16_t *dst, uint16_t *ref)
{
    int i;
    for (i = 0; i < 8; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("%#04hx, ", dst[i]);
#endif
    }
#ifdef DEBUG
    for (i = 0; i < 8; i++) {
        printf("%#04hx, ", dst[i]);
    }
    printf("\n");
#endif
}

static inline void result_compare_u32(uint32_t *dst, uint32_t *ref)
{
    int i;
    for (i = 0; i < 4; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("%#08x, ", dst[i]);
#endif
    }
#ifdef DEBUG
    for (i = 0; i < 4; i++) {
        printf("%#08x, ", dst[i]);
    }
    printf("\n");
#endif
}

static inline void result_compare_u64(uint64_t *dst, uint64_t *ref)
{
    int i;
    for (i = 0; i < 2; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("%#016llx, ", dst[i]);
#endif
    }
#ifdef DEBUG
    for (i = 0; i < 2; i++) {
        printf("%#016llx, ", dst[i]);
    }
    printf("\n");
#endif
}

static inline void result_compare_u8_lmul(uint8_t *dst, uint8_t *ref)
{
    int i;
    for (i = 0; i < 16 * LMUL; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%02hhx, 0x%02hhx, ", dst[i], ref[i]);
#endif
    }
}

static inline void result_compare_u16_lmul(uint16_t *dst, uint16_t *ref)
{
    int i;
    for (i = 0; i < 8 * LMUL; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%04hx, 0x%04hx, ", dst[i], ref[i]);
#endif
    }
}

static inline void result_compare_u32_lmul(uint32_t *dst, uint32_t *ref)
{
    int i;
    for (i = 0; i < 4 * LMUL; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%08x, 0x%08x, ", dst[i], ref[i]);
#endif
    }
}

static inline void result_compare_u64_lmul(uint64_t *dst, uint64_t *ref)
{
    int i;
    for (i = 0; i < 2 * LMUL; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%016llx, 0x%016llx, ", dst[i], ref[i]);
#endif
    }
}

inline void result_compare_f32(uint32_t *dst, uint32_t *ref)
{
    int i;
#ifdef DEBUG
    for (i = 0; i < 4; i++) {
        TEST(dst[i] == ref[i]);
        printf("0x%x, ", dst[i]);
    }
    printf("\n");
    for (i = 0; i < 4; i++) {
        printf("0x%x, ", ref[i]);
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
        printf("0x%x, ", dst[i]);
    }
    printf("\n");
    for (i = 0; i < 8; i++) {
        printf("0x%x, ", ref[i]);
    }
    printf("\n");
#else
    for (i = 0; i < 8; i++) {
        TEST(dst[i] == ref[i]);
    }
#endif
}

static inline void result_compare_s8_lmulw(int8_t *dst, int8_t *ref)
{
    int i;
    for (i = 0; i < 16 * LMUL * 2; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        if (dst[i] != ref[i]) {
            printf("0x%02hhx \n", dst[i]);
        }
#endif
    }
#ifdef DEBUG
    for (i = 0; i < 16 * LMUL * 2; i++) {
        printf("0x%02hhx, ", dst[i]);
    }
#endif
}

static inline void result_compare_s16_lmulw(int16_t *dst, int16_t *ref)
{
    int i;
    for (i = 0; i < 8 * LMUL * 2; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        if (dst[i] != ref[i]) {
            printf("0x%04hx \n", dst[i]);
        }
#endif
    }
#ifdef DEBUG
    for (i = 0; i < 8 * LMUL * 2; i++) {
        printf("0x%04hx, ", dst[i]);
    }
    printf("\n");
#endif
}

static inline void result_compare_s32_lmulw(int32_t *dst, int32_t *ref)
{
    int i;
    for (i = 0; i < 4 * LMUL * 2; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%08x, 0x%08x, ", dst[i], ref[i]);
#endif
    }
}

static inline void result_compare_s64_lmulw(int64_t *dst, int64_t *ref)
{
    int i;
    for (i = 0; i < 2 * LMUL * 2; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%016llx, 0x%016llx, ", dst[i], ref[i]);
#endif
    }
}

void test_vmaqa_vv(void *b, void *c, void *d, void *e, void *f);
void test_vmaqau_vv(void *b, void *c, void *d, void *e, void *f);
void test_vmaqasu_vv(void *b, void *c, void *d, void *e, void *f);
void test_vpmaqa_vv(void *b, void *c, void *d, void *e, void *f);
void test_vpmaqau_vv(void *b, void *c, void *d, void *e, void *f);
void test_vpmaqasu_vv(void *b, void *c, void *d, void *e, void *f);
void test_vmaqa_vx(void *b, int64_t c, void *d, void *e, void *f);
void test_vmaqau_vx(void *b, uint64_t c, void *d, void *e, void *f);
void test_vmaqasu_vx(void *b, int64_t c, void *d, void *e, void *f);
void test_vmaqaus_vx(void *b, uint64_t c, void *d, void *e, void *f);
void test_vpmaqa_vx(void *b, int64_t c, void *d, void *e, void *f);
void test_vpmaqau_vx(void *b, uint64_t c, void *d, void *e, void *f);
void test_vpmaqasu_vx(void *b, int64_t c, void *d, void *e, void *f);
void test_vpmaqaus_vx(void *b, uint64_t c, void *d, void *e, void *f);
void test_vpnclip_wv(void *b, void *c, void *d, void *e, void *f);
void test_vpnclipu_wv(void *b, void *c, void *d, void *e, void *f);
void test_vpnclip_wx(int64_t b, void *c, void *d, void *e, void *f);
void test_vpnclipu_wx(uint64_t b, void *c, void *d, void *e, void *f);
void test_vpwadd_vv(void *b, void *c, void *d, void *e, void *f);
void test_vpwaddu_vv(void *b, void *c, void *d, void *e, void *f);
void test_vpwadd_vx(int64_t b, void *c, void *d, void *e, void *f);
void test_vpwaddu_vx(uint64_t b, void *c, void *d, void *e, void *f);
#endif
