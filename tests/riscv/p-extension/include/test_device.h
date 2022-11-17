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

#ifndef TEST_DEVICE_H
#define TEST_DEVICE_H

#include <stdint.h>
#include "width.h"
#define CSKY_MATH_CK803S


struct unary_calculation {
    target_ulong op1;
    target_ulong result;
};

struct unary64_calculation {
    uint32_t op1;
    uint64_t result;
};

struct binary_calculation {
    target_ulong op1;
    target_ulong op2;
    target_ulong result;
};

struct binary64_calculation {
    uint32_t op1;
    uint32_t op2;
    uint64_t result;
};

struct binary64_64_calculation {
   uint64_t op1;
   uint32_t op2;
   uint64_t result;
};

struct binary64_ul_calculation {
   uint64_t op1;
   target_ulong op2;
   uint64_t result;
};

struct binary64_32_ul_calculation {
   uint64_t op1;
   uint32_t op2;
   target_ulong result;
};

struct binary64_ul_ul_calculation {
   uint64_t op1;
   target_ulong op2;
   target_ulong result;
};

struct ternary_calculation {
    target_ulong op1;
    target_ulong op2;
    target_ulong op3;
    target_ulong result;
};

struct ternary_ul_ul_64_calculation {
    target_ulong op1;
    target_ulong op2;
    uint64_t op3;
    uint64_t result;
};

struct ternary64_calculation {
    uint32_t op1;
    uint32_t op2;
    uint64_t op3;
    uint64_t result;
};

struct quanary_calculation {
   uint32_t op1;
   uint32_t op2;
   uint32_t op3;
   uint32_t op4;
   uint32_t result;
};

struct binary64_64_64_calculation {
    uint64_t op1;
    uint64_t op2;
    uint64_t result;
};
#endif  /* TEST_DEVICE_H */
