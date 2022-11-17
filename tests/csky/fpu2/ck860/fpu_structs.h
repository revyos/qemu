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

#ifndef FPU_STRUCTS_H
#define FPU_STRUCTS_H

typedef short                   int16_t;
typedef unsigned short          uint16_t;
typedef int                     int32_t;
typedef unsigned int            uint32_t;
typedef long long               int64_t;
typedef unsigned long long      uint64_t;

typedef union float16_t {
    __fp16 f;
    unsigned short int d;
} float16;
#define HpsNaN      0x7c01
#define HnsNaN      0xfc01
#define HpqNaN      0x7e00
#define HnqNaN      0xfe00
#define HpInf       0x7c00
#define HnInf       0xfc00
/* +0.5 */
#define HpNorm      0x3800
/* -0.5 */
#define HnNorm      0xb800
#define HpDeNorm    0x0001
#define HnDeNorm    0x8001
#define HpZero      0x0000
#define HnZero      0x8000
#define HpLFN       0x7dff
#define HnLFN       0xfdff
#define HpMIN       0x0200
#define HnMIN       0x8200

typedef union float32_t {
    float f;
    unsigned int d;
} float32;
#define SpsNaN      0x7f800001
#define SnsNaN      0xff800001
#define SpqNaN      0x7fc00000
#define SnqNaN      0xffc00000
#define SpInf       0x7f800000
#define SnInf       0xff800000
/* +0.5 */
#define SpNorm      0x3f000000
/* -0.5 */
#define SnNorm      0xbf000000
#define SpDeNorm    0x00000001
#define SnDeNorm    0x80000001
#define SpZero      0x00000000
#define SnZero      0x80000000
#define SpLFN       0x7f7fffff
#define SnLFN       0xff7fffff
#define SpMIN       0x00800000
#define SnMIN       0x80800000

typedef union float64_t {
    double f;
    unsigned long long int d;
} float64;
#define DpsNaN      0x7ff0000000000001
#define DnsNaN      0xfff0000000000001
#define DpqNaN      0x7ff8000000000000
#define DnqNaN      0xfff8000000000000
#define DpInf       0x7ff0000000000000
#define DnInf       0xfff0000000000000
/* +0.5 */
#define DpNorm      0x3fe0000000000000
/* -0.5 */
#define DnNorm      0xbfe0000000000000
#define DpDeNorm    0x0000000000000001
#define DnDeNorm    0x8000000000000001
#define DpZero      0x0000000000000000
#define DnZero      0x8000000000000000
#define DpLFN       0x7fefffffffffffff
#define DnLFN       0xffefffffffffffff
#define DpMIN       0x0010000000000000
#define DnMIN       0x8010000000000000


typedef struct operand_64 {
    union {
        double d;
        unsigned int i[2];
        unsigned long long ull;
        float f[2];
    } a;
} operand_64_t;

typedef struct unary_calculation_64 {
    operand_64_t op1;
    operand_64_t result;
} unary_calculation_64_t;

typedef struct binary_calculation_64 {
    operand_64_t op1;
    operand_64_t op2;
    operand_64_t result;
} binary_calculation_64_t;

typedef struct ternary_calculation_64 {
    operand_64_t op1;
    operand_64_t op2;
    operand_64_t op3;
    operand_64_t result;
} ternary_calculation_64_t;

struct unary_calculation {
    unsigned int op1;
    unsigned int result;
};

struct binary_calculation {
    unsigned int op1;
    unsigned int op2;
    unsigned int result;
};

struct ternary_calculation {
    unsigned int op1;
    unsigned int op2;
    unsigned int op3;
    unsigned int result;
};

struct op1_res1_s16_f16 {
    int16_t     op1;
    float16     res;
};

struct op1_res1_u16_f16 {
    uint16_t    op1;
    float16     res;
};

struct op1_res1_s16_f32 {
    int16_t     op1;
    float32     res;
};

struct op1_res1_u16_f32 {
    uint16_t    op1;
    float32     res;
};

struct op1_res1_s16_f64 {
    int16_t     op1;
    float64     res;
};

struct op1_res1_u16_f64 {
    uint16_t    op1;
    float64     res;
};

struct op1_res1_f16 {
    float16     op1;
    float16     res;
};

struct op1_res1_f16_s16 {
    float16     op1;
    int16_t     res;
};

struct op1_res1_f16_u16 {
    float16     op1;
    uint16_t    res;
};

struct op1_res1_f16_s32 {
    float16     op1;
    int32_t     res;
};

struct op1_res1_f16_u32 {
    float16     op1;
    uint32_t    res;
};

struct op1_res1_f16_f32 {
    float16     op1;
    float32     res;
};

struct op1_res1_s32_f16 {
    int32_t     op1;
    float16     res;
};

struct op1_res1_u32_f16 {
    uint32_t    op1;
    float16     res;
};

struct op1_res1_s32_f32 {
    int32_t     op1;
    float32     res;
};

struct op1_res1_s32_f64 {
    int32_t     op1;
    float64     res;
};

struct op1_res1_f32 {
    float32     op1;
    float32     res;
};

struct op1_res1_f32_s16 {
    float32     op1;
    int16_t     res;
};

struct op1_res1_f32_u16 {
    float32     op1;
    uint16_t    res;
};

struct op1_res1_f32_f16 {
    float32     op1;
    float16     res;
};

struct op1_res1_f32_s32 {
    float32     op1;
    int32_t     res;
};

struct op1_res1_f64 {
    float64     op1;
    float64     res;
};

struct op1_res1_f64_s16 {
    float64     op1;
    int16_t     res;
};

struct op1_res1_f64_u16 {
    float64     op1;
    uint16_t    res;
};

struct op1_res1_f64_f16 {
    float64     op1;
    float16     res;
};

struct op1_res1_f64_s32 {
    float64     op1;
    int32_t     res;
};

struct op1_res1_f64_f32 {
    float64     op1;
    float32     res;
};

struct op1_res2_f64_s32_s32 {
    float64     op1;
    int32_t     res1;
    int32_t     res2;
};

struct op2_res1_s16_s16_f16 {
    int16_t     op1;
    int16_t     op2;
    float16     res;
};

struct op2_res1_u16_s16_f16 {
    uint16_t    op1;
    int16_t     op2;
    float16     res;
};

struct op2_res1_s16_s16_f32 {
    int16_t     op1;
    int16_t     op2;
    float32     res;
};

struct op2_res1_u16_s16_f32 {
    uint16_t    op1;
    int16_t     op2;
    float32     res;
};

struct op2_res1_s16_s16_f64 {
    int16_t     op1;
    int16_t     op2;
    float64     res;
};

struct op2_res1_u16_s16_f64 {
    uint16_t    op1;
    int16_t     op2;
    float64     res;
};

struct op2_res1_f16 {
    float16     op1;
    float16     op2;
    float16     res;
};

struct op2_res1_f16_f16_s16 {
    float16     op1;
    float16     op2;
    int16_t     res;
};

struct op2_res1_f16_s16_s16 {
    float16     op1;
    int16_t     op2;
    int16_t     res;
};

struct op2_res1_f16_s16_u16 {
    float16     op1;
    int16_t     op2;
    uint16_t    res;
};

struct op2_res1_f16_s32_s32 {
    float16     op1;
    int32_t     op2;
    int32_t     res;
};

struct op2_res1_f16_s32_u32 {
    float16     op1;
    int32_t     op2;
    uint32_t    res;
};

struct op2_res1_s32_s32_f32 {
    int32_t     op1;
    int32_t     op2;
    float32     res;
};

struct op2_res1_u32_s32_f32 {
    uint32_t    op1;
    int32_t     op2;
    float32     res;
};
struct op2_res1_s32_s32_f16 {
    int32_t     op1;
    int32_t     op2;
    float16     res;
};

struct op2_res1_u32_s32_f16 {
    uint32_t    op1;
    int32_t     op2;
    float16     res;
};


struct op2_res1_s32_s32_f64 {
    int32_t     op1;
    int32_t     op2;
    float64     res;
};

struct op2_res1_u32_s32_f64 {
    uint32_t    op1;
    int32_t     op2;
    float64     res;
};

struct op2_res1_f32 {
    float32     op1;
    float32     op2;
    float32     res;
};

struct op2_res1_f32_s16_s16 {
    float32     op1;
    int16_t     op2;
    int16_t     res;
};

struct op2_res1_f32_s16_u16 {
    float32     op1;
    int16_t     op2;
    uint16_t    res;
};

struct op2_res1_f32_s32_s32 {
    float32     op1;
    int32_t     op2;
    int32_t     res;
};

struct op2_res1_f32_s32_u32 {
    float32     op1;
    int32_t     op2;
    uint32_t    res;
};

struct op2_res1_f32_f32_s32 {
    float32     op1;
    float32     op2;
    int32_t     res;
};

struct op2_res1_f64 {
    float64     op1;
    float64     op2;
    float64     res;
};

struct op2_res1_f64_s16_s16 {
    float64     op1;
    int16_t     op2;
    int16_t     res;
};

struct op2_res1_f64_s16_u16 {
    float64     op1;
    int16_t     op2;
    uint16_t    res;
};

struct op2_res1_f64_s32_s32 {
    float64     op1;
    int32_t     op2;
    int32_t     res;
};

struct op2_res1_f64_s32_u32 {
    float64     op1;
    int32_t     op2;
    uint32_t    res;
};


struct op2_res2_s32_s32_f32_f32 {
    int32_t     op1;
    int32_t     op2;
    float32     res1;
    float32     res2;
};

struct op2_res2_f32_f32_s32_s32 {
    float32     op1;
    float32     op2;
    int32_t     res1;
    int32_t     res2;
};

struct op3_res1_f16 {
    float16     op1;
    float16     op2;
    float16     op3;
    float16     res;
};

struct op3_res1_f32 {
    float32     op1;
    float32     op2;
    float32     op3;
    float32     res;
};

struct op3_res1_f64 {
    float64     op1;
    float64     op2;
    float64     op3;
    float64     res;
};

#endif
