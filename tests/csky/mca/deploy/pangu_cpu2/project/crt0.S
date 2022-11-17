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
 * @file     startup.S
 * @brief    startup file. Should use with
 *           GCC for CSKY Embedded Processors
 * @version  V1.0
 * @date     06. Mar 2019
 ******************************************************************************/

#include <../include/csi_config.h>

.section .vectors
    .align  10
    .globl  __Vectors
    .type   __Vectors, @object
__Vectors:
    .long   Reset_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   trap0_handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   tspend_handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    /* External interrupts */
#if defined (CONFIG_KERNEL_NONE) || defined (CONFIG_SUPPORT_TSPEND)
    .rept   9
    .long   Default_Handler
    .endr

    .long   DMAC1_IRQHandler

    .long   CORET_IRQHandler
    .rept   53
    .long   Default_Handler
    .endr
#else

    .rept   64
    .long   NOVIC_IRQ_Default_Handler    /*  default interrupt entry  */
    .endr
#endif

    .size    __Vectors, . - __Vectors

    .text
    .align   2
_start:
    .text
    .long    Reset_Handler
    .align   2
    .globl   Reset_Handler
    .type    Reset_Handler, %function
Reset_Handler:
//    lrw     r0, 0xe000f000   /* Cache register base address */
//    lrw     r2, 0x800006d    /* CRCR1 value means: Cached data from 0x8000000(QSPIFLASH), Size= 8MB, Enable*/
//    lrw     r1, 0x1800006d   /* CRCR0 value means: Cached data from 0x18000000(SDRAM), Size= 8MB, Enable*/
//    stw     r1, (r0, 0x8)    /* store 0x10000063 to CRCR0(0xe000f008) */
//    stw     r2, (r0, 0xC)    /* store 0x10000063 to CRCR0(0xe000f008) */
//    movi    r1, 0x7          /* store 0x1 to r1 */
//    stw     r1, (r0, 0x4)    /* set CIR(0xe000f004) to 0x1, means invalid all caches */
//    movi    r1, 0x15          /* store 0x15 to r1 */
//    stw     r1, (r0, 0x0)    /* set CER(0xe000f000) to 0x1, means enable all caches */

    /* enable return speculative execution */
    mfcr    r0, cr<31,0>
    bseti   r0, 3
    mtcr    r0, cr<31,0>
#ifndef CONFIG_SYSTEM_SECURE
    lrw     r0, 0x80000000
    mtcr    r0, psr
#else
    lrw     r0, 0xe0000000
    mtcr    r0, psr
#endif

    lrw     r0, g_top_irqstack
    mov     sp, r0

/*
 *  The ranges of copy from/to are specified by following symbols
 *    __etext: LMA of start of the section to copy from. Usually end of text
 *    __data_start__: VMA of start of the section to copy to
 *    __data_end__: VMA of end of the section to copy to
 *
 *  All addresses must be aligned to 4 bytes boundary.
 */
#    lrw     r1, __erodata
#    lrw     r2, __data_start__
#    lrw     r3, __data_end__
#
#    subu    r3, r2
#    cmpnei  r3, 0
#    bf      .L_loop0_done
#
#.L_loop0:
#    ldw     r0, (r1, 0)
#    stw     r0, (r2, 0)
#    addi    r1, 4
#    addi    r2, 4
#    subi    r3, 4
#    cmpnei  r3, 0
#    bt      .L_loop0
#
#.L_loop0_done:

/*
 *  The BSS section is specified by following symbols
 *    __bss_start__: start of the BSS section.
 *    __bss_end__: end of the BSS section.
 *
 *  Both addresses must be aligned to 4 bytes boundary.
 */
    lrw     r1, __bss_start__
    lrw     r2, __bss_end__

    movi    r0, 0

    subu    r2, r1
    cmpnei  r2, 0
    bf      .L_loop1_done

.L_loop1:
    stw     r0, (r1, 0)
    addi    r1, 4
    subi    r2, 4
    cmpnei  r2, 0
    bt      .L_loop1
.L_loop1_done:

#ifndef __NO_SYSTEM_INIT
    jbsr    SystemInit
#endif

#ifndef __NO_BOARD_INIT
    jbsr    board_init
#endif

    jbsr    main

    .size    Reset_Handler, . - Reset_Handler
    .globl  __exit
__exit:
    br      __exit

.section .bss

    .align  2
    .global g_intstackalloc
    .global g_intstackbase
    .global g_top_irqstack
g_intstackalloc:
g_intstackbase:
    .space  CONFIG_ARCH_INTERRUPTSTACK
g_top_irqstack:
