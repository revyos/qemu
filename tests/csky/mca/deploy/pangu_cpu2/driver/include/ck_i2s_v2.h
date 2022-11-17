/*
 * Copyright (C) 2017 C-SKY Microsystems Co., Ltd. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/******************************************************************************
 * @file     ck_i2s_v2.h
 * @brief    header File for I2S Driver
 * @version  V1.0
 * @date     02. June 2018
 ******************************************************************************/
#ifndef _CK_I2S_V2_H_
#define _CK_I2S_V2_H_
#include "soc.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Bitfields in IIS_AUDIOEN */
#define AUDIOEN_IIS_EN      (1 << 0)    /* IIS enable */
#define AUDIOEN_SPDIF_EN    (1 << 1)    /* SPDIF enable */

/* Bitfields in IIS_FUNCMODE */
#define FUNCMODE_MODE_RX    (0 << 0)
#define FUNCMODE_MODE_TX    (1 << 0)
#define FUNCMODE_MODE_WEN   (1 << 1)    /* MODE write enable */

/* Bitfields in IIS_IISCNF_IN */
#define I2SCNF_IN_AUDFMT_I2S            (0 << 0)
#define I2SCNF_IN_AUDFMT_RIGHT_J        (1 << 0)
#define I2SCNF_IN_AUDFMT_LEFT_J         (2 << 0)
#define I2SCNF_IN_WS_POLARITY_NORMAL    (0 << 2)
#define I2SCNF_IN_WS_POLARITY_INVERTED  (1 << 2)
#define I2SCNF_IN_SAMPLE_SOURCE_VOICE   (1 << 4)
#define I2SCNF_IN_SLAVE         (0 << 8)
#define I2SCNF_IN_MASTER        (1 << 8)

/* Bitfields in I2S_IISCNF_OUT */
#define I2SCNF_OUT_SLAVE                (0 << 4)
#define I2SCNF_OUT_MASTER               (1 << 4)
#define I2SCNF_OUT_SOURCE_STEREO        (0 << 3)
#define I2SCNF_OUT_SOURCE_MONO          (1 << 3)
#define I2SCNF_OUT_AUDFMT_I2S           (0 << 0)
#define I2SCNF_OUT_AUDFMT_RIGHT_J       (1 << 0)
#define I2SCNF_OUT_AUDFMT_LEFT_J        (2 << 0)
#define I2SCNF_OUT_AUDFMT_PCM           (3 << 0)
#define I2SCNF_OUT_AUDFMT_MASK          (3 << 0)

/* Bitfields in I2S_FSSTA */
#define FSSTA_MCLK_SEL_256     (0x0 << 16)
#define FSSTA_MCLK_SEL_384     (0x1 << 16)
#define FSSTA_MCLK_SEL_MASK    (0x1 << 16)
#define FSSTA_SCLK_SEL_32      (0x0 << 12)
#define FSSTA_SCLK_SEL_48      (0x1 << 12)
#define FSSTA_SCLK_SEL_64      (0x2 << 12)
#define FSSTA_SCLK_SEL_16      (0x3 << 12)
#define FSSTA_SCLK_SEL_MASK    (0x3 << 12)
#define FSSTA_DATAWTH_BITS16_FIFO16      (0x0 << 8)
#define FSSTA_DATAWTH_BITS16_FIFO24      (0x1 << 8)
#define FSSTA_DATAWTH_BITS16_FIFO16      (0x0 << 8)
#define FSSTA_DATAWTH_BITS16_FIFO24      (0x1 << 8)
#define FSSTA_DATAWTH_BITS24_FIFO16      (0x4 << 8)
#define FSSTA_DATAWTH_BITS24_FIFO24      (0x5 << 8)
#define FSSTA_DATAWTH_BITS24_FIFO32      (0x6 << 8)
#define FSSTA_DATAWTH_BITS32_FIFO16      (0x8 << 8)
#define FSSTA_DATAWTH_BITS32_FIFO24      (0x9 << 8)
#define FSSTA_DATAWTH_BITS32_FIFO32      (0xb << 8)
#define FSSTA_DATAWTH_BITS8_FIFO16       (0xc << 8)
#define FSSTA_DATAWTH_BITS8_FIFO24       (0xd << 8)
#define FSSTA_DATAWTH_BITS8_FIFO32       (0xe << 8)
#define FSSTA_DATAWTH_BITS8_FIFO8        (0xf << 8)
#define FSSTA_DATAWTH_MASK               (0xf << 8)
#define FSSTA_AFR(x)            ((x) << 4)    /* Audio Fundamental Rate */
#define FSSTA_AFR_MASK          (0x3 << 4)
#define FSSTA_ARS(x)            ((x) << 6)    /* Audio Rate Scale(I2S only) */
#define FSSTA_ARS_MASK          (0x3 << 6)
#define FSSTA_RATE_SET_BY_USER  (0 << 0)    /* input rate is set by user */
#define FSSTA_RATE_AUTO_DETECT  (1 << 0)    /* input rate auto detected */

#define TXFTLR_TFT(x)   ((x) << 0)
#define RXFTLR_RFT(x)   ((x) << 0)

/* Bitfields in IIS_IMR */
#define I2SIMR_IFSCM    (1 << 9)    /* Input sample frequency change Mask */
#define I2SIMR_ITBFCM   (1 << 8)    /* I2S tx busy flag change Mask */
#define I2SIMR_IRBFCM   (1 << 7)    /* I2S Rx busy flag change Mask */
#define I2SIMR_RXFIM    (1 << 6)    /* Receive FIFO Threshold Full Interrupt Mask */
#define I2SIMR_TXEIM    (1 << 5)    /* Transmit FIFO Threshold Empty Interrupt Mask */
#define I2SIMR_RXIOM    (1 << 4)    /* Receive FIFO Overflow error Mask */
#define I2SIMR_RXUIM    (1 << 3)    /* Receive FIFO Underflow error Mask */
#define I2SIMR_TXOIM    (1 << 2)    /* Transmit FIFO overflow error Mask */
#define I2SIMR_TXUIRM   (1 << 1)    /* Transmit FIFO Underflow error Mask */
#define I2SIMR_WADEM    (1 << 0)    /* I2S wrong address error Mask */

//#define I2SIMR_DEFAULT_MASK  (I2SIMR_RXIOM | I2SIMR_RXUIM | I2SIMR_TXOIM)
#define I2SIMR_DEFAULT_MASK  (I2SIMR_WADEM | I2SIMR_TXUIRM | I2SIMR_TXEIM | I2SIMR_RXUIM | I2SIMR_RXIOM)
/* dmac */
#define  I2SDMACR_TX_ENABLE     (1 << 1)
#define  I2SDMACR_RX_ENABLE     (1 << 0)
/* Bitfields in IIS_FICR */
#define I2SICR_IFSC     (1 << 9)    /* clear Input sample frequency change Mask */
#define I2SICR_ITBFC    (1 << 8)    /* clear I2S tx busy flag change Mask */
#define I2SICR_IRBFC    (1 << 7)    /* clear I2S Rx busy flag change Mask */
#define I2SICR_RXFIC    (1 << 6)    /* clear Receive FIFO Threshold Full Interrupt Mask */
#define I2SICR_TXEIC    (1 << 5)    /* clear Transmit FIFO Threshold Empty Interrupt Mask */
#define I2SICR_RXIOC    (1 << 4)    /* clear Receive FIFO Overflow error Mask */
#define I2SICR_RXUIC    (1 << 3)    /* clear Receive FIFO Underflow error Mask */
#define I2SICR_TXOIC    (1 << 2)    /* clear Transmit FIFO overflow error Mask */
#define I2SICR_TXUIRC   (1 << 1)    /* clear Transmit FIFO Underflow error Mask */
#define I2SICR_WADEC    (1 << 0)    /* clear I2S wrong address error Mask */

#define CK_I2S_FIFO_MAX_LV      0x20
/* Bitfields in IIS_SR */
#define I2SSR_TX_BUSY   (1 << 1)    /* IIS Tx Busy Flag. */
#define I2SSR_RX_BUSY   (1 << 0)    /* IIS Rx Busy Flag */

/* Bitfields in IIS DMACR */
#define I2S_DMACR_TDMAE   (1 << 1)    /* Transmit DMA Enable. */
#define I2S_DMACR_RDMAE   (0 << 1)    /* Receive DMA Enable. */

#define I2S_DMARDLR(x)   (x)    /* Receive Data Level. */
#define I2S_DMATDLR(x)   (x)    /* Transmit Data Level. */

#define I2S_SRC_CLK  12288000

typedef struct {
    __IOM uint32_t I2S_IISEN;            /* Offset: 0x000h (R/W)  AUDIO_IO Enable Register */
    __IOM uint32_t I2S_FUNCMODE;         /* Offset: 0x004h (R/W)  AUDIO_IO function mode */
    __IOM uint32_t I2S_IISCNF_IN;        /* Offset: 0x008h (R/W)  IIS interface configuration in (on ARX side) */
    __IOM uint32_t I2S_FSSTA;            /* Offset: 0x00ch (R/W)  IIS ATX audio input control/state register */
    __IOM uint32_t I2S_IISCNF_OUT;       /* Offset: 0x010h (R/W)  IIS interface configuration in (on ATX side) */
    __IOM uint32_t I2S_FADTLR;           /* Offset: 0x014h (R/W)  IIS Fs auto detected Threshold level register */
    __IOM uint32_t I2S_SCCR;             /* Offset: 0x018h (R/W)  Sample compress control register */
    __IOM uint32_t I2S_TXFTLR;           /* Offset: 0x01ch (R/W)  Transmit FIFO Threshold Level */
    __IOM uint32_t I2S_RXFTLR;           /* Offset: 0x020h (R/W)  Receive FIFO Threshold Level */
    __IOM uint32_t I2S_TXFLR;            /* Offset: 0x024h (R/W)  Transmit FIFO Level Register */
    __IOM uint32_t I2S_RXFLR;            /* Offset: 0x028h (R/W)  Receive FIFO Level Register */
    __IOM uint32_t I2S_SR;               /* Offset: 0x02ch (R/W)  Status Register */
    __IOM uint32_t I2S_IMR;              /* Offset: 0x030h (R/W)  Interrupt Mask Register */
    __IOM uint32_t I2S_ISR;              /* Offset: 0x034h (R/W)  Interrupt Status Register */
    __IOM uint32_t I2S_RISR;             /* Offset: 0x038h (R/W)  Raw Interrupt Status Register */
    __IOM uint32_t I2S_ICR;              /* Offset: 0x03ch (R/W)  FIFO Interrupt Clear Register */
    __IOM uint32_t I2S_DMACR;            /* Offset: 0x040h (R/W)  DMA Control Register */
    __IOM uint32_t I2S_DMATDLR;          /* Offset: 0x044h (R/W)  DMA Transmit Data Level */
    __IOM uint32_t I2S_DMARDLR;          /* Offset: 0x048h (R/W)  DMA Receive Data Level */
    __IOM uint32_t I2S_DR;               /* Offset: 0x04Ch (R/W)  Data Register */
    __IOM uint32_t I2S_DIV0_LEVEL;       /* Offset: 0x050h (R/W)  Divide i2s_clkgen source clock, get mclk or sclk */
    __IOM uint32_t I2S_DIV3_LEVEL;       /* Offset: 0x054h (R/W)  Divide i2s_clkgen source clock, get reference clock */
} ck_i2s_v2_reg_t;

#ifdef __cplusplus
}
#endif

#endif /* _CK_I2S_V2_H_ */
