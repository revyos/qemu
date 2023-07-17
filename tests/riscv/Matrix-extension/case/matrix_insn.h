/*
 * Copyright (c) 2011-2019 C-SKY Limited. All rights reserved.
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

#include "testsuite.h"
#ifndef MATRIX_INSN_H
#define MATRIX_INSN_H
#include <stdint.h>
#include <memory.h>
#define DEBUG
#define VLEN 128
#define LMUL 2



// 8bis multiply-accumulate
struct matrix_mmaqa_b {
    uint8_t     matrix_uint8_s4x16[4][16];
    int8_t     matrix_int8_s4x16[4][16];
    int32_t     matrix_int32_s4x4[4][4];   
};

struct matrix_pmmaqa_b {
    uint8_t     matrix_uint4_s4x32[4][16];
    int8_t     matrix_int4_s4x32[4][16];
    int32_t     matrix_int32_s4x4[4][4];   
};

struct matrix_mmaqa_h {
    //full physical memory

    uint16_t     matrix_uint16_s4x8[4][8];

    int64_t     mat_int64_s4x2_pair[2][4][2];
    int64_t     mat_int64_s3x2_pair[2][4][2];

    int16_t     matrix_int16_s4x8[4][8];

    int64_t     matrix_int64_s4x4[4][4];   

    //half physical memory
    int16_t     matrix_int16_s3x8[4][8];
    uint16_t     matrix_uint16_s3x8[4][8];

    int64_t     matrix_int64_s3x4[4][4];


};

struct matrix_operates {
    
    int32_t     matrix_int32_s4x4[4][4];
    int32_t     matrix_int32_s3x3[4][4];
    int64_t     matrix_int64_s4x4[4][4];
    int64_t     matrix_int64_s3x3[4][4];
    int         matrix_mx;

};


struct  matrix_ld_st{
    int  move_int8[4][4];
    int  move_int16[4][4];
    int  move_int32[4][4];
    long int  move_int64[4][2];
};



struct mmov {
    uint64_t matrix_uint64_4x2[4][2];
};

struct matrix_mn4clip_s {
    int32_t matrix_int32_s4x4[4][4];
    uint32_t matrix_uint32_4x4[4][4];

    int8_t matrix_int8_s4x16[4][16];
    uint8_t matrix_uint8_4x16[4][16];
};


struct matrix_msras {
    //full physical memory for msra and msub
    int32_t     matrix_int32_s4x4[4][4];
    int32_t     matrix_int32_s3x3[4][4];
    int         matrix_mx;
    int8_t matrix_int8_s4x16[4][16];
    uint8_t matrix_uint8_4x16[4][16];
};


struct matrix_fmmacc {

    _Float16    matrix_float16_s4x8[4][8];
    _Float16    matrix_float16_s2x4[2][4];

    _Float32    matrix_float32_s4x4[4][4];
    _Float32    matrix_float32_s2x2[4][4];

    _Float64    matrix_float64_s4x2[4][2];
    _Float64    matrix_float64_s2x2[4][4];

    _Float64    matrix_float64_s4x4[4][4];


    _Float64    matrix_float64_s4x2_pair[2][4][2];
    _Float64    matrix_float64_s2x1_pair[2][4][2];
    
};





static inline void result_compare_fmmacc_h_2x4(_Float16 (* dst)[4], _Float16 (* ref)[4])
{
    int i,j;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 4; j++){

            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
            if (dst[i][j] != ref[i][j]) {
            printf("Error: [%d][%d] \n", i, j);
            printf("%f, %f  \n", (double)dst[i][j], (double)ref[i][j]);
        }
#endif
        }
    }
}


static inline void result_compare_fmmacc_s_2x2(_Float32 (* dst)[2], _Float32 (* ref)[2])
{
    int i,j;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){

            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
            if (dst[i][j] != ref[i][j]) {
            printf("Error: [%d][%d] \n", i, j);
            printf("%f, %f  \n", (double)dst[i][j], (double)ref[i][j]);
        }
#endif
        }
    }
}

static inline void result_compare_fmmacc_s_4x4(_Float32 (* dst)[4], _Float32 (* ref)[4])
{
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){

            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
            if (dst[i][j] != ref[i][j]) {
            printf("Error: [%d][%d] \n", i, j);
            printf("%f, %f  \n", (double)dst[i][j], (double)ref[i][j]);
        }
#endif
        }
    }
}

static inline void result_compare_fmmacc_d_2x2(_Float64 (* dst)[2], _Float64 (* ref)[2])
{
    int i,j;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){

            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
            if (dst[i][j] != ref[i][j]) {
            printf("Error: [%d][%d] \n", i, j);
            printf("%f, %f  \n", (double)dst[i][j], (double)ref[i][j]);
        }
#endif
        }
    }
}

// static inline void result_compare_fmmacc_d_4x2(_Float64 (* dst)[4], _Float64 (* ref)[4])
// {
//     int i,j;
//     for(i = 0; i < 4; i++){
//         for(j = 0; j < 4; j++){

//             TEST(dst[i][j] == ref[i][j]);
// #ifdef DEBUG
//         if (dst[i][j] != ref[i][j]) {
//             printf("Error: [%d][%d] \n", i, j);
//             printf("%f, %f  \n", (double)dst[i][j], (double)ref[i][j]);
//         }
// #endif
//         }
//     }
// }
static inline void result_compare_fmmacc_d_4x2(_Float64 dst[2][4][2], _Float64 ref[2][4][2])
{
    int p_idx, i, j;
    for (p_idx = 0; p_idx < 2; p_idx++){
        for(i = 0; i < 4; i++){
            for(j = 0; j < 2; j++){
                TEST(dst[p_idx][i][j] == ref[p_idx][i][j]);
#ifdef DEBUG
            if (dst[p_idx][i][j] != ref[p_idx][i][j]) {
                printf("Error: [%d][%d][%d] \n", p_idx, i, j);
                printf("%f, %f  \n", (double)dst[p_idx][i][j], (double)ref[p_idx][i][j]);
    }
#endif
            
        }
    }
    printf("\n");
}
}


static inline void result_compare_fwmmacc_h_4x8(_Float32 (* dst)[8], _Float32 (* ref)[8])
{
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 8; j++){

            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
        if (dst[i][j] != ref[i][j]) {
            printf("Error: [%d][%d] \n", i, j);
            printf("%f, %f  \n", (double)dst[i][j], (double)ref[i][j]);
        }
#endif
        }
    }
}

static inline void result_compare_fwmmacc_h_2x4(_Float32 (* dst)[4], _Float32 (* ref)[4])
{
    int i,j;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 4; j++){

            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
        if (dst[i][j] != ref[i][j]) {
            printf("Error: [%d][%d] \n", i, j);
            printf("%f, %f  \n", (double)dst[i][j], (double)ref[i][j]);
        }
#endif
        }
    }
}





static inline void result_compare_fwmmacc_s_2x2(_Float64 (* dst)[2], _Float64 (* ref)[2])
{
    int i,j;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){

            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
        if (dst[i][j] != ref[i][j]) {
            printf("Error: [%d][%d] \n", i, j);
            printf("%f, %f  \n", (double)dst[i][j], (double)ref[i][j]);
        }
#endif
        }
    }
}

static inline void result_compare_fwmmacc_s_4x4(_Float64 (* dst)[4], _Float64 (* ref)[4])
{
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){

            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
        if (dst[i][j] != ref[i][j]) {
            printf("Error: [%d][%d] \n", i, j);
            printf("%f, %f  \n", (double)dst[i][j], (double)ref[i][j]);
        }
#endif
        }
    }
}


static inline void result_compare_matrix_msras(int32_t (* dst)[4], int32_t (* ref)[4])
{
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            
            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
            if (dst[i][j] != ref[i][j]) {
                printf("Error: [%d][%d] \n", i, j);
                printf("0x%08x, 0x%08x, ", dst[i][j], ref[i][j]);
            }
#endif
        }
    }
    printf("\n");
}

static inline void result_compare_matrix_msras_nfull(int32_t (* dst)[3], int32_t (* ref)[3])
{
    int i,j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            
            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
            if (dst[i][j] != ref[i][j]) {
                printf("Error: [%d][%d] \n", i, j);
                printf("0x%08x, 0x%08x, ", dst[i][j], ref[i][j]);
            }
#endif
        }
    }
    printf("\n");
}

static inline void result_compare_mmaqa_4x4(int32_t (* dst)[4], int32_t (* ref)[4])
{
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            
            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
        if (dst[i][j] != ref[i][j]) {
            printf("Error: [%d][%d] \n", i, j);
            printf("0x%08x, 0x%08x  \n", dst[i][j], ref[i][j]);
        }
#endif
        }
    }
    printf("\n");
}



static inline void result_compare_mmaqa_h_pair_128(int64_t dst[2][4][2], int64_t ref[2][4][2])
{
    int p_idx, i, j;
    for (p_idx = 0; p_idx < 2; p_idx++){
        for(i = 0; i < 4; i++){
            for(j = 0; j < 2; j++){
                TEST(dst[p_idx][i][j] == ref[p_idx][i][j]);
#ifdef DEBUG
            if(dst[p_idx][i][j] != ref[p_idx][i][j]){
                printf("%d, [%d][%d] ", p_idx, i, j);
                printf("0x%016x, 0x%016x,\n", dst[i][j], ref[i][j]);
            }
#endif
            }
        }
    }
    printf("\n");
}


static inline void result_compare_mmaqa_nfull_h128(int64_t dst[2][4][2], int64_t ref[2][4][2])
{
    int p_idx, i, j;
    for (p_idx = 0; p_idx < 2; p_idx++){
        for(i = 0; i < 3; i++){
            for(j = 0; j < 2; j++){
                TEST(dst[p_idx][i][j] == ref[p_idx][i][j]);
#ifdef DEBUG
            if(dst[p_idx][i][j] != ref[p_idx][i][j]){
                printf("%d, [%d][%d]\n", p_idx, i, j);
                printf("0x%016x, 0x%016x, ", dst[i][j], ref[i][j]);
            }
        
#endif
        }
    }
    printf("\n");
}
}

static inline void result_compare_mmov(uint64_t dst[4][2], uint64_t ref[4][2])
{
    int i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 2; j++){
            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
            if (dst[i][j] != ref[i][j]) {
                printf("Error: [%d][%d] \n", i, j);
                printf("0x%016llx, 0x%016llx, \n", dst[i][j], ref[i][j]);
            }
#endif
        }
    }
    printf("\n");
}

static inline void result_compare_fmmacc_h_4x8(_Float16 (* dst)[8], _Float16 (* ref)[8])
{
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 8; j++){

            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
        if (dst[i][j] != ref[i][j]) {
            printf("Error: [%d][%d] \n", i, j);
            printf("%f, %f  \n", (double)dst[i][j], (double)ref[i][j]);
        }
#endif
        }
    }
}

static inline void result_compare_mn4clip_s(int8_t dst[4][16],  int8_t ref[4][16])
{
    int i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 16; j++){
            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
    if (dst[i][j] != ref[i][j]) {
        printf("error[%d][%d]\n", i,j);
        printf("0x%016x, 0x%016x, \n", dst[i][j], ref[i][j]);
    }
#endif
        }
    }
    printf("\n");
}

static inline void result_compare_mn4clipu_s(uint8_t dst[4][16],  uint8_t ref[4][16])
{
    int i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 16; j++){
            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
    if (dst[i][j] != ref[i][j]) {
        printf("error[%d][%d]\n", i,j);
        printf("0x%016x, 0x%016x, \n", dst[i][j], ref[i][j]);
    }
#endif
        }
    }
    printf("\n");
}


static inline void result_compare_msubs(int32_t (* dst)[4], int32_t (* ref)[4])
{
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            
            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
            if (dst[i][j] != ref[i][j]) {
                    printf("Error: [%d][%d] \n", i, j);
                    printf("0x%08x, 0x%08x, ", dst[i][j], ref[i][j]);
            }
#endif
        }
    }
    printf("\n");
}

static inline void result_compare_msubs_nfull(int32_t (* dst)[4], int32_t (* ref)[4])
{
    int i,j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            
            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
            if (dst[i][j] != ref[i][j]) {
                    printf("Error: [%d][%d] \n", i, j);
                    printf("0x%08x, 0x%08x, ", dst[i][j], ref[i][j]);
            }
#endif
        }
    }
    printf("\n");
}

static inline void result_compare_madds(int32_t (* dst)[4], int32_t (* ref)[4])
{
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            
            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
            if (dst[i][j] != ref[i][j]) {
                        printf("Error: [%d][%d] \n", i, j);
                        printf("0x%08x, 0x%08x, ", dst[i][j], ref[i][j]);
            }
#endif
        }
    }
    printf("\n");
}

static inline void result_compare_madds_nfull(int32_t (* dst)[4], int32_t (* ref)[4])
{
    int i,j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            
            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
            if (dst[i][j] != ref[i][j]) {
                    printf("Error: [%d][%d] \n", i, j);
                    printf("0x%08x, 0x%08x, ", dst[i][j], ref[i][j]);
            }
#endif
        }
    }
    printf("\n");
}

static inline void result_compare_matrix_operations_I64(int64_t (* dst)[4], int64_t (* ref)[4])
{
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            
            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
            if (dst[i][j] != ref[i][j]) {
                        printf("Error: [%d][%d] \n", i, j);
                        printf("0x%08x, 0x%08x, ", dst[i][j], ref[i][j]);
            }
#endif
        }
    }
    printf("\n");
}

static inline void result_compare_matrix_operations_nfull_I64(int64_t (* dst)[4], int64_t (* ref)[4])
{
    int i,j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            
            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
            if (dst[i][j] != ref[i][j]) {
                    printf("Error: [%d][%d] \n", i, j);
                    printf("0x%08x, 0x%08x, ", dst[i][j], ref[i][j]);
            }
#endif
        }
    }
    printf("\n");
}



static inline void result_compare_matrix_mmuls(int32_t (* dst)[4], int32_t (* ref)[4])
{
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            
            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
            if (dst[i][j] != ref[i][j]) {
                    printf("Error: [%d][%d] \n", i, j);
                    printf("0x%08x, 0x%08x, ", dst[i][j], ref[i][j]);
            }
#endif
        }
    }
    printf("\n");
}

static inline void result_compare_matrix_mmuls_nfull(int32_t (* dst)[4], int32_t (* ref)[4])
{
    int i,j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            
            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
            if (dst[i][j] != ref[i][j]) {
                printf("Error: [%d][%d] \n", i, j);
                printf("0x%08x, 0x%08x, ", dst[i][j], ref[i][j]);
            }
#endif
        }
    }
    printf("\n");
}


static inline void result_compare_ld_and_st(int64_t (* dst)[2], int64_t (* ref)[2])
{
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 2; j++){
            
            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
            if (dst[i][j] != ref[i][j]) {
                printf("Error: [%d][%d]", i, j);
                printf("0x%016llx, 0x%016llx\n", dst[i][j], ref[i][j]);
            }
#endif
        }
    }
}

static inline void result_compare_ld_and_st32(int32_t (* dst)[4], int32_t (* ref)[4])
{
    int i,j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 4; j++){
            
            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
            if (dst[i][j] != ref[i][j]) {
                printf("Error: [%d][%d] \n", i, j);
                printf("0x%08llx, 0x%08llx, ", dst[i][j], ref[i][j]);
            }
#endif
        }
    }
    printf("\n");
}
static inline void result_compare_ld_and_st16(int16_t (* dst)[4], int16_t (* ref)[4])
{
    int i,j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 4; j++){
            
            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
            if (dst[i][j] != ref[i][j]) {
                printf("Error: [%d][%d] \n", i, j);
                printf("0x%04x, 0x%04llx, ", dst[i][j], ref[i][j]);
            }
#endif
        }
    }
    printf("\n");
}

static inline void result_compare_ld_and_st8(int8_t (* dst)[4], int8_t (* ref)[4])
{
    int i,j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 4; j++){
            
            TEST(dst[i][j] == ref[i][j]);
#ifdef DEBUG
            if (dst[i][j] != ref[i][j]) {
                printf("Error: [%d][%d] \n", i, j);
                printf("0x%02llx, 0x%02llx, ", dst[i][j], ref[i][j]);
            }
#endif
        }
    }
    printf("\n");
}




void test_mmaqa_full_h128(void *a, void *b, void *c, void *d);
void test_mmaqa_nfull_h128(void *a, void *b, void *c, void *d);

void test_mmaqau_full_h128(void *a, void *b, void *c, void *d);
void test_mmaqau_nfull_h128(void *a, void *b, void *c, void *d);

void test_mmaqaus_full_h128(void *a, void *b, void *c, void *d);
void test_mmaqaus_nfull_h128(void *a, void *b, void *c, void *d);

void test_mmaqasu_full_h128(void *a, void *b, void *c, void *d);
void test_mmaqasu_nfull_h128(void *a, void *b, void *c, void *d);


void test_pmmaqa_4x4(void *a, void *b, void *c, void *d);
void test_pmmaqa_2x3(void *a, void *b, void *c, void *d);

void test_pmmaqau_4x4(void *a, void *b, void *c, void *d);
void test_pmmaqau_2x3(void *a, void *b, void *c, void *d);

void test_pmmaqaus_4x4(void *a, void *b, void *c, void *d);
void test_pmmaqaus_2x3(void *a, void *b, void *c, void *d);

void test_pmmaqasu_4x4(void *a, void *b, void *c, void *d);
void test_pmmaqasu_2x3(void *a, void *b, void *c, void *d);


void test_mmaqa_4x4(void *a, void *b, void *c, void *d);
void test_mmaqa_2x3(void *a, void *b, void *c, void *d);
void test_mmaqau_4x4(void *a, void *b, void *c, void *d);
void test_mmaqau_2x3(void *a, void *b, void *c, void *d);
void test_mmaqaus_4x4(void *a, void *b, void *c, void *d);
void test_mmaqaus_2x3(void *a, void *b, void *c, void *d);
void test_mmaqasu_4x4(void *a, void *b, void *c, void *d);
void test_mmaqasu_2x3(void *a, void *b, void *c, void *d);


void test_madds_mm(void *a, void *b, void *c, void *d);
void test_madds_mm_nfull(void *a, void *b, void *c, void *d);

void test_madds_mv_x(void *a, void *b, void *c, void *d, int e);
void test_madds_mv_x_nfull(void *a, void *b, void *c, void *d, int e);

void test_madds_mx(int a, void *b, void *c, void *d);
void test_madds_mx_nfull(int a, void *b, void *c, void *d);

void test_madds_mv_i(void *a, void *b, void *c, void *d);
void test_madds_mv_i_nfull(void *a, void *b, void *c, void *d);

void test_madds_mm_I64(void *a, void *b, void *c, void *d);
void test_madds_mm_nfull_I64(void *a, void *b, void *c, void *d);

void test_madds_mv_x_I64(void *a, void *b, void *c, void *d, int e);
void test_madds_mv_x_nfull_I64(void *a, void *b, void *c, void *d, int e);

void test_madds_mx_I64(int a, void *b, void *c, void *d);
void test_madds_mx_nfull_I64(int a, void *b, void *c, void *d);

void test_madds_mv_i_I64(void *a, void *b, void *c, void *d);
void test_madds_mv_i_nfull_I64(void *a, void *b, void *c, void *d);

void test_mldb(void *a, void *b);
void test_mldh(void *a, void *b);
void test_mldw(void *a, void *b);
void test_mldd(void *a, void *b);


void test_mldm1b(void *a, void *b);
void test_mldm1h(void *a, void *b);
void test_mldm1w(void *a, void *b);
void test_mldm1d(void *a, void *b);

void test_mldm2b(void *a, void *b);
void test_mldm2h(void *a, void *b);
void test_mldm2w(void *a, void *b);
void test_mldm2d(void *a, void *b);

void test_mldm4b(void *a, void *b);
void test_mldm4h(void *a, void *b);
void test_mldm4w(void *a, void *b);
void test_mldm4d(void *a, void *b);

void test_mldm8b(void *a, void *b);
void test_mldm8h(void *a, void *b);
void test_mldm8w(void *a, void *b);
void test_mldm8d(void *a, void *b);



void test_msldb(void *a, void *b);
void test_msldh(void *a, void *b);
void test_msldw(void *a, void *b);
void test_msldd(void *a, void *b);

void test_msubs_mm(void *a, void *b, void *c, void *d);
void test_msubs_mm_nfull(void *a, void *b, void *c, void *d);

void test_msubs_mv_x(void *a, void *b, void *c, void *d, int e);
void test_msubs_mv_x_nfull(void *a, void *b, void *c, void *d, int e);

void test_msubs_mx(int a, void *b, void *c, void *d);
void test_msubs_mx_nfull(int a, void *b, void *c, void *d);

void test_msubs_mv_i(void *a, void *b, void *c, void *d);
void test_msubs_mv_i_nfull(void *a, void *b, void *c, void *d);






void test_mmov_mm(void *a, void *b, void *c);
void test_mmov_mv_x(void *a, void *b, void *c, uint8_t row_index);
void test_mmov_mv_i(void *a, void *b, void *c);
void test_mmov_mx(uint64_t a, void *b, void *c);

void test_fmmacc_h_4x8(void *a, void *b, void *c, void *d, void *e);
void test_fmmacc_h_2x4(void *a, void *b, void *c, void *d, void *e);

void test_fmmacc_s_4x4(void *a, void *b, void *c, void *d);
void test_fmmacc_s_2x2(void *a, void *b, void *c, void *d);

void test_fmmacc_d_4x2(void *a, void *b, void *c, void *d);
void test_fmmacc_d_2x1(void *a, void *b, void *c, void *d);


void test_fwmmacc_h_4x8(void *a, void *b, void *c, void *d, void *e);
void test_fwmmacc_h_2x4(void *a, void *b, void *c, void *d, void *e);

void test_fwmmacc_s_4x4(void *a, void *b, void *c);
void test_fwmmacc_s_2x2(void *a, void *b, void *c);


void test_mn4clip_s_mm(void *a, void *b, void *c, void *d);
void test_mn4clip_s_mm_3x3(void *a, void *b, void *c, void *d);
void test_mn4clip_s_mv_i(void *a, void *b, void *c, void *d);
void test_mn4clip_s_mv_i_3x3(void *a, void *b, void *c, void *d);
void test_mn4clip_s_mv_x(void *a, void *b, void *c, void *d, uint8_t row_index);
void test_mn4clip_s_mv_x_3x3(void *a, void *b, void *c, void *d, uint8_t row_index);
void test_mn4clip_s_mx(void *a, void *b, void *c, uint8_t shamt);
void test_mn4clip_s_mx_3x3(void *a, void *b, void *c, uint8_t shamt);

void test_mn4clipu_s_mm(void *a, void *b, void *c, void *d);
void test_mn4clipu_s_mm_3x3(void *a, void *b, void *c, void *d);
void test_mn4clipu_s_mv_i(void *a, void *b, void *c, void *d);
void test_mn4clipu_s_mv_i_3x3(void *a, void *b, void *c, void *d);
void test_mn4clipu_s_mv_x(void *a, void *b, void *c, void *d, uint8_t row_index);
void test_mn4clipu_s_mv_x_3x3(void *a, void *b, void *c, void *d, uint8_t row_index);
void test_mn4clipu_s_mx(void *a, void *b, void *c, uint8_t shamt);
void test_mn4clipu_s_mx_3x3(void *a, void *b, void *c, uint8_t shamt);



void test_mmuls_mm(void *a, void *b, void *c, void *d);
void test_mmuls_mm_nfull(void *a, void *b, void *c, void *d);

void test_mmuls_mv_x(void *a, void *b, void *c, void *d, int e);
void test_mmuls_mv_x_nfull(void *a, void *b, void *c, void *d, int e);

void test_mmuls_mx(int a, void *b, void *c, void *d);
void test_mmuls_mx_nfull(int a, void *b, void *c, void *d);

void test_mmuls_mv_i(void *a, void *b, void *c, void *d);
void test_mmuls_mv_i_nfull(void *a, void *b, void *c, void *d);


void test_mmulhs_mm(void *a, void *b, void *c, void *d);
void test_mmulhs_mm_nfull(void *a, void *b, void *c, void *d);

void test_mmulhs_mv_x(void *a, void *b, void *c, void *d, int e);
void test_mmulhs_mv_x_nfull(void *a, void *b, void *c, void *d, int e);

void test_mmulhs_mx(int a, void *b, void *c, void *d);
void test_mmulhs_mx_nfull(int a, void *b, void *c, void *d);

void test_mmulhs_mv_i(void *a, void *b, void *c, void *d);
void test_mmulhs_mv_i_nfull(void *a, void *b, void *c, void *d);


void test_msra_s_mm(void *a, void *b, void *c, void *d);
void test_msra_s_mm_3x3(void *a, void *b, void *c, void *d);

void test_msra_s_mv_x(void *a, void *b, void *c, void *d, int e);
void test_msra_s_mv_x_3x3(void *a, void *b, void *c, void *d, int e);

void test_msra_s_mx(void *a, void *b, void *c, int d);
void test_msra_s_mx_3x3(void *a, void *b, void *c, int d);

void test_msra_s_mv_i(void *a, void *b, void *c, void *d);
void test_msra_s_mv_i_3x3(void *a, void *b, void *c, void *d);
#endif
