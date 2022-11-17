/*
 * asr_asm.h
 *
 *  Created on: 2018-10-26
 *      Author: user
 *      Brief: assembly function declaration for ck805
 */

#ifndef ASR_ASM_H_
#define ASR_ASM_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int8_t fxp8_t;
typedef int16_t fxp16_t;
typedef int32_t fxp32_t;
typedef int64_t fxp64_t;

void asr_vdsp2_fully_connected_8(
		const fxp8_t *vector,
		const fxp8_t *matrix,
		uint16_t dim_vec,
		uint16_t num_of_rows,
		const fxp16_t *bias,
		int8_t bias_shift,
		fxp32_t *out);

void asr_vdsp2_fully_connected_relu_8(
		const fxp8_t *vector,
		const fxp8_t *matrix,
		uint16_t dim_vec,
		uint16_t num_of_rows,
		const fxp16_t *bias,
		int8_t bias_shift,
		fxp32_t *out);

void asr_vdsp2_relu_32(
		const fxp32_t * data,
		uint16_t block_size);

// Brief: dst[i] = src0[i] * src1[i];
void asr_vdsp2_mult_32_16(
		const fxp32_t *src0,
		const fxp16_t *src1,
		fxp32_t *dst,
		uint32_t block_size);

// Brief: result += src0[i] * src1[i] + ... src0[n] * src1[n];
void asr_vdsp2_dot_prod_u64_u8(
		const uint8_t *src0,
		const uint64_t *src1,
		uint64_t *result,
		uint32_t block_size);

// Brief: src[i] <<= shift[i];
void asr_vdsp2_dynamic_shift_32(
		fxp32_t *src,
		int8_t *shift,
		uint32_t block_size);

#ifdef __cplusplus
}
#endif


#endif /* ASR_ASM_H_ */
