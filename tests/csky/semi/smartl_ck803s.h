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
