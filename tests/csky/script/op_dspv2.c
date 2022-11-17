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

#include "inst_dspv2.h"
static inline uint32_t helper_sig_sat_add(uint32_t x, uint32_t y, uint32_t len)
{
    /* rz = rx + ry, signed & saturated add for len bits operands, len <= 32 */
    uint32_t res = x + y;
    uint32_t signbit = 1 << (len - 1);
    uint32_t mask = 0xffffffff >> (32 - len);
    if (((res ^ x) & signbit) && !((x ^ y) & signbit)) {
        res = ~(((int32_t)(x << (32 - len)) >> 31) ^ signbit);
    }
    return res & mask;
}

static inline uint32_t helper_unsig_sat_add(uint32_t x,
                                            uint32_t y, uint32_t len)
{
    /* rz = rx + ry, unsigned & saturated add for len bits operands. */
    uint32_t mask = 0xffffffff >> (32 - len);
    uint32_t res = (x + y) & mask;
    if (res < x || res < y) {
        res = mask;
    }
    return res;
}

static inline uint32_t helper_sig_sat_sub(uint32_t x, uint32_t y, uint32_t len)
{
    /* rz = rx - ry, signed & saturated sub for len bits operands, len <= 32 */
    uint32_t res = x - y;
    uint32_t signbit = 1 << (len - 1);
    uint32_t mask = 0xffffffff >> (32 - len);
    if (((res ^ x) & signbit) && ((x ^ y) & signbit)) {
        res = ~(((int32_t)(x << (32 - len)) >> 31) ^ signbit);
    }
    return res & mask;
}

static inline uint32_t helper_unsig_sat_sub(uint32_t x,
                                            uint32_t y, uint32_t len)
{
    /* rz = rx + ry, unsigned & saturated add for len bits operands. */
    uint32_t mask = 0xffffffff >> (32 - len);
    uint32_t res = (x - y) & mask;
    if (res > x) {
        res = 0;
    }
    return res;
}

static inline uint32_t helper_sat_lsl(uint32_t x, uint32_t n, uint32_t len)
{
    /*  unsigned & saturated add for len bits operands, len <= 32 */
    uint32_t res = x << n;
    uint32_t mask1 = (0xffffffff >> n) << n;
    uint32_t mask2 = (0xffffffff << (32 - len)) >> (32 - len);
    if ((x & mask1 & mask2) != 0) {
        res = mask2;
    }
    return res & mask2;
}

uint32_t DSPV2_HELPER(add_s32_s)(uint32_t x, uint32_t y)
{
    /* rz = rx + ry, signed & saturated */
    return helper_sig_sat_add(x, y, 32);
}

uint32_t DSPV2_HELPER(add_u32_s)(uint32_t x, uint32_t y)
{
    /* rz = rx + ry, signed & saturated */
    return helper_unsig_sat_add(x, y, 32);
}

uint32_t DSPV2_HELPER(padd_s8_s)(uint32_t x, uint32_t y)
{
    /* rz[7:0] = rx[7:0] + ry[7:0]*/
    /* rz[15:8] = rx[15:8] + ry[15:8]*/
    /* rz[23:16] = rx[23:16] + ry[23:16]*/
    /* rz[31:24] = rx[31:24] + ry[31:24], signed & saturated. */
    uint32_t byte0, byte1, byte2, byte3;
    byte0 = helper_sig_sat_add(x & 0xff, y & 0xff, 8);
    byte1 = helper_sig_sat_add((x & 0xff00) >> 8, (y & 0xff00) >> 8, 8);
    byte2 = helper_sig_sat_add((x & 0xff0000) >> 16, (y & 0xff0000) >> 16, 8);
    byte3 = helper_sig_sat_add((x & 0xff000000) >> 24,
                               (y & 0xff000000) >> 24, 8);
    return (byte3 << 24) | (byte2 << 16) |(byte1 << 8) | byte0;
}

uint32_t DSPV2_HELPER(padd_u8_s)(uint32_t x, uint32_t y)
{
    /* rz[7:0] = rx[7:0] + ry[7:0]*/
    /* rz[15:8] = rx[15:8] + ry[15:8]*/
    /* rz[23:16] = rx[23:16] + ry[23:16]*/
    /* rz[31:24] = rx[31:24] + ry[31:24], unsigned & saturated. */
    uint32_t byte0, byte1, byte2, byte3;
    byte0 = helper_unsig_sat_add(x & 0xff, y & 0xff, 8);
    byte1 = helper_unsig_sat_add((x & 0xff00) >> 8, (y & 0xff00) >> 8, 8);
    byte2 = helper_unsig_sat_add((x & 0xff0000) >> 16, (y & 0xff0000) >> 16, 8);
    byte3 = helper_unsig_sat_add((x & 0xff000000) >> 24,
                                 (y & 0xff000000) >> 24, 8);
    return (byte3 << 24) | (byte2 << 16) |(byte1 << 8) | byte0;
}

uint32_t DSPV2_HELPER(padd_s16_s)(uint32_t x, uint32_t y)
{
    /* rz[15:0] = rx[15:0] + ry[15:0],
     * rz[31:16] = rx[31:16] + ry[31:16], signed & saturated */
    uint32_t lo, hi;
    lo  = helper_sig_sat_add(x & 0xffff, y & 0xffff, 16);
    hi  = helper_sig_sat_add((x & 0xffff0000) >> 16,
                             (y & 0xffff0000) >> 16, 16);
    return (hi << 16) | lo;
}

uint32_t DSPV2_HELPER(padd_u16_s)(uint32_t x, uint32_t y)
{
    /* rz[15:0] = rx[15:0] + ry[15:0],
     * rz[31:16] = rx[31:16] + ry[31:16], unsigned & saturated */
    uint32_t lo, hi;
    lo  = helper_unsig_sat_add(x & 0xffff, y & 0xffff, 16);
    hi  = helper_unsig_sat_add((x & 0xffff0000) >> 16,
                               (y & 0xffff0000) >> 16, 16);
    return (hi << 16) | lo;
}

uint32_t DSPV2_HELPER(sub_s32_s)(uint32_t x, uint32_t y)
{
    /* rz = rx - ry, signed & saturated */
    return helper_sig_sat_sub(x, y, 32);
}

uint32_t DSPV2_HELPER(sub_u32_s)(uint32_t x, uint32_t y)
{
    /* rz = rx - ry, unsigned & saturated */
    return helper_unsig_sat_sub(x, y, 32);
}

uint32_t DSPV2_HELPER(psub_s8_s)(uint32_t x, uint32_t y)
{
    /* rz[7:0] = rx[7:0] - ry[7:0]*/
    /* rz[15:8] = rx[15:8] - ry[15:8]*/
    /* rz[23:16] = rx[23:16] - ry[23:16]*/
    /* rz[31:24] = rx[31:24] - ry[31:24], signed & saturated. */
    uint32_t byte0, byte1, byte2, byte3;
    byte0 = helper_sig_sat_sub(x & 0xff, y & 0xff, 8);
    byte1 = helper_sig_sat_sub((x & 0xff00) >> 8, (y & 0xff00) >> 8, 8);
    byte2 = helper_sig_sat_sub((x & 0xff0000) >> 8, (y & 0xff0000) >> 8, 8);
    byte3 = helper_sig_sat_sub((x & 0xff000000) >> 8,
                               (y & 0xff000000) >> 8, 8);
    return (byte3 << 24) | (byte2 << 16) |(byte1 << 8) | byte0;
}

uint32_t DSPV2_HELPER(psub_u8_s)(uint32_t x, uint32_t y)
{
    /* rz[7:0] = rx[7:0] - ry[7:0]*/
    /* rz[15:8] = rx[15:8] - ry[15:8]*/
    /* rz[23:16] = rx[23:16] - ry[23:16]*/
    /* rz[31:24] = rx[31:24] - ry[31:24], unsigned & saturated. */
    uint32_t byte0, byte1, byte2, byte3;
    byte0 = helper_unsig_sat_sub(x & 0xff, y & 0xff, 8);
    byte1 = helper_unsig_sat_sub((x & 0xff00) >> 8, (y & 0xff00) >> 8, 8);
    byte2 = helper_unsig_sat_sub((x & 0xff0000) >> 8, (y & 0xff0000) >> 8, 8);
    byte3 = helper_unsig_sat_sub((x & 0xff000000) >> 8,
                                 (y & 0xff000000) >> 8, 8);
    return (byte3 << 24) | (byte2 << 16) |(byte1 << 8) | byte0;
}

uint32_t DSPV2_HELPER(psub_s16_s)(uint32_t x, uint32_t y)
{
    /* rz[15:0] = rx[15:0] - ry[15:0],
     * rz[31:16] = rx[31:16] - ry[31:16], signed & saturated */
    uint32_t lo, hi;
    lo  = helper_sig_sat_sub(x & 0xffff, y & 0xffff, 16);
    hi  = helper_sig_sat_sub((x & 0xffff0000) >> 16,
                             (y & 0xffff0000) >> 16, 16);
    return (hi << 16) | lo;
}

uint32_t DSPV2_HELPER(psub_u16_s)(uint32_t x, uint32_t y)
{
    /* rz[15:0] = rx[15:0] - ry[15:0],
     * rz[31:16] = rx[31:16] - ry[31:16], unsigned & saturated */
    uint32_t lo, hi;
    lo  = helper_unsig_sat_sub(x & 0xffff, y & 0xffff, 16);
    hi  = helper_unsig_sat_sub((x & 0xffff0000) >> 16,
                               (y & 0xffff0000) >> 16, 16);
    return (hi << 16) | lo;
}

uint32_t DSPV2_HELPER(paddh_s8)(uint32_t x, uint32_t y)
{
    /* rz[7:0] = (rx[7:0] + ry[7:0])/2,
     * rz[15:8] = (rx[15:8] + ry[15:8])/2,
     * rz[23:16] = (rx[23:16] + ry[23:16])/2,
     * rz[31:24] = (rx[31:24] + ry[31:24])/2, signed */
    uint32_t byte0, byte1, byte2, byte3;
    byte0 = (int8_t)(x + y) / 2;
    byte1 = (int8_t)((x >> 8) + (y >> 8)) / 2;
    byte2 = (int8_t)((x >> 16) + (y >> 16)) / 2;
    byte3 = (int8_t)((x >> 24) + (y >> 24)) / 2;
    return (byte3 << 24) | (byte2 << 16) |(byte1 << 8) | byte0;
}

uint32_t DSPV2_HELPER(paddh_u8)(uint32_t x, uint32_t y)
{
    /* rz[7:0] = (rx[7:0] + ry[7:0])/2,
     * rz[15:8] = (rx[15:8] + ry[15:8])/2,
     * rz[23:16] = (rx[23:16] + ry[23:16])/2,
     * rz[31:24] = (rx[31:24] + ry[31:24])/2, unsigned */
    uint32_t byte0, byte1, byte2, byte3;
    byte0 = (uint8_t)(x + y) / 2;
    byte1 = (uint8_t)((x >> 8) + (y >> 8)) / 2;
    byte2 = (uint8_t)((x >> 16) + (y >> 16)) / 2;
    byte3 = (uint8_t)((x >> 24) + (y >> 24)) / 2;
    return (byte3 << 24) | (byte2 << 16) |(byte1 << 8) | byte0;
}

uint32_t DSPV2_HELPER(paddh_s16)(uint32_t x, uint32_t y)
{
    /* rz[15:0] = (rx[15:0] + ry[15:0])/2,
     * rz[31:16] = (rx[31:16] + ry[31:16])/2, signed */
    uint32_t lo, hi;
    lo = (int16_t)(x + y) / 2;
    hi = (int16_t)((x >> 16) + (y >> 16)) / 2;
    return (hi << 16) | (lo & 0xffff);
}

uint32_t DSPV2_HELPER(paddh_u16)(uint32_t x, uint32_t y)
{
    /* rz[15:0] = (rx[15:0] + ry[15:0])/2,
     * rz[31:16] = (rx[31:16] + ry[31:16])/2, unsigned */
    uint32_t lo, hi;
    lo = (uint16_t)(x + y) / 2;
    hi = (uint16_t)((x >> 16) + (y >> 16)) / 2;
    return (hi << 16) | (lo & 0xffff);
}

uint32_t DSPV2_HELPER(psubh_s8)(uint32_t x, uint32_t y)
{
    /* rz[7:0] = (rx[7:0] - ry[7:0])/2,
     * rz[15:8] = (rx[15:8] - ry[15:8])/2,
     * rz[23:16] = (rx[23:16] - ry[23:16])/2,
     * rz[31:24] = (rx[31:24] - ry[31:24])/2, signed */
    uint32_t byte0, byte1, byte2, byte3;
    byte0 = (int8_t)(x - y) / 2;
    byte1 = (int8_t)((x >> 8) - (y >> 8)) / 2;
    byte2 = (int8_t)((x >> 16) - (y >> 16)) / 2;
    byte3 = (int8_t)((x >> 24) - (y >> 24)) / 2;
    return (byte3 << 24) | (byte2 << 16) |(byte1 << 8) | byte0;
}

uint32_t DSPV2_HELPER(psubh_u8)(uint32_t x, uint32_t y)
{
    /* rz[7:0] = (rx[7:0] - ry[7:0])/2,
     * rz[15:8] = (rx[15:8] - ry[15:8])/2,
     * rz[23:16] = (rx[23:16] - ry[23:16])/2,
     * rz[31:24] = (rx[31:24] - ry[31:24])/2, unsigned */
    uint32_t byte0, byte1, byte2, byte3;
    byte0 = (uint8_t)(x - y) / 2;
    byte1 = (uint8_t)((x >> 8) - (y >> 8)) / 2;
    byte2 = (uint8_t)((x >> 16) - (y >> 16)) / 2;
    byte3 = (uint8_t)((x >> 24) - (y >> 24)) / 2;
    return (byte3 << 24) | (byte2 << 16) |(byte1 << 8) | byte0;
}

uint32_t DSPV2_HELPER(psubh_s16)(uint32_t x, uint32_t y)
{
    /* rz[15:0] = (rx[15:0] - ry[15:0])/2,
     * rz[31:16] = (rx[31:16] - ry[31:16])/2, signed */
    uint32_t lo, hi;
    lo = (int16_t)(x - y) / 2;
    hi = (int16_t)((x >> 16) - (y >> 16)) / 2;
    return (hi << 16) | (lo & 0xffff);
}

uint32_t DSPV2_HELPER(psubh_u16)(uint32_t x, uint32_t y)
{
    /* rz[15:0] = (rx[15:0] - ry[15:0])/2,
     * rz[31:16] = (rx[31:16] - ry[31:16])/2, unsigned */
    uint32_t lo, hi;
    lo = (uint16_t)(x - y) / 2;
    hi = (uint16_t)((x >> 16) - (y >> 16)) / 2;
    return (hi << 16) | (lo & 0xffff);
}

uint32_t DSPV2_HELPER(pasx_s16_s)(uint32_t x, uint32_t y)
{
    /* rz[31:16] = rx[31:16] + ry[15:0],
     * rz[15:0] = rx[15:0] - ry[31:16], signed & saturated */
    uint32_t lo, hi;
    hi  = helper_sig_sat_add((x & 0xffff0000) >> 16, y & 0xffff, 16);
    lo  = helper_sig_sat_sub(x & 0xffff, (y & 0xffff0000) >> 16, 16);
    return (hi << 16) | lo;
}

uint32_t DSPV2_HELPER(pasx_u16_s)(uint32_t x, uint32_t y)
{
    /* rz[31:16] = rx[31:16] + ry[15:0],
     * rz[15:0] = rx[15:0] - ry[31:16], unsigned & saturated */
    uint32_t lo, hi;
    hi  = helper_unsig_sat_add((x & 0xffff0000) >> 16, y & 0xffff, 16);
    lo  = helper_unsig_sat_sub(x & 0xffff, (y & 0xffff0000) >> 16, 16);
    return (hi << 16) | lo;
}

uint32_t DSPV2_HELPER(psax_s16_s)(uint32_t x, uint32_t y)
{
    /* rz[31:16] = rx[31:16] - ry[15:0],
     * rz[15:0] = rx[15:0] + ry[31:16], signed & saturated */
    uint32_t lo, hi;
    hi  = helper_sig_sat_sub((x & 0xffff0000) >> 16, y & 0xffff, 16);
    lo  = helper_sig_sat_add(x & 0xffff, (y & 0xffff0000) >> 16, 16);
    return (hi << 16) | lo;
}

uint32_t DSPV2_HELPER(psax_u16_s)(uint32_t x, uint32_t y)
{
    /* rz[31:16] = rx[31:16] - ry[15:0],
     * rz[15:0] = rx[15:0] + ry[31:16], unsigned & saturated */
    uint32_t lo, hi;
    hi  = helper_unsig_sat_sub((x & 0xffff0000) >> 16, y & 0xffff, 16);
    lo  = helper_unsig_sat_add(x & 0xffff, (y & 0xffff0000) >> 16, 16);
    return (hi << 16) | lo;
}

uint32_t DSPV2_HELPER(pasxh_s16)(uint32_t x, uint32_t y)
{
    /* rz[31:16] = (rx[31:16] + ry[31:16])/2,
     * rz[15:0] = (rx[15:0] - ry[15:0])/2, signed */
    uint32_t lo, hi;
    hi = (int16_t)((x >> 16) + y) / 2;
    lo = (int16_t)(x - (y >> 16)) / 2;
    return (hi << 16) | (lo & 0xffff);
}

uint32_t DSPV2_HELPER(pasxh_u16)(uint32_t x, uint32_t y)
{
    /* rz[31:16] = (rx[31:16] + ry[31:16])/2,
     * rz[15:0] = (rx[15:0] - ry[15:0])/2, unsigned */
    uint32_t lo, hi;
    hi = (uint16_t)((x >> 16) + y) / 2;
    lo = (uint16_t)(x - (y >> 16)) / 2;
    return (hi << 16) | (lo & 0xffff);
}

uint32_t DSPV2_HELPER(psaxh_s16)(uint32_t x, uint32_t y)
{
    /* rz[31:16] = (rx[31:16] - ry[31:16])/2,
     * rz[15:0] = (rx[15:0] + ry[15:0])/2, signed */
    uint32_t lo, hi;
    hi = (int16_t)((x >> 16) - y) / 2;
    lo = (int16_t)(x + (y >> 16)) / 2;
    return (hi << 16) | (lo & 0xffff);
}

uint32_t DSPV2_HELPER(psaxh_u16)(uint32_t x, uint32_t y)
{
    /* rz[31:16] = (rx[31:16] - ry[31:16])/2,
     * rz[15:0] = (rx[15:0] + ry[15:0])/2, unsigned */
    uint32_t lo, hi;
    hi = (uint16_t)((x >> 16) - y) / 2;
    lo = (uint16_t)(x + (y >> 16)) / 2;
    return (hi << 16) | (lo & 0xffff);
}

uint64_t DSPV2_HELPER(add_s64_s)(uint64_t x, uint64_t y)
{
    /* rz = rx + ry, signed & saturated */
    uint64_t res = x + y;
    if (((res ^ x) & SIGNBIT64) && !((x ^ y) & SIGNBIT64)) {
        res = ~(((int64_t)x >> 63) ^ SIGNBIT64);
    }
    return res;
}

uint64_t DSPV2_HELPER(add_u64_s)(uint64_t x, uint64_t y)
{
    /* rz = rx + ry, unsigned & saturated */
    uint64_t res = x + y;
    if (res < x || res < y) {
        res = 0xffffffffffffffff;
    }
    return res;
}

uint64_t DSPV2_HELPER(sub_s64_s)(uint64_t x, uint64_t y)
{
    /* rz = rx - ry, signed & saturated */
    uint64_t res = x - y;
    if (((res ^ x) & SIGNBIT64) && ((x ^ y) & SIGNBIT64)) {
        res = ~(((int64_t)x >> 63) ^ SIGNBIT64);
    }
    return res;
}

uint64_t DSPV2_HELPER(sub_u64_s)(uint64_t x, uint64_t y)
{
    /* rz = rx + ry, unsigned & saturated */
    uint64_t res = x - y;
    if (res > x) {
        res = 0;
    }
    return res;
}

uint32_t DSPV2_HELPER(lsli_32_s)(uint32_t x, uint32_t imm)
{
    /* Rz[31:0] <- Satur(Rx[31:0] << imm[4:0]) */
    return helper_sat_lsl(x, imm, 32);
}

uint32_t DSPV2_HELPER(lsl_32_s)(uint32_t x, uint32_t y)
{
    /* Rz[31:0] <- Satur(Rx[31:0] << ry[5:0]) */
    return helper_sat_lsl(x, y, 32);
}

uint32_t DSPV2_HELPER(plsli_u16_s)(uint32_t x, uint32_t imm)
{
    /* Rz[31:16] <- Saturate(Rx[31:16] << oimm[3:0]),
     * Rz[15:0] <- Saturate(Rx[15:0] << oimm[3:0]) */
    uint32_t hi, lo;
    hi = helper_sat_lsl((x & 0xffff0000) >> 16, imm, 16);
    lo = helper_sat_lsl(x & 0xffff, imm, 16);
    return hi << 16 | lo;
}

uint32_t DSPV2_HELPER(plsl_u16_s)(uint32_t x, uint32_t y)
{
    /* Rz[31:16] <- Saturate(Rx[31:16] << ry[3:0]),
     * Rz[15:0] <- Saturate(Rx[15:0] << ry[3:0]) */
    uint32_t hi, lo;
    hi = helper_sat_lsl((x & 0xffff0000) >> 16, y, 16);
    lo = helper_sat_lsl(x & 0xffff, y, 16);
    return hi << 16 | lo;
}

uint32_t DSPV2_HELPER(pcmpne_8)(uint32_t x, uint32_t y)
{
    uint32_t mask = 0xff;
    uint32_t i = 0;
    uint32_t res = 0;
    while (i < 4) {
        res |= ((x & mask) != (y & mask)) ? mask : 0;
        mask = mask << 8;
        i++;
    }
    return res;
}

uint32_t DSPV2_HELPER(pcmpne_16)(uint32_t x, uint32_t y)
{
    uint32_t mask = 0xffff;
    uint32_t res = 0;
    res |= ((x & mask) != (y & mask)) ? mask : 0;
    mask = mask << 16;
    res |= ((x & mask) != (y & mask)) ? mask : 0;
    return res;
}

uint32_t DSPV2_HELPER(pcmphs_u8)(uint32_t x, uint32_t y)
{
    uint32_t mask = 0xff;
    uint32_t i = 0;
    uint32_t res = 0;
    while (i < 4) {
        res |= ((x & mask) >= (y & mask)) ? mask : 0;
        mask = mask << 8;
        i++;
    }
    return res;
}

uint32_t DSPV2_HELPER(pcmphs_s8)(uint32_t x, uint32_t y)
{
    uint32_t mask = 0xff;
    uint32_t i = 0;
    uint32_t res = 0;
    while (i < 4) {
        int8_t byte_x, byte_y;
        byte_x = (x >> (i * 8)) & mask;
        byte_y = (x >> (i * 8)) & mask;
        res |= (byte_x >= byte_y) ? (mask << (i * 8)) : 0;
        i++;
    }
    return res;
}


uint32_t DSPV2_HELPER(pcmphs_u16)(uint32_t x, uint32_t y)
{
    uint32_t mask = 0xffff;
    uint32_t res = 0;
    res |= ((x & mask) >= (y & mask)) ? mask : 0;
    mask = mask << 16;
    res |= ((x & mask) >= (y & mask)) ? mask : 0;
    return res;
}

uint32_t DSPV2_HELPER(pcmphs_s16)(uint32_t x, uint32_t y)
{
    uint32_t mask = 0xffff;
    uint32_t res = 0;
    res |= ((int16_t)(x & mask) >= (int16_t)(y & mask)) ? mask : 0;
    mask = mask << 16;
    res |= ((int32_t)(x & mask) >= (int32_t)(y & mask)) ? mask : 0;
    return res;
}

uint32_t DSPV2_HELPER(pcmplt_u8)(uint32_t x, uint32_t y)
{
    uint32_t mask = 0xff;
    uint32_t i = 0;
    uint32_t res = 0;
    while (i < 4) {
        res |= ((x & mask) < (y & mask)) ? mask : 0;
        mask = mask << 8;
        i++;
    }
    return res;
}

uint32_t DSPV2_HELPER(pcmplt_s8)(uint32_t x, uint32_t y)
{
    uint32_t mask = 0xff;
    uint32_t i = 0;
    uint32_t res = 0;
    while (i < 4) {
        int8_t byte_x, byte_y;
        byte_x = (x >> (i * 8)) & mask;
        byte_y = (x >> (i * 8)) & mask;
        res |= (byte_x < byte_y) ? (mask << (i * 8)) : 0;
        i++;
    }
    return res;
}


uint32_t DSPV2_HELPER(pcmplt_u16)(uint32_t x, uint32_t y)
{
    uint32_t mask = 0xffff;
    uint32_t res = 0;
    res |= ((x & mask) < (y & mask)) ? mask : 0;
    mask = mask << 16;
    res |= ((x & mask) < (y & mask)) ? mask : 0;
    return res;
}

uint32_t DSPV2_HELPER(pcmplt_s16)(uint32_t x, uint32_t y)
{
    uint32_t mask = 0xffff;
    uint32_t res = 0;
    res |= ((int16_t)(x & mask) < (int16_t)(y & mask)) ? mask : 0;
    mask = mask << 16;
    res |= ((int32_t)(x & mask) < (int32_t)(y & mask)) ? mask : 0;
    return res;
}

uint32_t DSPV2_HELPER(pmax_s8)(uint32_t x, uint32_t y)
{
    uint32_t mask = 0xff;
    uint32_t i = 0;
    uint32_t res = 0;
    while (i < 4) {
        int8_t byte_x, byte_y;
        byte_x = (x >> (i * 8)) & mask;
        byte_y = (x >> (i * 8)) & mask;
        res |= (byte_x > byte_y) ? (byte_x << (i * 8)) : (byte_y << (i * 8));
        i++;
    }
    return res;
}

uint32_t DSPV2_HELPER(pmax_u8)(uint32_t x, uint32_t y)
{
    uint32_t mask = 0xff;
    uint32_t i = 0;
    uint32_t res = 0;
    while (i < 4) {
        res |= ((x & mask) > (y & mask)) ? (x & mask) : (y & mask);
        mask = mask << 8;
        i++;
    }
    return res;
}

uint32_t DSPV2_HELPER(pmin_s8)(uint32_t x, uint32_t y)
{
    uint32_t mask = 0xff;
    uint32_t i = 0;
    uint32_t res = 0;
    while (i < 4) {
        int8_t byte_x, byte_y;
        byte_x = (x >> (i * 8)) & mask;
        byte_y = (x >> (i * 8)) & mask;
        res |= (byte_x < byte_y) ? (byte_x << (i * 8)) : (byte_y << (i * 8));
        i++;
    }
    return res;
}

uint32_t DSPV2_HELPER(pmin_u8)(uint32_t x, uint32_t y)
{
    uint32_t mask = 0xff;
    uint32_t i = 0;
    uint32_t res = 0;
    while (i < 4) {
        res |= ((x & mask) > (y & mask)) ? (x & mask) : (y & mask);
        mask = mask << 8;
        i++;
    }
    return res;
}

uint64_t DSPV2_HELPER(pext_u8_e)(uint32_t x)
{
    uint8_t byte_x;
    uint32_t i = 0;
    uint64_t res = 0;
    while (i < 4) {
        byte_x = (x >> (i * 8)) & 0xff;
        res |= ((uint64_t)byte_x) << (i * 16);
        i++;
    }
    return res;
}

uint64_t DSPV2_HELPER(pext_s8_e)(uint32_t x)
{
    uint8_t byte_x;
    uint32_t i = 0;
    uint64_t res = 0;
    while (i < 4) {
        byte_x = (x >> (i * 8)) & 0xff;
        res |= (((int64_t)byte_x) & 0xffff) << (i * 16);
        i++;
    }
    return res;
}

uint64_t DSPV2_HELPER(pextx_u8_e)(uint32_t x)
{
    uint64_t res = 0;
    res |= x & 0xff;
    res |= x & 0xff0000;
    res |= (x & 0xff00) << 24;
    res |= (x & 0xff000000) << 24;
    return res;
}

uint64_t DSPV2_HELPER(pextx_s8_e)(uint32_t x)
{
    int8_t byte_x;
    uint64_t res = 0;
    byte_x = (x & 0xff);
    res |= ((int64_t)byte_x & 0xffff);
    byte_x = (x >> 8) & 0xff;
    res |= ((int64_t)byte_x & 0xffff) << 32;
    byte_x = (x >> 16) & 0xff;
    res |= ((int64_t)byte_x & 0xffff) << 16;
    byte_x = (x >> 24) & 0xff;
    res |= ((int64_t)byte_x & 0xffff) << 48;
    return res;
}

uint32_t DSPV2_HELPER(narl)(uint32_t x, uint32_t y)
{
    uint32_t mask_0 = 0xff;
    uint32_t mask_2 = 0xff0000;

    uint32_t res = 0;
    res |= x & mask_0;
    res |= (x & mask_2) >> 8;
    res |= (y & mask_0) << 16;
    res |= (y & mask_2) << 8;
    return res;
}

uint32_t DSPV2_HELPER(narh)(uint32_t x, uint32_t y)
{
    uint32_t mask_1 = 0xff00;
    uint32_t mask_3 = 0xff000000;

    uint32_t res = 0;
    res |= (x & mask_1) >> 8;
    res |= (x & mask_3) >> 16;
    res |= (y & mask_1) << 8;
    res |= y & mask_3;
    return res;
}

uint32_t DSPV2_HELPER(narlx)(uint32_t x, uint32_t y)
{
    uint32_t mask_02 = 0xff00ff;

    uint32_t res = 0;
    res |= x & mask_02;
    res |= (y & mask_02) << 8;
    return res;
}

uint32_t DSPV2_HELPER(narhx)(uint32_t x, uint32_t y)
{
    uint32_t mask_13 = 0xff00ff00;

    uint32_t res = 0;
    res |= (x & mask_13) >> 8;
    res |= y & mask_13;
    return res;
}

uint32_t DSPV2_HELPER(clipi_u32)(uint32_t x, uint32_t imm)
{
    uint32_t max = (1 << imm) -1;
    uint32_t res = 0;
    if (x > max) {
        res = max;
    } else {
        res = x;
    }
    return res;
}

uint32_t DSPV2_HELPER(clipi_s32)(uint32_t x, uint32_t imm)
{
    int32_t max = (1 << imm) - 1;
    int32_t min = -(1 << imm);
    uint32_t res = 0;
    if (x > max) {
        res = max;
    } else if (x < min) {
        res = min;
    }else {
        res = x;
    }
    return res;
}

uint32_t DSPV2_HELPER(clip_u32)(uint32_t x, uint32_t y)
{
    uint32_t max = (1 << (y & 0x1f)) -1;
    uint32_t res = 0;
    if (x > max) {
        res = max;
    } else {
        res = x;
    }
    return res;
}

uint32_t DSPV2_HELPER(clip_s32)(uint32_t x, uint32_t y)
{
    int32_t max = (1 << (y & 0x1f)) - 1;
    int32_t min = -(1 << (y & 0x1f));
    uint32_t res = 0;
    if (x > max) {
        res = max;
    } else if (x < min) {
        res = min;
    }else {
        res = x;
    }
    return res;
}

uint32_t DSPV2_HELPER(pclipi_u16)(uint32_t x, uint32_t imm)
{
    uint16_t max = (1 << imm) - 1;
    uint32_t res = 0;
    int16_t hword = x & 0xffff;
    if (hword > max) {
        hword = max;
    }
    res |= hword & 0xffff;
    hword = x >> 16;
    if (hword > max) {
        hword = max;
    }
    res |= hword << 16;
    return res;
}

uint32_t DSPV2_HELPER(pclipi_s16)(uint32_t x, uint32_t imm)
{
    int16_t max = (1 << imm) - 1;
    int16_t min = -(1 << (imm & 0xf));
    uint32_t res = 0;
    int16_t hword = x & 0xffff;
    if (hword > max) {
        hword = max;
    } else if (hword < min) {
        hword = min;
    }
    res |= hword & 0xffff;
    hword = x >> 16;
    if (hword > max) {
        hword = max;
    } else if (hword < min) {
        hword = min;
    }
    res |= hword << 16;
    return res;
}

uint32_t DSPV2_HELPER(pclip_u16)(uint32_t x, uint32_t y)
{
    uint16_t max = (1 << (y & 0xf)) - 1;
    uint32_t res = 0;
    int16_t hword = x & 0xffff;
    if (hword > max) {
        hword = max;
    }
    res |= hword & 0xffff;
    hword = x >> 16;
    if (hword > max) {
        hword = max;
    }
    res |= hword << 16;
    return res;
}

uint32_t DSPV2_HELPER(pclip_s16)(uint32_t x, uint32_t y)
{
    int16_t max = (1 << (y & 0xf)) - 1;
    int16_t min = -(1 << (y & 0xf));
    uint32_t res = 0;
    int16_t hword = x & 0xffff;
    if (hword > max) {
        hword = max;
    } else if (hword < min) {
        hword = min;
    }
    res |= hword & 0xffff;
    hword = x >> 16;
    if (hword > max) {
        hword = max;
    } else if (hword < min) {
        hword = min;
    }
    res |= hword << 16;
    return res;
}


uint32_t DSPV2_HELPER(pabs_s8_s)(uint32_t x)
{
    /* Rz[31:24] = Saturate(abs(Rx[31:24]))
     * Rz[23:16] = Saturate(abs(Rx[23:16]))
     * Rz[15:8] = Saturate(abs(Rx[15:8]))
     * Rz[7:0] = Saturate(abs(Rx[7:0])) */
    int8_t byte_x;
    uint32_t i = 0;
    uint64_t res = 0;
    while (i < 4) {
        byte_x = (x >> (i * 8)) & 0xff;
        if (byte_x == (int8_t)0x80) {
            byte_x = 0x7f;
        } else if (byte_x < 0) {
            byte_x = -byte_x;
        }
        res |= byte_x << (i * 8);
        i++;
    }
    return res;
}

uint32_t DSPV2_HELPER(pabs_s16_s)(uint32_t x)
{
    /* rz[15:0] = | rx[15:0] |, rz[31:16] = | rx[31:16] |, signed */
    int16_t lo, hi;
    lo = (int16_t)x;
    hi = (int16_t)(x >> 16);
    lo = lo > 0 ? lo : -lo;
    hi = hi > 0 ? hi : -hi;
    if (lo == (int16_t)0x8000) {
        lo = 0x7fff;
    }
    if (hi == (int16_t)0x8000) {
        hi = 0x7fff;
    }
    return (lo & 0xffff) | (hi << 16);
}

uint32_t DSPV2_HELPER(abs_s32_s)(uint32_t x)
{
    /* rz[31:0] = Saturate(abs(Rx[31:0])), signed */
    uint32_t res;
    if ((int32_t)x >= 0) {
        res = x;
    } else if (x == 0x80000000) {
        res = 0x7fffffff;
    } else {
        res = -x;
    }
    return res;
}

uint32_t DSPV2_HELPER(pneg_s8_s)(uint32_t x)
{
    /* Rz[31:24] = Saturate(neg(Rx[31:24]))
     * Rz[23:16] = Saturate(neg(Rx[23:16]))
     * Rz[15:8] = Saturate(neg(Rx[15:8]))
     * Rz[7:0] = Saturate(neg(Rx[7:0])) */
    int8_t byte_x;
    uint32_t i = 0;
    uint64_t res = 0;
    while (i < 4) {
        byte_x = -((x >> (i * 8)) & 0xff);
        if (byte_x == (int8_t)0x80) {
            byte_x = 0x7f;
        }
        res |= byte_x << (i * 8);
        i++;
    }
    return res;
}

uint32_t DSPV2_HELPER(pneg_s16_s)(uint32_t x)
{
    /* rz[15:0] = !rx[15:0], rz[31:16] = !rx[31:16] */
    int16_t lo, hi;
    lo = x & 0xffff;
    hi = x >> 16;
    lo = -lo;
    hi = -hi;
    if (lo == (int16_t)0x8000) {
        lo = 0x7fff;
    }
    if (hi == (int16_t)0x8000) {
        hi = 0x7fff;
    }
    return (lo & 0xffff) | (hi << 16);
}

uint32_t DSPV2_HELPER(neg_s32_s)(uint32_t x)
{
    /* Rz[31:0] = Saturate(neg(Rx[31:0])) */
    int32_t res = -((int32_t)x);
    if (res == (int32_t)0x80000000) {
        res = 0x7fffffff;
    }
    return res;
}

uint32_t DSPV2_HELPER(rmul_s32_h)(uint32_t x, uint32_t y)
{
    /* if(Rx[31:0] == 32’h8000 0000 && Ry[31:0] == 32’h8000 0000)
     *   Rz[31:0] = 32’h7FFF FFFF
     * else
     *   Rz[31:0] = {Rx[31:0] X Ry[31:0]}[62:31] */
    int64_t res;
    if ((x == 0x80000000) && (y == 0x80000000)) {
        return 0x7fffffff;
    } else {
        res = (int64_t)(int32_t)x * (int64_t)(int32_t)y;
        return res >> 31;
    }
}

uint32_t DSPV2_HELPER(rmul_s32_rh)(uint32_t x, uint32_t y)
{
    /* if(Rx[31:0] == 32’h8000 0000 && Ry[31:0] == 32’h8000 0000)
     *   Rz[31:0] = 32’h7FFF FFFF
     * else
     *   Rz[31:0] = {Rx[31:0] X Ry[31:0]}[62:31] */
    int64_t res;
    if ((x == 0x80000000) && (y == 0x80000000)) {
        return 0x7fffffff;
    } else {
        res = (int64_t)(int32_t)x * (int64_t)(int32_t)y + 0x40000000;
        return res >> 31;
    }
}

uint64_t DSPV2_HELPER(mula_s32_s)(uint32_t z, uint32_t z1,
                                  uint32_t x, uint32_t y)
{
    /* Rz[31:0] = Saturate( {Rz[31:0],Rz+1[31:0]}
     * + {Rx[31:0] X Ry[31:0]}[63:32] ) */
    int64_t res, xy;
    int64_t z_long = ((uint64_t)z1 << 32) + z;
    xy = (int64_t)(int32_t)x * (int64_t)(int32_t)y;
    res = xy + z_long;
    if (((res ^ z_long) & SIGNBIT64) && !((xy ^ z_long) & SIGNBIT64)) {
        res = ~(((int64_t)z_long >> 63) ^ SIGNBIT64);
    }
    return res;
}

uint64_t DSPV2_HELPER(mula_u32_s)(uint32_t z, uint32_t z1,
                                    uint32_t x, uint32_t y)
{
    /* Rz[31:0] = Saturate( {Rz[31:0],Rz+1[31:0]}
     * + {Rx[31:0] X Ry[31:0]}[63:32] ) */
    uint64_t res, xy;
    uint64_t z_long = ((uint64_t)z1 << 32) + z;
    xy = (uint64_t)x * (uint64_t)y;
    res = xy + z_long;
    if (res < xy || res < z_long) {
        res = 0xffffffffffffffff;
    }
    return res;
}

uint64_t DSPV2_HELPER(muls_s32_s)(uint32_t z, uint32_t z1,
                                  uint32_t x, uint32_t y)
{
    /* Rz[31:0] = Saturate( {Rz[31:0],Rz+1[31:0]}
     * - {Rx[31:0] X Ry[31:0]}[63:32] ) */
    int64_t res, xy;
    int64_t z_long = ((uint64_t)z1 << 32) + z;
    xy = (int64_t)(int32_t)x * (int64_t)(int32_t)y;
    res = z_long - xy;
    if (((res ^ z_long) & SIGNBIT64) && ((xy ^ z_long) & SIGNBIT64)) {
        res = ~(((int64_t)z_long >> 63) ^ SIGNBIT64);
    }
    return res;
}

uint64_t DSPV2_HELPER(muls_u32_s)(uint32_t z, uint32_t z1,
                                    uint32_t x, uint32_t y)
{
    /* Rz[31:0] = Saturate( {Rz[31:0],Rz+1[31:0]}
     * - {Rx[31:0] X Ry[31:0]}[63:32] ) */
    uint64_t res, xy;
    uint64_t z_long = ((uint64_t)z1 << 32) + z;
    xy = (uint64_t)x * (uint64_t)y;
    res = z_long - xy;
    if (res > z_long) {
        res = 0;
    }
    return res;
}

uint32_t DSPV2_HELPER(mula_32_l)(uint32_t z, uint32_t x, uint32_t y)
{
    /* Rz[31:0] =  Rz[31:0] + {Rx[31:0] X Ry[31:0]}[31:0] ) */
    return z + x * y;
}

uint32_t DSPV2_HELPER(mula_s32_hs)(uint32_t z, uint32_t x, uint32_t y)
{
    /* Rz[31:0] = Saturate( Rz[31:0] + {Rx[31:0] X Ry[31:0]}[63:32] ) */
    int32_t xy = ((int64_t)(int32_t)x * (int64_t)(int32_t)y) >> 32;
    return helper_sig_sat_add(z, xy, 32);
}

uint32_t DSPV2_HELPER(muls_s32_hs)(uint32_t z, uint32_t x, uint32_t y)
{
    /* Rz[31:0] = Saturate( Rz[31:0] + {Rx[31:0] X Ry[31:0]}[63:32] ) */
    int32_t xy = ((int64_t)(int32_t)x * (int64_t)(int32_t)y) >> 32;
    return helper_sig_sat_sub(z, xy, 32);
}

uint32_t DSPV2_HELPER(mula_s32_rhs)(uint32_t z, uint32_t x, uint32_t y)
{
    /* Rz[31:0] = Saturate( Rz[31:0] + {Rx[31:0] X Ry[31:0]
     * + 32’h80000000}[63:32] ) */
    int32_t xy = ((int64_t)(int32_t)x * (int64_t)(int32_t)y
                  + 0x80000000) >> 32;
    return helper_sig_sat_add(z, xy, 32);
}

uint32_t DSPV2_HELPER(muls_s32_rhs)(uint32_t z, uint32_t x, uint32_t y)
{
    /* Rz[31:0] = Saturate( Rz[31:0] + {Rx[31:0] X Ry[31:0]
     * + 32’h80000000}[63:32] ) */
    int64_t xy = (int64_t)(int32_t)x * (int64_t)(int32_t)y - 0x80000000;
    int64_t z_long = (uint64_t)z << 32;
    int64_t res = z_long - xy;
    if (((res ^ z_long) & SIGNBIT64) && ((xy ^ z_long) & SIGNBIT64)) {
        res = ~(((int64_t)z_long >> 63) ^ SIGNBIT64);
    }
    return res >> 32;
}

uint32_t DSPV2_HELPER(rmulxl_s32)(uint32_t x, uint32_t y)
{
    /* if(Rx[31:0] == 32’h8000 0000 && Ry[15:0] == 32’h8000)
     *   Rz[31:0] = 32’h7FFF FFFF
     * else
     *   Rz[31:0] = {Rx[31:0] X Ry[15:0]}[46:15] */
    int64_t res;
    int16_t tmp_y = y & 0xffff;
    if ((x == 0x80000000) && (tmp_y == (int16_t)0x8000)) {
        return 0x7fffffff;
    } else {
        res = (int64_t)(int32_t)x * (int64_t)tmp_y;
        return res >> 15;
    }
}

uint32_t DSPV2_HELPER(rmulxl_s32_r)(uint32_t x, uint32_t y)
{
    /* if(Rx[31:0] == 32’h8000 0000 && Ry[15:0] == 32’h8000)
     *   Rz[31:0] = 32’h7FFF FFFF
     * else
     *   Rz[31:0] = {Rx[31:0] X Ry[15:0]}[46:15] */
    int64_t res;
    int16_t tmp_y = y & 0xffff;
    if ((x == 0x80000000) && (tmp_y == (int16_t)0x8000)) {
        return 0x7fffffff;
    } else {
        res = (int64_t)(int32_t)x * (int64_t)tmp_y + 0x4000;
        return res >> 15;
    }
}

uint32_t DSPV2_HELPER(rmulxh_s32)(uint32_t x, uint32_t y)
{
    /* if(Rx[31:0] == 32’h8000 0000 && Ry[31:16] == 32’h8000)
     *   Rz[31:0] = 32’h7FFF FFFF
     * else
     *   Rz[31:0] = {Rx[31:0] X Ry[31:16]}[46:15] */
    int64_t res;
    int16_t tmp_y = y >> 16;
    if ((x == 0x80000000) && (tmp_y == (int16_t)0x8000)) {
        return 0x7fffffff;
    } else {
        res = (int64_t)(int32_t)x * (int64_t)tmp_y;
        return res >> 15;
    }
}

uint32_t DSPV2_HELPER(rmulxh_s32_r)(uint32_t x, uint32_t y)
{
    /* if(Rx[31:0] == 32’h8000 0000 && Ry[31:16] == 32’h8000)
     *   Rz[31:0] = 32’h7FFF FFFF
     * else
     *   Rz[31:0] = {Rx[31:0] X Ry[31:16]}[46:15] */
    int64_t res;
    int16_t tmp_y = y >> 16;
    if ((x == 0x80000000) && (tmp_y == (int16_t)0x8000)) {
        return 0x7fffffff;
    } else {
        res = (int64_t)(int32_t)x * (int64_t)tmp_y + 0x4000;
        return res >> 15;
    }
}

uint32_t DSPV2_HELPER(mulaxl_s32_s)(uint32_t z, uint32_t x, uint32_t y)
{
    /* Rz[31:0] = Saturate( Rz[31:0] + {Rx[31:0] X Ry[15:0]}[63:32] ) */
    int16_t tmp_y = y & 0xffff;
    int32_t xy = ((int64_t)(int32_t)x * (int64_t)tmp_y) >> 16;
    return helper_sig_sat_add(z, xy, 32);
}

uint32_t DSPV2_HELPER(mulaxl_s32_rs)(uint32_t z, uint32_t x, uint32_t y)
{
    int16_t tmp_y = y & 0xffff;
    int32_t xy = ((int64_t)x * (int64_t)tmp_y + 0xf000) >> 16;
    return helper_sig_sat_add(z, xy, 32);
}

uint32_t DSPV2_HELPER(mulaxh_s32_s)(uint32_t z, uint32_t x, uint32_t y)
{
    /* Rz[31:0] = Saturate( Rz[31:0] + {Rx[31:0] X Ry[31:16]}[63:32] ) */
    int16_t tmp_y = y >> 16;
    int32_t xy = ((int64_t)(int32_t)x * (int64_t)tmp_y) >> 16;
    return helper_sig_sat_add(z, xy, 32);
}

uint32_t DSPV2_HELPER(mulaxh_s32_rs)(uint32_t z, uint32_t x, uint32_t y)
{
    int16_t tmp_y = y >> 16;
    int32_t xy = ((int64_t)(int32_t)x * (int64_t)tmp_y + 0xf000) >> 16;
    return helper_sig_sat_add(z, xy, 32);
}

uint32_t DSPV2_HELPER(rmulll_s16)(uint32_t x, uint32_t y)
{
    /* if(Rx[15:0] == 32’h8000 && Ry[15:0] == 32’h8000)
     *   Rz[31:0] = 32’h7FFF FFFF
     * else
     *   Rz[31:0] = {Rx[15:0] X Ry[15:0]} << 1 */
    int16_t tmp_x = x & 0xffff;
    int16_t tmp_y = y & 0xffff;
    if ((tmp_x == (int16_t)0x8000) && (tmp_y == (int16_t)0x8000)) {
        return 0x7fffffff;
    } else {
        return ((int32_t)tmp_x * (int32_t)tmp_y) << 1;
    }
}

uint32_t DSPV2_HELPER(rmulhh_s16)(uint32_t x, uint32_t y)
{
    /* if(Rx[31:16] == 32’h8000 && Ry[31:16] == 32’h8000)
     *   Rz[31:0] = 32’h7FFF FFFF
     * else
     *   Rz[31:0] = {Rx[31:16] X Ry[31:16]} << 1 */
    int16_t tmp_x = x >> 16;
    int16_t tmp_y = y >> 16;
    if ((tmp_x == (int16_t)0x8000) && (tmp_y == (int16_t)0x8000)) {
        return 0x7fffffff;
    } else {
        return ((int32_t)tmp_x * (int32_t)tmp_y) << 1;
    }
}

uint32_t DSPV2_HELPER(rmulhl_s16)(uint32_t x, uint32_t y)
{
    /* if(Rx[31:16] == 32’h8000 && Ry[15:0] == 32’h8000)
     *   Rz[31:0] = 32’h7FFF FFFF
     * else
     *   Rz[31:0] = {Rx[31:16] X Ry[15:0]} << 1 */
    int16_t tmp_x = x >> 16;
    int16_t tmp_y = y & 0xffff;
    if ((tmp_x == (int16_t)0x8000) && (tmp_y == (int16_t)0x8000)) {
        return 0x7fffffff;
    } else {
        return ((int32_t)tmp_x * (int32_t)tmp_y) << 1;
    }
}

uint32_t DSPV2_HELPER(mulall_s16)(uint32_t z, uint32_t x, uint32_t y)
{
    /* Rz[31:0] = Rz[31:0] + Rx[15:0] X Ry[15:0]) */
    int16_t tmp_x = x & 0xffff;
    int16_t tmp_y = y & 0xffff;
    return z + (int32_t)tmp_x * (int32_t)tmp_y;
}

uint32_t DSPV2_HELPER(mulall_s16_s)(uint32_t z, uint32_t x, uint32_t y)
{
    /* Rz[31:0] = Saturate(Rz[31:0] + Rx[15:0] X Ry[15:0]) */
    int16_t tmp_x = x & 0xffff;
    int16_t tmp_y = y & 0xffff;
    int32_t xy = (int32_t)tmp_x * (int32_t)tmp_y;
    return helper_sig_sat_add(z, xy, 32);
}

uint32_t DSPV2_HELPER(mulahh_s16_s)(uint32_t z, uint32_t x, uint32_t y)
{
    /* Rz[31:0] = Saturate(Rz[31:0] + Rx[31:16] X Ry[31:16]) */
    int16_t tmp_x = x >> 16;
    int16_t tmp_y = y >> 16;
    int32_t xy = (int32_t)tmp_x * (int32_t)tmp_y;
    return helper_sig_sat_add(z, xy, 32);
}

uint32_t DSPV2_HELPER(mulahl_s16_s)(uint32_t z, uint32_t x, uint32_t y)
{
    /* Rz[31:0] = Saturate(Rz[31:0] + Rx[31:16] X Ry[15:0]) */
    int16_t tmp_x = x >> 16;
    int16_t tmp_y = y & 0xffff;
    int32_t xy = (int32_t)tmp_x * (int32_t)tmp_y;
    return helper_sig_sat_add(z, xy, 32);
}

uint64_t DSPV2_HELPER(mulall_s16_e)(uint32_t z, uint32_t z1,
                                    uint32_t x, uint32_t y)
{
    /* {Rz+1[31:0],Rz[31:0]} = {Rz+1[31:0],Rz[31:0]} + Rx[15:0] X Ry[15:0] */
    int64_t res = ((uint64_t)z1 << 32) + z;
    int16_t tmp_x = x & 0xffff;
    int16_t tmp_y = y & 0xffff;
    int64_t xy = (int64_t)tmp_x * (int64_t)tmp_y;
    return res + xy;
}

uint64_t DSPV2_HELPER(mulahh_s16_e)(uint32_t z, uint32_t z1,
                                    uint32_t x, uint32_t y)
{
    /* {Rz+1[31:0],Rz[31:0]} = {Rz+1[31:0],Rz[31:0]} + Rx[31:16] X Ry[31:16] */
    int64_t res = ((uint64_t)z1 << 32) + z;
    int16_t tmp_x = x >> 16;
    int16_t tmp_y = y >> 16;
    int64_t xy = (int64_t)tmp_x * (int64_t)tmp_y;
    return res + xy;
}

uint64_t DSPV2_HELPER(mulahl_s16_e)(uint32_t z, uint32_t z1,
                                    uint32_t x, uint32_t y)
{
    /* {Rz+1[31:0],Rz[31:0]} = {Rz+1[31:0],Rz[31:0]} + Rx[31:16] X Ry[15:0] */
    int64_t res = ((uint64_t)z1 << 32) + z;
    int16_t tmp_x = x >> 16;
    int16_t tmp_y = y & 0xffff;
    int64_t xy = (int64_t)tmp_x * (int64_t)tmp_y;
    return res + xy;
}

uint64_t DSPV2_HELPER(prmul_s16)(uint32_t x, uint32_t y)
{
    uint64_t res = 0;
    int16_t tmp_x = x >> 16;
    int16_t tmp_y = y >> 16;
    if ((tmp_x == (int16_t)0x8000) && (tmp_y == (int16_t)0x8000)) {
        res |= (uint64_t)0x7fffffff << 32;
    } else {
        res |= (uint64_t)((int32_t)tmp_x * (int32_t)tmp_y) << 33;
    }
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    if ((tmp_x == (int16_t)0x8000) && (tmp_y == (int16_t)0x8000)) {
        res |= 0x7fffffff;
    } else {
        res |= (((int64_t)tmp_x * (int64_t)tmp_y) << 1) & 0xffffffff;
    }
    return res;
}

uint64_t DSPV2_HELPER(prmulx_s16)(uint32_t x, uint32_t y)
{
    uint64_t res = 0;
    int16_t tmp_x = x >> 16;
    int16_t tmp_y = y & 0xffff;
    if ((tmp_x == (int16_t)0x8000) && (tmp_y == (int16_t)0x8000)) {
        res |= (uint64_t)0x7fffffff << 32;
    } else {
        res |= (uint64_t)((int32_t)tmp_x * (int32_t)tmp_y) << 33;
    }
    tmp_x = x & 0xffff;
    tmp_y = y >> 16;
    if ((tmp_x == (int16_t)0x8000) && (tmp_y == (int16_t)0x8000)) {
        res |= 0x7fffffff;
    } else {
        res |= (((int64_t)tmp_x * (int64_t)tmp_y) << 1) & 0xffffffff;
    }
    return res;
}

uint32_t DSPV2_HELPER(prmul_s16_h)(uint32_t x, uint32_t y)
{
    uint32_t res = 0;
    int16_t tmp_x = x >> 16;
    int16_t tmp_y = y >> 16;
    if ((tmp_x == (int16_t)0x8000) && (tmp_y == (int16_t)0x8000)) {
        res |= 0x7fff0000;
    } else {
        res |= (((int32_t)tmp_x * (int32_t)tmp_y) << 1) & 0xffff0000;
    }
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    if ((tmp_x == (int16_t)0x8000) && (tmp_y == (int16_t)0x8000)) {
        res |= 0x7fff;
    } else {
        res |= (((int32_t)tmp_x * (int32_t)tmp_y) >>15) & 0xffff;
    }
    return res;
}

uint32_t DSPV2_HELPER(prmul_s16_rh)(uint32_t x, uint32_t y)
{
    uint32_t res = 0;
    int16_t tmp_x = x >> 16;
    int16_t tmp_y = y >> 16;
    if ((tmp_x == (int16_t)0x8000) && (tmp_y == (int16_t)0x8000)) {
        res |= 0x7fff0000;
    } else {
        res |= (((int32_t)tmp_x * (int32_t)tmp_y + 0x4000) << 1) & 0xffff0000;
    }
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    if ((tmp_x == (int16_t)0x8000) && (tmp_y == (int16_t)0x8000)) {
        res |= 0x7fff;
    } else {
        res |= (((int32_t)tmp_x * (int32_t)tmp_y + 0x4000) >>15) & 0xffff;
    }
    return res;
}

uint32_t DSPV2_HELPER(prmulx_s16_h)(uint32_t x, uint32_t y)
{
    uint32_t res = 0;
    int16_t tmp_x = x >> 16;
    int16_t tmp_y = y & 0xffff;
    if ((tmp_x == (int16_t)0x8000) && (tmp_y == (int16_t)0x8000)) {
        res |= 0x7fff0000;
    } else {
        res |= (((int32_t)tmp_x * (int32_t)tmp_y) << 1) & 0xffff0000;
    }
    tmp_x = x & 0xffff;
    tmp_y = y >> 16;
    if ((tmp_x == (int16_t)0x8000) && (tmp_y == (int16_t)0x8000)) {
        res |= 0x7fff;
    } else {
        res |= (((int32_t)tmp_x * (int32_t)tmp_y) >>15) & 0xffff;
    }
    return res;
}

uint32_t DSPV2_HELPER(prmulx_s16_rh)(uint32_t x, uint32_t y)
{
    uint32_t res = 0;
    int16_t tmp_x = x >> 16;
    int16_t tmp_y = y & 0xffff;
    if ((tmp_x == (int16_t)0x8000) && (tmp_y == (int16_t)0x8000)) {
        res |= 0x7fff0000;
    } else {
        res |= (((int32_t)tmp_x * (int32_t)tmp_y + 0x4000) << 1) & 0xffff0000;
    }
    tmp_x = x & 0xffff;
    tmp_y = y >> 16;
    if ((tmp_x == (int16_t)0x8000) && (tmp_y == (int16_t)0x8000)) {
        res |= 0x7fff;
    } else {
        res |= (((int32_t)tmp_x * (int32_t)tmp_y + 0x4000) >>15) & 0xffff;
    }
    return res;
}

uint32_t DSPV2_HELPER(mulca_s16_s)(uint32_t x, uint32_t y)
{
    int16_t tmp_x;
    int16_t tmp_y;
    int32_t res;
    if ((x == 0x80008000) && (y == 0x80008000)) {
        res = 0x7fffffff;
    } else {
        tmp_x = x & 0xffff;
        tmp_y = y & 0xffff;
        res = ((int32_t)x >> 16) * ((int32_t)y >> 16)
            + (int32_t)tmp_x * (int32_t)tmp_y;
    }
    return res;
}

uint32_t DSPV2_HELPER(mulcax_s16_s)(uint32_t x, uint32_t y)
{
    int16_t tmp_x;
    int16_t tmp_y;
    int32_t res;
    if ((x == 0x80008000) && (y == 0x80008000)) {
        res = 0x7fffffff;
    } else {
        tmp_x = x & 0xffff;
        tmp_y = y & 0xffff;
        res = ((int32_t)x >> 16) * (int32_t)tmp_y
            + (int32_t)tmp_x * ((int32_t)y >> 16);
    }
    return res;
}

uint32_t DSPV2_HELPER(mulaca_s16_s)(uint32_t z, uint32_t x, uint32_t y)
{
    int16_t tmp_x;
    int16_t tmp_y;
    int32_t res;
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    res = ((int32_t)x >> 16) * ((int32_t)y >> 16)
        + (int32_t)tmp_x * (int32_t)tmp_y;
    return helper_sig_sat_add(z, res, 32);
}

uint32_t DSPV2_HELPER(mulacax_s16_s)(uint32_t z, uint32_t x, uint32_t y)
{
    int16_t tmp_x;
    int16_t tmp_y;
    int32_t res;
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    res = ((int32_t)x >> 16) * (int32_t)tmp_y
        + (int32_t)tmp_x * ((int32_t)y >> 16);
    return helper_sig_sat_add(z, res, 32);
}

uint32_t DSPV2_HELPER(mulacs_s16_s)(uint32_t z, uint32_t x, uint32_t y)
{
    int16_t tmp_x;
    int16_t tmp_y;
    int32_t res;
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    res = (int32_t)tmp_x * (int32_t)tmp_y
        - ((int32_t)x >> 16) * ((int32_t)y >> 16);
    return helper_sig_sat_add(z, res, 32);
}

uint32_t DSPV2_HELPER(mulacsr_s16_s)(uint32_t z, uint32_t x, uint32_t y)
{
    int16_t tmp_x;
    int16_t tmp_y;
    int32_t res;
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    res = ((int32_t)x >> 16) * ((int32_t)y >> 16)
        - (int32_t)tmp_x * (int32_t)tmp_y;
    return helper_sig_sat_add(z, res, 32);
}

uint32_t DSPV2_HELPER(mulacsx_s16_s)(uint32_t z, uint32_t x, uint32_t y)
{
    int16_t tmp_x;
    int16_t tmp_y;
    int32_t res;
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    res = (int32_t)tmp_x * ((int32_t)y >> 16)
        - ((int32_t)x >> 16) * (int32_t)tmp_y;
    return helper_sig_sat_add(z, res, 32);
}

uint32_t DSPV2_HELPER(mulsca_s16_s)(uint32_t z, uint32_t x, uint32_t y)
{
    int16_t tmp_x;
    int16_t tmp_y;
    int32_t res;
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    res = ((int32_t)x >> 16) * ((int32_t)y >> 16)
        + (int32_t)tmp_x * (int32_t)tmp_y;
    return helper_sig_sat_sub(z, res, 32);
}

uint32_t DSPV2_HELPER(mulscax_s16_s)(uint32_t z, uint32_t x, uint32_t y)
{
    int16_t tmp_x;
    int16_t tmp_y;
    int32_t res;
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    res = ((int32_t)x >> 16) * (int32_t)tmp_y
        + (int32_t)tmp_x * ((int32_t)y >> 16);
    return helper_sig_sat_sub(z, res, 32);
}

uint32_t DSPV2_HELPER(psabsa_u8)(uint32_t x, uint32_t y)
{
    uint32_t res = 0;
    uint32_t i = 0;
    uint8_t tmp_sub;
    while (i < 4) {
        tmp_sub = ((x >> (i * 8)) - (y >> (i * 8))) & 0xff;
        res += (tmp_sub > 0) ? tmp_sub : -tmp_sub;
        i++;
    }
    return res;
}

uint32_t DSPV2_HELPER(psabsaa_u8)(uint32_t z, uint32_t x, uint32_t y)
{
    uint32_t res = 0;
    uint32_t i = 0;
    uint8_t tmp_sub;
    while (i < 4) {
        tmp_sub = ((x >> (i * 8)) - (y >> (i * 8))) & 0xff;
        res += (tmp_sub > 0) ? tmp_sub : -tmp_sub;
        i++;
    }
    return res + z;
}

