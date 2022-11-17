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

#endif
