#ifndef __FFT_FXP_H__
#define __FFT_FXP_H__

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * A switch that controls the enable state of rounding in the FFT.
 */
#define ENABLE_ROUNDING 0

/**
 * N-point real fixed-point FFT.
 *
 * Note:
 *   # x_len must be in range of [1, N]. If x_len is less than N, zeros will
 *     be appended.
 *   # x can be same as y, i.e. supports in-place computation.
 *   # y is stored as:
 *       [r(0), r(N/2), r1, i1, ..., r(N/2-2), i(N/2-2), r(N/2-1), i(N/2-1)]
 *   # Q of y is log2(N) less than the q of x.
 */

void real_fft_fxp_512(const int32_t *x, size_t x_len, int32_t *y);
void real_fft_fxp_256(const int32_t *x, size_t x_len, int32_t *y);
void real_fft_fxp_128(const int32_t *x, size_t x_len, int32_t *y);
void real_fft_fxp_64(const int32_t *x, size_t x_len, int32_t *y);
void real_fft_fxp_32(const int32_t *x, size_t x_len, int32_t *y);
void real_fft_fxp_16(const int32_t *x, size_t x_len, int32_t *y);

/**
 * Computes power spectrum with N-point real fixed-point FFT.
 *
 * Note:
 *   # x_len must be in range of [1, N]. If x_len is less than N, zeros will
 *     be appended.
 *   # power_spectrum is stored as:
 *       [ps(0), ps(1), ps(2), ..., ps(N/2-1), ps(N/2)]
 *   # Q of power_spectrum is:
 *       2 * (q_of_x - log2(N))
 */

void power_spectrum_fxp_512(const int32_t *x, size_t x_len, int64_t *ps);
void power_spectrum_fxp_256(const int32_t *x, size_t x_len, int64_t *ps);
void power_spectrum_fxp_128(const int32_t *x, size_t x_len, int64_t *ps);
void power_spectrum_fxp_64(const int32_t *x, size_t x_len, int64_t *ps);
void power_spectrum_fxp_32(const int32_t *x, size_t x_len, int64_t *ps);
void power_spectrum_fxp_16(const int32_t *x, size_t x_len, int64_t *ps);

/**
 * N-point real fixed-point inverse FFT.
 *
 * Note:
 *   # x can be same as y, i.e. supports in-place computation.
 *   # x is stored as:
 *       [r(0), r(N/2), r1, i1, ..., r(N/2-2), i(N/2-2), r(N/2-1), i(N/2-1)]
 *   # Q of y is 1 less than the q of x.
 */

void real_ifft_fxp_512(const int32_t *x, int32_t *y);
void real_ifft_fxp_256(const int32_t *x, int32_t *y);
void real_ifft_fxp_128(const int32_t *x, int32_t *y);
void real_ifft_fxp_64(const int32_t *x, int32_t *y);
void real_ifft_fxp_32(const int32_t *x, int32_t *y);
void real_ifft_fxp_16(const int32_t *x, int32_t *y);

/**
 * N-point complex fixed-point FFT.
 *
 * Note:
 *   # x can be same as y, i.e. supports in-place computation.
 *   # x and y is stored as:
 *       [r(0), i(0), r(1), i(1), ..., r(N-2), i(N-2), r(N-1), i(N-1)]
 *   # Q of y is log2(N)+1 less than the q of x.
 */

void complex_fft_fxp_512(const int32_t *x, int32_t *y);
void complex_fft_fxp_256(const int32_t *x, int32_t *y);
void complex_fft_fxp_128(const int32_t *x, int32_t *y);
void complex_fft_fxp_64(const int32_t *x, int32_t *y);
void complex_fft_fxp_32(const int32_t *x, int32_t *y);
void complex_fft_fxp_16(const int32_t *x, int32_t *y);

/**
 * N-point complex fixed-point inverse FFT.
 *
 * Note:
 *   # x can be same as y, i.e. supports in-place computation.
 *   # x and y is stored as:
 *       [r(0), i(0), r(1), i(1), ..., r(N-2), i(N-2), r(N-1), i(N-1)]
 *   # Q of y is 1 less than the q of x.
 */

void complex_ifft_fxp_512(const int32_t *x, int32_t *y);
void complex_ifft_fxp_256(const int32_t *x, int32_t *y);
void complex_ifft_fxp_128(const int32_t *x, int32_t *y);
void complex_ifft_fxp_64(const int32_t *x, int32_t *y);
void complex_ifft_fxp_32(const int32_t *x, int32_t *y);
void complex_ifft_fxp_16(const int32_t *x, int32_t *y);

#ifdef __cplusplus
}
#endif

#endif
