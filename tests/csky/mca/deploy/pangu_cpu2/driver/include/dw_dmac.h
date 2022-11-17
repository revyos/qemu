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
* @file     dw_dmac.h
* @brief    header file for DMAC Driver
* @version  V1.0
* @date     02. June 2017
******************************************************************************/
#ifndef __CK_DMA_H
#define __CK_DMA_H
#include <stdio.h>
#include "soc.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CK_DMA_MAXCHANNEL  2
#define CK_DMA_INT_EN      1
#define CK_DMA_CH_EN       1
#define CK_DMA_TFR   0x0002
#define CK_DMA_ERR   0x0001
#define CK_DMA_INTC     0x1f
#define CK_DMA_MASK     0x1f00

typedef enum {
    DMA_ADDR_INCREMENT = 0,
    DMA_ADDR_DECREMENT = 1,
    DMA_ADDR_NOCHANGE  = 2
} enum_addr_state_e;

typedef enum {
    DMA_DATAWIDTH_SIZE8  = 1,
    DMA_DATAWIDTH_SIZE16 = 2,
    DMA_DATAWIDTH_SIZE32 = 4
} dma_datawidth_e;

typedef enum {
    DMA_HANDSHAKING_HARDWARE = 0,
    DMA_HANDSHAKING_SOFTWARE = 1,
} dma_handshaking_select_e;

typedef enum {
    DMA_PRIORITY0 = 0,
    DMA_PRIORITY1 = 1,
    DMA_PRIOTITY2 = 2,
    DMA_PRIOTITY3 = 3
} dma_priority_t;

typedef enum {
    DWENUM_DMA_UART0_RX,
    DWENUM_DMA_UART0_TX,
    DWENUM_DMA_UART1_RX,
    DWENUM_DMA_UART1_TX,
    DWENUM_DMA_ADC_RX,
    DWENUM_DMA_ADC_TX,
    DWENUM_DMA_SPI1_RX,
    DWENUM_DMA_SPI1_TX,
    DWENUM_DMA_SPI0_RX,
    DWENUM_DMA_SPI0_TX,
    DWENUM_DMA_IIC0_RX,
    DWENUM_DMA_IIC0_TX,
    DWENUM_DMA_IIC1_RX,
    DWENUM_DMA_IIC1_TX,
    DWENUM_DMA_IIS_RX,
    DWENUM_DMA_IIS_TX,
    DWENUM_DMA_MEMORY
} dwenum_dma_device_e;

#define DMA_REG_SARx            0x0
#define DMA_REG_DARx            0x8
#define DMA_REG_CTRLax          0x18
#define DMA_REG_CTRLbx          0x1c
#define DMA_REG_CFGax           0x40
#define DMA_REG_CFGbx           0x44

#define DMA_REG_RawTfr          0x2c0
#define DMA_REG_RawBlock        0x2c8
#define DMA_REG_RawSrcTran      0x2d0
#define DMA_REG_RawDstTran      0x2d8
#define DMA_REG_RawErr          0x2e0

#define DMA_REG_StatusTfr       0x2e8
#define DMA_REG_StatusBlock     0x2f0
#define DMA_REG_StatusSrcTran   0x2f8
#define DMA_REG_StatusDstTran   0x300
#define DMA_REG_StatusErr       0x308

#define DMA_REG_MaskTfr         0x310
#define DMA_REG_MaskBlock       0x318
#define DMA_REG_MaskSrcTran     0x320
#define DMA_REG_MaskDstTran     0x328
#define DMA_REG_MaskErr         0x330

#define DMA_REG_ClearTfr        0x338
#define DMA_REG_ClearBlock      0x340
#define DMA_REG_ClearSrcTran    0x348
#define DMA_REG_ClearDstTran    0x350
#define DMA_REG_ClearErr        0x358
#define DMA_REG_StatusInt       0x360

#define DMA_REG_ReqSrc          0x368
#define DMA_REG_ReqDst          0x370
#define DMA_REG_SglReqSrc       0x378
#define DMA_REG_SglReqDst       0x380
#define DMA_REG_LstReqSrc       0x388
#define DMA_REG_LstReqDst       0x390

#define DMA_REG_Cfg             0x398
#define DMA_REG_ChEn            0x3a0

typedef struct {
    __IOM uint32_t   SARx;        /* offset: 0x00 (R/W) Source Address Register for Channel x                  */
          uint32_t   RESERVED0;
    __IOM uint32_t   DARx;        /* offset: 0x08 (R/W) Destination Address Register for Channel x             */
          uint32_t   RESERVED1;
    __IOM uint32_t   LLPLx;       /* offset: 0x10 (R/W) Linked List Pointer Register for Channel x, Low word   */
    __IOM uint32_t   LLPHx;       /* offset: 0x14 (R/W) Linked List Pointer Register for Channel x, High word  */
    __IOM uint32_t   CTLLx;       /* offset: 0x18 (R/W) Control Register for channel x, Low word               */
    __IOM uint32_t   CTLHx;       /* offset: 0x1C (R/W) Control Register for channel x, high word              */
    __IOM uint32_t   SSTATx;      /* offset: 0x20 (R/W) Source Status Register for Channel x                   */
          uint32_t   RESERVED2;
    __IOM uint32_t   DSTATx;      /* offset: 0x28 (R/W) Destination Status Register for Channel x              */
          uint32_t   RESERVED3;
    __IOM uint32_t   SSTATARx;    /* offset: 0x30 (R/W) Source Status Address Register for Channel x           */
          uint32_t   RESERVED4;
    __IOM uint32_t   DSTATARx;    /* offset: 0x38 (R/W) Destination Status Address Register for Channel x      */
          uint32_t   RESERVED5;
    __IOM uint32_t   CFGLx;       /* offset: 0x40 (R/W) Configuration Register for Channel x, low word         */
    __IOM uint32_t   CFGHx;       /* offset: 0x44 (R/W) Configuration Register for Channel x, hgih word        */
    __IOM uint32_t   SGRx;        /* offset: 0x48 (R/W) Source Gather Register for Channel x                   */
          uint32_t   RESERVED6;
    __IOM uint32_t   DSRx;        /* offset: 0x50 (R/W) Destination Scatter Register for Channel x             */
          uint32_t   RESERVED7;
} dw_dma_chn_reg_t;

typedef struct {
	dw_dma_chn_reg_t  CHN0_REG;
	dw_dma_chn_reg_t  CHN1_REG;
	dw_dma_chn_reg_t  CHN2_REG;
	dw_dma_chn_reg_t  CHN3_REG;
	dw_dma_chn_reg_t  CHN4_REG;
	dw_dma_chn_reg_t  CHN5_REG;
	dw_dma_chn_reg_t  CHN6_REG;
	dw_dma_chn_reg_t  CHN7_REG;
    __IM  uint32_t   RawTfr;        /* offset: 0x2C0 (R)   Interrupt Raw Status Registers                     */
          uint32_t   RESERVED0;
    __IM  uint32_t   RawBlock;      /* offset: 0x2C8 (R)   Interrupt Raw Status Registers                     */
          uint32_t   RESERVED1;
    __IM  uint32_t   RawSrcTran;    /* offset: 0x2D0 (R)   Interrupt Raw Status Registers                     */
          uint32_t   RESERVED2;
    __IM  uint32_t   RawDstTran;    /* offset: 0x2D8 (R)   Interrupt Raw Status Registers                     */
          uint32_t   RESERVED3;
    __IM  uint32_t   RawErr;        /* offset: 0x2E0 (R)   Interrupt Raw Status Registers                     */
          uint32_t   RESERVED4;
    __IM  uint32_t   StatusTfr;     /* offset: 0x2E8 (R)   Interrupt Status Registers                         */
          uint32_t   RESERVED5;
    __IM  uint32_t   StatusBlock;   /* offset: 0x2F0 (R)   Interrupt Status Registers                         */
          uint32_t   RESERVED6;
    __IM  uint32_t   StatusSrcTran; /* offset: 0x2F8 (R)   Interrupt Status Registers                         */
          uint32_t   RESERVED7;
    __IM  uint32_t   StatusDstTran; /* offset: 0x300 (R)   Interrupt Status Registers                         */
          uint32_t   RESERVED8;
    __IM  uint32_t   StatusErr;     /* offset: 0x308 (R)   Interrupt Status Registers                         */
          uint32_t   RESERVED9;
    __IOM uint32_t   MaskTfr;       /* offset: 0x310 (R/W) Interrupt Mask Registers                           */
          uint32_t   RESERVED10;
    __IOM uint32_t   MaskBlock;     /* offset: 0x318 (R/W) Interrupt Mask Registers                           */
          uint32_t   RESERVED11;
    __IOM uint32_t   MaskSrcTran;   /* offset: 0x320 (R/W) Interrupt Mask Registers                           */
          uint32_t   RESERVED12;
    __IOM uint32_t   MaskDstTran;   /* offset: 0x328 (R/W) Interrupt Mask Registers                           */
          uint32_t   RESERVED13;
    __IOM uint32_t   MaskErr;       /* offset: 0x330 (R/W) Interrupt Mask Registers                           */
          uint32_t   RESERVED14;
    __OM  uint32_t   ClearTfr;      /* offset: 0x338 (W)   Interrupt Clear Registers                          */
          uint32_t   RESERVED15;
    __OM  uint32_t   ClearBlock;    /* offset: 0x340 (W)   Interrupt Clear Registers                          */
          uint32_t   RESERVED16;
    __OM  uint32_t   ClearSrcTran;  /* offset: 0x348 (W)   Interrupt Clear Registers                          */
          uint32_t   RESERVED17;
    __OM  uint32_t   ClearDstTran;  /* offset: 0x350 (W)   Interrupt Clear Registers                          */
          uint32_t   RESERVED18;
    __OM  uint32_t   ClearErr;      /* offset: 0x358 (W)   Interrupt Clear Registers                          */
          uint32_t   RESERVED19;
    __IM  uint32_t   StatusInt;     /* offset: 0x360 (R/W) Status for each interrupt type         */
          uint32_t   RESERVED20;
    __IOM uint32_t   ReqSrcReg;     /* offset: 0x368 (R/W) Source Software Transaction Request Register      */
          uint32_t   RESERVED21;
    __IOM uint32_t   ReqDstReg;     /* offset: 0x370 (R/W) Destination Software Transaction Request Register */
          uint32_t   RESERVED22;
    __IOM uint32_t   SjlReqSrcReg;  /* offset: 0x378 (R/W) Single Source Transaction Request Register        */
          uint32_t   RESERVED23;
    __IOM uint32_t   SjlReqDstReg;  /* offset: 0x380 (R/W) Single Destination Transaction Request Register   */
          uint32_t   RESERVED24;
    __IOM uint32_t   LstSrcReg;     /* offset: 0x388 (R/W) Last Source Transaction Request Register          */
          uint32_t   RESERVED25;
    __IOM uint32_t   LstDstReg;     /* offset: 0x390 (R/W) Last Destination Transaction Request Register     */
          uint32_t   RESERVED26;
    __IOM uint32_t   DmaCfgReg;     /* offset: 0x398 (R/W) DW_ahb_dmac Configuration Register                */
          uint32_t   RESERVED27;
    __IOM uint32_t   ChEnReg;       /* offset: 0x3A0 (R/W) DW_ahb_dmac Channel Enable Register               */
          uint32_t   RESERVED28;
    __IM  uint32_t   DmaIdReg;      /* offset: 0x3A8 (R)   DW_ahb_dmac ID Register                           */
} dw_dma_reg_t;

#define  DMAC0_BASE  ((dw_dma_reg_t *)CSKY_DMAC0_BASE)
#define  DMAC1_BASE  ((dw_dma_reg_t *)CSKY_DMAC1_BASE)

//typedef struct {
//    __IOM uint32_t   SAR;       /* offset: 0x00 (R/W) Channel Source Address Register        */
//    __IOM uint32_t   DAR;       /* offset: 0x04 (R/W) Channel Destination Address Register   */
//    __IOM uint32_t   CHCTRLA;   /* offset: 0x08 (R/W) Channel Control Register A             */
//    __IOM uint32_t   CHCTRLB;   /* offset: 0x0C (R/W) Channel Control Register B             */
//    __IOM uint8_t   CHINTM:2;    /* offset: 0x10 (R/W) Channel Interrupt Mask Register        */
//    uint8_t  RESERVED0[3];
//    __IM  uint8_t   CHINTS:2;    /* offset: 0x14 (R/ ) Channel Interrupt Status Register      */
//    uint8_t  RESERVED1[3];
//    __IOM uint8_t   CHINTC:2;    /* offset: 0x18 (R/W) Channel Interrupt Clear Register       */
//    uint8_t  RESERVED2[3];
//    __IOM uint8_t   CHSREQ:1;    /* offset: 0x1C (R/W) Channel Software Request Register      */
//    uint8_t  RESERVED3[3];
//    __IOM uint8_t   CHEN:1;      /* offset: 0x20 (R/W) Channel Enable Register                */
//    uint8_t  RESERVED4[3];
//} dw_dma_reg_t;
#ifdef __cplusplus
}
#endif

#endif /* __CK_DMA_H */
