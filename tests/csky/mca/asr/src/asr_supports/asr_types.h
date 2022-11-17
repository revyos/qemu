#ifndef __ASR_TYPES_H__
#define __ASR_TYPES_H__

#include <stdbool.h>
#include <stdint.h>

#ifdef HIFI3
#include "NatureDSP_types.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef int8_t fxp8_t;
typedef int16_t fxp16_t;
typedef int32_t fxp32_t;
typedef int64_t fxp64_t;

typedef uint8_t ufxp8_t;
typedef uint16_t ufxp16_t;
typedef uint32_t ufxp32_t;
typedef uint64_t ufxp64_t;

// Types with known q value.
typedef fxp16_t fxp16_q15_t;
typedef fxp32_t fxp32_q16_t;
typedef fxp32_t fxp32_q24_t;
typedef fxp64_t fxp64_q48_t;

typedef ufxp32_t ufxp32_q24_t;
typedef ufxp32_t ufxp32_q32_t;
typedef ufxp64_t ufxp64_q24_t;
typedef ufxp64_t ufxp64_q48_t;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !__ASR_TYPES_H__
