/* ---------------------------------------------------------------------------
 * Copyright (C) 2016 CSKY Limited. All rights reserved.
 *
 * Redistribution and use of this software in source and binary forms,
 * with or without modification, are permitted provided that the following
 * conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *   * Neither the name of CSKY Ltd. nor the names of CSKY's contributors may
 *     be used to endorse or promote products derived from this software without
 *     specific prior written permission of CSKY Ltd.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 * -------------------------------------------------------------------------- */
/******************************************************************************
 * @file     smart_card_ck803s.h
 * @brief    CSI Core Peripheral Access Layer Header File for
 *           CK803 Device Series
 * @version  V3.00
 * @date     16. October 2015
 ******************************************************************************/

#ifndef SMART_CARD_CK803_H
#define SMART_CARD_CK803_H

#ifdef __cplusplus
//extern "C" {
#endif

/* APB frequence definition */
#define APB_DEFAULT_FREQ       48000000	/* Hz */

/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum IRQn {
/* ----------------------  CK803CM0 Specific Interrupt Numbers  --------------------- */
	CORET_IRQn = 1,
	UART0_IRQn = 2,
} IRQn_Type;

#define __RESET_CONST 0xABCD1234

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* --------  Configuration of the CK803 Processor and Core Peripherals  ------- */
#define __CM0_REV                 0x0000U	/* Core revision r0p0 */
#define __MGU_PRESENT             0		/* MGU present or not */
#define __GSR_GCR_PRESENT         0		/* no GSR/GCR present */
#define __SOFTRESET_PRESENT       0		/* no soft reset present */
#define __DCACHE_PRESENT          1
#define __ICACHE_PRESENT          1
#define __NVIC_PRIO_BITS          2		/* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0		/* Set to 1 if different SysTick Config is used */

#define __CMSIS_COMPATIBLE        1
#include "CSICORE_CK803S.h"			/* Processor and core peripherals */

/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */

/* ================================================================================ */
/* ============== Universal Asyncronous Receiver / Transmitter (UART) ============= */
/* ================================================================================ */
typedef struct {
	union {
		__IM uint32_t RBR;	/* Offset: 0x000 (R/ )  Receive buffer register */
		__OM uint32_t THR;	/* Offset: 0x000 ( /W)  Transmission hold register */
		__IOM uint32_t DLL;	/* Offset: 0x000 (R/W)  Clock frequency division low section register */
	};
	union {
		__IOM uint32_t DLH;	/* Offset: 0x004 (R/W)  Clock frequency division high section register */
		__IOM uint32_t IER;	/* Offset: 0x004 (R/W)  Interrupt enable register */
	};
	__IM uint32_t IIR;		/* Offset: 0x008 (R/ )  Interrupt indicia register */
	__IOM uint32_t LCR;		/* Offset: 0x00C (R/W)  Transmission control register */
	uint32_t RESERVED0;
	__IM uint32_t LSR;		/* Offset: 0x014 (R/ )  Transmission state register */
	uint32_t RESERVED1[25];
	__IM uint32_t USR;		/* Offset: 0x07c (R/ )  UART state register */
} SMARTL_UART_TypeDef;

#define DCACHE_LINE_SIZE 16
#define DCACHE_SIZE 32*1024
/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */
#define SMARTL_UART0_BASE            (0x40015000UL)

/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */
#define SMARTL_UART0                 ((SMARTL_UART_TypeDef *)    SMARTL_UART0_BASE)

#define SMARTL_UART0                 ((SMARTL_UART_TypeDef *)    SMARTL_UART0_BASE)

#define SMARTL_RAM0_BASE             0x0
#define SMARTL_CACHE_CRCR0           CACHE_CRCR_1M            

#define SMARTL_RAM1_BASE             0x20000000
#define SMARTL_CACHE_CRCR1           CACHE_CRCR_1M

#ifdef __cplusplus
//}
#endif
#endif /* SMART_CARD_CK803_H */
