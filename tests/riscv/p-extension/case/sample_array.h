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

#include "test_device.h"
#ifndef SAMPLE_ARRAY_H
#define SAMPLE_ARRAY_H

#ifdef RV32
/* stsa16 */
struct binary_calculation samples_stsa16[] = {
    {0x00015678, 0x00012222, 0x0000789a},
    {0xffffa000, 0x0001b000, 0xfffe5000},
    {0x00018000, 0x00028000, 0xffff0000},
    {0x0001ffff, 0x0002ffff, 0xfffffffe},
    {0x00020000, 0x0001ffff, 0x0001ffff},
    {0x00007fff, 0xffff8000, 0x0001ffff},
    {0x0000ffff, 0xffff0000, 0x0001ffff},
    {0x00008888, 0x00008888, 0x00001110},
    {0x00008888, 0xffff8888, 0x00011110},
    {0xffff8888, 0x00008888, 0xffff1110},
    {0xffff8888, 0xffff8888, 0x00001110},
    {0x1111ffff, 0x20200000, 0xf0f1ffff},
};

/* rstsa16 */
struct binary_calculation samples_rstsa16[] = {
    {0x00010001, 0x00010001, 0x00000001},
    {0xffffffff, 0x0001ffff, 0xffffffff},
    {0xffff7fff, 0xffff0001, 0x00004000},
    {0x7fffffff, 0xffff0001, 0x40000000},
    {0x00008000, 0x0001ffff, 0xffffbfff},
    {0x80008000, 0x00000000, 0xc000c000},
    {0xffff7fff, 0x00000000, 0xffff3fff},
    {0x0000ffff, 0x00000000, 0x0000ffff},
    {0xffff8000, 0x00000000, 0xffffc000},
    {0x00000000, 0xffff0000, 0x00000000},
    {0x80007fff, 0x7fff8000, 0x8000ffff},
    {0x0001ffff, 0x00010000, 0x0000ffff},
    {0x00007ff9, 0x00017fff, 0xffff7ffc},
};

/* urstsa16 */
struct binary_calculation samples_urstsa16[] = {
    {0x00010001, 0x00010001, 0x00000001},
    {0x00020002, 0x00020002, 0x00000002},
    {0x0001ffff, 0x00020001, 0xffff8000},
    {0x00010000, 0x00020001, 0xffff0000},
    {0x0000ffff, 0xffff0001, 0x80008000},
    {0xffff0000, 0x0000ffff, 0x7fff7fff},
    {0x1111ffff, 0x2222ffff, 0xf777ffff},
    {0x11117fff, 0x22227fff, 0xf7777fff},
};

/* kstsa16 */
struct binary_calculation samples_kstsa16[] = {
    {0x00010001, 0x00010001, 0x00000002},
    {0x00020001, 0x0001ffff, 0x00010000},
    {0xfffeffff, 0xffffffff, 0xfffffffe},
    {0x00000001, 0xffffffff, 0x00010000},
    {0x00000001, 0x0000ffff, 0x00000000},
    {0xffff0001, 0x0000ffff, 0xffff0000},
    {0x80000001, 0x7fff7fff, 0x80007fff},
    {0x7fff0000, 0xffffffff, 0x7fffffff},
    {0x7f7f8000, 0xffff0001, 0x7f808001},
    {0x80000000, 0x00010001, 0x80000001},
    {0x0000ffff, 0x00010000, 0xffffffff},
    {0x22227fff, 0x11110000, 0x11117fff},
    {0x22227fff, 0x11118000, 0x1111ffff},
    {0x22220000, 0x11110000, 0x11110000},
    {0x22220000, 0x11118000, 0x11118000},
    {0x2222aaaa, 0x1111bbbb, 0x11118000},
};

/* ukstsa16 */
struct binary_calculation samples_ukstsa16[] = {
    {0x00010001, 0x00010001, 0x00000002},
    {0x00020001, 0x00018000, 0x00018001},
    {0x00000001, 0xffffffff, 0x0000ffff},
    {0xffff0001, 0x0000ffff, 0xffffffff},
    {0x00000000, 0x00010000, 0x00000000},
    {0x0000ffff, 0x0001ffff, 0x0000ffff},
    {0x0000ffff, 0x0001ffff, 0x0000ffff},
    {0x00010000, 0x0002ffff, 0x0000ffff},
    {0x00020000, 0x00010000, 0x00010000},
    {0x00010000, 0x00020000, 0x00000000},
    {0x11110000, 0x2222ffff, 0x0000ffff},
    {0x11110000, 0x2222ff00, 0x0000ff00},
    {0x11118888, 0x22228888, 0x0000ffff},
};

/* stas16 */
struct binary_calculation samples_stas16[] = {
    {0x56780001, 0x22220001, 0x789a0000},
    {0xa000ffff, 0xb0000001, 0x5000fffe},
    {0x80000001, 0x80000002, 0x0000ffff},
    {0xffff0001, 0xffff0002, 0xfffeffff},
    {0x00000002, 0xffff0001, 0xffff0001},
    {0x7fff0000, 0x8000ffff, 0xffff0001},
    {0xffff0000, 0x0000ffff, 0xffff0001},
    {0x88880000, 0x88880000, 0x11100000},
    {0x88880000, 0x8888ffff, 0x11100001},
    {0x8888ffff, 0x88880000, 0x1110ffff},
    {0x8888ffff, 0x8888ffff, 0x11100000},
    {0xffff1111, 0x00002020, 0xfffff0f1},
};

/* rstas16 */
struct binary_calculation samples_rstas16[] = {
    {0x00010001, 0x00010001, 0x00010000},
    {0xffffffff, 0xffff0001, 0xffffffff},
    {0x7fffffff, 0x0001ffff, 0x40000000},
    {0xffff7fff, 0x0001ffff, 0x00004000},
    {0x80000000, 0xffff0001, 0xbfffffff},
    {0x80008000, 0x00000000, 0xc000c000},
    {0x7fffffff, 0x00000000, 0x3fffffff},
    {0xffff0000, 0x00000000, 0xffff0000},
    {0x8000ffff, 0x00000000, 0xc000ffff},
    {0x00000000, 0x0000ffff, 0x00000000},
    {0x7fff8000, 0x80007fff, 0xffff8000},
    {0xffff0001, 0x00000001, 0xffff0000},
    {0x7ff90000, 0x7fff0001, 0x7ffcffff},
};

/* urstas16 */
struct binary_calculation samples_urstas16[] = {
    {0x00010001, 0x00010001, 0x00010000},
    {0x00020002, 0x00020002, 0x00020000},
    {0xffff0001, 0x00010002, 0x8000ffff},
    {0x00000001, 0x00010002, 0x0000ffff},
    {0xffff0000, 0x0001ffff, 0x80008000},
    {0x0000ffff, 0xffff0000, 0x7fff7fff},
    {0xffff1111, 0xffff2222, 0xfffff777},
    {0x7fff1111, 0x7fff2222, 0x7ffff777},
};

/* kstas16 */
struct binary_calculation samples_kstas16[] = {
    {0x00010001, 0x00010001, 0x00020000},
    {0x00010002, 0xffff0001, 0x00000001},
    {0xfffffffe, 0xffffffff, 0xfffeffff},
    {0x00010000, 0xffffffff, 0x00000001},
    {0x00010000, 0xffff0000, 0x00000000},
    {0x0001ffff, 0xffff0000, 0x0000ffff},
    {0x00018000, 0x7fff7fff, 0x7fff8000},
    {0x00007fff, 0xffffffff, 0xffff7fff},
    {0x80007f7f, 0x0001ffff, 0x80017f80},
    {0x00008000, 0x00010001, 0x00018000},
    {0xffff0000, 0x00000001, 0xffffffff},
    {0x7fff2222, 0x00001111, 0x7fff1111},
    {0x7fff2222, 0x80001111, 0xffff1111},
    {0x00002222, 0x00001111, 0x00001111},
    {0x00002222, 0x80001111, 0x80001111},
    {0xaaaa2222, 0xbbbb1111, 0x80001111},
};

/* ukstas16 */
struct binary_calculation samples_ukstas16[] = {
    {0x00010001, 0x00010001, 0x00020000},
    {0x00010002, 0x80000001, 0x80010001},
    {0x00010000, 0xffffffff, 0xffff0000},
    {0x0001ffff, 0xffff0000, 0xffffffff},
    {0x00000000, 0x00000001, 0x00000000},
    {0xffff0000, 0xffff0001, 0xffff0000},
    {0xffff0000, 0xffff0001, 0xffff0000},
    {0x00000001, 0xffff0002, 0xffff0000},
    {0x00000002, 0x00000001, 0x00000001},
    {0x00000001, 0x00000002, 0x00000000},
    {0x00001111, 0xffff2222, 0xffff0000},
    {0x00001111, 0xff002222, 0xff000000},
    {0x88881111, 0x88882222, 0xffff0000},
};

/* sub8 */
struct binary_calculation samples_sub8[] = {
    {0x00000001, 0x00000001, 0x00000000},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0x00000001, 0xffffffff, 0x01010102},
    {0xffffffff, 0x00000001, 0xfffffffe},
    {0x00000000, 0x7fffffff, 0x81010101},
    {0x00000000, 0x80000000, 0x80000000},
    {0x00000000, 0xffffffff, 0x01010101},
    {0xffffffff, 0x80000000, 0x7fffffff},
    {0x80000000, 0xffffffff, 0x81010101},
    {0xffffffff, 0x7fffffff, 0x80000000},
    {0x22221111, 0x11112020, 0x1111f1f1},
};

/* sub16 */
struct binary_calculation samples_sub16[] = {
    {0x00010001, 0x00010001, 0x00000000},
    {0x0001ffff, 0x00020001, 0xfffffffe},
    {0xffff0001, 0x00010002, 0xfffeffff},
    {0x00010001, 0x00020002, 0xffffffff},
    {0x00020002, 0x00010001, 0x00010001},
    {0x00000000, 0xffffffff, 0x00010001},
    {0x00000000, 0x7fffffff, 0x80010001},
    {0x00000000, 0x80000000, 0x80000000},
    {0x80000000, 0x7fffffff, 0x00010001},
    {0x7fffffff, 0x80000000, 0xffffffff},
    {0x7fffffff, 0xffffffff, 0x80000000},
    {0x88881111, 0x11112020, 0x7777f0f1},
};

/* add8 */
struct binary_calculation samples_add8[] = {
    {0x00000000, 0x11111111, 0x11111111},
    {0x00000001, 0x00000001, 0x00000002},
    {0xff000000, 0x01000000, 0x00000000},
    {0xffffffff, 0x01010101, 0x00000000},
    {0x80808080, 0x80808080, 0x00000000},
    {0x7f7f7f7f, 0x01010101, 0x80808080},
    {0x00000000, 0xffffffff, 0xffffffff},
    {0xffffffff, 0xffffffff, 0xfefefefe},
    {0x11888888, 0x22888888, 0x33101010},
};

/* sra8 */
struct binary_calculation samples_sra8[] = {
    {0x40302010, 0x00000001, 0x20181008},
    {0x40302010, 0x00000002, 0x100c0804},
    {0x40302010, 0x00000004, 0x04030201},
    {0x40302010, 0x00000007, 0x00000000},
    {0xf4f3f2f1, 0x00000001, 0xfaf9f9f8},
    {0xf4f3f2f1, 0x00000002, 0xfdfcfcfc},
    {0xf4f3f2f1, 0x00000004, 0xffffffff},
    {0xf4f3f2f1, 0x00000007, 0xffffffff},
    {0xffffffff, 0x00000003, 0xffffffff},
    {0x7f7f7f7f, 0x00000003, 0x0f0f0f0f},
    {0x80808080, 0x00000003, 0xf0f0f0f0},
};

/* sra8.u */
struct binary_calculation samples_sra8_u[] = {
    {0x40302010, 0x00000001, 0x20181008},
    {0x40302010, 0x00000002, 0x100c0804},
    {0x40302010, 0x00000004, 0x04030201},
    {0x40302010, 0x00000007, 0x01000000},
    {0xf4f3f2f1, 0x00000001, 0xfafaf9f9},
    {0xf4f3f2f1, 0x00000002, 0xfdfdfdfc},
    {0xf4f3f2f1, 0x00000004, 0xffffffff},
    {0xf4f3f2f1, 0x00000007, 0x00000000},
    {0xffffffff, 0x00000003, 0x00000000},
    {0x7f7f7f7f, 0x00000003, 0x10101010},
    {0x80808080, 0x00000003, 0xf0f0f0f0},
};

/* srai8 */
struct binary_calculation samples_srai8[] = {
    {0x40302010, 0x00000001, 0x20181008},
    {0x40302010, 0x00000002, 0x100c0804},
    {0x40302010, 0x00000004, 0x04030201},
    {0x40302010, 0x00000007, 0x00000000},
    {0xf4f3f2f1, 0x00000001, 0xfaf9f9f8},
    {0xf4f3f2f1, 0x00000002, 0xfdfcfcfc},
    {0xf4f3f2f1, 0x00000004, 0xffffffff},
    {0xf4f3f2f1, 0x00000007, 0xffffffff},
    {0xffffffff, 0x00000003, 0xffffffff},
    {0x7f7f7f7f, 0x00000003, 0x0f0f0f0f},
    {0x80808080, 0x00000003, 0xf0f0f0f0},
};

/* srai8.u */
struct binary_calculation samples_srai8_u[] = {
    {0x40302010, 0x00000001, 0x20181008},
    {0x40302010, 0x00000002, 0x100c0804},
    {0x40302010, 0x00000004, 0x04030201},
    {0x40302010, 0x00000007, 0x01000000},
    {0xf4f3f2f1, 0x00000001, 0xfafaf9f9},
    {0xf4f3f2f1, 0x00000002, 0xfdfdfdfc},
    {0xf4f3f2f1, 0x00000004, 0xffffffff},
    {0xf4f3f2f1, 0x00000007, 0x00000000},
    {0xffffffff, 0x00000003, 0x00000000},
    {0x7f7f7f7f, 0x00000003, 0x10101010},
    {0x80808080, 0x00000003, 0xf0f0f0f0},
};

/* srl8 */
struct binary_calculation samples_srl8[] = {
    {0x40302010, 0x00000001, 0x20181008},
    {0x40302010, 0x00000002, 0x100c0804},
    {0x40302010, 0x00000004, 0x04030201},
    {0x40302010, 0x00000007, 0x00000000},
    {0xf4f3f2f1, 0x00000001, 0x7a797978},
    {0xf4f3f2f1, 0x00000002, 0x3d3c3c3c},
    {0xf4f3f2f1, 0x00000004, 0x0f0f0f0f},
    {0xf4f3f2f1, 0x00000007, 0x01010101},
    {0xffffffff, 0x00000003, 0x1f1f1f1f},
    {0x7f7f7f7f, 0x00000003, 0x0f0f0f0f},
    {0x80808080, 0x00000003, 0x10101010},
};

/* srl8.u */
struct binary_calculation samples_srl8_u[] = {
    {0x40302010, 0x00000001, 0x20181008},
    {0x40302010, 0x00000002, 0x100c0804},
    {0x40302010, 0x00000004, 0x04030201},
    {0x40302010, 0x00000007, 0x01000000},
    {0xf4f3f2f1, 0x00000001, 0x7a7a7979},
    {0xf4f3f2f1, 0x00000002, 0x3d3d3d3c},
    {0xf4f3f2f1, 0x00000004, 0x0f0f0f0f},
    {0xf4f3f2f1, 0x00000007, 0x02020202},
    {0xffffffff, 0x00000003, 0x20202020},
    {0x7f7f7f7f, 0x00000003, 0x10101010},
    {0x80808080, 0x00000003, 0x10101010},
};

/* srli8 */
struct binary_calculation samples_srli8[] = {
    {0x40302010, 0x00000001, 0x20181008},
    {0x40302010, 0x00000002, 0x100c0804},
    {0x40302010, 0x00000004, 0x04030201},
    {0x40302010, 0x00000007, 0x00000000},
    {0xf4f3f2f1, 0x00000001, 0x7a797978},
    {0xf4f3f2f1, 0x00000002, 0x3d3c3c3c},
    {0xf4f3f2f1, 0x00000004, 0x0f0f0f0f},
    {0xf4f3f2f1, 0x00000007, 0x01010101},
    {0xffffffff, 0x00000003, 0x1f1f1f1f},
    {0x7f7f7f7f, 0x00000003, 0x0f0f0f0f},
    {0x80808080, 0x00000003, 0x10101010},
};

/* srli8.u */
struct binary_calculation samples_srli8_u[] = {
    {0x40302010, 0x00000001, 0x20181008},
    {0x40302010, 0x00000002, 0x100c0804},
    {0x40302010, 0x00000004, 0x04030201},
    {0x40302010, 0x00000007, 0x01000000},
    {0xf4f3f2f1, 0x00000001, 0x7a7a7979},
    {0xf4f3f2f1, 0x00000002, 0x3d3d3d3c},
    {0xf4f3f2f1, 0x00000004, 0x0f0f0f0f},
    {0xf4f3f2f1, 0x00000007, 0x02020202},
    {0xffffffff, 0x00000003, 0x20202020},
    {0x7f7f7f7f, 0x00000003, 0x10101010},
    {0x80808080, 0x00000003, 0x10101010},
};

/* sll8 */
struct binary_calculation samples_sll8[] = {
    {0x40302010, 0x00000001, 0x80604020},
    {0x40302010, 0x00000002, 0x00c08040},
    {0x40302010, 0x00000004, 0x00000000},
    {0x40302010, 0x00000007, 0x00000000},
    {0xf4f3f2f1, 0x00000001, 0xe8e6e4e2},
    {0xf4f3f2f1, 0x00000002, 0xd0ccc8c4},
    {0xf4f3f2f1, 0x00000004, 0x40302010},
    {0xf4f3f2f1, 0x00000007, 0x00800080},
    {0xffffffff, 0x00000003, 0xf8f8f8f8},
    {0x7f7f7f7f, 0x00000003, 0xf8f8f8f8},
    {0x80808080, 0x00000003, 0x00000000},
};

/* slli8 */
struct binary_calculation samples_slli8[] = {
    {0x40302010, 0x00000001, 0x80604020},
    {0x40302010, 0x00000002, 0x00c08040},
    {0x40302010, 0x00000004, 0x00000000},
    {0x40302010, 0x00000007, 0x00000000},
    {0xf4f3f2f1, 0x00000001, 0xe8e6e4e2},
    {0xf4f3f2f1, 0x00000002, 0xd0ccc8c4},
    {0xf4f3f2f1, 0x00000004, 0x40302010},
    {0xf4f3f2f1, 0x00000007, 0x00800080},
    {0xffffffff, 0x00000003, 0xf8f8f8f8},
    {0x7f7f7f7f, 0x00000003, 0xf8f8f8f8},
    {0x80808080, 0x00000003, 0x00000000},
};

/* ksll8 */
struct binary_calculation samples_ksll8[] = {
    {0x40302010, 0x00000001, 0x7f604020},
    {0x40302010, 0x00000002, 0x7f7f7f40},
    {0x40302010, 0x00000004, 0x7f7f7f7f},
    {0x40302010, 0x00000007, 0x7f7f7f7f},
    {0xf4f3f2f1, 0x00000001, 0xe8e6e4e2},
    {0xf4f3f2f1, 0x00000002, 0xd0ccc8c4},
    {0xf4f3f2f1, 0x00000004, 0x80808080},
    {0xf4f3f2f1, 0x00000007, 0x80808080},
    {0xffffffff, 0x00000003, 0xf8f8f8f8},
    {0x7f7f7f7f, 0x00000003, 0x7f7f7f7f},
    {0x80808080, 0x00000003, 0x80808080},
};

/* kslli8 */
struct binary_calculation samples_kslli8[] = {
    {0x40302010, 0x00000001, 0x7f604020},
    {0x40302010, 0x00000002, 0x7f7f7f40},
    {0x40302010, 0x00000004, 0x7f7f7f7f},
    {0x40302010, 0x00000007, 0x7f7f7f7f},
    {0xf4f3f2f1, 0x00000001, 0xe8e6e4e2},
    {0xf4f3f2f1, 0x00000002, 0xd0ccc8c4},
    {0xf4f3f2f1, 0x00000004, 0x80808080},
    {0xf4f3f2f1, 0x00000007, 0x80808080},
    {0xffffffff, 0x00000003, 0xf8f8f8f8},
    {0x7f7f7f7f, 0x00000003, 0x7f7f7f7f},
    {0x80808080, 0x00000003, 0x80808080},
};

/* kslra8 */
struct binary_calculation samples_kslra8[] = {
    /* op2 >= 0 */
    {0x40302010, 0x00000001, 0x7f604020},
    {0x40302010, 0x00000002, 0x7f7f7f40},
    {0x40302010, 0x00000004, 0x7f7f7f7f},
    {0x40302010, 0x00000007, 0x7f7f7f7f},
    {0xf4f3f2f1, 0x00000001, 0xe8e6e4e2},
    {0xf4f3f2f1, 0x00000002, 0xd0ccc8c4},
    {0xf4f3f2f1, 0x00000004, 0x80808080},
    {0xf4f3f2f1, 0x00000007, 0x80808080},
    {0xffffffff, 0x00000003, 0xf8f8f8f8},
    {0x7f7f7f7f, 0x00000003, 0x7f7f7f7f},
    {0x80808080, 0x00000003, 0x80808080},
    /* op2 < 0 */
    {0x40302010, 0x000000ff, 0x20181008},
    {0x40302010, 0x000000fe, 0x100c0804},
    {0x40302010, 0x000000fc, 0x04030201},
    {0x40302010, 0x000000f9, 0x00000000},
    {0xf4f3f2f1, 0x000000ff, 0xfaf9f9f8},
    {0xf4f3f2f1, 0x000000fe, 0xfdfcfcfc},
    {0xf4f3f2f1, 0x000000fc, 0xffffffff},
    {0xf4f3f2f1, 0x000000f9, 0xffffffff},
    {0xffffffff, 0x000000fd, 0xffffffff},
    {0x7f7f7f7f, 0x000000fd, 0x0f0f0f0f},
    {0x80808080, 0x000000fd, 0xf0f0f0f0},
};

/* kslra8.u */
struct binary_calculation samples_kslra8_u[] = {
    /* op2 >= 0 */
    {0x40302010, 0x00000001, 0x7f604020},
    {0x40302010, 0x00000002, 0x7f7f7f40},
    {0x40302010, 0x00000004, 0x7f7f7f7f},
    {0x40302010, 0x00000007, 0x7f7f7f7f},
    {0xf4f3f2f1, 0x00000001, 0xe8e6e4e2},
    {0xf4f3f2f1, 0x00000002, 0xd0ccc8c4},
    {0xf4f3f2f1, 0x00000004, 0x80808080},
    {0xf4f3f2f1, 0x00000007, 0x80808080},
    {0xffffffff, 0x00000003, 0xf8f8f8f8},
    {0x7f7f7f7f, 0x00000003, 0x7f7f7f7f},
    {0x80808080, 0x00000003, 0x80808080},
    /* op2 < 0 */
    {0x40302010, 0x000000ff, 0x20181008},
    {0x40302010, 0x000000fe, 0x100c0804},
    {0x40302010, 0x000000fc, 0x04030201},
    {0x40302010, 0x000000f9, 0x01000000},
    {0xf4f3f2f1, 0x000000ff, 0xfafaf9f9},
    {0xf4f3f2f1, 0x000000fe, 0xfdfdfdfc},
    {0xf4f3f2f1, 0x000000fc, 0xffffffff},
    {0xf4f3f2f1, 0x000000f9, 0x00000000},
    {0xffffffff, 0x000000fd, 0x00000000},
    {0x7f7f7f7f, 0x000000fd, 0x10101010},
    {0x80808080, 0x000000fd, 0xf0f0f0f0},
};

/* kslraw */
struct binary_calculation samples_kslraw[] = {
    /* op2 >= 0 */
    {0x00000002, 0x00000001, 0x00000004},
    {0x00000004, 0x00000002, 0x00000010},
    {0x00000006, 0x00000004, 0x00000060},
    {0x00000008, 0x00000007, 0x00000400},
    {0xfffffff2, 0x00000001, 0xffffffe4},
    {0xfffffff4, 0x00000002, 0xffffffd0},
    {0xfffffff6, 0x00000004, 0xffffff60},
    {0xfffffff8, 0x00000007, 0xfffffc00},
    {0xffffffff, 0x00000003, 0xfffffff8},
    {0x80000000, 0x00000003, 0x80000000},
    {0x7fffffff, 0x00000003, 0x7fffffff},
    {0x00000001, 0x0000001f, 0x7fffffff},
    /* op2 < 0 */
    {0x00000002, 0x000000ff, 0x00000001},
    {0x00000004, 0x000000fe, 0x00000001},
    {0x00000006, 0x000000fc, 0x00000000},
    {0x00000080, 0x000000f9, 0x00000001},
    {0xfffffff2, 0x000000ff, 0xfffffff9},
    {0xfffffff4, 0x000000fe, 0xfffffffd},
    {0xfffffff6, 0x000000fc, 0xffffffff},
    {0xfffffff8, 0x000000f9, 0xffffffff},
    {0xffffffff, 0x000000fd, 0xffffffff},
    {0x80000000, 0x000000fd, 0xf0000000},
    {0x7fffffff, 0x000000fd, 0x0fffffff},
    {0x7fffffff, 0x00000020, 0x00000000},
};

/* kslraw.u */
struct binary_calculation samples_kslraw_u[] = {
    /* op2 >= 0 */
    {0x00000002, 0x00000001, 0x00000004},
    {0x00000004, 0x00000002, 0x00000010},
    {0x00000006, 0x00000004, 0x00000060},
    {0x00000008, 0x00000007, 0x00000400},
    {0xfffffff2, 0x00000001, 0xffffffe4},
    {0xfffffff4, 0x00000002, 0xffffffd0},
    {0xfffffff6, 0x00000004, 0xffffff60},
    {0xfffffff8, 0x00000007, 0xfffffc00},
    {0xffffffff, 0x00000003, 0xfffffff8},
    {0x80000000, 0x00000003, 0x80000000},
    {0x7fffffff, 0x00000003, 0x7fffffff},
    {0x00000001, 0x0000001f, 0x7fffffff},
    /* op2 < 0 */
    {0x00000002, 0x000000ff, 0x00000001},
    {0x00000004, 0x000000fe, 0x00000001},
    {0x00000006, 0x000000fc, 0x00000000},
    {0x00000080, 0x000000f9, 0x00000001},
    {0xfffffff2, 0x000000ff, 0xfffffff9},
    {0xfffffff4, 0x000000fe, 0xfffffffd},
    {0xfffffff6, 0x000000fc, 0xffffffff},
    {0xfffffff8, 0x000000f9, 0x00000000},
    {0xffffffff, 0x000000fd, 0x00000000},
    {0x80000000, 0x000000fd, 0xf0000000},
    {0x7fffffff, 0x000000fd, 0x10000000},
    {0x7fffffff, 0x00000020, 0x00000001},
};

/* add16 */
struct binary_calculation samples_add16[] = {
    {0x12345678, 0x11112222, 0x2345789A},
    {0x9000A000, 0xA000B000, 0x30005000},
    {0xFFFF8000, 0x00008000, 0xFFFF0000},
    {0xffffffff, 0xffffffff, 0xfffefffe},
    {0x00000000, 0xffffffff, 0xffffffff},
    {0x7fff7fff, 0x80008000, 0xffffffff},
    {0x7fffffff, 0x80000000, 0xffffffff},
    {0x88888888, 0x88888888, 0x11101110},
};

/* cras16 */
struct binary_calculation samples_cras16[] = {
    {0x00000001, 0x00000001, 0x00010001},
    {0x00010000, 0x00010001, 0x0002ffff},
    {0x7fff0000, 0x00000001, 0x80000000},
    {0xffff0000, 0x00000001, 0x00000000},
    {0x00008000, 0x00010000, 0x00007fff},
    {0x00000000, 0xffffffff, 0xffff0001},
    {0x7fffffff, 0xffffffff, 0x7ffe0000},
    {0xffffffff, 0x80000000, 0xffff7fff},
    {0x80000000, 0x7fffffff, 0x7fff8001},
    {0x11111111, 0x22222222, 0x3333eeef},
};

/* crsa16 */
struct binary_calculation samples_crsa16[] = {
    {0x00000001, 0x00000001, 0xffff0001},
    {0x80000000, 0x0000ffff, 0x80010000},
    {0x00007fff, 0x00010000, 0x00008000},
    {0x80007fff, 0x0001ffff, 0x80018000},
    {0xffffffff, 0x7fffffff, 0x00007ffe},
    {0xffffffff, 0x00000000, 0xffffffff},
    {0x80000000, 0xffffffff, 0x8001ffff},
    {0x7fffffff, 0x80000000, 0x7fff7fff},
    {0x11111111, 0x22222222, 0xeeef3333},
};

/* ukadd8 */
struct binary_calculation samples_ukadd8[] = {
    {0x01010101, 0x01010101, 0x02020202},
    {0x01010101, 0xffffffff, 0xffffffff},
    {0x01010101, 0xffffffff, 0xffffffff},
    {0x01010101, 0xff010101, 0xff020202},
    {0x01010101, 0x01ff0101, 0x02ff0202},
    {0x01010101, 0x0101ff01, 0x0202ff02},
    {0x01010101, 0x010101ff, 0x020202ff},
    {0xffffffff, 0xffffffff, 0xffffffff},
    {0x00000000, 0xffffffff, 0xffffffff},
    {0x00000001, 0xffffffff, 0xffffffff},
    {0x11888888, 0x22888888, 0x33ffffff},
};

/* kadd8 */
struct binary_calculation samples_kadd8[] = {
    {0x00000001, 0x00000001, 0x00000002},
    {0xffffffff, 0xffffffff, 0xfefefefe},
    {0x00000001, 0xffffffff, 0xffffff00},
    {0x00000001, 0x7f7f7f7f, 0x7f7f7f7f},
    {0x01010101, 0x7f7f7f7f, 0x7f7f7f7f},
    {0xffffffff, 0x80808080, 0x80808080},
    {0xffffffff, 0x00000080, 0xffffff80},
    {0x00000000, 0x00000001, 0x00000001},
    {0x00000000, 0x7f7f7f7f, 0x7f7f7f7f},
    {0x00000000, 0xffffffff, 0xffffffff},
    {0x00000000, 0x80000000, 0x80000000},
    {0x7fffffff, 0x80000000, 0xffffffff},
    {0x88117aaa, 0x812211bb, 0x80337f80},
};

/* ukadd16 */
struct binary_calculation samples_ukadd16[] = {
    {0x00000001, 0x00000001, 0x00000002},
    {0x00000001, 0x80008000, 0x80008001},
    {0x00000001, 0xffffffff, 0xffffffff},
    {0x00000001, 0x0000ffff, 0x0000ffff},
    {0x00010000, 0xffff0000, 0xffff0000},
    {0xffffffff, 0xffffffff, 0xffffffff},
    {0xffffffff, 0xffffffff, 0xffffffff},
    {0x00000000, 0xffffffff, 0xffffffff},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0xffff0000, 0xffff0000},
    {0x00000000, 0x0000ffff, 0x0000ffff},
    {0x00000000, 0x00ffff00, 0x00ffff00},
    {0x88888888, 0x00008888, 0x8888ffff},
};

/* kadd16 */
struct binary_calculation samples_kadd16[] = {
    {0x00000001, 0x00000001, 0x00000002},
    {0x00000001, 0xffffffff, 0xffff0000},
    {0xffffffff, 0xffffffff, 0xfffefffe},
    {0x00010001, 0xffffffff, 0x00000000},
    {0x00010001, 0x7fffffff, 0x7fff0000},
    {0x00000001, 0x7fffffff, 0x7fff0000},
    {0x00000001, 0xffff7fff, 0xffff7fff},
    {0x80000000, 0xffffffff, 0x8000ffff},
    {0x00008000, 0x00000001, 0x00008001},
    {0x80000000, 0x00010001, 0x80010001},
    {0x7fffffff, 0x00000000, 0x7fffffff},
    {0x7fff7fff, 0x00000000, 0x7fff7fff},
    {0x7fff7fff, 0x80008000, 0xffffffff},
    {0x00000000, 0x80000000, 0x80000000},
    {0x00000000, 0x80008000, 0x80008000},
    {0x7888aaaa, 0x2000bbbb, 0x7fff8000},
};

/* kaddh */
struct binary_calculation samples_kaddh[] = {
    {0x00000001, 0x00000001, 0x00000002},
    {0xffffffff, 0xffffffff, 0xfffffffe},
    {0x00000001, 0xffffffff, 0x00000000},
    {0x00000001, 0x7fffffff, 0x00007fff},
    {0xffffffff, 0x80000000, 0xffff8000},
    {0x00000001, 0x0000007f, 0x00000080},
    {0x00000001, 0x00007fff, 0x00007fff},
    {0xffffffff, 0xffffff80, 0xffffff7f},
    {0xffffffff, 0xfff80000, 0xffff8000},
    {0x00000001, 0x00000000, 0x00000001},
    {0x00000000, 0x7fffffff, 0x00007fff},
    {0x7fffffff, 0x80000000, 0xffffffff},
    {0xaaaaaaaa, 0xbbbbbbbb, 0xffff8000},
    {0x78888888, 0x28880000, 0x00007fff},
};

/* ukaddh */
struct binary_calculation samples_ukaddh[] = {
    {0x00000001, 0x00000001, 0x00000002},
    {0x00000001, 0xffffffff, 0xffffffff},
    {0x00010001, 0xffffffff, 0xffffffff},
    {0x00010001, 0x0001ffff, 0xffffffff},
    {0x00010000, 0x00ff0000, 0xffffffff},
    {0x00000001, 0x00000000, 0x00000001},
    {0x00000000, 0xffffffff, 0xffffffff},
    {0xffffffff, 0xffffffff, 0xffffffff},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00008000, 0x00000000, 0xffff8000},
    {0x00008000, 0x00007fff, 0xffffffff},
    {0x88888888, 0x88880000, 0xffffffff},
};

/* khmbb */
struct binary_calculation samples_khmbb[] = {
    {0x00000001, 0x00000001, 0x00000000},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0x00000001, 0xffffffff, 0xffffffff},
    {0x00008000, 0xffff8000, 0x00007fff},
    {0xffffffff, 0x00008000, 0x00000001},
    {0x00000001, 0x0000007f, 0x00000000},
    {0x00007fff, 0x00007fff, 0x00007ffe},
    {0x00007fff, 0xffff8000, 0xffff8001},
    {0xfffff001, 0xffff8000, 0x00000fff},
    {0x00000001, 0x00000000, 0x00000000},
    {0x00000000, 0x7fffffff, 0x00000000},
};

/* khmbt */
struct binary_calculation samples_khmbt[] = {
    {0x00000001, 0x00010000, 0x00000000},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0x00000001, 0xffffffff, 0xffffffff},
    {0x00008000, 0x8000ffff, 0x00007fff},
    {0xffffffff, 0x80000000, 0x00000001},
    {0x00000001, 0x007f0000, 0x00000000},
    {0x00007fff, 0x7fff0000, 0x00007ffe},
    {0x00007fff, 0x8000ffff, 0xffff8001},
    {0xfffff001, 0x8000ffff, 0x00000fff},
    {0x00000001, 0x00000000, 0x00000000},
    {0x00000000, 0xffff7fff, 0x00000000},
};

/* khmtt */
struct binary_calculation samples_khmtt[] = {
    {0x00010000, 0x00010000, 0x00000000},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0x00010000, 0xffffffff, 0xffffffff},
    {0x80000000, 0x8000ffff, 0x00007fff},
    {0xffffffff, 0x80000000, 0x00000001},
    {0x00010000, 0x007f0000, 0x00000000},
    {0x7fff0000, 0x7fff0000, 0x00007ffe},
    {0x7fff0000, 0x8000ffff, 0xffff8001},
    {0xf001ffff, 0x8000ffff, 0x00000fff},
    {0x00010000, 0x00000000, 0x00000000},
    {0x00000000, 0xffff7fff, 0x00000000},
};

/* ukaddw */
struct binary_calculation samples_ukaddw[] = {
    {0x00000001, 0x00000001, 0x00000002},
    {0x00000001, 0xffffffff, 0xffffffff},
    {0x00010001, 0xffffffff, 0xffffffff},
    {0x00010001, 0x0001ffff, 0x00030000},
    {0x00010000, 0x00ff0000, 0x01000000},
    {0x00000001, 0x00000000, 0x00000001},
    {0x00000000, 0xffffffff, 0xffffffff},
    {0xffffffff, 0xffffffff, 0xffffffff},
    {0x00000000, 0x00000000, 0x00000000},
    {0x80008000, 0x00000000, 0x80008000},
    {0x80008000, 0x7fff7fff, 0xffffffff},
    {0x88888888, 0x88880000, 0xffffffff},
};

/* kaddw */
struct binary_calculation samples_kaddw[] = {
    {0x00000001, 0x00000001, 0x00000002},
    {0xffffffff, 0xffffffff, 0xfffffffe},
    {0x00000001, 0xffffffff, 0x00000000},
    {0x00000001, 0x7fffffff, 0x7fffffff},
    {0xffffffff, 0x80000000, 0x80000000},
    {0x00000001, 0x0000007f, 0x00000080},
    {0x00000001, 0x00007fff, 0x00008000},
    {0xffffffff, 0xffffff80, 0xffffff7f},
    {0xffffffff, 0xfff80000, 0xfff7ffff},
    {0x00000001, 0x00000000, 0x00000001},
    {0x00000000, 0x7fffffff, 0x7fffffff},
    {0x7fffffff, 0x80000000, 0xffffffff},
    {0xaaaaaaaa, 0xbbbbbbbb, 0x80000000},
    {0x78888888, 0x28880000, 0x7fffffff},
};

/* uksub8 */
struct binary_calculation samples_uksub8[] = {
    {0x00000001, 0x00000001, 0x00000000},
    {0x00000002, 0x00000001, 0x00000001},
    {0x00000000, 0xffffffff, 0x00000000},
    {0xffffffff, 0x00000000, 0xffffffff},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0xffffffff, 0x7fffffff, 0x80000000},
    {0x00000001, 0xffffffff, 0x00000000},
    {0x7fffffff, 0x80000000, 0x00ffffff},
    {0xff7fffff, 0x00800000, 0xff00ffff},
    {0xfffff7ff, 0x00008000, 0xffff77ff},
    {0xffffff7f, 0x00000080, 0xffffff00},
    {0x88881111, 0x11112020, 0x77770000},
};

/* ksub8 */
struct binary_calculation samples_ksub8[] = {
    {0x00000001, 0x00000001, 0x00000000},
    {0xfffffffe, 0xffffffff, 0x000000ff},
    {0xfefefefe, 0xffffffff, 0xffffffff},
    {0x00000000, 0x7fffffff, 0x81010101},
    {0x00000000, 0x80000000, 0x7f000000},
    {0x7fffffff, 0x80808080, 0x7f7f7f7f},
    {0x7f7f7f7f, 0xffffffff, 0x7f7f7f7f},
    {0x80000000, 0x01000000, 0x80000000},
    {0x00008000, 0x00000100, 0x00008000},
    {0x00000080, 0x00000001, 0x00000080},
    {0x7a7aaaaa, 0xafaf7f7f, 0x7f7f8080},
};

/* uksub16 */
struct binary_calculation samples_uksub16[] = {
    {0x00000001, 0x00000001, 0x00000000},
    {0x00020002, 0x00010001, 0x00010001},
    {0x00000000, 0xffffffff, 0x00000000},
    {0xffffffff, 0x00000000, 0xffffffff},
    {0x00000000, 0x00000001, 0x00000000},
    {0x00000000, 0x00010001, 0x00000000},
    {0x00010001, 0x00020002, 0x00000000},
    {0x00010002, 0x00020001, 0x00000001},
    {0x00020001, 0x00010002, 0x00010000},
    {0x22221111, 0x11112222, 0x11110000},
};

/* ksub16 */
struct binary_calculation samples_ksub16[] = {
    {0x00000001, 0x00000001, 0x00000000},
    {0x00020002, 0x00010001, 0x00010001},
    {0xfffefffe, 0xffffffff, 0xffffffff},
    {0x00000000, 0x7fffffff, 0x80010001},
    {0x00000000, 0x80000000, 0x7fff0000},
    {0x7fffffff, 0x80000000, 0x7fffffff},
    {0x80008000, 0x7fff7fff, 0x80008000},
    {0x7fff7fff, 0xffffffff, 0x7fff7fff},
    {0x7f7f7f7f, 0xffffffff, 0x7f807f80},
    {0x80008000, 0x00010001, 0x80008000},
    {0x80000000, 0x00010001, 0x8000ffff},
    {0xaaaa2222, 0x7fff1111, 0x80001111},
};

/* ksubh */
struct binary_calculation samples_ksubh[] = {
    {0x00000001, 0x00000001, 0x00000000},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0x00007fff, 0xffffffff, 0x00007fff},
    {0xffff8000, 0x00000001, 0xffff8000},
    {0x00008000, 0x00000001, 0x00007fff},
    {0x00007fff, 0x0000ffff, 0xffff8000},
    {0x7fffffff, 0x00000000, 0x00007fff},
    {0x80000000, 0x7fffffff, 0xffff8000},
    {0x7fffffff, 0x80000000, 0x00007fff},
    {0xaaaaaaaa, 0x7fffffff, 0xffff8000},
    {0x7fff0000, 0xbbbb0000, 0x00007fff},
};

/* uksubh */
struct binary_calculation samples_uksubh[] = {
    {0x00000001, 0x00000001, 0x00000000},
    {0x00000001, 0x00000002, 0x00000000},
    {0x00010001, 0x00020002, 0x00000000},
    {0x01010101, 0x02020202, 0x00000000},
    {0x10000000, 0x02222222, 0xffffffff},
    {0x00000000, 0xffffffff, 0x00000000},
    {0xffffffff, 0x00000000, 0xffffffff},
    {0x11111111, 0x22222222, 0x00000000},
    {0x22222222, 0x11111111, 0xffffffff},
};

/* uksubw */
struct binary_calculation samples_uksubw[] = {
    {0x00000001, 0x00000001, 0x00000000},
    {0x00000001, 0x00000002, 0x00000000},
    {0x00010001, 0x00020002, 0x00000000},
    {0x01010101, 0x02020202, 0x00000000},
    {0x10000000, 0x02222222, 0x0dddddde},
    {0x00000000, 0xffffffff, 0x00000000},
    {0xffffffff, 0x00000000, 0xffffffff},
    {0x11111111, 0x22222222, 0x00000000},
    {0x22222222, 0x11111111, 0x11111111},
};

/* ksubw */
struct binary_calculation samples_ksubw[] = {
    {0x00000001, 0x00000001, 0x00000000},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0x7fffffff, 0xffffffff, 0x7fffffff},
    {0x80000000, 0x00000001, 0x80000000},
    {0x00008000, 0x00000001, 0x00007fff},
    {0x00007fff, 0x0000ffff, 0xffff8000},
    {0x7fffffff, 0x00000000, 0x7fffffff},
    {0x80000000, 0x7fffffff, 0x80000000},
    {0x7fffffff, 0x80000000, 0x7fffffff},
    {0xaaaaaaaa, 0x7fffffff, 0x80000000},
    {0x7fff0000, 0xbbbb0000, 0x7fffffff},
};

/* uraddw */
struct binary_calculation samples_uraddw[] = {
    {0x00000001, 0x00000001, 0x00000001},
    {0x80808082, 0x80808080, 0x80808081},
    {0x80000000, 0x80000000, 0x80000000},
    {0x00000000, 0xffffffff, 0x7fffffff},
    {0xffffffff, 0xffffffff, 0xffffffff},
    {0x7fffffff, 0x7fffffff, 0x7fffffff},
};

/* raddw */
struct binary_calculation samples_raddw[] = {
    {0x00000001, 0x00000001, 0x00000001},
    {0x80808082, 0x80808080, 0x80808081},
    {0x80000000, 0x80000000, 0x80000000},
    {0x00000000, 0xffffffff, 0xffffffff},
    {0x7fffffff, 0xffffffff, 0x3fffffff},
    {0x7fffffff, 0x7ffffff9, 0x7ffffffc},
    {0x80000002, 0x80000000, 0x80000001},
};

/* uradd8 */
struct binary_calculation samples_uradd8[] = {
    {0x00000001, 0x00000001, 0x00000001},
    {0x02020202, 0x02020202, 0x02020202},
    {0x80808080, 0x80808080, 0x80808080},
    {0x80000000, 0x80000000, 0x80000000},
    {0x00000000, 0xffffffff, 0x7f7f7f7f},
    {0xffffffff, 0xffffffff, 0xffffffff},
    {0x7f801000, 0x7f802001, 0x7f801800},
};

/* radd8 */
struct binary_calculation samples_radd8[] = {
    {0x00000001, 0x00000001, 0x00000001},
    {0xffffffff, 0xffffffff, 0xffffffff},
    {0x7f7f7f7f, 0x01010101, 0x40404040},
    {0x7fffffff, 0x00000001, 0x3fffff00},
    {0x80808080, 0xffffffff, 0xbfbfbfbf},
    {0x00000000, 0x7fffffff, 0x3fffffff},
    {0x00000000, 0x80000000, 0xc0000000},
    {0x7f881000, 0x7f112001, 0x7fcc1800},
};

/* uradd16 */
struct binary_calculation samples_uradd16[] = {
    {0x00000001, 0x00000001, 0x00000001},
    {0x00020002, 0x00020002, 0x00020002},
    {0xffffffff, 0x00000001, 0x7fff8000},
    {0xffff0000, 0x00010001, 0x80000000},
    {0xffffffff, 0x00010001, 0x80008000},
    {0x00000000, 0xffffffff, 0x7fff7fff},
    {0xffffffff, 0xffffffff, 0xffffffff},
    {0x80007fff, 0x80007fff, 0x80007fff},
};

/* radd16 */
struct binary_calculation samples_radd16[] = {
    {0x00000001, 0x00000001, 0x00000001},
    {0xffffffff, 0xffffffff, 0xffffffff},
    {0x7fff7fff, 0x00010001, 0x40004000},
    {0x7fffffff, 0x00010001, 0x40000000},
    {0x80008000, 0xffffffff, 0xbfffbfff},
    {0x80008000, 0xffff0000, 0xbfffc000},
    {0x7fff7fff, 0x00000000, 0x3fff3fff},
    {0x7fffffff, 0x00000000, 0x3fffffff},
    {0x80008000, 0x00000000, 0xc000c000},
    {0x80000000, 0x00000000, 0xc0000000},
    {0x7fff7fff, 0x80008000, 0xffffffff},
    {0x7fffffff, 0x80000000, 0xffffffff},
    {0x80007ff9, 0x80027fff, 0x80017ffc},
};

/* ursubw */
struct binary_calculation samples_ursubw[] = {
    {0x00000001, 0x00000001, 0x00000000},
    {0x00000001, 0x00000002, 0xffffffff},
    {0xffffffff, 0x00000000, 0x7fffffff},
    {0x00000000, 0xffffffff, 0x80000000},
    {0x7fffffff, 0x80000000, 0xffffffff},
    {0x00000000, 0x7fffffff, 0xc0000000},
    {0x11111111, 0x22222222, 0xf7777777},
    {0x7fffffff, 0x80000000, 0xffffffff},
};

/* rsubw */
struct binary_calculation samples_rsubw[] = {
    {0x00000001, 0x00000001, 0x00000000},
    {0x00000001, 0x00000002, 0xffffffff},
    {0xffffffff, 0xfffffffe, 0x00000000},
    {0x7fffffff, 0xffffffff, 0x40000000},
    {0x80000000, 0x00000001, 0xbfffffff},
    {0x00000000, 0x7fffffff, 0xc0000000},
    {0x00000000, 0x80000000, 0x40000000},
    {0x80000000, 0x00000000, 0xc0000000},
    {0x80000000, 0x7fffffff, 0x80000000},
    {0x00000001, 0x00000010, 0xfffffff8},
};

/* ursub8 */
struct binary_calculation samples_ursub8[] = {
    {0x00000001, 0x00000001, 0x00000000},
    {0x00000001, 0xffffffff, 0x80808081},
    {0x01010101, 0xffffffff, 0x81818181},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0x2222117f, 0x11112280, 0x0808f7ff},
};

/* rsub8 */
struct binary_calculation samples_rsub8[] = {
    {0x00000001, 0x00000001, 0x00000000},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0x00000001, 0xffffffff, 0x00000001},
    {0xffffffff, 0x00000001, 0xffffffff},
    {0x7f7f7f7f, 0xffffffff, 0x40404040},
    {0x80808080, 0x01010101, 0xbfbfbfbf},
    {0x7fffffff, 0xffffffff, 0x40000000},
    {0x80000000, 0x00000001, 0xc00000ff},
    {0x00000000, 0x7fffffff, 0xc0000000},
    {0x80000000, 0x7fffffff, 0x80000000},
    {0x7f7f7f7f, 0x80808080, 0x7f7f7f7f},
    {0x7fffffff, 0x80000000, 0x7fffffff},
    {0x01011111, 0x10102222, 0xf8f8f7f7},
};

/* ursub16 */
struct binary_calculation samples_ursub16[] = {
    {0x00000001, 0x00000001, 0x00000000},
    {0x00020002, 0x00000002, 0x00010000},
    {0x00000001, 0x00000002, 0x0000ffff},
    {0x00010001, 0x00020002, 0xffffffff},
    {0x00000000, 0xffffffff, 0x80008000},
    {0xffffffff, 0x00000000, 0x7fff7fff},
    {0x11111111, 0x22222222, 0xf777f777},
};

/* rsub16 */
struct binary_calculation samples_rsub16[] = {
    {0x00000001, 0x00000001, 0x00000000},
    {0xffffffff, 0x00000001, 0xffffffff},
    {0x7fffffff, 0xffffffff, 0x40000000},
    {0x7fff7fff, 0xffffffff, 0x40004000},
    {0x80000000, 0x00000001, 0xc000ffff},
    {0x80008000, 0x00000000, 0xc000c000},
    {0x7fffffff, 0x00000000, 0x3fffffff},
    {0x80000000, 0x00000000, 0xc0000000},
    {0x7fffffff, 0x80000000, 0x7fffffff},
    {0x80000000, 0x7fffffff, 0x80000000},
    {0x80008000, 0x7fff7fff, 0x80008000},
    {0x00010001, 0x00100001, 0xfff80000},
    {0x00000000, 0x00010001, 0xffffffff},
};

/* ukcras16 */
struct binary_calculation samples_ukcras16[] = {
    {0x00000001, 0x00000001, 0x00010001},
    {0xffff0000, 0x00000001, 0xffff0000},
    {0x00000000, 0x00010000, 0x00000000},
    {0x00000000, 0xffffffff, 0xffff0000},
    {0x7fffffff, 0xffffffff, 0xffff0000},
    {0xffffffff, 0x80000000, 0xffff7fff},
    {0x80000000, 0x7fffffff, 0xffff0000},
    {0xff001000, 0x10011111, 0xffff0000},
};

/* kcras16 */
struct binary_calculation samples_kcras16[] = {
    {0x00000001, 0x00000001, 0x00010001},
    {0x00010000, 0x00010001, 0x0002ffff},
    {0x7fff0000, 0x00000001, 0x7fff0000},
    {0x00080000, 0x00010000, 0x0008ffff},
    {0x00000000, 0xffffffff, 0xffff0001},
    {0x7fffffff, 0xffffffff, 0x7ffe0000},
    {0xffffffff, 0x80000000, 0xffff7fff},
    {0x80000000, 0x7fffffff, 0x80008001},
    {0x7fff8001, 0x10001111, 0x7fff8000},
};

/* ukcrsa16 */
struct binary_calculation samples_ukcrsa16[] = {
    {0x00000001, 0x00000001, 0x00000001},
    {0x00007fff, 0x00010001, 0x00008000},
    {0xffffffff, 0x7fffffff, 0x0000ffff},
    {0xffffffff, 0x00000000, 0xffffffff},
    {0x80000000, 0xffffffff, 0x0000ffff},
    {0x7fffffff, 0x80000000, 0x7fffffff},
    {0x1000ff00, 0x10001001, 0x0000ffff},
    {0x0000f000, 0x10000001, 0x0000ffff},
};

/* kcrsa16 */
struct binary_calculation samples_kcrsa16[] = {
    {0x00000001, 0x00000001, 0xffff0001},
    {0x80000000, 0x0000ffff, 0x80010000},
    {0x00007fff, 0x00010000, 0x00007fff},
    {0x80007fff, 0x0001ffff, 0x80017fff},
    {0xffffffff, 0x00000000, 0xffffffff},
    {0x80000000, 0x00000000, 0x80000000},
    {0x7fffffff, 0x80000000, 0x7fff8000},
    {0x80017f00, 0x10001001, 0x80007fff},
};

/* urcras16 */
struct binary_calculation samples_urcras16[] = {
    {0x00000001, 0x00010000, 0x00000000},
    {0x00010000, 0x00010001, 0x0001ffff},
    {0xffff0000, 0x00010000, 0x7fffffff},
    {0xffff0000, 0x00010001, 0x8000ffff},
    {0x00008000, 0x00008001, 0x40004000},
    {0x00000000, 0xffffffff, 0x7fff8000},
    {0x7fffffff, 0xffffffff, 0xbfff0000},
    {0xffffffff, 0x00008000, 0xbfff7fff},
    {0x80000000, 0xffff7fff, 0x7fff8000},
    {0x88881111, 0x22228888, 0x8888f777},
    {0x7fff0000, 0x00017fff, 0x7fffffff},
    {0x80008000, 0x7fff8000, 0x80000000},
    {0x7fff7fff, 0x80007fff, 0x7fffffff},
};

/* rcras16 */
struct binary_calculation samples_rcras16[] = {
    {0x00000001, 0x00010000, 0x00000000},
    {0x00010000, 0x00010001, 0x0001ffff},
    {0xffff0000, 0x00010000, 0xffffffff},
    {0xffff0000, 0x00010001, 0x0000ffff},
    {0x7fff0000, 0x00010000, 0x3fffffff},
    {0x00008000, 0x00008001, 0xc000c000},
    {0x80000000, 0xffff0000, 0xc0000000},
    {0x80007fff, 0xffffffff, 0xbfff4000},
    {0x00000000, 0xffffffff, 0xffff0000},
    {0x7fffffff, 0xffffffff, 0x3fff0000},
    {0xffffffff, 0x00008000, 0xbfffffff},
    {0x80000000, 0xffff7fff, 0xffff0000},
    {0x7fff0001, 0x00101000, 0x47fffff8},
    {0x7fff7fff, 0x80007fff, 0x7fff7fff},
};

/* urcrsa16 */
struct binary_calculation samples_urcrsa16[] = {
    {0x00010000, 0x00000001, 0x00000000},
    {0x00000001, 0x00010001, 0xffff0001},
    {0x0000ffff, 0x00000001, 0xffff7fff},
    {0x0000ffff, 0x00010001, 0xffff8000},
    {0x80000000, 0x80010000, 0x40004000},
    {0x00000000, 0xffffffff, 0x80007fff},
    {0xffff7fff, 0xffffffff, 0x0000bfff},
    {0xffffffff, 0x80000000, 0x7fffbfff},
    {0x00008000, 0x7fffffff, 0x80007fff},
    {0x1111ff00, 0x10002222, 0xf7778780},
    {0x0000ff00, 0x10000001, 0xffff8780},
};

/* rcrsa16 */
struct binary_calculation samples_rcrsa16[] = {
    {0x00010000, 0x00000001, 0x00000000},
    {0x00000001, 0x00010001, 0xffff0001},
    {0x0000ffff, 0x00000001, 0xffffffff},
    {0x0000ffff, 0x00010001, 0xffff0000},
    {0x00007fff, 0x00000001, 0xffff3fff},
    {0x80000000, 0x80010000, 0xc000c000},
    {0x00008000, 0x0000ffff, 0x0000c000},
    {0x7fff8000, 0xffffffff, 0x4000bfff},
    {0x00000000, 0xffffffff, 0x0000ffff},
    {0xffff7fff, 0xffffffff, 0x00003fff},
    {0xffffffff, 0x80000000, 0xffffbfff},
    {0x00008000, 0x7fffffff, 0x0000ffff},
    {0x00017f00, 0x20000010, 0xfff84f80},
};

/* add64 */
struct binary64_64_64_calculation samples_add64[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000200000002},
    {0x0000000100000000, 0x0000000100000000, 0x0000000200000000},
    {0x0000000000000001, 0x0000000000000001, 0x0000000000000002},
    {0xffffffff00000000, 0x0000000100000000, 0x0000000000000000},
    {0xffffffff80000000, 0x0000000180000000, 0x0000000100000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x7fffffff7fffffff},
    {0x7fffffff80000000, 0x800000007fffffff, 0xffffffffffffffff},
    {0x2000000000000000, 0xff00000000000000, 0x1f00000000000000},
};

/* radd64 */
struct binary64_64_64_calculation samples_radd64[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000100000001},
    {0x0000000100000000, 0x0000000100000000, 0x0000000100000000},
    {0x0000000000000001, 0x0000000000000001, 0x0000000000000001},
    {0xffffffff00000000, 0x0000000100000000, 0x0000000000000000},
    {0xffffffff80000000, 0x0000000180000000, 0x0000000080000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x3fffffffbfffffff},
    {0x7fffffff80000000, 0x800000007fffffff, 0xffffffffffffffff},
    {0x2000000000000000, 0xff00000000000000, 0x0f80000000000000},
    {0x7fffffffffffffff, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x7fffffffffffffff, 0x8000000000000000, 0xffffffffffffffff},
    {0x8000000000000000, 0x8000000000000000, 0x8000000000000000},
};

/* uradd64 */
struct binary64_64_64_calculation samples_uradd64[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000100000001},
    {0x0000000100000000, 0x0000000100000000, 0x0000000100000000},
    {0x0000000000000001, 0x0000000000000001, 0x0000000000000001},
    {0xffffffff00000000, 0x0000000100000000, 0x8000000000000000},
    {0xffffffff80000000, 0x0000000180000000, 0x8000000080000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x3fffffffbfffffff},
    {0x7fffffff80000000, 0x800000007fffffff, 0x7fffffffffffffff},
    {0x2000000000000000, 0xff00000000000000, 0x8f80000000000000},
    {0x7fffffffffffffff, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x7fffffffffffffff, 0x8000000000000000, 0x7fffffffffffffff},
    {0x8000000000000000, 0x8000000000000000, 0x8000000000000000},
};

/* ukadd64 */
struct binary64_64_64_calculation samples_ukadd64[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000200000002},
    {0x0000000100000000, 0x0000000100000000, 0x0000000200000000},
    {0x0000000000000001, 0x0000000000000001, 0x0000000000000002},
    {0xffffffff00000000, 0x0000000100000000, 0xffffffffffffffff},
    {0xffffffff80000000, 0x0000000180000000, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x7fffffff7fffffff},
    {0x7fffffff80000000, 0x800000007fffffff, 0xffffffffffffffff},
    {0xff00000000000000, 0x2000000000000000, 0xffffffffffffffff},
};
/* kadd64 */
struct binary64_64_64_calculation samples_kadd64[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000200000002},
    {0x0000000100000000, 0x0000000100000000, 0x0000000200000000},
    {0x0000000000000001, 0x0000000000000001, 0x0000000000000002},
    {0x7fffffff00000000, 0x0000000100000000, 0x7fffffffffffffff},
    {0x8000000000000000, 0x8000000000000000, 0x8000000000000000},
    {0x7fffffff80000000, 0x0000000180000000, 0x7fffffffffffffff},
    {0xffffffff80000000, 0x0000000180000000, 0x0000000100000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x7fffffff7fffffff},
    {0x7fffffff80000000, 0x800000007fffffff, 0xffffffffffffffff},
    {0x7f00000000000000, 0x2000000000000000, 0x7fffffffffffffff},
    {0x8000000000000001, 0xaa00000000000000, 0x8000000000000000},
};

/* sub64 */
struct binary64_64_64_calculation samples_sub64[] = {
    {0x0000001000000010, 0x0000000100000001, 0x0000000f0000000f},
    {0x0000001000000000, 0x0000000100000000, 0x0000000f00000000},
    {0x0000000000000010, 0x0000000000000001, 0x000000000000000f},
    {0x0000000000000000, 0xffffffff00000000, 0x0000000100000000},
    {0x0000000000000000, 0x8000000000000000, 0x8000000000000000},
    {0x0000000000000000, 0x7fffffff80000000, 0x8000000080000000},
    {0x0000000000000000, 0xffffffff80000000, 0x0000000080000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xfffffffefffffffe, 0xffffffffffffffff, 0xfffffffeffffffff},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fffffff80000000, 0x800000007fffffff},
    {0x0000000000000001, 0x0000000000000010, 0xfffffffffffffff1},
};

/* rsub64 */
struct binary64_64_64_calculation samples_rsub64[] = {
    {0x0000001000000010, 0x0000000100000001, 0x0000000780000007},
    {0x0000001000000000, 0x0000000100000000, 0x0000000780000000},
    {0x0000000000000010, 0x0000000000000001, 0x0000000000000007},
    {0x0000000000000000, 0xffffffff00000000, 0x0000000080000000},
    {0x0000000000000000, 0x8000000000000000, 0x4000000000000000},
    {0x0000000000000000, 0x7fffffff80000000, 0xc000000040000000},
    {0x0000000000000000, 0xffffffff80000000, 0x0000000040000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xfffffffefffffffe, 0xffffffffffffffff, 0xffffffff7fffffff},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fffffff80000000, 0xc00000003fffffff},
    {0x0000000000000001, 0x0000000000000010, 0xfffffffffffffff8},
};

/* ursub64 */
struct binary64_64_64_calculation samples_ursub64[] = {
    {0x0000001000000010, 0x0000000100000001, 0x0000000780000007},
    {0x0000001000000000, 0x0000000100000000, 0x0000000780000000},
    {0x0000000000000010, 0x0000000000000001, 0x0000000000000007},
    {0x0000000000000000, 0xffffffff00000000, 0x0000000080000000},
    {0x0000000000000000, 0x8000000000000000, 0x4000000000000000},
    {0x0000000000000000, 0x7fffffff80000000, 0x4000000040000000},
    {0x0000000000000000, 0xffffffff80000000, 0x0000000040000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xfffffffefffffffe, 0xffffffffffffffff, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fffffff80000000, 0x400000003fffffff},
    {0x0000000000000001, 0x0000000000000010, 0x7ffffffffffffff8},
};

/* uksub64 */
struct binary64_64_64_calculation samples_uksub64[] = {
    {0x0000001000000010, 0x0000000100000001, 0x0000000f0000000f},
    {0x0000001000000000, 0x0000000100000000, 0x0000000f00000000},
    {0x0000000000000010, 0x0000000000000001, 0x000000000000000f},
    {0x0000000000000000, 0xffffffff00000000, 0x0000000000000000},
    {0x0000000000000000, 0x8000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fffffff80000000, 0x0000000000000000},
    {0x0000000000000000, 0xffffffff80000000, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xfffffffefffffffe, 0xffffffffffffffff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fffffff80000000, 0x800000007fffffff},
    {0x1000000000000000, 0x2000000000000000, 0x0000000000000000},
};

/* ksub64 */
struct binary64_64_64_calculation samples_ksub64[] = {
    {0x0000001000000010, 0x0000000100000001, 0x0000000f0000000f},
    {0x0000001000000000, 0x0000000100000000, 0x0000000f00000000},
    {0x0000000000000010, 0x0000000000000001, 0x000000000000000f},
    {0x8000000000000000, 0x7fffffff00000000, 0x8000000000000000},
    {0x0000000000000000, 0x8000000000000000, 0x7fffffffffffffff},
    {0x0000000000000000, 0x7fffffff80000000, 0x8000000080000000},
    {0x0000000000000000, 0xffffffff80000000, 0x0000000080000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xfffffffefffffffe, 0xffffffffffffffff, 0xfffffffeffffffff},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fffffff80000000, 0x800000007fffffff},
    {0x7000000000000001, 0x7000000000000000, 0x0000000000000001},
};

/* sra.u */
struct binary_calculation samples_sra_u[] = {
    {0x00000001, 0x00000001, 0x00000001},
    {0x00000001, 0x00000010, 0x00000000},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0x0000001f, 0x00000000},
    {0x01111111, 0x0000001f, 0x00000000},
    {0xffffffff, 0x0000001f, 0x00000000},
    {0xbfffffff, 0x0000001f, 0xffffffff},
    {0x7fffffff, 0x0000001f, 0x00000001},
    {0x80000000, 0x0000001f, 0xffffffff},
    {0x10101011, 0x00000001, 0x08080809},
    {0x80101011, 0x00000001, 0xc0080809},
    {0x10101012, 0x00000002, 0x04040405},
    {0x10101010, 0x00000002, 0x04040404},
    {0x80101012, 0x00000002, 0xe0040405},
    {0x80000000, 0x00000000, 0x80000000},
    {0x80000000, 0x0000003f, 0xffffffff},
};

/* srai.u */
struct binary_calculation samples_srai_u[] = {
    {0x00000001, 0x00000001, 0x00000001},
    {0x00000001, 0x00000010, 0x00000000},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0x0000001f, 0x00000000},
    {0x01111111, 0x0000001f, 0x00000000},
    {0xffffffff, 0x0000001f, 0x00000000},
    {0xbfffffff, 0x0000001f, 0xffffffff},
    {0x7fffffff, 0x0000001f, 0x00000001},
    {0x80000000, 0x0000001f, 0xffffffff},
    {0x10101011, 0x00000001, 0x08080809},
    {0x80101011, 0x00000001, 0xc0080809},
    {0x10101012, 0x00000002, 0x04040405},
    {0x10101010, 0x00000002, 0x04040404},
    {0x80101012, 0x00000002, 0xe0040405},
    {0x80000000, 0x00000000, 0x80000000},
    {0x80000000, 0x0000003f, 0xffffffff},
};

/* bitrev */
struct binary_calculation samples_bitrev[] = {
    {0x00000001, 0x00000001, 0x00000002},
    {0x00000001, 0x00000010, 0x00010000},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0x0000001f, 0x00000000},
    {0x01111111, 0x0000001f, 0x88888880},
    {0xffffffff, 0x0000001f, 0xffffffff},
    {0xbfffffff, 0x0000001f, 0xfffffffd},
    {0x7fffffff, 0x0000001f, 0xfffffffe},
    {0x80000000, 0x0000001f, 0x00000001},
    {0x10101011, 0x00000001, 0x00000002},
    {0x80101011, 0x00000001, 0x00000002},
    {0x10101012, 0x00000002, 0x00000002},
    {0x10101010, 0x00000002, 0x00000000},
    {0x80101012, 0x00000002, 0x00000002},
    {0x80000000, 0x00000000, 0x00000000},
    {0x80000000, 0x0000003f, 0x00000001},
};

/* bitrevi */
struct binary_calculation samples_bitrevi[] = {
    {0x00000001, 0x00000001, 0x00000002},
    {0x00000001, 0x00000010, 0x00010000},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0x0000001f, 0x00000000},
    {0x01111111, 0x0000001f, 0x88888880},
    {0xffffffff, 0x0000001f, 0xffffffff},
    {0xbfffffff, 0x0000001f, 0xfffffffd},
    {0x7fffffff, 0x0000001f, 0xfffffffe},
    {0x80000000, 0x0000001f, 0x00000001},
    {0x10101011, 0x00000001, 0x00000002},
    {0x80101011, 0x00000001, 0x00000002},
    {0x10101012, 0x00000002, 0x00000002},
    {0x10101010, 0x00000002, 0x00000000},
    {0x80101012, 0x00000002, 0x00000002},
    {0x80000000, 0x00000000, 0x00000000},
    {0x80000000, 0x0000003f, 0x00000001},
};

/* kslliw */
struct binary_calculation samples_kslliw[] = {
    {0x00000001, 0x00000001, 0x00000002},
    {0xfffffffe, 0x00000001, 0xfffffffc},
    {0x7fffffff, 0x00000001, 0x7fffffff},
    {0x80000000, 0x00000001, 0x80000000},
    {0x007fffff, 0x00000009, 0x7fffffff},
    {0xff800000, 0x00000009, 0x80000000},
    {0xffffffff, 0x0000001f, 0x80000000},
    {0x00000000, 0x0000001f, 0x00000000},
    {0x00000001, 0x0000001f, 0x7fffffff},
    {0x40101010, 0x00000002, 0x7fffffff},
    {0x80101010, 0x00000002, 0x80000000},
};

/* ksllw */
struct binary_calculation samples_ksllw[] = {
    {0x00000001, 0x00000001, 0x00000002},
    {0xfffffffe, 0x00000001, 0xfffffffc},
    {0x7fffffff, 0x00000001, 0x7fffffff},
    {0x80000000, 0x00000001, 0x80000000},
    {0x007fffff, 0x00000009, 0x7fffffff},
    {0xff800000, 0x00000009, 0x80000000},
    {0xffffffff, 0x0000001f, 0x80000000},
    {0x00000000, 0x0000001f, 0x00000000},
    {0x00000001, 0x0000001f, 0x7fffffff},
    {0x7fffffff, 0x00000000, 0x7fffffff},
    {0x40101010, 0x00000002, 0x7fffffff},
    {0x80101010, 0x00000002, 0x80000000},
};

/* srai16 */
struct binary_calculation samples_srai16[] = {
    {0x10000000, 0x00000001, 0x08000000},
    {0x00010001, 0x00000001, 0x00000000},
    {0x80111010, 0x00000001, 0xc0080808},
    {0x80007fff, 0x0000000f, 0xffff0000},
    {0x80111010, 0x00000002, 0xe0040404},
    {0x80008000, 0x00000002, 0xe000e000},
    {0x10001000, 0x00000002, 0x04000400},
};

/* sra16 */
struct binary_calculation samples_sra16[] = {
    {0x10000000, 0x00000001, 0x08000000},
    {0x00010001, 0x00000001, 0x00000000},
    {0x00000000, 0x00000000, 0x00000000},
    {0x80111010, 0x0000000f, 0xffff0000},
    {0x80111010, 0x00000001, 0xc0080808},
    {0x80007fff, 0x0000000f, 0xffff0000},
    {0x80111010, 0x00000001, 0xc0080808},
    {0x80008000, 0x00000001, 0xc000c000},
    {0x10001000, 0x00000001, 0x08000800},
    {0x80008000, 0x0000001f, 0xffffffff},
    {0x80008000, 0x0000000f, 0xffffffff},
};

/* srai16.u */
struct binary_calculation samples_srai16_u[] = {
    {0x10000000, 0x00000001, 0x08000000},
    {0x00000001, 0x00000001, 0x00000001},
    {0x00000001, 0x00000002, 0x00000000},
    {0x80121012, 0x00000002, 0xe0050405},
    {0x80111011, 0x00000001, 0xc0090809},
    {0x80008000, 0x00000002, 0xe000e000},
    {0x80028002, 0x00000002, 0xe001e001},
    {0x10001000, 0x00000002, 0x04000400},
    {0x10021002, 0x00000002, 0x04010401},
    {0x80008000, 0x00000000, 0x80008000},
};

/* sra16.u */
struct binary_calculation samples_sra16_u[] = {
    {0x10000000, 0x00000001, 0x08000000},
    {0x00000001, 0x00000001, 0x00000001},
    {0x00000001, 0x00000002, 0x00000000},
    {0x80121012, 0x00000002, 0xe0050405},
    {0x80111011, 0x00000001, 0xc0090809},
    {0x80008000, 0x00000001, 0xc000c000},
    {0x80018001, 0x00000001, 0xc001c001},
    {0x80008000, 0x00000000, 0x80008000},
};

/* srli16 */
struct binary_calculation samples_srli16[] = {
    {0x10000000, 0x00000001, 0x08000000},
    {0x11000000, 0x00000001, 0x08800000},
    {0x11000000, 0x00000002, 0x04400000},
    {0x10001000, 0x00000001, 0x08000800},
    {0x00000001, 0x00000001, 0x00000000},
    {0x00000001, 0x00000002, 0x00000000},
    {0x10000001, 0x00000002, 0x04000000},
    {0x10000001, 0x00000001, 0x08000000},
    {0x10000001, 0x00000003, 0x02000000},
    {0x7fff7fff, 0x00000003, 0x0fff0fff},
    {0xffffffff, 0x0000000f, 0x00010001},
    {0xbfffffff, 0x0000000f, 0x00010001},
    {0x7fffffff, 0x0000000f, 0x00000001},
    {0x80000000, 0x0000000f, 0x00010000},
    {0x10118010, 0x00000002, 0x04042004},
    {0x10101010, 0x00000002, 0x04040404},
    {0x80108010, 0x00000002, 0x20042004},
};

/* srl16 */
struct binary_calculation samples_srl16[] = {
    {0x10000000, 0x00000001, 0x08000000},
    {0x11000000, 0x00000001, 0x08800000},
    {0x11000000, 0x00000002, 0x04400000},
    {0x10001000, 0x00000001, 0x08000800},
    {0x00000001, 0x00000001, 0x00000000},
    {0x10000001, 0x00000002, 0x04000000},
    {0x10000001, 0x00000001, 0x08000000},
    {0x10000001, 0x00000003, 0x02000000},
    {0x7fff7fff, 0x00000003, 0x0fff0fff},
    {0x00000000, 0x00000000, 0x00000000},
    {0xffffffff, 0x0000000f, 0x00010001},
    {0xbfffffff, 0x0000000f, 0x00010001},
    {0x7fffffff, 0x0000000f, 0x00000001},
    {0x80000000, 0x0000000f, 0x00010000},
    {0x80111010, 0x00000001, 0x40080808},
    {0x80118011, 0x00000001, 0x40084008},
    {0x10101010, 0x00000001, 0x08080808},
};

/* srli16.u */
struct binary_calculation samples_srli16_u[] = {
    {0x10000000, 0x00000001, 0x08000000},
    {0x11000000, 0x00000001, 0x08800000},
    {0x11000000, 0x00000002, 0x04400000},
    {0x10001000, 0x00000001, 0x08000800},
    {0x00000001, 0x00000001, 0x00000001},
    {0x00000001, 0x00000002, 0x00000000},
    {0x10000001, 0x00000002, 0x04000000},
    {0x10000001, 0x00000001, 0x08000001},
    {0x10000001, 0x00000003, 0x02000000},
    {0x7fff7fff, 0x00000003, 0x10001000},
    {0x00000000, 0x0000000f, 0x00000000},
    {0x01111111, 0x0000000f, 0x00000000},
    {0xffffffff, 0x0000000f, 0x00020002},
    {0xbfffffff, 0x0000000f, 0x00010002},
    {0x7fffffff, 0x0000000f, 0x00010002},
    {0x80000000, 0x0000000f, 0x00010000},
    {0x80121012, 0x00000002, 0x20050405},
    {0x80008000, 0x00000002, 0x20002000},
    {0x80028002, 0x00000002, 0x20012001},
};

/* srl16.u */
struct binary_calculation samples_srl16_u[] = {
    {0x10000000, 0x00000001, 0x08000000},
    {0x11000000, 0x00000001, 0x08800000},
    {0x11000000, 0x00000002, 0x04400000},
    {0x10001000, 0x00000001, 0x08000800},
    {0x00000001, 0x00000001, 0x00000001},
    {0x00000001, 0x00000002, 0x00000000},
    {0x10000001, 0x00000002, 0x04000000},
    {0x10000001, 0x00000001, 0x08000001},
    {0x10000001, 0x00000003, 0x02000000},
    {0x7fff7fff, 0x00000003, 0x10001000},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0x0000000f, 0x00000000},
    {0x01111111, 0x0000000f, 0x00000000},
    {0xffffffff, 0x0000000f, 0x00020002},
    {0xbfffffff, 0x0000000f, 0x00010002},
    {0x7fffffff, 0x0000000f, 0x00010002},
    {0x80000000, 0x0000000f, 0x00010000},
    {0x80181018, 0x00000004, 0x08020102},
    {0x80088000, 0x00000004, 0x08010800},
    {0x80008000, 0x0000000f, 0x00010001},
};

/* slli16 */
struct binary_calculation samples_slli16[] = {
    {0x00000001, 0x00000001, 0x00000002},
    {0xfffffffe, 0x00000001, 0xfffefffc},
    {0x7fffffff, 0x00000001, 0xfffefffe},
    {0x80000000, 0x00000001, 0x00000000},
    {0x007fffff, 0x00000009, 0xfe00fe00},
    {0x00800000, 0x00000009, 0x00000000},
    {0x80108011, 0x00000001, 0x00200022},
    {0x80008000, 0x00000001, 0x00000000},
};

/* sll16 */
struct binary_calculation samples_sll16[] = {
    {0x00000001, 0x00000001, 0x00000002},
    {0xfffffffe, 0x00000001, 0xfffefffc},
    {0x7fffffff, 0x00000001, 0xfffefffe},
    {0x80000000, 0x00000001, 0x00000000},
    {0x007fffff, 0x00000009, 0xfe00fe00},
    {0x00800000, 0x00000009, 0x00000000},
    {0x7fffffff, 0x00000000, 0x7fffffff},
    {0x80108011, 0x00000002, 0x00400044},
    {0x80008000, 0x00000002, 0x00000000},
    {0x80008000, 0x00000000, 0x80008000},
};

/* kslli16 */
struct binary_calculation samples_kslli16[] = {
    {0x00000001, 0x00000001, 0x00000002},
    {0xfffffffe, 0x00000001, 0xfffefffc},
    {0x7fffffff, 0x00000001, 0x7ffffffe},
    {0x80000000, 0x00000001, 0x80000000},
    {0x007fffff, 0x00000009, 0x7ffffe00},
    {0xff800000, 0x00000009, 0x80000000},
    {0x40118010, 0x00000002, 0x7fff8000},
    {0x80008000, 0x00000002, 0x80008000},
};

/* ksll16 */
struct binary_calculation samples_ksll16[] = {
    {0x00000001, 0x00000001, 0x00000002},
    {0xfffffffe, 0x00000001, 0xfffefffc},
    {0x7fffffff, 0x00000001, 0x7ffffffe},
    {0x80000000, 0x00000001, 0x80000000},
    {0x007fffff, 0x00000009, 0x7ffffe00},
    {0xff800000, 0x00000009, 0x80000000},
    {0x7fffffff, 0x00000000, 0x7fffffff},
    {0x10118010, 0x00000004, 0x7fff8000},
    {0x80008000, 0x00000004, 0x80008000},
    {0x20002000, 0x00000004, 0x7fff7fff},
    {0x00010001, 0x0000000f, 0x7fff7fff},
    {0x00010001, 0x0000000e, 0x40004000},
};

/* kslra16 */
struct binary_calculation samples_kslra16[] = {
    /* op2 >= 0 */
    {0x00000001, 0x00000001, 0x00000002},
    {0xfffffffe, 0x00000001, 0xfffefffc},
    {0x7fffffff, 0x00000001, 0x7ffffffe},
    {0x80000000, 0x00000001, 0x80000000},
    {0x007fffff, 0x00000009, 0x7ffffe00},
    {0xff800000, 0x00000009, 0x80000000},
    {0x7fffffff, 0x00000000, 0x7fffffff},
    {0x10118010, 0x00000004, 0x7fff8000},
    {0x80008000, 0x00000004, 0x80008000},
    {0x20002000, 0x00000004, 0x7fff7fff},
    {0x00010001, 0x0000000f, 0x7fff7fff},
    {0x00010001, 0x0000000e, 0x40004000},
    /* op2 < 0 */
    {0x10000000, 0x0000001f, 0x08000000},
    {0x00010001, 0x0000001f, 0x00000000},
    {0x80111010, 0x0000001f, 0xc0080808},
    {0x80007fff, 0x00000011, 0xffff0000},
    {0x80111010, 0x0000001e, 0xe0040404},
    {0x80008000, 0x0000001e, 0xe000e000},
    {0x10001000, 0x0000001e, 0x04000400},

};

/* kslra16.u */
struct binary_calculation samples_kslra16_u[] = {
    /* op2 >= 0 */
    {0x00000001, 0x00000001, 0x00000002},
    {0xfffffffe, 0x00000001, 0xfffefffc},
    {0x7fffffff, 0x00000001, 0x7ffffffe},
    {0x80000000, 0x00000001, 0x80000000},
    {0x007fffff, 0x00000009, 0x7ffffe00},
    {0xff800000, 0x00000009, 0x80000000},
    {0x7fffffff, 0x00000000, 0x7fffffff},
    {0x10118010, 0x00000004, 0x7fff8000},
    {0x80008000, 0x00000004, 0x80008000},
    {0x20002000, 0x00000004, 0x7fff7fff},
    {0x00010001, 0x0000000f, 0x7fff7fff},
    {0x00010001, 0x0000000e, 0x40004000},
    /* op2 < 0 */
    {0x10000000, 0x0000001f, 0x08000000},
    {0x00000001, 0x0000001f, 0x00000001},
    {0x00000001, 0x0000001e, 0x00000000},
    {0x80121012, 0x0000001e, 0xe0050405},
    {0x80111011, 0x0000001f, 0xc0090809},
    {0x80008000, 0x0000001f, 0xc000c000},
    {0x80018001, 0x0000001f, 0xc001c001},
    {0x80008000, 0x00000000, 0x80008000},
};

/* cmpeq8 */
struct binary_calculation samples_cmpeq8[] = {
    {0x22222222, 0x11111111, 0x00000000},
    {0x22222222, 0x22111111, 0xff000000},
    {0x22222222, 0x22221111, 0xffff0000},
    {0x22222222, 0x22222211, 0xffffff00},
    {0x22222222, 0x22222222, 0xffffffff},
    {0x0110aa00, 0x0111ab00, 0xff0000ff},
    {0x00000000, 0x01010101, 0x00000000},
    {0x00000000, 0x00000000, 0xffffffff},
};

/* cmpeq16 */
struct binary_calculation samples_cmpeq16[] = {
    {0x22222222, 0x11111111, 0x00000000},
    {0x22222222, 0x22111111, 0x00000000},
    {0x22222222, 0x22221111, 0xffff0000},
    {0x22222222, 0x22222211, 0xffff0000},
    {0x22222222, 0x22222222, 0xffffffff},
    {0x80111010, 0x00001010, 0x0000ffff},
    {0x00010001, 0x00010001, 0xffffffff},
};

/* ucmple8 */
struct binary_calculation samples_ucmple8[] = {
    {0x11111111, 0x22222222, 0xffffffff},
    {0x22111111, 0x22222222, 0xffffffff},
    {0x33221111, 0x22222222, 0x00ffffff},
    {0x33332211, 0x22222222, 0x0000ffff},
    {0x33333333, 0x22222222, 0x00000000},
    {0x80808080, 0x7f7f7f7f, 0x00000000},
    {0x80808080, 0xffffffff, 0xffffffff},
    {0x00000000, 0xffffffff, 0xffffffff},
    {0x11112001, 0x12111010, 0xffff00ff},
    {0x00000000, 0x01010101, 0xffffffff},
    {0x01010101, 0x01010101, 0xffffffff},
};

/* scmple8 */
struct binary_calculation samples_scmple8[] = {
    {0x11111111, 0x22222222, 0xffffffff},
    {0x22111111, 0x22222222, 0xffffffff},
    {0x33221111, 0x22222222, 0x00ffffff},
    {0x33332211, 0x22222222, 0x0000ffff},
    {0x33333333, 0x22222222, 0x00000000},
    {0xeeeeeeee, 0x22222222, 0xffffffff},
    {0x22222222, 0xeeeeeeee, 0x00000000},
    {0x80808080, 0x7f7f7f7f, 0xffffffff},
    {0x80808080, 0xffffffff, 0xffffffff},
    {0x00000000, 0xffffffff, 0x00000000},
    {0xfdaa7f01, 0xfeaa1010, 0xffff00ff},
    {0x00000000, 0x01010101, 0xffffffff},
    {0x00000000, 0x80808080, 0x00000000},
    {0xaaaaaaaa, 0xaaaaaaaa, 0xffffffff},
};

/* ucmple16 */
struct binary_calculation samples_ucmple16[] = {
    {0x11111111, 0x22222222, 0xffffffff},
    {0x22111111, 0x22222222, 0xffffffff},
    {0x33221111, 0x22222222, 0x0000ffff},
    {0x33332211, 0x22222222, 0x0000ffff},
    {0x33333333, 0x22222222, 0x00000000},
    {0x80808080, 0x7f7f7f7f, 0x00000000},
    {0x80008000, 0x7fff7fff, 0x00000000},
    {0x80808080, 0xffffffff, 0xffffffff},
    {0x00000000, 0xffffffff, 0xffffffff},
    {0x10000001, 0x00101000, 0x0000ffff},
    {0x80008000, 0x80008000, 0xffffffff},
};

/* ucmplt8 */
struct binary_calculation samples_ucmplt8[] = {
    {0x11111111, 0x22222222, 0xffffffff},
    {0x22111111, 0x22222222, 0x00ffffff},
    {0x33221111, 0x22222222, 0x0000ffff},
    {0x33332211, 0x22222222, 0x000000ff},
    {0x33333333, 0x22222222, 0x00000000},
    {0x80808080, 0x7f7f7f7f, 0x00000000},
    {0x80808080, 0xffffffff, 0xffffffff},
    {0x00000000, 0xffffffff, 0xffffffff},
    {0x01810101, 0xf1111001, 0xff00ff00},
};

/* scmplt8 */
struct binary_calculation samples_scmplt8[] = {
    {0x11111111, 0x22222222, 0xffffffff},
    {0x22111111, 0x22222222, 0x00ffffff},
    {0x33221111, 0x22222222, 0x0000ffff},
    {0x33332211, 0x22222222, 0x000000ff},
    {0x33333333, 0x22222222, 0x00000000},
    {0xeeeeeeee, 0x22222222, 0xffffffff},
    {0x22222222, 0xeeeeeeee, 0x00000000},
    {0x80808080, 0x7f7f7f7f, 0xffffffff},
    {0x80808080, 0xffffffff, 0xffffffff},
    {0x00000000, 0xffffffff, 0x00000000},
    {0x01810101, 0xf1111001, 0x00ffff00},
};

/* ucmplt16 */
struct binary_calculation samples_ucmplt16[] = {
    {0x11111111, 0x22222222, 0xffffffff},
    {0x22111111, 0x22222222, 0xffffffff},
    {0x33221111, 0x22222222, 0x0000ffff},
    {0x33332211, 0x22222222, 0x0000ffff},
    {0x33333333, 0x22222222, 0x00000000},
    {0x80808080, 0x7f7f7f7f, 0x00000000},
    {0x80008000, 0x7fff7fff, 0x00000000},
    {0x80808080, 0xffffffff, 0xffffffff},
    {0x00000000, 0xffffffff, 0xffffffff},
    {0x00000000, 0x00010000, 0xffff0000},
};

/* scmplt16 */
struct binary_calculation samples_scmplt16[] = {
    {0x11111111, 0x22222222, 0xffffffff},
    {0x22111111, 0x22222222, 0xffffffff},
    {0x33221111, 0x22222222, 0x0000ffff},
    {0x33332211, 0x22222222, 0x0000ffff},
    {0x33333333, 0x22222222, 0x00000000},
    {0xeeeeeeee, 0x22222222, 0xffffffff},
    {0x22222222, 0xeeeeeeee, 0x00000000},
    {0x80808080, 0x7f7f7f7f, 0xffffffff},
    {0x80008000, 0x7fff7fff, 0xffffffff},
    {0x80808080, 0xffffffff, 0xffffffff},
    {0x00000000, 0xffffffff, 0x00000000},
    {0x1001a000, 0x80010000, 0x0000ffff},
};

/* scmple16 */
struct binary_calculation samples_scmple16[] = {
    {0x11111111, 0x22222222, 0xffffffff},
    {0x22111111, 0x22222222, 0xffffffff},
    {0x33221111, 0x22222222, 0x0000ffff},
    {0x33332211, 0x22222222, 0x0000ffff},
    {0x33333333, 0x22222222, 0x00000000},
    {0xeeeeeeee, 0x22222222, 0xffffffff},
    {0x22222222, 0xeeeeeeee, 0x00000000},
    {0x80808080, 0x7f7f7f7f, 0xffffffff},
    {0x80008000, 0x7fff7fff, 0xffffffff},
    {0x80808080, 0xffffffff, 0xffffffff},
    {0x00000000, 0xffffffff, 0x00000000},
    {0x1001a000, 0x80010000, 0x0000ffff},
    {0x00010001, 0x00010001, 0xffffffff},
};

/* umax8 */
struct binary_calculation samples_umax8[] = {
    {0x22222222, 0x11111111, 0x22222222},
    {0x22222222, 0x22111111, 0x22222222},
    {0x22222222, 0x33221111, 0x33222222},
    {0x22222222, 0x33332211, 0x33332222},
    {0x22222222, 0x33333333, 0x33333333},
    {0x22222222, 0xeeeeeeee, 0xeeeeeeee},
    {0xeeeeeeee, 0x22222222, 0xeeeeeeee},
    {0x7f7f7f7f, 0x80808080, 0x80808080},
    {0xffffffff, 0x80808080, 0xffffffff},
    {0xffffffff, 0x00000000, 0xffffffff},
    {0x80111010, 0x00aa1110, 0x80aa1110},
};

/* smax8 */
struct binary_calculation samples_smax8[] = {
    {0x22222222, 0x11111111, 0x22222222},
    {0x22222222, 0x22111111, 0x22222222},
    {0x22222222, 0x33221111, 0x33222222},
    {0x22222222, 0x33332211, 0x33332222},
    {0x22222222, 0x33333333, 0x33333333},
    {0x22222222, 0xeeeeeeee, 0x22222222},
    {0xeeeeeeee, 0x22222222, 0x22222222},
    {0x7f7f7f7f, 0x80808080, 0x7f7f7f7f},
    {0xffffffff, 0x80808080, 0xffffffff},
    {0xffffffff, 0x00000000, 0x00000000},
    {0x80111022, 0x00aaaa10, 0x00111022},
};

/* sclip8 */
struct binary_calculation samples_sclip8[] = {
    {0xf5f6f7f8, 0x1, 0xfefefefe},
    {0xf5f6f7f8, 0x2, 0xfcfcfcfc},
    {0xf5f6f7f8, 0x3, 0xf8f8f8f8},
    {0x05060708, 0x1, 0x01010101},
    {0x05060708, 0x2, 0x03030303},
    {0x05060708, 0x3, 0x05060707},
    {0x80808080, 0x6, 0xc0c0c0c0},
    {0x80808080, 0x7, 0x80808080},
    {0x7f7f7f7f, 0x6, 0x3f3f3f3f},
    {0x7f7f7f7f, 0x7, 0x7f7f7f7f},
};

/* uclip8 */
struct binary_calculation samples_uclip8[] = {
    {0xf5f6f7f8, 0x1, 0x00000000},
    {0xf5f6f7f8, 0x2, 0x00000000},
    {0xf5f6f7f8, 0x3, 0x00000000},
    {0x05060708, 0x1, 0x01010101},
    {0x05060708, 0x2, 0x03030303},
    {0x05060708, 0x3, 0x05060707},
    {0x80808080, 0x6, 0x00000000},
    {0x80808080, 0x7, 0x00000000},
    {0x7f7f7f7f, 0x6, 0x3f3f3f3f},
    {0x7f7f7f7f, 0x7, 0x7f7f7f7f},
};


/* umax16 */
struct binary_calculation samples_umax16[] = {
    {0x22222222, 0x11111111, 0x22222222},
    {0x22222222, 0x22111111, 0x22222222},
    {0x22222222, 0x33221111, 0x33222222},
    {0x22222222, 0x33332211, 0x33332222},
    {0x22222222, 0x33333333, 0x33333333},
    {0x22222222, 0xeeeeeeee, 0xeeeeeeee},
    {0xeeeeeeee, 0x22222222, 0xeeeeeeee},
    {0x22222222, 0x33111111, 0x33112222},
    {0x7f7f7f7f, 0x80808080, 0x80808080},
    {0xffffffff, 0x80808080, 0xffffffff},
    {0xffffffff, 0x00000000, 0xffffffff},
    {0xa0011010, 0x11111010, 0xa0011010},
};

/* smax16 */
struct binary_calculation samples_smax16[] = {
    {0x22222222, 0x11111111, 0x22222222},
    {0x22222222, 0x22111111, 0x22222222},
    {0x22222222, 0x33221111, 0x33222222},
    {0x22222222, 0x33332211, 0x33332222},
    {0x22222222, 0x33333333, 0x33333333},
    {0x22222222, 0xeeeeeeee, 0x22222222},
    {0xeeeeeeee, 0x22222222, 0x22222222},
    {0x22222222, 0x33111111, 0x33112222},
    {0x7f7f7f7f, 0x80808080, 0x7f7f7f7f},
    {0xffffffff, 0x80808080, 0xffffffff},
    {0xffffffff, 0x00000000, 0x00000000},
    {0xa0011010, 0xb0011011, 0xb0011011},
};

/* maxw */
struct binary_calculation samples_maxw[] = {
    {0x22222222, 0x11111111, 0x22222222},
    {0x22222222, 0x22111111, 0x22222222},
    {0x22222222, 0x33221111, 0x33221111},
    {0x22222222, 0x33332211, 0x33332211},
    {0x22222222, 0x33333333, 0x33333333},
    {0x22222222, 0xeeeeeeee, 0x22222222},
    {0xeeeeeeee, 0x22222222, 0x22222222},
    {0x22222222, 0x33111111, 0x33111111},
    {0x7f7f7f7f, 0x80808080, 0x7f7f7f7f},
    {0xffffffff, 0x80808080, 0xffffffff},
    {0xffffffff, 0x00000000, 0x00000000},
    {0xa0001000, 0xb0000001, 0xb0000001},
};

/* umin8 */
struct binary_calculation samples_umin8[] = {
    {0x11111111, 0x22222222, 0x11111111},
    {0x22111111, 0x22222222, 0x22111111},
    {0x33221111, 0x22222222, 0x22221111},
    {0x33332211, 0x22222222, 0x22222211},
    {0x33333333, 0x22222222, 0x22222222},
    {0xa1810101, 0xf1111001, 0xa1110101},
    {0x80808080, 0x00000000, 0x00000000},
    {0x80808080, 0x80808080, 0x80808080},
};

/* smin8 */
struct binary_calculation samples_smin8[] = {
    {0x11111111, 0x22222222, 0x11111111},
    {0x22111111, 0x22222222, 0x22111111},
    {0x33221111, 0x22222222, 0x22221111},
    {0x33332211, 0x22222222, 0x22222211},
    {0x33333333, 0x22222222, 0x22222222},
    {0xeeeeeeee, 0x22222222, 0xeeeeeeee},
    {0x22222222, 0xeeeeeeee, 0xeeeeeeee},
    {0x80808080, 0x7f7f7f7f, 0x80808080},
    {0x80808080, 0xffffffff, 0x80808080},
    {0x00000000, 0xffffffff, 0xffffffff},
    {0xa1811101, 0xa0111001, 0xa0811001},
};

/* umin16 */
struct binary_calculation samples_umin16[] = {
    {0x11111111, 0x22222222, 0x11111111},
    {0x22111111, 0x22222222, 0x22111111},
    {0x33221111, 0x22222222, 0x22221111},
    {0x33332211, 0x22222222, 0x22222211},
    {0x33333333, 0x22222222, 0x22222222},
    {0xeeeeeeee, 0x22222222, 0x22222222},
    {0x22222222, 0xeeeeeeee, 0x22222222},
    {0x33111111, 0x22222222, 0x22221111},
    {0x80808080, 0x7f7f7f7f, 0x7f7f7f7f},
    {0x80808080, 0xffffffff, 0x80808080},
    {0x00000000, 0xffffffff, 0x00000000},
    {0x00000000, 0x80008000, 0x00000000},
};

/* smin16 */
struct binary_calculation samples_smin16[] = {
    {0x11111111, 0x22222222, 0x11111111},
    {0x22111111, 0x22222222, 0x22111111},
    {0x33221111, 0x22222222, 0x22221111},
    {0x33332211, 0x22222222, 0x22222211},
    {0x33333333, 0x22222222, 0x22222222},
    {0xeeeeeeee, 0x22222222, 0xeeeeeeee},
    {0x22222222, 0xeeeeeeee, 0xeeeeeeee},
    {0x33111111, 0x22222222, 0x22221111},
    {0x80808080, 0x7f7f7f7f, 0x80808080},
    {0x80808080, 0xffffffff, 0x80808080},
    {0x00000000, 0xffffffff, 0xffffffff},
    {0xa0018000, 0x80010000, 0x80018000},
};

/* minw */
struct binary_calculation samples_minw[] = {
    {0x11111111, 0x22222222, 0x11111111},
    {0x33221111, 0x22222222, 0x22222222},
    {0xeeeeeeee, 0x22222222, 0xeeeeeeee},
    {0x22222222, 0xeeeeeeee, 0xeeeeeeee},
    {0x80808080, 0x7f7f7f7f, 0x80808080},
    {0x80808080, 0xffffffff, 0x80808080},
    {0x00000000, 0xffffffff, 0xffffffff},
    {0x80000001, 0x70000001, 0x80000001},
};

/* pkbb16 */
struct binary_calculation samples_pkbb16[] = {
    {0x89abcdef, 0x01234567, 0xcdef4567},
    {0x00000000, 0xffffffff, 0x0000ffff},
    {0x12345678, 0xffffffff, 0x5678ffff},
    {0xffffffff, 0x00000000, 0xffff0000},
    {0xa0011010, 0x11111011, 0x10101011},
};

/* pkbt16 */
struct binary_calculation samples_pkbt16[] = {
    {0x89abcdef, 0x01234567, 0xcdef0123},
    {0x00000000, 0xffffffff, 0x0000ffff},
    {0x12345678, 0xffffffff, 0x5678ffff},
    {0xffffffff, 0x00000000, 0xffff0000},
    {0xa0011010, 0x11111011, 0x10101111},
};

/* pktt16 */
struct binary_calculation samples_pktt16[] = {
    {0x89abcdef, 0x01234567, 0x89ab0123},
    {0x00000000, 0xffffffff, 0x0000ffff},
    {0x12345678, 0xffffffff, 0x1234ffff},
    {0xffffffff, 0x00000000, 0xffff0000},
    {0x00100000, 0x10000001, 0x00101000},
};

/* pktb16 */
struct binary_calculation samples_pktb16[] = {
    {0x89abcdef, 0x01234567, 0x89ab4567},
    {0x00000000, 0xffffffff, 0x0000ffff},
    {0x12345678, 0xffffffff, 0x1234ffff},
    {0xffffffff, 0x00000000, 0xffff0000},
    {0x00100000, 0x10000001, 0x00100001},
};

/* sclip32 */
struct binary_calculation samples_sclip32[] = {
    {0x00000001, 0x00000000, 0x00000000},
    {0x00000001, 0x00000001, 0x00000001},
    {0x00000001, 0x0000001f, 0x00000001},
    {0xffffffff, 0x00000001, 0xffffffff},
    {0xffffffff, 0x0000001f, 0xffffffff},
    {0xfffffffe, 0x0000001f, 0xfffffffe},
    {0x00000001, 0x0000001e, 0x00000001},
    {0xffffffff, 0x0000001f, 0xffffffff},
    {0xffffffff, 0x0000001e, 0xffffffff},
    {0x00000000, 0x0000001f, 0x00000000},
    {0x7fffffff, 0x0000001e, 0x3fffffff},
    {0x80000000, 0x0000001e, 0xc0000000},
    {0xffffffff, 0x0000001e, 0xffffffff},
    {0x0000001f, 0x00000005, 0x0000001f},
    {0x0000002f, 0x00000005, 0x0000001f},
    {0x0000000f, 0x00000005, 0x0000000f},
    {0xffffffc0, 0x00000005, 0xffffffe0},
    {0xffffffe1, 0x00000005, 0xffffffe1},
};

/* uclip32 */
struct binary_calculation samples_uclip32[] = {
    {0x00000001, 0x00000001, 0x00000001},
    {0x00000001, 0x00000002, 0x00000001},
    {0x00000001, 0x00000000, 0x00000000},
    {0x00000001, 0x0000001f, 0x00000001},
    {0xffffffff, 0x00000000, 0x00000000},
    {0xffffffff, 0x0000001f, 0x00000000},
    {0x00000000, 0x00000000, 0x00000000},
    {0x0000003f, 0x00000006, 0x0000003f},
    {0x0000001f, 0x00000006, 0x0000001f},
    {0x0000004f, 0x00000006, 0x0000003f},
};

/* clrs32 */
struct unary_calculation samples_clrs32[] = {
    {0x00000002, 0x0000001d},
    {0x00000004, 0x0000001c},
    {0x00000006, 0x0000001c},
    {0x00000008, 0x0000001b},
    {0x0000000a, 0x0000001b},
    {0x0000000c, 0x0000001b},
    {0x0000000e, 0x0000001b},
    {0x00000010, 0x0000001a},
    {0xfffffff2, 0x0000001b},
    {0xfffffff4, 0x0000001b},
    {0xfffffff6, 0x0000001b},
    {0xfffffff8, 0x0000001c},
    {0xfffffffa, 0x0000001c},
    {0xfffffffc, 0x0000001d},
    {0xfffffffe, 0x0000001e},
    {0xffffffff, 0x0000001f},
    {0x7ffffff2, 0x00000000},
    {0x7ffffff4, 0x00000000},
    {0x80000002, 0x00000000},
    {0x80000004, 0x00000000},
};

/* clz32 */
struct unary_calculation samples_clz32[] = {
    {0x00000002, 0x0000001e},
    {0x00000004, 0x0000001d},
    {0x00000006, 0x0000001d},
    {0x00000008, 0x0000001c},
    {0x0000000a, 0x0000001c},
    {0x0000000c, 0x0000001c},
    {0x0000000e, 0x0000001c},
    {0x00000010, 0x0000001b},
    {0xfffffff2, 0x00000000},
    {0xfffffff4, 0x00000000},
    {0xfffffff6, 0x00000000},
    {0xfffffff8, 0x00000000},
    {0xfffffffa, 0x00000000},
    {0xfffffffc, 0x00000000},
    {0xfffffffe, 0x00000000},
    {0xffffffff, 0x00000000},
    {0x7ffffff2, 0x00000001},
    {0x7ffffff4, 0x00000001},
    {0x80000002, 0x00000000},
    {0x80000004, 0x00000000},
};

/* clo32 */
struct unary_calculation samples_clo32[] = {
    {0x00000002, 0x00000000},
    {0x00000004, 0x00000000},
    {0x00000006, 0x00000000},
    {0x00000008, 0x00000000},
    {0x0000000a, 0x00000000},
    {0x0000000c, 0x00000000},
    {0x0000000e, 0x00000000},
    {0x00000010, 0x00000000},
    {0xfffffff2, 0x0000001c},
    {0xfffffff4, 0x0000001c},
    {0xfffffff6, 0x0000001c},
    {0xfffffff8, 0x0000001d},
    {0xfffffffa, 0x0000001d},
    {0xfffffffc, 0x0000001e},
    {0xfffffffe, 0x0000001f},
    {0xffffffff, 0x00000020},
    {0x7ffffff2, 0x00000000},
    {0x7ffffff4, 0x00000000},
    {0x80000002, 0x00000001},
    {0x80000004, 0x00000001},
};

/* sclip16 */
struct binary_calculation samples_sclip16[] = {
    {0x00000001, 0x00000001, 0x00000001},
    {0x00010001, 0x00000001, 0x00010001},
    {0xffff0001, 0x00000001, 0xffff0001},
    {0xfffe0001, 0x00000001, 0xfffe0001},
    {0xfffd0010, 0x00000002, 0xfffd0003},
    {0xfffc0011, 0x00000002, 0xfffc0003},
    {0x00010001, 0x0000000f, 0x00010001},
    {0xffffffff, 0x0000000f, 0xffffffff},
    {0x00000000, 0x0000000f, 0x00000000},
    {0x7fffffff, 0x0000000f, 0x7fffffff},
    {0x80000000, 0x0000000f, 0x80000000},
    {0x7ffe8001, 0x0000000e, 0x3fffc000},
    {0x000100ff, 0x00000008, 0x000100ff},
    {0x8001fe01, 0x00000008, 0xff00ff00},
    {0xfe01fe01, 0x00000008, 0xff00ff00},
};

/* uclip16 */
struct binary_calculation samples_uclip16[] = {
    {0x00000001, 0x00000001, 0x00000001},
    {0x00010001, 0x00000001, 0x00010001},
    {0xffff0001, 0x00000001, 0x00000001},
    {0xfffe0001, 0x00000001, 0x00000001},
    {0xfffd0010, 0x00000002, 0x00000003},
    {0xfffc0011, 0x00000002, 0x00000003},
    {0x00010001, 0x0000000f, 0x00010001},
    {0xffffffff, 0x0000000f, 0x00000000},
    {0x00000000, 0x0000000f, 0x00000000},
    {0x7fffffff, 0x0000000f, 0x7fff0000},
    {0x80000000, 0x0000000f, 0x00000000},
    {0x7ffe8001, 0x0000000e, 0x3fff0000},
    {0x000100ff, 0x00000008, 0x000100ff},
    {0x8001fe01, 0x00000008, 0x00000000},
    {0xfe01fe01, 0x00000008, 0x00000000},
};

/* pbsad */
struct binary_calculation samples_pbsad[] = {
    {0x44556677, 0x00112233, 0x00000110},
    {0x00112233, 0x44556677, 0x00000110},
    {0x44444444, 0x44444444, 0x00000000},
    {0xffffffff, 0x7f7f7f7f, 0x00000200},
    {0xffffffff, 0x00000000, 0x000003fc},
    {0x7f7f7f7f, 0x80808080, 0x00000004},
    {0xff7f0080, 0x7fff807f, 0x00000181},
    {0xff01807f, 0xff107f80, 0x00000011},
};

/* smaqa */
struct ternary_calculation samples_smaqa[] = {
    {0x01010101, 0x40404040, 0x00000000, 0x00000100},
    {0x40404040, 0x01010101, 0x00000100, 0x00000200},
    {0x02020202, 0x40404040, 0x80000000, 0x80000200},
    {0x01010101, 0x80808080, 0x7fffffff, 0x7ffffdff},
    {0xffffffff, 0x00000000, 0x00000001, 0x00000001},
    {0xffffffff, 0xffffffff, 0x10000000, 0x10000004},
    {0x7fffffff, 0x80808080, 0x00002000, 0xffffe200},
    {0x80000000, 0x7fff4000, 0xffffffff, 0xffffc07f},
    {0x7fffffff, 0x4000ff00, 0xffffffff, 0x00001fc0},
    {0x7f80ff01, 0x40ff017f, 0xffffffff, 0x000020bd},
};

/* umaqa */
struct ternary_calculation samples_umaqa[] = {
    {0x01010101, 0x40404040, 0x00000000, 0x00000100},
    {0x40404040, 0x01010101, 0x00000100, 0x00000200},
    {0x02020202, 0x40404040, 0x80000000, 0x80000200},
    {0x01010101, 0x80808080, 0x7fffffff, 0x800001ff},
    {0xffffffff, 0x00000000, 0x00000001, 0x00000001},
    {0xffffffff, 0xffffffff, 0x10000000, 0x1003f804},
    {0x7fffffff, 0x80808080, 0x00002000, 0x0001de00},
    {0x80000000, 0x7fff4000, 0xffffffff, 0x00003f7f},
    {0x7fffffff, 0x4000ff00, 0xffffffff, 0x00011dc0},
    {0x7f80ff01, 0x40ff017f, 0xffffffff, 0x0000a0bd},
};

/* smaqa.su */
struct ternary_calculation samples_smaqa_su[] = {
    {0x01010101, 0x40404040, 0x00000000, 0x00000100},
    {0x40404040, 0x01010101, 0x00000100, 0x00000200},
    {0x02020202, 0x40404040, 0x80000000, 0x80000200},
    {0x01010101, 0x80808080, 0x7fffffff, 0x800001ff},
    {0xffffffff, 0x00000000, 0x00000001, 0x00000001},
    {0xffffffff, 0xffffffff, 0x10000000, 0x0ffffc04},
    {0x7fffffff, 0x80808080, 0x00002000, 0x00005e00},
    {0x80000000, 0x7fff4000, 0xffffffff, 0xffffc07f},
    {0x7fffffff, 0x4000ff00, 0xffffffff, 0x00001ec0},
    {0x7f80ff01, 0x40ff017f, 0xffffffff, 0xffffa0bd},
};

/* kabs8*/
struct unary_calculation samples_kabs8[] = {
    {0x01010101, 0x01010101},
    {0x00000001, 0x00000001},
    {0x00010001, 0x00010001},
    {0x80808080, 0x7f7f7f7f},
    {0x80000000, 0x7f000000},
    {0x80008000, 0x7f007f00},
    {0x00000000, 0x00000000},
    {0xffffffff, 0x01010101},
    {0x7f7f7f7f, 0x7f7f7f7f},
    {0x7fffffff, 0x7f010101},
    {0x7fff7fff, 0x7f017f01},
    {0x80807f02, 0x7f7f7f02},
    {0x81818181, 0x7f7f7f7f},
    {0x80808080, 0x7f7f7f7f},
    {0x7f7f7f7f, 0x7f7f7f7f},
};

/* clrs8*/
struct unary_calculation samples_clrs8[] = {
    {0x05060708, 0x04040403},
    {0x0d0e0f10, 0x03030302},
    {0xf5f6f7f8, 0x03030304},
    {0xfdfeffff, 0x05060707},
    {0x84858687, 0x00000000},
    {0x74757677, 0x00000000},
    {0x7f7f7f7f, 0x00000000},
};

/* clz8*/
struct unary_calculation samples_clz8[] = {
    {0x05060708, 0x05050504},
    {0x0d0e0f10, 0x04040403},
    {0xf5f6f7f8, 0x00000000},
    {0xfdfeffff, 0x00000000},
    {0x84858687, 0x00000000},
    {0x74757677, 0x01010101},
    {0x7f7f7f7f, 0x01010101},
};

/* clo8*/
struct unary_calculation samples_clo8[] = {
    {0x05060708, 0x00000000},
    {0x0d0e0f10, 0x00000000},
    {0xf5f6f7f8, 0x04040405},
    {0xfdfeffff, 0x06070808},
    {0x84858687, 0x01010101},
    {0x74757677, 0x00000000},
    {0x7f7f7f7f, 0x00000000},
};

/* sunpkd810 */
struct unary_calculation samples_sunpkd810[] = {
    {0x05060708, 0x00070008},
    {0x0d0e0f10, 0x000f0010},
    {0xf5f6f7f8, 0xfff7fff8},
    {0xfdfeffff, 0xffffffff},
    {0x84858687, 0xff86ff87},
    {0x74757677, 0x00760077},
    {0x7c7d7e7f, 0x007e007f},
};

/* sunpkd820 */
struct unary_calculation samples_sunpkd820[] = {
    {0x05060708, 0x00060008},
    {0x0d0e0f10, 0x000e0010},
    {0xf5f6f7f8, 0xfff6fff8},
    {0xfdfeffff, 0xfffeffff},
    {0x84858687, 0xff85ff87},
    {0x74757677, 0x00750077},
    {0x7c7d7e7f, 0x007d007f},
};

/* sunpkd830 */
struct unary_calculation samples_sunpkd830[] = {
    {0x05060708, 0x00050008},
    {0x0d0e0f10, 0x000d0010},
    {0xf5f6f7f8, 0xfff5fff8},
    {0xfdfeffff, 0xfffdffff},
    {0x84858687, 0xff84ff87},
    {0x74757677, 0x00740077},
    {0x7c7d7e7f, 0x007c007f},
};

/* sunpkd831 */
struct unary_calculation samples_sunpkd831[] = {
    {0x05060708, 0x00050007},
    {0x0d0e0f10, 0x000d000f},
    {0xf5f6f7f8, 0xfff5fff7},
    {0xfdfeffff, 0xfffdffff},
    {0x84858687, 0xff84ff86},
    {0x74757677, 0x00740076},
    {0x7c7d7e7f, 0x007c007e},
};

/* sunpkd832 */
struct unary_calculation samples_sunpkd832[] = {
    {0x05060708, 0x00050006},
    {0x0d0e0f10, 0x000d000e},
    {0xf5f6f7f8, 0xfff5fff6},
    {0xfdfeffff, 0xfffdfffe},
    {0x84858687, 0xff84ff85},
    {0x74757677, 0x00740075},
    {0x7c7d7e7f, 0x007c007d},
};

/* zunpkd810 */
struct unary_calculation samples_zunpkd810[] = {
    {0x05060708, 0x00070008},
    {0x0d0e0f10, 0x000f0010},
    {0xf5f6f7f8, 0x00f700f8},
    {0xfdfeffff, 0x00ff00ff},
    {0x84858687, 0x00860087},
    {0x74757677, 0x00760077},
    {0x7c7d7e7f, 0x007e007f},
};

/* zunpkd820 */
struct unary_calculation samples_zunpkd820[] = {
    {0x05060708, 0x00060008},
    {0x0d0e0f10, 0x000e0010},
    {0xf5f6f7f8, 0x00f600f8},
    {0xfdfeffff, 0x00fe00ff},
    {0x84858687, 0x00850087},
    {0x74757677, 0x00750077},
    {0x7c7d7e7f, 0x007d007f},
};

/* zunpkd830 */
struct unary_calculation samples_zunpkd830[] = {
    {0x05060708, 0x00050008},
    {0x0d0e0f10, 0x000d0010},
    {0xf5f6f7f8, 0x00f500f8},
    {0xfdfeffff, 0x00fd00ff},
    {0x84858687, 0x00840087},
    {0x74757677, 0x00740077},
    {0x7c7d7e7f, 0x007c007f},
};

/* zunpkd831 */
struct unary_calculation samples_zunpkd831[] = {
    {0x05060708, 0x00050007},
    {0x0d0e0f10, 0x000d000f},
    {0xf5f6f7f8, 0x00f500f7},
    {0xfdfeffff, 0x00fd00ff},
    {0x84858687, 0x00840086},
    {0x74757677, 0x00740076},
    {0x7c7d7e7f, 0x007c007e},
};

/* zunpkd832 */
struct unary_calculation samples_zunpkd832[] = {
    {0x05060708, 0x00050006},
    {0x0d0e0f10, 0x000d000e},
    {0xf5f6f7f8, 0x00f500f6},
    {0xfdfeffff, 0x00fd00fe},
    {0x84858687, 0x00840085},
    {0x74757677, 0x00740075},
    {0x7c7d7e7f, 0x007c007d},
};

/* kabs16 */
struct unary_calculation samples_kabs16[] = {
    {0x01010101, 0x01010101},
    {0x00000001, 0x00000001},
    {0x00010001, 0x00010001},
    {0x80808080, 0x7f807f80},
    {0x80000000, 0x7fff0000},
    {0x80008000, 0x7fff7fff},
    {0x00000000, 0x00000000},
    {0xffffffff, 0x00010001},
    {0x7f7f7f7f, 0x7f7f7f7f},
    {0x7fffffff, 0x7fff0001},
    {0x7fff7fff, 0x7fff7fff},
    {0x8000001f, 0x7fff001f},
    {0xf00100ff, 0x0fff00ff},
    {0x80018001, 0x7fff7fff},
};

/* clrs16 */
struct unary_calculation samples_clrs16[] = {
    {0x00030004, 0x000d000c},
    {0x00070008, 0x000c000b},
    {0x000b000c, 0x000b000b},
    {0x000f0010, 0x000b000a},
    {0xfff3fff4, 0x000b000b},
    {0xfff7fff8, 0x000b000c},
    {0xfffbfffc, 0x000c000d},
    {0xffffffff, 0x000f000f},
    {0x7ff37ff4, 0x00000000},
    {0x80008003, 0x00000000},
};

/* clz16 */
struct unary_calculation samples_clz16[] = {
    {0x00030004, 0x000e000d},
    {0x00070008, 0x000d000c},
    {0x000b000c, 0x000c000c},
    {0x000f0010, 0x000c000b},
    {0xfff3fff4, 0x00000000},
    {0xfff7fff8, 0x00000000},
    {0xfffbfffc, 0x00000000},
    {0xffffffff, 0x00000000},
    {0x7ff37ff4, 0x00010001},
    {0x80008003, 0x00000000},
};

/* clo16 */
struct unary_calculation samples_clo16[] = {
    {0x00030004, 0x00000000},
    {0x00070008, 0x00000000},
    {0x000b000c, 0x00000000},
    {0x000f0010, 0x00000000},
    {0xfff3fff4, 0x000c000c},
    {0xfff7fff8, 0x000c000d},
    {0xfffbfffc, 0x000d000e},
    {0xffffffff, 0x00100010},
    {0x7ff37ff4, 0x00000000},
    {0x80008003, 0x00010001},
};

/* kabsw */
struct unary_calculation samples_kabsw[] = {
    {0x01010101, 0x01010101},
    {0x00000001, 0x00000001},
    {0x00010001, 0x00010001},
    {0x80808080, 0x7f7f7f80},
    {0x80000000, 0x7fffffff},
    {0x80008000, 0x7fff8000},
    {0x00000000, 0x00000000},
    {0xffffffff, 0x00000001},
    {0x7f7f7f7f, 0x7f7f7f7f},
    {0x7fffffff, 0x7fffffff},
    {0x7fff7fff, 0x7fff7fff},
    {0x0000003f, 0x0000003f},
    {0xf000001f, 0x0fffffe1},
};

/* bpick */
struct ternary_calculation samples_bpick[] = {
    {0x00000000, 0xffffffff, 0x00000000, 0xffffffff},
    {0x00000000, 0xffffffff, 0xffffffff, 0x00000000},
    {0xffff0000, 0x0000ffff, 0xffff0000, 0xffffffff},
    {0xffff0000, 0x0000ffff, 0x0000ffff, 0x00000000},
    {0x00000000, 0xffffffff, 0xaaaaaaaa, 0x55555555},
    {0x00000000, 0xffffffff, 0x55555555, 0xaaaaaaaa},
};

/* wext */
struct binary64_ul_ul_calculation samples_wext[] = {
    {0x89abcdef89abcdef, 0x00000008, 0xef89abcd},
    {0x89abcdef89abcdef, 0x00000004, 0xf89abcde},
    {0x0000000000000000, 0x00000002, 0x00000000},
    {0xffffffffffffffff, 0x0000001f, 0xffffffff},
    {0x0101010101010101, 0x00000004, 0x10101010},
};

/* wexti */
struct binary64_32_ul_calculation samples_wexti[] = {
    {0x89abcdef89abcdef, 0x00000008, 0xef89abcd},
    {0x89abcdef89abcdef, 0x00000004, 0xf89abcde},
    {0x0000000000000000, 0x00000002, 0x00000000},
    {0xffffffffffffffff, 0x0000001f, 0xffffffff},
    {0x0101010101010101, 0x00000004, 0x10101010},
};

/* pbsada */
struct ternary_calculation samples_pbsada[] = {
    {0x44556677, 0x00112233, 0x00000000, 0x00000110},
    {0x00112233, 0x44556677, 0x00000000, 0x00000110},
    {0x44444444, 0x44444444, 0xffffffff, 0xffffffff},
    {0xffffffff, 0x7f7f7f7f, 0xffffffff, 0x000001ff},
    {0xffffffff, 0x00000000, 0x00000000, 0x000003fc},
    {0x7f7f7f7f, 0x80808080, 0x00000000, 0x00000004},
    {0xff7f0080, 0x7fff807f, 0xffffffff, 0x00000180},
    {0xff01807f, 0xff107f80, 0x00000000, 0x00000011},
};

/* umsr64 */
struct ternary_ul_ul_64_calculation samples_umsr64[] = {
    {0x00000001, 0x00000001, 0x0000000000000001, 0x0000000000000000},
    {0x00000001, 0x00000001, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0x00000001, 0x00000001, 0x8000000000000000, 0x7fffffffffffffff},
    {0x00000001, 0x00000001, 0x7fffffffffffffff, 0x7ffffffffffffffe},
    {0x00000001, 0xffffffff, 0xffffffffffffffff, 0xffffffff00000000},
    {0x00000001, 0xffffffff, 0x8000000000000000, 0x7fffffff00000001},
    {0x00000001, 0xffffffff, 0x7fffffffffffffff, 0x7fffffff00000000},
    {0x80000000, 0x80000000, 0xffffffffffffffff, 0xbfffffffffffffff},
    {0x80000000, 0x80000000, 0x8000000000000000, 0x4000000000000000},
    {0x80000000, 0x80000000, 0x7fffffffffffffff, 0x3fffffffffffffff},
    {0x7fffffff, 0xffffffff, 0xffffffffffffffff, 0x800000017ffffffe},
    {0x7fffffff, 0xffffffff, 0x8000000000000000, 0x000000017fffffff},
    {0x7fffffff, 0xffffffff, 0x0000000000000000, 0x800000017fffffff},
    {0x00000000, 0x00000001, 0x0000000000000000, 0x0000000000000000},
    {0x00000001, 0x00000000, 0x0000000000000000, 0x0000000000000000},
    {0x00000001, 0x00000001, 0x000000007fffffff, 0x000000007ffffffe},
};

/* smsr64 */
struct ternary_ul_ul_64_calculation samples_smsr64[] = {
    {0x00000001, 0x00000001, 0x0000000000000001, 0x0000000000000000},
    {0x00000001, 0x00000001, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0x00000001, 0x00000001, 0x8000000000000000, 0x7fffffffffffffff},
    {0x00000001, 0x00000001, 0x7fffffffffffffff, 0x7ffffffffffffffe},
    {0x00000001, 0xffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0x00000001, 0xffffffff, 0x8000000000000000, 0x8000000000000001},
    {0x00000001, 0xffffffff, 0x7fffffffffffffff, 0x8000000000000000},
    {0x80000000, 0x80000000, 0xffffffffffffffff, 0xbfffffffffffffff},
    {0x80000000, 0x80000000, 0x8000000000000000, 0x4000000000000000},
    {0x80000000, 0x80000000, 0x7fffffffffffffff, 0x3fffffffffffffff},
    {0x7fffffff, 0xffffffff, 0xffffffffffffffff, 0x000000007ffffffe},
    {0x7fffffff, 0xffffffff, 0x8000000000000000, 0x800000007fffffff},
    {0x7fffffff, 0xffffffff, 0x0000000000000000, 0x000000007fffffff},
    {0x00000000, 0x00000001, 0x0000000000000000, 0x0000000000000000},
    {0x00000001, 0x00000000, 0x0000000000000000, 0x0000000000000000},
    {0x00000001, 0x00000001, 0x000000007fffffff, 0x000000007ffffffe},
};

/* kdmabb */
struct ternary_calculation samples_kdmabb[] = {
    {0x00000001, 0x00000001, 0x00000001, 0x00000003},
    {0x00000001, 0x00000001, 0xffffffff, 0x00000001},
    {0x00000001, 0x00000001, 0x80000000, 0x80000002},
    {0x00000001, 0x00000001, 0x7fffffff, 0x7fffffff},
    {0x00000001, 0xffffffff, 0xffffffff, 0xfffffffd},
    {0x00000001, 0xffffffff, 0x80000000, 0x80000000},
    {0x00000001, 0xffffffff, 0x7fffffff, 0x7ffffffd},
    {0x80008000, 0x80008000, 0xffffffff, 0x7ffffffe},
    {0x80008000, 0x80008000, 0x80000000, 0xffffffff},
    {0x80008000, 0x80008000, 0x7fffffff, 0x7fffffff},
    {0x7fff7fff, 0xffff7fff, 0xffffffff, 0x7ffe0001},
    {0x7fff7fff, 0xffff7fff, 0x80000000, 0xfffe0002},
    {0x7fff7fff, 0xffff7fff, 0x00000000, 0x7ffe0002},
    {0x00000000, 0x00000001, 0x00000000, 0x00000000},
    {0x00000001, 0x00000000, 0x00000000, 0x00000000},
};

/* kdmabt */
struct ternary_calculation samples_kdmabt[] = {
    {0x00000001, 0x00010000, 0x00000001, 0x00000003},
    {0x00000001, 0x00010000, 0xffffffff, 0x00000001},
    {0x00000001, 0x00010000, 0x80000000, 0x80000002},
    {0x00000001, 0x00010000, 0x7fffffff, 0x7fffffff},
    {0x00000001, 0xffffffff, 0xffffffff, 0xfffffffd},
    {0x00000001, 0xffffffff, 0x80000000, 0x80000000},
    {0x00000001, 0xffffffff, 0x7fffffff, 0x7ffffffd},
    {0x80008000, 0x80008000, 0xffffffff, 0x7ffffffe},
    {0x80008000, 0x80008000, 0x80000000, 0xffffffff},
    {0x80008000, 0x80008000, 0x7fffffff, 0x7fffffff},
    {0x7fff7fff, 0x7fffffff, 0xffffffff, 0x7ffe0001},
    {0x7fff7fff, 0x7fffffff, 0x80000000, 0xfffe0002},
    {0x7fff7fff, 0x7fffffff, 0x00000000, 0x7ffe0002},
    {0x00000000, 0x00010000, 0x00000000, 0x00000000},
    {0x00000001, 0x00000000, 0x00000000, 0x00000000},
};

/* kdmatt */
struct ternary_calculation samples_kdmatt[] = {
    {0x00010000, 0x00010000, 0x00000001, 0x00000003},
    {0x00010000, 0x00010000, 0xffffffff, 0x00000001},
    {0x00010000, 0x00010000, 0x80000000, 0x80000002},
    {0x00010000, 0x00010000, 0x7fffffff, 0x7fffffff},
    {0x00010000, 0xffffffff, 0xffffffff, 0xfffffffd},
    {0x00010000, 0xffffffff, 0x80000000, 0x80000000},
    {0x00010000, 0xffffffff, 0x7fffffff, 0x7ffffffd},
    {0x80008000, 0x80008000, 0xffffffff, 0x7ffffffe},
    {0x80008000, 0x80008000, 0x80000000, 0xffffffff},
    {0x80008000, 0x80008000, 0x7fffffff, 0x7fffffff},
    {0x7fff7fff, 0x7fffffff, 0xffffffff, 0x7ffe0001},
    {0x7fff7fff, 0x7fffffff, 0x80000000, 0xfffe0002},
    {0x7fff7fff, 0x7fffffff, 0x00000000, 0x7ffe0002},
    {0x00000000, 0x00010000, 0x00000000, 0x00000000},
    {0x00010000, 0x00000000, 0x00000000, 0x00000000},
};

/* kmar64 */
struct ternary_ul_ul_64_calculation samples_kmar64[] = {
    {0x00000001, 0x00000001, 0x0000000000000001, 0x0000000000000002},
    {0x00000001, 0x00000001, 0xffffffffffffffff, 0x0000000000000000},
    {0x00000001, 0x00000001, 0x8000000000000000, 0x8000000000000001},
    {0x00000001, 0x00000001, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x00000001, 0xffffffff, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0x00000001, 0xffffffff, 0x8000000000000000, 0x8000000000000000},
    {0x00000001, 0xffffffff, 0x7fffffffffffffff, 0x7ffffffffffffffe},
    {0x80000000, 0x80000000, 0xffffffffffffffff, 0x3fffffffffffffff},
    {0x80000000, 0x80000000, 0x8000000000000000, 0xc000000000000000},
    {0x80000000, 0x80000000, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x7fffffff, 0xffffffff, 0xffffffffffffffff, 0xffffffff80000000},
    {0x7fffffff, 0xffffffff, 0x8000000000000000, 0x8000000000000000},
    {0x7fffffff, 0xffffffff, 0x7fffffffffffffff, 0x7fffffff80000000},
    {0x00000000, 0x00000001, 0x0000000000000000, 0x0000000000000000},
    {0x00000001, 0x00000000, 0x0000000000000000, 0x0000000000000000},
};

/* ukmar64 */
struct ternary_ul_ul_64_calculation samples_ukmar64[] = {
    {0x00000001, 0x00000001, 0x0000000000000001, 0x0000000000000002},
    {0x00000001, 0x00000001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x00000001, 0x00000001, 0x8000000000000000, 0x8000000000000001},
    {0x00000001, 0x00000001, 0x7fffffffffffffff, 0x8000000000000000},
    {0x00000001, 0xffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x00000001, 0xffffffff, 0x8000000000000000, 0x80000000ffffffff},
    {0x00000001, 0xffffffff, 0x7fffffffffffffff, 0x80000000fffffffe},
    {0x80000000, 0x80000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x80000000, 0x80000000, 0x8000000000000000, 0xc000000000000000},
    {0x80000000, 0x80000000, 0x7fffffffffffffff, 0xbfffffffffffffff},
    {0x7fffffff, 0xffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff, 0xffffffff, 0x8000000000000000, 0xFFFFFFFE80000001},
    {0x7fffffff, 0xffffffff, 0x7fffffffffffffff, 0xFFFFFFFE80000000},
    {0x00000000, 0x00000001, 0x0000000000000000, 0x0000000000000000},
    {0x00000001, 0x00000000, 0x0000000000000000, 0x0000000000000000},
};

/* kmsr64 */
struct ternary_ul_ul_64_calculation samples_kmsr64[] = {
    {0x00000001, 0x00000001, 0x0000000000000001, 0x0000000000000000},
    {0x00000001, 0x00000001, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0x00000001, 0x00000001, 0x8000000000000000, 0x8000000000000000},
    {0x00000001, 0x00000001, 0x7fffffffffffffff, 0x7ffffffffffffffe},
    {0x00000001, 0xffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0x00000001, 0xffffffff, 0x8000000000000000, 0x8000000000000001},
    {0x00000001, 0xffffffff, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x80000000, 0x80000000, 0xffffffffffffffff, 0xbfffffffffffffff},
    {0x80000000, 0x80000000, 0x8000000000000000, 0x8000000000000000},
    {0x80000000, 0x80000000, 0x7fffffffffffffff, 0x3fffffffffffffff},
    {0x7fffffff, 0xffffffff, 0xffffffffffffffff, 0x000000007ffffffe},
    {0x7fffffff, 0xffffffff, 0x8000000000000000, 0x800000007fffffff},
    {0x7fffffff, 0xffffffff, 0x0000000000000000, 0x000000007fffffff},
    {0x00000000, 0x00000001, 0x0000000000000000, 0x0000000000000000},
    {0x00000001, 0x00000000, 0x0000000000000000, 0x0000000000000000},
    {0x00000001, 0x00000001, 0x000000007fffffff, 0x000000007ffffffe},
};

/* ukmsr64 */
struct ternary_ul_ul_64_calculation samples_ukmsr64[] = {
    {0x00000001, 0x00000001, 0x0000000000000001, 0x0000000000000000},
    {0x00000001, 0x00000001, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0x00000001, 0x00000001, 0x8000000000000000, 0x7fffffffffffffff},
    {0x00000001, 0x00000001, 0x7fffffffffffffff, 0x7ffffffffffffffe},
    {0x00000001, 0xffffffff, 0xffffffffffffffff, 0xffffffff00000000},
    {0x00000001, 0xffffffff, 0x8000000000000000, 0x7fffffff00000001},
    {0x00000001, 0xffffffff, 0x7fffffffffffffff, 0x7fffffff00000000},
    {0x80000000, 0x80000000, 0xffffffffffffffff, 0xbfffffffffffffff},
    {0x80000000, 0x80000000, 0x8000000000000000, 0x4000000000000000},
    {0x80000000, 0x80000000, 0x7fffffffffffffff, 0x3fffffffffffffff},
    {0x7fffffff, 0xffffffff, 0xffffffffffffffff, 0x800000017ffffffe},
    {0x7fffffff, 0xffffffff, 0x4000000000000000, 0x0000000000000000},
    {0x7fffffff, 0xffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x00000000, 0x00000001, 0x0000000000000000, 0x0000000000000000},
    {0x00000001, 0x00000000, 0x0000000000000000, 0x0000000000000000},
    {0x00000001, 0x00000001, 0x000000007fffffff, 0x000000007ffffffe},
};

/* kwmmul */
struct binary_calculation samples_kwmmul[] = {
    {0x7fffffff, 0x7fffffff, 0x7ffffffe},
    {0x80000000, 0x80000000, 0x7fffffff},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0x00000000, 0x00000000, 0x00000000},
    {0x7fffffff, 0x80000000, 0x80000001},
    {0x80000000, 0x7fffffff, 0x80000001},
    {0x7fffffff, 0xffffffff, 0xffffffff},
    {0xffffffff, 0x7fffffff, 0xffffffff},
    {0x7fffffff, 0x00000000, 0x00000000},
    {0x00000000, 0x7fffffff, 0x00000000},
    {0x80000000, 0xffffffff, 0x00000001},
    {0xffffffff, 0x80000000, 0x00000001},
    {0x00000000, 0x80000000, 0x00000000},
    {0x80000000, 0x00000000, 0x00000000},
    {0xffffffff, 0x00000000, 0x00000000},
    {0x00000000, 0xffffffff, 0x00000000},
    {0x80000000, 0x00000001, 0xffffffff},
    {0x00000000, 0x00000000, 0x00000000},
    {0x80000000, 0x80000001, 0x7fffffff},
};

/* kwmmul.u */
struct binary_calculation samples_kwmmul_u[] = {
    {0x7fffffff, 0x7fffffff, 0x7ffffffe},
    {0x80000000, 0x80000000, 0x7fffffff},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0x00000000, 0x00000000, 0x00000000},
    {0x7fffffff, 0x80000000, 0x80000001},
    {0x80000000, 0x7fffffff, 0x80000001},
    {0x7fffffff, 0xffffffff, 0xffffffff},
    {0xffffffff, 0x7fffffff, 0xffffffff},
    {0x7fffffff, 0x00000000, 0x00000000},
    {0x00000000, 0x7fffffff, 0x00000000},
    {0x80000000, 0xffffffff, 0x00000001},
    {0xffffffff, 0x80000000, 0x00000001},
    {0x00000000, 0x80000000, 0x00000000},
    {0x80000000, 0x00000000, 0x00000000},
    {0xffffffff, 0x00000000, 0x00000000},
    {0x7fff8000, 0x80008000, 0x80010000},
    {0x80000000, 0x00000001, 0xffffffff},
    {0x07ffffff, 0x0fffffff, 0x01000000},
};

/* kmmac */
struct ternary_calculation samples_kmmac[] = {
    {0x00000001, 0x00000001, 0x00000000, 0x00000000},
    {0x00000001, 0x00000001, 0xffffffff, 0xffffffff},
    {0x00000001, 0x00000001, 0x80000000, 0x80000000},
    {0x00000001, 0x00000001, 0x7fffffff, 0x7fffffff},
    {0x00000001, 0xffffffff, 0xffffffff, 0xfffffffe},
    {0x00000001, 0xffffffff, 0x80000000, 0x80000000},
    {0x00000001, 0xffffffff, 0x7fffffff, 0x7ffffffe},
    {0x80000000, 0x80000000, 0xffffffff, 0x3fffffff},
    {0x80000000, 0x80000000, 0x80000000, 0xc0000000},
    {0x80000000, 0x80000000, 0x7fffffff, 0x7fffffff},
    {0x7fffffff, 0xffffffff, 0xffffffff, 0xfffffffe},
    {0x7fffffff, 0xffffffff, 0x80000000, 0x80000000},
    {0x7fffffff, 0xffffffff, 0x7fffffff, 0x7ffffffe},
    {0x00000000, 0x00000001, 0x00000000, 0x00000000},
    {0x00000001, 0x00000000, 0x00000000, 0x00000000},
    {0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff},
    {0x7fffffff, 0x7fffffff, 0x00000001, 0x40000000},
    {0x07ffffff, 0x0fffffff, 0xc0000000, 0xc07fffff},
    {0x80000000, 0x7fffffff, 0x7fffffff, 0x3fffffff},
};

/* kmmsb */
struct ternary_calculation samples_kmmsb[] = {
    {0x00000001, 0x00000001, 0x00000000, 0x00000000},
    {0x00000001, 0x00000001, 0xffffffff, 0xffffffff},
    {0x00000001, 0x00000001, 0x80000000, 0x80000000},
    {0x00000001, 0x00000001, 0x7fffffff, 0x7fffffff},
    {0x00000001, 0xffffffff, 0xffffffff, 0x00000000},
    {0x00000001, 0xffffffff, 0x80000000, 0x80000001},
    {0x00000001, 0xffffffff, 0x7fffffff, 0x7fffffff},
    {0x80000000, 0x80000000, 0xffffffff, 0xbfffffff},
    {0x80000000, 0x80000000, 0x80000000, 0x80000000},
    {0x80000000, 0x80000000, 0x7fffffff, 0x3fffffff},
    {0x7fffffff, 0xffffffff, 0xffffffff, 0x00000000},
    {0x7fffffff, 0xffffffff, 0x80000000, 0x80000001},
    {0x7fffffff, 0xffffffff, 0x7fffffff, 0x7fffffff},
    {0x00000000, 0x00000001, 0x00000000, 0x00000000},
    {0x00000001, 0x00000000, 0x00000000, 0x00000000},
    {0x7fffffff, 0x7fffffff, 0x80000000, 0x80000000},
    {0x7fffffff, 0x7fffffff, 0x7fffffff, 0x40000000},
};

/* kmmac.u */
struct ternary_calculation samples_kmmac_u[] = {
    {0x00000001, 0x00000001, 0x00000000, 0x00000000},
    {0x00000001, 0x00000001, 0xffffffff, 0xffffffff},
    {0x00000001, 0x00000001, 0x80000000, 0x80000000},
    {0x00000001, 0x00000001, 0x7fffffff, 0x7fffffff},
    {0x00000001, 0xffffffff, 0xffffffff, 0xffffffff},
    {0x00000001, 0xffffffff, 0x80000000, 0x80000000},
    {0x00000001, 0xffffffff, 0x7fffffff, 0x7fffffff},
    {0x80000000, 0x80000000, 0xffffffff, 0x3fffffff},
    {0x80000000, 0x80000000, 0x80000000, 0xc0000000},
    {0x80000000, 0x80000000, 0x7fffffff, 0x7fffffff},
    {0x7fffffff, 0xffffffff, 0xffffffff, 0xffffffff},
    {0x7fffffff, 0xffffffff, 0x80000000, 0x80000000},
    {0x7fffffff, 0xffffffff, 0x7fffffff, 0x7fffffff},
    {0x00000000, 0x00000001, 0x00000000, 0x00000000},
    {0x00000001, 0x00000000, 0x00000000, 0x00000000},
    {0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff},
    {0x80000000, 0x00000002, 0x80000000, 0x80000000},
};

/* kmmsb.u */
struct ternary_calculation samples_kmmsb_u[] = {
    {0x00000001, 0x00000001, 0x00000000, 0x00000000},
    {0x00000001, 0x00000001, 0xffffffff, 0xffffffff},
    {0x00000001, 0x00000001, 0x80000000, 0x80000000},
    {0x00000001, 0x00000001, 0x7fffffff, 0x7fffffff},
    {0x00000001, 0xffffffff, 0xffffffff, 0xffffffff},
    {0x00000001, 0xffffffff, 0x80000000, 0x80000000},
    {0x00000001, 0xffffffff, 0x7fffffff, 0x7fffffff},
    {0x80000000, 0x80000000, 0xffffffff, 0xbfffffff},
    {0x80000000, 0x80000000, 0x80000000, 0x80000000},
    {0x80000000, 0x80000000, 0x7fffffff, 0x3fffffff},
    {0x7fffffff, 0xffffffff, 0xffffffff, 0xffffffff},
    {0x7fffffff, 0xffffffff, 0x80000000, 0x80000000},
    {0x7fffffff, 0xffffffff, 0x7fffffff, 0x7fffffff},
    {0x00000000, 0x00000001, 0x00000000, 0x00000000},
    {0x00000001, 0x00000000, 0x00000000, 0x00000000},
    {0x7fffffff, 0x80000000, 0x7fffffff, 0x7fffffff},
    {0x7fffffff, 0x00000002, 0x80000000, 0x80000000},
};

/* smmwb */
struct binary_calculation samples_smmwb[] = {
    {0x00000001, 0x00010001, 0x00000000},
    {0x00000001, 0x7fff7fff, 0x00000000},
    {0x00000001, 0xffffffff, 0xffffffff},
    {0xffffffff, 0x00010001, 0xffffffff},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0xffffffff, 0x7fff7fff, 0xffffffff},
    {0x80000000, 0x80008000, 0x40000000},
    {0x80000000, 0x7fff7fff, 0xc0008000},
    {0x80000000, 0xffffffff, 0x00008000},
    {0x7fffffff, 0x00010001, 0x00007fff},
    {0x7fffffff, 0xffffffff, 0xffff8000},
    {0x7fffffff, 0x7fff7fff, 0x3fff7fff},
    {0x7fffffff, 0x80008000, 0xc0000000},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0x7fff7fff, 0x00000000},
    {0x7fffffff, 0xffff7fff, 0x3fff7fff},
    {0x7fffffff, 0x7fffffff, 0xffff8000},
    {0x7fffffff, 0x7fff8000, 0xc0000000},
};

/* smmwb.u */
struct binary_calculation samples_smmwb_u[] = {
    {0x00000001, 0x00010001, 0x00000000},
    {0x00000001, 0x7fff7fff, 0x00000000},
    {0x00000001, 0xffffffff, 0x00000000},
    {0xffffffff, 0x00010001, 0x00000000},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0xffffffff, 0x7fff7fff, 0x00000000},
    {0x80000000, 0x7fff7fff, 0xc0008000},
    {0x80000000, 0xffffffff, 0x00008000},
    {0x7fffffff, 0x00010001, 0x00008000},
    {0x7fffffff, 0xffffffff, 0xffff8000},
    {0x7fffffff, 0x7fff7fff, 0x3fff8000},
    {0x7fffffff, 0x80008000, 0xc0000001},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0x7fff7fff, 0x00000000},
    {0x7fffffff, 0x0000ffff, 0xffff8000},
    {0x7fffffff, 0x00007fff, 0x3fff8000},
    {0x80000000, 0x0000ffff, 0x00008000},
    {0x80008000, 0x0000ffff, 0x00008000},
};

/* smmwt */
struct binary_calculation samples_smmwt[] = {
    {0x00000001, 0x00010001, 0x00000000},
    {0x00000001, 0x7fff7fff, 0x00000000},
    {0x00000001, 0xffffffff, 0xffffffff},
    {0xffffffff, 0x00010001, 0xffffffff},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0xffffffff, 0x7fff7fff, 0xffffffff},
    {0x80000000, 0x80008000, 0x40000000},
    {0x80000000, 0x7fff7fff, 0xc0008000},
    {0x80000000, 0xffffffff, 0x00008000},
    {0x7fffffff, 0x00010001, 0x00007fff},
    {0x7fffffff, 0xffffffff, 0xffff8000},
    {0x7fffffff, 0x7fff7fff, 0x3fff7fff},
    {0x7fffffff, 0x80008000, 0xc0000000},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0x7fff7fff, 0x00000000},
    {0x7fffffff, 0x00007fff, 0x00000000},
    {0x7fffffff, 0x7fff0000, 0x3fff7fff},
    {0x7fffffff, 0x80000001, 0xc0000000},
};

/* smmwt.u */
struct binary_calculation samples_smmwt_u[] = {
    {0x00000001, 0x00010001, 0x00000000},
    {0x00000001, 0x7fff7fff, 0x00000000},
    {0x00000001, 0xffffffff, 0x00000000},
    {0xffffffff, 0x00010001, 0x00000000},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0xffffffff, 0x7fff7fff, 0x00000000},
    {0x80000000, 0x80008000, 0x40000000},
    {0x80000000, 0x7fff7fff, 0xc0008000},
    {0x80000000, 0xffffffff, 0x00008000},
    {0x7fffffff, 0x00010001, 0x00008000},
    {0x7fffffff, 0xffffffff, 0xffff8000},
    {0x7fffffff, 0x7fff7fff, 0x3fff8000},
    {0x7fffffff, 0x80008000, 0xc0000001},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0x7fff7fff, 0x00000000},
    {0x7fffffff, 0x7fff0000, 0x3fff8000},
    {0x7fffffff, 0x80007fff, 0xc0000001},
    {0x80000000, 0x7fff8000, 0xc0008000},
};

/* kmmwb2 */
struct binary_calculation samples_kmmwb2[] = {
    {0x00000001, 0x00010001, 0x00000000},
    {0x00000001, 0x7fff7fff, 0x00000000},
    {0x00000001, 0xffffffff, 0xffffffff},
    {0xffffffff, 0x00010001, 0xffffffff},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0xffffffff, 0x7fff7fff, 0xffffffff},
    {0x80000000, 0x80008000, 0x7fffffff},
    {0x80000000, 0x7fff7fff, 0x80010000},
    {0x80000000, 0xffffffff, 0x00010000},
    {0x7fffffff, 0x00010001, 0x0000ffff},
    {0x7fffffff, 0xffffffff, 0xffff0000},
    {0x7fffffff, 0x7fff7fff, 0x7ffeffff},
    {0x7fffffff, 0x80008000, 0x80000001},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0x7fff7fff, 0x00000000},
    {0x80000000, 0x7fff8000, 0x7fffffff},
    {0x7fffffff, 0xffff7fff, 0x7ffeffff},
    {0x7fffffff, 0x7fffffff, 0xffff0000},
    {0x80000000, 0x7fffffff, 0x00010000},
};

/* kmmwb2.u */
struct binary_calculation samples_kmmwb2_u[] = {
    {0x00000001, 0x00010001, 0x00000000},
    {0x00000001, 0x7fff7fff, 0x00000001},
    {0x00000001, 0xffffffff, 0x00000000},
    {0xffffffff, 0x00010001, 0x00000000},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0xffffffff, 0x7fff7fff, 0xffffffff},
    {0x80000000, 0x80008000, 0x7fffffff},
    {0x80000000, 0x7fff7fff, 0x80010000},
    {0x80000000, 0xffffffff, 0x00010000},
    {0x7fffffff, 0x00010001, 0x00010000},
    {0x7fffffff, 0xffffffff, 0xffff0000},
    {0x7fffffff, 0x7fff7fff, 0x7ffeffff},
    {0x7fffffff, 0x80008000, 0x80000001},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0x7fff7fff, 0x00000000},
    {0x7fffffff, 0xffff7fff, 0x7ffeffff},
    {0x7fffffff, 0x7fffffff, 0xffff0000},
    {0x0000ffff, 0x0000ffff, 0xfffffffe},
    {0x80000000, 0x7fff8000, 0x7fffffff},
    {0x80000000, 0x80007fff, 0x80010000},
};

/* kmmwt2 */
struct binary_calculation samples_kmmwt2[] = {
    {0x00000001, 0x00010001, 0x00000000},
    {0x00000001, 0x7fff7fff, 0x00000000},
    {0x00000001, 0xffffffff, 0xffffffff},
    {0xffffffff, 0x00010001, 0xffffffff},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0xffffffff, 0x7fff7fff, 0xffffffff},
    {0x80000000, 0x80008000, 0x7fffffff},
    {0x80000000, 0x7fff7fff, 0x80010000},
    {0x80000000, 0xffffffff, 0x00010000},
    {0x7fffffff, 0x00010001, 0x0000ffff},
    {0x7fffffff, 0xffffffff, 0xffff0000},
    {0x7fffffff, 0x7fff7fff, 0x7ffeffff},
    {0x7fffffff, 0x80008000, 0x80000001},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0x7fff7fff, 0x00000000},
    {0x80000000, 0x8000ffff, 0x7fffffff},
    {0x7fffffff, 0x00007fff, 0x00000000},
    {0x7fffffff, 0x7fff0000, 0x7ffeffff},
    {0x7fffffff, 0x80000001, 0x80000001},
};

/* kmmwt2.u */
struct binary_calculation samples_kmmwt2_u[] = {
    {0x00000001, 0x00010001, 0x00000000},
    {0x00000001, 0x7fff7fff, 0x00000001},
    {0x00000001, 0xffffffff, 0x00000000},
    {0xffffffff, 0x00010001, 0x00000000},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0xffffffff, 0x7fff7fff, 0xffffffff},
    {0x80000000, 0x80008000, 0x7fffffff},
    {0x80000000, 0x7fff7fff, 0x80010000},
    {0x80000000, 0xffffffff, 0x00010000},
    {0x7fffffff, 0x00010001, 0x00010000},
    {0x7fffffff, 0xffffffff, 0xffff0000},
    {0x7fffffff, 0x7fff7fff, 0x7ffeffff},
    {0x7fffffff, 0x80008000, 0x80000001},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0x7fff7fff, 0x00000000},
    {0x7fffffff, 0x7fffffff, 0x7ffeffff},
    {0x7fffffff, 0xffff7fff, 0xffff0000},
    {0x80000000, 0x8000ffff, 0x7fffffff},
    {0x80000001, 0x8001ffff, 0x7ffeffff},
};

/* kmmawb */
struct ternary_calculation samples_kmmawb[] = {
    {0x00000001, 0x00010001, 0x00000001, 0x00000001},
    {0x00000001, 0x7fff7fff, 0x7fffffff, 0x7fffffff},
    {0x00000001, 0xffffffff, 0x80000000, 0x80000000},
    {0xffffffff, 0x00010001, 0xffffffff, 0xfffffffe},
    {0xffffffff, 0xffffffff, 0x40000000, 0x40000000},
    {0xffffffff, 0x7fff7fff, 0x00000000, 0xffffffff},
    {0x80000000, 0x80008000, 0x00008000, 0x40008000},
    {0x80000000, 0x7fff7fff, 0x7fffffff, 0x40007fff},
    {0x80000000, 0xffffffff, 0x80000000, 0x80008000},
    {0x7fffffff, 0x00010001, 0xffffffff, 0x00007ffe},
    {0x7fffffff, 0xffffffff, 0x00000001, 0xffff8001},
    {0x7fffffff, 0x7fff7fff, 0x80000000, 0xbfff7fff},
    {0x7fffffff, 0x80008000, 0x7fffffff, 0x3fffffff},
    {0x00000000, 0x00000000, 0x00008000, 0x00008000},
    {0x00000000, 0x7fff7fff, 0x00000000, 0x00000000},
    {0x7fffffff, 0xffff0001, 0x7fffffff, 0x7fffffff},
    {0x00000001, 0x7fffffff, 0x80000000, 0x80000000},
};

/* kmmawb.u */
struct ternary_calculation samples_kmmawb_u[] = {
    {0x00000001, 0x00010001, 0x00000001, 0x00000001},
    {0x00000001, 0x7fff7fff, 0x7fffffff, 0x7fffffff},
    {0x00000001, 0xffffffff, 0x80000000, 0x80000000},
    {0xffffffff, 0x00010001, 0xffffffff, 0xffffffff},
    {0xffffffff, 0xffffffff, 0x40000000, 0x40000000},
    {0xffffffff, 0x7fff7fff, 0x00000000, 0x00000000},
    {0x80000000, 0x80008000, 0x00008000, 0x40008000},
    {0x80000000, 0x7fff7fff, 0x7fffffff, 0x40007fff},
    {0x80000000, 0xffffffff, 0x80000000, 0x80008000},
    {0x7fffffff, 0x00010001, 0xffffffff, 0x00007fff},
    {0x7fffffff, 0xffffffff, 0x00000001, 0xffff8001},
    {0x7fffffff, 0x7fff7fff, 0x80000000, 0xbfff8000},
    {0x7fffffff, 0x80008000, 0x7fffffff, 0x40000000},
    {0x00000000, 0x00000000, 0x00008000, 0x00008000},
    {0x00000000, 0x7fff7fff, 0x00000000, 0x00000000},
    {0x7fffffff, 0xffff7fff, 0x7fffffff, 0x7fffffff},
    {0x7fffffff, 0xffffffff, 0x80000000, 0x80000000},
    {0x7fffffff, 0x00000001, 0x80000000, 0x80008000},
};

/* kmmawb2 */
struct ternary_calculation samples_kmmawb2[] = {
    {0x00000001, 0x00010001, 0x00000001, 0x00000001},
    {0x00000001, 0x7fff7fff, 0x7fffffff, 0x7fffffff},
    {0x00000001, 0xffffffff, 0x80000000, 0x80000000},
    {0xffffffff, 0x00010001, 0xffffffff, 0xfffffffe},
    {0xffffffff, 0xffffffff, 0x40000000, 0x40000000},
    {0xffffffff, 0x7fff7fff, 0x00000000, 0xffffffff},
    {0x80000000, 0x80008000, 0x00008000, 0x7fffffff},
    {0x80000000, 0x7fff7fff, 0x7fffffff, 0x0000ffff},
    {0x80000000, 0xffffffff, 0x80000000, 0x80010000},
    {0x7fffffff, 0x00010001, 0xffffffff, 0x0000fffe},
    {0x7fffffff, 0xffffffff, 0x00000001, 0xffff0001},
    {0x7fffffff, 0x7fff7fff, 0x80000000, 0xfffeffff},
    {0x7fffffff, 0x80008000, 0x7fffffff, 0x00000000},
    {0x00000000, 0x00000000, 0x00008000, 0x00008000},
    {0x00000000, 0x7fff7fff, 0x00000000, 0x00000000},
    {0x7fffffff, 0xffff0001, 0x7fffffff, 0x7fffffff},
    {0x00000001, 0x7fffffff, 0x80000000, 0x80000000},
};

/* kmmawb2.u */
struct ternary_calculation samples_kmmawb2_u[] = {
    {0x00000001, 0x00010001, 0x00000001, 0x00000001},
    {0x00000001, 0x7fff7fff, 0x7fffffff, 0x7fffffff},
    {0x00000001, 0xffffffff, 0x80000000, 0x80000000},
    {0xffffffff, 0x00010001, 0xffffffff, 0xffffffff},
    {0xffffffff, 0xffffffff, 0x40000000, 0x40000000},
    {0xffffffff, 0x7fff7fff, 0x00000000, 0xffffffff},
    {0x80000000, 0x80008000, 0x00008000, 0x7fffffff},
    {0x80000000, 0x7fff7fff, 0x7fffffff, 0x0000ffff},
    {0x80000000, 0xffffffff, 0x80000000, 0x80010000},
    {0x7fffffff, 0x00010001, 0xffffffff, 0x0000ffff},
    {0x7fffffff, 0xffffffff, 0x00000001, 0xffff0001},
    {0x7fffffff, 0x7fff7fff, 0x80000000, 0xfffeffff},
    {0x7fffffff, 0x80008000, 0x7fffffff, 0x00000000},
    {0x00000000, 0x00000000, 0x00008000, 0x00008000},
    {0x00000000, 0x7fff7fff, 0x00000000, 0x00000000},
    {0x7fffffff, 0xffff0001, 0x7fffffff, 0x7fffffff},
    {0x00000001, 0x7fffffff, 0x80000000, 0x80000000},
};

/* kmmawt */
struct ternary_calculation samples_kmmawt[] = {
    {0x00000001, 0x00010001, 0x00000001, 0x00000001},
    {0x00000001, 0x7fff7fff, 0x7fffffff, 0x7fffffff},
    {0x00000001, 0xffffffff, 0x80000000, 0x80000000},
    {0xffffffff, 0x00010001, 0xffffffff, 0xfffffffe},
    {0xffffffff, 0xffffffff, 0x40000000, 0x40000000},
    {0xffffffff, 0x7fff7fff, 0x00000000, 0xffffffff},
    {0x80000000, 0x80008000, 0x00008000, 0x40008000},
    {0x80000000, 0x7fff7fff, 0x7fffffff, 0x40007fff},
    {0x80000000, 0xffffffff, 0x80000000, 0x80008000},
    {0x7fffffff, 0x00010001, 0xffffffff, 0x00007ffe},
    {0x7fffffff, 0xffffffff, 0x00000001, 0xffff8001},
    {0x7fffffff, 0x7fff7fff, 0x80000000, 0xbfff7fff},
    {0x7fffffff, 0x80008000, 0x7fffffff, 0x3fffffff},
    {0x00000000, 0x00000000, 0x00008000, 0x00008000},
    {0x00000000, 0x7fff7fff, 0x00000000, 0x00000000},
    {0x7fffffff, 0x0001ffff, 0x7fffffff, 0x7fffffff},
    {0x7fffffff, 0xffff7fff, 0x80000000, 0x80000000},
    {0x7fffffff, 0x7fffffff, 0x00000000, 0x3fff7fff},
};

/* kmmawt.u */
struct ternary_calculation samples_kmmawt_u[] = {
    {0x00000001, 0x00010001, 0x00000001, 0x00000001},
    {0x00000001, 0x7fff7fff, 0x7fffffff, 0x7fffffff},
    {0x00000001, 0xffffffff, 0x80000000, 0x80000000},
    {0xffffffff, 0x00010001, 0xffffffff, 0xffffffff},
    {0xffffffff, 0xffffffff, 0x40000000, 0x40000000},
    {0xffffffff, 0x7fff7fff, 0x00000000, 0x00000000},
    {0x80000000, 0x80008000, 0x00008000, 0x40008000},
    {0x80000000, 0x7fff7fff, 0x7fffffff, 0x40007fff},
    {0x80000000, 0xffffffff, 0x80000000, 0x80008000},
    {0x7fffffff, 0x00010001, 0xffffffff, 0x00007fff},
    {0x7fffffff, 0xffffffff, 0x00000001, 0xffff8001},
    {0x7fffffff, 0x7fff7fff, 0x80000000, 0xbfff8000},
    {0x7fffffff, 0x80008000, 0x7fffffff, 0x40000000},
    {0x00000000, 0x00000000, 0x00008000, 0x00008000},
    {0x00000000, 0x7fff7fff, 0x00000000, 0x00000000},
    {0x7fffffff, 0x7fff0000, 0x7fffffff, 0x7fffffff},
    {0x7fffffff, 0xffff0000, 0x80000000, 0x80000000},
    {0x7fffffff, 0x7fffffff, 0x00000000, 0x3fff8000},
};

/* kmmawt2 */
struct ternary_calculation samples_kmmawt2[] = {
    {0x00000001, 0x00010001, 0x00000001, 0x00000001},
    {0x00000001, 0x7fff7fff, 0x7fffffff, 0x7fffffff},
    {0x00000001, 0xffffffff, 0x80000000, 0x80000000},
    {0xffffffff, 0x00010001, 0xffffffff, 0xfffffffe},
    {0xffffffff, 0xffffffff, 0x40000000, 0x40000000},
    {0xffffffff, 0x7fff7fff, 0x00000000, 0xffffffff},
    {0x80000000, 0x80008000, 0x00008000, 0x7fffffff},
    {0x80000000, 0x7fff7fff, 0x7fffffff, 0x0000ffff},
    {0x80000000, 0xffffffff, 0x80000000, 0x80010000},
    {0x7fffffff, 0x00010001, 0xffffffff, 0x0000fffe},
    {0x7fffffff, 0xffffffff, 0x00000001, 0xffff0001},
    {0x7fffffff, 0x7fff7fff, 0x80000000, 0xfffeffff},
    {0x7fffffff, 0x80008000, 0x7fffffff, 0x00000000},
    {0x00000000, 0x00000000, 0x00008000, 0x00008000},
    {0x00000000, 0x7fff7fff, 0x00000000, 0x00000000},
    {0x7fffffff, 0xffff0001, 0x7fffffff, 0x7ffeffff},
    {0x00000001, 0x7fffffff, 0x80000000, 0x80000000},
};

/* kmmawt2.u */
struct ternary_calculation samples_kmmawt2_u[] = {
    {0x00000001, 0x00010001, 0x00000001, 0x00000001},
    {0x00000001, 0x7fff7fff, 0x7fffffff, 0x7fffffff},
    {0x00000001, 0xffffffff, 0x80000000, 0x80000000},
    {0xffffffff, 0x00010001, 0xffffffff, 0xffffffff},
    {0xffffffff, 0xffffffff, 0x40000000, 0x40000000},
    {0xffffffff, 0x7fff7fff, 0x00000000, 0xffffffff},
    {0x80000000, 0x80008000, 0x00008000, 0x7fffffff},
    {0x80000000, 0x7fff7fff, 0x7fffffff, 0x0000ffff},
    {0x80000000, 0xffffffff, 0x80000000, 0x80010000},
    {0x7fffffff, 0x00010001, 0xffffffff, 0x0000ffff},
    {0x7fffffff, 0xffffffff, 0x00000001, 0xffff0001},
    {0x7fffffff, 0x7fff7fff, 0x80000000, 0xfffeffff},
    {0x7fffffff, 0x80008000, 0x7fffffff, 0x00000000},
    {0x00000000, 0x00000000, 0x00008000, 0x00008000},
    {0x00000000, 0x7fff7fff, 0x00000000, 0x00000000},
    {0x7fffffff, 0xffff0001, 0x7fffffff, 0x7ffeffff},
    {0x00000001, 0x7fffffff, 0x80000000, 0x80000001},
};

/* kdmbb */
struct binary_calculation samples_kdmbb[] = {
    {0x00000001, 0x00000001, 0x00000002},
    {0x00000001, 0x7fff7fff, 0x0000fffe},
    {0x00000001, 0xffffffff, 0xfffffffe},
    {0xffffffff, 0xffffffff, 0x00000002},
    {0x00008000, 0x80008000, 0x7fffffff},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0x7fffffff, 0x00000000},
    {0x80000000, 0x00008000, 0x00000000},
    {0x00008000, 0x00008000, 0x7fffffff},
    {0x80007fff, 0xffff7fff, 0x7ffe0002},
    {0x80007fff, 0x7fffffff, 0xffff0002},
    {0x80007fff, 0x7fff8000, 0x80010000},
};

/* kdmtt */
struct binary_calculation samples_kdmtt[] = {
    {0x00010000, 0x00010000, 0x00000002},
    {0x00010000, 0x7fff7fff, 0x0000fffe},
    {0x00010000, 0xffffffff, 0xfffffffe},
    {0xffffffff, 0xffffffff, 0x00000002},
    {0x80000000, 0x80008000, 0x7fffffff},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0xffff7fff, 0x00000000},
    {0x00008000, 0x80000000, 0x00000000},
    {0x80000000, 0x8000ffff, 0x7fffffff},
    {0x7fffffff, 0xffff7fff, 0xffff0002},
    {0x7fffffff, 0x0000ffff, 0x00000000},
    {0x8000ffff, 0x7fffffff, 0x80010000},
};

/* kdmbt */
struct binary_calculation samples_kdmbt[] = {
    {0x00000001, 0x00010000, 0x00000002},
    {0x00000001, 0x7fff7fff, 0x0000fffe},
    {0x00000001, 0xffffffff, 0xfffffffe},
    {0xffffffff, 0xffffffff, 0x00000002},
    {0x00008000, 0x80008000, 0x7fffffff},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0xffff7fff, 0x00000000},
    {0x80000000, 0x80000000, 0x00000000},
    {0x00008000, 0x8000ffff, 0x7fffffff},
    {0xffff7fff, 0xffff7fff, 0xffff0002},
    {0xffff7fff, 0x0000ffff, 0x00000000},
    {0xffff8000, 0x7fffffff, 0x80010000},
};

/* kmabb */
struct ternary_calculation samples_kmabb[] = {
    {0x00008000, 0x0001ffff, 0x7fffffff, 0x7fffffff},
    {0x00017fff, 0x00007fff, 0x80000000, 0xbfff0001},
    {0x00017fff, 0x00007fff, 0xffffffff, 0x3fff0000},
    {0x00017fff, 0x00007fff, 0x7fffffff, 0x7fffffff},
    {0xffff8000, 0x00008000, 0x80000000, 0xc0000000},
    {0x80008000, 0x7fff8000, 0xffffffff, 0x3fffffff},
    {0xffff8000, 0x80008000, 0x7fffffff, 0x7fffffff},
    {0xffffffff, 0x0000ffff, 0x80000000, 0x80000001},
    {0x8000ffff, 0x7fffffff, 0xffffffff, 0x00000000},
    {0x8000ffff, 0x8000ffff, 0x7fffffff, 0x7fffffff},
    {0x00007fff, 0x00008000, 0x80000000, 0x80000000},
    {0x7fff8000, 0x7fff7fff, 0xffffffff, 0xc0007fff},
    {0x80008000, 0x80007fff, 0x7fffffff, 0x40007fff},
    {0x0000ffff, 0x00018000, 0x80000000, 0x80008000},
    {0x00008000, 0x0001ffff, 0xffffffff, 0x00007fff},
    {0x00000000, 0xffffffff, 0x00000000, 0x00000000},
    {0x7fff0000, 0x8000ffff, 0xffffffff, 0xffffffff},
    {0x8000ffff, 0xffff0000, 0x00000000, 0x00000000},
    {0x0000ffff, 0xffff0000, 0xffffffff, 0xffffffff},
    {0x7fff0000, 0x80000000, 0x00000000, 0x00000000},
    {0x80000000, 0x80000000, 0xffffffff, 0xffffffff},
    {0xffffffff, 0x00000001, 0x80000000, 0x80000000},
    {0x00000001, 0x00000001, 0x7fffffff, 0x7fffffff},
};

/* kmatt */
struct ternary_calculation samples_kmatt[] = {
    {0x80000000, 0xffff0001, 0x7fffffff, 0x7fffffff},
    {0x7fff0001, 0x7fff0000, 0x80000000, 0xbfff0001},
    {0x7fff0001, 0x7fff0000, 0xffffffff, 0x3fff0000},
    {0x7fff0001, 0x7fff0000, 0x7fffffff, 0x7fffffff},
    {0x8000ffff, 0x80000000, 0x80000000, 0xc0000000},
    {0x80008000, 0x80007fff, 0xffffffff, 0x3fffffff},
    {0x8000ffff, 0x80008000, 0x7fffffff, 0x7fffffff},
    {0xffffffff, 0xffff0000, 0x80000000, 0x80000001},
    {0xffff8000, 0xffff7fff, 0xffffffff, 0x00000000},
    {0xffff8000, 0xffff8000, 0x7fffffff, 0x7fffffff},
    {0x7fff0000, 0x80000000, 0x80000000, 0x80000000},
    {0x80007fff, 0x7fff7fff, 0xffffffff, 0xc0007fff},
    {0x80008000, 0x7fff8000, 0x7fffffff, 0x40007fff},
    {0xffff0000, 0x80000001, 0x80000000, 0x80008000},
    {0x80000000, 0xffff0001, 0xffffffff, 0x00007fff},
    {0x00000000, 0xffffffff, 0x00000000, 0x00000000},
    {0x00007fff, 0xffff8000, 0xffffffff, 0xffffffff},
    {0xffff8000, 0x0000ffff, 0x00000000, 0x00000000},
    {0xffff0000, 0x0000ffff, 0xffffffff, 0xffffffff},
    {0x00007fff, 0x00008000, 0x00000000, 0x00000000},
    {0x00008000, 0x00008000, 0xffffffff, 0xffffffff},
    {0xffffffff, 0x0001ffff, 0x80000000, 0x80000000},
    {0x0001ffff, 0xffffffff, 0x7fffffff, 0x7ffffffe},
};

/* kmabt */
struct ternary_calculation samples_kmabt[] = {
    {0x0001ffff, 0x80000000, 0x7fffffff, 0x7fffffff},
    {0x00007fff, 0x7fff0001, 0x80000000, 0xbfff0001},
    {0x00007fff, 0x7fff0001, 0xffffffff, 0x3fff0000},
    {0x00007fff, 0x7fff0001, 0x7fffffff, 0x7fffffff},
    {0x00008000, 0x8000ffff, 0x80000000, 0xc0000000},
    {0x7fff8000, 0x80008000, 0xffffffff, 0x3fffffff},
    {0x80008000, 0x8000ffff, 0x7fffffff, 0x7fffffff},
    {0x0000ffff, 0xffffffff, 0x80000000, 0x80000001},
    {0x7fffffff, 0xffff8000, 0xffffffff, 0x00000000},
    {0x8000ffff, 0xffff8000, 0x7fffffff, 0x7fffffff},
    {0x00008000, 0x7fff0000, 0x80000000, 0x80000000},
    {0x7fff7fff, 0x80007fff, 0xffffffff, 0xc0007fff},
    {0x80007fff, 0x80008000, 0x7fffffff, 0x40007fff},
    {0x00018000, 0xffff0000, 0x80000000, 0x80008000},
    {0x0001ffff, 0x80000000, 0xffffffff, 0x00007fff},
    {0xffffffff, 0x00000000, 0x00000000, 0x00000000},
    {0x8000ffff, 0x00007fff, 0xffffffff, 0xffffffff},
    {0xffff0000, 0xffff8000, 0x00000000, 0x00000000},
    {0xffff0000, 0xffff0000, 0xffffffff, 0xffffffff},
    {0x80000000, 0x00007fff, 0x00000000, 0x00000000},
    {0x80000000, 0x00008000, 0xffffffff, 0xffffffff},
    {0xffff0001, 0xffffffff, 0x80000000, 0x80000000},
    {0xffff0001, 0x0001ffff, 0x7fffffff, 0x7fffffff},
    {0x7fffffff, 0x0001ffff, 0x7fffffff, 0x7ffffffe},
};

/* smalbb */
struct ternary_ul_ul_64_calculation samples_smalbb[] = {
    {0x00017fff, 0x00007fff, 0x8000000000000000, 0x800000003fff0001},
    {0x00017fff, 0x00007fff, 0xffffffffffffffff, 0x000000003fff0000},
    {0x00017fff, 0x00007fff, 0x7fffffffffffffff, 0x800000003fff0000},
    {0xffff8000, 0x00008000, 0x8000000000000000, 0x8000000040000000},
    {0x80008000, 0x7fff8000, 0xffffffffffffffff, 0x000000003fffffff},
    {0xffff8000, 0x80008000, 0x7fffffffffffffff, 0x800000003fffffff},
    {0xffff7fff, 0x00008000, 0x8000000000000000, 0x7fffffffc0008000},
    {0x80007fff, 0x7fff8000, 0xffffffffffffffff, 0xffffffffc0007fff},
    {0x80007fff, 0x80008000, 0x7fffffffffffffff, 0x7fffffffc0007fff},
    {0x0000ffff, 0x0000ffff, 0x8000000000000000, 0x8000000000000001},
    {0x7fffffff, 0x7fffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0x8000ffff, 0x8000ffff, 0x7fffffffffffffff, 0x8000000000000000},
    {0x0000ffff, 0x00018000, 0x8000000000000000, 0x8000000000008000},
    {0x00008000, 0x0001ffff, 0xffffffffffffffff, 0x0000000000007fff},
    {0x00008000, 0x0001ffff, 0x7fffffffffffffff, 0x8000000000007fff},
    {0x00000000, 0xffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x7fff0000, 0x8000ffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x8000ffff, 0xffff0000, 0x0000000000000000, 0x0000000000000000},
    {0x0000ffff, 0xffff0000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fff0000, 0x80000000, 0x0000000000000000, 0x0000000000000000},
    {0x80000000, 0x80000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x00007fff, 0x00007fff, 0x8000000000000000, 0x800000003fff0001},
    {0x00007fff, 0x00007fff, 0x7fffffffffffffff, 0x800000003fff0000},
    {0x00008000, 0x00008000, 0xffffffffffffffff, 0x000000003fffffff},
    {0x00007fff, 0x00008000, 0xffffffffffffffff, 0xffffffffc0007fff},
};

/* smalbt */
struct ternary_ul_ul_64_calculation samples_smalbt[] = {
    {0x00017fff, 0x7fff0000, 0x8000000000000000, 0x800000003fff0001},
    {0x00017fff, 0x7fff0000, 0xffffffffffffffff, 0x000000003fff0000},
    {0x00017fff, 0x7fff0000, 0x7fffffffffffffff, 0x800000003fff0000},
    {0xffff8000, 0x80000000, 0x8000000000000000, 0x8000000040000000},
    {0x80008000, 0x80007fff, 0xffffffffffffffff, 0x000000003fffffff},
    {0xffff8000, 0x80008000, 0x7fffffffffffffff, 0x800000003fffffff},
    {0xffff7fff, 0x80000000, 0x8000000000000000, 0x7fffffffc0008000},
    {0x80007fff, 0x80007fff, 0xffffffffffffffff, 0xffffffffc0007fff},
    {0x80007fff, 0x80008000, 0x7fffffffffffffff, 0x7fffffffc0007fff},
    {0x0000ffff, 0xffff0000, 0x8000000000000000, 0x8000000000000001},
    {0x7fffffff, 0xffff7fff, 0xffffffffffffffff, 0x0000000000000000},
    {0x8000ffff, 0xffff8000, 0x7fffffffffffffff, 0x8000000000000000},
    {0x0000ffff, 0x80000001, 0x8000000000000000, 0x8000000000008000},
    {0x00008000, 0xffff0001, 0xffffffffffffffff, 0x0000000000007fff},
    {0x00008000, 0xffff0001, 0x7fffffffffffffff, 0x8000000000007fff},
    {0x00000000, 0xffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x7fff0000, 0xffff8000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x8000ffff, 0x0000ffff, 0x0000000000000000, 0x0000000000000000},
    {0x0000ffff, 0x0000ffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fff0000, 0x00008000, 0x0000000000000000, 0x0000000000000000},
    {0x80000000, 0x00008000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x00007fff, 0x7fff0000, 0x8000000000000000, 0x800000003fff0001},
    {0x00007fff, 0x7fff0000, 0x7fffffffffffffff, 0x800000003fff0000},
    {0x00008000, 0x80000000, 0xffffffffffffffff, 0x000000003fffffff},
    {0x00007fff, 0x80000000, 0xffffffffffffffff, 0xffffffffc0007fff},
};

/* smaltt */
struct ternary_ul_ul_64_calculation samples_smaltt[] = {
    {0x7fff0001, 0x7fff0000, 0x8000000000000000, 0x800000003fff0001},
    {0x7fff0001, 0x7fff0000, 0xffffffffffffffff, 0x000000003fff0000},
    {0x7fff0001, 0x7fff0000, 0x7fffffffffffffff, 0x800000003fff0000},
    {0x8000ffff, 0x80000000, 0x8000000000000000, 0x8000000040000000},
    {0x80008000, 0x80007fff, 0xffffffffffffffff, 0x000000003fffffff},
    {0x8000ffff, 0x80008000, 0x7fffffffffffffff, 0x800000003fffffff},
    {0x7fffffff, 0x80000000, 0x8000000000000000, 0x7fffffffc0008000},
    {0x7fff8000, 0x80007fff, 0xffffffffffffffff, 0xffffffffc0007fff},
    {0x7fff8000, 0x80008000, 0x7fffffffffffffff, 0x7fffffffc0007fff},
    {0xffff0000, 0xffff0000, 0x8000000000000000, 0x8000000000000001},
    {0xffff7fff, 0xffff7fff, 0xffffffffffffffff, 0x0000000000000000},
    {0xffff8000, 0xffff8000, 0x7fffffffffffffff, 0x8000000000000000},
    {0xffff0000, 0x80000001, 0x8000000000000000, 0x8000000000008000},
    {0x80000000, 0xffff0001, 0xffffffffffffffff, 0x0000000000007fff},
    {0x80000000, 0xffff0001, 0x7fffffffffffffff, 0x8000000000007fff},
    {0x00000000, 0xffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x00007fff, 0xffff8000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffff8000, 0x0000ffff, 0x0000000000000000, 0x0000000000000000},
    {0xffff0000, 0x0000ffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x00007fff, 0x00008000, 0x0000000000000000, 0x0000000000000000},
    {0x00008000, 0x00008000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fff0000, 0x7fff0000, 0x8000000000000000, 0x800000003fff0001},
    {0x7fff0000, 0x7fff0000, 0x7fffffffffffffff, 0x800000003fff0000},
    {0x80000000, 0x80000000, 0xffffffffffffffff, 0x000000003fffffff},
    {0x7fff0000, 0x80000000, 0xffffffffffffffff, 0xffffffffc0007fff},
};

/* smalda */
struct ternary_ul_ul_64_calculation samples_smalda[] = {
    {0x7fff0001, 0x7fff0000, 0x8000000000000000, 0x800000003fff0001},
    {0x00017fff, 0x00007fff, 0x8000000000000000, 0x800000003fff0001},
    {0x00017fff, 0x00007fff, 0xffffffffffffffff, 0x000000003fff0000},
    {0x00017fff, 0x00007fff, 0x7fffffffffffffff, 0x800000003fff0000},
    {0xffff8000, 0x00008000, 0x8000000000000000, 0x8000000040000000},
    {0x80008000, 0x7fff8000, 0xffffffffffffffff, 0x0000000000007fff},
    {0xffff8000, 0x80008000, 0x7fffffffffffffff, 0x8000000040007fff},
    {0xffff7fff, 0x00008000, 0x8000000000000000, 0x7fffffffc0008000},
    {0x80007fff, 0x7fff8000, 0xffffffffffffffff, 0xffffffff8000ffff},
    {0x80007fff, 0x80008000, 0x7fffffffffffffff, 0x8000000000007fff},
    {0x0000ffff, 0x0000ffff, 0x8000000000000000, 0x8000000000000001},
    {0x7fffffff, 0x7fffffff, 0xffffffffffffffff, 0x000000003fff0001},
    {0x8000ffff, 0x8000ffff, 0x7fffffffffffffff, 0x8000000040000000},
    {0x0000ffff, 0x00018000, 0x8000000000000000, 0x8000000000008000},
    {0x00008000, 0x0001ffff, 0xffffffffffffffff, 0x0000000000007fff},
    {0x00008000, 0x0001ffff, 0x7fffffffffffffff, 0x8000000000007fff},
    {0x00000000, 0xffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x7fff0000, 0x8000ffff, 0xffffffffffffffff, 0xffffffffc0007fff},
    {0x8000ffff, 0xffff0000, 0x0000000000000000, 0x0000000000008000},
    {0x0000ffff, 0xffff0000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fff0000, 0x80000000, 0x0000000000000000, 0xffffffffc0008000},
    {0x80000000, 0x80000000, 0xffffffffffffffff, 0x000000003fffffff},
    {0x00007fff, 0x00007fff, 0x8000000000000000, 0x800000003fff0001},
    {0x00007fff, 0x00007fff, 0x7fffffffffffffff, 0x800000003fff0000},
    {0x00008000, 0x00008000, 0xffffffffffffffff, 0x000000003fffffff},
    {0x00007fff, 0x00008000, 0xffffffffffffffff, 0xffffffffc0007fff},
};

/* smalxda */
struct ternary_ul_ul_64_calculation samples_smalxda[] = {
    {0x00017fff, 0x7fff0000, 0x8000000000000000, 0x800000003fff0001},
    {0x00017fff, 0x7fff0000, 0xffffffffffffffff, 0x000000003fff0000},
    {0x00017fff, 0x7fff0000, 0x7fffffffffffffff, 0x800000003fff0000},
    {0xffff8000, 0x80000000, 0x8000000000000000, 0x8000000040000000},
    {0x80008000, 0x80007fff, 0xffffffffffffffff, 0x0000000000007fff},
    {0xffff8000, 0x80008000, 0x7fffffffffffffff, 0x8000000040007fff},
    {0xffff7fff, 0x80000000, 0x8000000000000000, 0x7fffffffc0008000},
    {0x80007fff, 0x80007fff, 0xffffffffffffffff, 0xffffffff8000ffff},
    {0x80007fff, 0x80008000, 0x7fffffffffffffff, 0x8000000000007fff},
    {0x0000ffff, 0xffff0000, 0x8000000000000000, 0x8000000000000001},
    {0x7fffffff, 0xffff7fff, 0xffffffffffffffff, 0x000000003fff0001},
    {0x8000ffff, 0xffff8000, 0x7fffffffffffffff, 0x8000000040000000},
    {0x0000ffff, 0x80000001, 0x8000000000000000, 0x8000000000008000},
    {0x00008000, 0xffff0001, 0xffffffffffffffff, 0x0000000000007fff},
    {0x00008000, 0xffff0001, 0x7fffffffffffffff, 0x8000000000007fff},
    {0x00000000, 0xffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x7fff0000, 0xffff8000, 0xffffffffffffffff, 0xffffffffc0007fff},
    {0x8000ffff, 0x0000ffff, 0x0000000000000000, 0x0000000000008000},
    {0x0000ffff, 0x0000ffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fff0000, 0x00008000, 0x0000000000000000, 0xffffffffc0008000},
    {0x80000000, 0x00008000, 0xffffffffffffffff, 0x000000003fffffff},
    {0x00007fff, 0x7fff0000, 0x8000000000000000, 0x800000003fff0001},
    {0x00007fff, 0x7fff0000, 0x7fffffffffffffff, 0x800000003fff0000},
    {0x00008000, 0x80000000, 0xffffffffffffffff, 0x000000003fffffff},
    {0x00007fff, 0x80000000, 0xffffffffffffffff, 0xffffffffc0007fff},

};

/* smalds */
struct ternary_ul_ul_64_calculation samples_smalds[] = {
    {0x7fff7fff, 0x7fff7ffe, 0x8000000000000000, 0x8000000000007fff},
    {0x7fff7fff, 0x7fff7ffe, 0xffffffffffffffff, 0x0000000000007ffe},
    {0x7fff7fff, 0x7fff7ffe, 0x7fffffffffffffff, 0x8000000000007ffe},
    {0x80008000, 0x80008001, 0x8000000000000000, 0x8000000000008000},
    {0x80008000, 0x80008001, 0xffffffffffffffff, 0x0000000000007fff},
    {0x80008000, 0x80008001, 0x7fffffffffffffff, 0x8000000000007fff},
    {0x7fff7fff, 0x80008001, 0x8000000000000000, 0x7fffffffffff8001},
    {0x7fff7fff, 0x80008001, 0xffffffffffffffff, 0xffffffffffff8000},
    {0x7fff7fff, 0x80008001, 0x7fffffffffffffff, 0x7fffffffffff8000},
    {0xffffffff, 0xfffffffe, 0x8000000000000000, 0x7fffffffffffffff},
    {0xffffffff, 0xfffffffe, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0xffffffff, 0xfffffffe, 0x7fffffffffffffff, 0x7ffffffffffffffe},
};

/* smaldrs */
struct ternary_ul_ul_64_calculation samples_smaldrs[] = {
    {0x7fff7fff, 0x7ffe7fff, 0x8000000000000000, 0x8000000000007fff},
    {0x7fff7fff, 0x7ffe7fff, 0xffffffffffffffff, 0x0000000000007ffe},
    {0x7fff7fff, 0x7ffe7fff, 0x7fffffffffffffff, 0x8000000000007ffe},
    {0x80008000, 0x80018000, 0x8000000000000000, 0x8000000000008000},
    {0x80008000, 0x80018000, 0xffffffffffffffff, 0x0000000000007fff},
    {0x80008000, 0x80018000, 0x7fffffffffffffff, 0x8000000000007fff},
    {0x7fff7fff, 0x80018000, 0x8000000000000000, 0x7fffffffffff8001},
    {0x7fff7fff, 0x80018000, 0xffffffffffffffff, 0xffffffffffff8000},
    {0x7fff7fff, 0x80018000, 0x7fffffffffffffff, 0x7fffffffffff8000},
    {0xffffffff, 0xfffeffff, 0x8000000000000000, 0x7fffffffffffffff},
    {0xffffffff, 0xfffeffff, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0xffffffff, 0xfffeffff, 0x7fffffffffffffff, 0x7ffffffffffffffe},
};

/* smalxds */
struct ternary_ul_ul_64_calculation samples_smalxds[] = {
    {0x7fff7fff, 0x7ffe7fff, 0x8000000000000000, 0x8000000000007fff},
    {0x7fff7fff, 0x7ffe7fff, 0xffffffffffffffff, 0x0000000000007ffe},
    {0x7fff7fff, 0x7ffe7fff, 0x7fffffffffffffff, 0x8000000000007ffe},
    {0x80008000, 0x80018000, 0x8000000000000000, 0x8000000000008000},
    {0x80008000, 0x80018000, 0xffffffffffffffff, 0x0000000000007fff},
    {0x80008000, 0x80018000, 0x7fffffffffffffff, 0x8000000000007fff},
    {0x7fff7fff, 0x80018000, 0x8000000000000000, 0x7fffffffffff8001},
    {0x7fff7fff, 0x80018000, 0xffffffffffffffff, 0xffffffffffff8000},
    {0x7fff7fff, 0x80018000, 0x7fffffffffffffff, 0x7fffffffffff8000},
    {0xffffffff, 0xfffeffff, 0x8000000000000000, 0x7fffffffffffffff},
    {0xffffffff, 0xfffeffff, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0xffffffff, 0xfffeffff, 0x7fffffffffffffff, 0x7ffffffffffffffe},

};

/* smslda */
struct ternary_ul_ul_64_calculation samples_smslda[] = {
    {0x7fff7fff, 0x7fff7fff, 0x8000000000000000, 0x7fffffff8001fffe},
    {0x7fff7fff, 0x7fff7fff, 0xffffffffffffffff, 0xffffffff8001fffd},
    {0x7fff7fff, 0x7fff7fff, 0x7fffffffffffffff, 0x7fffffff8001fffd},
    {0x80008000, 0x80008000, 0x8000000000000000, 0x7fffffff80000000},
    {0x80008000, 0x80008000, 0xffffffffffffffff, 0xffffffff7fffffff},
    {0x80008000, 0x80008000, 0x7fffffffffffffff, 0x7fffffff7fffffff},
    {0x7fff7fff, 0x80008000, 0x8000000000000000, 0x800000007fff0000},
    {0x7fff7fff, 0x80008000, 0xffffffffffffffff, 0x000000007ffeffff},
    {0x7fff7fff, 0x80008000, 0x7fffffffffffffff, 0x800000007ffeffff},
    {0xffffffff, 0xffffffff, 0x8000000000000000, 0x7ffffffffffffffe},
    {0xffffffff, 0xffffffff, 0xffffffffffffffff, 0xfffffffffffffffd},
    {0xffffffff, 0xffffffff, 0x7fffffffffffffff, 0x7ffffffffffffffd},
    {0xffffffff, 0x80008000, 0x8000000000000000, 0x7fffffffffff0000},
    {0x80008000, 0xffffffff, 0xffffffffffffffff, 0xfffffffffffeffff},
    {0x80008000, 0xffffffff, 0x7fffffffffffffff, 0x7ffffffffffeffff},
    {0x00000000, 0xffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x11112222, 0x12345678, 0x8000000000000000, 0x7FFFFFFFF341EA9C},
    {0x12345678, 0x11112222, 0x8000000000000000, 0x7FFFFFFFF341EA9C},
};

/* smslxda */
struct ternary_ul_ul_64_calculation samples_smslxda[] = {
    {0x7fff7fff, 0x7fff7fff, 0x8000000000000000, 0x7fffffff8001fffe},
    {0x7fff7fff, 0x7fff7fff, 0xffffffffffffffff, 0xffffffff8001fffd},
    {0x7fff7fff, 0x7fff7fff, 0x7fffffffffffffff, 0x7fffffff8001fffd},
    {0x80008000, 0x80008000, 0x8000000000000000, 0x7fffffff80000000},
    {0x80008000, 0x80008000, 0xffffffffffffffff, 0xffffffff7fffffff},
    {0x80008000, 0x80008000, 0x7fffffffffffffff, 0x7fffffff7fffffff},
    {0x7fff7fff, 0x80008000, 0x8000000000000000, 0x800000007fff0000},
    {0x7fff7fff, 0x80008000, 0xffffffffffffffff, 0x000000007ffeffff},
    {0x7fff7fff, 0x80008000, 0x7fffffffffffffff, 0x800000007ffeffff},
    {0xffffffff, 0xffffffff, 0x8000000000000000, 0x7ffffffffffffffe},
    {0xffffffff, 0xffffffff, 0xffffffffffffffff, 0xfffffffffffffffd},
    {0xffffffff, 0xffffffff, 0x7fffffffffffffff, 0x7ffffffffffffffd},
    {0xffffffff, 0x80008000, 0x8000000000000000, 0x7fffffffffff0000},
    {0x80008000, 0xffffffff, 0xffffffffffffffff, 0xfffffffffffeffff},
    {0x80008000, 0xffffffff, 0x7fffffffffffffff, 0x7ffffffffffeffff},
    {0x00000000, 0xffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x11112222, 0x56781234, 0x8000000000000000, 0x7FFFFFFFF341EA9C},
    {0x12345678, 0x22221111, 0x8000000000000000, 0x7FFFFFFFF341EA9C},
};

/* smul8 */
struct binary64_calculation samples_smul8[] = {
    {0x00000001, 0x00010001, 0x0000000000000001},
    {0x04030201, 0x7f7f7f7f, 0x01fc017d00fe007f},
    {0xf1f2f3f4, 0xffffffff, 0x000f000e000d000c},
    {0x80808080, 0xf1f2f3f4, 0x0780070006800600},
    {0x80808080, 0x80808080, 0x4000400040004000},
    {0x80808080, 0x7f7f7f7f, 0xc080c080c080c080},
    {0xf1f2f3f4, 0x7f7f7f7f, 0xf88ff90ef98dfa0c},
};

/* smulx8 */
struct binary64_calculation samples_smulx8[] = {
    {0x00000001, 0x01000100, 0x0000000000000001},
    {0x04030201, 0x7f7f7f7f, 0x01fc017d00fe007f},
    {0xf1f2f3f4, 0xffffffff, 0x000f000e000d000c},
    {0x80808080, 0xf2f1f4f3, 0x0780070006800600},
    {0x80808080, 0x80808080, 0x4000400040004000},
    {0x80808080, 0x7f7f7f7f, 0xc080c080c080c080},
    {0xf1f2f3f4, 0x7f7f7f7f, 0xf88ff90ef98dfa0c},
};

/* umul8 */
struct binary64_calculation samples_umul8[] = {
    {0x00000001, 0x00010001, 0x0000000000000001},
    {0x04030201, 0x7f7f7f7f, 0x01fc017d00fe007f},
    {0xf1f2f3f4, 0xffffffff, 0xf00ff10ef20df30c},
    {0x80808080, 0xf1f2f3f4, 0x7880790079807a00},
    {0x80808080, 0x80808080, 0x4000400040004000},
    {0xffffffff, 0x7f7f7f7f, 0x7e817e817e817e81},
    {0xf1f2f3f4, 0x7f7f7f7f, 0x778f780e788d790c},
    {0xffffffff, 0xffffffff, 0xfe01fe01fe01fe01},
};

/* umulx8 */
struct binary64_calculation samples_umulx8[] = {
    {0x00000001, 0x01000100, 0x0000000000000001},
    {0x04030201, 0x7f7f7f7f, 0x01fc017d00fe007f},
    {0xf1f2f3f4, 0xffffffff, 0xf00ff10ef20df30c},
    {0x80808080, 0xf2f1f4f3, 0x7880790079807a00},
    {0x80808080, 0x80808080, 0x4000400040004000},
    {0xffffffff, 0x7f7f7f7f, 0x7e817e817e817e81},
    {0xf1f2f3f4, 0x7f7f7f7f, 0x778f780e788d790c},
    {0xffffffff, 0xffffffff, 0xfe01fe01fe01fe01},
};
/* khm8 */
struct binary_calculation samples_khm8[] = {
    {0xf5f6f7f8, 0x80808080, 0x0b0a0908},
    {0xf5f6f7f8, 0x7f7f7f7f, 0xf5f6f7f8},
    {0x80808080, 0x7f7f7f7f, 0x81818181},
    {0x80808080, 0x80808080, 0x7f7f7f7f},
    {0x80808080, 0x05060708, 0xfbfaf9f8},
    {0x7f7f7f7f, 0x05060708, 0x04050607},
};

/* khmx8 */
struct binary_calculation samples_khmx8[] = {
    {0xf5f6f7f8, 0x80808080, 0x0b0a0908},
    {0xf5f6f7f8, 0x7f7f7f7f, 0xf5f6f7f8},
    {0x80808080, 0x7f7f7f7f, 0x81818181},
    {0x80808080, 0x80808080, 0x7f7f7f7f},
    {0x80808080, 0x06050807, 0xfbfaf9f8},
    {0x7f7f7f7f, 0x06050807, 0x04050607},
};

/* smul16 */
struct binary64_calculation samples_smul16[] = {
    {0x00000001, 0x00010001, 0x0000000000000001},
    {0x00000001, 0x7fff7fff, 0x0000000000007fff},
    {0x00000001, 0xffffffff, 0x00000000ffffffff},
    {0xffffffff, 0x00010001, 0xffffffffffffffff},
    {0xffffffff, 0xffffffff, 0x0000000100000001},
    {0xffffffff, 0x7fff7fff, 0xffff8001ffff8001},
    {0x80000000, 0x80008000, 0x4000000000000000},
    {0x80000000, 0x7fff7fff, 0xc000800000000000},
    {0x80000000, 0xffffffff, 0x0000800000000000},
    {0x7fffffff, 0x00010001, 0x00007fffffffffff},
    {0x7fffffff, 0xffffffff, 0xffff800100000001},
    {0x7fffffff, 0x7fff7fff, 0x3fff0001ffff8001},
    {0x7fffffff, 0x80008000, 0xc000800000008000},
    {0x00000000, 0x00000000, 0x0000000000000000},
    {0x00000000, 0x7fff7fff, 0x0000000000000000},
    {0x8000ffff, 0xffff7fff, 0x00008000ffff8001},
    {0x7fff0000, 0x8000ffff, 0xc000800000000000},
};

/* umul16 */
struct binary64_calculation samples_umul16[] = {
    {0x00000001, 0x00010001, 0x0000000000000001},
    {0x00000001, 0x7fff7fff, 0x0000000000007fff},
    {0x00000001, 0xffffffff, 0x000000000000ffff},
    {0xffffffff, 0x00010001, 0x0000ffff0000ffff},
    {0xffffffff, 0xffffffff, 0xfffe0001fffe0001},
    {0xffffffff, 0x7fff7fff, 0x7ffe80017ffe8001},
    {0x80000000, 0x80008000, 0x4000000000000000},
    {0x80000000, 0x7fff7fff, 0x3fff800000000000},
    {0x80000000, 0xffffffff, 0x7fff800000000000},
    {0x7fffffff, 0x00010001, 0x00007fff0000ffff},
    {0x7fffffff, 0xffffffff, 0x7ffe8001fffe0001},
    {0x7fffffff, 0x7fff7fff, 0x3fff00017ffe8001},
    {0x7fffffff, 0x80008000, 0x3fff80007fff8000},
    {0x00000000, 0x00000000, 0x0000000000000000},
    {0x00000000, 0x7fff7fff, 0x0000000000000000},
    {0x8000ffff, 0xffff7fff, 0x7fff80007ffe8001},
    {0x7fff0000, 0x8000ffff, 0x3fff800000000000},
    {0x80007fff, 0xffffffff, 0x7fff80007ffe8001},
};

/* smulx16 */
struct binary64_calculation samples_smulx16[] = {
    {0x00000001, 0x00010001, 0x0000000000000001},
    {0x00000001, 0x7fff7fff, 0x0000000000007fff},
    {0x00000001, 0xffffffff, 0x00000000ffffffff},
    {0xffffffff, 0x00010001, 0xffffffffffffffff},
    {0xffffffff, 0xffffffff, 0x0000000100000001},
    {0xffffffff, 0x7fff7fff, 0xffff8001ffff8001},
    {0x80000000, 0x80008000, 0x4000000000000000},
    {0x80000000, 0x7fff7fff, 0xc000800000000000},
    {0x80000000, 0xffffffff, 0x0000800000000000},
    {0x7fffffff, 0x00010001, 0x00007fffffffffff},
    {0x7fffffff, 0xffffffff, 0xffff800100000001},
    {0x7fffffff, 0x7fff7fff, 0x3fff0001ffff8001},
    {0x7fffffff, 0x80008000, 0xc000800000008000},
    {0x00000000, 0x00000000, 0x0000000000000000},
    {0x00000000, 0x7fff7fff, 0x0000000000000000},
    {0x8000ffff, 0xffff7fff, 0xc000800000000001},
    {0x7fff0000, 0xffff8000, 0xc000800000000000},
    {0x80007fff, 0xffffffff, 0x00008000ffff8001},
};

/* umulx16 */
struct binary64_calculation samples_umulx16[] = {
    {0x00000001, 0x00010001, 0x0000000000000001},
    {0x00000001, 0x7fff7fff, 0x0000000000007fff},
    {0x00000001, 0xffffffff, 0x000000000000ffff},
    {0xffffffff, 0x00010001, 0x0000ffff0000ffff},
    {0xffffffff, 0xffffffff, 0xfffe0001fffe0001},
    {0xffffffff, 0x7fff7fff, 0x7ffe80017ffe8001},
    {0x80000000, 0x80008000, 0x4000000000000000},
    {0x80000000, 0x7fff7fff, 0x3fff800000000000},
    {0x80000000, 0xffffffff, 0x7fff800000000000},
    {0x7fffffff, 0x00010001, 0x00007fff0000ffff},
    {0x7fffffff, 0xffffffff, 0x7ffe8001fffe0001},
    {0x7fffffff, 0x7fff7fff, 0x3fff00017ffe8001},
    {0x7fffffff, 0x80008000, 0x3fff80007fff8000},
    {0x00000000, 0x00000000, 0x0000000000000000},
    {0x00000000, 0x7fff7fff, 0x0000000000000000},
    {0x8000ffff, 0x7fffffff, 0x7fff80007ffe8001},
    {0x7fff0000, 0xffff8000, 0x3fff800000000000},
    {0x80007fff, 0xffffffff, 0x7fff80007ffe8001},
};

/* khm16 */
struct binary_calculation samples_khm16[] = {
    {0x7fff8000, 0x7fff8000, 0x7ffe7fff},
    {0x00030004, 0xffffffff, 0xffffffff},
    {0x00030004, 0x7fff7fff, 0x00020003},
    {0x00000000, 0x7fff7fff, 0x00000000},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0xffffffff, 0x7fff7fff, 0xffffffff},
    {0xfff3fff4, 0x7fff7fff, 0xfff3fff4},
};

/* khmx16 */
struct binary_calculation samples_khmx16[] = {
    {0x7fff8000, 0x80007fff, 0x7ffe7fff},
    {0x00030004, 0xffffffff, 0xffffffff},
    {0x00030004, 0x7fff7fff, 0x00020003},
    {0x00000000, 0x7fff7fff, 0x00000000},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0xffffffff, 0x7fff7fff, 0xffffffff},
    {0xfff3fff4, 0x7fff7fff, 0xfff3fff4},
};

/* kmda */
struct binary_calculation samples_kmda[] = {
    {0x00010001, 0x00000001, 0x00000001},
    {0x00010001, 0x00008000, 0xffff8000},
    {0x00010001, 0x7fff7fff, 0x0000fffe},
    {0x00010001, 0x0000ffff, 0xffffffff},
    {0x00010002, 0x7fff8000, 0xffff7fff},
    {0x00017fff, 0x8000ffff, 0xffff0001},
    {0x0001ffff, 0x0000ffff, 0x00000001},
    {0x0001ffff, 0x7fff8000, 0x0000ffff},
    {0x00018000, 0x80008000, 0x3fff8000},
    {0x00010000, 0x00000000, 0x00000000},
    {0x00010000, 0x7fff7fff, 0x00007fff},
    {0x00010000, 0x80008000, 0xffff8000},
    {0x80008000, 0x80008000, 0x7fffffff},
    {0x4000ffff, 0x00014000, 0x00000000},
    {0x80007fff, 0x7fffffff, 0xc0000001},
    {0x7fffffff, 0x8000ffff, 0xc0008001},
};

/* kmxda */
struct binary_calculation samples_kmxda[] = {
    {0x00010001, 0x00010000, 0x00000001},
    {0x00010001, 0x80000000, 0xffff8000},
    {0x00010001, 0x7fff7fff, 0x0000fffe},
    {0x00010001, 0xffff0000, 0xffffffff},
    {0x00010002, 0x80007fff, 0xffff7fff},
    {0x00017fff, 0xffff8000, 0xffff0001},
    {0x0001ffff, 0xffff0000, 0x00000001},
    {0x0001ffff, 0x80007fff, 0x0000ffff},
    {0x00018000, 0x80008000, 0x3fff8000},
    {0x00010000, 0x00000000, 0x00000000},
    {0x00010000, 0x7fff7fff, 0x00007fff},
    {0x00010000, 0x80008000, 0xffff8000},
    {0x80008000, 0x80008000, 0x7fffffff},
    {0x4000ffff, 0x00014000, 0x0fffffff},
    {0x4000ffff, 0x40000001, 0x00000000},
    {0x80007fff, 0x7fffffff, 0x3fff8001},
    {0x7fffffff, 0x8000ffff, 0x00000001},
};

/* smdrs */
struct binary_calculation samples_smdrs[] = {
    {0x00010001, 0x00000001, 0x00000001},
    {0x00010001, 0x7fff7fff, 0x00000000},
    {0x00010010, 0x80007fff, 0x00087ff0},
    {0x00010001, 0x0000ffff, 0xffffffff},
    {0x00010002, 0x7fff8000, 0xfffe8001},
    {0x00017fff, 0x8000ffff, 0x00000001},
    {0x0001ffff, 0x0000ffff, 0x00000001},
    {0x0001ffff, 0x7fff8000, 0x00000001},
    {0x00018000, 0x80008000, 0x40008000},
    {0x00010000, 0x00000000, 0x00000000},
    {0x00010000, 0x7fff7fff, 0xffff8001},
    {0x00010000, 0x80008000, 0x00008000},
    {0x80008000, 0x80008000, 0x00000000},
    {0x7fffffff, 0x00017fff, 0xffff0002},
    {0x7fff0001, 0xffff7fff, 0x0000fffe},
};

/* smds */
struct binary_calculation samples_smds[] = {
    {0x00010001, 0x00010000, 0x00000001},
    {0x00010001, 0x7fff7fff, 0x00000000},
    {0x00100001, 0x7fff8000, 0x00087ff0},
    {0x00010001, 0xffff0000, 0xffffffff},
    {0x00020001, 0x80007fff, 0xfffe8001},
    {0x7fff0001, 0xffff8000, 0x00000001},
    {0xffff0001, 0xffff0000, 0x00000001},
    {0xffff0001, 0x80007fff, 0x00000001},
    {0x80000001, 0x80008000, 0x40008000},
    {0x00000001, 0x00000000, 0x00000000},
    {0x00000001, 0x7fff7fff, 0xffff8001},
    {0x00000001, 0x80008000, 0x00008000},
    {0x80008000, 0x80008000, 0x00000000},
    {0x7fffffff, 0x00017fff, 0x0000fffe},
    {0x7fff0001, 0xffff7fff, 0xffff0002},
};

/* smxds */
struct binary_calculation samples_smxds[] = {
    {0x00010000, 0x00010001, 0x00000001},
    {0x7fff7fff, 0x00010001, 0x00000000},
    {0x7fff8000, 0x00010010, 0x00087ff0},
    {0xffff0000, 0x00010001, 0xffffffff},
    {0x80007fff, 0x00010002, 0xfffe8001},
    {0xffff8000, 0x00017fff, 0x00000001},
    {0xffff0000, 0x0001ffff, 0x00000001},
    {0x80007fff, 0x0001ffff, 0x00000001},
    {0x80008000, 0x00018000, 0x40008000},
    {0x00000000, 0x00010000, 0x00000000},
    {0x7fff7fff, 0x00010000, 0xffff8001},
    {0x80008000, 0x00010000, 0x00008000},
    {0x80008000, 0x80008000, 0x00000000},
    {0x7fff0001, 0x7fffffff, 0xffff0002},
    {0x7fffffff, 0x7fff0001, 0x0000fffe},
};

/* kmada */
struct ternary_calculation samples_kmada[] = {
    {0x00010001, 0x00010001, 0x00000001, 0x00000003},
    {0x80007fff, 0x80007fff, 0x80000000, 0xffff0001},
    {0x80007fff, 0x80007fff, 0xffffffff, 0x7fff0000},
    {0x80007fff, 0x80007fff, 0x7fffffff, 0x7fffffff},
    {0x7fff7fff, 0x80008000, 0x80000000, 0x80000000},
    {0x7fff7fff, 0x80008000, 0xffffffff, 0x8000ffff},
    {0x7fff7fff, 0x80008000, 0x7fffffff, 0x0000ffff},
    {0xffffffff, 0xffffffff, 0x80000000, 0x80000002},
    {0xffffffff, 0xffffffff, 0xffffffff, 0x00000001},
    {0xffffffff, 0xffffffff, 0x7fffffff, 0x7fffffff},
    {0xffffffff, 0x80008000, 0x80000000, 0x80010000},
    {0xffffffff, 0x80008000, 0xffffffff, 0x0000ffff},
    {0xffffffff, 0x80008000, 0x7fffffff, 0x7fffffff},
    {0x8000ffff, 0x8000ffff, 0x80000000, 0xc0000001},
    {0x8000ffff, 0x8000ffff, 0xffffffff, 0x40000000},
    {0x8000ffff, 0x8000ffff, 0x7fffffff, 0x7fffffff},
    {0x00010000, 0xffffffff, 0x00000000, 0xffffffff},
    {0x0001ffff, 0xffff0000, 0x00000000, 0xffffffff},
    {0x00000001, 0xffffffff, 0x00000000, 0xffffffff},
    {0x0000ffff, 0xffff0001, 0x00000000, 0xffffffff},
    {0x00000000, 0x00000000, 0x00000000, 0x00000000},
    {0x7fff0000, 0x00017fff, 0x7fffffff, 0x7fffffff},
    {0x7fff0001, 0x0001ffff, 0x7fffffff, 0x7fffffff},
    {0x7fffffff, 0xffffffff, 0x80000000, 0x80000000},
};

/* kmaxda */
struct ternary_calculation samples_kmaxda[] = {
    {0x00010001, 0x00010001, 0x00000001, 0x00000003},
    {0x80007fff, 0x7fff8000, 0x80000000, 0xffff0001},
    {0x80007fff, 0x7fff8000, 0xffffffff, 0x7fff0000},
    {0x80007fff, 0x7fff8000, 0x7fffffff, 0x7fffffff},
    {0x7fff7fff, 0x80008000, 0x80000000, 0x80000000},
    {0x7fff7fff, 0x80008000, 0xffffffff, 0x8000ffff},
    {0x7fff7fff, 0x80008000, 0x7fffffff, 0x0000ffff},
    {0xffffffff, 0xffffffff, 0x80000000, 0x80000002},
    {0xffffffff, 0xffffffff, 0xffffffff, 0x00000001},
    {0xffffffff, 0xffffffff, 0x7fffffff, 0x7fffffff},
    {0xffffffff, 0x80008000, 0x80000000, 0x80010000},
    {0xffffffff, 0x80008000, 0xffffffff, 0x0000ffff},
    {0xffffffff, 0x80008000, 0x7fffffff, 0x7fffffff},
    {0x8000ffff, 0xffff8000, 0x80000000, 0xc0000001},
    {0x8000ffff, 0xffff8000, 0xffffffff, 0x40000000},
    {0x8000ffff, 0xffff8000, 0x7fffffff, 0x7fffffff},
    {0x00010000, 0xffffffff, 0x00000000, 0xffffffff},
    {0x0001ffff, 0x0000ffff, 0x00000000, 0xffffffff},
    {0x00000001, 0xffffffff, 0x00000000, 0xffffffff},
    {0x0000ffff, 0x0001ffff, 0x00000000, 0xffffffff},
    {0x00000000, 0x00000000, 0x00000000, 0x00000000},
    {0x7fff0001, 0xffff0001, 0x7fffffff, 0x7fffffff},
    {0xffff0001, 0x00017fff, 0x80000000, 0x80000000},
    {0x7fff0001, 0xffff0001, 0x7fff0000, 0x7fff7ffe},
};

/* kmadrs */
struct ternary_calculation samples_kmadrs[] = {
    {0x00010001, 0x00010001, 0x00000001, 0x00000001},
    {0x80007fff, 0x80007fff, 0x80000000, 0x80000000},
    {0x80007fff, 0x80007fff, 0xffffffff, 0xffff0000},
    {0x80007fff, 0x80007fff, 0x7fffffff, 0x7fff0000},
    {0x7fff7fff, 0x80008000, 0x80000000, 0x80000000},
    {0x7fff7fff, 0x80008000, 0xffffffff, 0xffffffff},
    {0x7fff7fff, 0x80008000, 0x7fffffff, 0x7fffffff},
    {0xffffffff, 0xffffffff, 0x80000000, 0x80000000},
    {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff},
    {0xffffffff, 0xffffffff, 0x7fffffff, 0x7fffffff},
    {0xffffffff, 0x80008000, 0x80000000, 0x80000000},
    {0xffffffff, 0x80008000, 0xffffffff, 0xffffffff},
    {0xffffffff, 0x80008000, 0x7fffffff, 0x7fffffff},
    {0x8000ffff, 0x8000ffff, 0x80000000, 0x80000000},
    {0x8000ffff, 0x8000ffff, 0xffffffff, 0xc0000000},
    {0x8000ffff, 0x8000ffff, 0x7fffffff, 0x40000000},
    {0x00010000, 0xffffffff, 0x00000000, 0x00000001},
    {0x0001ffff, 0xffff0000, 0x00000000, 0x00000001},
    {0x00000001, 0xffffffff, 0x00000000, 0xffffffff},
    {0x0000ffff, 0xffff0001, 0x00000000, 0xffffffff},
    {0x00000000, 0x00000000, 0x00000000, 0x00000000},
    {0x7fff0001, 0xffff7fff, 0x7fffffff, 0x7fffffff},
    {0xffff7fff, 0x0001ffff, 0x80000000, 0x80000000},
    {0x7fff0000, 0xffff0000, 0x7fff0000, 0x7fff7fff},
};

/* kmads */
struct ternary_calculation samples_kmads[] = {
    {0x00010001, 0x00010001, 0x00000001, 0x00000001},
    {0x7fff8000, 0x7fff8000, 0x80000000, 0x80000000},
    {0x7fff8000, 0x7fff8000, 0xffffffff, 0xffff0000},
    {0x7fff8000, 0x7fff8000, 0x7fffffff, 0x7fff0000},
    {0x7fff7fff, 0x80008000, 0x80000000, 0x80000000},
    {0x7fff7fff, 0x80008000, 0xffffffff, 0xffffffff},
    {0x7fff7fff, 0x80008000, 0x7fffffff, 0x7fffffff},
    {0xffffffff, 0xffffffff, 0x80000000, 0x80000000},
    {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff},
    {0xffffffff, 0xffffffff, 0x7fffffff, 0x7fffffff},
    {0xffffffff, 0x80008000, 0x80000000, 0x80000000},
    {0xffffffff, 0x80008000, 0xffffffff, 0xffffffff},
    {0xffffffff, 0x80008000, 0x7fffffff, 0x7fffffff},
    {0xffff8000, 0xffff8000, 0x80000000, 0x80000000},
    {0xffff8000, 0xffff8000, 0xffffffff, 0xc0000000},
    {0xffff8000, 0xffff8000, 0x7fffffff, 0x40000000},
    {0x00000001, 0xffffffff, 0x00000000, 0x00000001},
    {0xffff0001, 0x0000ffff, 0x00000000, 0x00000001},
    {0x00010000, 0xffffffff, 0x00000000, 0xffffffff},
    {0xffff0000, 0x0001ffff, 0x00000000, 0xffffffff},
    {0x00000000, 0x00000000, 0x00000000, 0x00000000},
    {0x7fff0001, 0x00010001, 0x7fffffff, 0x7fffffff},
    {0x7fff0001, 0xffff0001, 0x80000000, 0x80000000},
    {0x7fffffff, 0xffffffff, 0xffff0000, 0xfffe8000},
};

/* kmaxds */
struct ternary_calculation samples_kmaxds[] = {
    {0x00010001, 0x00010001, 0x00000001, 0x00000001},
    {0x7fff8000, 0x80007fff, 0x80000000, 0x80000000},
    {0x7fff8000, 0x80007fff, 0xffffffff, 0xffff0000},
    {0x7fff8000, 0x80007fff, 0x7fffffff, 0x7fff0000},
    {0x80008000, 0x7fff7fff, 0x80000000, 0x80000000},
    {0x80008000, 0x7fff7fff, 0xffffffff, 0xffffffff},
    {0x80008000, 0x7fff7fff, 0x7fffffff, 0x7fffffff},
    {0xffffffff, 0xffffffff, 0x80000000, 0x80000000},
    {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff},
    {0xffffffff, 0xffffffff, 0x7fffffff, 0x7fffffff},
    {0x80008000, 0xffffffff, 0x80000000, 0x80000000},
    {0x80008000, 0xffffffff, 0xffffffff, 0xffffffff},
    {0x80008000, 0xffffffff, 0x7fffffff, 0x7fffffff},
    {0xffff8000, 0x8000ffff, 0x80000000, 0x80000000},
    {0xffff8000, 0x8000ffff, 0xffffffff, 0xc0000000},
    {0xffff8000, 0x8000ffff, 0x7fffffff, 0x40000000},
    {0xffffffff, 0x00010000, 0x00000000, 0x00000001},
    {0x0000ffff, 0x0001ffff, 0x00000000, 0x00000001},
    {0xffffffff, 0x00000001, 0x00000000, 0xffffffff},
    {0x0001ffff, 0x0000ffff, 0x00000000, 0xffffffff},
    {0x00000000, 0x00000000, 0x00000000, 0x00000000},
    {0x00010001, 0x00017fff, 0x7fffffff, 0x7fffffff},
    {0x7fffffff, 0x0001ffff, 0x80000000, 0x80000000},
    {0xffff8000, 0xffff7fff, 0x4000ffff, 0x40000000},
};

/* kmsda */
struct ternary_calculation samples_kmsda[] = {
    {0x00010001, 0x00010001, 0x00000001, 0xffffffff},
    {0x80007fff, 0x80007fff, 0x80000000, 0x80000000},
    {0x80007fff, 0x80007fff, 0xffffffff, 0x8000fffe},
    {0x80007fff, 0x80007fff, 0x7fffffff, 0x0000fffe},
    {0x7fff7fff, 0x80008000, 0x80000000, 0xffff0000},
    {0x7fff7fff, 0x80008000, 0xffffffff, 0x7ffeffff},
    {0x7fff7fff, 0x80008000, 0x7fffffff, 0x7fffffff},
    {0xffffffff, 0xffffffff, 0x80000000, 0x80000000},
    {0xffffffff, 0xffffffff, 0xffffffff, 0xfffffffd},
    {0xffffffff, 0xffffffff, 0x7fffffff, 0x7ffffffd},
    {0xffffffff, 0x80008000, 0x80000000, 0x80000000},
    {0xffffffff, 0x80008000, 0xffffffff, 0xfffeffff},
    {0xffffffff, 0x80008000, 0x7fffffff, 0x7ffeffff},
    {0x8000ffff, 0x8000ffff, 0x80000000, 0x80000000},
    {0x8000ffff, 0x8000ffff, 0xffffffff, 0xbffffffe},
    {0x8000ffff, 0x8000ffff, 0x7fffffff, 0x3ffffffe},
    {0x00010000, 0xffffffff, 0x00000000, 0x00000001},
    {0x0001ffff, 0xffff0000, 0x00000000, 0x00000001},
    {0x00000001, 0xffffffff, 0x00000000, 0x00000001},
    {0x0000ffff, 0xffff0001, 0x00000000, 0x00000001},
    {0x00000000, 0x00000000, 0x00000000, 0x00000000},
    {0xffff0001, 0x7fff0001, 0x7fffffff, 0x7fffffff},
    {0x7fffffff, 0x00010001, 0x80000000, 0x80000000},
    {0xffff7fff, 0x8000ffff, 0x7fff8000, 0x7fff7fff},
};

/* kmsxda */
struct ternary_calculation samples_kmsxda[] = {
    {0x00010001, 0x00010001, 0x00000001, 0xffffffff},
    {0x80007fff, 0x7fff8000, 0x80000000, 0x80000000},
    {0x80007fff, 0x7fff8000, 0xffffffff, 0x8000fffe},
    {0x80007fff, 0x7fff8000, 0x7fffffff, 0x0000fffe},
    {0x7fff7fff, 0x80008000, 0x80000000, 0xffff0000},
    {0x7fff7fff, 0x80008000, 0xffffffff, 0x7ffeffff},
    {0x7fff7fff, 0x80008000, 0x7fffffff, 0x7fffffff},
    {0xffffffff, 0xffffffff, 0x80000000, 0x80000000},
    {0xffffffff, 0xffffffff, 0xffffffff, 0xfffffffd},
    {0xffffffff, 0xffffffff, 0x7fffffff, 0x7ffffffd},
    {0xffffffff, 0x80008000, 0x80000000, 0x80000000},
    {0xffffffff, 0x80008000, 0xffffffff, 0xfffeffff},
    {0xffffffff, 0x80008000, 0x7fffffff, 0x7ffeffff},
    {0x8000ffff, 0xffff8000, 0x80000000, 0x80000000},
    {0x8000ffff, 0xffff8000, 0xffffffff, 0xbffffffe},
    {0x8000ffff, 0xffff8000, 0x7fffffff, 0x3ffffffe},
    {0x00010000, 0xffffffff, 0x00000000, 0x00000001},
    {0x0001ffff, 0x0000ffff, 0x00000000, 0x00000001},
    {0x00000001, 0xffffffff, 0x00000000, 0x00000001},
    {0x0000ffff, 0x0001ffff, 0x00000000, 0x00000001},
    {0x00000000, 0x00000000, 0x00000000, 0x00000000},
    {0x7fff0001, 0x0001ffff, 0x7fffffff, 0x7fffffff},
    {0x7fffffff, 0x00017fff, 0x80000000, 0x80000000},
    {0xffff7fff, 0xffff8000, 0x7fff8000, 0x7fff7fff},
};

/* smal */
struct binary64_ul_calculation samples_smal[] = {
    {0x0000000000000001, 0x00010001, 0x0000000000000002},
    {0x8000000000000000, 0x7fff7fff, 0x800000003fff0001},
    {0xffffffffffffffff, 0x7fff7fff, 0x000000003fff0000},
    {0x7fffffffffffffff, 0x7fff7fff, 0x800000003fff0000},
    {0x8000000000000000, 0x7fff8000, 0x7fffffffc0008000},
    {0xffffffffffffffff, 0x7fff8000, 0xffffffffc0007fff},
    {0x7fffffffffffffff, 0x7fff8000, 0x7fffffffc0007fff},
    {0x8000000000000000, 0xffffffff, 0x8000000000000001},
    {0xffffffffffffffff, 0xffffffff, 0x0000000000000000},
    {0x7fffffffffffffff, 0xffffffff, 0x8000000000000000},
    {0x8000000000000000, 0xffff8000, 0x8000000000008000},
    {0xffffffffffffffff, 0xffff8000, 0x0000000000007fff},
    {0x7fffffffffffffff, 0xffff8000, 0x8000000000007fff},
    {0x8000000000000000, 0xffffffff, 0x8000000000000001},
    {0xffffffffffffffff, 0xffffffff, 0x0000000000000000},
    {0x7fffffffffffffff, 0xffffffff, 0x8000000000000000},
    {0x0000000000000000, 0x0000ffff, 0x0000000000000000},
    {0x0000000000000000, 0x0001ffff, 0xffffffffffffffff},
    {0x0000000000000000, 0xffff0001, 0xffffffffffffffff},
    {0x0000000000000000, 0xffff0000, 0x0000000000000000},
    {0x0000000000000000, 0x00000000, 0x0000000000000000},
    {0x800000007fff4000, 0x7fff8000, 0x800000003fffc000},
    {0x7fffffff4000ff00, 0xff00ffff, 0x7fffffff40010000},
};

/* mulr64 */
struct binary_calculation samples_mulr64[] = {
    {0x7fffffff, 0x7fffffff, 0x00000001},
    {0x80000000, 0x80000000, 0x00000000},
    {0xffffffff, 0xffffffff, 0x00000001},
    {0x00000000, 0x00000000, 0x00000000},
    {0x7fffffff, 0x80000000, 0x80000000},
    {0x80000000, 0x7fffffff, 0x80000000},
    {0x7fffffff, 0xffffffff, 0x80000001},
    {0xffffffff, 0x7fffffff, 0x80000001},
    {0x7fffffff, 0x00000000, 0x00000000},
    {0x00000000, 0x7fffffff, 0x00000000},
    {0x80000000, 0xffffffff, 0x80000000},
    {0xffffffff, 0x80000000, 0x80000000},
    {0x00000000, 0x80000000, 0x00000000},
    {0x80000000, 0x00000000, 0x00000000},
    {0xffffffff, 0x00000000, 0x00000000},
    {0x00000000, 0xffffffff, 0x00000000},
};

/* mulsr64 */
struct binary_calculation samples_mulsr64[] = {
    {0x7fffffff, 0x7fffffff, 0x00000001},
    {0x80000000, 0x80000000, 0x00000000},
    {0xffffffff, 0xffffffff, 0x00000001},
    {0x00000000, 0x00000000, 0x00000000},
    {0x7fffffff, 0x80000000, 0x80000000},
    {0x80000000, 0x7fffffff, 0x80000000},
    {0x7fffffff, 0xffffffff, 0x80000001},
    {0xffffffff, 0x7fffffff, 0x80000001},
    {0x7fffffff, 0x00000000, 0x00000000},
    {0x00000000, 0x7fffffff, 0x00000000},
    {0x80000000, 0xffffffff, 0x80000000},
    {0xffffffff, 0x80000000, 0x80000000},
    {0x00000000, 0x80000000, 0x00000000},
    {0x80000000, 0x00000000, 0x00000000},
    {0xffffffff, 0x00000000, 0x00000000},
    {0x00000000, 0xffffffff, 0x00000000},
    {0x7fffffff, 0x7fffffff, 0x00000001},
};

/* ave */
struct binary_calculation samples_ave[] = {
    {0x7fffffff, 0x7fffffff, 0x7fffffff},
    {0x80000000, 0x80000000, 0x80000000},
    {0xffffffff, 0xffffffff, 0xffffffff},
    {0x00000000, 0x00000000, 0x00000000},
    {0x7fffffff, 0x80000000, 0x00000000},
    {0x80000000, 0x7fffffff, 0x00000000},
    {0x7fffffff, 0xffffffff, 0x3fffffff},
    {0xffffffff, 0x7fffffff, 0x3fffffff},
    {0x7fffffff, 0x00000000, 0x40000000},
    {0x00000000, 0x7fffffff, 0x40000000},
    {0x80000000, 0xffffffff, 0xc0000000},
    {0xffffffff, 0x80000000, 0xc0000000},
    {0x00000000, 0x80000000, 0xc0000000},
    {0x80000000, 0x00000000, 0xc0000000},
    {0xffffffff, 0x00000000, 0x00000000},
    {0x00000000, 0xffffffff, 0x00000000},
};

/* umar64 */
struct ternary_ul_ul_64_calculation samples_umar64[] = {
    {0x00000001, 0x00000001, 0x0000000000000001, 0x0000000000000002},
    {0x00000001, 0x00000001, 0xffffffffffffffff, 0x0000000000000000},
    {0x00000001, 0x00000001, 0x8000000000000000, 0x8000000000000001},
    {0x00000001, 0x00000001, 0x7fffffffffffffff, 0x8000000000000000},
    {0x00000001, 0xffffffff, 0xffffffffffffffff, 0x00000000fffffffe},
    {0x00000001, 0xffffffff, 0x8000000000000000, 0x80000000ffffffff},
    {0x00000001, 0xffffffff, 0x7fffffffffffffff, 0x80000000fffffffe},
    {0x80000000, 0x80000000, 0xffffffffffffffff, 0x3fffffffffffffff},
    {0x80000000, 0x80000000, 0x8000000000000000, 0xc000000000000000},
    {0x80000000, 0x80000000, 0x7fffffffffffffff, 0xbfffffffffffffff},
    {0x7fffffff, 0xffffffff, 0xffffffffffffffff, 0x7FFFFFFE80000000},
    {0x7fffffff, 0xffffffff, 0x8000000000000000, 0xFFFFFFFE80000001},
    {0x7fffffff, 0xffffffff, 0x7fffffffffffffff, 0xFFFFFFFE80000000},
    {0x00000000, 0x00000001, 0x0000000000000000, 0x0000000000000000},
    {0x00000001, 0x00000000, 0x0000000000000000, 0x0000000000000000},
};

/* smar64 */
struct ternary_ul_ul_64_calculation samples_smar64[] = {
    {0x00000001, 0x00000001, 0x0000000000000001, 0x0000000000000002},
    {0x00000001, 0x00000001, 0xffffffffffffffff, 0x0000000000000000},
    {0x00000001, 0x00000001, 0x8000000000000000, 0x8000000000000001},
    {0x00000001, 0x00000001, 0x7fffffffffffffff, 0x8000000000000000},
    {0x00000001, 0xffffffff, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0x00000001, 0xffffffff, 0x8000000000000000, 0x7fffffffffffffff},
    {0x00000001, 0xffffffff, 0x7fffffffffffffff, 0x7ffffffffffffffe},
    {0x80000000, 0x80000000, 0xffffffffffffffff, 0x3fffffffffffffff},
    {0x80000000, 0x80000000, 0x8000000000000000, 0xc000000000000000},
    {0x80000000, 0x80000000, 0x7fffffffffffffff, 0xbfffffffffffffff},
    {0x7fffffff, 0xffffffff, 0xffffffffffffffff, 0xffffffff80000000},
    {0x7fffffff, 0xffffffff, 0x8000000000000000, 0x7fffffff80000001},
    {0x7fffffff, 0xffffffff, 0x7fffffffffffffff, 0x7fffffff80000000},
    {0x00000000, 0x00000001, 0x0000000000000000, 0x0000000000000000},
    {0x00000001, 0x00000000, 0x0000000000000000, 0x0000000000000000},
};

/* maddr32 */
struct ternary_calculation samples_maddr32[] = {
    {0x00000001, 0x00000001, 0x00000000, 0x00000001},
    {0x00000002, 0x40000000, 0x00000000, 0x80000000},
    {0x00000001, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF},
    {0x00000001, 0x00000001, 0x00000001, 0x00000002},
    {0x00000002, 0x20000000, 0x40000000, 0x80000000},
    {0x00000002, 0x80000000, 0x00000000, 0x00000000},
    {0x00000002, 0x80000001, 0x00000000, 0x00000002},
    {0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000001},
    {0x80000000, 0x80000000, 0x00000000, 0x00000000},
    {0x80000000, 0x80000000, 0x80000000, 0x80000000},
    {0x00000100, 0x10000001, 0xFFFFFFFF, 0x000000FF},
    {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000},
    {0x00000000, 0x00000001, 0x00000000, 0x00000000},
    {0x00000000, 0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000},
    {0x00000000, 0x00000001, 0x00000001, 0x00000001},
    {0x00000000, 0x00000000, 0x00000001, 0x00000001},
    {0x00000000, 0xFFFFFFFF, 0x00000001, 0x00000001},
};

/* insb */
struct ternary_calculation samples_insb[] = {
    {0x00000002, 0x00000001, 0x00000000, 0x00000001},
    {0x00000002, 0x00000101, 0x00000001, 0x00000102},
    {0x22222222, 0x00010001, 0x00000002, 0x22012222},
    {0x00000001, 0x22222222, 0x00000003, 0x22000001},
    {0x00000000, 0x000000ff, 0x00000004, 0x00000000},
    {0x12345678, 0x12345678, 0x00000005, 0x12345678},
    {0x80000000, 0xffffffff, 0x00000006, 0x80000000},
    {0x00000000, 0xffffffff, 0x00000007, 0x00000000},
};

/* smmul */
struct binary_calculation samples_smmul[] = {
    {0x7fffffff, 0x7fffffff, 0x3fffffff},
    {0x80000000, 0x80000000, 0x40000000},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0x00000000, 0x00000000, 0x00000000},
    {0x7fffffff, 0x80000000, 0xc0000000},
    {0x80000000, 0x7fffffff, 0xc0000000},
    {0x7fffffff, 0xffffffff, 0xffffffff},
    {0xffffffff, 0x7fffffff, 0xffffffff},
    {0x7fffffff, 0x00000000, 0x00000000},
    {0x00000000, 0x7fffffff, 0x00000000},
    {0x80000000, 0xffffffff, 0x00000000},
    {0xffffffff, 0x80000000, 0x00000000},
    {0x00000000, 0x80000000, 0x00000000},
    {0x80000000, 0x00000000, 0x00000000},
    {0xffffffff, 0x00000000, 0x00000000},
    {0x00000000, 0xffffffff, 0x00000000},
};

/* smmul.u */
struct binary_calculation samples_smmul_u[] = {
    {0x7fffffff, 0x7fffffff, 0x3fffffff},
    {0x80000000, 0x80000000, 0x40000000},
    {0xffffffff, 0xffffffff, 0x00000000},
    {0x00000000, 0x00000000, 0x00000000},
    {0x7fffffff, 0x80000000, 0xc0000001},
    {0x80000000, 0x7fffffff, 0xc0000001},
    {0x7fffffff, 0xffffffff, 0x00000000},
    {0xffffffff, 0x7fffffff, 0x00000000},
    {0x7fffffff, 0x00000000, 0x00000000},
    {0x00000000, 0x7fffffff, 0x00000000},
    {0x80000000, 0xffffffff, 0x00000001},
    {0xffffffff, 0x80000000, 0x00000001},
    {0x00000000, 0x80000000, 0x00000000},
    {0x80000000, 0x00000000, 0x00000000},
    {0xffffffff, 0x00000000, 0x00000000},
    {0x00000000, 0xffffffff, 0x00000000},
    {0x00000001, 0x7fffffff, 0x00000000},
    {0x00000002, 0x7fffffff, 0x00000001},
};

/* smbb16 */
struct binary_calculation samples_smbb16[] = {
    {0x00000001, 0x00000001, 0x00000001},
    {0x00000001, 0x7fff7fff, 0x00007fff},
    {0x00000001, 0xffffffff, 0xffffffff},
    {0xffffffff, 0xffffffff, 0x00000001},
    {0x00008000, 0x80008000, 0x40000000},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0x7fffffff, 0x00000000},
    {0x80000000, 0x00008000, 0x00000000},
    {0xffff7fff, 0xffff7fff, 0x3fff0001},
    {0xffff7fff, 0x7fffffff, 0xffff8001},
    {0xffff8000, 0xffff8000, 0x40000000},
    {0xffff8000, 0x8000ffff, 0x00008000},
};

/* smtt16 */
struct binary_calculation samples_smtt16[] = {
    {0x00010000, 0x00010000, 0x00000001},
    {0x00010000, 0x7fff7fff, 0x00007fff},
    {0x00010000, 0xffffffff, 0xffffffff},
    {0xffffffff, 0xffffffff, 0x00000001},
    {0x80000000, 0x80008000, 0x40000000},
    {0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0xffff7fff, 0x00000000},
    {0x80000000, 0x80000000, 0x40000000},
    {0x7fffffff, 0x7fffffff, 0x3fff0001},
    {0x8000ffff, 0x8000ffff, 0x40000000},
    {0xffff8000, 0x8000ffff, 0x00008000},
    {0x7fffffff, 0x80007fff, 0xc0008000},
    {0x0001ffff, 0xffff7fff, 0xffffffff},
};

/* smbt16 */
struct binary_calculation samples_smbt16[] = {
    {0x00000001, 0x00010000, 0x00000001},
    {0x7fff7fff, 0x00010000, 0x00007fff},
    {0xffffffff, 0x00010000, 0xffffffff},
    {0xffffffff, 0xffffffff, 0x00000001},
    {0x80008000, 0x80000000, 0x40000000},
    {0x00000000, 0x00000000, 0x00000000},
    {0x7fffffff, 0x00000000, 0x00000000},
    {0x00008000, 0x80000000, 0x40000000},
    {0x7fffffff, 0x7fffffff, 0xffff8001},
    {0x7fffffff, 0x0001ffff, 0xffffffff},
    {0xffff7fff, 0x7fffffff, 0x3fff0001},
    {0x7fff8000, 0x8000ffff, 0x40000000},
};

#else
/* stsa16 */
struct binary_calculation samples_stsa16[] = {
    {0x0001123400015678, 0x0001111100012222, 0x000023450000789a},
    {0x00019000ffffa000, 0x0002a0000001b000, 0xffff3000fffe5000},
    {0xffffffff00018000, 0x0001000000028000, 0xfffeffffffff0000},
    {0x0001ffff0001ffff, 0x0002ffff0002ffff, 0xfffffffefffffffe},
    {0x0002000000020000, 0x0001ffff0001ffff, 0x0001ffff0001ffff},
    {0x00007fff00007fff, 0xffff8000ffff8000, 0x0001ffff0001ffff},
    {0x00007fff0000ffff, 0x7fff8000ffff0000, 0x8001ffff0001ffff},
    {0x0000888800008888, 0x8000888800008888, 0x8000111000001110},
    {0x8000888800008888, 0x7fff8888ffff8888, 0x0001111000011110},
    {0x7fff8888ffff8888, 0x8000888800008888, 0xffff1110ffff1110},
    {0x7fff8888ffff8888, 0xffff8888ffff8888, 0x8000111000001110},
    {0x88887fff1111ffff, 0x1111800020200000, 0x7777fffff0f1ffff},
};

/* rstsa16 */
struct binary_calculation samples_rstsa16[] = {
    {0x0000000000010001, 0x0000000000010001, 0x0000000000000001},
    {0xffffffffffffffff, 0x0000ffff0001ffff, 0xffffffffffffffff},
    {0x7fff7fffffff7fff, 0xffff0001ffff0001, 0x4000400000004000},
    {0x7fff7fff7fffffff, 0xffff0001ffff0001, 0x4000400040000000},
    {0x8000800000008000, 0x0000ffff0001ffff, 0xc000bfffffffbfff},
    {0x8000800080008000, 0x0000ffff00000000, 0xc000bfffc000c000},
    {0x7fff7fffffff7fff, 0x0000000000000000, 0x3fff3fffffff3fff},
    {0x80007fff0000ffff, 0x0000000000000000, 0xc0003fff0000ffff},
    {0x7fff8000ffff8000, 0x8000000000000000, 0x7fffc000ffffc000},
    {0x8000800000000000, 0x7fff0000ffff0000, 0x8000c00000000000},
    {0x80007fff80007fff, 0x7fff80007fff8000, 0x8000ffff8000ffff},
    {0x00017fff0001ffff, 0x0010800000010000, 0xfff8ffff0000ffff},
    {0x0000800000007ff9, 0x0001800200017fff, 0xffff8001ffff7ffc},
};

/* urstsa16 */
struct binary_calculation samples_urstsa16[] = {
    {0x0000000000010001, 0x0000000000010001, 0x0000000000000001},
    {0x0002000200020002, 0x0000000200020002, 0x0001000200000002},
    {0x0000ffff0001ffff, 0x0000000000020001, 0x00007fffffff8000},
    {0x0001ffff00010000, 0x0002000100020001, 0xffff8000ffff0000},
    {0x0000ffff0000ffff, 0xffff0001ffff0001, 0x8000800080008000},
    {0xffff0000ffff0000, 0x0000ffff0000ffff, 0x7fff7fff7fff7fff},
    {0x1111ffff1111ffff, 0x2222ffff2222ffff, 0xf777fffff777ffff},
    {0x1111800011117fff, 0x2222800022227fff, 0xf7778000f7777fff},
};

/* kstsa16 */
struct binary_calculation samples_kstsa16[] = {
    {0x0000000000010001, 0x0000000000010001, 0x0000000000000002},
    {0x0002000000020001, 0x0001ffff0001ffff, 0x0001ffff00010000},
    {0xfffefffffffeffff, 0xffffffffffffffff, 0xfffffffefffffffe},
    {0x0000000100000001, 0x7fffffffffffffff, 0x8001000000010000},
    {0x0000000100000001, 0x80007fff0000ffff, 0x7fff7fff00000000},
    {0x7fff0000ffff0001, 0x80007fff0000ffff, 0x7fff7fffffff0000},
    {0x8000000080000001, 0x7fffffff7fff7fff, 0x8000ffff80007fff},
    {0x7fff80007fff0000, 0xffffffffffffffff, 0x7fff80007fffffff},
    {0x7f7f00007f7f8000, 0xffff0000ffff0001, 0x7f8000007f808001},
    {0x8000800080000000, 0x0001000100010001, 0x8000800180000001},
    {0x80007fff0000ffff, 0x0001000000010000, 0x80007fffffffffff},
    {0xaaaa7fff22227fff, 0x7fff000011110000, 0x80007fff11117fff},
    {0xaaaa7fff22227fff, 0x7fff800011118000, 0x8000ffff1111ffff},
    {0xaaaa000022220000, 0x7fff800011110000, 0x8000800011110000},
    {0xaaaa000022220000, 0x7fff800011118000, 0x8000800011118000},
    {0xaaaa78882222aaaa, 0x7fff20001111bbbb, 0x80007fff11118000},
};

/* ukstsa16 */
struct binary_calculation samples_ukstsa16[] = {
    {0x0000000000010001, 0x0000000000010001, 0x0000000000000002},
    {0x0002000000020001, 0x0001800000018000, 0x0001800000018001},
    {0x0000000000000001, 0xffffffffffffffff, 0x0000ffff0000ffff},
    {0xffff0000ffff0001, 0x000000000000ffff, 0xffff0000ffffffff},
    {0x0000000100000000, 0x0000ffff00010000, 0x0000ffff00000000},
    {0x0000ffff0000ffff, 0x0000ffff0001ffff, 0x0000ffff0000ffff},
    {0x0000ffff0000ffff, 0x0001ffff0001ffff, 0x0000ffff0000ffff},
    {0x0001000000010000, 0x0002ffff0002ffff, 0x0000ffff0000ffff},
    {0x0001000000020000, 0x0002000000010000, 0x0000000000010000},
    {0x0002000000010000, 0x0001ffff00020000, 0x0001ffff00000000},
    {0x2222000011110000, 0x111100002222ffff, 0x111100000000ffff},
    {0x2222000011110000, 0x111100ff2222ff00, 0x111100ff0000ff00},
    {0x2222888811118888, 0x1111000022228888, 0x111188880000ffff},
};

/* stas16 */
struct binary_calculation samples_stas16[] = {
    {0x1234000156780001, 0x1111000122220001, 0x23450000789a0000},
    {0x90000001a000ffff, 0xa0000002b0000001, 0x3000ffff5000fffe},
    {0xffffffff80000001, 0x0000000180000002, 0xfffffffe0000ffff},
    {0xffff0001ffff0001, 0xffff0002ffff0002, 0xfffefffffffeffff},
    {0x0000000200000002, 0xffff0001ffff0001, 0xffff0001ffff0001},
    {0x7fff00007fff0000, 0x8000ffff8000ffff, 0xffff0001ffff0001},
    {0x7fff0000ffff0000, 0x80007fff0000ffff, 0xffff8001ffff0001},
    {0x8888000088880000, 0x8888800088880000, 0x1110800011100000},
    {0x8888800088880000, 0x88887fff8888ffff, 0x1110000111100001},
    {0x88887fff8888ffff, 0x8888800088880000, 0x1110ffff1110ffff},
    {0x88887fff8888ffff, 0x8888ffff8888ffff, 0x1110800011100000},
    {0x7fff8888ffff1111, 0x8000111100002020, 0xffff7777fffff0f1},
};

/* rstas16 */
struct binary_calculation samples_rstas16[] = {
    {0x0000000000010001, 0x0000000000010001, 0x0000000000010000},
    {0xffffffffffffffff, 0xffff0000ffff0001, 0xffffffffffffffff},
    {0x7fff7fff7fffffff, 0x0001ffff0001ffff, 0x4000400040000000},
    {0x7fff7fffffff7fff, 0x0001ffff0001ffff, 0x4000400000004000},
    {0x8000800080000000, 0xffff0000ffff0001, 0xbfffc000bfffffff},
    {0x8000800080008000, 0xffff000000000000, 0xbfffc000c000c000},
    {0x7fff7fff7fffffff, 0x0000000000000000, 0x3fff3fff3fffffff},
    {0x7fff8000ffff0000, 0x0000000000000000, 0x3fffc000ffff0000},
    {0x80007fff8000ffff, 0x0000800000000000, 0xc0007fffc000ffff},
    {0x8000800000000000, 0x00007fff0000ffff, 0xc000800000000000},
    {0x7fff80007fff8000, 0x80007fff80007fff, 0xffff8000ffff8000},
    {0x7fff0001ffff0001, 0x8000001000000001, 0xfffffff8ffff0000},
    {0x800000007ff90000, 0x800200017fff0001, 0x8001ffff7ffcffff},
};

/* urstas16 */
struct binary_calculation samples_urstas16[] = {
    {0x0000000000010001, 0x0000000000010001, 0x0000000000010000},
    {0x0002000200020002, 0x0002000000020002, 0x0002000100020000},
    {0xffff0000ffff0001, 0x0000000000010002, 0x7fff00008000ffff},
    {0xffff000100000001, 0x0001000200010002, 0x8000ffff0000ffff},
    {0xffff0000ffff0000, 0x0001ffff0001ffff, 0x8000800080008000},
    {0x0000ffff0000ffff, 0xffff0000ffff0000, 0x7fff7fff7fff7fff},
    {0xffff1111ffff1111, 0xffff2222ffff2222, 0xfffff777fffff777},
    {0x800011117fff1111, 0x800022227fff2222, 0x8000f7777ffff777},
};

/* kstas16 */
struct binary_calculation samples_kstas16[] = {
    {0x0000000000010001, 0x0000000000010001, 0x0000000000020000},
    {0x0000000200010002, 0xffff0001ffff0001, 0xffff000100000001},
    {0xfffffffefffffffe, 0xffffffffffffffff, 0xfffefffffffeffff},
    {0x0001000000010000, 0xffff7fffffffffff, 0x0000800100000001},
    {0x0001000000010000, 0x7fff8000ffff0000, 0x7fff7fff00000000},
    {0x00007fff0001ffff, 0x7fff8000ffff0000, 0x7fff7fff0000ffff},
    {0x0000800000018000, 0xffff7fff7fff7fff, 0xffff80007fff8000},
    {0x80007fff00007fff, 0xffffffffffffffff, 0x80007fffffff7fff},
    {0x00007f7f80007f7f, 0x0000ffff0001ffff, 0x00007f8080017f80},
    {0x8000800000008000, 0x0001000100010001, 0x8001800000018000},
    {0x7fff8000ffff0000, 0x0000000100000001, 0x7fff8000ffffffff},
    {0x7fffaaaa7fff2222, 0x00007fff00001111, 0x7fff80007fff1111},
    {0x7fffaaaa7fff2222, 0x80007fff80001111, 0xffff8000ffff1111},
    {0x0000aaaa00002222, 0x80007fff00001111, 0x8000800000001111},
    {0x0000aaaa00002222, 0x80007fff80001111, 0x8000800080001111},
    {0x7888aaaaaaaa2222, 0x20007fffbbbb1111, 0x7fff800080001111},
};

/* ukstas16 */
struct binary_calculation samples_ukstas16[] = {
    {0x0000000000010001, 0x0000000000010001, 0x0000000000020000},
    {0x0000000200010002, 0x8000000180000001, 0x8000000180010001},
    {0x0000000000010000, 0xffffffffffffffff, 0xffff0000ffff0000},
    {0x0000ffff0001ffff, 0x00000000ffff0000, 0x0000ffffffffffff},
    {0x0001000000000000, 0xffff000000000001, 0xffff000000000000},
    {0xffff0000ffff0000, 0xffff0000ffff0001, 0xffff0000ffff0000},
    {0xffff0000ffff0000, 0xffff0001ffff0001, 0xffff0000ffff0000},
    {0x0000000100000001, 0xffff0002ffff0002, 0xffff0000ffff0000},
    {0x0000000100000002, 0x0000000200000001, 0x0000000000000001},
    {0x0000000200000001, 0xffff000100000002, 0xffff000100000000},
    {0x0000222200001111, 0x00001111ffff2222, 0x00001111ffff0000},
    {0x0000222200001111, 0x00ff1111ff002222, 0x00ff1111ff000000},
    {0x8888222288881111, 0x0000111188882222, 0x88881111ffff0000},
};

/* sub8 */
struct binary_calculation samples_sub8[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0x0000000100000001, 0xffffffffffffffff, 0x0101010201010102},
    {0xffffffffffffffff, 0x0000000100000001, 0xfffffffefffffffe},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x8101010181010101},
    {0x0000000000000000, 0x8000000080000000, 0x8000000080000000},
    {0x0000000000000000, 0xffffffffffffffff, 0x0101010101010101},
    {0xffffffffffffffff, 0x8000000080000000, 0x7fffffff7fffffff},
    {0x8000000080000000, 0xffffffffffffffff, 0x8101010181010101},
    {0xffffffffffffffff, 0x7fffffff7fffffff, 0x8000000080000000},
    {0x2222111122221111, 0x1111202011112020, 0x1111f1f11111f1f1},
};

/* sub16 */
struct binary_calculation samples_sub16[] = {
    {0x0001000100010001, 0x0001000100010001, 0x0000000000000000},
    {0x0001ffff0001ffff, 0x0002000100020001, 0xfffffffefffffffe},
    {0xffff0001ffff0001, 0x0001000200010002, 0xfffefffffffeffff},
    {0x0001000100010001, 0x0002000200020002, 0xffffffffffffffff},
    {0x0002000200020002, 0x0001000100010001, 0x0001000100010001},
    {0x0000000000000000, 0xffffffffffffffff, 0x0001000100010001},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x8001000180010001},
    {0x0000000000000000, 0x8000000080000000, 0x8000000080000000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x0001000100010001},
    {0x7fffffff7fffffff, 0x8000000080000000, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x8000000080000000},
    {0x8888111188881111, 0x1111202011112020, 0x7777f0f17777f0f1},
};

/* add8 */
struct binary_calculation samples_add8[] = {
    {0x0000000000000000, 0x1111111111111111, 0x1111111111111111},
    {0x0000000100000001, 0x0000000100000001, 0x0000000200000002},
    {0xff000000ff000000, 0x0100000001000000, 0x0000000000000000},
    {0xffffffffffffffff, 0x0101010101010101, 0x0000000000000000},
    {0x8080808080808080, 0x8080808080808080, 0x0000000000000000},
    {0x7f7f7f7f7f7f7f7f, 0x0101010101010101, 0x8080808080808080},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xfefefefefefefefe},
    {0x1188888811888888, 0x2288888822888888, 0x3310101033101010},
};

/* sra8 */
struct binary_calculation samples_sra8[] = {
    {0x8070605040302010, 0x0000000000000001, 0xc038302820181008},
    {0x8070605040302010, 0x0000000000000002, 0xe01c1814100c0804},
    {0x8070605040302010, 0x0000000000000004, 0xf807060504030201},
    {0x8070605040302010, 0x0000000000000007, 0xff00000000000000},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000001, 0xfcfbfbfafaf9f9f8},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000002, 0xfefdfdfdfdfcfcfc},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000004, 0xffffffffffffffff},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000007, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0000000000000003, 0xffffffffffffffff},
    {0x7f7f7f7f7f7f7f7f, 0x0000000000000003, 0x0f0f0f0f0f0f0f0f},
    {0x8080808080808080, 0x0000000000000003, 0xf0f0f0f0f0f0f0f0},
};

/* sra8.u */
struct binary_calculation samples_sra8_u[] = {
    {0x8070605040302010, 0x0000000000000001, 0xc038302820181008},
    {0x8070605040302010, 0x0000000000000002, 0xe01c1814100c0804},
    {0x8070605040302010, 0x0000000000000004, 0xf807060504030201},
    {0x8070605040302010, 0x0000000000000007, 0xff01010101000000},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000001, 0xfcfcfbfbfafaf9f9},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000002, 0xfefefefdfdfdfdfc},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000004, 0x00ffffffffffffff},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000007, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000000000003, 0x0000000000000000},
    {0x7f7f7f7f7f7f7f7f, 0x0000000000000003, 0x1010101010101010},
    {0x8080808080808080, 0x0000000000000003, 0xf0f0f0f0f0f0f0f0},
};

/* srai8 */
struct binary_calculation samples_srai8[] = {
    {0x8070605040302010, 0x0000000000000001, 0xc038302820181008},
    {0x8070605040302010, 0x0000000000000002, 0xe01c1814100c0804},
    {0x8070605040302010, 0x0000000000000004, 0xf807060504030201},
    {0x8070605040302010, 0x0000000000000007, 0xff00000000000000},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000001, 0xfcfbfbfafaf9f9f8},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000002, 0xfefdfdfdfdfcfcfc},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000004, 0xffffffffffffffff},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000007, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0000000000000003, 0xffffffffffffffff},
    {0x7f7f7f7f7f7f7f7f, 0x0000000000000003, 0x0f0f0f0f0f0f0f0f},
    {0x8080808080808080, 0x0000000000000003, 0xf0f0f0f0f0f0f0f0},
};

/* srai8.u */
struct binary_calculation samples_srai8_u[] = {
    {0x8070605040302010, 0x0000000000000001, 0xc038302820181008},
    {0x8070605040302010, 0x0000000000000002, 0xe01c1814100c0804},
    {0x8070605040302010, 0x0000000000000004, 0xf807060504030201},
    {0x8070605040302010, 0x0000000000000007, 0xff01010101000000},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000001, 0xfcfcfbfbfafaf9f9},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000002, 0xfefefefdfdfdfdfc},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000004, 0x00ffffffffffffff},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000007, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000000000003, 0x0000000000000000},
    {0x7f7f7f7f7f7f7f7f, 0x0000000000000003, 0x1010101010101010},
    {0x8080808080808080, 0x0000000000000003, 0xf0f0f0f0f0f0f0f0},
};

/* srl8 */
struct binary_calculation samples_srl8[] = {
    {0x8070605040302010, 0x0000000000000001, 0x4038302820181008},
    {0x8070605040302010, 0x0000000000000002, 0x201c1814100c0804},
    {0x8070605040302010, 0x0000000000000004, 0x0807060504030201},
    {0x8070605040302010, 0x0000000000000007, 0x0100000000000000},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000001, 0x7c7b7b7a7a797978},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000002, 0x3e3d3d3d3d3c3c3c},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000004, 0x0f0f0f0f0f0f0f0f},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000007, 0x0101010101010101},
    {0xffffffffffffffff, 0x0000000000000003, 0x1f1f1f1f1f1f1f1f},
    {0x7f7f7f7f7f7f7f7f, 0x0000000000000003, 0x0f0f0f0f0f0f0f0f},
    {0x8080808080808080, 0x0000000000000003, 0x1010101010101010},
};

/* srl8.u */
struct binary_calculation samples_srl8_u[] = {
    {0x8070605040302010, 0x0000000000000001, 0x4038302820181008},
    {0x8070605040302010, 0x0000000000000002, 0x201c1814100c0804},
    {0x8070605040302010, 0x0000000000000004, 0x0807060504030201},
    {0x8070605040302010, 0x0000000000000007, 0x0101010101000000},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000001, 0x7c7c7b7b7a7a7979},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000002, 0x3e3e3e3d3d3d3d3c},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000004, 0x100f0f0f0f0f0f0f},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000007, 0x0202020202020202},
    {0xffffffffffffffff, 0x0000000000000003, 0x2020202020202020},
    {0x7f7f7f7f7f7f7f7f, 0x0000000000000003, 0x1010101010101010},
    {0x8080808080808080, 0x0000000000000003, 0x1010101010101010},
};

/* srli8 */
struct binary_calculation samples_srli8[] = {
    {0x8070605040302010, 0x0000000000000001, 0x4038302820181008},
    {0x8070605040302010, 0x0000000000000002, 0x201c1814100c0804},
    {0x8070605040302010, 0x0000000000000004, 0x0807060504030201},
    {0x8070605040302010, 0x0000000000000007, 0x0100000000000000},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000001, 0x7c7b7b7a7a797978},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000002, 0x3e3d3d3d3d3c3c3c},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000004, 0x0f0f0f0f0f0f0f0f},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000007, 0x0101010101010101},
    {0xffffffffffffffff, 0x0000000000000003, 0x1f1f1f1f1f1f1f1f},
    {0x7f7f7f7f7f7f7f7f, 0x0000000000000003, 0x0f0f0f0f0f0f0f0f},
    {0x8080808080808080, 0x0000000000000003, 0x1010101010101010},
};

/* srli8.u */
struct binary_calculation samples_srli8_u[] = {
    {0x8070605040302010, 0x0000000000000001, 0x4038302820181008},
    {0x8070605040302010, 0x0000000000000002, 0x201c1814100c0804},
    {0x8070605040302010, 0x0000000000000004, 0x0807060504030201},
    {0x8070605040302010, 0x0000000000000007, 0x0101010101000000},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000001, 0x7c7c7b7b7a7a7979},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000002, 0x3e3e3e3d3d3d3d3c},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000004, 0x100f0f0f0f0f0f0f},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000007, 0x0202020202020202},
    {0xffffffffffffffff, 0x0000000000000003, 0x2020202020202020},
    {0x7f7f7f7f7f7f7f7f, 0x0000000000000003, 0x1010101010101010},
    {0x8080808080808080, 0x0000000000000003, 0x1010101010101010},
};

/* sll8 */
struct binary_calculation samples_sll8[] = {
    {0x8070605040302010, 0x0000000000000001, 0x00e0c0a080604020},
    {0x8070605040302010, 0x0000000000000002, 0x00c0804000c08040},
    {0x8070605040302010, 0x0000000000000004, 0x0000000000000000},
    {0x8070605040302010, 0x0000000000000007, 0x0000000000000000},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000001, 0xf0eeeceae8e6e4e2},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000002, 0xe0dcd8d4d0ccc8c4},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000004, 0x8070605040302010},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000007, 0x0080008000800080},
    {0xffffffffffffffff, 0x0000000000000003, 0xf8f8f8f8f8f8f8f8},
    {0x7f7f7f7f7f7f7f7f, 0x0000000000000003, 0xf8f8f8f8f8f8f8f8},
    {0x8080808080808080, 0x0000000000000003, 0x0000000000000000},
};

/* slli8 */
struct binary_calculation samples_slli8[] = {
    {0x8070605040302010, 0x0000000000000001, 0x00e0c0a080604020},
    {0x8070605040302010, 0x0000000000000002, 0x00c0804000c08040},
    {0x8070605040302010, 0x0000000000000004, 0x0000000000000000},
    {0x8070605040302010, 0x0000000000000007, 0x0000000000000000},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000001, 0xf0eeeceae8e6e4e2},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000002, 0xe0dcd8d4d0ccc8c4},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000004, 0x8070605040302010},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000007, 0x0080008000800080},
    {0xffffffffffffffff, 0x0000000000000003, 0xf8f8f8f8f8f8f8f8},
    {0x7f7f7f7f7f7f7f7f, 0x0000000000000003, 0xf8f8f8f8f8f8f8f8},
    {0x8080808080808080, 0x0000000000000003, 0x0000000000000000},
};

/* ksll8 */
struct binary_calculation samples_ksll8[] = {
    {0x8070605040302010, 0x0000000000000001, 0x807f7f7f7f604020},
    {0x8070605040302010, 0x0000000000000002, 0x807f7f7f7f7f7f40},
    {0x8070605040302010, 0x0000000000000004, 0x807f7f7f7f7f7f7f},
    {0x8070605040302010, 0x0000000000000007, 0x807f7f7f7f7f7f7f},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000001, 0xf0eeeceae8e6e4e2},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000002, 0xe0dcd8d4d0ccc8c4},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000004, 0x8080808080808080},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000007, 0x8080808080808080},
    {0xffffffffffffffff, 0x0000000000000003, 0xf8f8f8f8f8f8f8f8},
    {0x7f7f7f7f7f7f7f7f, 0x0000000000000003, 0x7f7f7f7f7f7f7f7f},
    {0x8080808080808080, 0x0000000000000003, 0x8080808080808080},
};

/* kslli8 */
struct binary_calculation samples_kslli8[] = {
    {0x8070605040302010, 0x0000000000000001, 0x807f7f7f7f604020},
    {0x8070605040302010, 0x0000000000000002, 0x807f7f7f7f7f7f40},
    {0x8070605040302010, 0x0000000000000004, 0x807f7f7f7f7f7f7f},
    {0x8070605040302010, 0x0000000000000007, 0x807f7f7f7f7f7f7f},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000001, 0xf0eeeceae8e6e4e2},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000002, 0xe0dcd8d4d0ccc8c4},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000004, 0x8080808080808080},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000007, 0x8080808080808080},
    {0xffffffffffffffff, 0x0000000000000003, 0xf8f8f8f8f8f8f8f8},
    {0x7f7f7f7f7f7f7f7f, 0x0000000000000003, 0x7f7f7f7f7f7f7f7f},
    {0x8080808080808080, 0x0000000000000003, 0x8080808080808080},
};

/* kslra8 */
struct binary_calculation samples_kslra8[] = {
    /* op2 >= 0 */
    {0x8070605040302010, 0x0000000000000001, 0x807f7f7f7f604020},
    {0x8070605040302010, 0x0000000000000002, 0x807f7f7f7f7f7f40},
    {0x8070605040302010, 0x0000000000000004, 0x807f7f7f7f7f7f7f},
    {0x8070605040302010, 0x0000000000000007, 0x807f7f7f7f7f7f7f},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000001, 0xf0eeeceae8e6e4e2},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000002, 0xe0dcd8d4d0ccc8c4},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000004, 0x8080808080808080},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000007, 0x8080808080808080},
    {0xffffffffffffffff, 0x0000000000000003, 0xf8f8f8f8f8f8f8f8},
    {0x7f7f7f7f7f7f7f7f, 0x0000000000000003, 0x7f7f7f7f7f7f7f7f},
    {0x8080808080808080, 0x0000000000000003, 0x8080808080808080},
    /* op2 < 0 */
    {0x8070605040302010, 0x00000000000000ff, 0xc038302820181008},
    {0x8070605040302010, 0x00000000000000fe, 0xe01c1814100c0804},
    {0x8070605040302010, 0x00000000000000fc, 0xf807060504030201},
    {0x8070605040302010, 0x00000000000000f9, 0xff00000000000000},
    {0xf8f7f6f5f4f3f2f1, 0x00000000000000ff, 0xfcfbfbfafaf9f9f8},
    {0xf8f7f6f5f4f3f2f1, 0x00000000000000fe, 0xfefdfdfdfdfcfcfc},
    {0xf8f7f6f5f4f3f2f1, 0x00000000000000fc, 0xffffffffffffffff},
    {0xf8f7f6f5f4f3f2f1, 0x00000000000000f9, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x00000000000000fd, 0xffffffffffffffff},
    {0x7f7f7f7f7f7f7f7f, 0x00000000000000fd, 0x0f0f0f0f0f0f0f0f},
    {0x8080808080808080, 0x00000000000000fd, 0xf0f0f0f0f0f0f0f0},
};

/* kslra8.u */
struct binary_calculation samples_kslra8_u[] = {
    /* op2 >= 0 */
    {0x8070605040302010, 0x0000000000000001, 0x807f7f7f7f604020},
    {0x8070605040302010, 0x0000000000000002, 0x807f7f7f7f7f7f40},
    {0x8070605040302010, 0x0000000000000004, 0x807f7f7f7f7f7f7f},
    {0x8070605040302010, 0x0000000000000007, 0x807f7f7f7f7f7f7f},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000001, 0xf0eeeceae8e6e4e2},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000002, 0xe0dcd8d4d0ccc8c4},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000004, 0x8080808080808080},
    {0xf8f7f6f5f4f3f2f1, 0x0000000000000007, 0x8080808080808080},
    {0xffffffffffffffff, 0x0000000000000003, 0xf8f8f8f8f8f8f8f8},
    {0x7f7f7f7f7f7f7f7f, 0x0000000000000003, 0x7f7f7f7f7f7f7f7f},
    {0x8080808080808080, 0x0000000000000003, 0x8080808080808080},
    /* op2 < 0 */
    {0x8070605040302010, 0x00000000000000ff, 0xc038302820181008},
    {0x8070605040302010, 0x00000000000000fe, 0xe01c1814100c0804},
    {0x8070605040302010, 0x00000000000000fc, 0xf807060504030201},
    {0x8070605040302010, 0x00000000000000f9, 0xff01010101000000},
    {0xf8f7f6f5f4f3f2f1, 0x00000000000000ff, 0xfcfcfbfbfafaf9f9},
    {0xf8f7f6f5f4f3f2f1, 0x00000000000000fe, 0xfefefefdfdfdfdfc},
    {0xf8f7f6f5f4f3f2f1, 0x00000000000000fc, 0x00ffffffffffffff},
    {0xf8f7f6f5f4f3f2f1, 0x00000000000000f9, 0x0000000000000000},
    {0xffffffffffffffff, 0x00000000000000fd, 0x0000000000000000},
    {0x7f7f7f7f7f7f7f7f, 0x00000000000000fd, 0x1010101010101010},
    {0x8080808080808080, 0x00000000000000fd, 0xf0f0f0f0f0f0f0f0},
};

/* kslraw */
struct binary_calculation samples_kslraw[] = {
    /* op2 >= 0 */
    {0x0000000100000002, 0x0000000000000001, 0x0000000000000004},
    {0x0000000300000004, 0x0000000000000002, 0x0000000000000010},
    {0x0000000500000006, 0x0000000000000004, 0x0000000000000060},
    {0x0000000700000008, 0x0000000000000007, 0x0000000000000400},
    {0xfffffff1fffffff2, 0x0000000000000001, 0xffffffffffffffe4},
    {0xfffffff3fffffff4, 0x0000000000000002, 0xffffffffffffffd0},
    {0xfffffff5fffffff6, 0x0000000000000004, 0xffffffffffffff60},
    {0xfffffff7fffffff8, 0x0000000000000007, 0xfffffffffffffc00},
    {0xffffffffffffffff, 0x0000000000000003, 0xfffffffffffffff8},
    {0x7fffffff80000000, 0x0000000000000003, 0xffffffff80000000},
    {0x800000007fffffff, 0x0000000000000003, 0x000000007fffffff},
    {0x8000000000000001, 0x000000000000001f, 0x000000007fffffff},
    /* op2 < 0 */
    {0x0000000100000002, 0x00000000000000ff, 0x0000000000000001},
    {0x0000000300000004, 0x00000000000000fe, 0x0000000000000001},
    {0x0000000500000006, 0x00000000000000fc, 0x0000000000000000},
    {0x0000000700000080, 0x00000000000000f9, 0x0000000000000001},
    {0xfffffff1fffffff2, 0x00000000000000ff, 0xfffffffffffffff9},
    {0xfffffff3fffffff4, 0x00000000000000fe, 0xfffffffffffffffd},
    {0xfffffff5fffffff6, 0x00000000000000fc, 0xffffffffffffffff},
    {0xfffffff7fffffff8, 0x00000000000000f9, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x00000000000000fd, 0xffffffffffffffff},
    {0x7fffffff80000000, 0x00000000000000fd, 0xfffffffff0000000},
    {0x800000007fffffff, 0x00000000000000fd, 0x000000000fffffff},
    {0x800000007fffffff, 0x0000000000000020, 0x0000000000000000},
};

/* kslraw.u */
struct binary_calculation samples_kslraw_u[] = {
    /* op2 >= 0 */
    {0x0000000100000002, 0x0000000000000001, 0x0000000000000004},
    {0x0000000300000004, 0x0000000000000002, 0x0000000000000010},
    {0x0000000500000006, 0x0000000000000004, 0x0000000000000060},
    {0x0000000700000008, 0x0000000000000007, 0x0000000000000400},
    {0xfffffff1fffffff2, 0x0000000000000001, 0xffffffffffffffe4},
    {0xfffffff3fffffff4, 0x0000000000000002, 0xffffffffffffffd0},
    {0xfffffff5fffffff6, 0x0000000000000004, 0xffffffffffffff60},
    {0xfffffff7fffffff8, 0x0000000000000007, 0xfffffffffffffc00},
    {0xffffffffffffffff, 0x0000000000000003, 0xfffffffffffffff8},
    {0x7fffffff80000000, 0x0000000000000003, 0xffffffff80000000},
    {0x800000007fffffff, 0x0000000000000003, 0x000000007fffffff},
    {0x8000000000000001, 0x000000000000001f, 0x000000007fffffff},
    /* op2 < 0 */
    {0x0000000100000002, 0x00000000000000ff, 0x0000000000000001},
    {0x0000000300000004, 0x00000000000000fe, 0x0000000000000001},
    {0x0000000500000006, 0x00000000000000fc, 0x0000000000000000},
    {0x0000000700000080, 0x00000000000000f9, 0x0000000000000001},
    {0xfffffff1fffffff2, 0x00000000000000ff, 0xfffffffffffffff9},
    {0xfffffff3fffffff4, 0x00000000000000fe, 0xfffffffffffffffd},
    {0xfffffff5fffffff6, 0x00000000000000fc, 0xffffffffffffffff},
    {0xfffffff7fffffff8, 0x00000000000000f9, 0x0000000000000000},
    {0xffffffffffffffff, 0x00000000000000fd, 0x0000000000000000},
    {0x7fffffff80000000, 0x00000000000000fd, 0xfffffffff0000000},
    {0x800000007fffffff, 0x00000000000000fd, 0x0000000010000000},
    {0x800000007fffffff, 0x0000000000000020, 0x0000000000000001},
};

/* add16 */
struct binary_calculation samples_add16[] = {
    {0x1234567812345678, 0x1111222211112222, 0x2345789A2345789A},
    {0x9000A0009000A000, 0xA000B000A000B000, 0x3000500030005000},
    {0xFFFF8000FFFF8000, 0x0000800000008000, 0xFFFF0000FFFF0000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xfffefffefffefffe},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x8000000080000000, 0xffffffffffffffff},
    {0x8888888888888888, 0x8888888888888888, 0x1110111011101110},
};

/* cras16 */
struct binary_calculation samples_cras16[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0001000100010001},
    {0x0001000000010000, 0x0001000100010001, 0x0002ffff0002ffff},
    {0x7fff00007fff0000, 0x0000000100000001, 0x8000000080000000},
    {0xffff0000ffff0000, 0x0000000100000001, 0x0000000000000000},
    {0x0000800000008000, 0x0001000000010000, 0x00007fff00007fff},
    {0x0000000000000000, 0xffffffffffffffff, 0xffff0001ffff0001},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x7ffe00007ffe0000},
    {0xffffffffffffffff, 0x8000000080000000, 0xffff7fffffff7fff},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x7fff80017fff8001},
    {0x1111111111111111, 0x2222222222222222, 0x3333eeef3333eeef},
};

/* crsa16 */
struct binary_calculation samples_crsa16[] = {
    {0x0000000100000001, 0x0000000100000001, 0xffff0001ffff0001},
    {0x8000000080000000, 0x0000ffff0000ffff, 0x8001000080010000},
    {0x00007fff00007fff, 0x0001000000010000, 0x0000800000008000},
    {0x80007fff80007fff, 0x0001ffff0001ffff, 0x8001800080018000},
    {0xffffffffffffffff, 0x7fffffff7fffffff, 0x00007ffe00007ffe},
    {0xffffffffffffffff, 0x0000000000000000, 0xffffffffffffffff},
    {0x8000000080000000, 0xffffffffffffffff, 0x8001ffff8001ffff},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x7fff7fff7fff7fff},
    {0x1111111111111111, 0x2222222222222222, 0xeeef3333eeef3333},
};

/* ukadd8 */
struct binary_calculation samples_ukadd8[] = {
    {0x0101010101010101, 0x0101010101010101, 0x0202020202020202},
    {0x0101010101010101, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0101010101010101, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0101010101010101, 0xff010101ff010101, 0xff020202ff020202},
    {0x0101010101010101, 0x01ff010101ff0101, 0x02ff020202ff0202},
    {0x0101010101010101, 0x0101ff010101ff01, 0x0202ff020202ff02},
    {0x0101010101010101, 0x010101ff010101ff, 0x020202ff020202ff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x1188888811888888, 0x2288888822888888, 0x33ffffff33ffffff},
};

/* kadd8 */
struct binary_calculation samples_kadd8[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000200000002},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xfefefefefefefefe},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffff00ffffff00},
    {0x0000000100000001, 0x7f7f7f7f7f7f7f7f, 0x7f7f7f7f7f7f7f7f},
    {0x0101010101010101, 0x7f7f7f7f7f7f7f7f, 0x7f7f7f7f7f7f7f7f},
    {0xffffffffffffffff, 0x8080808080808080, 0x8080808080808080},
    {0xffffffffffffffff, 0x0000008000000080, 0xffffff80ffffff80},
    {0x0000000000000000, 0x0000000100000001, 0x0000000100000001},
    {0x0000000000000000, 0x7f7f7f7f7f7f7f7f, 0x7f7f7f7f7f7f7f7f},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000000000000, 0x8000000080000000, 0x8000000080000000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0xffffffffffffffff},
    {0x88117aaa88117aaa, 0x812211bb812211bb, 0x80337f8080337f80},
};

/* ukadd16 */
struct binary_calculation samples_ukadd16[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000200000002},
    {0x0000000100000001, 0x8000800080008000, 0x8000800180008001},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000100000001, 0x0000ffff0000ffff, 0x0000ffff0000ffff},
    {0x0001000000010000, 0xffff0000ffff0000, 0xffff0000ffff0000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0xffff0000ffff0000, 0xffff0000ffff0000},
    {0x0000000000000000, 0x0000ffff0000ffff, 0x0000ffff0000ffff},
    {0x0000000000000000, 0x00ffff0000ffff00, 0x00ffff0000ffff00},
    {0x8888888888888888, 0x0000888800008888, 0x8888ffff8888ffff},
};

/* kadd16 */
struct binary_calculation samples_kadd16[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000200000002},
    {0x0000000100000001, 0xffffffffffffffff, 0xffff0000ffff0000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xfffefffefffefffe},
    {0x0001000100010001, 0xffffffffffffffff, 0x0000000000000000},
    {0x0001000100010001, 0x7fffffff7fffffff, 0x7fff00007fff0000},
    {0x0000000100000001, 0x7fffffff7fffffff, 0x7fff00007fff0000},
    {0x0000000100000001, 0xffff7fffffff7fff, 0xffff7fffffff7fff},
    {0x8000000080000000, 0xffffffffffffffff, 0x8000ffff8000ffff},
    {0x0000800000008000, 0x0000000100000001, 0x0000800100008001},
    {0x8000000080000000, 0x0001000100010001, 0x8001000180010001},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x7fffffff7fffffff},
    {0x7fff7fff7fff7fff, 0x0000000000000000, 0x7fff7fff7fff7fff},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0xffffffffffffffff},
    {0x0000000000000000, 0x8000000080000000, 0x8000000080000000},
    {0x0000000000000000, 0x8000800080008000, 0x8000800080008000},
    {0x7888aaaa7888aaaa, 0x2000bbbb2000bbbb, 0x7fff80007fff8000},
};

/* kaddh */
struct binary_calculation samples_kaddh[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000002},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0x0000000100000001, 0xffffffffffffffff, 0x0000000000000000},
    {0x0000000100000001, 0x7fffffff7fffffff, 0x0000000000007fff},
    {0xffffffffffffffff, 0x8000000080000000, 0xffffffffffff8000},
    {0x0000000100000001, 0x0000007f0000007f, 0x0000000000000080},
    {0x0000000100000001, 0x00007fff00007fff, 0x0000000000007fff},
    {0xffffffffffffffff, 0xffffff80ffffff80, 0xffffffffffffff7f},
    {0xffffffffffffffff, 0xfff80000fff80000, 0xffffffffffff8000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000001},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x0000000000007fff},
    {0x7fffffff7fffffff, 0x8000000080000000, 0xffffffffffffffff},
    {0xaaaaaaaaaaaaaaaa, 0xbbbbbbbbbbbbbbbb, 0xffffffffffff8000},
    {0x7888888878888888, 0x2888000028880000, 0x0000000000007fff},
};

/* ukaddh */
struct binary_calculation samples_ukaddh[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000002},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0001000100010001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0001000100010001, 0x0001ffff0001ffff, 0xffffffffffffffff},
    {0x0001000000010000, 0x00ff000000ff0000, 0xffffffffffffffff},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000001},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x8000800000008000, 0x0000000000000000, 0xffffffffffff8000},
    {0x8000800000008000, 0x7fff7fff00007fff, 0xffffffffffffffff},
    {0x8888888888888888, 0x8888000088880000, 0xffffffffffffffff},
};

/* khmbb */
struct binary_calculation samples_khmbb[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000100008000, 0x7fffffffffff8000, 0x0000000000007fff},
    {0xffffffffffffffff, 0x8000000000008000, 0x0000000000000001},
    {0x0000000100000001, 0x0000007f0000007f, 0x0000000000000000},
    {0x0000000100007fff, 0x00007fff00007fff, 0x0000000000007ffe},
    {0xffffffff00007fff, 0xffffff80ffff8000, 0xffffffffffff8001},
    {0xfffffffffffff001, 0xfff80000ffff8000, 0x0000000000000fff},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x0000000000000000},
};

/* khmbt */
struct binary_calculation samples_khmbt[] = {
    {0x0000000100000001, 0x0000000100010000, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000100008000, 0x7fffffff8000ffff, 0x0000000000007fff},
    {0xffffffffffffffff, 0x8000000080000000, 0x0000000000000001},
    {0x0000000100000001, 0x0000007f007f0000, 0x0000000000000000},
    {0x0000000100007fff, 0x00007fff7fff0000, 0x0000000000007ffe},
    {0xffffffff00007fff, 0xffffff808000ffff, 0xffffffffffff8001},
    {0xfffffffffffff001, 0xfff800008000ffff, 0x0000000000000fff},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fffffffffff7fff, 0x0000000000000000},
};

/* khmtt */
struct binary_calculation samples_khmtt[] = {
    {0x0000000100010000, 0x0000000100010000, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0x0000000100010000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000180000000, 0x7fffffff8000ffff, 0x0000000000007fff},
    {0xffffffffffffffff, 0x8000000080000000, 0x0000000000000001},
    {0x0000000100010000, 0x0000007f007f0000, 0x0000000000000000},
    {0x000000017fff0000, 0x00007fff7fff0000, 0x0000000000007ffe},
    {0xffffffff7fff0000, 0xffffff808000ffff, 0xffffffffffff8001},
    {0xfffffffff001ffff, 0xfff800008000ffff, 0x0000000000000fff},
    {0x0000000100010000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fffffffffff7fff, 0x0000000000000000},
};

/* ukaddw */
struct binary_calculation samples_ukaddw[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000002},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0001000100010001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0001000100010001, 0x0001ffff0001ffff, 0x0000000000030000},
    {0x0001000000010000, 0x00ff000000ff0000, 0x0000000001000000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000001},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x8000800080008000, 0x0000000000000000, 0xffffffff80008000},
    {0x8000800080008000, 0x7fff7fff7fff7fff, 0xffffffffffffffff},
    {0x8888888888888888, 0x8888000088880000, 0xffffffffffffffff},
};

/* kaddw */
struct binary_calculation samples_kaddw[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000002},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0x0000000100000001, 0xffffffffffffffff, 0x0000000000000000},
    {0x0000000100000001, 0x7fffffff7fffffff, 0x000000007fffffff},
    {0xffffffffffffffff, 0x8000000080000000, 0xffffffff80000000},
    {0x0000000100000001, 0x0000007f0000007f, 0x0000000000000080},
    {0x0000000100000001, 0x00007fff00007fff, 0x0000000000008000},
    {0xffffffffffffffff, 0xffffff80ffffff80, 0xffffffffffffff7f},
    {0xffffffffffffffff, 0xfff80000fff80000, 0xfffffffffff7ffff},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000001},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x000000007fffffff},
    {0x7fffffff7fffffff, 0x8000000080000000, 0xffffffffffffffff},
    {0xaaaaaaaaaaaaaaaa, 0xbbbbbbbbbbbbbbbb, 0xffffffff80000000},
    {0x7888888878888888, 0x2888000028880000, 0x000000007fffffff},
};

/* uksub8 */
struct binary_calculation samples_uksub8[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0x0000000200000002, 0x0000000100000001, 0x0000000100000001},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000000000000, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fffffff7fffffff, 0x8000000080000000},
    {0x0000000100000001, 0xffffffffffffffff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x00ffffff00ffffff},
    {0xff7fffffff7fffff, 0x0080000000800000, 0xff00ffffff00ffff},
    {0xfffff7fffffff7ff, 0x0000800000008000, 0xffff77ffffff77ff},
    {0xffffff7fffffff7f, 0x0000008000000080, 0xffffff00ffffff00},
    {0x8888111188881111, 0x1111202011112020, 0x7777000077770000},
};

/* ksub8 */
struct binary_calculation samples_ksub8[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0xfffffffefffffffe, 0xffffffffffffffff, 0x000000ff000000ff},
    {0xfefefefefefefefe, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x8101010181010101},
    {0x0000000000000000, 0x8000000080000000, 0x7f0000007f000000},
    {0x7fffffff7fffffff, 0x8080808080808080, 0x7f7f7f7f7f7f7f7f},
    {0x7f7f7f7f7f7f7f7f, 0xffffffffffffffff, 0x7f7f7f7f7f7f7f7f},
    {0x8000000080000000, 0x0100000001000000, 0x8000000080000000},
    {0x0000800000008000, 0x0000010000000100, 0x0000800000008000},
    {0x0000008000000080, 0x0000000100000001, 0x0000008000000080},
    {0x7a7aaaaa7a7aaaaa, 0xafaf7f7fafaf7f7f, 0x7f7f80807f7f8080},
};

/* uksub16 */
struct binary_calculation samples_uksub16[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0x0002000200020002, 0x0001000100010001, 0x0001000100010001},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000000000000, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000000100000001, 0x0000000000000000},
    {0x0000000000000000, 0x0001000100010001, 0x0000000000000000},
    {0x0001000100010001, 0x0002000200020002, 0x0000000000000000},
    {0x0001000200010002, 0x0002000100020001, 0x0000000100000001},
    {0x0002000100020001, 0x0001000200010002, 0x0001000000010000},
    {0x2222111122221111, 0x1111222211112222, 0x1111000011110000},
};

/* ksub16 */
struct binary_calculation samples_ksub16[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0x0002000200020002, 0x0001000100010001, 0x0001000100010001},
    {0xfffefffefffefffe, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x8001000180010001},
    {0x0000000000000000, 0x8000000080000000, 0x7fff00007fff0000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x7fffffff7fffffff},
    {0x8000800080008000, 0x7fff7fff7fff7fff, 0x8000800080008000},
    {0x7fff7fff7fff7fff, 0xffffffffffffffff, 0x7fff7fff7fff7fff},
    {0x7f7f7f7f7f7f7f7f, 0xffffffffffffffff, 0x7f807f807f807f80},
    {0x8000800080008000, 0x0001000100010001, 0x8000800080008000},
    {0x8000000080000000, 0x0001000100010001, 0x8000ffff8000ffff},
    {0xaaaa2222aaaa2222, 0x7fff11117fff1111, 0x8000111180001111},
};

/* ksubh */
struct binary_calculation samples_ksubh[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0x7fffffff00007fff, 0xffffffffffffffff, 0x0000000000007fff},
    {0x80000000ffff8000, 0x0000000100000001, 0xffffffffffff8000},
    {0x0000800000008000, 0x0000000100000001, 0x0000000000007fff},
    {0x00007fff00007fff, 0x0000ffff0000ffff, 0xffffffffffff8000},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x0000000000007fff},
    {0x8000000080000000, 0x7fffffff7fffffff, 0xffffffffffff8000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x0000000000007fff},
    {0xaaaaaaaaaaaaaaaa, 0x7fffffff7fffffff, 0xffffffffffff8000},
    {0x7fff00007fff0000, 0xbbbb0000bbbb0000, 0x0000000000007fff},
};

/* uksubh */
struct binary_calculation samples_uksubh[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0x0000000100000001, 0x0000000200000002, 0x0000000000000000},
    {0x0001000100010001, 0x0002000200020002, 0x0000000000000000},
    {0x0101010101010101, 0x0202020202020202, 0x0000000000000000},
    {0x1000000010000000, 0x0222222202222222, 0xffffffffffffffff},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000000000000, 0xffffffffffffffff},
    {0x1111111111111111, 0x2222222222222222, 0x0000000000000000},
    {0x2222222222222222, 0x1111111111111111, 0xffffffffffffffff},
};

/* uksubw */
struct binary_calculation samples_uksubw[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0x0000000100000001, 0x0000000200000002, 0x0000000000000000},
    {0x0001000100010001, 0x0002000200020002, 0x0000000000000000},
    {0x0101010101010101, 0x0202020202020202, 0x0000000000000000},
    {0x1000000010000000, 0x0222222202222222, 0x000000000dddddde},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000000000000, 0xffffffffffffffff},
    {0x1111111111111111, 0x2222222222222222, 0x0000000000000000},
    {0x2222222222222222, 0x1111111111111111, 0x0000000011111111},
};

/* ksubw */
struct binary_calculation samples_ksubw[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x000000007fffffff},
    {0x8000000080000000, 0x0000000100000001, 0xffffffff80000000},
    {0x0000800000008000, 0x0000000100000001, 0x0000000000007fff},
    {0x00007fff00007fff, 0x0000ffff0000ffff, 0xffffffffffff8000},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x000000007fffffff},
    {0x8000000080000000, 0x7fffffff7fffffff, 0xffffffff80000000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x000000007fffffff},
    {0xaaaaaaaaaaaaaaaa, 0x7fffffff7fffffff, 0xffffffff80000000},
    {0x7fff00007fff0000, 0xbbbb0000bbbb0000, 0x000000007fffffff},
};

/* uraddw */
struct binary_calculation samples_uraddw[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000001},
    {0x8080808280808082, 0x8080808080808080, 0xffffffff80808081},
    {0x8000000080000000, 0x8000000080000000, 0xffffffff80000000},
    {0x0000000000000000, 0xffffffffffffffff, 0x000000007fffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x000000007fffffff},
};

/* raddw */
struct binary_calculation samples_raddw[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000001},
    {0x8080808280808082, 0x8080808080808080, 0xffffffff80808081},
    {0x8000000080000000, 0x8000000080000000, 0xffffffff80000000},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x000000003fffffff},
    {0x7fffffff7fffffff, 0x7ffffff97ffffff9, 0x000000007ffffffc},
    {0x8000000280000002, 0x8000000080000000, 0xffffffff80000001},
};

/* uradd8 */
struct binary_calculation samples_uradd8[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000100000001},
    {0x0202020202020202, 0x0202020202020202, 0x0202020202020202},
    {0x8080808080808080, 0x8080808080808080, 0x8080808080808080},
    {0x8000000080000000, 0x8000000080000000, 0x8000000080000000},
    {0x0000000000000000, 0xffffffffffffffff, 0x7f7f7f7f7f7f7f7f},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7f8010007f801000, 0x7f8020017f802001, 0x7f8018007f801800},
};

/* radd8 */
struct binary_calculation samples_radd8[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000100000001},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7f7f7f7f7f7f7f7f, 0x0101010101010101, 0x4040404040404040},
    {0x7fffffff7fffffff, 0x0000000100000001, 0x3fffff003fffff00},
    {0x8080808080808080, 0xffffffffffffffff, 0xbfbfbfbfbfbfbfbf},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x3fffffff3fffffff},
    {0x0000000000000000, 0x8000000080000000, 0xc0000000c0000000},
    {0x7f8810007f881000, 0x7f1120017f112001, 0x7fcc18007fcc1800},
};

/* uradd16 */
struct binary_calculation samples_uradd16[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000100000001},
    {0x0002000200020002, 0x0002000200020002, 0x0002000200020002},
    {0xffffffffffffffff, 0x0000000100000001, 0x7fff80007fff8000},
    {0xffff0000ffff0000, 0x0001000100010001, 0x8000000080000000},
    {0xffffffffffffffff, 0x0001000100010001, 0x8000800080008000},
    {0x0000000000000000, 0xffffffffffffffff, 0x7fff7fff7fff7fff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x80007fff80007fff, 0x80007fff80007fff, 0x80007fff80007fff},
};

/* radd16 */
struct binary_calculation samples_radd16[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000100000001},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fff7fff7fff7fff, 0x0001000100010001, 0x4000400040004000},
    {0x7fffffff7fffffff, 0x0001000100010001, 0x4000000040000000},
    {0x8000800080008000, 0xffffffffffffffff, 0xbfffbfffbfffbfff},
    {0x8000800080008000, 0xffff0000ffff0000, 0xbfffc000bfffc000},
    {0x7fff7fff7fff7fff, 0x0000000000000000, 0x3fff3fff3fff3fff},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x3fffffff3fffffff},
    {0x8000800080008000, 0x0000000000000000, 0xc000c000c000c000},
    {0x8000000080000000, 0x0000000000000000, 0xc0000000c0000000},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x8000000080000000, 0xffffffffffffffff},
    {0x80007ff980007ff9, 0x80027fff80027fff, 0x80017ffc80017ffc},
};

/* ursubw */
struct binary_calculation samples_ursubw[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0x0000000100000001, 0x0000000200000002, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0000000000000000, 0x000000007fffffff},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffff80000000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0xffffffffffffffff},
    {0x0000000000000000, 0x7fffffff7fffffff, 0xffffffffc0000000},
    {0x1111111111111111, 0x2222222222222222, 0xfffffffff7777777},
    {0x7fffffff7fffffff, 0x8000000080000000, 0xffffffffffffffff},
};

/* rsubw */
struct binary_calculation samples_rsubw[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0x0000000100000001, 0x0000000200000002, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xfffffffefffffffe, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x0000000040000000},
    {0x8000000080000000, 0x0000000100000001, 0xffffffffbfffffff},
    {0x0000000000000000, 0x7fffffff7fffffff, 0xffffffffc0000000},
    {0x0000000000000000, 0x8000000080000000, 0x0000000040000000},
    {0x8000000080000000, 0x0000000000000000, 0xffffffffc0000000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0xffffffff80000000},
    {0x0000000100000001, 0x0000001000000010, 0xfffffffffffffff8},
};

/* ursub8 */
struct binary_calculation samples_ursub8[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0x0000000100000001, 0xffffffffffffffff, 0x8080808180808081},
    {0x0101010101010101, 0xffffffffffffffff, 0x8181818181818181},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0x2222117f2222117f, 0x1111228011112280, 0x0808f7ff0808f7ff},
};

/* rsub8 */
struct binary_calculation samples_rsub8[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0x0000000100000001, 0xffffffffffffffff, 0x0000000100000001},
    {0xffffffffffffffff, 0x0000000100000001, 0xffffffffffffffff},
    {0x7f7f7f7f7f7f7f7f, 0xffffffffffffffff, 0x4040404040404040},
    {0x8080808080808080, 0x0101010101010101, 0xbfbfbfbfbfbfbfbf},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x4000000040000000},
    {0x8000000080000000, 0x0000000100000001, 0xc00000ffc00000ff},
    {0x0000000000000000, 0x7fffffff7fffffff, 0xc0000000c0000000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x8000000080000000},
    {0x7f7f7f7f7f7f7f7f, 0x8080808080808080, 0x7f7f7f7f7f7f7f7f},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x7fffffff7fffffff},
    {0x0101111101011111, 0x1010222210102222, 0xf8f8f7f7f8f8f7f7},
};

/* ursub16 */
struct binary_calculation samples_ursub16[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0x0002000200020002, 0x0000000200000002, 0x0001000000010000},
    {0x0000000100000001, 0x0000000200000002, 0x0000ffff0000ffff},
    {0x0001000100010001, 0x0002000200020002, 0xffffffffffffffff},
    {0x0000000000000000, 0xffffffffffffffff, 0x8000800080008000},
    {0xffffffffffffffff, 0x0000000000000000, 0x7fff7fff7fff7fff},
    {0x1111111111111111, 0x2222222222222222, 0xf777f777f777f777},
};

/* rsub16 */
struct binary_calculation samples_rsub16[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000100000001, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x4000000040000000},
    {0x7fff7fff7fff7fff, 0xffffffffffffffff, 0x4000400040004000},
    {0x8000000080000000, 0x0000000100000001, 0xc000ffffc000ffff},
    {0x8000800080008000, 0x0000000000000000, 0xc000c000c000c000},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x3fffffff3fffffff},
    {0x8000000080000000, 0x0000000000000000, 0xc0000000c0000000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x8000000080000000},
    {0x8000800080008000, 0x7fff7fff7fff7fff, 0x8000800080008000},
    {0x0001000100010001, 0x0010000100100001, 0xfff80000fff80000},
    {0x0000000000000000, 0x0001000100010001, 0xffffffffffffffff},
};

/* ukcras16 */
struct binary_calculation samples_ukcras16[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0001000100010001},
    {0xffff0000ffff0000, 0x0000000100000001, 0xffff0000ffff0000},
    {0x0000000000000000, 0x0001000000010000, 0x0000000000000000},
    {0x0000000000000000, 0xffffffffffffffff, 0xffff0000ffff0000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffff0000ffff0000},
    {0xffffffffffffffff, 0x8000000080000000, 0xffff7fffffff7fff},
    {0x8000000080000000, 0x7fffffff7fffffff, 0xffff0000ffff0000},
    {0xff001000ff001000, 0x1001111110011111, 0xffff0000ffff0000},
};

/* kcras16 */
struct binary_calculation samples_kcras16[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0001000100010001},
    {0x0001000000010000, 0x0001000100010001, 0x0002ffff0002ffff},
    {0x7fff00007fff0000, 0x0000000100000001, 0x7fff00007fff0000},
    {0x0008000000080000, 0x0001000000010000, 0x0008ffff0008ffff},
    {0x0000000000000000, 0xffffffffffffffff, 0xffff0001ffff0001},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x7ffe00007ffe0000},
    {0xffffffffffffffff, 0x8000000080000000, 0xffff7fffffff7fff},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x8000800180008001},
    {0x7fff80017fff8001, 0x1000111110001111, 0x7fff80007fff8000},
};

/* ukcrsa16 */
struct binary_calculation samples_ukcrsa16[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000100000001},
    {0x00007fff00007fff, 0x0001000100010001, 0x0000800000008000},
    {0xffffffffffffffff, 0x7fffffff7fffffff, 0x0000ffff0000ffff},
    {0xffffffffffffffff, 0x0000000000000000, 0xffffffffffffffff},
    {0x8000000080000000, 0xffffffffffffffff, 0x0000ffff0000ffff},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x7fffffff7fffffff},
    {0x1000ff001000ff00, 0x1000100110001001, 0x0000ffff0000ffff},
    {0x0000f0000000f000, 0x1000000110000001, 0x0000ffff0000ffff},
};

/* kcrsa16 */
struct binary_calculation samples_kcrsa16[] = {
    {0x0000000100000001, 0x0000000100000001, 0xffff0001ffff0001},
    {0x8000000080000000, 0x0000ffff0000ffff, 0x8001000080010000},
    {0x00007fff00007fff, 0x0001000000010000, 0x00007fff00007fff},
    {0x80007fff80007fff, 0x0001ffff0001ffff, 0x80017fff80017fff},
    {0xffffffffffffffff, 0x0000000000000000, 0xffffffffffffffff},
    {0x8000000080000000, 0x0000000000000000, 0x8000000080000000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x7fff80007fff8000},
    {0x80017f0080017f00, 0x1000100110001001, 0x80007fff80007fff},
};

/* urcras16 */
struct binary_calculation samples_urcras16[] = {
    {0x0000000100000001, 0x0001000000010000, 0x0000000000000000},
    {0x0001000000010000, 0x0001000100010001, 0x0001ffff0001ffff},
    {0xffff0000ffff0000, 0x0001000000010000, 0x7fffffff7fffffff},
    {0xffff0000ffff0000, 0x0001000100010001, 0x8000ffff8000ffff},
    {0x0000800000008000, 0x0000800100008001, 0x4000400040004000},
    {0x0000000000000000, 0xffffffffffffffff, 0x7fff80007fff8000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xbfff0000bfff0000},
    {0xffffffffffffffff, 0x0000800000008000, 0xbfff7fffbfff7fff},
    {0x8000000080000000, 0xffff7fffffff7fff, 0x7fff80007fff8000},
    {0x8888111188881111, 0x2222888822228888, 0x8888f7778888f777},
    {0x7fff00007fff0000, 0x00017fff00017fff, 0x7fffffff7fffffff},
    {0x8000800080008000, 0x7fff80007fff8000, 0x8000000080000000},
    {0x7fff7fff7fff7fff, 0x80007fff80007fff, 0x7fffffff7fffffff},
};

/* rcras16 */
struct binary_calculation samples_rcras16[] = {
    {0x0000000100000001, 0x0001000000010000, 0x0000000000000000},
    {0x0001000000010000, 0x0001000100010001, 0x0001ffff0001ffff},
    {0xffff0000ffff0000, 0x0001000000010000, 0xffffffffffffffff},
    {0xffff0000ffff0000, 0x0001000100010001, 0x0000ffff0000ffff},
    {0x7fff00007fff0000, 0x0001000000010000, 0x3fffffff3fffffff},
    {0x0000800000008000, 0x0000800100008001, 0xc000c000c000c000},
    {0x8000000080000000, 0xffff0000ffff0000, 0xc0000000c0000000},
    {0x80007fff80007fff, 0xffffffffffffffff, 0xbfff4000bfff4000},
    {0x0000000000000000, 0xffffffffffffffff, 0xffff0000ffff0000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x3fff00003fff0000},
    {0xffffffffffffffff, 0x0000800000008000, 0xbfffffffbfffffff},
    {0x8000000080000000, 0xffff7fffffff7fff, 0xffff0000ffff0000},
    {0x7fff00017fff0001, 0x0010100000101000, 0x47fffff847fffff8},
    {0x7fff7fff7fff7fff, 0x80007fff80007fff, 0x7fff7fff7fff7fff},
};

/* urcrsa16 */
struct binary_calculation samples_urcrsa16[] = {
    {0x0001000000010000, 0x0000000100000001, 0x0000000000000000},
    {0x0000000100000001, 0x0001000100010001, 0xffff0001ffff0001},
    {0x0000ffff0000ffff, 0x0000000100000001, 0xffff7fffffff7fff},
    {0x0000ffff0000ffff, 0x0001000100010001, 0xffff8000ffff8000},
    {0x8000000080000000, 0x8001000080010000, 0x4000400040004000},
    {0x0000000000000000, 0xffffffffffffffff, 0x80007fff80007fff},
    {0xffff7fffffff7fff, 0xffffffffffffffff, 0x0000bfff0000bfff},
    {0xffffffffffffffff, 0x8000000080000000, 0x7fffbfff7fffbfff},
    {0x0000800000008000, 0x7fffffff7fffffff, 0x80007fff80007fff},
    {0x1111ff001111ff00, 0x1000222210002222, 0xf7778780f7778780},
    {0x0000ff000000ff00, 0x1000000110000001, 0xffff8780ffff8780},
};

/* rcrsa16 */
struct binary_calculation samples_rcrsa16[] = {
    {0x0001000000010000, 0x0000000100000001, 0x0000000000000000},
    {0x0000000100000001, 0x0001000100010001, 0xffff0001ffff0001},
    {0x0000ffff0000ffff, 0x0000000100000001, 0xffffffffffffffff},
    {0x0000ffff0000ffff, 0x0001000100010001, 0xffff0000ffff0000},
    {0x00007fff00007fff, 0x0000000100000001, 0xffff3fffffff3fff},
    {0x8000000080000000, 0x8001000080010000, 0xc000c000c000c000},
    {0x0000800000008000, 0x0000ffff0000ffff, 0x0000c0000000c000},
    {0x7fff80007fff8000, 0xffffffffffffffff, 0x4000bfff4000bfff},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000ffff0000ffff},
    {0xffff7fffffff7fff, 0xffffffffffffffff, 0x00003fff00003fff},
    {0xffffffffffffffff, 0x8000000080000000, 0xffffbfffffffbfff},
    {0x0000800000008000, 0x7fffffff7fffffff, 0x0000ffff0000ffff},
    {0x00017f0000017f00, 0x2000001020000010, 0xfff84f80fff84f80},
};

/* add64 */
struct binary64_64_64_calculation samples_add64[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000200000002},
    {0x0000000100000000, 0x0000000100000000, 0x0000000200000000},
    {0x0000000000000001, 0x0000000000000001, 0x0000000000000002},
    {0xffffffff00000000, 0x0000000100000000, 0x0000000000000000},
    {0xffffffff80000000, 0x0000000180000000, 0x0000000100000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x7fffffff7fffffff},
    {0x7fffffff80000000, 0x800000007fffffff, 0xffffffffffffffff},
    {0x2000000000000000, 0xff00000000000000, 0x1f00000000000000},
};

/* radd64 */
struct binary64_64_64_calculation samples_radd64[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000100000001},
    {0x0000000100000000, 0x0000000100000000, 0x0000000100000000},
    {0x0000000000000001, 0x0000000000000001, 0x0000000000000001},
    {0xffffffff00000000, 0x0000000100000000, 0x0000000000000000},
    {0xffffffff80000000, 0x0000000180000000, 0x0000000080000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x3fffffffbfffffff},
    {0x7fffffff80000000, 0x800000007fffffff, 0xffffffffffffffff},
    {0x2000000000000000, 0xff00000000000000, 0x0f80000000000000},
    {0x7fffffffffffffff, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x7fffffffffffffff, 0x8000000000000000, 0xffffffffffffffff},
    {0x8000000000000000, 0x8000000000000000, 0x8000000000000000},
};

/* uradd64 */
struct binary64_64_64_calculation samples_uradd64[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000100000001},
    {0x0000000100000000, 0x0000000100000000, 0x0000000100000000},
    {0x0000000000000001, 0x0000000000000001, 0x0000000000000001},
    {0xffffffff00000000, 0x0000000100000000, 0x8000000000000000},
    {0xffffffff80000000, 0x0000000180000000, 0x8000000080000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x3fffffffbfffffff},
    {0x7fffffff80000000, 0x800000007fffffff, 0x7fffffffffffffff},
    {0x2000000000000000, 0xff00000000000000, 0x8f80000000000000},
    {0x7fffffffffffffff, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x7fffffffffffffff, 0x8000000000000000, 0x7fffffffffffffff},
    {0x8000000000000000, 0x8000000000000000, 0x8000000000000000},
};

/* ukadd64 */
struct binary64_64_64_calculation samples_ukadd64[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000200000002},
    {0x0000000100000000, 0x0000000100000000, 0x0000000200000000},
    {0x0000000000000001, 0x0000000000000001, 0x0000000000000002},
    {0xffffffff00000000, 0x0000000100000000, 0xffffffffffffffff},
    {0xffffffff80000000, 0x0000000180000000, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x7fffffff7fffffff},
    {0x7fffffff80000000, 0x800000007fffffff, 0xffffffffffffffff},
    {0xff00000000000000, 0x2000000000000000, 0xffffffffffffffff},
};

/* kadd64 */
struct binary64_64_64_calculation samples_kadd64[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000200000002},
    {0x0000000100000000, 0x0000000100000000, 0x0000000200000000},
    {0x0000000000000001, 0x0000000000000001, 0x0000000000000002},
    {0x7fffffff00000000, 0x0000000100000000, 0x7fffffffffffffff},
    {0x8000000000000000, 0x8000000000000000, 0x8000000000000000},
    {0x7fffffff80000000, 0x0000000180000000, 0x7fffffffffffffff},
    {0xffffffff80000000, 0x0000000180000000, 0x0000000100000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x7fffffff7fffffff},
    {0x7fffffff80000000, 0x800000007fffffff, 0xffffffffffffffff},
    {0x7f00000000000000, 0x2000000000000000, 0x7fffffffffffffff},
    {0x8000000000000001, 0xaa00000000000000, 0x8000000000000000},
};

/* sub64 */
struct binary64_64_64_calculation samples_sub64[] = {
    {0x0000001000000010, 0x0000000100000001, 0x0000000f0000000f},
    {0x0000001000000000, 0x0000000100000000, 0x0000000f00000000},
    {0x0000000000000010, 0x0000000000000001, 0x000000000000000f},
    {0x0000000000000000, 0xffffffff00000000, 0x0000000100000000},
    {0x0000000000000000, 0x8000000000000000, 0x8000000000000000},
    {0x0000000000000000, 0x7fffffff80000000, 0x8000000080000000},
    {0x0000000000000000, 0xffffffff80000000, 0x0000000080000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xfffffffefffffffe, 0xffffffffffffffff, 0xfffffffeffffffff},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fffffff80000000, 0x800000007fffffff},
    {0x0000000000000001, 0x0000000000000010, 0xfffffffffffffff1},
};

/* rsub64 */
struct binary64_64_64_calculation samples_rsub64[] = {
    {0x0000001000000010, 0x0000000100000001, 0x0000000780000007},
    {0x0000001000000000, 0x0000000100000000, 0x0000000780000000},
    {0x0000000000000010, 0x0000000000000001, 0x0000000000000007},
    {0x0000000000000000, 0xffffffff00000000, 0x0000000080000000},
    {0x0000000000000000, 0x8000000000000000, 0x4000000000000000},
    {0x0000000000000000, 0x7fffffff80000000, 0xc000000040000000},
    {0x0000000000000000, 0xffffffff80000000, 0x0000000040000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xfffffffefffffffe, 0xffffffffffffffff, 0xffffffff7fffffff},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fffffff80000000, 0xc00000003fffffff},
    {0x0000000000000001, 0x0000000000000010, 0xfffffffffffffff8},
};

/* ursub64 */
struct binary64_64_64_calculation samples_ursub64[] = {
    {0x0000001000000010, 0x0000000100000001, 0x0000000780000007},
    {0x0000001000000000, 0x0000000100000000, 0x0000000780000000},
    {0x0000000000000010, 0x0000000000000001, 0x0000000000000007},
    {0x0000000000000000, 0xffffffff00000000, 0x0000000080000000},
    {0x0000000000000000, 0x8000000000000000, 0x4000000000000000},
    {0x0000000000000000, 0x7fffffff80000000, 0x4000000040000000},
    {0x0000000000000000, 0xffffffff80000000, 0x0000000040000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xfffffffefffffffe, 0xffffffffffffffff, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fffffff80000000, 0x400000003fffffff},
    {0x0000000000000001, 0x0000000000000010, 0x7ffffffffffffff8},
};

/* uksub64 */
struct binary64_64_64_calculation samples_uksub64[] = {
    {0x0000001000000010, 0x0000000100000001, 0x0000000f0000000f},
    {0x0000001000000000, 0x0000000100000000, 0x0000000f00000000},
    {0x0000000000000010, 0x0000000000000001, 0x000000000000000f},
    {0x0000000000000000, 0xffffffff00000000, 0x0000000000000000},
    {0x0000000000000000, 0x8000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fffffff80000000, 0x0000000000000000},
    {0x0000000000000000, 0xffffffff80000000, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xfffffffefffffffe, 0xffffffffffffffff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fffffff80000000, 0x800000007fffffff},
    {0x1000000000000000, 0x2000000000000000, 0x0000000000000000},
};

/* ksub64 */
struct binary64_64_64_calculation samples_ksub64[] = {
    {0x0000001000000010, 0x0000000100000001, 0x0000000f0000000f},
    {0x0000001000000000, 0x0000000100000000, 0x0000000f00000000},
    {0x0000000000000010, 0x0000000000000001, 0x000000000000000f},
    {0x8000000000000000, 0x7fffffff00000000, 0x8000000000000000},
    {0x0000000000000000, 0x8000000000000000, 0x7fffffffffffffff},
    {0x0000000000000000, 0x7fffffff80000000, 0x8000000080000000},
    {0x0000000000000000, 0xffffffff80000000, 0x0000000080000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xfffffffefffffffe, 0xffffffffffffffff, 0xfffffffeffffffff},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fffffff80000000, 0x800000007fffffff},
    {0x7000000000000001, 0x7000000000000000, 0x0000000000000001},
};

/* sra.u */
struct binary_calculation samples_sra_u[] = {
    {0x0000000000000001, 0x00000001, 0x0000000000000001},
    {0x0000000000000001, 0x00000010, 0x0000000000000000},
    {0x0000000000000000, 0x00000000, 0x0000000000000000},
    {0x0000000000000000, 0x0000001f, 0x0000000000000000},
    {0x0000000001111111, 0x0000001f, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000001f, 0x0000000000000000},
    {0xffffffffbfffffff, 0x0000001f, 0xffffffffffffffff},
    {0x000000007fffffff, 0x0000001f, 0x0000000000000001},
    {0xffffffff80000000, 0x0000001f, 0xffffffffffffffff},
    {0x0000000010101011, 0x00000001, 0x0000000008080809},
    {0xffffffff80101011, 0x00000001, 0xffffffffc0080809},
    {0x0000000010101012, 0x00000002, 0x0000000004040405},
    {0x0000000010101010, 0x00000002, 0x0000000004040404},
    {0xffffffff80101012, 0x00000002, 0xffffffffe0040405},
    {0xffffffff80000000, 0x00000000, 0xffffffff80000000},
    {0xffffffff80000000, 0x0000003f, 0x0000000000000000},
};

/* srai.u */
struct binary_calculation samples_srai_u[] = {
    {0x0000000000000001, 0x00000001, 0x0000000000000001},
    {0x0000000000000001, 0x00000010, 0x0000000000000000},
    {0x0000000000000000, 0x00000000, 0x0000000000000000},
    {0x0000000000000000, 0x0000001f, 0x0000000000000000},
    {0x0000000001111111, 0x0000001f, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000001f, 0x0000000000000000},
    {0xffffffffbfffffff, 0x0000001f, 0xffffffffffffffff},
    {0x000000007fffffff, 0x0000001f, 0x0000000000000001},
    {0xffffffff80000000, 0x0000001f, 0xffffffffffffffff},
    {0x0000000010101011, 0x00000001, 0x0000000008080809},
    {0xffffffff80101011, 0x00000001, 0xffffffffc0080809},
    {0x0000000010101012, 0x00000002, 0x0000000004040405},
    {0x0000000010101010, 0x00000002, 0x0000000004040404},
    {0xffffffff80101012, 0x00000002, 0xffffffffe0040405},
    {0xffffffff80000000, 0x00000000, 0xffffffff80000000},
    {0xffffffff80000000, 0x0000003f, 0x0000000000000000},
};

/* bitrev */
struct binary_calculation samples_bitrev[] = {
    {0x0000000000000001, 0x00000001, 0x0000000000000002},
    {0x0000000000000001, 0x00000010, 0x0000000000010000},
    {0x0000000000000000, 0x00000000, 0x0000000000000000},
    {0x0000000000000000, 0x0000001f, 0x0000000000000000},
    {0x0000000001111111, 0x0000001f, 0x0000000088888880},
    {0xffffffffffffffff, 0x0000001f, 0x00000000ffffffff},
    {0xffffffffbfffffff, 0x0000001f, 0x00000000fffffffd},
    {0x000000007fffffff, 0x0000001f, 0x00000000fffffffe},
    {0xffffffff80000000, 0x0000001f, 0x0000000000000001},
    {0x0000000010101011, 0x00000001, 0x0000000000000002},
    {0xffffffff80101011, 0x00000001, 0x0000000000000002},
    {0x0000000010101012, 0x00000002, 0x0000000000000002},
    {0x0000000010101010, 0x00000002, 0x0000000000000000},
    {0xffffffff80101012, 0x00000002, 0x0000000000000002},
    {0xffffffff80000000, 0x00000000, 0x0000000000000000},
    {0xffffffff80000000, 0x0000003f, 0x00000001ffffffff},
};

/* bitrevi */
struct binary_calculation samples_bitrevi[] = {
    {0x0000000000000001, 0x00000001, 0x0000000000000002},
    {0x0000000000000001, 0x00000010, 0x0000000000010000},
    {0x0000000000000000, 0x00000000, 0x0000000000000000},
    {0x0000000000000000, 0x0000001f, 0x0000000000000000},
    {0x0000000001111111, 0x0000001f, 0x0000000088888880},
    {0xffffffffffffffff, 0x0000001f, 0x00000000ffffffff},
    {0xffffffffbfffffff, 0x0000001f, 0x00000000fffffffd},
    {0x000000007fffffff, 0x0000001f, 0x00000000fffffffe},
    {0xffffffff80000000, 0x0000001f, 0x0000000000000001},
    {0x0000000010101011, 0x00000001, 0x0000000000000002},
    {0xffffffff80101011, 0x00000001, 0x0000000000000002},
    {0x0000000010101012, 0x00000002, 0x0000000000000002},
    {0x0000000010101010, 0x00000002, 0x0000000000000000},
    {0xffffffff80101012, 0x00000002, 0x0000000000000002},
    {0xffffffff80000000, 0x00000000, 0x0000000000000000},
    {0xffffffff80000000, 0x0000003f, 0x00000001ffffffff},
};

/* kslliw */
struct binary_calculation samples_kslliw[] = {
    {0x0000000000000001, 0x00000001, 0x0000000000000002},
    {0x00000000fffffffe, 0x00000001, 0xfffffffffffffffc},
    {0x000000007fffffff, 0x00000001, 0x000000007fffffff},
    {0x0000000080000000, 0x00000001, 0xffffffff80000000},
    {0x00000000007fffff, 0x00000009, 0x000000007fffffff},
    {0x00000000ff800000, 0x00000009, 0xffffffff80000000},
    {0x00000000ffffffff, 0x0000001f, 0xffffffff80000000},
    {0x0000000000000000, 0x0000001f, 0x0000000000000000},
    {0x0000000000000001, 0x0000001f, 0x000000007fffffff},
    {0x0000000040101010, 0x00000002, 0x000000007fffffff},
    {0x0000000080101010, 0x00000002, 0xffffffff80000000},
};

/* ksllw */
struct binary_calculation samples_ksllw[] = {
    {0x0000000100000001, 0x00000001, 0x0000000000000002},
    {0xfffffffefffffffe, 0x00000001, 0xfffffffffffffffc},
    {0x7fffffff7fffffff, 0x00000001, 0x000000007fffffff},
    {0x8000000080000000, 0x00000001, 0xffffffff80000000},
    {0x007fffff007fffff, 0x00000009, 0x000000007fffffff},
    {0xff800000ff800000, 0x00000009, 0xffffffff80000000},
    {0xffffffffffffffff, 0x0000001f, 0xffffffff80000000},
    {0x0000000000000000, 0x0000001f, 0x0000000000000000},
    {0x0000000100000001, 0x0000001f, 0x000000007fffffff},
    {0x7fffffff7fffffff, 0x00000000, 0x000000007fffffff},
    {0x4010101040101010, 0x00000002, 0x000000007fffffff},
    {0x8010101080101010, 0x00000002, 0xffffffff80000000},
};

/* srai16 */
struct binary_calculation samples_srai16[] = {
    {0x1000000010000000, 0x00000001, 0x0800000008000000},
    {0x0001000100010001, 0x00000001, 0x0000000000000000},
    {0x8011101080111010, 0x00000001, 0xc0080808c0080808},
    {0x80007fff80007fff, 0x0000000f, 0xffff0000ffff0000},
    {0x8011101080111010, 0x00000002, 0xe0040404e0040404},
    {0x8000800080008000, 0x00000002, 0xe000e000e000e000},
    {0x1000100010001000, 0x00000002, 0x0400040004000400},
};

/* sra16 */
struct binary_calculation samples_sra16[] = {
    {0x1000000010000000, 0x0000000100000001, 0x0800000008000000},
    {0x0001000100010001, 0x0000000100000001, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x8011101080111010, 0x000000100000000f, 0xffff0000ffff0000},
    {0x8011101080111010, 0x0000000100000001, 0xc0080808c0080808},
    {0x80007fff80007fff, 0x0000000f0000000f, 0xffff0000ffff0000},
    {0x8011101080111010, 0x0000000100000001, 0xc0080808c0080808},
    {0x8000800080008000, 0x0000000100000001, 0xc000c000c000c000},
    {0x1000100010001000, 0x0000000100000001, 0x0800080008000800},
    {0x8000800080008000, 0x0000001f0000001f, 0xffffffffffffffff},
    {0x8000800080008000, 0x000000100000000f, 0xffffffffffffffff},
};

/* srai16.u */
struct binary_calculation samples_srai16_u[] = {
    {0x1000000010000000, 0x00000001, 0x0800000008000000},
    {0x0000000100000001, 0x00000001, 0x0000000100000001},
    {0x0000000100000001, 0x00000002, 0x0000000000000000},
    {0x8012101280121012, 0x00000002, 0xe0050405e0050405},
    {0x8011101180111011, 0x00000001, 0xc0090809c0090809},
    {0x8000800080008000, 0x00000002, 0xe000e000e000e000},
    {0x8002800280028002, 0x00000002, 0xe001e001e001e001},
    {0x1000100010001000, 0x00000002, 0x0400040004000400},
    {0x1002100210021002, 0x00000002, 0x0401040104010401},
    {0x8000800080008000, 0x00000000, 0x8000800080008000},
};

/* sra16.u */
struct binary_calculation samples_sra16_u[] = {
    {0x1000000010000000, 0x00000001, 0x0800000008000000},
    {0x0000000100000001, 0x00000001, 0x0000000100000001},
    {0x0000000100000001, 0x00000002, 0x0000000000000000},
    {0x8012101280121012, 0x00000002, 0xe0050405e0050405},
    {0x8011101180111011, 0x00000001, 0xc0090809c0090809},
    {0x8000800080008000, 0x00000001, 0xc000c000c000c000},
    {0x8001800180018001, 0x00000001, 0xc001c001c001c001},
    {0x8000800080008000, 0x00000000, 0x8000800080008000},
};

/* srli16 */
struct binary_calculation samples_srli16[] = {
    {0x1000000010000000, 0x00000001, 0x0800000008000000},
    {0x1100000011000000, 0x00000001, 0x0880000008800000},
    {0x1100000011000000, 0x00000002, 0x0440000004400000},
    {0x1000100010001000, 0x00000001, 0x0800080008000800},
    {0x0000000100000001, 0x00000001, 0x0000000000000000},
    {0x0000000100000001, 0x00000002, 0x0000000000000000},
    {0x1000000110000001, 0x00000002, 0x0400000004000000},
    {0x1000000110000001, 0x00000001, 0x0800000008000000},
    {0x1000000110000001, 0x00000003, 0x0200000002000000},
    {0x7fff7fff7fff7fff, 0x00000003, 0x0fff0fff0fff0fff},
    {0xffffffffffffffff, 0x0000000f, 0x0001000100010001},
    {0xbfffffffbfffffff, 0x0000000f, 0x0001000100010001},
    {0x7fffffff7fffffff, 0x0000000f, 0x0000000100000001},
    {0x8000000080000000, 0x0000000f, 0x0001000000010000},
    {0x1011801010118010, 0x00000002, 0x0404200404042004},
    {0x1010101010101010, 0x00000002, 0x0404040404040404},
    {0x8010801080108010, 0x00000002, 0x2004200420042004},
};

/* srl16 */
struct binary_calculation samples_srl16[] = {
    {0x1000000010000000, 0x00000001, 0x0800000008000000},
    {0x1100000011000000, 0x00000001, 0x0880000008800000},
    {0x1100000011000000, 0x00000002, 0x0440000004400000},
    {0x1000100010001000, 0x00000001, 0x0800080008000800},
    {0x0000000100000001, 0x00000001, 0x0000000000000000},
    {0x1000000110000001, 0x00000002, 0x0400000004000000},
    {0x1000000110000001, 0x00000001, 0x0800000008000000},
    {0x1000000110000001, 0x00000003, 0x0200000002000000},
    {0x7fff7fff7fff7fff, 0x00000003, 0x0fff0fff0fff0fff},
    {0x0000000000000000, 0x00000000, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000f, 0x0001000100010001},
    {0xbfffffffbfffffff, 0x0000000f, 0x0001000100010001},
    {0x7fffffff7fffffff, 0x0000000f, 0x0000000100000001},
    {0x8000000080000000, 0x0000000f, 0x0001000000010000},
    {0x8011101080111010, 0x00000001, 0x4008080840080808},
    {0x8011801180118011, 0x00000001, 0x4008400840084008},
    {0x1010101010101010, 0x00000001, 0x0808080808080808},
};

/* srli16.u */
struct binary_calculation samples_srli16_u[] = {
    {0x1000000010000000, 0x00000001, 0x0800000008000000},
    {0x1100000011000000, 0x00000001, 0x0880000008800000},
    {0x1100000011000000, 0x00000002, 0x0440000004400000},
    {0x1000100010001000, 0x00000001, 0x0800080008000800},
    {0x0000000100000001, 0x00000001, 0x0000000100000001},
    {0x0000000100000001, 0x00000002, 0x0000000000000000},
    {0x1000000110000001, 0x00000002, 0x0400000004000000},
    {0x1000000110000001, 0x00000001, 0x0800000108000001},
    {0x1000000110000001, 0x00000003, 0x0200000002000000},
    {0x7fff7fff7fff7fff, 0x00000003, 0x1000100010001000},
    {0x0000000000000000, 0x0000000f, 0x0000000000000000},
    {0x0111111101111111, 0x0000000f, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000f, 0x0002000200020002},
    {0xbfffffffbfffffff, 0x0000000f, 0x0001000200010002},
    {0x7fffffff7fffffff, 0x0000000f, 0x0001000200010002},
    {0x8000000080000000, 0x0000000f, 0x0001000000010000},
    {0x8012101280121012, 0x00000002, 0x2005040520050405},
    {0x8000800080008000, 0x00000002, 0x2000200020002000},
    {0x8002800280028002, 0x00000002, 0x2001200120012001},
};

/* srl16.u */
struct binary_calculation samples_srl16_u[] = {
    {0x1000000010000000, 0x00000001, 0x0800000008000000},
    {0x1100000011000000, 0x00000001, 0x0880000008800000},
    {0x1100000011000000, 0x00000002, 0x0440000004400000},
    {0x1000100010001000, 0x00000001, 0x0800080008000800},
    {0x0000000100000001, 0x00000001, 0x0000000100000001},
    {0x0000000100000001, 0x00000002, 0x0000000000000000},
    {0x1000000110000001, 0x00000002, 0x0400000004000000},
    {0x1000000110000001, 0x00000001, 0x0800000108000001},
    {0x1000000110000001, 0x00000003, 0x0200000002000000},
    {0x7fff7fff7fff7fff, 0x00000003, 0x1000100010001000},
    {0x0000000000000000, 0x00000000, 0x0000000000000000},
    {0x0000000000000000, 0x0000000f, 0x0000000000000000},
    {0x0111111101111111, 0x0000000f, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000f, 0x0002000200020002},
    {0xbfffffffbfffffff, 0x0000000f, 0x0001000200010002},
    {0x7fffffff7fffffff, 0x0000000f, 0x0001000200010002},
    {0x8000000080000000, 0x0000000f, 0x0001000000010000},
    {0x8018101880181018, 0x00000004, 0x0802010208020102},
    {0x8008800080088000, 0x00000004, 0x0801080008010800},
    {0x8000800080008000, 0x0000000f, 0x0001000100010001},
};

/* slli16 */
struct binary_calculation samples_slli16[] = {
    {0x0000000100000001, 0x00000001, 0x0000000200000002},
    {0xfffffffefffffffe, 0x00000001, 0xfffefffcfffefffc},
    {0x7fffffff7fffffff, 0x00000001, 0xfffefffefffefffe},
    {0x8000000080000000, 0x00000001, 0x0000000000000000},
    {0x007fffff007fffff, 0x00000009, 0xfe00fe00fe00fe00},
    {0x0080000000800000, 0x00000009, 0x0000000000000000},
    {0x8010801180108011, 0x00000001, 0x0020002200200022},
    {0x8000800080008000, 0x00000001, 0x0000000000000000},
};

/* sll16 */
struct binary_calculation samples_sll16[] = {
    {0x0000000100000001, 0x00000001, 0x0000000200000002},
    {0xfffffffefffffffe, 0x00000001, 0xfffefffcfffefffc},
    {0x7fffffff7fffffff, 0x00000001, 0xfffefffefffefffe},
    {0x8000000080000000, 0x00000001, 0x0000000000000000},
    {0x007fffff007fffff, 0x00000009, 0xfe00fe00fe00fe00},
    {0x0080000000800000, 0x00000009, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x00000000, 0x7fffffff7fffffff},
    {0x8010801180108011, 0x00000002, 0x0040004400400044},
    {0x8000800080008000, 0x00000002, 0x0000000000000000},
    {0x8000800080008000, 0x00000000, 0x8000800080008000},
};

/* kslli16 */
struct binary_calculation samples_kslli16[] = {
    {0x0000000100000001, 0x00000001, 0x0000000200000002},
    {0xfffffffefffffffe, 0x00000001, 0xfffefffcfffefffc},
    {0x7fffffff7fffffff, 0x00000001, 0x7ffffffe7ffffffe},
    {0x8000000080000000, 0x00000001, 0x8000000080000000},
    {0x007fffff007fffff, 0x00000009, 0x7ffffe007ffffe00},
    {0xff800000ff800000, 0x00000009, 0x8000000080000000},
    {0x4011801040118010, 0x00000002, 0x7fff80007fff8000},
    {0x8000800080008000, 0x00000002, 0x8000800080008000},
};

/* ksll16 */
struct binary_calculation samples_ksll16[] = {
    {0x0000000100000001, 0x00000001, 0x0000000200000002},
    {0xfffffffefffffffe, 0x00000001, 0xfffefffcfffefffc},
    {0x7fffffff7fffffff, 0x00000001, 0x7ffffffe7ffffffe},
    {0x8000000080000000, 0x00000001, 0x8000000080000000},
    {0x007fffff007fffff, 0x00000009, 0x7ffffe007ffffe00},
    {0xff800000ff800000, 0x00000009, 0x8000000080000000},
    {0x7fffffff7fffffff, 0x00000000, 0x7fffffff7fffffff},
    {0x1011801010118010, 0x00000004, 0x7fff80007fff8000},
    {0x8000800080008000, 0x00000004, 0x8000800080008000},
    {0x2000200020002000, 0x00000004, 0x7fff7fff7fff7fff},
    {0x0001000100010001, 0x0000000f, 0x7fff7fff7fff7fff},
    {0x0001000100010001, 0x0000000e, 0x4000400040004000},
};

/* kslra16 */
struct binary_calculation samples_kslra16[] = {
    /* op2 >= 0 */
    {0x0000000100000001, 0x00000001, 0x0000000200000002},
    {0xfffffffefffffffe, 0x00000001, 0xfffefffcfffefffc},
    {0x7fffffff7fffffff, 0x00000001, 0x7ffffffe7ffffffe},
    {0x8000000080000000, 0x00000001, 0x8000000080000000},
    {0x007fffff007fffff, 0x00000009, 0x7ffffe007ffffe00},
    {0xff800000ff800000, 0x00000009, 0x8000000080000000},
    {0x7fffffff7fffffff, 0x00000000, 0x7fffffff7fffffff},
    {0x1011801010118010, 0x00000004, 0x7fff80007fff8000},
    {0x8000800080008000, 0x00000004, 0x8000800080008000},
    {0x2000200020002000, 0x00000004, 0x7fff7fff7fff7fff},
    {0x0001000100010001, 0x0000000f, 0x7fff7fff7fff7fff},
    {0x0001000100010001, 0x0000000e, 0x4000400040004000},
    /* op2 < 0 */
    {0x1000000010000000, 0x0000001f, 0x0800000008000000},
    {0x0001000100010001, 0x0000001f, 0x0000000000000000},
    {0x8011101080111010, 0x0000001f, 0xc0080808c0080808},
    {0x80007fff80007fff, 0x00000011, 0xffff0000ffff0000},
    {0x8011101080111010, 0x0000001e, 0xe0040404e0040404},
    {0x8000800080008000, 0x0000001e, 0xe000e000e000e000},
    {0x1000100010001000, 0x0000001e, 0x0400040004000400},

};

/* kslra16.u */
struct binary_calculation samples_kslra16_u[] = {
    /* op2 >= 0 */
    {0x0000000100000001, 0x00000001, 0x0000000200000002},
    {0xfffffffefffffffe, 0x00000001, 0xfffefffcfffefffc},
    {0x7fffffff7fffffff, 0x00000001, 0x7ffffffe7ffffffe},
    {0x8000000080000000, 0x00000001, 0x8000000080000000},
    {0x007fffff007fffff, 0x00000009, 0x7ffffe007ffffe00},
    {0xff800000ff800000, 0x00000009, 0x8000000080000000},
    {0x7fffffff7fffffff, 0x00000000, 0x7fffffff7fffffff},
    {0x1011801010118010, 0x00000004, 0x7fff80007fff8000},
    {0x8000800080008000, 0x00000004, 0x8000800080008000},
    {0x2000200020002000, 0x00000004, 0x7fff7fff7fff7fff},
    {0x0001000100010001, 0x0000000f, 0x7fff7fff7fff7fff},
    {0x0001000100010001, 0x0000000e, 0x4000400040004000},
    /* op2 < 0 */
    {0x1000000010000000, 0x0000001f, 0x0800000008000000},
    {0x0000000100000001, 0x0000001f, 0x0000000100000001},
    {0x0000000100000001, 0x0000001e, 0x0000000000000000},
    {0x8012101280121012, 0x0000001e, 0xe0050405e0050405},
    {0x8011101180111011, 0x0000001f, 0xc0090809c0090809},
    {0x8000800080008000, 0x0000001f, 0xc000c000c000c000},
    {0x8001800180018001, 0x0000001f, 0xc001c001c001c001},
    {0x8000800080008000, 0x00000000, 0x8000800080008000},
};

/* cmpeq8 */
struct binary_calculation samples_cmpeq8[] = {
    {0x2222222222222222, 0x1111111111111111, 0x0000000000000000},
    {0x2222222222222222, 0x2211111122111111, 0xff000000ff000000},
    {0x2222222222222222, 0x2222111122221111, 0xffff0000ffff0000},
    {0x2222222222222222, 0x2222221122222211, 0xffffff00ffffff00},
    {0x2222222222222222, 0x2222222222222222, 0xffffffffffffffff},
    {0x0110aa000110aa00, 0x0111ab000111ab00, 0xff0000ffff0000ff},
    {0x0000000000000000, 0x0101010101010101, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000, 0xffffffffffffffff},
};

/* cmpeq16 */
struct binary_calculation samples_cmpeq16[] = {
    {0x2222222222222222, 0x1111111111111111, 0x0000000000000000},
    {0x2222222222222222, 0x2211111122111111, 0x0000000000000000},
    {0x2222222222222222, 0x2222111122221111, 0xffff0000ffff0000},
    {0x2222222222222222, 0x2222221122222211, 0xffff0000ffff0000},
    {0x2222222222222222, 0x2222222222222222, 0xffffffffffffffff},
    {0x8011101080111010, 0x0000101000001010, 0x0000ffff0000ffff},
    {0x0001000100010001, 0x0001000100010001, 0xffffffffffffffff},
};

/* ucmple8 */
struct binary_calculation samples_ucmple8[] = {
    {0x1111111111111111, 0x2222222222222222, 0xffffffffffffffff},
    {0x2211111122111111, 0x2222222222222222, 0xffffffffffffffff},
    {0x3322111133221111, 0x2222222222222222, 0x00ffffff00ffffff},
    {0x3333221133332211, 0x2222222222222222, 0x0000ffff0000ffff},
    {0x3333333333333333, 0x2222222222222222, 0x0000000000000000},
    {0x8080808080808080, 0x7f7f7f7f7f7f7f7f, 0x0000000000000000},
    {0x8080808080808080, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x1111200111112001, 0x1211101012111010, 0xffff00ffffff00ff},
    {0x0000000000000000, 0x0101010101010101, 0xffffffffffffffff},
    {0x0101010101010101, 0x0101010101010101, 0xffffffffffffffff},
};

/* scmple8 */
struct binary_calculation samples_scmple8[] = {
    {0x1111111111111111, 0x2222222222222222, 0xffffffffffffffff},
    {0x2211111122111111, 0x2222222222222222, 0xffffffffffffffff},
    {0x3322111133221111, 0x2222222222222222, 0x00ffffff00ffffff},
    {0x3333221133332211, 0x2222222222222222, 0x0000ffff0000ffff},
    {0x3333333333333333, 0x2222222222222222, 0x0000000000000000},
    {0xeeeeeeeeeeeeeeee, 0x2222222222222222, 0xffffffffffffffff},
    {0x2222222222222222, 0xeeeeeeeeeeeeeeee, 0x0000000000000000},
    {0x8080808080808080, 0x7f7f7f7f7f7f7f7f, 0xffffffffffffffff},
    {0x8080808080808080, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0xfdaa7f01fdaa7f01, 0xfeaa1010feaa1010, 0xffff00ffffff00ff},
    {0x0000000000000000, 0x0101010101010101, 0xffffffffffffffff},
    {0x0000000000000000, 0x8080808080808080, 0x0000000000000000},
    {0xaaaaaaaaaaaaaaaa, 0xaaaaaaaaaaaaaaaa, 0xffffffffffffffff},
};

/* ucmple16 */
struct binary_calculation samples_ucmple16[] = {
    {0x1111111111111111, 0x2222222222222222, 0xffffffffffffffff},
    {0x2211111122111111, 0x2222222222222222, 0xffffffffffffffff},
    {0x3322111133221111, 0x2222222222222222, 0x0000ffff0000ffff},
    {0x3333221133332211, 0x2222222222222222, 0x0000ffff0000ffff},
    {0x3333333333333333, 0x2222222222222222, 0x0000000000000000},
    {0x8080808080808080, 0x7f7f7f7f7f7f7f7f, 0x0000000000000000},
    {0x8000800080008000, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x8080808080808080, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x1000000110000001, 0x0010100000101000, 0x0000ffff0000ffff},
    {0x8000800080008000, 0x8000800080008000, 0xffffffffffffffff},
};

/* ucmplt8 */
struct binary_calculation samples_ucmplt8[] = {
    {0x1111111111111111, 0x2222222222222222, 0xffffffffffffffff},
    {0x2211111122111111, 0x2222222222222222, 0x00ffffff00ffffff},
    {0x3322111133221111, 0x2222222222222222, 0x0000ffff0000ffff},
    {0x3333221133332211, 0x2222222222222222, 0x000000ff000000ff},
    {0x3333333333333333, 0x2222222222222222, 0x0000000000000000},
    {0x8080808080808080, 0x7f7f7f7f7f7f7f7f, 0x0000000000000000},
    {0x8080808080808080, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0181010101810101, 0xf1111001f1111001, 0xff00ff00ff00ff00},
};

/* scmplt8 */
struct binary_calculation samples_scmplt8[] = {
    {0x1111111111111111, 0x2222222222222222, 0xffffffffffffffff},
    {0x2211111122111111, 0x2222222222222222, 0x00ffffff00ffffff},
    {0x3322111133221111, 0x2222222222222222, 0x0000ffff0000ffff},
    {0x3333221133332211, 0x2222222222222222, 0x000000ff000000ff},
    {0x3333333333333333, 0x2222222222222222, 0x0000000000000000},
    {0xeeeeeeeeeeeeeeee, 0x2222222222222222, 0xffffffffffffffff},
    {0x2222222222222222, 0xeeeeeeeeeeeeeeee, 0x0000000000000000},
    {0x8080808080808080, 0x7f7f7f7f7f7f7f7f, 0xffffffffffffffff},
    {0x8080808080808080, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0x0181010101810101, 0xf1111001f1111001, 0x00ffff0000ffff00},
};

/* ucmplt16 */
struct binary_calculation samples_ucmplt16[] = {
    {0x1111111111111111, 0x2222222222222222, 0xffffffffffffffff},
    {0x2211111122111111, 0x2222222222222222, 0xffffffffffffffff},
    {0x3322111133221111, 0x2222222222222222, 0x0000ffff0000ffff},
    {0x3333221133332211, 0x2222222222222222, 0x0000ffff0000ffff},
    {0x3333333333333333, 0x2222222222222222, 0x0000000000000000},
    {0x8080808080808080, 0x7f7f7f7f7f7f7f7f, 0x0000000000000000},
    {0x8000800080008000, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x8080808080808080, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000000000000, 0x0001000000010000, 0xffff0000ffff0000},
};

/* scmplt16 */
struct binary_calculation samples_scmplt16[] = {
    {0x1111111111111111, 0x2222222222222222, 0xffffffffffffffff},
    {0x2211111122111111, 0x2222222222222222, 0xffffffffffffffff},
    {0x3322111133221111, 0x2222222222222222, 0x0000ffff0000ffff},
    {0x3333221133332211, 0x2222222222222222, 0x0000ffff0000ffff},
    {0x3333333333333333, 0x2222222222222222, 0x0000000000000000},
    {0xeeeeeeeeeeeeeeee, 0x2222222222222222, 0xffffffffffffffff},
    {0x2222222222222222, 0xeeeeeeeeeeeeeeee, 0x0000000000000000},
    {0x8080808080808080, 0x7f7f7f7f7f7f7f7f, 0xffffffffffffffff},
    {0x8000800080008000, 0x7fff7fff7fff7fff, 0xffffffffffffffff},
    {0x8080808080808080, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0x1001a0001001a000, 0x8001000080010000, 0x0000ffff0000ffff},
};

/* scmple16 */
struct binary_calculation samples_scmple16[] = {
    {0x1111111111111111, 0x2222222222222222, 0xffffffffffffffff},
    {0x2211111122111111, 0x2222222222222222, 0xffffffffffffffff},
    {0x3322111133221111, 0x2222222222222222, 0x0000ffff0000ffff},
    {0x3333221133332211, 0x2222222222222222, 0x0000ffff0000ffff},
    {0x3333333333333333, 0x2222222222222222, 0x0000000000000000},
    {0xeeeeeeeeeeeeeeee, 0x2222222222222222, 0xffffffffffffffff},
    {0x2222222222222222, 0xeeeeeeeeeeeeeeee, 0x0000000000000000},
    {0x8080808080808080, 0x7f7f7f7f7f7f7f7f, 0xffffffffffffffff},
    {0x8000800080008000, 0x7fff7fff7fff7fff, 0xffffffffffffffff},
    {0x8080808080808080, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0x1001a0001001a000, 0x8001000080010000, 0x0000ffff0000ffff},
    {0x0001000100010001, 0x0001000100010001, 0xffffffffffffffff},
};

/* umax8 */
struct binary_calculation samples_umax8[] = {
    {0x2222222222222222, 0x1111111111111111, 0x2222222222222222},
    {0x2222222222222222, 0x2211111122111111, 0x2222222222222222},
    {0x2222222222222222, 0x3322111133221111, 0x3322222233222222},
    {0x2222222222222222, 0x3333221133332211, 0x3333222233332222},
    {0x2222222222222222, 0x3333333333333333, 0x3333333333333333},
    {0x2222222222222222, 0xeeeeeeeeeeeeeeee, 0xeeeeeeeeeeeeeeee},
    {0xeeeeeeeeeeeeeeee, 0x2222222222222222, 0xeeeeeeeeeeeeeeee},
    {0x7f7f7f7f7f7f7f7f, 0x8080808080808080, 0x8080808080808080},
    {0xffffffffffffffff, 0x8080808080808080, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0000000000000000, 0xffffffffffffffff},
    {0x8011101080111010, 0x00aa111000aa1110, 0x80aa111080aa1110},
};

/* smax8 */
struct binary_calculation samples_smax8[] = {
    {0x2222222222222222, 0x1111111111111111, 0x2222222222222222},
    {0x2222222222222222, 0x2211111122111111, 0x2222222222222222},
    {0x2222222222222222, 0x3322111133221111, 0x3322222233222222},
    {0x2222222222222222, 0x3333221133332211, 0x3333222233332222},
    {0x2222222222222222, 0x3333333333333333, 0x3333333333333333},
    {0x2222222222222222, 0xeeeeeeeeeeeeeeee, 0x2222222222222222},
    {0xeeeeeeeeeeeeeeee, 0x2222222222222222, 0x2222222222222222},
    {0x7f7f7f7f7f7f7f7f, 0x8080808080808080, 0x7f7f7f7f7f7f7f7f},
    {0xffffffffffffffff, 0x8080808080808080, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x8011102280111022, 0x00aaaa1000aaaa10, 0x0011102200111022},
};

/* sclip8 */
struct binary_calculation samples_sclip8[] = {
    {0xf1f2f3f4f5f6f7f8, 0x1, 0xfefefefefefefefe},
    {0xf1f2f3f4f5f6f7f8, 0x2, 0xfcfcfcfcfcfcfcfc},
    {0xf1f2f3f4f5f6f7f8, 0x3, 0xf8f8f8f8f8f8f8f8},
    {0x0102030405060708, 0x1, 0x0101010101010101},
    {0x0102030405060708, 0x2, 0x0102030303030303},
    {0x0102030405060708, 0x3, 0x0102030405060707},
    {0x8080808080808080, 0x6, 0xc0c0c0c0c0c0c0c0},
    {0x8080808080808080, 0x7, 0x8080808080808080},
    {0x7f7f7f7f7f7f7f7f, 0x6, 0x3f3f3f3f3f3f3f3f},
    {0x7f7f7f7f7f7f7f7f, 0x7, 0x7f7f7f7f7f7f7f7f},
};

/* uclip8 */
struct binary_calculation samples_uclip8[] = {
    {0xf1f2f3f4f5f6f7f8, 0x1, 0x0000000000000000},
    {0xf1f2f3f4f5f6f7f8, 0x2, 0x0000000000000000},
    {0xf1f2f3f4f5f6f7f8, 0x3, 0x0000000000000000},
    {0x0102030405060708, 0x1, 0x0101010101010101},
    {0x0102030405060708, 0x2, 0x0102030303030303},
    {0x0102030405060708, 0x3, 0x0102030405060707},
    {0x8080808080808080, 0x6, 0x0000000000000000},
    {0x8080808080808080, 0x7, 0x0000000000000000},
    {0x7f7f7f7f7f7f7f7f, 0x6, 0x3f3f3f3f3f3f3f3f},
    {0x7f7f7f7f7f7f7f7f, 0x7, 0x7f7f7f7f7f7f7f7f},
};


/* umax16 */
struct binary_calculation samples_umax16[] = {
    {0x2222222222222222, 0x1111111111111111, 0x2222222222222222},
    {0x2222222222222222, 0x2211111122111111, 0x2222222222222222},
    {0x2222222222222222, 0x3322111133221111, 0x3322222233222222},
    {0x2222222222222222, 0x3333221133332211, 0x3333222233332222},
    {0x2222222222222222, 0x3333333333333333, 0x3333333333333333},
    {0x2222222222222222, 0xeeeeeeeeeeeeeeee, 0xeeeeeeeeeeeeeeee},
    {0xeeeeeeeeeeeeeeee, 0x2222222222222222, 0xeeeeeeeeeeeeeeee},
    {0x2222222222222222, 0x3311111133111111, 0x3311222233112222},
    {0x7f7f7f7f7f7f7f7f, 0x8080808080808080, 0x8080808080808080},
    {0xffffffffffffffff, 0x8080808080808080, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0000000000000000, 0xffffffffffffffff},
    {0xa0011010a0011010, 0x1111101011111010, 0xa0011010a0011010},
};

/* smax16 */
struct binary_calculation samples_smax16[] = {
    {0x2222222222222222, 0x1111111111111111, 0x2222222222222222},
    {0x2222222222222222, 0x2211111122111111, 0x2222222222222222},
    {0x2222222222222222, 0x3322111133221111, 0x3322222233222222},
    {0x2222222222222222, 0x3333221133332211, 0x3333222233332222},
    {0x2222222222222222, 0x3333333333333333, 0x3333333333333333},
    {0x2222222222222222, 0xeeeeeeeeeeeeeeee, 0x2222222222222222},
    {0xeeeeeeeeeeeeeeee, 0x2222222222222222, 0x2222222222222222},
    {0x2222222222222222, 0x3311111133111111, 0x3311222233112222},
    {0x7f7f7f7f7f7f7f7f, 0x8080808080808080, 0x7f7f7f7f7f7f7f7f},
    {0xffffffffffffffff, 0x8080808080808080, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0xa0011010a0011010, 0xb0011011b0011011, 0xb0011011b0011011},
};

/* maxw */
struct binary_calculation samples_maxw[] = {
    {0x2222222222222222, 0x1111111111111111, 0x0000000022222222},
    {0x2222222222222222, 0x2211111122111111, 0x0000000022222222},
    {0x2222222222222222, 0x3322111133221111, 0x0000000033221111},
    {0x2222222222222222, 0x3333221133332211, 0x0000000033332211},
    {0x2222222222222222, 0x3333333333333333, 0x0000000033333333},
    {0x2222222222222222, 0xeeeeeeeeeeeeeeee, 0x0000000022222222},
    {0xeeeeeeeeeeeeeeee, 0x2222222222222222, 0x0000000022222222},
    {0x2222222222222222, 0x3311111133111111, 0x0000000033111111},
    {0x7f7f7f7f7f7f7f7f, 0x8080808080808080, 0x000000007f7f7f7f},
    {0xffffffffffffffff, 0x8080808080808080, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0xa0001000a0001000, 0xb0000001b0000001, 0xffffffffb0000001},
};

/* umin8 */
struct binary_calculation samples_umin8[] = {
    {0x1111111111111111, 0x2222222222222222, 0x1111111111111111},
    {0x2211111122111111, 0x2222222222222222, 0x2211111122111111},
    {0x3322111133221111, 0x2222222222222222, 0x2222111122221111},
    {0x3333221133332211, 0x2222222222222222, 0x2222221122222211},
    {0x3333333333333333, 0x2222222222222222, 0x2222222222222222},
    {0xa1810101a1810101, 0xf1111001f1111001, 0xa1110101a1110101},
    {0x8080808080808080, 0x0000000000000000, 0x0000000000000000},
    {0x8080808080808080, 0x8080808080808080, 0x8080808080808080},
};

/* smin8 */
struct binary_calculation samples_smin8[] = {
    {0x1111111111111111, 0x2222222222222222, 0x1111111111111111},
    {0x2211111122111111, 0x2222222222222222, 0x2211111122111111},
    {0x3322111133221111, 0x2222222222222222, 0x2222111122221111},
    {0x3333221133332211, 0x2222222222222222, 0x2222221122222211},
    {0x3333333333333333, 0x2222222222222222, 0x2222222222222222},
    {0xeeeeeeeeeeeeeeee, 0x2222222222222222, 0xeeeeeeeeeeeeeeee},
    {0x2222222222222222, 0xeeeeeeeeeeeeeeee, 0xeeeeeeeeeeeeeeee},
    {0x8080808080808080, 0x7f7f7f7f7f7f7f7f, 0x8080808080808080},
    {0x8080808080808080, 0xffffffffffffffff, 0x8080808080808080},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xa1811101a1811101, 0xa0111001a0111001, 0xa0811001a0811001},
};

/* umin16 */
struct binary_calculation samples_umin16[] = {
    {0x1111111111111111, 0x2222222222222222, 0x1111111111111111},
    {0x2211111122111111, 0x2222222222222222, 0x2211111122111111},
    {0x3322111133221111, 0x2222222222222222, 0x2222111122221111},
    {0x3333221133332211, 0x2222222222222222, 0x2222221122222211},
    {0x3333333333333333, 0x2222222222222222, 0x2222222222222222},
    {0xeeeeeeeeeeeeeeee, 0x2222222222222222, 0x2222222222222222},
    {0x2222222222222222, 0xeeeeeeeeeeeeeeee, 0x2222222222222222},
    {0x3311111133111111, 0x2222222222222222, 0x2222111122221111},
    {0x8080808080808080, 0x7f7f7f7f7f7f7f7f, 0x7f7f7f7f7f7f7f7f},
    {0x8080808080808080, 0xffffffffffffffff, 0x8080808080808080},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0x0000000000000000, 0x8000800080008000, 0x0000000000000000},
};

/* smin16 */
struct binary_calculation samples_smin16[] = {
    {0x1111111111111111, 0x2222222222222222, 0x1111111111111111},
    {0x2211111122111111, 0x2222222222222222, 0x2211111122111111},
    {0x3322111133221111, 0x2222222222222222, 0x2222111122221111},
    {0x3333221133332211, 0x2222222222222222, 0x2222221122222211},
    {0x3333333333333333, 0x2222222222222222, 0x2222222222222222},
    {0xeeeeeeeeeeeeeeee, 0x2222222222222222, 0xeeeeeeeeeeeeeeee},
    {0x2222222222222222, 0xeeeeeeeeeeeeeeee, 0xeeeeeeeeeeeeeeee},
    {0x3311111133111111, 0x2222222222222222, 0x2222111122221111},
    {0x8080808080808080, 0x7f7f7f7f7f7f7f7f, 0x8080808080808080},
    {0x8080808080808080, 0xffffffffffffffff, 0x8080808080808080},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xa0018000a0018000, 0x8001000080010000, 0x8001800080018000},
};

/* minw */
struct binary_calculation samples_minw[] = {
    {0x1111111111111111, 0x2222222222222222, 0x0000000011111111},
    {0x3322111133221111, 0x2222222222222222, 0x0000000022222222},
    {0xeeeeeeeeeeeeeeee, 0x2222222222222222, 0xffffffffeeeeeeee},
    {0x2222222222222222, 0xeeeeeeeeeeeeeeee, 0xffffffffeeeeeeee},
    {0x8080808080808080, 0x7f7f7f7f7f7f7f7f, 0xffffffff80808080},
    {0x8080808080808080, 0xffffffffffffffff, 0xffffffff80808080},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x8000000180000001, 0x7000000170000001, 0xffffffff80000001},
};

/* pkbb16 */
struct binary_calculation samples_pkbb16[] = {
    {0x89abcdef89abcdef, 0x0123456701234567, 0xcdef4567cdef4567},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000ffff0000ffff},
    {0x1234567812345678, 0xffffffffffffffff, 0x5678ffff5678ffff},
    {0xffffffffffffffff, 0x0000000000000000, 0xffff0000ffff0000},
    {0xa0011010a0011010, 0x1111101111111011, 0x1010101110101011},
};

/* pkbt16 */
struct binary_calculation samples_pkbt16[] = {
    {0x89abcdef89abcdef, 0x0123456701234567, 0xcdef0123cdef0123},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000ffff0000ffff},
    {0x1234567812345678, 0xffffffffffffffff, 0x5678ffff5678ffff},
    {0xffffffffffffffff, 0x0000000000000000, 0xffff0000ffff0000},
    {0xa0011010a0011010, 0x1111101111111011, 0x1010111110101111},
};

/* pktt16 */
struct binary_calculation samples_pktt16[] = {
    {0x89abcdef89abcdef, 0x0123456701234567, 0x89ab012389ab0123},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000ffff0000ffff},
    {0x1234567812345678, 0xffffffffffffffff, 0x1234ffff1234ffff},
    {0xffffffffffffffff, 0x0000000000000000, 0xffff0000ffff0000},
    {0x0010000000100000, 0x1000000110000001, 0x0010100000101000},
};

/* pktb16 */
struct binary_calculation samples_pktb16[] = {
    {0x89abcdef89abcdef, 0x0123456701234567, 0x89ab456789ab4567},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000ffff0000ffff},
    {0x1234567812345678, 0xffffffffffffffff, 0x1234ffff1234ffff},
    {0xffffffffffffffff, 0x0000000000000000, 0xffff0000ffff0000},
    {0x0010000000100000, 0x1000000110000001, 0x0010000100100001},
};

/* sclip32 */
struct binary_calculation samples_sclip32[] = {
    {0x0000000100000001, 0x00000000, 0x0000000000000000},
    {0x0000000100000001, 0x00000001, 0x0000000100000001},
    {0x0000000100000001, 0x0000001f, 0x0000000100000001},
    {0xffffffffffffffff, 0x00000001, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0000001f, 0xffffffffffffffff},
    {0xfffffffefffffffe, 0x0000001f, 0xfffffffefffffffe},
    {0x0000000100000001, 0x0000001e, 0x0000000100000001},
    {0xffffffffffffffff, 0x0000001f, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0000001e, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000001f, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x0000001e, 0x3fffffff3fffffff},
    {0x8000000080000000, 0x0000001e, 0xc0000000c0000000},
    {0xffffffffffffffff, 0x0000001e, 0xffffffffffffffff},
    {0x0000001f0000001f, 0x00000005, 0x0000001f0000001f},
    {0x0000002f0000002f, 0x00000005, 0x0000001f0000001f},
    {0x0000000f0000000f, 0x00000005, 0x0000000f0000000f},
    {0xffffffc0ffffffc0, 0x00000005, 0xffffffe0ffffffe0},
    {0xffffffe1ffffffe1, 0x00000005, 0xffffffe1ffffffe1},
};

/* uclip32 */
struct binary_calculation samples_uclip32[] = {
    {0x0000000100000001, 0x00000001, 0x0000000100000001},
    {0x0000000100000001, 0x00000002, 0x0000000100000001},
    {0x0000000100000001, 0x00000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000001f, 0x0000000100000001},
    {0xffffffffffffffff, 0x00000000, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000001f, 0x0000000000000000},
    {0x0000000000000000, 0x00000000, 0x0000000000000000},
    {0x0000003f0000003f, 0x00000006, 0x0000003f0000003f},
    {0x0000001f0000001f, 0x00000006, 0x0000001f0000001f},
    {0x0000004f0000004f, 0x00000006, 0x0000003f0000003f},
};

/* clrs32 */
struct unary_calculation samples_clrs32[] = {
    {0x0000000100000002, 0x0000001e0000001d},
    {0x0000000300000004, 0x0000001d0000001c},
    {0x0000000500000006, 0x0000001c0000001c},
    {0x0000000700000008, 0x0000001c0000001b},
    {0x000000090000000a, 0x0000001b0000001b},
    {0x0000000b0000000c, 0x0000001b0000001b},
    {0x0000000d0000000e, 0x0000001b0000001b},
    {0x0000000f00000010, 0x0000001b0000001a},
    {0xfffffff1fffffff2, 0x0000001b0000001b},
    {0xfffffff3fffffff4, 0x0000001b0000001b},
    {0xfffffff5fffffff6, 0x0000001b0000001b},
    {0xfffffff7fffffff8, 0x0000001b0000001c},
    {0xfffffff9fffffffa, 0x0000001c0000001c},
    {0xfffffffbfffffffc, 0x0000001c0000001d},
    {0xfffffffdfffffffe, 0x0000001d0000001e},
    {0xffffffffffffffff, 0x0000001f0000001f},
    {0x7ffffff17ffffff2, 0x0000000000000000},
    {0x7ffffff37ffffff4, 0x0000000000000000},
    {0x8000000180000002, 0x0000000000000000},
    {0x8000000380000004, 0x0000000000000000},
};

/* clz32 */
struct unary_calculation samples_clz32[] = {
    {0x0000000100000002, 0x0000001f0000001e},
    {0x0000000300000004, 0x0000001e0000001d},
    {0x0000000500000006, 0x0000001d0000001d},
    {0x0000000700000008, 0x0000001d0000001c},
    {0x000000090000000a, 0x0000001c0000001c},
    {0x0000000b0000000c, 0x0000001c0000001c},
    {0x0000000d0000000e, 0x0000001c0000001c},
    {0x0000000f00000010, 0x0000001c0000001b},
    {0xfffffff1fffffff2, 0x0000000000000000},
    {0xfffffff3fffffff4, 0x0000000000000000},
    {0xfffffff5fffffff6, 0x0000000000000000},
    {0xfffffff7fffffff8, 0x0000000000000000},
    {0xfffffff9fffffffa, 0x0000000000000000},
    {0xfffffffbfffffffc, 0x0000000000000000},
    {0xfffffffdfffffffe, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000000000000},
    {0x7ffffff17ffffff2, 0x0000000100000001},
    {0x7ffffff37ffffff4, 0x0000000100000001},
    {0x8000000180000002, 0x0000000000000000},
    {0x8000000380000004, 0x0000000000000000},
};

/* clo32 */
struct unary_calculation samples_clo32[] = {
    {0x0000000100000002, 0x0000000000000000},
    {0x0000000300000004, 0x0000000000000000},
    {0x0000000500000006, 0x0000000000000000},
    {0x0000000700000008, 0x0000000000000000},
    {0x000000090000000a, 0x0000000000000000},
    {0x0000000b0000000c, 0x0000000000000000},
    {0x0000000d0000000e, 0x0000000000000000},
    {0x0000000f00000010, 0x0000000000000000},
    {0xfffffff1fffffff2, 0x0000001c0000001c},
    {0xfffffff3fffffff4, 0x0000001c0000001c},
    {0xfffffff5fffffff6, 0x0000001c0000001c},
    {0xfffffff7fffffff8, 0x0000001c0000001d},
    {0xfffffff9fffffffa, 0x0000001d0000001d},
    {0xfffffffbfffffffc, 0x0000001d0000001e},
    {0xfffffffdfffffffe, 0x0000001e0000001f},
    {0xffffffffffffffff, 0x0000002000000020},
    {0x7ffffff17ffffff2, 0x0000000000000000},
    {0x7ffffff37ffffff4, 0x0000000000000000},
    {0x8000000180000002, 0x0000000100000001},
    {0x8000000380000004, 0x0000000100000001},
};

/* sclip16 */
struct binary_calculation samples_sclip16[] = {
    {0x0000000100000001, 0x00000001, 0x0000000100000001},
    {0x0001000100010001, 0x00000001, 0x0001000100010001},
    {0xffff0001ffff0001, 0x00000001, 0xffff0001ffff0001},
    {0xfffe0001fffe0001, 0x00000001, 0xfffe0001fffe0001},
    {0xfffd0010fffd0010, 0x00000002, 0xfffd0003fffd0003},
    {0xfffc0011fffc0011, 0x00000002, 0xfffc0003fffc0003},
    {0x0001000100010001, 0x0000000f, 0x0001000100010001},
    {0xffffffffffffffff, 0x0000000f, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000000f, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x0000000f, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x0000000f, 0x8000000080000000},
    {0x7ffe80017ffe8001, 0x0000000e, 0x3fffc0003fffc000},
    {0x000100ff000100ff, 0x00000008, 0x000100ff000100ff},
    {0x8001fe018001fe01, 0x00000008, 0xff00ff00ff00ff00},
    {0xfe01fe01fe01fe01, 0x00000008, 0xff00ff00ff00ff00},
};

/* uclip16 */
struct binary_calculation samples_uclip16[] = {
    {0x0000000100000001, 0x00000001, 0x0000000100000001},
    {0x0001000100010001, 0x00000001, 0x0001000100010001},
    {0xffff0001ffff0001, 0x00000001, 0x0000000100000001},
    {0xfffe0001fffe0001, 0x00000001, 0x0000000100000001},
    {0xfffd0010fffd0010, 0x00000002, 0x0000000300000003},
    {0xfffc0011fffc0011, 0x00000002, 0x0000000300000003},
    {0x0001000100010001, 0x0000000f, 0x0001000100010001},
    {0xffffffffffffffff, 0x0000000f, 0x0000000000000000},
    {0x0000000000000000, 0x0000000f, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x0000000f, 0x7fff00007fff0000},
    {0x8000000080000000, 0x0000000f, 0x0000000000000000},
    {0x7ffe80017ffe8001, 0x0000000e, 0x3fff00003fff0000},
    {0x000100ff000100ff, 0x00000008, 0x000100ff000100ff},
    {0x8001fe018001fe01, 0x00000008, 0x0000000000000000},
    {0xfe01fe01fe01fe01, 0x00000008, 0x0000000000000000},
};

/* pbsad */
struct binary_calculation samples_pbsad[] = {
    {0x4455667744556677, 0x0011223300112233, 0x0000000000000220},
    {0x0011223300112233, 0x4455667744556677, 0x0000000000000220},
    {0x4444444444444444, 0x4444444444444444, 0x0000000000000000},
    {0xffffffffffffffff, 0x7f7f7f7f7f7f7f7f, 0x0000000000000400},
    {0xffffffffffffffff, 0x0000000000000000, 0x00000000000007f8},
    {0x7f7f7f7f7f7f7f7f, 0x8080808080808080, 0x0000000000000008},
    {0xff7f0080ff7f0080, 0x7fff807f7fff807f, 0x0000000000000302},
    {0xff01807fff01807f, 0xff107f80ff107f80, 0x0000000000000022},
};

/* smaqa */
struct ternary_calculation samples_smaqa[] = {
    {0x0101010101010101, 0x4040404040404040, 0x0000000000000000, 0x0000010000000100},
    {0x4040404040404040, 0x0101010101010101, 0x0000010000000100, 0x0000020000000200},
    {0x0202020202020202, 0x4040404040404040, 0x8000000080000000, 0x8000020080000200},
    {0x0101010101010101, 0x8080808080808080, 0x7fffffff7fffffff, 0x7ffffdff7ffffdff},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000100000001, 0x0000000100000001},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x1000000010000000, 0x1000000410000004},
    {0x7fffffff7fffffff, 0x8080808080808080, 0x0000200000002000, 0xffffe200ffffe200},
    {0x8000000080000000, 0x7fff40007fff4000, 0xffffffffffffffff, 0xffffc07fffffc07f},
    {0x7fffffff7fffffff, 0x4000ff004000ff00, 0xffffffffffffffff, 0x00001fc000001fc0},
    {0x7f80ff017f80ff01, 0x40ff017f40ff017f, 0xffffffffffffffff, 0x000020bd000020bd},
};

/* umaqa */
struct ternary_calculation samples_umaqa[] = {
    {0x0101010101010101, 0x4040404040404040, 0x0000000000000000, 0x0000010000000100},
    {0x4040404040404040, 0x0101010101010101, 0x0000010000000100, 0x0000020000000200},
    {0x0202020202020202, 0x4040404040404040, 0x8000000080000000, 0x8000020080000200},
    {0x0101010101010101, 0x8080808080808080, 0x7fffffff7fffffff, 0x800001ff800001ff},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000100000001, 0x0000000100000001},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x1000000010000000, 0x1003f8041003f804},
    {0x7fffffff7fffffff, 0x8080808080808080, 0x0000200000002000, 0x0001de000001de00},
    {0x8000000080000000, 0x7fff40007fff4000, 0xffffffffffffffff, 0x00003f7f00003f7f},
    {0x7fffffff7fffffff, 0x4000ff004000ff00, 0xffffffffffffffff, 0x00011dc000011dc0},
    {0x7f80ff017f80ff01, 0x40ff017f40ff017f, 0xffffffffffffffff, 0x0000a0bd0000a0bd},
};

/* smaqa.su */
struct ternary_calculation samples_smaqa_su[] = {
    {0x0101010101010101, 0x4040404040404040, 0x0000000000000000, 0x0000010000000100},
    {0x4040404040404040, 0x0101010101010101, 0x0000010000000100, 0x0000020000000200},
    {0x0202020202020202, 0x4040404040404040, 0x8000000080000000, 0x8000020080000200},
    {0x0101010101010101, 0x8080808080808080, 0x7fffffff7fffffff, 0x800001ff800001ff},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000100000001, 0x0000000100000001},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x1000000010000000, 0x0ffffc040ffffc04},
    {0x7fffffff7fffffff, 0x8080808080808080, 0x0000200000002000, 0x00005e0000005e00},
    {0x8000000080000000, 0x7fff40007fff4000, 0xffffffffffffffff, 0xffffc07fffffc07f},
    {0x7fffffff7fffffff, 0x4000ff004000ff00, 0xffffffffffffffff, 0x00001ec000001ec0},
    {0x7f80ff017f80ff01, 0x40ff017f40ff017f, 0xffffffffffffffff, 0xffffa0bdffffa0bd},
};

/* kabs8*/
struct unary_calculation samples_kabs8[] = {
    {0x0101010101010101, 0x0101010101010101},
    {0x0000000100000001, 0x0000000100000001},
    {0x0001000100010001, 0x0001000100010001},
    {0x8080808080808080, 0x7f7f7f7f7f7f7f7f},
    {0x8000000080000000, 0x7f0000007f000000},
    {0x8000800080008000, 0x7f007f007f007f00},
    {0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0x0101010101010101},
    {0x7f7f7f7f7f7f7f7f, 0x7f7f7f7f7f7f7f7f},
    {0x7fffffff7fffffff, 0x7f0101017f010101},
    {0x7fff7fff7fff7fff, 0x7f017f017f017f01},
    {0x80807f0280807f02, 0x7f7f7f027f7f7f02},
    {0x8181818181818181, 0x7f7f7f7f7f7f7f7f},
    {0x8080808080808080, 0x7f7f7f7f7f7f7f7f},
    {0x7f7f7f7f7f7f7f7f, 0x7f7f7f7f7f7f7f7f},
};

/* clrs8*/
struct unary_calculation samples_clrs8[] = {
    {0x0102030405060708, 0x0605050404040403},
    {0x090a0b0c0d0e0f10, 0x0303030303030302},
    {0xf1f2f3f4f5f6f7f8, 0x0303030303030304},
    {0xf9fafbfcfdfeffff, 0x0404040505060707},
    {0x8081828384858687, 0x0000000000000000},
    {0x7071727374757677, 0x0000000000000000},
    {0x7f7f7f7f7f7f7f7f, 0x0000000000000000},
};

/* clz8*/
struct unary_calculation samples_clz8[] = {
    {0x0102030405060708, 0x0706060505050504},
    {0x090a0b0c0d0e0f10, 0x0404040404040403},
    {0xf1f2f3f4f5f6f7f8, 0x0000000000000000},
    {0xf9fafbfcfdfeffff, 0x0000000000000000},
    {0x8081828384858687, 0x0000000000000000},
    {0x7071727374757677, 0x0101010101010101},
    {0x7f7f7f7f7f7f7f7f, 0x0101010101010101},
};

/* clo8*/
struct unary_calculation samples_clo8[] = {
    {0x0102030405060708, 0x0000000000000000},
    {0x090a0b0c0d0e0f10, 0x0000000000000000},
    {0xf1f2f3f4f5f6f7f8, 0x0404040404040405},
    {0xf9fafbfcfdfeffff, 0x0505050606070808},
    {0x8081828384858687, 0x0101010101010101},
    {0x7071727374757677, 0x0000000000000000},
    {0x7f7f7f7f7f7f7f7f, 0x0000000000000000},
};

/* sunpkd810 */
struct unary_calculation samples_sunpkd810[] = {
    {0x0102030405060708, 0x0003000400070008},
    {0x090a0b0c0d0e0f10, 0x000b000c000f0010},
    {0xf1f2f3f4f5f6f7f8, 0xfff3fff4fff7fff8},
    {0xf9fafbfcfdfeffff, 0xfffbfffcffffffff},
    {0x8081828384858687, 0xff82ff83ff86ff87},
    {0x7071727374757677, 0x0072007300760077},
    {0x78797a7b7c7d7e7f, 0x007a007b007e007f},
};

/* sunpkd820 */
struct unary_calculation samples_sunpkd820[] = {
    {0x0102030405060708, 0x0002000400060008},
    {0x090a0b0c0d0e0f10, 0x000a000c000e0010},
    {0xf1f2f3f4f5f6f7f8, 0xfff2fff4fff6fff8},
    {0xf9fafbfcfdfeffff, 0xfffafffcfffeffff},
    {0x8081828384858687, 0xff81ff83ff85ff87},
    {0x7071727374757677, 0x0071007300750077},
    {0x78797a7b7c7d7e7f, 0x0079007b007d007f},
};

/* sunpkd830 */
struct unary_calculation samples_sunpkd830[] = {
    {0x0102030405060708, 0x0001000400050008},
    {0x090a0b0c0d0e0f10, 0x0009000c000d0010},
    {0xf1f2f3f4f5f6f7f8, 0xfff1fff4fff5fff8},
    {0xf9fafbfcfdfeffff, 0xfff9fffcfffdffff},
    {0x8081828384858687, 0xff80ff83ff84ff87},
    {0x7071727374757677, 0x0070007300740077},
    {0x78797a7b7c7d7e7f, 0x0078007b007c007f},
};

/* sunpkd831 */
struct unary_calculation samples_sunpkd831[] = {
    {0x0102030405060708, 0x0001000300050007},
    {0x090a0b0c0d0e0f10, 0x0009000b000d000f},
    {0xf1f2f3f4f5f6f7f8, 0xfff1fff3fff5fff7},
    {0xf9fafbfcfdfeffff, 0xfff9fffbfffdffff},
    {0x8081828384858687, 0xff80ff82ff84ff86},
    {0x7071727374757677, 0x0070007200740076},
    {0x78797a7b7c7d7e7f, 0x0078007a007c007e},
};

/* sunpkd832 */
struct unary_calculation samples_sunpkd832[] = {
    {0x0102030405060708, 0x0001000200050006},
    {0x090a0b0c0d0e0f10, 0x0009000a000d000e},
    {0xf1f2f3f4f5f6f7f8, 0xfff1fff2fff5fff6},
    {0xf9fafbfcfdfeffff, 0xfff9fffafffdfffe},
    {0x8081828384858687, 0xff80ff81ff84ff85},
    {0x7071727374757677, 0x0070007100740075},
    {0x78797a7b7c7d7e7f, 0x00780079007c007d},
};

/* zunpkd810 */
struct unary_calculation samples_zunpkd810[] = {
    {0x0102030405060708, 0x0003000400070008},
    {0x090a0b0c0d0e0f10, 0x000b000c000f0010},
    {0xf1f2f3f4f5f6f7f8, 0x00f300f400f700f8},
    {0xf9fafbfcfdfeffff, 0x00fb00fc00ff00ff},
    {0x8081828384858687, 0x0082008300860087},
    {0x7071727374757677, 0x0072007300760077},
    {0x78797a7b7c7d7e7f, 0x007a007b007e007f},
};

/* zunpkd820 */
struct unary_calculation samples_zunpkd820[] = {
    {0x0102030405060708, 0x0002000400060008},
    {0x090a0b0c0d0e0f10, 0x000a000c000e0010},
    {0xf1f2f3f4f5f6f7f8, 0x00f200f400f600f8},
    {0xf9fafbfcfdfeffff, 0x00fa00fc00fe00ff},
    {0x8081828384858687, 0x0081008300850087},
    {0x7071727374757677, 0x0071007300750077},
    {0x78797a7b7c7d7e7f, 0x0079007b007d007f},
};

/* zunpkd830 */
struct unary_calculation samples_zunpkd830[] = {
    {0x0102030405060708, 0x0001000400050008},
    {0x090a0b0c0d0e0f10, 0x0009000c000d0010},
    {0xf1f2f3f4f5f6f7f8, 0x00f100f400f500f8},
    {0xf9fafbfcfdfeffff, 0x00f900fc00fd00ff},
    {0x8081828384858687, 0x0080008300840087},
    {0x7071727374757677, 0x0070007300740077},
    {0x78797a7b7c7d7e7f, 0x0078007b007c007f},
};

/* zunpkd831 */
struct unary_calculation samples_zunpkd831[] = {
    {0x0102030405060708, 0x0001000300050007},
    {0x090a0b0c0d0e0f10, 0x0009000b000d000f},
    {0xf1f2f3f4f5f6f7f8, 0x00f100f300f500f7},
    {0xf9fafbfcfdfeffff, 0x00f900fb00fd00ff},
    {0x8081828384858687, 0x0080008200840086},
    {0x7071727374757677, 0x0070007200740076},
    {0x78797a7b7c7d7e7f, 0x0078007a007c007e},
};

/* zunpkd832 */
struct unary_calculation samples_zunpkd832[] = {
    {0x0102030405060708, 0x0001000200050006},
    {0x090a0b0c0d0e0f10, 0x0009000a000d000e},
    {0xf1f2f3f4f5f6f7f8, 0x00f100f200f500f6},
    {0xf9fafbfcfdfeffff, 0x00f900fa00fd00fe},
    {0x8081828384858687, 0x0080008100840085},
    {0x7071727374757677, 0x0070007100740075},
    {0x78797a7b7c7d7e7f, 0x00780079007c007d},
};

/* kabs16 */
struct unary_calculation samples_kabs16[] = {
    {0x0101010101010101, 0x0101010101010101},
    {0x0000000100000001, 0x0000000100000001},
    {0x0001000100010001, 0x0001000100010001},
    {0x8080808080808080, 0x7f807f807f807f80},
    {0x8000000080000000, 0x7fff00007fff0000},
    {0x8000800080008000, 0x7fff7fff7fff7fff},
    {0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0x0001000100010001},
    {0x7f7f7f7f7f7f7f7f, 0x7f7f7f7f7f7f7f7f},
    {0x7fffffff7fffffff, 0x7fff00017fff0001},
    {0x7fff7fff7fff7fff, 0x7fff7fff7fff7fff},
    {0x8000001f8000001f, 0x7fff001f7fff001f},
    {0xf00100fff00100ff, 0x0fff00ff0fff00ff},
    {0x8001800180018001, 0x7fff7fff7fff7fff},
};

/* clrs16 */
struct unary_calculation samples_clrs16[] = {
    {0x0001000200030004, 0x000e000d000d000c},
    {0x0005000600070008, 0x000c000c000c000b},
    {0x0009000a000b000c, 0x000b000b000b000b},
    {0x000d000e000f0010, 0x000b000b000b000a},
    {0xfff1fff2fff3fff4, 0x000b000b000b000b},
    {0xfff5fff6fff7fff8, 0x000b000b000b000c},
    {0xfff9fffafffbfffc, 0x000c000c000c000d},
    {0xfffdfffeffffffff, 0x000d000e000f000f},
    {0x7ff17ff27ff37ff4, 0x0000000000000000},
    {0x8001800280008003, 0x0000000000000000},
};

/* clz16 */
struct unary_calculation samples_clz16[] = {
    {0x0001000200030004, 0x000f000e000e000d},
    {0x0005000600070008, 0x000d000d000d000c},
    {0x0009000a000b000c, 0x000c000c000c000c},
    {0x000d000e000f0010, 0x000c000c000c000b},
    {0xfff1fff2fff3fff4, 0x0000000000000000},
    {0xfff5fff6fff7fff8, 0x0000000000000000},
    {0xfff9fffafffbfffc, 0x0000000000000000},
    {0xfffdfffeffffffff, 0x0000000000000000},
    {0x7ff17ff27ff37ff4, 0x0001000100010001},
    {0x8001800280008003, 0x0000000000000000},
};

/* clo16 */
struct unary_calculation samples_clo16[] = {
    {0x0001000200030004, 0x0000000000000000},
    {0x0005000600070008, 0x0000000000000000},
    {0x0009000a000b000c, 0x0000000000000000},
    {0x000d000e000f0010, 0x0000000000000000},
    {0xfff1fff2fff3fff4, 0x000c000c000c000c},
    {0xfff5fff6fff7fff8, 0x000c000c000c000d},
    {0xfff9fffafffbfffc, 0x000d000d000d000e},
    {0xfffdfffeffffffff, 0x000e000f00100010},
    {0x7ff17ff27ff37ff4, 0x0000000000000000},
    {0x8001800280008003, 0x0001000100010001},
};

/* kabsw */
struct unary_calculation samples_kabsw[] = {
    {0x0101010101010101, 0x0000000001010101},
    {0x0000000100000001, 0x0000000000000001},
    {0x0001000100010001, 0x0000000000010001},
    {0x8080808080808080, 0x000000007f7f7f80},
    {0x8000000080000000, 0x000000007fffffff},
    {0x8000800080008000, 0x000000007fff8000},
    {0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000000000001},
    {0x7f7f7f7f7f7f7f7f, 0x000000007f7f7f7f},
    {0x7fffffff7fffffff, 0x000000007fffffff},
    {0x7fff7fff7fff7fff, 0x000000007fff7fff},
    {0x0000003f0000003f, 0x000000000000003f},
    {0xf000001ff000001f, 0x000000000fffffe1},
};

/* bpick */
struct ternary_calculation samples_bpick[] = {
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000, 0xffffffffffffffff},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0xffff0000ffff0000, 0x0000ffff0000ffff, 0xffff0000ffff0000, 0xffffffffffffffff},
    {0xffff0000ffff0000, 0x0000ffff0000ffff, 0x0000ffff0000ffff, 0x0000000000000000},
    {0x0000000000000000, 0xffffffffffffffff, 0xaaaaaaaaaaaaaaaa, 0x5555555555555555},
    {0x0000000000000000, 0xffffffffffffffff, 0x5555555555555555, 0xaaaaaaaaaaaaaaaa},
};

/* wext */
struct binary64_ul_ul_calculation samples_wext[] = {
    {0x89abcdef89abcdef, 0x0000000000000008, 0xffffffffef89abcd},
    {0x89abcdef89abcdef, 0x0000000000000004, 0xfffffffff89abcde},
    {0x0000000000000000, 0x0000000000000002, 0x0000000000000000},
    {0xffffffffffffffff, 0x000000000000001f, 0xffffffffffffffff},
    {0x0101010101010101, 0x0000000000000004, 0x0000000010101010},
};

/* wexti */
struct binary64_32_ul_calculation samples_wexti[] = {
    {0x89abcdef89abcdef, 0x00000008, 0xffffffffef89abcd},
    {0x89abcdef89abcdef, 0x00000004, 0xfffffffff89abcde},
    {0x0000000000000000, 0x00000002, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000001f, 0xffffffffffffffff},
    {0x0101010101010101, 0x00000004, 0x0000000010101010},
};

/* pbsada */
struct ternary_calculation samples_pbsada[] = {
    {0x4455667744556677, 0x0011223300112233, 0x0000000000000000, 0x0000000000000220},
    {0x0011223300112233, 0x4455667744556677, 0x0000000000000000, 0x0000000000000220},
    {0x4444444444444444, 0x4444444444444444, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x7f7f7f7f7f7f7f7f, 0xffffffffffffffff, 0x00000000000003ff},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000, 0x00000000000007f8},
    {0x7f7f7f7f7f7f7f7f, 0x8080808080808080, 0x0000000000000000, 0x0000000000000008},
    {0xff7f0080ff7f0080, 0x7fff807f7fff807f, 0xffffffffffffffff, 0x0000000000000301},
    {0xff01807fff01807f, 0xff107f80ff107f80, 0x8000000000000000, 0x8000000000000022},
};

/* umsr64 */
struct ternary_ul_ul_64_calculation samples_umsr64[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000001, 0xffffffffffffffff},
    {0x0000000100000001, 0x0000000100000001, 0xffffffffffffffff, 0xfffffffffffffffd},
    {0x0000000100000001, 0x0000000100000001, 0x8000000000000000, 0x7ffffffffffffffe},
    {0x0000000100000001, 0x0000000100000001, 0x7fffffffffffffff, 0x7ffffffffffffffd},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffe00000001},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000000000000, 0x7ffffffe00000002},
    {0x0000000100000001, 0xffffffffffffffff, 0x7fffffffffffffff, 0x7ffffffe00000001},
    {0x8000000080000000, 0x8000000080000000, 0xffffffffffffffff, 0x7fffffffffffffff},
    {0x8000000080000000, 0x8000000080000000, 0x8000000000000000, 0x0000000000000000},
    {0x8000000080000000, 0x8000000080000000, 0x7fffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0x00000002fffffffd},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x8000000000000000, 0x80000002fffffffe},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x0000000000000000, 0x00000002fffffffe},
    {0x0000000000000000, 0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000100000001, 0x000000007fffffff, 0x000000007ffffffd},
};

/* smsr64 */
struct ternary_ul_ul_64_calculation samples_smsr64[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000001, 0xffffffffffffffff},
    {0x0000000100000001, 0x0000000100000001, 0xffffffffffffffff, 0xfffffffffffffffd},
    {0x0000000100000001, 0x0000000100000001, 0x8000000000000000, 0x7ffffffffffffffe},
    {0x0000000100000001, 0x0000000100000001, 0x7fffffffffffffff, 0x7ffffffffffffffd},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000001},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000000000000, 0x8000000000000002},
    {0x0000000100000001, 0xffffffffffffffff, 0x7fffffffffffffff, 0x8000000000000001},
    {0x8000000080000000, 0x8000000080000000, 0xffffffffffffffff, 0x7fffffffffffffff},
    {0x8000000080000000, 0x8000000080000000, 0x8000000000000000, 0x0000000000000000},
    {0x8000000080000000, 0x8000000080000000, 0x7fffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0x00000000fffffffd},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x8000000000000000, 0x80000000fffffffe},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x0000000000000000, 0x00000000fffffffe},
    {0x0000000000000000, 0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000100000001, 0x000000007fffffff, 0x000000007ffffffd},
};

/* kdmabb */
struct ternary_calculation samples_kdmabb[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000001, 0x0000000000000003},
    {0x0000000100000001, 0x0000000100000001, 0xffffffffffffffff, 0x0000000000000001},
    {0x0000000100000001, 0x0000000100000001, 0x8000000080000000, 0xffffffff80000002},
    {0x0000000100000001, 0x0000000100000001, 0x7fffffff7fffffff, 0x000000007fffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffffffffffd},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000080000000, 0xffffffff80000000},
    {0x0000000100000001, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x000000007ffffffd},
    {0x8000800080008000, 0x8000800080008000, 0xffffffffffffffff, 0x000000007ffffffe},
    {0x8000800080008000, 0x8000800080008000, 0x8000000080000000, 0xffffffffffffffff},
    {0x8000800080008000, 0x8000800080008000, 0x7fffffff7fffffff, 0x000000007fffffff},
    {0x7fff7fff7fff7fff, 0xffff7fffffff7fff, 0xffffffffffffffff, 0x000000007ffe0001},
    {0x7fff7fff7fff7fff, 0xffff7fffffff7fff, 0x8000000080000000, 0xfffffffffffe0002},
    {0x7fff7fff7fff7fff, 0xffff7fffffff7fff, 0x0000000000000000, 0x000000007ffe0002},
    {0x0000000000000000, 0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
};

/* kdmabt */
struct ternary_calculation samples_kdmabt[] = {
    {0x0000000100000001, 0x0000000100010000, 0x0000000000000001, 0x0000000000000003},
    {0x0000000100000001, 0x0000000100010000, 0xffffffffffffffff, 0x0000000000000001},
    {0x0000000100000001, 0x0000000100010000, 0x8000000080000000, 0xffffffff80000002},
    {0x0000000100000001, 0x0000000100010000, 0x7fffffff7fffffff, 0x000000007fffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffffffffffd},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000080000000, 0xffffffff80000000},
    {0x0000000100000001, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x000000007ffffffd},
    {0x8000800080008000, 0x8000800080008000, 0xffffffffffffffff, 0x000000007ffffffe},
    {0x8000800080008000, 0x8000800080008000, 0x8000000080000000, 0xffffffffffffffff},
    {0x8000800080008000, 0x8000800080008000, 0x7fffffff7fffffff, 0x000000007fffffff},
    {0x7fff7fff7fff7fff, 0xffff7fff7fffffff, 0xffffffffffffffff, 0x000000007ffe0001},
    {0x7fff7fff7fff7fff, 0xffff7fff7fffffff, 0x8000000080000000, 0xfffffffffffe0002},
    {0x7fff7fff7fff7fff, 0xffff7fff7fffffff, 0x0000000000000000, 0x000000007ffe0002},
    {0x0000000000000000, 0x0000000100010000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
};

/* kdmatt */
struct ternary_calculation samples_kdmatt[] = {
    {0x0000000100010000, 0x0000000100010000, 0x0000000000000001, 0x0000000000000003},
    {0x0000000100010000, 0x0000000100010000, 0xffffffffffffffff, 0x0000000000000001},
    {0x0000000100010000, 0x0000000100010000, 0x8000000080000000, 0xffffffff80000002},
    {0x0000000100010000, 0x0000000100010000, 0x7fffffff7fffffff, 0x000000007fffffff},
    {0x0000000100010000, 0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffffffffffd},
    {0x0000000100010000, 0xffffffffffffffff, 0x8000000080000000, 0xffffffff80000000},
    {0x0000000100010000, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x000000007ffffffd},
    {0x8000800080008000, 0x8000800080008000, 0xffffffffffffffff, 0x000000007ffffffe},
    {0x8000800080008000, 0x8000800080008000, 0x8000000080000000, 0xffffffffffffffff},
    {0x8000800080008000, 0x8000800080008000, 0x7fffffff7fffffff, 0x000000007fffffff},
    {0x7fff7fff7fff7fff, 0xffff7fff7fffffff, 0xffffffffffffffff, 0x000000007ffe0001},
    {0x7fff7fff7fff7fff, 0xffff7fff7fffffff, 0x8000000080000000, 0xfffffffffffe0002},
    {0x7fff7fff7fff7fff, 0xffff7fff7fffffff, 0x0000000000000000, 0x000000007ffe0002},
    {0x0000000000000000, 0x0000000100010000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100010000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
};

/* kmar64 */
struct ternary_ul_ul_64_calculation samples_kmar64[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000001, 0x0000000000000003},
    {0x0000000100000001, 0x0000000100000001, 0xffffffffffffffff, 0x0000000000000001},
    {0x0000000100000001, 0x0000000100000001, 0x8000000000000000, 0x8000000000000002},
    {0x0000000100000001, 0x0000000100000001, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffffffffffd},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000000000000, 0x8000000000000000},
    {0x0000000100000001, 0xffffffffffffffff, 0x7fffffffffffffff, 0x7ffffffffffffffd},
    {0x8000000080000000, 0x8000000080000000, 0xffffffffffffffff, 0x7fffffffffffffff},
    {0x8000000080000000, 0x8000000080000000, 0x8000000000000000, 0x0000000000000000},
    {0x8000000080000000, 0x8000000080000000, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffff00000001},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x8000000000000000, 0x8000000000000000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x0000000000000000, 0xffffffff00000002},
    {0x0000000000000000, 0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
};

/* ukmar64 */
struct ternary_calculation samples_ukmar64[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000001, 0x0000000000000003},
    {0x0000000100000001, 0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000100000001, 0x0000000100000001, 0x8000000000000000, 0x8000000000000002},
    {0x0000000100000001, 0x0000000100000001, 0x7fffffffffffffff, 0x8000000000000001},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000000000000, 0x80000001fffffffe},
    {0x0000000100000001, 0xffffffffffffffff, 0x7fffffffffffffff, 0x80000001fffffffd},
    {0x8000000080000000, 0x8000000080000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x8000000080000000, 0x8000000080000000, 0x8000000000000000, 0xffffffffffffffff},
    {0x8000000080000000, 0x8000000080000000, 0x7fffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x8000000000000000, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x0000000000000000, 0xfffffffd00000002},
    {0x0000000000000000, 0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
};

/* kmsr64 */
struct ternary_ul_ul_64_calculation samples_kmsr64[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000001, 0xffffffffffffffff},
    {0x0000000100000001, 0x0000000100000001, 0xffffffffffffffff, 0xfffffffffffffffd},
    {0x0000000100000001, 0x0000000100000001, 0x8000000000000000, 0x8000000000000000},
    {0x0000000100000001, 0x0000000100000001, 0x7fffffffffffffff, 0x7ffffffffffffffd},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000001},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000000000000, 0x8000000000000002},
    {0x0000000100000001, 0xffffffffffffffff, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x8000000080000000, 0x8000000080000000, 0xffffffffffffffff, 0x8000000000000000},
    {0x8000000080000000, 0x8000000080000000, 0x8000000000000000, 0x8000000000000000},
    {0x8000000080000000, 0x8000000080000000, 0x7fffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0x00000000fffffffd},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x8000000000000000, 0x80000000fffffffe},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x0000000000000000, 0x00000000fffffffe},
    {0x0000000000000000, 0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000100000001, 0x000000007fffffff, 0x000000007ffffffd},
};

/* ukmsr64 */
struct ternary_calculation samples_ukmsr64[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000001, 0x0000000000000000},
    {0x0000000100000001, 0x0000000100000001, 0xffffffffffffffff, 0xfffffffffffffffd},
    {0x0000000100000001, 0x0000000100000001, 0x8000000000000000, 0x7ffffffffffffffe},
    {0x0000000100000001, 0x0000000100000001, 0x7fffffffffffffff, 0x7ffffffffffffffd},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffe00000001},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000000000000, 0x7ffffffe00000002},
    {0x0000000100000001, 0xffffffffffffffff, 0x7fffffffffffffff, 0x7ffffffe00000001},
    {0x8000000080000000, 0x8000000080000000, 0xffffffffffffffff, 0x7fffffffffffffff},
    {0x8000000080000000, 0x8000000080000000, 0x8000000000000000, 0x0000000000000000},
    {0x8000000080000000, 0x8000000080000000, 0x7fffffffffffffff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0x00000002fffffffd},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x8000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000100000001, 0x000000007fffffff, 0x000000007ffffffd},
};

/* kwmmul */
struct binary_calculation samples_kwmmul[] = {
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x7ffffffe7ffffffe},
    {0x8000000080000000, 0x8000000080000000, 0x7fffffff7fffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x8000000180000001},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x8000000180000001},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x7fffffff7fffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x8000000080000000, 0xffffffffffffffff, 0x0000000100000001},
    {0xffffffffffffffff, 0x8000000080000000, 0x0000000100000001},
    {0x0000000000000000, 0x8000000080000000, 0x0000000000000000},
    {0x8000000080000000, 0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0x8000000080000000, 0x0000000100000001, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x8000000080000000, 0x8000000180000001, 0x7fffffff7fffffff},
};

/* kwmmul.u */
struct binary_calculation samples_kwmmul_u[] = {
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x7ffffffe7ffffffe},
    {0x8000000080000000, 0x8000000080000000, 0x7fffffff7fffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x8000000180000001},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x8000000180000001},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x7fffffff7fffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x8000000080000000, 0xffffffffffffffff, 0x0000000100000001},
    {0xffffffffffffffff, 0x8000000080000000, 0x0000000100000001},
    {0x0000000000000000, 0x8000000080000000, 0x0000000000000000},
    {0x8000000080000000, 0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x7fff80007fff8000, 0x8000800080008000, 0x8001000080010000},
    {0x8000000080000000, 0x0000000100000001, 0xffffffffffffffff},
    {0x07ffffff07ffffff, 0x0fffffff0fffffff, 0x0100000001000000},
};

/* kmmac */
struct ternary_calculation samples_kmmac[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000100000001, 0x0000000100000001, 0x8000000080000000, 0x8000000080000000},
    {0x0000000100000001, 0x0000000100000001, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffefffffffe},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0x0000000100000001, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7ffffffe7ffffffe},
    {0x8000000080000000, 0x8000000080000000, 0xffffffffffffffff, 0x3fffffff3fffffff},
    {0x8000000080000000, 0x8000000080000000, 0x8000000080000000, 0xc0000000c0000000},
    {0x8000000080000000, 0x8000000080000000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffefffffffe},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7ffffffe7ffffffe},
    {0x0000000000000000, 0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x0000000100000001, 0x4000000040000000},
    {0x07ffffff07ffffff, 0x0fffffff0fffffff, 0xc0000000c0000000, 0xc07fffffc07fffff},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x3fffffff3fffffff},
};

/* kmmsb */
struct ternary_calculation samples_kmmsb[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000100000001, 0x0000000100000001, 0x8000000080000000, 0x8000000080000000},
    {0x0000000100000001, 0x0000000100000001, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000080000000, 0x8000000180000001},
    {0x0000000100000001, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x8000000080000000, 0xffffffffffffffff, 0xbfffffffbfffffff},
    {0x8000000080000000, 0x8000000080000000, 0x8000000080000000, 0x8000000080000000},
    {0x8000000080000000, 0x8000000080000000, 0x7fffffff7fffffff, 0x3fffffff3fffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x8000000080000000, 0x8000000180000001},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000000000000, 0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x8000000080000000, 0x8000000080000000},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x4000000040000000},
};

/* kmmac.u */
struct ternary_calculation samples_kmmac_u[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000100000001, 0x0000000100000001, 0x8000000080000000, 0x8000000080000000},
    {0x0000000100000001, 0x0000000100000001, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0x0000000100000001, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x8000000080000000, 0xffffffffffffffff, 0x3fffffff3fffffff},
    {0x8000000080000000, 0x8000000080000000, 0x8000000080000000, 0xc0000000c0000000},
    {0x8000000080000000, 0x8000000080000000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000000000000, 0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x0000000200000002, 0x8000000080000000, 0x8000000080000000},
};

/* kmmsb.u */
struct ternary_calculation samples_kmmsb_u[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000100000001, 0x0000000100000001, 0x8000000080000000, 0x8000000080000000},
    {0x0000000100000001, 0x0000000100000001, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0x0000000100000001, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x8000000080000000, 0xffffffffffffffff, 0xbfffffffbfffffff},
    {0x8000000080000000, 0x8000000080000000, 0x8000000080000000, 0x8000000080000000},
    {0x8000000080000000, 0x8000000080000000, 0x7fffffff7fffffff, 0x3fffffff3fffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000000000000, 0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0x0000000200000002, 0x8000000080000000, 0x8000000080000000},
};

/* smmwb */
struct binary_calculation samples_smmwb[] = {
    {0x0000000100000001, 0x0001000100010001, 0x0000000000000000},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0001000100010001, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fff7fff7fff7fff, 0xffffffffffffffff},
    {0x8000000080000000, 0x8000800080008000, 0x4000000040000000},
    {0x8000000080000000, 0x7fff7fff7fff7fff, 0xc0008000c0008000},
    {0x8000000080000000, 0xffffffffffffffff, 0x0000800000008000},
    {0x7fffffff7fffffff, 0x0001000100010001, 0x00007fff00007fff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffff8000ffff8000},
    {0x7fffffff7fffffff, 0x7fff7fff7fff7fff, 0x3fff7fff3fff7fff},
    {0x7fffffff7fffffff, 0x8000800080008000, 0xc0000000c0000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffff7fffffff7fff, 0x3fff7fff3fff7fff},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0xffff8000ffff8000},
    {0x7fffffff7fffffff, 0x7fff80007fff8000, 0xc0000000c0000000},
};

/* smmwb.u */
struct binary_calculation samples_smmwb_u[] = {
    {0x0000000100000001, 0x0001000100010001, 0x0000000000000000},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x0000000100000001, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x0001000100010001, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x8000000080000000, 0x7fff7fff7fff7fff, 0xc0008000c0008000},
    {0x8000000080000000, 0xffffffffffffffff, 0x0000800000008000},
    {0x7fffffff7fffffff, 0x0001000100010001, 0x0000800000008000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffff8000ffff8000},
    {0x7fffffff7fffffff, 0x7fff7fff7fff7fff, 0x3fff80003fff8000},
    {0x7fffffff7fffffff, 0x8000800080008000, 0xc0000001c0000001},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x0000ffff0000ffff, 0xffff8000ffff8000},
    {0x7fffffff7fffffff, 0x00007fff00007fff, 0x3fff80003fff8000},
    {0x8000000080000000, 0x0000ffff0000ffff, 0x0000800000008000},
    {0x8000800080008000, 0x0000ffff0000ffff, 0x0000800000008000},
};

/* smmwt */
struct binary_calculation samples_smmwt[] = {
    {0x0000000100000001, 0x0001000100010001, 0x0000000000000000},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0001000100010001, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fff7fff7fff7fff, 0xffffffffffffffff},
    {0x8000000080000000, 0x8000800080008000, 0x4000000040000000},
    {0x8000000080000000, 0x7fff7fff7fff7fff, 0xc0008000c0008000},
    {0x8000000080000000, 0xffffffffffffffff, 0x0000800000008000},
    {0x7fffffff7fffffff, 0x0001000100010001, 0x00007fff00007fff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffff8000ffff8000},
    {0x7fffffff7fffffff, 0x7fff7fff7fff7fff, 0x3fff7fff3fff7fff},
    {0x7fffffff7fffffff, 0x8000800080008000, 0xc0000000c0000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x00007fff00007fff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x7fff00007fff0000, 0x3fff7fff3fff7fff},
    {0x7fffffff7fffffff, 0x8000000180000001, 0xc0000000c0000000},
};

/* smmwt.u */
struct binary_calculation samples_smmwt_u[] = {
    {0x0000000100000001, 0x0001000100010001, 0x0000000000000000},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x0000000100000001, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x0001000100010001, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x8000000080000000, 0x8000800080008000, 0x4000000040000000},
    {0x8000000080000000, 0x7fff7fff7fff7fff, 0xc0008000c0008000},
    {0x8000000080000000, 0xffffffffffffffff, 0x0000800000008000},
    {0x7fffffff7fffffff, 0x0001000100010001, 0x0000800000008000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffff8000ffff8000},
    {0x7fffffff7fffffff, 0x7fff7fff7fff7fff, 0x3fff80003fff8000},
    {0x7fffffff7fffffff, 0x8000800080008000, 0xc0000001c0000001},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x7fff00007fff0000, 0x3fff80003fff8000},
    {0x7fffffff7fffffff, 0x80007fff80007fff, 0xc0000001c0000001},
    {0x8000000080000000, 0x7fff80007fff8000, 0xc0008000c0008000},
};

/* kmmwb2 */
struct binary_calculation samples_kmmwb2[] = {
    {0x0000000100000001, 0x0001000100010001, 0x0000000000000000},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0001000100010001, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fff7fff7fff7fff, 0xffffffffffffffff},
    {0x8000000080000000, 0x8000800080008000, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x7fff7fff7fff7fff, 0x8001000080010000},
    {0x8000000080000000, 0xffffffffffffffff, 0x0001000000010000},
    {0x7fffffff7fffffff, 0x0001000100010001, 0x0000ffff0000ffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffff0000ffff0000},
    {0x7fffffff7fffffff, 0x7fff7fff7fff7fff, 0x7ffeffff7ffeffff},
    {0x7fffffff7fffffff, 0x8000800080008000, 0x8000000180000001},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x8000000080000000, 0x7fff80007fff8000, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0xffff7fffffff7fff, 0x7ffeffff7ffeffff},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0xffff0000ffff0000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x0001000000010000},
};

/* kmmwb2.u */
struct binary_calculation samples_kmmwb2_u[] = {
    {0x0000000100000001, 0x0001000100010001, 0x0000000000000000},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x0000000100000001},
    {0x0000000100000001, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x0001000100010001, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fff7fff7fff7fff, 0xffffffffffffffff},
    {0x8000000080000000, 0x8000800080008000, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x7fff7fff7fff7fff, 0x8001000080010000},
    {0x8000000080000000, 0xffffffffffffffff, 0x0001000000010000},
    {0x7fffffff7fffffff, 0x0001000100010001, 0x0001000000010000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffff0000ffff0000},
    {0x7fffffff7fffffff, 0x7fff7fff7fff7fff, 0x7ffeffff7ffeffff},
    {0x7fffffff7fffffff, 0x8000800080008000, 0x8000000180000001},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffff7fffffff7fff, 0x7ffeffff7ffeffff},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0xffff0000ffff0000},
    {0x0000ffff0000ffff, 0x0000ffff0000ffff, 0xfffffffefffffffe},
    {0x8000000080000000, 0x7fff80007fff8000, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x80007fff80007fff, 0x8001000080010000},
};

/* kmmwt2 */
struct binary_calculation samples_kmmwt2[] = {
    {0x0000000100000001, 0x0001000100010001, 0x0000000000000000},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0001000100010001, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fff7fff7fff7fff, 0xffffffffffffffff},
    {0x8000000080000000, 0x8000800080008000, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x7fff7fff7fff7fff, 0x8001000080010000},
    {0x8000000080000000, 0xffffffffffffffff, 0x0001000000010000},
    {0x7fffffff7fffffff, 0x0001000100010001, 0x0000ffff0000ffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffff0000ffff0000},
    {0x7fffffff7fffffff, 0x7fff7fff7fff7fff, 0x7ffeffff7ffeffff},
    {0x7fffffff7fffffff, 0x8000800080008000, 0x8000000180000001},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x8000000080000000, 0x8000ffff8000ffff, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0x00007fff00007fff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x7fff00007fff0000, 0x7ffeffff7ffeffff},
    {0x7fffffff7fffffff, 0x8000000180000001, 0x8000000180000001},
};

/* kmmwt2.u */
struct binary_calculation samples_kmmwt2_u[] = {
    {0x0000000100000001, 0x0001000100010001, 0x0000000000000000},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x0000000100000001},
    {0x0000000100000001, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x0001000100010001, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fff7fff7fff7fff, 0xffffffffffffffff},
    {0x8000000080000000, 0x8000800080008000, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x7fff7fff7fff7fff, 0x8001000080010000},
    {0x8000000080000000, 0xffffffffffffffff, 0x0001000000010000},
    {0x7fffffff7fffffff, 0x0001000100010001, 0x0001000000010000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffff0000ffff0000},
    {0x7fffffff7fffffff, 0x7fff7fff7fff7fff, 0x7ffeffff7ffeffff},
    {0x7fffffff7fffffff, 0x8000800080008000, 0x8000000180000001},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x7ffeffff7ffeffff},
    {0x7fffffff7fffffff, 0xffff7fffffff7fff, 0xffff0000ffff0000},
    {0x8000000080000000, 0x8000ffff8000ffff, 0x7fffffff7fffffff},
    {0x8000000180000001, 0x8001ffff8001ffff, 0x7ffeffff7ffeffff},
};

/* kmmawb */
struct ternary_calculation samples_kmmawb[] = {
    {0x0000000100000001, 0x0001000100010001, 0x0000000100000001, 0x0000000100000001},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0xffffffffffffffff, 0x0001000100010001, 0xffffffffffffffff, 0xfffffffefffffffe},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x4000000040000000, 0x4000000040000000},
    {0xffffffffffffffff, 0x7fff7fff7fff7fff, 0x0000000000000000, 0xffffffffffffffff},
    {0x8000000080000000, 0x8000800080008000, 0x0000800000008000, 0x4000800040008000},
    {0x8000000080000000, 0x7fff7fff7fff7fff, 0x7fffffff7fffffff, 0x40007fff40007fff},
    {0x8000000080000000, 0xffffffffffffffff, 0x8000000080000000, 0x8000800080008000},
    {0x7fffffff7fffffff, 0x0001000100010001, 0xffffffffffffffff, 0x00007ffe00007ffe},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x0000000100000001, 0xffff8001ffff8001},
    {0x7fffffff7fffffff, 0x7fff7fff7fff7fff, 0x8000000080000000, 0xbfff7fffbfff7fff},
    {0x7fffffff7fffffff, 0x8000800080008000, 0x7fffffff7fffffff, 0x3fffffff3fffffff},
    {0x0000000000000000, 0x0000000000000000, 0x0000800000008000, 0x0000800000008000},
    {0x0000000000000000, 0x7fff7fff7fff7fff, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffff0001ffff0001, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000100000001, 0x7fffffff7fffffff, 0x8000000080000000, 0x8000000080000000},
};

/* kmmawb.u */
struct ternary_calculation samples_kmmawb_u[] = {
    {0x0000000100000001, 0x0001000100010001, 0x0000000100000001, 0x0000000100000001},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0xffffffffffffffff, 0x0001000100010001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x4000000040000000, 0x4000000040000000},
    {0xffffffffffffffff, 0x7fff7fff7fff7fff, 0x0000000000000000, 0x0000000000000000},
    {0x8000000080000000, 0x8000800080008000, 0x0000800000008000, 0x4000800040008000},
    {0x8000000080000000, 0x7fff7fff7fff7fff, 0x7fffffff7fffffff, 0x40007fff40007fff},
    {0x8000000080000000, 0xffffffffffffffff, 0x8000000080000000, 0x8000800080008000},
    {0x7fffffff7fffffff, 0x0001000100010001, 0xffffffffffffffff, 0x00007fff00007fff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x0000000100000001, 0xffff8001ffff8001},
    {0x7fffffff7fffffff, 0x7fff7fff7fff7fff, 0x8000000080000000, 0xbfff8000bfff8000},
    {0x7fffffff7fffffff, 0x8000800080008000, 0x7fffffff7fffffff, 0x4000000040000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000800000008000, 0x0000800000008000},
    {0x0000000000000000, 0x7fff7fff7fff7fff, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffff7fffffff7fff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0x7fffffff7fffffff, 0x0000000100000001, 0x8000000080000000, 0x8000800080008000},
};

/* kmmawb2 */
struct ternary_calculation samples_kmmawb2[] = {
    {0x0000000100000001, 0x0001000100010001, 0x0000000100000001, 0x0000000100000001},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0xffffffffffffffff, 0x0001000100010001, 0xffffffffffffffff, 0xfffffffefffffffe},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x4000000040000000, 0x4000000040000000},
    {0xffffffffffffffff, 0x7fff7fff7fff7fff, 0x0000000000000000, 0xffffffffffffffff},
    {0x8000000080000000, 0x8000800080008000, 0x0000800000008000, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x7fff7fff7fff7fff, 0x7fffffff7fffffff, 0x0000ffff0000ffff},
    {0x8000000080000000, 0xffffffffffffffff, 0x8000000080000000, 0x8001000080010000},
    {0x7fffffff7fffffff, 0x0001000100010001, 0xffffffffffffffff, 0x0000fffe0000fffe},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x0000000100000001, 0xffff0001ffff0001},
    {0x7fffffff7fffffff, 0x7fff7fff7fff7fff, 0x8000000080000000, 0xfffefffffffeffff},
    {0x7fffffff7fffffff, 0x8000800080008000, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000800000008000, 0x0000800000008000},
    {0x0000000000000000, 0x7fff7fff7fff7fff, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffff0001ffff0001, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000100000001, 0x7fffffff7fffffff, 0x8000000080000000, 0x8000000080000000},
};

/* kmmawb2.u */
struct ternary_calculation samples_kmmawb2_u[] = {
    {0x0000000100000001, 0x0001000100010001, 0x0000000100000001, 0x0000000100000001},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0xffffffffffffffff, 0x0001000100010001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x4000000040000000, 0x4000000040000000},
    {0xffffffffffffffff, 0x7fff7fff7fff7fff, 0x0000000000000000, 0xffffffffffffffff},
    {0x8000000080000000, 0x8000800080008000, 0x0000800000008000, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x7fff7fff7fff7fff, 0x7fffffff7fffffff, 0x0000ffff0000ffff},
    {0x8000000080000000, 0xffffffffffffffff, 0x8000000080000000, 0x8001000080010000},
    {0x7fffffff7fffffff, 0x0001000100010001, 0xffffffffffffffff, 0x0000ffff0000ffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x0000000100000001, 0xffff0001ffff0001},
    {0x7fffffff7fffffff, 0x7fff7fff7fff7fff, 0x8000000080000000, 0xfffefffffffeffff},
    {0x7fffffff7fffffff, 0x8000800080008000, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000800000008000, 0x0000800000008000},
    {0x0000000000000000, 0x7fff7fff7fff7fff, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffff0001ffff0001, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000100000001, 0x7fffffff7fffffff, 0x8000000080000000, 0x8000000080000000},
};

/* kmmawt */
struct ternary_calculation samples_kmmawt[] = {
    {0x0000000100000001, 0x0001000100010001, 0x0000000100000001, 0x0000000100000001},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0xffffffffffffffff, 0x0001000100010001, 0xffffffffffffffff, 0xfffffffefffffffe},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x4000000040000000, 0x4000000040000000},
    {0xffffffffffffffff, 0x7fff7fff7fff7fff, 0x0000000000000000, 0xffffffffffffffff},
    {0x8000000080000000, 0x8000800080008000, 0x0000800000008000, 0x4000800040008000},
    {0x8000000080000000, 0x7fff7fff7fff7fff, 0x7fffffff7fffffff, 0x40007fff40007fff},
    {0x8000000080000000, 0xffffffffffffffff, 0x8000000080000000, 0x8000800080008000},
    {0x7fffffff7fffffff, 0x0001000100010001, 0xffffffffffffffff, 0x00007ffe00007ffe},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x0000000100000001, 0xffff8001ffff8001},
    {0x7fffffff7fffffff, 0x7fff7fff7fff7fff, 0x8000000080000000, 0xbfff7fffbfff7fff},
    {0x7fffffff7fffffff, 0x8000800080008000, 0x7fffffff7fffffff, 0x3fffffff3fffffff},
    {0x0000000000000000, 0x0000000000000000, 0x0000800000008000, 0x0000800000008000},
    {0x0000000000000000, 0x7fff7fff7fff7fff, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x0001ffff0001ffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0xffff7fffffff7fff, 0x8000000080000000, 0x8000000080000000},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x0000000000000000, 0x3fff7fff3fff7fff},
};

/* kmmawt.u */
struct ternary_calculation samples_kmmawt_u[] = {
    {0x0000000100000001, 0x0001000100010001, 0x0000000100000001, 0x0000000100000001},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0xffffffffffffffff, 0x0001000100010001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x4000000040000000, 0x4000000040000000},
    {0xffffffffffffffff, 0x7fff7fff7fff7fff, 0x0000000000000000, 0x0000000000000000},
    {0x8000000080000000, 0x8000800080008000, 0x0000800000008000, 0x4000800040008000},
    {0x8000000080000000, 0x7fff7fff7fff7fff, 0x7fffffff7fffffff, 0x40007fff40007fff},
    {0x8000000080000000, 0xffffffffffffffff, 0x8000000080000000, 0x8000800080008000},
    {0x7fffffff7fffffff, 0x0001000100010001, 0xffffffffffffffff, 0x00007fff00007fff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x0000000100000001, 0xffff8001ffff8001},
    {0x7fffffff7fffffff, 0x7fff7fff7fff7fff, 0x8000000080000000, 0xbfff8000bfff8000},
    {0x7fffffff7fffffff, 0x8000800080008000, 0x7fffffff7fffffff, 0x4000000040000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000800000008000, 0x0000800000008000},
    {0x0000000000000000, 0x7fff7fff7fff7fff, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x7fff00007fff0000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0xffff0000ffff0000, 0x8000000080000000, 0x8000000080000000},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x0000000000000000, 0x3fff80003fff8000},
};

/* kmmawt2 */
struct ternary_calculation samples_kmmawt2[] = {
    {0x0000000100000001, 0x0001000100010001, 0x0000000100000001, 0x0000000100000001},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0xffffffffffffffff, 0x0001000100010001, 0xffffffffffffffff, 0xfffffffefffffffe},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x4000000040000000, 0x4000000040000000},
    {0xffffffffffffffff, 0x7fff7fff7fff7fff, 0x0000000000000000, 0xffffffffffffffff},
    {0x8000000080000000, 0x8000800080008000, 0x0000800000008000, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x7fff7fff7fff7fff, 0x7fffffff7fffffff, 0x0000ffff0000ffff},
    {0x8000000080000000, 0xffffffffffffffff, 0x8000000080000000, 0x8001000080010000},
    {0x7fffffff7fffffff, 0x0001000100010001, 0xffffffffffffffff, 0x0000fffe0000fffe},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x0000000100000001, 0xffff0001ffff0001},
    {0x7fffffff7fffffff, 0x7fff7fff7fff7fff, 0x8000000080000000, 0xfffefffffffeffff},
    {0x7fffffff7fffffff, 0x8000800080008000, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000800000008000, 0x0000800000008000},
    {0x0000000000000000, 0x7fff7fff7fff7fff, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffff0001ffff0001, 0x7fffffff7fffffff, 0x7ffeffff7ffeffff},
    {0x0000000100000001, 0x7fffffff7fffffff, 0x8000000080000000, 0x8000000080000000},
};

/* kmmawt2.u */
struct ternary_calculation samples_kmmawt2_u[] = {
    {0x0000000100000001, 0x0001000100010001, 0x0000000100000001, 0x0000000100000001},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0xffffffffffffffff, 0x0001000100010001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x4000000040000000, 0x4000000040000000},
    {0xffffffffffffffff, 0x7fff7fff7fff7fff, 0x0000000000000000, 0xffffffffffffffff},
    {0x8000000080000000, 0x8000800080008000, 0x0000800000008000, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x7fff7fff7fff7fff, 0x7fffffff7fffffff, 0x0000ffff0000ffff},
    {0x8000000080000000, 0xffffffffffffffff, 0x8000000080000000, 0x8001000080010000},
    {0x7fffffff7fffffff, 0x0001000100010001, 0xffffffffffffffff, 0x0000ffff0000ffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x0000000100000001, 0xffff0001ffff0001},
    {0x7fffffff7fffffff, 0x7fff7fff7fff7fff, 0x8000000080000000, 0xfffefffffffeffff},
    {0x7fffffff7fffffff, 0x8000800080008000, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000800000008000, 0x0000800000008000},
    {0x0000000000000000, 0x7fff7fff7fff7fff, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffff0001ffff0001, 0x7fffffff7fffffff, 0x7ffeffff7ffeffff},
    {0x0000000100000001, 0x7fffffff7fffffff, 0x8000000080000000, 0x8000000180000001},
};

/* kdmbb */
struct binary_calculation samples_kdmbb[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000002},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x000000000000fffe},
    {0x0000000100000001, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000002},
    {0x0000800000008000, 0x8000800080008000, 0x000000007fffffff},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x8000000080000000, 0x0000800000008000, 0x0000000000000000},
    {0x0000800000008000, 0x0000800000008000, 0x000000007fffffff},
    {0x80007fff80007fff, 0xffff7fffffff7fff, 0x000000007ffe0002},
    {0x80007fff80007fff, 0x7fffffff7fffffff, 0xffffffffffff0002},
    {0x80007fff80007fff, 0x7fff80007fff8000, 0xffffffff80010000},
};

/* kdmtt */
struct binary_calculation samples_kdmtt[] = {
    {0x0001000000010000, 0x0001000000010000, 0x0000000000000002},
    {0x0001000000010000, 0x7fff7fff7fff7fff, 0x000000000000fffe},
    {0x0001000000010000, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000002},
    {0x8000000080000000, 0x8000800080008000, 0x000000007fffffff},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0xffff7fffffff7fff, 0x0000000000000000},
    {0x0000800000008000, 0x8000000080000000, 0x0000000000000000},
    {0x8000000080000000, 0x8000ffff8000ffff, 0x000000007fffffff},
    {0x7fffffff7fffffff, 0xffff7fffffff7fff, 0xffffffffffff0002},
    {0x7fffffff7fffffff, 0x0000ffff0000ffff, 0x0000000000000000},
    {0x8000ffff8000ffff, 0x7fffffff7fffffff, 0xffffffff80010000},
};

/* kdmbt */
struct binary_calculation samples_kdmbt[] = {
    {0x0001000000000001, 0x0001000000010000, 0x0000000000000002},
    {0x0001000000000001, 0x7fff7fff7fff7fff, 0x000000000000fffe},
    {0x0001000000000001, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000002},
    {0x8000000000008000, 0x8000800080008000, 0x000000007fffffff},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0xffff7fffffff7fff, 0x0000000000000000},
    {0x0000800080000000, 0x8000000080000000, 0x0000000000000000},
    {0x8000000000008000, 0x8000ffff8000ffff, 0x000000007fffffff},
    {0x7fffffffffff7fff, 0xffff7fffffff7fff, 0xffffffffffff0002},
    {0x7fffffffffff7fff, 0x0000ffff0000ffff, 0x0000000000000000},
    {0x8000ffffffff8000, 0x7fffffff7fffffff, 0xffffffff80010000},
};

/* kmabb */
struct ternary_calculation samples_kmabb[] = {
    {0x0000800000008000, 0x0001ffff0001ffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x00017fff00017fff, 0x00007fff00007fff, 0x8000000080000000, 0xbfff0001bfff0001},
    {0x00017fff00017fff, 0x00007fff00007fff, 0xffffffffffffffff, 0x3fff00003fff0000},
    {0x00017fff00017fff, 0x00007fff00007fff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0xffff8000ffff8000, 0x0000800000008000, 0x8000000080000000, 0xc0000000c0000000},
    {0x8000800080008000, 0x7fff80007fff8000, 0xffffffffffffffff, 0x3fffffff3fffffff},
    {0xffff8000ffff8000, 0x8000800080008000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0xffffffffffffffff, 0x0000ffff0000ffff, 0x8000000080000000, 0x8000000180000001},
    {0x8000ffff8000ffff, 0x7fffffff7fffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0x8000ffff8000ffff, 0x8000ffff8000ffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x00007fff00007fff, 0x0000800000008000, 0x8000000080000000, 0x8000000080000000},
    {0x7fff80007fff8000, 0x7fff7fff7fff7fff, 0xffffffffffffffff, 0xc0007fffc0007fff},
    {0x8000800080008000, 0x80007fff80007fff, 0x7fffffff7fffffff, 0x40007fff40007fff},
    {0x0000ffff0000ffff, 0x0001800000018000, 0x8000000080000000, 0x8000800080008000},
    {0x0000800000008000, 0x0001ffff0001ffff, 0xffffffffffffffff, 0x00007fff00007fff},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x7fff00007fff0000, 0x8000ffff8000ffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x8000ffff8000ffff, 0xffff0000ffff0000, 0x0000000000000000, 0x0000000000000000},
    {0x0000ffff0000ffff, 0xffff0000ffff0000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fff00007fff0000, 0x8000000080000000, 0x0000000000000000, 0x0000000000000000},
    {0x8000000080000000, 0x8000000080000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0000000100000001, 0x8000000080000000, 0x8000000080000000},
    {0x0000000100000001, 0x0000000100000001, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
};

/* kmatt */
struct ternary_calculation samples_kmatt[] = {
    {0x8000000080000000, 0xffff0001ffff0001, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x7fff00017fff0001, 0x7fff00007fff0000, 0x8000000080000000, 0xbfff0001bfff0001},
    {0x7fff00017fff0001, 0x7fff00007fff0000, 0xffffffffffffffff, 0x3fff00003fff0000},
    {0x7fff00017fff0001, 0x7fff00007fff0000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x8000ffff8000ffff, 0x8000000080000000, 0x8000000080000000, 0xc0000000c0000000},
    {0x8000800080008000, 0x80007fff80007fff, 0xffffffffffffffff, 0x3fffffff3fffffff},
    {0x8000ffff8000ffff, 0x8000800080008000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0xffffffffffffffff, 0xffff0000ffff0000, 0x8000000080000000, 0x8000000180000001},
    {0xffff8000ffff8000, 0xffff7fffffff7fff, 0xffffffffffffffff, 0x0000000000000000},
    {0xffff8000ffff8000, 0xffff8000ffff8000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x7fff00007fff0000, 0x8000000080000000, 0x8000000080000000, 0x8000000080000000},
    {0x80007fff80007fff, 0x7fff7fff7fff7fff, 0xffffffffffffffff, 0xc0007fffc0007fff},
    {0x8000800080008000, 0x7fff80007fff8000, 0x7fffffff7fffffff, 0x40007fff40007fff},
    {0xffff0000ffff0000, 0x8000000180000001, 0x8000000080000000, 0x8000800080008000},
    {0x8000000080000000, 0xffff0001ffff0001, 0xffffffffffffffff, 0x00007fff00007fff},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x00007fff00007fff, 0xffff8000ffff8000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffff8000ffff8000, 0x0000ffff0000ffff, 0x0000000000000000, 0x0000000000000000},
    {0xffff0000ffff0000, 0x0000ffff0000ffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x00007fff00007fff, 0x0000800000008000, 0x0000000000000000, 0x0000000000000000},
    {0x0000800000008000, 0x0000800000008000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0001ffff0001ffff, 0x8000000080000000, 0x8000000080000000},
    {0x0001ffff0001ffff, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7ffffffe7ffffffe},
};

/* kmabt */
struct ternary_calculation samples_kmabt[] = {
    {0x0001ffff0001ffff, 0x8000000080000000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x00007fff00007fff, 0x7fff00017fff0001, 0x8000000080000000, 0xbfff0001bfff0001},
    {0x00007fff00007fff, 0x7fff00017fff0001, 0xffffffffffffffff, 0x3fff00003fff0000},
    {0x00007fff00007fff, 0x7fff00017fff0001, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000800000008000, 0x8000ffff8000ffff, 0x8000000080000000, 0xc0000000c0000000},
    {0x7fff80007fff8000, 0x8000800080008000, 0xffffffffffffffff, 0x3fffffff3fffffff},
    {0x8000800080008000, 0x8000ffff8000ffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000ffff0000ffff, 0xffffffffffffffff, 0x8000000080000000, 0x8000000180000001},
    {0x7fffffff7fffffff, 0xffff8000ffff8000, 0xffffffffffffffff, 0x0000000000000000},
    {0x8000ffff8000ffff, 0xffff8000ffff8000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000800000008000, 0x7fff00007fff0000, 0x8000000080000000, 0x8000000080000000},
    {0x7fff7fff7fff7fff, 0x80007fff80007fff, 0xffffffffffffffff, 0xc0007fffc0007fff},
    {0x80007fff80007fff, 0x8000800080008000, 0x7fffffff7fffffff, 0x40007fff40007fff},
    {0x0001800000018000, 0xffff0000ffff0000, 0x8000000080000000, 0x8000800080008000},
    {0x0001ffff0001ffff, 0x8000000080000000, 0xffffffffffffffff, 0x00007fff00007fff},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x8000ffff8000ffff, 0x00007fff00007fff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffff0000ffff0000, 0xffff8000ffff8000, 0x0000000000000000, 0x0000000000000000},
    {0xffff0000ffff0000, 0xffff0000ffff0000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x8000000080000000, 0x00007fff00007fff, 0x0000000000000000, 0x0000000000000000},
    {0x8000000080000000, 0x0000800000008000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffff0001ffff0001, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0xffff0001ffff0001, 0x0001ffff0001ffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0x0001ffff0001ffff, 0x7fffffff7fffffff, 0x7ffffffe7ffffffe},
};

/* smalbb */
struct ternary_ul_ul_64_calculation samples_smalbb[] = {
    {0x000100017fff7fff, 0x000000007fff7fff, 0x8000000000000000, 0x800000003fff0001},
    {0x000100017fff7fff, 0x000000007fff7fff, 0xffffffffffffffff, 0x000000003fff0000},
    {0x000100017fff7fff, 0x000000007fff7fff, 0x7fffffffffffffff, 0x800000003fff0000},
    {0xffffffff80008000, 0x0000000080008000, 0x8000000000000000, 0x8000000040000000},
    {0x8000800080008000, 0x7fff7fff80008000, 0xffffffffffffffff, 0x0000000000007fff},
    {0xffffffff80008000, 0x8000800080008000, 0x7fffffffffffffff, 0x8000000040007fff},
    {0xffffffff7fff7fff, 0x0000000080008000, 0x8000000000000000, 0x7fffffffc0008000},
    {0x800080007fff7fff, 0x7fff7fff80008000, 0xffffffffffffffff, 0xffffffff8000ffff},
    {0x800080007fff7fff, 0x8000800080008000, 0x7fffffffffffffff, 0x8000000000007fff},
    {0x00000000ffffffff, 0x00000000ffffffff, 0x8000000000000000, 0x8000000000000001},
    {0x7fff7fffffffffff, 0x7fff7fffffffffff, 0xffffffffffffffff, 0x000000003fff0001},
    {0x80008000ffffffff, 0x80008000ffffffff, 0x7fffffffffffffff, 0x8000000040000000},
    {0x00000000ffffffff, 0x0001000180008000, 0x8000000000000000, 0x8000000000008000},
    {0x0000000080008000, 0x00010001ffffffff, 0xffffffffffffffff, 0x0000000000007fff},
    {0x0000000080008000, 0x00010001ffffffff, 0x7fffffffffffffff, 0x8000000000007fff},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x7fff7fff00000000, 0x80008000ffffffff, 0xffffffffffffffff, 0xffffffffc0007fff},
    {0x80008000ffffffff, 0xffffffff00000000, 0x0000000000000000, 0x0000000000008000},
    {0x00000000ffffffff, 0xffffffff00000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fff7fff00000000, 0x8000800000000000, 0x0000000000000000, 0xffffffffc0008000},
    {0x8000800000000000, 0x8000800000000000, 0xffffffffffffffff, 0x000000003fffffff},
    {0x000000007fff7fff, 0x000000007fff7fff, 0x8000000000000000, 0x800000003fff0001},
    {0x000000007fff7fff, 0x000000007fff7fff, 0x7fffffffffffffff, 0x800000003fff0000},
    {0x0000000080008000, 0x0000000080008000, 0xffffffffffffffff, 0x000000003fffffff},
    {0x000000007fff7fff, 0x0000000080008000, 0xffffffffffffffff, 0xffffffffc0007fff},
};

/* smalbt */
struct ternary_ul_ul_64_calculation samples_smalbt[] = {
    {0x000100017fff7fff, 0x000000007fff7fff, 0x8000000000000000, 0x800000003fff0001},
    {0x000100017fff7fff, 0x000000007fff7fff, 0xffffffffffffffff, 0x000000003fff0000},
    {0x000100017fff7fff, 0x000000007fff7fff, 0x7fffffffffffffff, 0x800000003fff0000},
    {0xffffffff80008000, 0x0000000080008000, 0x8000000000000000, 0x8000000040000000},
    {0x8000800080008000, 0x7fff7fff80008000, 0xffffffffffffffff, 0x0000000000007fff},
    {0xffffffff80008000, 0x8000800080008000, 0x7fffffffffffffff, 0x8000000040007fff},
    {0xffffffff7fff7fff, 0x0000000080008000, 0x8000000000000000, 0x7fffffffc0008000},
    {0x800080007fff7fff, 0x7fff7fff80008000, 0xffffffffffffffff, 0xffffffff8000ffff},
    {0x800080007fff7fff, 0x8000800080008000, 0x7fffffffffffffff, 0x8000000000007fff},
    {0x00000000ffffffff, 0x00000000ffffffff, 0x8000000000000000, 0x8000000000000001},
    {0x7fff7fffffffffff, 0x7fff7fffffffffff, 0xffffffffffffffff, 0x000000003fff0001},
    {0x80008000ffffffff, 0x80008000ffffffff, 0x7fffffffffffffff, 0x8000000040000000},
    {0x00000000ffffffff, 0x0001000180008000, 0x8000000000000000, 0x8000000000008000},
    {0x0000000080008000, 0x00010001ffffffff, 0xffffffffffffffff, 0x0000000000007fff},
    {0x0000000080008000, 0x00010001ffffffff, 0x7fffffffffffffff, 0x8000000000007fff},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x7fff7fff00000000, 0x80008000ffffffff, 0xffffffffffffffff, 0xffffffffc0007fff},
    {0x80008000ffffffff, 0xffffffff00000000, 0x0000000000000000, 0x0000000000008000},
    {0x00000000ffffffff, 0xffffffff00000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fff7fff00000000, 0x8000800000000000, 0x0000000000000000, 0xffffffffc0008000},
    {0x8000800000000000, 0x8000800000000000, 0xffffffffffffffff, 0x000000003fffffff},
    {0x000000007fff7fff, 0x000000007fff7fff, 0x8000000000000000, 0x800000003fff0001},
    {0x000000007fff7fff, 0x000000007fff7fff, 0x7fffffffffffffff, 0x800000003fff0000},
    {0x0000000080008000, 0x0000000080008000, 0xffffffffffffffff, 0x000000003fffffff},
    {0x000000007fff7fff, 0x0000000080008000, 0xffffffffffffffff, 0xffffffffc0007fff},
};

/* smaltt */
struct ternary_ul_ul_64_calculation samples_smaltt[] = {
    {0x000100017fff7fff, 0x000000007fff7fff, 0x8000000000000000, 0x800000003fff0001},
    {0x000100017fff7fff, 0x000000007fff7fff, 0xffffffffffffffff, 0x000000003fff0000},
    {0x000100017fff7fff, 0x000000007fff7fff, 0x7fffffffffffffff, 0x800000003fff0000},
    {0xffffffff80008000, 0x0000000080008000, 0x8000000000000000, 0x8000000040000000},
    {0x8000800080008000, 0x7fff7fff80008000, 0xffffffffffffffff, 0x0000000000007fff},
    {0xffffffff80008000, 0x8000800080008000, 0x7fffffffffffffff, 0x8000000040007fff},
    {0xffffffff7fff7fff, 0x0000000080008000, 0x8000000000000000, 0x7fffffffc0008000},
    {0x800080007fff7fff, 0x7fff7fff80008000, 0xffffffffffffffff, 0xffffffff8000ffff},
    {0x800080007fff7fff, 0x8000800080008000, 0x7fffffffffffffff, 0x8000000000007fff},
    {0x00000000ffffffff, 0x00000000ffffffff, 0x8000000000000000, 0x8000000000000001},
    {0x7fff7fffffffffff, 0x7fff7fffffffffff, 0xffffffffffffffff, 0x000000003fff0001},
    {0x80008000ffffffff, 0x80008000ffffffff, 0x7fffffffffffffff, 0x8000000040000000},
    {0x00000000ffffffff, 0x0001000180008000, 0x8000000000000000, 0x8000000000008000},
    {0x0000000080008000, 0x00010001ffffffff, 0xffffffffffffffff, 0x0000000000007fff},
    {0x0000000080008000, 0x00010001ffffffff, 0x7fffffffffffffff, 0x8000000000007fff},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x7fff7fff00000000, 0x80008000ffffffff, 0xffffffffffffffff, 0xffffffffc0007fff},
    {0x80008000ffffffff, 0xffffffff00000000, 0x0000000000000000, 0x0000000000008000},
    {0x00000000ffffffff, 0xffffffff00000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fff7fff00000000, 0x8000800000000000, 0x0000000000000000, 0xffffffffc0008000},
    {0x8000800000000000, 0x8000800000000000, 0xffffffffffffffff, 0x000000003fffffff},
    {0x000000007fff7fff, 0x000000007fff7fff, 0x8000000000000000, 0x800000003fff0001},
    {0x000000007fff7fff, 0x000000007fff7fff, 0x7fffffffffffffff, 0x800000003fff0000},
    {0x0000000080008000, 0x0000000080008000, 0xffffffffffffffff, 0x000000003fffffff},
    {0x000000007fff7fff, 0x0000000080008000, 0xffffffffffffffff, 0xffffffffc0007fff},
};

/* smalda */
struct ternary_calculation samples_smalda[] = {
    {0x000100017fff7fff, 0x000000007fff7fff, 0x8000000000000000, 0x800000007ffe0002},
    {0x000100017fff7fff, 0x000000007fff7fff, 0xffffffffffffffff, 0x000000007ffe0001},
    {0x000100017fff7fff, 0x000000007fff7fff, 0x7fffffffffffffff, 0x800000007ffe0001},
    {0xffffffff80008000, 0x0000000080008000, 0x8000000000000000, 0x8000000080000000},
    {0x8000800080008000, 0x7fff7fff80008000, 0xffffffffffffffff, 0x000000000000ffff},
    {0xffffffff80008000, 0x8000800080008000, 0x7fffffffffffffff, 0x800000008000ffff},
    {0xffffffff7fff7fff, 0x0000000080008000, 0x8000000000000000, 0x7fffffff80010000},
    {0x800080007fff7fff, 0x7fff7fff80008000, 0xffffffffffffffff, 0xffffffff0001ffff},
    {0x800080007fff7fff, 0x8000800080008000, 0x7fffffffffffffff, 0x800000000000ffff},
    {0x00000000ffffffff, 0x00000000ffffffff, 0x8000000000000000, 0x8000000000000002},
    {0x7fff7fffffffffff, 0x7fff7fffffffffff, 0xffffffffffffffff, 0x000000007ffe0003},
    {0x80008000ffffffff, 0x80008000ffffffff, 0x7fffffffffffffff, 0x8000000080000001},
    {0x00000000ffffffff, 0x0001000180008000, 0x8000000000000000, 0x8000000000010000},
    {0x0000000080008000, 0x00010001ffffffff, 0xffffffffffffffff, 0x000000000000ffff},
    {0x0000000080008000, 0x00010001ffffffff, 0x7fffffffffffffff, 0x800000000000ffff},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x7fff7fff00000000, 0x80008000ffffffff, 0xffffffffffffffff, 0xffffffff8000ffff},
    {0x80008000ffffffff, 0xffffffff00000000, 0x0000000000000000, 0x0000000000010000},
    {0x00000000ffffffff, 0xffffffff00000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fff7fff00000000, 0x8000800000000000, 0x0000000000000000, 0xffffffff80010000},
    {0x8000800000000000, 0x8000800000000000, 0xffffffffffffffff, 0x000000007fffffff},
    {0x000000007fff7fff, 0x000000007fff7fff, 0x8000000000000000, 0x800000007ffe0002},
    {0x000000007fff7fff, 0x000000007fff7fff, 0x7fffffffffffffff, 0x800000007ffe0001},
    {0x0000000080008000, 0x0000000080008000, 0xffffffffffffffff, 0x000000007fffffff},
    {0x000000007fff7fff, 0x0000000080008000, 0xffffffffffffffff, 0xffffffff8000ffff},
};

/* smalxda */
struct ternary_calculation samples_smalxda[] = {
    {0x000100017fff7fff, 0x000000007fff7fff, 0x8000000000000000, 0x800000007ffe0002},
    {0x000100017fff7fff, 0x000000007fff7fff, 0xffffffffffffffff, 0x000000007ffe0001},
    {0x000100017fff7fff, 0x000000007fff7fff, 0x7fffffffffffffff, 0x800000007ffe0001},
    {0xffffffff80008000, 0x0000000080008000, 0x8000000000000000, 0x8000000080000000},
    {0x8000800080008000, 0x7fff7fff80008000, 0xffffffffffffffff, 0x000000000000ffff},
    {0xffffffff80008000, 0x8000800080008000, 0x7fffffffffffffff, 0x800000008000ffff},
    {0xffffffff7fff7fff, 0x0000000080008000, 0x8000000000000000, 0x7fffffff80010000},
    {0x800080007fff7fff, 0x7fff7fff80008000, 0xffffffffffffffff, 0xffffffff0001ffff},
    {0x800080007fff7fff, 0x8000800080008000, 0x7fffffffffffffff, 0x800000000000ffff},
    {0x00000000ffffffff, 0x00000000ffffffff, 0x8000000000000000, 0x8000000000000002},
    {0x7fff7fffffffffff, 0x7fff7fffffffffff, 0xffffffffffffffff, 0x000000007ffe0003},
    {0x80008000ffffffff, 0x80008000ffffffff, 0x7fffffffffffffff, 0x8000000080000001},
    {0x00000000ffffffff, 0x0001000180008000, 0x8000000000000000, 0x8000000000010000},
    {0x0000000080008000, 0x00010001ffffffff, 0xffffffffffffffff, 0x000000000000ffff},
    {0x0000000080008000, 0x00010001ffffffff, 0x7fffffffffffffff, 0x800000000000ffff},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x7fff7fff00000000, 0x80008000ffffffff, 0xffffffffffffffff, 0xffffffff8000ffff},
    {0x80008000ffffffff, 0xffffffff00000000, 0x0000000000000000, 0x0000000000010000},
    {0x00000000ffffffff, 0xffffffff00000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fff7fff00000000, 0x8000800000000000, 0x0000000000000000, 0xffffffff80010000},
    {0x8000800000000000, 0x8000800000000000, 0xffffffffffffffff, 0x000000007fffffff},
    {0x000000007fff7fff, 0x000000007fff7fff, 0x8000000000000000, 0x800000007ffe0002},
    {0x000000007fff7fff, 0x000000007fff7fff, 0x7fffffffffffffff, 0x800000007ffe0001},
    {0x0000000080008000, 0x0000000080008000, 0xffffffffffffffff, 0x000000007fffffff},
    {0x000000007fff7fff, 0x0000000080008000, 0xffffffffffffffff, 0xffffffff8000ffff},
};

/* smalds */
struct ternary_calculation samples_smalds[] = {
    {0x000100017fff7fff, 0x000000007fff7ffe, 0x8000000000000000, 0x8000000000007fff},
    {0x000100017fff7fff, 0x000000007fff7ffe, 0xffffffffffffffff, 0x0000000000007ffe},
    {0x000100017fff7fff, 0x000000007fff7ffe, 0x7fffffffffffffff, 0x8000000000007ffe},
    {0xffffffff80008000, 0x0000000080008001, 0x8000000000000000, 0x8000000000008000},
    {0x8000800080008000, 0x7fff7fff80008001, 0xffffffffffffffff, 0x0000000000007fff},
    {0xffffffff80008000, 0x8000800080008001, 0x7fffffffffffffff, 0x8000000000007fff},
    {0xffffffff7fff7fff, 0x0000000080008001, 0x8000000000000000, 0x7fffffffffff8001},
    {0x800080007fff7fff, 0x7fff7fff80008001, 0xffffffffffffffff, 0xffffffffffff8000},
    {0x800080007fff7fff, 0x8000800080008001, 0x7fffffffffffffff, 0x7fffffffffff8000},
    {0x00000000ffffffff, 0x00000000fffffffe, 0x8000000000000000, 0x7fffffffffffffff},
    {0x7fff7fffffffffff, 0x7fff7ffffffffffe, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0x80008000ffffffff, 0x80008000fffffffe, 0x7fffffffffffffff, 0x7ffffffffffffffe},
};

/* smaldrs */
struct ternary_calculation samples_smaldrs[] = {
    {0x000100017fff7fff, 0x000000007ffe7fff, 0x8000000000000000, 0x8000000000007fff},
    {0x000100017fff7fff, 0x000000007ffe7fff, 0xffffffffffffffff, 0x0000000000007ffe},
    {0x000100017fff7fff, 0x000000007ffe7fff, 0x7fffffffffffffff, 0x8000000000007ffe},
    {0xffffffff80008000, 0x0000000080018000, 0x8000000000000000, 0x8000000000008000},
    {0x8000800080008000, 0x7fff7fff80018000, 0xffffffffffffffff, 0x0000000000007fff},
    {0xffffffff80008000, 0x8000800080018000, 0x7fffffffffffffff, 0x8000000000007fff},
    {0xffffffff7fff7fff, 0x0000000080018000, 0x8000000000000000, 0x7fffffffffff8001},
    {0x800080007fff7fff, 0x7fff7fff80018000, 0xffffffffffffffff, 0xffffffffffff8000},
    {0x800080007fff7fff, 0x8000800080018000, 0x7fffffffffffffff, 0x7fffffffffff8000},
    {0x00000000ffffffff, 0x00000000fffeffff, 0x8000000000000000, 0x7fffffffffffffff},
    {0x7fff7fffffffffff, 0x7fff7ffffffeffff, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0x80008000ffffffff, 0x80008000fffeffff, 0x7fffffffffffffff, 0x7ffffffffffffffe},
};

/* smalxds */
struct ternary_calculation samples_smalxds[] = {
    {0x000100017fff7fff, 0x000000007ffe7fff, 0x8000000000000000, 0x8000000000007fff},
    {0x000100017fff7fff, 0x000000007ffe7fff, 0xffffffffffffffff, 0x0000000000007ffe},
    {0x000100017fff7fff, 0x000000007ffe7fff, 0x7fffffffffffffff, 0x8000000000007ffe},
    {0xffffffff80008000, 0x0000000080018000, 0x8000000000000000, 0x8000000000008000},
    {0x8000800080008000, 0x7fff7fff80018000, 0xffffffffffffffff, 0x0000000000007fff},
    {0xffffffff80008000, 0x8000800080018000, 0x7fffffffffffffff, 0x8000000000007fff},
    {0xffffffff7fff7fff, 0x0000000080018000, 0x8000000000000000, 0x7fffffffffff8001},
    {0x800080007fff7fff, 0x7fff7fff80018000, 0xffffffffffffffff, 0xffffffffffff8000},
    {0x800080007fff7fff, 0x8000800080018000, 0x7fffffffffffffff, 0x7fffffffffff8000},
    {0x00000000ffffffff, 0x00000000fffeffff, 0x8000000000000000, 0x7fffffffffffffff},
    {0x7fff7fffffffffff, 0x7fff7ffffffeffff, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0x80008000ffffffff, 0x80008000fffeffff, 0x7fffffffffffffff, 0x7ffffffffffffffe},
};

/* smslda */
struct ternary_calculation samples_smslda[] = {
    {0x000100017fff7fff, 0x000000007fff7fff, 0x8000000000000000, 0x7fffffff8001fffe},
    {0x000100017fff7fff, 0x000000007fff7fff, 0xffffffffffffffff, 0xffffffff8001fffd},
    {0x000100017fff7fff, 0x000000007fff7fff, 0x7fffffffffffffff, 0x7fffffff8001fffd},
    {0xffffffff80008000, 0x0000000080008000, 0x8000000000000000, 0x7fffffff80000000},
    {0x8000800080008000, 0x7fff7fff80008000, 0xffffffffffffffff, 0xfffffffffffeffff},
    {0xffffffff80008000, 0x8000800080008000, 0x7fffffffffffffff, 0x7fffffff7ffeffff},
    {0xffffffff7fff7fff, 0x0000000080008000, 0x8000000000000000, 0x800000007fff0000},
    {0x800080007fff7fff, 0x7fff7fff80008000, 0xffffffffffffffff, 0x00000000fffdffff},
    {0x800080007fff7fff, 0x8000800080008000, 0x7fffffffffffffff, 0x7ffffffffffeffff},
    {0x00000000ffffffff, 0x00000000ffffffff, 0x8000000000000000, 0x7ffffffffffffffe},
    {0x7fff7fffffffffff, 0x7fff7fffffffffff, 0xffffffffffffffff, 0xffffffff8001fffb},
    {0x80008000ffffffff, 0x80008000ffffffff, 0x7fffffffffffffff, 0x7fffffff7ffffffd},
    {0x00000000ffffffff, 0x0001000180008000, 0x8000000000000000, 0x7fffffffffff0000},
    {0x0000000080008000, 0x00010001ffffffff, 0xffffffffffffffff, 0xfffffffffffeffff},
    {0x0000000080008000, 0x00010001ffffffff, 0x7fffffffffffffff, 0x7ffffffffffeffff},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
};

/* smslxda */
struct ternary_calculation samples_smslxda[] = {
    {0x000100017fff7fff, 0x000000007fff7fff, 0x8000000000000000, 0x7fffffff8001fffe},
    {0x000100017fff7fff, 0x000000007fff7fff, 0xffffffffffffffff, 0xffffffff8001fffd},
    {0x000100017fff7fff, 0x000000007fff7fff, 0x7fffffffffffffff, 0x7fffffff8001fffd},
    {0xffffffff80008000, 0x0000000080008000, 0x8000000000000000, 0x7fffffff80000000},
    {0x8000800080008000, 0x7fff7fff80008000, 0xffffffffffffffff, 0xfffffffffffeffff},
    {0xffffffff80008000, 0x8000800080008000, 0x7fffffffffffffff, 0x7fffffff7ffeffff},
    {0xffffffff7fff7fff, 0x0000000080008000, 0x8000000000000000, 0x800000007fff0000},
    {0x800080007fff7fff, 0x7fff7fff80008000, 0xffffffffffffffff, 0x00000000fffdffff},
    {0x800080007fff7fff, 0x8000800080008000, 0x7fffffffffffffff, 0x7ffffffffffeffff},
    {0x00000000ffffffff, 0x00000000ffffffff, 0x8000000000000000, 0x7ffffffffffffffe},
    {0x7fff7fffffffffff, 0x7fff7fffffffffff, 0xffffffffffffffff, 0xffffffff8001fffb},
    {0x80008000ffffffff, 0x80008000ffffffff, 0x7fffffffffffffff, 0x7fffffff7ffffffd},
    {0x00000000ffffffff, 0x0001000180008000, 0x8000000000000000, 0x7fffffffffff0000},
    {0x0000000080008000, 0x00010001ffffffff, 0xffffffffffffffff, 0xfffffffffffeffff},
    {0x0000000080008000, 0x00010001ffffffff, 0x7fffffffffffffff, 0x7ffffffffffeffff},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
};

/* smul8 */
struct binary64_calculation samples_smul8[] = {
    {0x00000001, 0x00010001, 0x0000000000000001},
    {0x04030201, 0x7f7f7f7f, 0x01fc017d00fe007f},
    {0xf1f2f3f4, 0xffffffff, 0x000f000e000d000c},
    {0x80808080, 0xf1f2f3f4, 0x0780070006800600},
    {0x80808080, 0x80808080, 0x4000400040004000},
    {0x80808080, 0x7f7f7f7f, 0xc080c080c080c080},
    {0xf1f2f3f4, 0x7f7f7f7f, 0xf88ff90ef98dfa0c},
};

/* smulx8 */
struct binary64_calculation samples_smulx8[] = {
    {0x00000001, 0x01000100, 0x0000000000000001},
    {0x04030201, 0x7f7f7f7f, 0x01fc017d00fe007f},
    {0xf1f2f3f4, 0xffffffff, 0x000f000e000d000c},
    {0x80808080, 0xf2f1f4f3, 0x0780070006800600},
    {0x80808080, 0x80808080, 0x4000400040004000},
    {0x80808080, 0x7f7f7f7f, 0xc080c080c080c080},
    {0xf1f2f3f4, 0x7f7f7f7f, 0xf88ff90ef98dfa0c},
};

/* umul8 */
struct binary64_calculation samples_umul8[] = {
    {0x00000001, 0x00010001, 0x0000000000000001},
    {0x04030201, 0x7f7f7f7f, 0x01fc017d00fe007f},
    {0xf1f2f3f4, 0xffffffff, 0xf00ff10ef20df30c},
    {0x80808080, 0xf1f2f3f4, 0x7880790079807a00},
    {0x80808080, 0x80808080, 0x4000400040004000},
    {0xffffffff, 0x7f7f7f7f, 0x7e817e817e817e81},
    {0xf1f2f3f4, 0x7f7f7f7f, 0x778f780e788d790c},
    {0xffffffff, 0xffffffff, 0xfe01fe01fe01fe01},
};

/* umulx8 */
struct binary64_calculation samples_umulx8[] = {
    {0x00000001, 0x01000100, 0x0000000000000001},
    {0x04030201, 0x7f7f7f7f, 0x01fc017d00fe007f},
    {0xf1f2f3f4, 0xffffffff, 0xf00ff10ef20df30c},
    {0x80808080, 0xf2f1f4f3, 0x7880790079807a00},
    {0x80808080, 0x80808080, 0x4000400040004000},
    {0xffffffff, 0x7f7f7f7f, 0x7e817e817e817e81},
    {0xf1f2f3f4, 0x7f7f7f7f, 0x778f780e788d790c},
    {0xffffffff, 0xffffffff, 0xfe01fe01fe01fe01},
};

/* khm8 */
struct binary_calculation samples_khm8[] = {
    {0xf1f2f3f4f5f6f7f8, 0x8080808080808080, 0x0f0e0d0c0b0a0908},
    {0xf1f2f3f4f5f6f7f8, 0x7f7f7f7f7f7f7f7f, 0xf1f2f3f4f5f6f7f8},
    {0x8080808080808080, 0x7f7f7f7f7f7f7f7f, 0x8181818181818181},
    {0x8080808080808080, 0x8080808080808080, 0x7f7f7f7f7f7f7f7f},
    {0x8080808080808080, 0x0102030405060708, 0xfffefdfcfbfaf9f8},
    {0x7f7f7f7f7f7f7f7f, 0x0102030405060708, 0x0001020304050607},
};

/* khmx8 */
struct binary_calculation samples_khmx8[] = {
    {0xf1f2f3f4f5f6f7f8, 0x8080808080808080, 0x0f0e0d0c0b0a0908},
    {0xf1f2f3f4f5f6f7f8, 0x7f7f7f7f7f7f7f7f, 0xf1f2f3f4f5f6f7f8},
    {0x8080808080808080, 0x7f7f7f7f7f7f7f7f, 0x8181818181818181},
    {0x8080808080808080, 0x8080808080808080, 0x7f7f7f7f7f7f7f7f},
    {0x8080808080808080, 0x0201040306050807, 0xfffefdfcfbfaf9f8},
    {0x7f7f7f7f7f7f7f7f, 0x0201040306050807, 0x0001020304050607},
};

/* smul16 */
struct binary64_calculation samples_smul16[] = {
    {0x00000001, 0x00010001, 0x0000000000000001},
    {0x00000001, 0x7fff7fff, 0x0000000000007fff},
    {0x00000001, 0xffffffff, 0x00000000ffffffff},
    {0xffffffff, 0x00010001, 0xffffffffffffffff},
    {0xffffffff, 0xffffffff, 0x0000000100000001},
    {0xffffffff, 0x7fff7fff, 0xffff8001ffff8001},
    {0x80000000, 0x80008000, 0x4000000000000000},
    {0x80000000, 0x7fff7fff, 0xc000800000000000},
    {0x80000000, 0xffffffff, 0x0000800000000000},
    {0x7fffffff, 0x00010001, 0x00007fffffffffff},
    {0x7fffffff, 0xffffffff, 0xffff800100000001},
    {0x7fffffff, 0x7fff7fff, 0x3fff0001ffff8001},
    {0x7fffffff, 0x80008000, 0xc000800000008000},
    {0x00000000, 0x00000000, 0x0000000000000000},
    {0x00000000, 0x7fff7fff, 0x0000000000000000},
    {0x8000ffff, 0xffff7fff, 0x00008000ffff8001},
    {0x7fff0000, 0x8000ffff, 0xc000800000000000},
};

/* umul16 */
struct binary64_calculation samples_umul16[] = {
    {0x00000001, 0x00010001, 0x0000000000000001},
    {0x00000001, 0x7fff7fff, 0x0000000000007fff},
    {0x00000001, 0xffffffff, 0x000000000000ffff},
    {0xffffffff, 0x00010001, 0x0000ffff0000ffff},
    {0xffffffff, 0xffffffff, 0xfffe0001fffe0001},
    {0xffffffff, 0x7fff7fff, 0x7ffe80017ffe8001},
    {0x80000000, 0x80008000, 0x4000000000000000},
    {0x80000000, 0x7fff7fff, 0x3fff800000000000},
    {0x80000000, 0xffffffff, 0x7fff800000000000},
    {0x7fffffff, 0x00010001, 0x00007fff0000ffff},
    {0x7fffffff, 0xffffffff, 0x7ffe8001fffe0001},
    {0x7fffffff, 0x7fff7fff, 0x3fff00017ffe8001},
    {0x7fffffff, 0x80008000, 0x3fff80007fff8000},
    {0x00000000, 0x00000000, 0x0000000000000000},
    {0x00000000, 0x7fff7fff, 0x0000000000000000},
    {0x8000ffff, 0xffff7fff, 0x7fff80007ffe8001},
    {0x7fff0000, 0x8000ffff, 0x3fff800000000000},
    {0x80007fff, 0xffffffff, 0x7fff80007ffe8001},
};

/* smulx16 */
struct binary64_calculation samples_smulx16[] = {
    {0x00000001, 0x00010001, 0x0000000000000001},
    {0x00000001, 0x7fff7fff, 0x0000000000007fff},
    {0x00000001, 0xffffffff, 0x00000000ffffffff},
    {0xffffffff, 0x00010001, 0xffffffffffffffff},
    {0xffffffff, 0xffffffff, 0x0000000100000001},
    {0xffffffff, 0x7fff7fff, 0xffff8001ffff8001},
    {0x80000000, 0x80008000, 0x4000000000000000},
    {0x80000000, 0x7fff7fff, 0xc000800000000000},
    {0x80000000, 0xffffffff, 0x0000800000000000},
    {0x7fffffff, 0x00010001, 0x00007fffffffffff},
    {0x7fffffff, 0xffffffff, 0xffff800100000001},
    {0x7fffffff, 0x7fff7fff, 0x3fff0001ffff8001},
    {0x7fffffff, 0x80008000, 0xc000800000008000},
    {0x00000000, 0x00000000, 0x0000000000000000},
    {0x00000000, 0x7fff7fff, 0x0000000000000000},
    {0x8000ffff, 0xffff7fff, 0xc000800000000001},
    {0x7fff0000, 0xffff8000, 0xc000800000000000},
    {0x80007fff, 0xffffffff, 0x00008000ffff8001},
};

/* umulx16 */
struct binary64_calculation samples_umulx16[] = {
    {0x00000001, 0x00010001, 0x0000000000000001},
    {0x00000001, 0x7fff7fff, 0x0000000000007fff},
    {0x00000001, 0xffffffff, 0x000000000000ffff},
    {0xffffffff, 0x00010001, 0x0000ffff0000ffff},
    {0xffffffff, 0xffffffff, 0xfffe0001fffe0001},
    {0xffffffff, 0x7fff7fff, 0x7ffe80017ffe8001},
    {0x80000000, 0x80008000, 0x4000000000000000},
    {0x80000000, 0x7fff7fff, 0x3fff800000000000},
    {0x80000000, 0xffffffff, 0x7fff800000000000},
    {0x7fffffff, 0x00010001, 0x00007fff0000ffff},
    {0x7fffffff, 0xffffffff, 0x7ffe8001fffe0001},
    {0x7fffffff, 0x7fff7fff, 0x3fff00017ffe8001},
    {0x7fffffff, 0x80008000, 0x3fff80007fff8000},
    {0x00000000, 0x00000000, 0x0000000000000000},
    {0x00000000, 0x7fff7fff, 0x0000000000000000},
    {0x8000ffff, 0x7fffffff, 0x7fff80007ffe8001},
    {0x7fff0000, 0xffff8000, 0x3fff800000000000},
    {0x80007fff, 0xffffffff, 0x7fff80007ffe8001},
};

/* khm16 */
struct binary_calculation samples_khm16[] = {
    {0x80007fff7fff8000, 0x7fff80007fff8000, 0x800180017ffe7fff},
    {0x0001000200030004, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0001000200030004, 0x7fff7fff7fff7fff, 0x0000000100020003},
    {0x0000000000000000, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fff7fff7fff7fff, 0xffffffffffffffff},
    {0xfff1fff2fff3fff4, 0x7fff7fff7fff7fff, 0xfff1fff2fff3fff4},
};

/* khmx16 */
struct binary_calculation samples_khmx16[] = {
    {0x80007fff7fff8000, 0x80007fff80007fff, 0x800180017ffe7fff},
    {0x0001000200030004, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0001000200030004, 0x7fff7fff7fff7fff, 0x0000000100020003},
    {0x0000000000000000, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fff7fff7fff7fff, 0xffffffffffffffff},
    {0xfff1fff2fff3fff4, 0x7fff7fff7fff7fff, 0xfff1fff2fff3fff4},
};

/* kmda */
struct binary_calculation samples_kmda[] = {
    {0x0001000100010001, 0x0000000100000001, 0x0000000100000001},
    {0x0001000100010001, 0x0000800000008000, 0xffff8000ffff8000},
    {0x0001000100010001, 0x7fff7fff7fff7fff, 0x0000fffe0000fffe},
    {0x0001000100010001, 0x0000ffff0000ffff, 0xffffffffffffffff},
    {0x0001000200010002, 0x7fff80007fff8000, 0xffff7fffffff7fff},
    {0x00017fff00017fff, 0x8000ffff8000ffff, 0xffff0001ffff0001},
    {0x0001ffff0001ffff, 0x0000ffff0000ffff, 0x0000000100000001},
    {0x0001ffff0001ffff, 0x7fff80007fff8000, 0x0000ffff0000ffff},
    {0x0001800000018000, 0x8000800080008000, 0x3fff80003fff8000},
    {0x0001000000010000, 0x0000000000000000, 0x0000000000000000},
    {0x0001000000010000, 0x7fff7fff7fff7fff, 0x00007fff00007fff},
    {0x0001000000010000, 0x8000800080008000, 0xffff8000ffff8000},
    {0x8000800080008000, 0x8000800080008000, 0x7fffffff7fffffff},
    {0x4000ffff4000ffff, 0x0001400000014000, 0x0000000000000000},
    {0x80007fff80007fff, 0x7fffffff7fffffff, 0xc0000001c0000001},
    {0x7fffffff7fffffff, 0x8000ffff8000ffff, 0xc0008001c0008001},
};

/* kmxda */
struct binary_calculation samples_kmxda[] = {
    {0x0001000100010001, 0x0001000000010000, 0x0000000100000001},
    {0x0001000100010001, 0x8000000080000000, 0xffff8000ffff8000},
    {0x0001000100010001, 0x7fff7fff7fff7fff, 0x0000fffe0000fffe},
    {0x0001000100010001, 0xffff0000ffff0000, 0xffffffffffffffff},
    {0x0001000200010002, 0x80007fff80007fff, 0xffff7fffffff7fff},
    {0x00017fff00017fff, 0xffff8000ffff8000, 0xffff0001ffff0001},
    {0x0001ffff0001ffff, 0xffff0000ffff0000, 0x0000000100000001},
    {0x0001ffff0001ffff, 0x80007fff80007fff, 0x0000ffff0000ffff},
    {0x0001800000018000, 0x8000800080008000, 0x3fff80003fff8000},
    {0x0001000000010000, 0x0000000000000000, 0x0000000000000000},
    {0x0001000000010000, 0x7fff7fff7fff7fff, 0x00007fff00007fff},
    {0x0001000000010000, 0x8000800080008000, 0xffff8000ffff8000},
    {0x8000800080008000, 0x8000800080008000, 0x7fffffff7fffffff},
    {0x4000ffff4000ffff, 0x0001400000014000, 0x0fffffff0fffffff},
    {0x4000ffff4000ffff, 0x4000000140000001, 0x0000000000000000},
    {0x80007fff80007fff, 0x7fffffff7fffffff, 0x3fff80013fff8001},
    {0x7fffffff7fffffff, 0x8000ffff8000ffff, 0x0000000100000001},
};

/* smdrs */
struct binary_calculation samples_smdrs[] = {
    {0x0001000100010001, 0x0000000100000001, 0x0000000100000001},
    {0x0001000100010001, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x0001001000010010, 0x80007fff80007fff, 0x00087ff000087ff0},
    {0x0001000100010001, 0x0000ffff0000ffff, 0xffffffffffffffff},
    {0x0001000200010002, 0x7fff80007fff8000, 0xfffe8001fffe8001},
    {0x00017fff00017fff, 0x8000ffff8000ffff, 0x0000000100000001},
    {0x0001ffff0001ffff, 0x0000ffff0000ffff, 0x0000000100000001},
    {0x0001ffff0001ffff, 0x7fff80007fff8000, 0x0000000100000001},
    {0x0001800000018000, 0x8000800080008000, 0x4000800040008000},
    {0x0001000000010000, 0x0000000000000000, 0x0000000000000000},
    {0x0001000000010000, 0x7fff7fff7fff7fff, 0xffff8001ffff8001},
    {0x0001000000010000, 0x8000800080008000, 0x0000800000008000},
    {0x8000800080008000, 0x8000800080008000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x00017fff00017fff, 0xffff0002ffff0002},
    {0x7fff00017fff0001, 0xffff7fffffff7fff, 0x0000fffe0000fffe},
};

/* smds */
struct binary_calculation samples_smds[] = {
    {0x0001000100010001, 0x0001000000010000, 0x0000000100000001},
    {0x0001000100010001, 0x7fff7fff7fff7fff, 0x0000000000000000},
    {0x0010000100100001, 0x7fff80007fff8000, 0x00087ff000087ff0},
    {0x0001000100010001, 0xffff0000ffff0000, 0xffffffffffffffff},
    {0x0002000100020001, 0x80007fff80007fff, 0xfffe8001fffe8001},
    {0x7fff00017fff0001, 0xffff8000ffff8000, 0x0000000100000001},
    {0xffff0001ffff0001, 0xffff0000ffff0000, 0x0000000100000001},
    {0xffff0001ffff0001, 0x80007fff80007fff, 0x0000000100000001},
    {0x8000000180000001, 0x8000800080008000, 0x4000800040008000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0xffff8001ffff8001},
    {0x0000000100000001, 0x8000800080008000, 0x0000800000008000},
    {0x8000800080008000, 0x8000800080008000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x00017fff00017fff, 0x0000fffe0000fffe},
    {0x7fff00017fff0001, 0xffff7fffffff7fff, 0xffff0002ffff0002},
};

/* smxds */
struct binary_calculation samples_smxds[] = {
    {0x0001000000010000, 0x0001000100010001, 0x0000000100000001},
    {0x7fff7fff7fff7fff, 0x0001000100010001, 0x0000000000000000},
    {0x7fff80007fff8000, 0x0001001000010010, 0x00087ff000087ff0},
    {0xffff0000ffff0000, 0x0001000100010001, 0xffffffffffffffff},
    {0x80007fff80007fff, 0x0001000200010002, 0xfffe8001fffe8001},
    {0xffff8000ffff8000, 0x00017fff00017fff, 0x0000000100000001},
    {0xffff0000ffff0000, 0x0001ffff0001ffff, 0x0000000100000001},
    {0x80007fff80007fff, 0x0001ffff0001ffff, 0x0000000100000001},
    {0x8000800080008000, 0x0001800000018000, 0x4000800040008000},
    {0x0000000000000000, 0x0001000000010000, 0x0000000000000000},
    {0x7fff7fff7fff7fff, 0x0001000000010000, 0xffff8001ffff8001},
    {0x8000800080008000, 0x0001000000010000, 0x0000800000008000},
    {0x8000800080008000, 0x8000800080008000, 0x0000000000000000},
    {0x7fff00017fff0001, 0x7fffffff7fffffff, 0xffff0002ffff0002},
    {0x7fffffff7fffffff, 0x7fff00017fff0001, 0x0000fffe0000fffe},
};

/* kmada */
struct ternary_calculation samples_kmada[] = {
    {0x0001000100010001, 0x0001000100010001, 0x0000000100000001, 0x0000000300000003},
    {0x80007fff80007fff, 0x80007fff80007fff, 0x8000000080000000, 0xffff0001ffff0001},
    {0x80007fff80007fff, 0x80007fff80007fff, 0xffffffffffffffff, 0x7fff00007fff0000},
    {0x80007fff80007fff, 0x80007fff80007fff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0x8000000080000000, 0x8000000080000000},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0xffffffffffffffff, 0x8000ffff8000ffff},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0x7fffffff7fffffff, 0x0000ffff0000ffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x8000000080000000, 0x8000000280000002},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0x0000000100000001},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0xffffffffffffffff, 0x8000800080008000, 0x8000000080000000, 0x8001000080010000},
    {0xffffffffffffffff, 0x8000800080008000, 0xffffffffffffffff, 0x0000ffff0000ffff},
    {0xffffffffffffffff, 0x8000800080008000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x8000ffff8000ffff, 0x8000ffff8000ffff, 0x8000000080000000, 0xc0000001c0000001},
    {0x8000ffff8000ffff, 0x8000ffff8000ffff, 0xffffffffffffffff, 0x4000000040000000},
    {0x8000ffff8000ffff, 0x8000ffff8000ffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0001000000010000, 0xffffffffffffffff, 0x0000000000000000, 0xffffffffffffffff},
    {0x0001ffff0001ffff, 0xffff0000ffff0000, 0x0000000000000000, 0xffffffffffffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0x0000000000000000, 0xffffffffffffffff},
    {0x0000ffff0000ffff, 0xffff0001ffff0001, 0x0000000000000000, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x7fff00007fff0000, 0x00017fff00017fff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x7fff00017fff0001, 0x0001ffff0001ffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
};

/* kmaxda */
struct ternary_calculation samples_kmaxda[] = {
    {0x0001000100010001, 0x0001000100010001, 0x0000000100000001, 0x0000000300000003},
    {0x80007fff80007fff, 0x7fff80007fff8000, 0x8000000080000000, 0xffff0001ffff0001},
    {0x80007fff80007fff, 0x7fff80007fff8000, 0xffffffffffffffff, 0x7fff00007fff0000},
    {0x80007fff80007fff, 0x7fff80007fff8000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0x8000000080000000, 0x8000000080000000},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0xffffffffffffffff, 0x8000ffff8000ffff},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0x7fffffff7fffffff, 0x0000ffff0000ffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x8000000080000000, 0x8000000280000002},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0x0000000100000001},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0xffffffffffffffff, 0x8000800080008000, 0x8000000080000000, 0x8001000080010000},
    {0xffffffffffffffff, 0x8000800080008000, 0xffffffffffffffff, 0x0000ffff0000ffff},
    {0xffffffffffffffff, 0x8000800080008000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x8000ffff8000ffff, 0xffff8000ffff8000, 0x8000000080000000, 0xc0000001c0000001},
    {0x8000ffff8000ffff, 0xffff8000ffff8000, 0xffffffffffffffff, 0x4000000040000000},
    {0x8000ffff8000ffff, 0xffff8000ffff8000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0001000000010000, 0xffffffffffffffff, 0x0000000000000000, 0xffffffffffffffff},
    {0x0001ffff0001ffff, 0x0000ffff0000ffff, 0x0000000000000000, 0xffffffffffffffff},
    {0x0000000100000001, 0xffffffffffffffff, 0x0000000000000000, 0xffffffffffffffff},
    {0x0000ffff0000ffff, 0x0001ffff0001ffff, 0x0000000000000000, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x7fff00017fff0001, 0xffff0001ffff0001, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0xffff0001ffff0001, 0x00017fff00017fff, 0x8000000080000000, 0x8000000080000000},
    {0x7fff00017fff0001, 0xffff0001ffff0001, 0x7fff00007fff0000, 0x7fff7ffe7fff7ffe},
};

/* kmadrs */
struct ternary_calculation samples_kmadrs[] = {
    {0x0001000100010001, 0x0001000100010001, 0x0000000100000001, 0x0000000100000001},
    {0x80007fff80007fff, 0x80007fff80007fff, 0x8000000080000000, 0x8000000080000000},
    {0x80007fff80007fff, 0x80007fff80007fff, 0xffffffffffffffff, 0xffff0000ffff0000},
    {0x80007fff80007fff, 0x80007fff80007fff, 0x7fffffff7fffffff, 0x7fff00007fff0000},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0x8000000080000000, 0x8000000080000000},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0xffffffffffffffff, 0x8000800080008000, 0x8000000080000000, 0x8000000080000000},
    {0xffffffffffffffff, 0x8000800080008000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x8000800080008000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x8000ffff8000ffff, 0x8000ffff8000ffff, 0x8000000080000000, 0x8000000080000000},
    {0x8000ffff8000ffff, 0x8000ffff8000ffff, 0xffffffffffffffff, 0xc0000000c0000000},
    {0x8000ffff8000ffff, 0x8000ffff8000ffff, 0x7fffffff7fffffff, 0x4000000040000000},
    {0x0001000000010000, 0xffffffffffffffff, 0x0000000000000000, 0x0000000100000001},
    {0x0001ffff0001ffff, 0xffff0000ffff0000, 0x0000000000000000, 0x0000000100000001},
    {0x0000000100000001, 0xffffffffffffffff, 0x0000000000000000, 0xffffffffffffffff},
    {0x0000ffff0000ffff, 0xffff0001ffff0001, 0x0000000000000000, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x7fff00017fff0001, 0xffff7fffffff7fff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0xffff7fffffff7fff, 0x0001ffff0001ffff, 0x8000000080000000, 0x8000000080000000},
    {0x7fff00007fff0000, 0xffff0000ffff0000, 0x7fff00007fff0000, 0x7fff7fff7fff7fff},
};

/* kmads */
struct ternary_calculation samples_kmads[] = {
    {0x0001000100010001, 0x0001000100010001, 0x0000000100000001, 0x0000000100000001},
    {0x7fff80007fff8000, 0x7fff80007fff8000, 0x8000000080000000, 0x8000000080000000},
    {0x7fff80007fff8000, 0x7fff80007fff8000, 0xffffffffffffffff, 0xffff0000ffff0000},
    {0x7fff80007fff8000, 0x7fff80007fff8000, 0x7fffffff7fffffff, 0x7fff00007fff0000},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0x8000000080000000, 0x8000000080000000},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0xffffffffffffffff, 0x8000800080008000, 0x8000000080000000, 0x8000000080000000},
    {0xffffffffffffffff, 0x8000800080008000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x8000800080008000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0xffff8000ffff8000, 0xffff8000ffff8000, 0x8000000080000000, 0x8000000080000000},
    {0xffff8000ffff8000, 0xffff8000ffff8000, 0xffffffffffffffff, 0xc0000000c0000000},
    {0xffff8000ffff8000, 0xffff8000ffff8000, 0x7fffffff7fffffff, 0x4000000040000000},
    {0x0000000100000001, 0xffffffffffffffff, 0x0000000000000000, 0x0000000100000001},
    {0xffff0001ffff0001, 0x0000ffff0000ffff, 0x0000000000000000, 0x0000000100000001},
    {0x0001000000010000, 0xffffffffffffffff, 0x0000000000000000, 0xffffffffffffffff},
    {0xffff0000ffff0000, 0x0001ffff0001ffff, 0x0000000000000000, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x7fff00017fff0001, 0x0001000100010001, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x7fff00017fff0001, 0xffff0001ffff0001, 0x8000000080000000, 0x8000000080000000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffff0000ffff0000, 0xfffe8000fffe8000},
};

/* kmaxds */
struct ternary_calculation samples_kmaxds[] = {
    {0x0001000100010001, 0x0001000100010001, 0x0000000100000001, 0x0000000100000001},
    {0x7fff80007fff8000, 0x80007fff80007fff, 0x8000000080000000, 0x8000000080000000},
    {0x7fff80007fff8000, 0x80007fff80007fff, 0xffffffffffffffff, 0xffff0000ffff0000},
    {0x7fff80007fff8000, 0x80007fff80007fff, 0x7fffffff7fffffff, 0x7fff00007fff0000},
    {0x8000800080008000, 0x7fff7fff7fff7fff, 0x8000000080000000, 0x8000000080000000},
    {0x8000800080008000, 0x7fff7fff7fff7fff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x8000800080008000, 0x7fff7fff7fff7fff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x8000800080008000, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0x8000800080008000, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x8000800080008000, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0xffff8000ffff8000, 0x8000ffff8000ffff, 0x8000000080000000, 0x8000000080000000},
    {0xffff8000ffff8000, 0x8000ffff8000ffff, 0xffffffffffffffff, 0xc0000000c0000000},
    {0xffff8000ffff8000, 0x8000ffff8000ffff, 0x7fffffff7fffffff, 0x4000000040000000},
    {0xffffffffffffffff, 0x0001000000010000, 0x0000000000000000, 0x0000000100000001},
    {0x0000ffff0000ffff, 0x0001ffff0001ffff, 0x0000000000000000, 0x0000000100000001},
    {0xffffffffffffffff, 0x0000000100000001, 0x0000000000000000, 0xffffffffffffffff},
    {0x0001ffff0001ffff, 0x0000ffff0000ffff, 0x0000000000000000, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0001000100010001, 0x00017fff00017fff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0x0001ffff0001ffff, 0x8000000080000000, 0x8000000080000000},
    {0xffff8000ffff8000, 0xffff7fffffff7fff, 0x4000ffff4000ffff, 0x4000000040000000},
};

/* kmsda */
struct ternary_calculation samples_kmsda[] = {
    {0x0001000100010001, 0x0001000100010001, 0x0000000100000001, 0xffffffffffffffff},
    {0x80007fff80007fff, 0x80007fff80007fff, 0x8000000080000000, 0x8000000080000000},
    {0x80007fff80007fff, 0x80007fff80007fff, 0xffffffffffffffff, 0x8000fffe8000fffe},
    {0x80007fff80007fff, 0x80007fff80007fff, 0x7fffffff7fffffff, 0x0000fffe0000fffe},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0x8000000080000000, 0xffff0000ffff0000},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0xffffffffffffffff, 0x7ffeffff7ffeffff},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffdfffffffd},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7ffffffd7ffffffd},
    {0xffffffffffffffff, 0x8000800080008000, 0x8000000080000000, 0x8000000080000000},
    {0xffffffffffffffff, 0x8000800080008000, 0xffffffffffffffff, 0xfffefffffffeffff},
    {0xffffffffffffffff, 0x8000800080008000, 0x7fffffff7fffffff, 0x7ffeffff7ffeffff},
    {0x8000ffff8000ffff, 0x8000ffff8000ffff, 0x8000000080000000, 0x8000000080000000},
    {0x8000ffff8000ffff, 0x8000ffff8000ffff, 0xffffffffffffffff, 0xbffffffebffffffe},
    {0x8000ffff8000ffff, 0x8000ffff8000ffff, 0x7fffffff7fffffff, 0x3ffffffe3ffffffe},
    {0x0001000000010000, 0xffffffffffffffff, 0x0000000000000000, 0x0000000100000001},
    {0x0001ffff0001ffff, 0xffff0000ffff0000, 0x0000000000000000, 0x0000000100000001},
    {0x0000000100000001, 0xffffffffffffffff, 0x0000000000000000, 0x0000000100000001},
    {0x0000ffff0000ffff, 0xffff0001ffff0001, 0x0000000000000000, 0x0000000100000001},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0xffff0001ffff0001, 0x7fff00017fff0001, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0x0001000100010001, 0x8000000080000000, 0x8000000080000000},
    {0xffff7fffffff7fff, 0x8000ffff8000ffff, 0x7fff80007fff8000, 0x7fff7fff7fff7fff},
};

/* kmsxda */
struct ternary_calculation samples_kmsxda[] = {
    {0x0001000100010001, 0x0001000100010001, 0x0000000100000001, 0xffffffffffffffff},
    {0x80007fff80007fff, 0x7fff80007fff8000, 0x8000000080000000, 0x8000000080000000},
    {0x80007fff80007fff, 0x7fff80007fff8000, 0xffffffffffffffff, 0x8000fffe8000fffe},
    {0x80007fff80007fff, 0x7fff80007fff8000, 0x7fffffff7fffffff, 0x0000fffe0000fffe},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0x8000000080000000, 0xffff0000ffff0000},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0xffffffffffffffff, 0x7ffeffff7ffeffff},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x8000000080000000, 0x8000000080000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffdfffffffd},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7ffffffd7ffffffd},
    {0xffffffffffffffff, 0x8000800080008000, 0x8000000080000000, 0x8000000080000000},
    {0xffffffffffffffff, 0x8000800080008000, 0xffffffffffffffff, 0xfffefffffffeffff},
    {0xffffffffffffffff, 0x8000800080008000, 0x7fffffff7fffffff, 0x7ffeffff7ffeffff},
    {0x8000ffff8000ffff, 0xffff8000ffff8000, 0x8000000080000000, 0x8000000080000000},
    {0x8000ffff8000ffff, 0xffff8000ffff8000, 0xffffffffffffffff, 0xbffffffebffffffe},
    {0x8000ffff8000ffff, 0xffff8000ffff8000, 0x7fffffff7fffffff, 0x3ffffffe3ffffffe},
    {0x0001000000010000, 0xffffffffffffffff, 0x0000000000000000, 0x0000000100000001},
    {0x0001ffff0001ffff, 0x0000ffff0000ffff, 0x0000000000000000, 0x0000000100000001},
    {0x0000000100000001, 0xffffffffffffffff, 0x0000000000000000, 0x0000000100000001},
    {0x0000ffff0000ffff, 0x0001ffff0001ffff, 0x0000000000000000, 0x0000000100000001},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x7fff00017fff0001, 0x0001ffff0001ffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0x00017fff00017fff, 0x8000000080000000, 0x8000000080000000},
    {0xffff7fffffff7fff, 0xffff8000ffff8000, 0x7fff80007fff8000, 0x7fff7fff7fff7fff},
};

/* smal */
struct binary_calculation samples_smal[] = {
    {0x0000000000000001, 0x0001000100010001, 0x0000000000000003},
    {0x8000000000000000, 0x800080007fff7fff, 0x800000007fff0001},
    {0xffffffffffffffff, 0x800080007fff7fff, 0x000000007fff0000},
    {0x7fffffffffffffff, 0x800080007fff7fff, 0x800000007fff0000},
    {0x8000000000000000, 0x7fff80007fff8000, 0x7fffffff80010000},
    {0xffffffffffffffff, 0x7fff80007fff8000, 0xffffffff8000ffff},
    {0x7fffffffffffffff, 0x7fff80007fff8000, 0x7fffffff8000ffff},
    {0x8000000000000000, 0xffffffffffffffff, 0x8000000000000002},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000001},
    {0x7fffffffffffffff, 0xffffffffffffffff, 0x8000000000000001},
    {0x8000000000000000, 0xffff8000ffff8000, 0x8000000000010000},
    {0xffffffffffffffff, 0xffff8000ffff8000, 0x000000000000ffff},
    {0x7fffffffffffffff, 0xffff8000ffff8000, 0x800000000000ffff},
    {0x8000000000000000, 0x80008000ffffffff, 0x8000000040000001},
    {0xffffffffffffffff, 0x80008000ffffffff, 0x0000000040000000},
    {0x7fffffffffffffff, 0x80008000ffffffff, 0x8000000040000000},
    {0x0000000000000000, 0x0001ffff0000ffff, 0xffffffffffffffff},
    {0x0000000000000000, 0x0001ffffffff0000, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000ffff0001ffff, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000ffffffff0001, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x800000007fff4000, 0x7fff800040000000, 0x800000003fffc000},
    {0x7fffffff4000ff00, 0x40007fffff00ffff, 0x7fffffff6000c000},
};

/* mulr64 */
struct binary_calculation samples_mulr64[] = {
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x3fffffff00000001},
    {0x8000000080000000, 0x8000000080000000, 0x4000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffe00000001},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x3fffffff80000000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x3fffffff80000000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x7ffffffe80000001},
    {0xffffffffffffffff, 0x7fffffff7fffffff, 0x7ffffffe80000001},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x8000000080000000, 0xffffffffffffffff, 0x7fffffff80000000},
    {0xffffffffffffffff, 0x8000000080000000, 0x7fffffff80000000},
    {0x0000000000000000, 0x8000000080000000, 0x0000000000000000},
    {0x8000000080000000, 0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
};

/* mulsr64 */
struct binary_calculation samples_mulsr64[] = {
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x3fffffff00000001},
    {0x8000000080000000, 0x8000000080000000, 0x4000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000001},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0xc000000080000000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0xc000000080000000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffffffff80000001},
    {0xffffffffffffffff, 0x7fffffff7fffffff, 0xffffffff80000001},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x8000000080000000, 0xffffffffffffffff, 0x0000000080000000},
    {0xffffffffffffffff, 0x8000000080000000, 0x0000000080000000},
    {0x0000000000000000, 0x8000000080000000, 0x0000000000000000},
    {0x8000000080000000, 0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x3fffffff00000001},
};

/* ave */
struct binary_calculation samples_ave[] = {
    {0x7fffffffffffffff, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x8000000000000000, 0x8000000000000000, 0x8000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x0000000000000000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x3fffffffbfffffff},
    {0xffffffffffffffff, 0x7fffffff7fffffff, 0x3fffffffbfffffff},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x3fffffffc0000000},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x3fffffffc0000000},
    {0x8000000080000000, 0xffffffffffffffff, 0xc000000040000000},
    {0xffffffffffffffff, 0x8000000080000000, 0xc000000040000000},
    {0x0000000000000000, 0x8000000080000000, 0xc000000040000000},
    {0x8000000080000000, 0x0000000000000000, 0xc000000040000000},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
};

/* umar64 */
struct ternary_ul_ul_64_calculation samples_umar64[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000001, 0x0000000000000003},
    {0x0000000100000001, 0x0000000100000001, 0xffffffffffffffff, 0x0000000000000001},
    {0x0000000100000001, 0x0000000100000001, 0x8000000000000000, 0x8000000000000002},
    {0x0000000100000001, 0x0000000100000001, 0x7fffffffffffffff, 0x8000000000000001},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff, 0x00000001fffffffd},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000000000000, 0x80000001fffffffe},
    {0x0000000100000001, 0xffffffffffffffff, 0x7fffffffffffffff, 0x80000001fffffffd},
    {0x8000000080000000, 0x8000000080000000, 0xffffffffffffffff, 0x7fffffffffffffff},
    {0x8000000080000000, 0x8000000080000000, 0x8000000000000000, 0x0000000000000000},
    {0x8000000080000000, 0x8000000080000000, 0x7fffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffd00000001},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x8000000000000000, 0x7ffffffd00000002},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x7fffffffffffffff, 0x7ffffffd00000001},
    {0x0000000000000000, 0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
};

/* smar64 */
struct ternary_ul_ul_64_calculation samples_smar64[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000001, 0x0000000000000003},
    {0x0000000100000001, 0x0000000100000001, 0xffffffffffffffff, 0x0000000000000001},
    {0x0000000100000001, 0x0000000100000001, 0x8000000000000000, 0x8000000000000002},
    {0x0000000100000001, 0x0000000100000001, 0x7fffffffffffffff, 0x8000000000000001},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffffffffffd},
    {0x0000000100000001, 0xffffffffffffffff, 0x8000000000000000, 0x7ffffffffffffffe},
    {0x0000000100000001, 0xffffffffffffffff, 0x7fffffffffffffff, 0x7ffffffffffffffd},
    {0x8000000080000000, 0x8000000080000000, 0xffffffffffffffff, 0x7fffffffffffffff},
    {0x8000000080000000, 0x8000000080000000, 0x8000000000000000, 0x0000000000000000},
    {0x8000000080000000, 0x8000000080000000, 0x7fffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffff00000001},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x8000000000000000, 0x7fffffff00000002},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x7fffffffffffffff, 0x7fffffff00000001},
    {0x0000000000000000, 0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
};

/* maddr32 */
struct ternary_calculation samples_maddr32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000, 0x0000000000000001},
    {0x0000000200000002, 0x4000000040000000, 0x0000000000000000, 0xffffffff80000000},
    {0x0000000100000001, 0xFFFFFFFFFFFFFFFF, 0x0000000000000000, 0xFFFFFFFFFFFFFFFF},
    {0x0000000100000001, 0x0000000100000001, 0x0000000100000001, 0x0000000000000002},
    {0x0000000200000002, 0x2000000020000000, 0x4000000040000000, 0xffffffff80000000},
    {0x0000000200000002, 0x8000000080000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000200000002, 0x8000000180000001, 0x0000000000000000, 0x0000000000000002},
    {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0x0000000000000000, 0x0000000000000001},
    {0x8000000080000000, 0x8000000080000000, 0x0000000000000000, 0x0000000000000000},
    {0x8000000080000000, 0x8000000080000000, 0x8000000080000000, 0xffffffff80000000},
    {0x0000010000000100, 0x1000000110000001, 0xFFFFFFFFFFFFFFFF, 0x00000000000000FF},
    {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0x0000000000000000},
    {0x0000000000000000, 0x0000000100000001, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0xFFFFFFFFFFFFFFFF, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x0000000100000001, 0x0000000100000001, 0x0000000000000001},
    {0x0000000000000000, 0x0000000000000000, 0x0000000100000001, 0x0000000000000001},
    {0x0000000000000000, 0xFFFFFFFFFFFFFFFF, 0x0000000100000001, 0x0000000000000001},
};

/* insb */
struct ternary_calculation samples_insb[] = {
    {0x0000000100000002, 0x0000000300000001, 0x0000000000000000, 0x0000000100000001},
    {0x0000000100000002, 0x0000000300000101, 0x0000000000000001, 0x0000000100000102},
    {0x1111111122222222, 0x0000000300010001, 0x0000000000000002, 0x1111111122012222},
    {0x0000000300000001, 0x1111111122222222, 0x0000000000000003, 0x0000000322000001},
    {0x0000000000000000, 0x00000000000000ff, 0x0000000000000004, 0x000000ff00000000},
    {0x1234567812345678, 0x1234657812345678, 0x0000000000000005, 0x1234787812345678},
    {0x8000000080000000, 0x7fffffffffffffff, 0x0000000000000006, 0x80ff000080000000},
    {0x8000000000000000, 0x7fffffffffffffff, 0x0000000000000007, 0xff00000000000000},
};

/* smmul */
struct binary_calculation samples_smmul[] = {
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x3fffffff3fffffff},
    {0x8000000080000000, 0x8000000080000000, 0x4000000040000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0xc0000000c0000000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0xc0000000c0000000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x7fffffff7fffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x8000000080000000, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x8000000080000000, 0x0000000000000000},
    {0x0000000000000000, 0x8000000080000000, 0x0000000000000000},
    {0x8000000080000000, 0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
};

/* smmul.u */
struct binary_calculation samples_smmul_u[] = {
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x3fffffff3fffffff},
    {0x8000000080000000, 0x8000000080000000, 0x4000000040000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0xc0000001c0000001},
    {0x8000000080000000, 0x7fffffff7fffffff, 0xc0000001c0000001},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x8000000080000000, 0xffffffffffffffff, 0x0000000100000001},
    {0xffffffffffffffff, 0x8000000080000000, 0x0000000100000001},
    {0x0000000000000000, 0x8000000080000000, 0x0000000000000000},
    {0x8000000080000000, 0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0x0000000100000001, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x0000000200000002, 0x7fffffff7fffffff, 0x0000000100000001},
};

/* smbb16 */
struct binary_calculation samples_smbb16[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000100000001},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x00007fff00007fff},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000100000001},
    {0x0000800000008000, 0x8000800080008000, 0x4000000040000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x8000000080000000, 0x0000800000008000, 0x0000000000000000},
    {0xffff7fffffff7fff, 0xffff7fffffff7fff, 0x3fff00013fff0001},
    {0xffff7fffffff7fff, 0x7fffffff7fffffff, 0xffff8001ffff8001},
    {0xffff8000ffff8000, 0xffff8000ffff8000, 0x4000000040000000},
    {0xffff8000ffff8000, 0x8000ffff8000ffff, 0x0000800000008000},
};

/* smtt16 */
struct binary_calculation samples_smtt16[] = {
    {0x0001000000010000, 0x0001000000010000, 0x0000000100000001},
    {0x0001000000010000, 0x7fff7fff7fff7fff, 0x00007fff00007fff},
    {0x0001000000010000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000100000001},
    {0x8000000080000000, 0x8000800080008000, 0x4000000040000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0xffff7fffffff7fff, 0x0000000000000000},
    {0x8000000080000000, 0x8000000080000000, 0x4000000040000000},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x3fff00013fff0001},
    {0x8000ffff8000ffff, 0x8000ffff8000ffff, 0x4000000040000000},
    {0xffff8000ffff8000, 0x8000ffff8000ffff, 0x0000800000008000},
    {0x7fffffff7fffffff, 0x80007fff80007fff, 0xc0008000c0008000},
    {0x0001ffff0001ffff, 0xffff7fffffff7fff, 0xffffffffffffffff},
};

/* smbt16 */
struct binary_calculation samples_smbt16[] = {
    {0x0000000100000001, 0x0001000000010000, 0x0000000100000001},
    {0x7fff7fff7fff7fff, 0x0001000000010000, 0x00007fff00007fff},
    {0xffffffffffffffff, 0x0001000000010000, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000100000001},
    {0x8000800080008000, 0x8000000080000000, 0x4000000040000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x0000000000000000},
    {0x0000800000008000, 0x8000000080000000, 0x4000000040000000},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0xffff8001ffff8001},
    {0x7fffffff7fffffff, 0x0001ffff0001ffff, 0xffffffffffffffff},
    {0xffff7fffffff7fff, 0x7fffffff7fffffff, 0x3fff00013fff0001},
    {0x7fff80007fff8000, 0x8000ffff8000ffff, 0x4000000040000000},
};

/* add32 */
struct binary_calculation samples_add32[] = {
    {0x1234567812345678, 0x1111222211112222, 0x2345789A2345789A},
    {0x9000A0009000A000, 0xA000B000A000B000, 0x3001500030015000},
    {0xFFFF8000FFFF8000, 0x0000800000008000, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffefffffffe},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x8000000080000000, 0xffffffffffffffff},
    {0x8888888888888888, 0x8888888888888888, 0x1111111011111110},
};

/* uradd32 */
struct binary_calculation samples_uradd32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000100000001},
    {0x8080808280808082, 0x8080808080808080, 0x8080808180808081},
    {0x8000000080000000, 0x8000000080000000, 0x8000000080000000},
    {0x0000000000000000, 0xffffffffffffffff, 0x7fffffff7fffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
};

/* radd32 */
struct binary_calculation samples_radd32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000100000001},
    {0x8080808280808082, 0x8080808080808080, 0x8080808180808081},
    {0x8000000080000000, 0x8000000080000000, 0x8000000080000000},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x3fffffff3fffffff},
    {0x7fffffff7fffffff, 0x7ffffff97ffffff9, 0x7ffffffc7ffffffc},
    {0x8000000280000002, 0x8000000080000000, 0x8000000180000001},
};

/* kadd32 */
struct binary_calculation samples_kadd32[] = {
    {0x1234567812345678, 0x1111222211112222, 0x2345789A2345789A},
    {0x4000000090000000, 0x4000000090000000, 0x7fffffff80000000},
    {0x8000000080000000, 0x0000000100000001, 0x8000000180000001},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffefffffffe},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x8000000080000000, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x7ffffffe7ffffffe},
    {0x8888888888888888, 0x8888888888888888, 0x8000000080000000},
};

/* ukadd32 */
struct binary_calculation samples_ukadd32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000200000002},
    {0x0000000100000001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0001000100010001, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0001000100010001, 0x0001ffff0001ffff, 0x0003000000030000},
    {0x0001000000010000, 0x00ff000000ff0000, 0x0100000001000000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000100000001},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x8000800080008000, 0x0000000000000000, 0x8000800080008000},
    {0x8000800080008000, 0x7fff7fff7fff7fff, 0xffffffffffffffff},
    {0x8888888888888888, 0x8888000088880000, 0xffffffffffffffff},
};

/* sub32 */
struct binary_calculation samples_sub32[] = {
    {0x2345789A2345789A, 0x1234567812345678, 0x1111222211112222},
    {0x3001500030015000, 0x9000A0009000A000, 0xA000B000A000B000},
    {0x0000000000000000, 0xFFFF8000FFFF8000, 0x0000800000008000},
    {0xfffffffefffffffe, 0xffffffffffffffff, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0000000000000000, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x7fff7fff7fff7fff, 0x8000800080008000},
    {0xffffffffffffffff, 0x7fffffff7fffffff, 0x8000000080000000},
    {0x1111111011111110, 0x8888888888888888, 0x8888888888888888},
};
/* rsub32 */
struct binary_calculation samples_rsub32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0x0000000100000001, 0x0000000200000002, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xfffffffefffffffe, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x4000000040000000},
    {0x8000000080000000, 0x0000000100000001, 0xbfffffffbfffffff},
    {0x0000000000000000, 0x7fffffff7fffffff, 0xc0000000c0000000},
    {0x0000000000000000, 0x8000000080000000, 0x4000000040000000},
    {0x8000000080000000, 0x0000000000000000, 0xc0000000c0000000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x8000000080000000},
    {0x0000000100000001, 0x0000001000000010, 0xfffffff8fffffff8},
};

/* ursub32 */
struct binary_calculation samples_ursub32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0x0000000100000001, 0x0000000200000002, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0000000000000000, 0x7fffffff7fffffff},
    {0x0000000000000000, 0xffffffffffffffff, 0x8000000080000000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0xffffffffffffffff},
    {0x0000000000000000, 0x7fffffff7fffffff, 0xc0000000c0000000},
    {0x1111111111111111, 0x2222222222222222, 0xf7777777f7777777},
    {0x7fffffff7fffffff, 0x8000000080000000, 0xffffffffffffffff},
};

/* ksub32 */
struct binary_calculation samples_ksub32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x0000000100000001, 0x8000000080000000},
    {0x0000800000008000, 0x0000000100000001, 0x00007fff00007fff},
    {0x00007fff00007fff, 0x0000ffff0000ffff, 0xffff8000ffff8000},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x8000000080000000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x7fffffff7fffffff},
    {0xaaaaaaaaaaaaaaaa, 0x7fffffff7fffffff, 0x8000000080000000},
    {0x7fff00007fff0000, 0xbbbb0000bbbb0000, 0x7fffffff7fffffff},
};

/* uksub32 */
struct binary_calculation samples_uksub32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0x0000000100000001, 0x0000000200000002, 0x0000000000000000},
    {0x0001000100010001, 0x0002000200020002, 0x0000000000000000},
    {0x0101010101010101, 0x0202020202020202, 0x0000000000000000},
    {0x1000000010000000, 0x0222222202222222, 0x0dddddde0dddddde},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000000000000, 0xffffffffffffffff},
    {0x1111111111111111, 0x2222222222222222, 0x0000000000000000},
    {0x2222222222222222, 0x1111111111111111, 0x1111111111111111},
};


/* cras32 */
struct binary_calculation samples_cras32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000200000000},
    {0x1111111123456789, 0x1111111112345678, 0x2345678912345678},
    {0x7fffffff7fffffff, 0x0000000100000001, 0x800000007ffffffe},
    {0xffffffffffffffff, 0x0000000100000001, 0x00000000fffffffe},
    {0x8000000080000000, 0x0000000100000001, 0x800000017fffffff},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffff00000001},
    {0x7fffffffffffffff, 0xffffffffffffffff, 0x7ffffffe00000000},
    {0xffffffffffffffff, 0x8000000080000000, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x7fffffff7fffffff, 0xffffffff00000001},
    {0x1111111111111111, 0x2222222222222222, 0x33333333eeeeeeef},
};

/* rcras32 */
struct binary_calculation samples_rcras32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000100000000},
    {0x8080808200000001, 0x0000000280808080, 0x80808081ffffffff},
    {0x80000000ffffffff, 0xfffffffe80000000, 0x8000000000000000},
    {0x000000007fffffff, 0xffffffffffffffff, 0xffffffff40000000},
    {0x7fffffff80000000, 0x00000001ffffffff, 0x3fffffffbfffffff},
    {0x7fffffff00000000, 0x7fffffff7ffffff9, 0x7ffffffcc0000000},
    {0x8000000200000000, 0x8000000080000000, 0x8000000140000000},
    {0xffffffff80000000, 0x0000000080000000, 0xbfffffffc0000000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0xffffffff80000000},
    {0xffffffff00000001, 0x0000001022222222, 0x11111110fffffff8},
};

/* urcras32 */
struct binary_calculation samples_urcras32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000100000000},
    {0x8080808200000001, 0x0000000280808080, 0x80808081ffffffff},
    {0x80000000ffffffff, 0x0000000080000000, 0x800000007fffffff},
    {0x0000000000000000, 0xffffffffffffffff, 0x7fffffff80000000},
    {0xffffffff7fffffff, 0x80000000ffffffff, 0xffffffffffffffff},
    {0x7fffffff00000000, 0x7fffffff7fffffff, 0x7fffffffc0000000},
};

/* kcras32 */
struct binary_calculation samples_kcras32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000200000000},
    {0x1111111123456789, 0x1111111112345678, 0x2345678912345678},
    {0x7fffffff7fffffff, 0x0000000100000001, 0x7fffffff7ffffffe},
    {0xffffffffffffffff, 0x0000000100000001, 0x00000000fffffffe},
    {0x8000000080000000, 0x0000000100000001, 0x8000000180000000},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffff00000001},
    {0x7fffffffffffffff, 0xffffffffffffffff, 0x7ffffffe00000000},
    {0xffffffffffffffff, 0x8000000080000000, 0x800000007fffffff},
    {0x8000000080000000, 0x7fffffff7fffffff, 0xffffffff80000000},
    {0x1111111111111111, 0x2222222222222222, 0x33333333eeeeeeef},
};

/* ukcras32 */
struct binary_calculation samples_ukcras32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000200000000},
    {0x0000000100000001, 0x00000002ffffffff, 0xffffffff00000000},
    {0x0001000100010001, 0x00020002ffffffff, 0xffffffff00000000},
    {0x0001000101010101, 0x020202020001ffff, 0x0003000000000000},
    {0x0001000010000000, 0x0222222200ff0000, 0x010000000dddddde},
    {0x0000000100000000, 0xffffffff00000000, 0x0000000100000000},
    {0x00000000ffffffff, 0x00000000ffffffff, 0xffffffffffffffff},
    {0xffffffff11111111, 0x22222222ffffffff, 0xffffffff00000000},
    {0x0000000022222222, 0x1111111100000000, 0x0000000011111111},
};

/* crsa32 */
struct binary_calculation samples_crsa32[] = {
    {0x0000000200000000, 0x0000000100000001, 0x0000000100000001},
    {0x2345678912345678, 0x1111111112345678, 0x1111111123456789},
    {0x800000007ffffffe, 0x0000000100000001, 0x7fffffff7fffffff},
    {0x00000000fffffffe, 0x0000000100000001, 0xffffffffffffffff},
    {0x800000017ffffffe, 0x0000000100000001, 0x800000007fffffff},
    {0xffffffff00000001, 0xffffffffffffffff, 0x0000000000000000},
    {0x7ffffffe00000000, 0xffffffffffffffff, 0x7fffffffffffffff},
    {0x7fffffff7fffffff, 0x8000000080000000, 0xffffffffffffffff},
    {0xffffffff00000001, 0x7fffffff7fffffff, 0x8000000080000000},
    {0x33333333eeeeeeef, 0x2222222222222222, 0x1111111111111111},
};

/* rcrsa32 */
struct binary_calculation samples_rcrsa32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000001},
    {0x0000000180808082, 0x8080808000000002, 0xffffffff80808081},
    {0xffffffff80000000, 0x80000000fffffffe, 0x0000000080000000},
    {0x7fffffff00000000, 0xffffffffffffffff, 0x40000000ffffffff},
    {0x800000007fffffff, 0xffffffff00000001, 0xbfffffff3fffffff},
    {0x000000007fffffff, 0x7ffffff97fffffff, 0xc00000007ffffffc},
    {0x0000000080000002, 0x8000000080000000, 0x4000000080000001},
};

/* urcrsa32 */
struct binary_calculation samples_urcrsa32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000001},
    {0x0000000180808082, 0x8080808000000002, 0xffffffff80808081},
    {0xffffffff80000000, 0x8000000000000000, 0x7fffffff80000000},
    {0x0000000000000000, 0xffffffffffffffff, 0x800000007fffffff},
    {0x7fffffffffffffff, 0xffffffff80000000, 0xffffffffffffffff},
    {0x000000007fffffff, 0x7fffffff7fffffff, 0xc00000007fffffff},
};

/* kcrsa32 */
struct binary_calculation samples_kcrsa32[] = {
    {0x0000000200000000, 0x0000000100000001, 0x0000000100000001},
    {0x2345678912345678, 0x1111111112345678, 0x1111111123456789},
    {0x800000007ffffffe, 0x0000000100000001, 0x800000007fffffff},
    {0x00000000fffffffe, 0x0000000100000001, 0xffffffffffffffff},
    {0x800000017ffffffe, 0x0000000100000001, 0x800000007fffffff},
    {0xffffffff00000001, 0xffffffffffffffff, 0x0000000000000000},
    {0x7ffffffe00000000, 0xffffffffffffffff, 0x7fffffffffffffff},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x7fffffffffffffff},
    {0xffffffff00000001, 0x7fffffff7fffffff, 0x800000007fffffff},
    {0x33333333eeeeeeef, 0x2222222222222222, 0x1111111111111111},
};

/* ukcrsa32 */
struct binary_calculation samples_ukcrsa32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000002},
    {0x0000000100000001, 0xffffffff00000002, 0x00000000ffffffff},
    {0x0001000100010001, 0xffffffff00020002, 0x00000000ffffffff},
    {0x0101010100010001, 0x0001ffff02020202, 0x0000000000030000},
    {0x1000000000010000, 0x00ff000002222222, 0x0dddddde01000000},
    {0x0000000000000001, 0x00000000ffffffff, 0x0000000000000001},
    {0xffffffff00000000, 0xffffffff00000000, 0xffffffffffffffff},
    {0x11111111ffffffff, 0xffffffff22222222, 0x00000000ffffffff},
    {0x2222222200000000, 0x0000000011111111, 0x1111111100000000},

};

/* stas32 */
struct binary_calculation samples_stas32[] = {
    {0x123456782345789A, 0x1111222212345678, 0x2345789A11112222},
    {0x9000A00030015000, 0xA000B0009000A000, 0x30015000A000B000},
    {0xFFFF800000000000, 0x00008000FFFF8000, 0x0000000000008000},
    {0xfffffffffffffffe, 0xffffffffffffffff, 0xfffffffeffffffff},
    {0x00000000ffffffff, 0xffffffff00000000, 0xffffffffffffffff},
    {0x7fff7fffffffffff, 0x800080007fff7fff, 0xffffffff80008000},
    {0x7fffffffffffffff, 0x800000007fffffff, 0xffffffff80000000},
    {0x8888888811111110, 0x8888888888888888, 0x1111111088888888},
};

/* rstas32 */
struct binary_calculation samples_rstas32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000100000000},
    {0x8080808200000001, 0x8080808000000002, 0x80808081ffffffff},
    {0x80000000ffffffff, 0x80000000fffffffe, 0x8000000000000000},
    {0x000000007fffffff, 0xffffffffffffffff, 0xffffffff40000000},
    {0x7fffffff80000000, 0xffffffff00000001, 0x3fffffffbfffffff},
    {0x7fffffff00000000, 0x7ffffff97fffffff, 0x7ffffffcc0000000},
    {0x8000000200000000, 0x8000000080000000, 0x8000000140000000},

};

/* urstas32 */
struct binary_calculation samples_urstas32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000100000000},
    {0x8080808200000001, 0x8080808000000002, 0x80808081ffffffff},
    {0x80000000ffffffff, 0x8000000000000000, 0x800000007fffffff},
    {0x0000000000000000, 0xffffffffffffffff, 0x7fffffff80000000},
    {0xffffffff7fffffff, 0xffffffff80000000, 0xffffffffffffffff},
    {0x7fffffff00000000, 0x7fffffff7fffffff, 0x7fffffffc0000000},
};

/* kstas32 */
struct binary_calculation samples_kstas32[] = {
    {0x1234567800000001, 0x1111222200000001, 0x2345789A00000000},
    {0x40000000ffffffff, 0x40000000ffffffff, 0x7fffffff00000000},
    {0x800000007fffffff, 0x00000001ffffffff, 0x800000017fffffff},
    {0xffffffff80000000, 0xffffffff00000001, 0xfffffffe80000000},
    {0x0000000000008000, 0xffffffff00000001, 0xffffffff00007fff},
    {0x7fffffff00007fff, 0x800000000000ffff, 0xffffffffffff8000},
    {0x7fffffff7fffffff, 0xffffffff00000000, 0x7ffffffe7fffffff},
    {0x8888888880000000, 0x888888887fffffff, 0x8000000080000000},
};

/* ukstas32 */
struct binary_calculation samples_ukstas32[] = {
    {0x0001000100000001, 0x0001ffff00000001, 0x0003000000000000},
    {0x0001000000000001, 0x00ff000000000002, 0x0100000000000000},
    {0x0000000100010001, 0x0000000000020002, 0x0000000100000000},
    {0x0000000001010101, 0xffffffff02020202, 0xffffffff00000000},
    {0xffffffff10000000, 0xffffffff02222222, 0xffffffff0dddddde},
    {0x0000000000000000, 0x00000000ffffffff, 0x0000000000000000},
    {0x80008000ffffffff, 0x0000000000000000, 0x80008000ffffffff},
    {0x8000800011111111, 0x7fff7fff22222222, 0xffffffff00000000},
    {0x8888888822222222, 0x8888000011111111, 0xffffffff11111111},
};

/* stsa32 */
struct binary_calculation samples_stsa32[] = {
    {0x2345789A12345678, 0x1234567811112222, 0x111122222345789A},
    {0x300150009000A000, 0x9000A000A000B000, 0xA000B00030015000},
    {0x00000000FFFF8000, 0xFFFF800000008000, 0x0000800000000000},
    {0xfffffffeffffffff, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0xffffffff00000000, 0x00000000ffffffff, 0xffffffffffffffff},
    {0xffffffff7fff7fff, 0x7fff7fff80008000, 0x80008000ffffffff},
    {0xffffffff7fffffff, 0x7fffffff80000000, 0x80000000ffffffff},
    {0x1111111088888888, 0x8888888888888888, 0x8888888811111110},
};

/* rstsa32 */
struct binary_calculation samples_rstsa32[] = {
    {0xffffffff00000001, 0xfffffffe00000001, 0x0000000000000001},
    {0x7fffffff80808082, 0xffffffff80808080, 0x4000000080808081},
    {0x8000000080000000, 0x0000000180000000, 0xbfffffff80000000},
    {0x0000000000000000, 0x7fffffffffffffff, 0xc0000000ffffffff},
    {0x000000007fffffff, 0x80000000ffffffff, 0x400000003fffffff},
    {0x800000007fffffff, 0x000000007ffffff9, 0xc00000007ffffffc},
    {0x8000000080000002, 0x7fffffff80000000, 0x8000000080000001},
};

/* urstsa32 */
struct binary_calculation samples_urstsa32[] = {
    {0xffffffff00000001, 0x0000000000000001, 0x7fffffff00000001},
    {0x0000000080808082, 0xffffffff80808080, 0x8000000080808081},
    {0x7fffffff80000000, 0x8000000080000000, 0xffffffff80000000},
    {0x0000000000000000, 0x7fffffffffffffff, 0xc00000007fffffff},
    {0x11111111ffffffff, 0x22222222ffffffff, 0xf7777777ffffffff},
    {0x7fffffff7fffffff, 0x800000007fffffff, 0xffffffff7fffffff},
};

/* kstsa32 */
struct binary_calculation samples_kstsa32[] = {
    {0x8000000012345678, 0x0000000111112222, 0x800000002345789A},
    {0x0000800090000000, 0x0000000190000000, 0x00007fff80000000},
    {0x00007fff80000000, 0x0000ffff00000001, 0xffff800080000001},
    {0x7fffffffffffffff, 0x00000000ffffffff, 0x7ffffffffffffffe},
    {0x8000000000000000, 0x7fffffffffffffff, 0x80000000ffffffff},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x7fffffffffffffff},
    {0xaaaaaaaa7fffffff, 0x7fffffffffffffff, 0x800000007ffffffe},
    {0x7fff000088888888, 0xbbbb000088888888, 0x7fffffff80000000},
};

/* ukstsa32 */
struct binary_calculation samples_ukstsa32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000002},
    {0x0000000100000001, 0x00000002ffffffff, 0x00000000ffffffff},
    {0x0001000100010001, 0x00020002ffffffff, 0x00000000ffffffff},
    {0x0101010100010001, 0x020202020001ffff, 0x0000000000030000},
    {0x1000000000010000, 0x0222222200ff0000, 0x0dddddde01000000},
    {0x0000000000000001, 0xffffffff00000000, 0x0000000000000001},
    {0xffffffff00000000, 0x00000000ffffffff, 0xffffffffffffffff},
    {0x11111111ffffffff, 0x22222222ffffffff, 0x00000000ffffffff},
    {0x2222222200000000, 0x1111111100000000, 0x1111111100000000},
};

/* sra32 */
struct binary_calculation samples_sra32[] = {
    {0x0000000100000001, 0x0000000000000000, 0x0000000100000001},
    {0x0000000100000001, 0x0000000000000001, 0x0000000000000000},
    {0x0000001000000010, 0x0000000000000001, 0x0000000800000008},
    {0x1122334455667788, 0x000000000000000f, 0x000022440000AACC},
    {0x1122334455667788, 0x000000000000002f, 0x000022440000AACC},
    {0x1122334455667788, 0x000000000000001f, 0x0000000000000000},
    {0x1122334455667788, 0x000000000000003f, 0x0000000000000000},
    {0x8899aabbccddeeff, 0x000000000000000f, 0xffff1133ffff99bb},
    {0x8899aabbccddeeff, 0x000000000000001f, 0xffffffffffffffff},
    {0x8000000080000000, 0x000000000000001f, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x000000000000001f, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x000000000000001f, 0x0000000000000000},
};

/* sra32.u */
struct binary_calculation samples_sra32_u[] = {
    {0x0000000100000001, 0x0000000000000001, 0x0000000100000001},
    {0x0000000100000001, 0x0000000000000002, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x000000000000001f, 0x0000000000000000},
    {0x0111111101111111, 0x000000000000001f, 0x0000000000000000},
    {0xffffffffffffffff, 0x000000000000001f, 0x0000000000000000},
    {0xbfffffffbfffffff, 0x000000000000001f, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x000000000000001f, 0x0000000100000001},
    {0x8000000080000000, 0x000000000000001f, 0xffffffffffffffff},
    {0x1010101110101011, 0x0000000000000001, 0x0808080908080809},
    {0x8010101180101011, 0x0000000000000001, 0xc0080809c0080809},
    {0x1010101210101012, 0x0000000000000002, 0x0404040504040405},
    {0x1010101010101010, 0x0000000000000002, 0x0404040404040404},
    {0x8010101280101012, 0x0000000000000002, 0xe0040405e0040405},
    {0x8000000080000000, 0x000000000000003f, 0xffffffffffffffff},
    {0x8000000080000000, 0x0000000000000020, 0x8000000080000000},
    {0x8000000080000000, 0x0000000000000000, 0x8000000080000000},
};

/* srai32 */
struct binary_calculation samples_srai32[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0x1000000010000000, 0x0000000000000000, 0x1000000010000000},
    {0x0000000000000000, 0x0000001f0000001f, 0x0000000000000000},
    {0x0111111101111111, 0x0000001f0000001f, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000001f0000001f, 0xffffffffffffffff},
    {0xbfffffffbfffffff, 0x0000001f0000001f, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x0000001f0000001f, 0x0000000000000000},
    {0x8000000080000000, 0x0000001f0000001f, 0xffffffffffffffff},
    {0x1010101110101011, 0x0000000100000001, 0x0808080808080808},
    {0x8010101180101011, 0x0000000100000001, 0xc0080808c0080808},
    {0x1010101210101012, 0x0000000200000002, 0x0404040404040404},
    {0x1010101010101010, 0x0000000200000002, 0x0404040404040404},
    {0x8010101280101012, 0x0000000200000002, 0xe0040404e0040404},
};

/* srai32.u */
struct binary_calculation samples_srai32_u[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000100000001},
    {0x1000000010000000, 0x0000000000000000, 0x1000000010000000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000100000001},
    {0x0000000000000000, 0x0000001f0000001f, 0x0000000000000000},
    {0x0111111101111111, 0x0000001f0000001f, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000001f0000001f, 0x0000000000000000},
    {0xbfffffffbfffffff, 0x0000001f0000001f, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x0000001f0000001f, 0x0000000100000001},
    {0x8000000080000000, 0x0000001f0000001f, 0xffffffffffffffff},
    {0x1010101110101011, 0x0000000100000001, 0x0808080908080809},
    {0x8010101180101011, 0x0000000100000001, 0xc0080809c0080809},
    {0x1010101210101012, 0x0000000200000002, 0x0404040504040405},
    {0x1010101010101010, 0x0000000200000002, 0x0404040404040404},
    {0x8010101280101012, 0x0000000200000002, 0xe0040405e0040405},
};

/* srl32 */
struct binary_calculation samples_srl32[] = {
    {0x1000000010000000, 0x0000000100000001, 0x0800000008000000},
    {0x1100000011000000, 0x0000000100000001, 0x0880000008800000},
    {0x1100000011000000, 0x0000001000000010, 0x0000110000001100},
    {0x0000000100000001, 0x0000000100000001, 0x0000000000000000},
    {0x0000000100000001, 0x0000001000000010, 0x0000000000000000},
    {0x1000000110000001, 0x0000000100000001, 0x0800000008000000},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x0000001f0000001f, 0x0000000000000000},
    {0x0111111101111111, 0x0000001f0000001f, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000001f0000001f, 0x0000000100000001},
    {0xbfffffffbfffffff, 0x0000001f0000001f, 0x0000000100000001},
    {0x7fffffff7fffffff, 0x0000001f0000001f, 0x0000000000000000},
    {0x8000000080000000, 0x0000001f0000001f, 0x0000000100000001},
    {0x1010101110101011, 0x0000000100000001, 0x0808080808080808},
    {0x1010101010101010, 0x0000000100000001, 0x0808080808080808},
    {0xffffffffffffffff, 0x0000003f0000003f, 0x0000000100000001},
    {0xffffffffffffffff, 0x0000002000000020, 0xffffffffffffffff},
    {0x0000000100000001, 0x0000000000000000, 0x0000000100000001},
};

/* srli32 */
struct binary_calculation samples_srli32[] = {
    {0x1000000010000000, 0x0000000100000001, 0x0800000008000000},
    {0x1100000011000000, 0x0000000100000001, 0x0880000008800000},
    {0x1010101110101011, 0x0000000100000001, 0x0808080808080808},
    {0x1000000110000001, 0x0000000100000001, 0x0800000008000000},
    {0x8000100080001000, 0x0000000000000000, 0x8000100080001000},
    {0x0000000000000000, 0x0000001f0000001f, 0x0000000000000000},
    {0x0111111101111111, 0x0000001f0000001f, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000001f0000001f, 0x0000000100000001},
    {0xbfffffffbfffffff, 0x0000001f0000001f, 0x0000000100000001},
    {0x7fffffff7fffffff, 0x0000001f0000001f, 0x0000000000000000},
    {0x8000000080000000, 0x0000001f0000001f, 0x0000000100000001},
    {0x8010101280101012, 0x0000000200000002, 0x2004040420040404},
    {0x8010101080101010, 0x0000000200000002, 0x2004040420040404},
};

/* srli32.u */
struct binary_calculation samples_srli32_u[] = {
    {0x1000000010000000, 0x0000000000000001, 0x0800000008000000},
    {0x1100000011000000, 0x0000000000000001, 0x0880000008800000},
    {0x1010101110101011, 0x0000000000000001, 0x0808080908080809},
    {0x1000000110000001, 0x0000000000000001, 0x0800000108000001},
    {0x8000100080001000, 0x0000000000000000, 0x8000100080001000},
    {0x0000000000000000, 0x000000000000001f, 0x0000000000000000},
    {0x0111111101111111, 0x000000000000001f, 0x0000000000000000},
    {0xffffffffffffffff, 0x000000000000001f, 0x0000000200000002},
    {0xbfffffffbfffffff, 0x000000000000001f, 0x0000000100000001},
    {0x7fffffff7fffffff, 0x000000000000001f, 0x0000000100000001},
    {0x8000000080000000, 0x000000000000001f, 0x0000000100000001},
    {0x8010101280101012, 0x0000000000000002, 0x2004040520040405},
    {0x8010101080101010, 0x0000000000000002, 0x2004040420040404},
};

/* srl32.u */
struct binary_calculation samples_srl32_u[] = {
    {0x1000000010000000, 0x0000000000000001, 0x0800000008000000},
    {0x1100000011000000, 0x0000000000000001, 0x0880000008800000},
    {0x1100000011000000, 0x0000000000000010, 0x0000110000001100},
    {0x0000000100000001, 0x0000000000000001, 0x0000000100000001},
    {0x0000000100000001, 0x0000000000000010, 0x0000000000000000},
    {0x1000000110000001, 0x0000000000000001, 0x0800000108000001},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x000000000000001f, 0x0000000000000000},
    {0x0111111101111111, 0x000000000000001f, 0x0000000000000000},
    {0xffffffffffffffff, 0x000000000000001f, 0x0000000200000002},
    {0xbfffffffbfffffff, 0x000000000000001f, 0x0000000100000001},
    {0x7fffffff7fffffff, 0x000000000000001f, 0x0000000100000001},
    {0x8000000080000000, 0x000000000000001f, 0x0000000100000001},
    {0x1010101110101011, 0x0000000000000001, 0x0808080908080809},
    {0x1010101010101010, 0x0000000000000001, 0x0808080808080808},
    {0xffffffffffffffff, 0x000000000000003f, 0x0000000200000002},
    {0xffffffffffffffff, 0x0000000000000020, 0xffffffffffffffff},
    {0x0000000100000001, 0x0000000000000000, 0x0000000100000001},
};

/* sll32 */
struct binary_calculation samples_sll32[] = {
    {0x0000000100000001, 0x0000000000000001, 0x0000000200000002},
    {0xfffffffefffffffe, 0x0000000000000001, 0xfffffffcfffffffc},
    {0x7fffffff7fffffff, 0x0000000000000001, 0xfffffffefffffffe},
    {0x8000000080000000, 0x0000000000000001, 0x0000000000000000},
    {0x007fffff007fffff, 0x0000000000000009, 0xfffffe00fffffe00},
    {0x0080000000800000, 0x0000000000000009, 0x0000000000000000},
    {0xffffffffffffffff, 0x000000000000001f, 0x8000000080000000},
    {0x0000000000000000, 0x000000000000001f, 0x0000000000000000},
    {0x0000000100000001, 0x000000000000001f, 0x8000000080000000},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x7fffffff7fffffff},
    {0x1010101010101010, 0x0000000000000002, 0x4040404040404040},
    {0x4010101040101010, 0x0000000000000004, 0x0101010001010100},
    {0x0000000100000001, 0x000000000000003f, 0x8000000080000000},
    {0xffffffffffffffff, 0x000000000000003f, 0x8000000080000000},
    {0x0000000100000001, 0x0000000000000020, 0x0000000100000001},
    {0xffffffffffffffff, 0x0000000000000020, 0xffffffffffffffff},
};

/* slli32 */
struct binary_calculation samples_slli32[] = {
    {0xffffffffffffffff, 0x000000000000001f, 0x8000000080000000},
    {0x0000000000000000, 0x000000000000001f, 0x0000000000000000},
    {0x0000000100000001, 0x0000000000000000, 0x0000000100000001},
    {0x1010101010101010, 0x0000000000000002, 0x4040404040404040},
    {0x4010101040101010, 0x0000000000000004, 0x0101010001010100},
    {0x0000000100000001, 0x0000000000000001, 0x0000000200000002},
    {0xfffffffefffffffe, 0x0000000000000001, 0xfffffffcfffffffc},
    {0x7fffffff7fffffff, 0x0000000000000001, 0xfffffffefffffffe},
    {0x8000000080000000, 0x0000000000000001, 0x0000000000000000},
    {0x007fffff007fffff, 0x0000000000000009, 0xfffffe00fffffe00},
    {0xff800000ff800000, 0x0000000000000009, 0x0000000000000000},
    {0xffffffffffffffff, 0x000000000000001f, 0x8000000080000000},
    {0x0000000000000000, 0x000000000000001f, 0x0000000000000000},
    {0x0000000100000001, 0x000000000000001f, 0x8000000080000000},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x7fffffff7fffffff},
    {0x4010101040101010, 0x0000000000000002, 0x0040404000404040},
    {0x8010101080101010, 0x0000000000000002, 0x0040404000404040},
};

/* ksll32 */
struct binary_calculation samples_ksll32[] = {
    {0x0000000100000001, 0x0000000000000001, 0x0000000200000002},
    {0xfffffffefffffffe, 0x0000000000000001, 0xfffffffcfffffffc},
    {0x7fffffff7fffffff, 0x0000000000000001, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x0000000000000001, 0x8000000080000000},
    {0x007fffff007fffff, 0x0000000000000009, 0x7fffffff7fffffff},
    {0xff800000ff800000, 0x0000000000000009, 0x8000000080000000},
    {0xffffffffffffffff, 0x000000000000001f, 0x8000000080000000},
    {0x0000000000000000, 0x000000000000001f, 0x0000000000000000},
    {0x0000000100000001, 0x000000000000001f, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x7fffffff7fffffff},
    {0x4010101040101010, 0x0000000000000002, 0x7fffffff7fffffff},
    {0x8010101080101010, 0x0000000000000002, 0x8000000080000000},
    {0x0000000100000001, 0x000000000000003f, 0x7fffffff7fffffff},
    {0xffffffffffffffff, 0x000000000000003f, 0x8000000080000000},
    {0x0000000100000001, 0x0000000000000020, 0x0000000100000001},
    {0xffffffffffffffff, 0x0000000000000020, 0xffffffffffffffff},
};

/* kslli32 */
struct binary_calculation samples_kslli32[] = {
    {0x0000000100000001, 0x0000000000000001, 0x0000000200000002},
    {0xfffffffefffffffe, 0x0000000000000001, 0xfffffffcfffffffc},
    {0x7fffffff7fffffff, 0x0000000000000001, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x0000000000000001, 0x8000000080000000},
    {0x007fffff007fffff, 0x0000000000000009, 0x7fffffff7fffffff},
    {0xff800000ff800000, 0x0000000000000009, 0x8000000080000000},
    {0xffffffffffffffff, 0x000000000000001f, 0x8000000080000000},
    {0x0000000000000000, 0x000000000000001f, 0x0000000000000000},
    {0x0000000100000001, 0x000000000000001f, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x7fffffff7fffffff},
    {0x4010101040101010, 0x0000000000000002, 0x7fffffff7fffffff},
    {0x8010101080101010, 0x0000000000000002, 0x8000000080000000},
};

/* kslra32 */
struct binary_calculation samples_kslra32[] = {
    {0x0000000100000001, 0x0000000000000001, 0x0000000200000002},
    {0xfffffffefffffffe, 0x0000000000000001, 0xfffffffcfffffffc},
    {0x7fffffff7fffffff, 0x0000000000000001, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x0000000000000001, 0x8000000080000000},
    {0x007fffff007fffff, 0x0000000000000009, 0x7fffffff7fffffff},
    {0xff800000ff800000, 0x0000000000000009, 0x8000000080000000},
    {0xffffffffffffffff, 0x000000000000001f, 0x8000000080000000},
    {0x0000000000000000, 0x000000000000001f, 0x0000000000000000},
    {0x0000000100000001, 0x000000000000001f, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x7fffffff7fffffff},
    {0x4010101040101010, 0x0000000000000002, 0x7fffffff7fffffff},
    {0x8010101080101010, 0x0000000000000002, 0x8000000080000000},

    {0x8000000180000001, 0x0000000000000020, 0xffffffffffffffff},
    {0x0000000100000001, 0x000000000000003f, 0x0000000000000000},
    {0x0000001000000010, 0x000000000000003f, 0x0000000800000008},
    {0x1122334411223344, 0x0000000000000031, 0x0000224400002244},
    {0x1122334411223344, 0x0000000000000231, 0x0000224400002244},
    {0x1122334411223344, 0x0000000000000021, 0x0000000000000000},
    {0x1122334411223344, 0x0000000000000221, 0x0000000000000000},
    {0x8899aabb8899aabb, 0x0000000000000031, 0xffff1133ffff1133},
    {0x8899aabb8899aabb, 0x0000000000000021, 0xffffffffffffffff},
    {0x8000000080000000, 0x0000000000000021, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0000000000000021, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x0000000000000021, 0x0000000000000000},
};

/* kslra32.u */
struct binary_calculation samples_kslra32_u[] = {
    {0x0000000100000001, 0x0000000000000001, 0x0000000200000002},
    {0xfffffffefffffffe, 0x0000000000000001, 0xfffffffcfffffffc},
    {0x7fffffff7fffffff, 0x0000000000000001, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x0000000000000001, 0x8000000080000000},
    {0x007fffff007fffff, 0x0000000000000009, 0x7fffffff7fffffff},
    {0xff800000ff800000, 0x0000000000000009, 0x8000000080000000},
    {0xffffffffffffffff, 0x000000000000001f, 0x8000000080000000},
    {0x0000000000000000, 0x000000000000001f, 0x0000000000000000},
    {0x0000000100000001, 0x000000000000001f, 0x7fffffff7fffffff},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x7fffffff7fffffff},
    {0x4010101040101010, 0x0000000000000002, 0x7fffffff7fffffff},
    {0x8010101080101010, 0x0000000000000002, 0x8000000080000000},

    {0x0000000100000001, 0x000000000000003f, 0x0000000100000001},
    {0x0000000100000001, 0x000000000000003e, 0x0000000000000000},
    {0x8000000080000000, 0x0000000000000020, 0xffffffffffffffff},
    {0x0000000000000000, 0x0000000000000021, 0x0000000000000000},
    {0x0111111101111111, 0x0000000000000021, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000000000021, 0x0000000000000000},
    {0xbfffffffbfffffff, 0x0000000000000021, 0xffffffffffffffff},
    {0x7fffffff7fffffff, 0x0000000000000021, 0x0000000100000001},
    {0x8000000080000000, 0x0000000000000021, 0xffffffffffffffff},
    {0x1010101110101011, 0x000000000000003f, 0x0808080908080809},
    {0x8010101180101011, 0x000000000000003f, 0xc0080809c0080809},
    {0x1010101210101012, 0x000000000000003e, 0x0404040504040405},
    {0x1010101010101010, 0x000000000000003e, 0x0404040404040404},
    {0x8010101280101012, 0x000000000000003e, 0xe0040405e0040405},
    {0x8000000080000000, 0x0000000000000221, 0xffffffffffffffff},
    {0x8000000080000000, 0x0000000000000220, 0xffffffffffffffff},
};

/* smin32 */
struct binary_calculation samples_smin32[] = {
    {0x1111111111111111, 0x2222222222222222, 0x1111111111111111},
    {0x3322111133221111, 0x2222222222222222, 0x2222222222222222},
    {0xeeeeeeeeeeeeeeee, 0x2222222222222222, 0xeeeeeeeeeeeeeeee},
    {0x2222222222222222, 0xeeeeeeeeeeeeeeee, 0xeeeeeeeeeeeeeeee},
    {0x8080808080808080, 0x7f7f7f7f7f7f7f7f, 0x8080808080808080},
    {0x8080808080808080, 0xffffffffffffffff, 0x8080808080808080},
    {0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff},
    {0x8000000180000001, 0x7000000170000001, 0x8000000180000001},
};

/* umin32 */
struct binary_calculation samples_umin32[] = {
    {0x1111111111111111, 0x2222222222222222, 0x1111111111111111},
    {0x2211111122111111, 0x2222222222222222, 0x2211111122111111},
    {0x3322111133221111, 0x2222222222222222, 0x2222222222222222},
    {0xeeeeeeeeeeeeeeee, 0x2222222222222222, 0x2222222222222222},
    {0x2222222222222222, 0xeeeeeeeeeeeeeeee, 0x2222222222222222},
    {0x8080808080808080, 0x7f7f7f7f7f7f7f7f, 0x7f7f7f7f7f7f7f7f},
    {0x8080808080808080, 0xffffffffffffffff, 0x8080808080808080},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0x8000000180000001, 0x7000000170000001, 0x7000000170000001},
};

/* smax32 */
struct binary_calculation samples_smax32[] = {
    {0x2222222222222222, 0x1111111111111111, 0x2222222222222222},
    {0x2222222222222222, 0x2211111122111111, 0x2222222222222222},
    {0x2222222222222222, 0x3322111133221111, 0x3322111133221111},
    {0x2222222222222222, 0x3333221133332211, 0x3333221133332211},
    {0x2222222222222222, 0x3333333333333333, 0x3333333333333333},
    {0x2222222222222222, 0xeeeeeeeeeeeeeeee, 0x2222222222222222},
    {0xeeeeeeeeeeeeeeee, 0x2222222222222222, 0x2222222222222222},
    {0x2222222222222222, 0x3311111133111111, 0x3311111133111111},
    {0x7f7f7f7f7f7f7f7f, 0x8080808080808080, 0x7f7f7f7f7f7f7f7f},
    {0xffffffffffffffff, 0x8080808080808080, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0xa0001000a0001000, 0xb0000001b0000001, 0xb0000001b0000001},
};

/* umax32 */
struct binary_calculation samples_umax32[] = {
    {0x2222222222222222, 0x1111111111111111, 0x2222222222222222},
    {0x2222222222222222, 0x2211111122111111, 0x2222222222222222},
    {0x2222222222222222, 0x3322111133221111, 0x3322111133221111},
    {0x2222222222222222, 0x3333221133332211, 0x3333221133332211},
    {0x2222222222222222, 0x3333333333333333, 0x3333333333333333},
    {0x2222222222222222, 0xeeeeeeeeeeeeeeee, 0xeeeeeeeeeeeeeeee},
    {0xeeeeeeeeeeeeeeee, 0x2222222222222222, 0xeeeeeeeeeeeeeeee},
    {0x2222222222222222, 0x3311111133111111, 0x3311111133111111},
    {0x7f7f7f7f7f7f7f7f, 0x8080808080808080, 0x8080808080808080},
    {0xffffffffffffffff, 0x8080808080808080, 0xffffffffffffffff},
    {0xffffffffffffffff, 0x0000000000000000, 0xffffffffffffffff},
    {0x0010000000100000, 0x1000000110000001, 0x1000000110000001},
};

/* kabs32 */
struct unary_calculation samples_kabs32[] = {
    {0x0000000100000001, 0x0000000100000001},
    {0x1111111123456789, 0x1111111123456789},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0xffffffffffffffff, 0x0000000100000001},
    {0x8000000080000000, 0x7fffffff7fffffff},
    {0x0000000000000000, 0x0000000000000000},
    {0x7fffffffffffffff, 0x7fffffff00000001},
    {0x1111111111111111, 0x1111111111111111},
};

/* khmbb16 */
struct binary_calculation samples_khmbb16[] = {
    {0x8000800080008000, 0x8000800080008000, 0x00007fff00007fff},
    {0x0000800000008000, 0x8000800080008000, 0x00007fff00007fff},
    {0x8000000080000000, 0x8000800080008000, 0x0000000000000000},
    {0x80007fff80007fff, 0x8000800080008000, 0xffff8001ffff8001},
    {0x8000ffff8000ffff, 0x8000800080008000, 0x0000000100000001},
    {0x8000ffff8000ffff, 0x8000ffff8000ffff, 0x0000000000000000},
    {0x800012348000abcd, 0x8000abcd80001234, 0xfffff406fffff406},
    {0x12348000abcd8000, 0xabcd800012348000, 0x00007fff00007fff},
    {0x8000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0x8000000000000000, 0x7fffffffffffffff, 0x0000000000000000},
    {0x8000000080000000, 0x7fffffffffffffff, 0x0000000000000000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x0000000000000000},
};

/* khmbt16 */
struct binary_calculation samples_khmbt16[] = {
    {0x8000800080008000, 0x8000800080008000, 0x00007fff00007fff},
    {0x0000800000008000, 0x8000800080008000, 0x00007fff00007fff},
    {0x8000000080000000, 0x8000800080008000, 0x0000000000000000},
    {0x80007fff80007fff, 0x8000800080008000, 0xffff8001ffff8001},
    {0x8000ffff8000ffff, 0x8000800080008000, 0x0000000100000001},
    {0x8000ffff8000ffff, 0x8000ffff8000ffff, 0x0000000100000001},
    {0x800012348000abcd, 0x8000abcd80001234, 0xffffedcc00005433},
    {0x12348000abcd8000, 0xabcd800012348000, 0x00005433ffffedcc},
    {0x8000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0x8000000000000000, 0x7fffffffffffffff, 0x0000000000000000},
    {0x8000000080000000, 0x7fffffffffffffff, 0x0000000000000000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x0000000000000000},
};

/* khmtt16 */
struct binary_calculation samples_khmtt16[] = {
    {0x8000800080008000, 0x8000800080008000, 0x00007fff00007fff},
    {0x0000800000008000, 0x8000800080008000, 0x0000000000000000},
    {0x8000000080000000, 0x8000800080008000, 0x00007fff00007fff},
    {0x80007fff80007fff, 0x8000800080008000, 0x00007fff00007fff},
    {0x8000ffff8000ffff, 0x8000800080008000, 0x00007fff00007fff},
    {0x8000ffff8000ffff, 0x8000ffff8000ffff, 0x00007fff00007fff},
    {0x800012348000abcd, 0x8000abcd80001234, 0x00007fff00007fff},
    {0x12348000abcd8000, 0xabcd800012348000, 0xfffff406fffff406},
    {0x8000000000000000, 0xffffffffffffffff, 0x0000000100000000},
    {0x8000000000000000, 0x7fffffffffffffff, 0xffff800100000000},
    {0x8000000080000000, 0x7fffffffffffffff, 0xffff800100000001},
    {0x8000000080000000, 0x7fffffff7fffffff, 0xffff8001ffff8001},
};

/* kdmbb16 */
struct binary_calculation samples_kdmbb16[] = {
    {0x0001000100010001, 0x0001000100010001, 0x0000000200000002},
    {0x1111222233334444, 0x0001000100010001, 0x0000444400008888},
    {0x0001000100010001, 0x1111222233334444, 0x0000444400008888},
    {0x8000800080008000, 0x8000800080008000, 0x7fffffff7fffffff},
    {0x0000800000008000, 0x8000800080008000, 0x7fffffff7fffffff},
    {0x8000800080008000, 0x8000000080000000, 0x0000000000000000},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0x8001000080010000},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x8000800080008000, 0x0001000000010000},
};

/* kdmbt16 */
struct binary_calculation samples_kdmbt16[] = {
    {0x0001000100010001, 0x0001000100010001, 0x0000000200000002},
    {0x1111222233334444, 0x0001000100010001, 0x0000444400008888},
    {0x0001000100010001, 0x2222111144443333, 0x0000444400008888},
    {0x8000800080008000, 0x8000800080008000, 0x7fffffff7fffffff},
    {0x0000800000008000, 0x8000800080008000, 0x7fffffff7fffffff},
    {0x8000800080008000, 0x0000800000008000, 0x0000000000000000},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0x8001000080010000},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x8000800080008000, 0x0001000000010000},
};

/* kdmtt16 */
struct binary_calculation samples_kdmtt16[] = {
    {0x0001000100010001, 0x0001000100010001, 0x0000000200000002},
    {0x2222111144443333, 0x0001000100010001, 0x0000444400008888},
    {0x0001000100010001, 0x2222111144443333, 0x0000444400008888},
    {0x8000800080008000, 0x8000800080008000, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x8000800080008000, 0x7fffffff7fffffff},
    {0x8000800080008000, 0x0000800000008000, 0x0000000000000000},
    {0x7fff7fff7fff7fff, 0x8000800080008000, 0x8001000080010000},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0xffffffffffffffff, 0x8000800080008000, 0x0001000000010000},
};

/* kdmabb16 */
struct ternary_calculation samples_kdmabb16[] = {
    {0x0000000100000001, 0x0000000100000001, 0x0000000100000001, 0x0000000300000003},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x0000000100000001, 0x0000ffff0000ffff},
    {0x0000000100000001, 0xffffffffffffffff, 0x0000000100000001, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000800000008000, 0x8000800080008000, 0xffffffffffffffff, 0x7ffffffe7ffffffe},
    {0x0000000000000000, 0x0000000000000000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x8000000080000000, 0x8000000080000000},
    {0x8000000080000000, 0x0000800000008000, 0x8000000080000000, 0x8000000080000000},
    {0x0000800000008000, 0x0000800000008000, 0x0000800000008000, 0x7fffffff7fffffff},
    {0x80007fff80007fff, 0xffff7fffffff7fff, 0x1000000010000000, 0x7fffffff7fffffff},
    {0x80007fff80007fff, 0x7fffffff7fffffff, 0x1000000010000000, 0x0fff00020fff0002},
    {0x80007fff80007fff, 0x7fff80007fff8000, 0x9000000090000000, 0x8000000080000000},
};

/* kdmatt16 */
struct ternary_calculation samples_kdmatt16[] = {
    {0x0001000000010000, 0x0001000000010000, 0x0000000100000001, 0x0000000300000003},
    {0x0001000000010000, 0x7fff7fff7fff7fff, 0x0000000100000001, 0x0000ffff0000ffff},
    {0x0001000000010000, 0xffffffffffffffff, 0x0000000100000001, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x8000000080000000, 0x8000800080008000, 0xffffffffffffffff, 0x7ffffffe7ffffffe},
    {0x0000000000000000, 0x0000000000000000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000000000000, 0xffff7fffffff7fff, 0x8000000080000000, 0x8000000080000000},
    {0x0000800000008000, 0x8000000080000000, 0x8000000080000000, 0x8000000080000000},
    {0x8000000080000000, 0x8000000080000000, 0x0000800000008000, 0x7fffffff7fffffff},
    {0x7fff80007fff8000, 0x7fffffff7fffffff, 0x1000000010000000, 0x7fffffff7fffffff},
    {0x7fff80007fff8000, 0xffff7fffffff7fff, 0x1000000010000000, 0x0fff00020fff0002},
    {0x7fff80007fff8000, 0x80007fff80007fff, 0x9000000090000000, 0x8000000080000000},

};

/* kdmabt16 */
struct ternary_calculation samples_kdmabt16[] = {
    {0x0000000100000001, 0x0001000000010000, 0x0000000100000001, 0x0000000300000003},
    {0x0000000100000001, 0x7fff7fff7fff7fff, 0x0000000100000001, 0x0000ffff0000ffff},
    {0x0000000100000001, 0xffffffffffffffff, 0x0000000100000001, 0xffffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000800000008000, 0x8000800080008000, 0xffffffffffffffff, 0x7ffffffe7ffffffe},
    {0x0000000000000000, 0x0000000000000000, 0x7fffffff7fffffff, 0x7fffffff7fffffff},
    {0x0000000000000000, 0xffff7fffffff7fff, 0x8000000080000000, 0x8000000080000000},
    {0x8000000080000000, 0x8000000080000000, 0x8000000080000000, 0x8000000080000000},
    {0x0000800000008000, 0x8000000080000000, 0x0000800000008000, 0x7fffffff7fffffff},
    {0x80007fff80007fff, 0x7fffffff7fffffff, 0x1000000010000000, 0x7fffffff7fffffff},
    {0x80007fff80007fff, 0xffff7fffffff7fff, 0x1000000010000000, 0x0fff00020fff0002},
    {0x80007fff80007fff, 0x80007fff80007fff, 0x9000000090000000, 0x8000000080000000},

};

/* smbt32 */
struct binary_calculation samples_smbt32[] = {
    {0x123456787fffffff, 0x7fffffff12345678, 0x3fffffff00000001},
    {0x1234567880000000, 0x8000000012345678, 0x4000000000000000},
    {0x12345678ffffffff, 0xffffffff12345678, 0x0000000000000001},
    {0x1234567800000000, 0x0000000012345678, 0x0000000000000000},
    {0x123456787fffffff, 0x8000000012345678, 0xc000000080000000},
    {0x1234567880000000, 0x7fffffff12345678, 0xc000000080000000},
    {0x123456787fffffff, 0xffffffff12345678, 0xffffffff80000001},
    {0x12345678ffffffff, 0x7fffffff12345678, 0xffffffff80000001},
    {0x123456787fffffff, 0x0000000012345678, 0x0000000000000000},
    {0x1234567800000000, 0x7fffffff12345678, 0x0000000000000000},
    {0x1234567880000000, 0xffffffff12345678, 0x0000000080000000},
    {0x12345678ffffffff, 0x8000000012345678, 0x0000000080000000},
    {0x1234567800000000, 0x8000000012345678, 0x0000000000000000},
    {0x1234567880000000, 0x0000000012345678, 0x0000000000000000},
    {0x12345678ffffffff, 0x0000000012345678, 0x0000000000000000},
    {0x1234567800000000, 0xffffffff12345678, 0x0000000000000000},
    {0x123456787fffffff, 0x7fffffff12345678, 0x3fffffff00000001},
};

/* smtt32 */
struct binary_calculation samples_smtt32[] = {
    {0x7fffffff12345678, 0x7fffffff12345678, 0x3fffffff00000001},
    {0x8000000012345678, 0x8000000012345678, 0x4000000000000000},
    {0xffffffff12345678, 0xffffffff12345678, 0x0000000000000001},
    {0x0000000012345678, 0x0000000012345678, 0x0000000000000000},
    {0x7fffffff12345678, 0x8000000012345678, 0xc000000080000000},
    {0x8000000012345678, 0x7fffffff12345678, 0xc000000080000000},
    {0x7fffffff12345678, 0xffffffff12345678, 0xffffffff80000001},
    {0xffffffff12345678, 0x7fffffff12345678, 0xffffffff80000001},
    {0x7fffffff12345678, 0x0000000012345678, 0x0000000000000000},
    {0x0000000012345678, 0x7fffffff12345678, 0x0000000000000000},
    {0x8000000012345678, 0xffffffff12345678, 0x0000000080000000},
    {0xffffffff12345678, 0x8000000012345678, 0x0000000080000000},
    {0x0000000012345678, 0x8000000012345678, 0x0000000000000000},
    {0x8000000012345678, 0x0000000012345678, 0x0000000000000000},
    {0xffffffff12345678, 0x0000000012345678, 0x0000000000000000},
    {0x0000000012345678, 0xffffffff12345678, 0x0000000000000000},
    {0x7fffffff12345678, 0x7fffffff12345678, 0x3fffffff00000001},
};

/* kmabb32 */
struct ternary_calculation samples_kmabb32[] = {
    {0x1234567800000001, 0x1234567800000001, 0x0000000000000001, 0x0000000000000002},
    {0x1234567800000001, 0x1234567800000001, 0xffffffffffffffff, 0x0000000000000000},
    {0x1234567800000001, 0x1234567800000001, 0x8000000000000000, 0x8000000000000001},
    {0x1234567800000001, 0x1234567800000001, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x1234567800000001, 0x12345678ffffffff, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0x1234567800000001, 0x12345678ffffffff, 0x8000000000000000, 0x8000000000000000},
    {0x1234567800000001, 0x12345678ffffffff, 0x7fffffffffffffff, 0x7ffffffffffffffe},
    {0x1234567880000000, 0x1234567880000000, 0xffffffffffffffff, 0x3fffffffffffffff},
    {0x1234567880000000, 0x1234567880000000, 0x8000000000000000, 0xc000000000000000},
    {0x1234567880000000, 0x1234567880000000, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x123456787fffffff, 0x12345678ffffffff, 0xffffffffffffffff, 0xffffffff80000000},
    {0x123456787fffffff, 0x12345678ffffffff, 0x8000000000000000, 0x8000000000000000},
    {0x123456787fffffff, 0x12345678ffffffff, 0x0000000000000000, 0xffffffff80000001},
    {0x1234567800000000, 0x1234567800000001, 0x0000000000000000, 0x0000000000000000},
    {0x1234567800000001, 0x1234567800000000, 0x0000000000000000, 0x0000000000000000},
};

/* kmabt32 */
struct ternary_calculation samples_kmabt32[] = {
    {0x1234567800000001, 0x0000000112345678, 0x0000000000000001, 0x0000000000000002},
    {0x1234567800000001, 0x0000000112345678, 0xffffffffffffffff, 0x0000000000000000},
    {0x1234567800000001, 0x0000000112345678, 0x8000000000000000, 0x8000000000000001},
    {0x1234567800000001, 0x0000000112345678, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x1234567800000001, 0xffffffff12345678, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0x1234567800000001, 0xffffffff12345678, 0x8000000000000000, 0x8000000000000000},
    {0x1234567800000001, 0xffffffff12345678, 0x7fffffffffffffff, 0x7ffffffffffffffe},
    {0x1234567880000000, 0x8000000012345678, 0xffffffffffffffff, 0x3fffffffffffffff},
    {0x1234567880000000, 0x8000000012345678, 0x8000000000000000, 0xc000000000000000},
    {0x1234567880000000, 0x8000000012345678, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x123456787fffffff, 0xffffffff12345678, 0xffffffffffffffff, 0xffffffff80000000},
    {0x123456787fffffff, 0xffffffff12345678, 0x8000000000000000, 0x8000000000000000},
    {0x123456787fffffff, 0xffffffff12345678, 0x0000000000000000, 0xffffffff80000001},
    {0x1234567800000000, 0x0000000112345678, 0x0000000000000000, 0x0000000000000000},
    {0x1234567800000001, 0x0000000012345678, 0x0000000000000000, 0x0000000000000000},
};

/* kmatt32 */
struct ternary_calculation samples_kmatt32[] = {
    {0x0000000112345678, 0x0000000112345678, 0x0000000000000001, 0x0000000000000002},
    {0x0000000112345678, 0x0000000112345678, 0xffffffffffffffff, 0x0000000000000000},
    {0x0000000112345678, 0x0000000112345678, 0x8000000000000000, 0x8000000000000001},
    {0x0000000112345678, 0x0000000112345678, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x0000000112345678, 0xffffffff12345678, 0xffffffffffffffff, 0xfffffffffffffffe},
    {0x0000000112345678, 0xffffffff12345678, 0x8000000000000000, 0x8000000000000000},
    {0x0000000112345678, 0xffffffff12345678, 0x7fffffffffffffff, 0x7ffffffffffffffe},
    {0x8000000012345678, 0x8000000012345678, 0xffffffffffffffff, 0x3fffffffffffffff},
    {0x8000000012345678, 0x8000000012345678, 0x8000000000000000, 0xc000000000000000},
    {0x8000000012345678, 0x8000000012345678, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x7fffffff12345678, 0xffffffff12345678, 0xffffffffffffffff, 0xffffffff80000000},
    {0x7fffffff12345678, 0xffffffff12345678, 0x8000000000000000, 0x8000000000000000},
    {0x7fffffff12345678, 0xffffffff12345678, 0x0000000000000000, 0xffffffff80000001},
    {0x0000000012345678, 0x0000000112345678, 0x0000000000000000, 0x0000000000000000},
    {0x0000000112345678, 0x0000000012345678, 0x0000000000000000, 0x0000000000000000},
};
/* kmda32 */
struct binary_calculation samples_kmda32[] = {
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x7ffffffe00000002},
    {0x8000000080000000, 0x8000000080000000, 0x7fffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000002},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x8000000100000000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x8000000100000000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xFFFFFFFF00000002},
    {0xffffffffffffffff, 0x7fffffff7fffffff, 0xFFFFFFFF00000002},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x8000000080000000, 0xffffffffffffffff, 0x0000000100000000},
    {0xffffffffffffffff, 0x8000000080000000, 0x0000000100000000},
    {0x0000000000000000, 0x8000000080000000, 0x0000000000000000},
    {0x8000000080000000, 0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x7FFFFFFE00000002},
};

/* kmxda32 */
struct binary_calculation samples_kmxda32[] = {
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x7ffffffe00000002},
    {0x8000000080000000, 0x8000000080000000, 0x7fffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000002},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x8000000100000000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x8000000100000000},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xFFFFFFFF00000002},
    {0xffffffffffffffff, 0x7fffffff7fffffff, 0xFFFFFFFF00000002},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x8000000080000000, 0xffffffffffffffff, 0x0000000100000000},
    {0xffffffffffffffff, 0x8000000080000000, 0x0000000100000000},
    {0x0000000000000000, 0x8000000080000000, 0x0000000000000000},
    {0x8000000080000000, 0x0000000000000000, 0x0000000000000000},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x7FFFFFFE00000002},
    {0x7fffffff00000000, 0x123456787fffffff, 0x3fffffff00000001},
    {0x8000000000000000, 0x1234567880000000, 0x4000000000000000},
    {0x123456787fffffff, 0x7fffffff00000000, 0x3fffffff00000001},
    {0x1234567880000000, 0x8000000000000000, 0x4000000000000000},
};

/* kmada32 */
struct ternary_calculation samples_kmada32[] = {
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x0000000000000001, 0x7ffffffe00000003},
    {0x8000000080000000, 0x8000000080000000, 0x0000000000000001, 0x7fffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000001, 0x0000000000000003},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000001, 0x0000000000000001},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x0000000000000001, 0x8000000100000001},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x0000000000000001, 0x8000000100000001},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x0000000000000001, 0xFFFFFFFF00000003},
    {0xffffffffffffffff, 0x7fffffff7fffffff, 0x0000000000000001, 0xFFFFFFFF00000003},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x0000000000000001, 0x0000000000000001},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x0000000000000001, 0x0000000000000001},
    {0x8000000080000000, 0xffffffffffffffff, 0x0000000000000001, 0x0000000100000001},
    {0xffffffffffffffff, 0x8000000080000000, 0x0000000000000001, 0x0000000100000001},
    {0x0000000000000000, 0x8000000080000000, 0x0000000000000001, 0x0000000000000001},
    {0x8000000080000000, 0x0000000000000000, 0x0000000000000001, 0x0000000000000001},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000000000001, 0x0000000000000001},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000001, 0x0000000000000001},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x0000000000000001, 0x7FFFFFFE00000003},
};

/* kmaxda32 */
struct ternary_calculation samples_kmaxda32[] = {
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x0000000000000001, 0x7ffffffe00000003},
    {0x8000000080000000, 0x8000000080000000, 0x0000000000000001, 0x7fffffffffffffff},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000001, 0x0000000000000003},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000001, 0x0000000000000001},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x0000000000000001, 0x8000000100000001},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x0000000000000001, 0x8000000100000001},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0x0000000000000001, 0xFFFFFFFF00000003},
    {0xffffffffffffffff, 0x7fffffff7fffffff, 0x0000000000000001, 0xFFFFFFFF00000003},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x0000000000000001, 0x0000000000000001},
    {0x0000000000000000, 0x7fffffff7fffffff, 0x0000000000000001, 0x0000000000000001},
    {0x8000000080000000, 0xffffffffffffffff, 0x0000000000000001, 0x0000000100000001},
    {0xffffffffffffffff, 0x8000000080000000, 0x0000000000000001, 0x0000000100000001},
    {0x0000000000000000, 0x8000000080000000, 0x0000000000000001, 0x0000000000000001},
    {0x8000000080000000, 0x0000000000000000, 0x0000000000000001, 0x0000000000000001},
    {0xffffffffffffffff, 0x0000000000000000, 0x0000000000000001, 0x0000000000000001},
    {0x0000000000000000, 0xffffffffffffffff, 0x0000000000000001, 0x0000000000000001},
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x0000000000000001, 0x7FFFFFFE00000003},
    {0x7fffffff00000000, 0x123456787fffffff, 0x0000000000000001, 0x3fffffff00000002},
    {0x8000000000000000, 0x1234567880000000, 0x0000000000000001, 0x4000000000000001},
    {0x123456787fffffff, 0x7fffffff00000000, 0x0000000000000001, 0x3fffffff00000002},
    {0x1234567880000000, 0x8000000000000000, 0x0000000000000001, 0x4000000000000001},
};


/* kmads32 */
struct ternary_calculation samples_kmads32[] = {
    {0x0000000100000002, 0x0000000300000001, 0x0000000000000001, 0x0000000000000002},
    {0x1111111122222222, 0x0000000300000001, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x0000000300000001, 0x1111111122222222, 0x0000000000000000, 0x0000000011111111},
    {0x0000000000000000, 0x0000000000000000, 0x123456789abcdef0, 0x123456789abcdef0},
    {0x1234567812345678, 0x1234567812345678, 0x0000000000000000, 0x0000000000000000},
    {0x8000000080000000, 0x7fffffffffffffff, 0x8000000000000000, 0x8000000000000000},
    {0x8000000000000000, 0x7fffffffffffffff, 0x0000000000000000, 0xc000000080000000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x7fffffffffffffff, 0x8000000000000000, 0xBFFFFFFF80000000},
    {0xffffffffffffffff, 0x8000000000000000, 0x7fffffffffffffff, 0x7fffffffffffffff},
};

/* kmadrs32 */
struct ternary_calculation samples_kmadrs32[] = {
    {0x0000000200000001, 0x0000000100000003, 0x0000000000000001, 0x0000000000000002},
    {0x2222222211111111, 0x0000000100000003, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x0000000100000003, 0x2222222211111111, 0x0000000000000000, 0x0000000011111111},
    {0x0000000000000000, 0x0000000000000000, 0x123456789abcdef0, 0x123456789abcdef0},
    {0x1234567812345678, 0x1234567812345678, 0x0000000000000000, 0x0000000000000000},
    {0x8000000080000000, 0xffffffff7fffffff, 0x8000000000000000, 0x8000000000000000},
    {0x0000000080000000, 0xffffffff7fffffff, 0x0000000000000000, 0xc000000080000000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffffffff7fffffff, 0x8000000000000000, 0xBFFFFFFF80000000},
    {0xffffffffffffffff, 0x0000000080000000, 0x7fffffffffffffff, 0x7fffffffffffffff},
};

/* kmaxds32 */
struct ternary_calculation samples_kmaxds32[] = {
    {0x0000000100000002, 0x0000000100000003, 0x0000000000000001, 0x0000000000000002},
    {0x1111111122222222, 0x0000000100000003, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x0000000300000001, 0x2222222211111111, 0x0000000000000000, 0x0000000011111111},
    {0x0000000000000000, 0x0000000000000000, 0x123456789abcdef0, 0x123456789abcdef0},
    {0x1234567812345678, 0x1234567812345678, 0x0000000000000000, 0x0000000000000000},
    {0x8000000080000000, 0xffffffff7fffffff, 0x8000000000000000, 0x8000000000000000},
    {0x8000000000000000, 0xffffffff7fffffff, 0x0000000000000000, 0xc000000080000000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x0000000000000000, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffffffff7fffffff, 0x8000000000000000, 0xBFFFFFFF80000000},
    {0xffffffffffffffff, 0x0000000080000000, 0x7fffffffffffffff, 0x7fffffffffffffff},
};

/* kmsda32 */
struct ternary_calculation samples_kmsda32[] = {
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x7ffffffe00000002, 0x0000000000000000},
    {0x8000000080000000, 0x8000000080000000, 0x0000000000000000, 0x8000000000000000},
    {0x8000000080000000, 0x8000000080000000, 0x7fffffffffffffff, 0xffffffffffffffff},
    {0x8000000080000000, 0x8000000080000000, 0xffffffffffffffff, 0x8000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x8000000000000000, 0x8000000000000000},
    {0x0000000000000000, 0x0000000000000000, 0x123456789abcdef0, 0x123456789abcdef0},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x7000000000000000, 0x7fffffffffffffff},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x1000000100000000, 0x7fffffffffffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xFFFFFFFF00000002, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fffffff7fffffff, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x1111111111111111, 0x1111111111111111},
};

/* kmsxda32 */
struct ternary_calculation samples_kmsxda32[] = {
    {0x7fffffff7fffffff, 0x7fffffff7fffffff, 0x7ffffffe00000002, 0x0000000000000000},
    {0x8000000080000000, 0x8000000080000000, 0x0000000000000000, 0x8000000000000000},
    {0x8000000080000000, 0x8000000080000000, 0x7fffffffffffffff, 0xffffffffffffffff},
    {0x8000000080000000, 0x8000000080000000, 0xffffffffffffffff, 0x8000000000000000},
    {0xffffffffffffffff, 0xffffffffffffffff, 0x8000000000000000, 0x8000000000000000},
    {0x0000000000000000, 0x0000000000000000, 0x123456789abcdef0, 0x123456789abcdef0},
    {0x7fffffff7fffffff, 0x8000000080000000, 0x7000000000000000, 0x7fffffffffffffff},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x1000000100000000, 0x7fffffffffffffff},
    {0x7fffffff7fffffff, 0xffffffffffffffff, 0xFFFFFFFF00000002, 0x0000000000000000},
    {0xffffffffffffffff, 0x7fffffff7fffffff, 0x7fffffffffffffff, 0x7fffffffffffffff},
    {0x7fffffff7fffffff, 0x0000000000000000, 0x1111111111111111, 0x1111111111111111},
};

/* smds32 */
struct binary_calculation samples_smds32[] = {
    {0x0000000100000002, 0x0000000300000001, 0x0000000000000001},
    {0x1111111122222222, 0x0000000300000001, 0x0000000011111111},
    {0x0000000300000001, 0x1111111122222222, 0x0000000011111111},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x1234567812345678, 0x1234567812345678, 0x0000000000000000},
    {0x8000000080000000, 0x7fffffffffffffff, 0xC000000000000000},
    {0x8000000000000000, 0x7fffffffffffffff, 0xc000000080000000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0x7fffffffffffffff, 0x3FFFFFFF80000000},
    {0xffffffffffffffff, 0x8000000000000000, 0x0000000080000000},
};

/* smdrs32 */
struct binary_calculation samples_smdrs32[] = {
    {0x0000000200000001, 0x0000000100000003, 0x0000000000000001},
    {0x2222222211111111, 0x0000000100000003, 0x0000000011111111},
    {0x0000000100000003, 0x2222222211111111, 0x0000000011111111},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x1234567812345678, 0x1234567812345678, 0x0000000000000000},
    {0x8000000080000000, 0xffffffff7fffffff, 0xC000000000000000},
    {0x0000000080000000, 0xffffffff7fffffff, 0xc000000080000000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffffffff7fffffff, 0x3FFFFFFF80000000},
    {0xffffffffffffffff, 0x0000000080000000, 0x0000000080000000},
};

/* smxds32 */
struct binary_calculation samples_smxds32[] = {
    {0x0000000100000002, 0x0000000100000003, 0x0000000000000001},
    {0x1111111122222222, 0x0000000100000003, 0x0000000011111111},
    {0x0000000300000001, 0x2222222211111111, 0x0000000011111111},
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000},
    {0x1234567812345678, 0x1234567812345678, 0x0000000000000000},
    {0x8000000080000000, 0xffffffff7fffffff, 0xC000000000000000},
    {0x8000000000000000, 0xffffffff7fffffff, 0xc000000080000000},
    {0x8000000080000000, 0x7fffffff7fffffff, 0x0000000000000000},
    {0x7fffffff7fffffff, 0xffffffff7fffffff, 0x3FFFFFFF80000000},
    {0xffffffffffffffff, 0x0000000080000000, 0x0000000080000000},
};

/* sraiw.u */
struct binary_calculation samples_sraiw_u[] = {
    {0x0000000012345678, 0x0000000000000000, 0x0000000012345678},
    {0x0000000000000001, 0x0000000000000001, 0x0000000000000001},
    {0x0000000000000000, 0x000000000000001f, 0x0000000000000000},
    {0x0000000001111111, 0x000000000000001f, 0x0000000000000000},
    {0x00000000ffffffff, 0x000000000000001f, 0x0000000000000000},
    {0x00000000bfffffff, 0x000000000000001f, 0xffffffffffffffff},
    {0x000000007fffffff, 0x000000000000001f, 0x0000000000000001},
    {0x0000000080000000, 0x000000000000001f, 0xffffffffffffffff},
    {0x0000000010101011, 0x0000000000000001, 0x0000000008080809},
    {0x0000000080101011, 0x0000000000000001, 0xffffffffc0080809},
    {0x0000000010101012, 0x0000000000000002, 0x0000000004040405},
    {0x0000000010101010, 0x0000000000000002, 0x0000000004040404},
    {0x0000000080101012, 0x0000000000000002, 0xffffffffe0040405},
};

/* pkbb32 */
struct binary_calculation samples_pkbb32[] = {
    {0x1234567811111111, 0x1234567822222222, 0x1111111122222222},
    {0x1111111112345678, 0x2222222212345678, 0x1234567812345678},
    {0x7fffffffffffffff, 0x7fffffffffffffff, 0xffffffffffffffff},
    {0x7fffffffffffffff, 0x8000000000000000, 0xffffffff00000000},
    {0x7fffffff80000000, 0x8000000000000000, 0x8000000000000000},
    {0xffffffffffffffff, 0x8000000080000000, 0xffffffff80000000},
};

/* pkbt32 */
struct binary_calculation samples_pkbt32[] = {
    {0x1234567811111111, 0x2222222212345678, 0x1111111122222222},
    {0x1111111112345678, 0x1234567822222222, 0x1234567812345678},
    {0x7fffffffffffffff, 0xffffffff7fffffff, 0xffffffffffffffff},
    {0x7fffffffffffffff, 0x0000000080000000, 0xffffffff00000000},
    {0x7fffffff80000000, 0x0000000080000000, 0x8000000000000000},
    {0xffffffffffffffff, 0x8000000080000000, 0xffffffff80000000},
};

/* pktt32 */
struct binary_calculation samples_pktt32[] = {
    {0x1111111112345678, 0x2222222212345678, 0x1111111122222222},
    {0x1234567811111111, 0x1234567822222222, 0x1234567812345678},
    {0xffffffff7fffffff, 0xffffffff7fffffff, 0xffffffffffffffff},
    {0xffffffff7fffffff, 0x0000000080000000, 0xffffffff00000000},
    {0x800000007fffffff, 0x0000000080000000, 0x8000000000000000},
    {0xffffffffffffffff, 0x8000000080000000, 0xffffffff80000000},
};

/* pktb32 */
struct binary_calculation samples_pktb32[] = {
    {0x1111111112345678, 0x1234567822222222, 0x1111111122222222},
    {0x1234567811111111, 0x2222222212345678, 0x1234567812345678},
    {0xffffffff7fffffff, 0x7fffffffffffffff, 0xffffffffffffffff},
    {0xffffffff7fffffff, 0x8000000000000000, 0xffffffff00000000},
    {0x800000007fffffff, 0x8000000000000000, 0x8000000000000000},
    {0xffffffffffffffff, 0x8000000080000000, 0xffffffff80000000},
};

#endif
#endif








