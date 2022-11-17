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

/*
 * crt0.S -- startup codes for CK-CPU.
 *
 * Define a exception vector table
 *
 * Initial PSR register.
 * Initial VBR register, relocate exception vector table.
 * Initial sp(stack pointer) register.
 * Initial BSS section to "0"
 * Then goto "main".
 *
 * Copyright (C) 2008~2015  Hangzhou C-SKY Microsystems Co., Ltd
 */

.file "crt0.S"

/*
 * For importing variable or functions from script file "ckcpu.ld".
 */
.import __stack		/* The stack pointer from linking script file */
.import	__sbss		/* The end of bss from linking script file */
.import __ebss		/* The end of bss from linking script file */

/*
 * For importing variable or functions from other c or assemble files.
 */
.import main				/* The c codes entry */
.import corex
.import core0
.import core1
.import core2
.import core3
.import mic_int_handler

/* For exporting varialbe or functions */
.export	ckcpu_vsr_table	/* Vector table base address. */
.export __start				/* The system entry. */

.section .exp_table
/* Vector table space. */

.align 10
ckcpu_vsr_table:

.long __start
.rept 9 
.long default_exception_handler
.endr
.long int_autovec_handler
.long default_exception_handler
.long default_exception_handler

.long default_exception_handler
.long default_exception_handler
.long default_exception_handler
/************test CSI use**************************/
.long default_exception_handler
/************test CSI use**************************/
.long default_exception_handler
/************test CSI use**************************/
.long default_exception_handler
/************test CSI use**************************/
.long default_exception_handler
.rept 25
.long default_exception_handler
.endr

ckcpu_rvbr_table:
.long core1start - 0x80000000
.long core2start - 0x80000000
.long core3start - 0x80000000


/* The ckcpu startup codes. */
.text
	/*
	 *
	 * This is the codes first entry point. This is where it all
	 * begins...
	 */

__start:
	/*
	 * Init psr value, enable exception, disable interrupt and fast interrupt.
	 * psr = 0x80000100
	 */
	lrw	a3, 0x80000100
	mtcr	a3, psr

	/*
	 * Setup initial vector base table for interrupts and exceptions
	 */
	lrw	a2, ckcpu_vsr_table
	mtcr	a2, vbr

	/* Initialize the normal stack pointer from the linker definition. */
	lrw	a1, __stack
	mov	sp, a1

	/*
	 * Zero out the bss region.
	 * NOTE: __sbss must align 4
	 */
	lrw	a3, __sbss	/* Get start of bss from linking script file */
	lrw	a2, __ebss	/* Get end of bss from linking script file */
	subu	a2, a3		/* Calculate size of bss */
	lsri	a2, 2		/* Size of whole words */
	cmpnei	a2, 0
	bf __goto_c	
	movi	a1, 0		/* Set zero value to write */
2:
	stw	a1, (a3)	/* Zero next word */
	addi	a3, 4		/* Increase bss pointer */
	subi	a2, 1		/* Decrease counter */
	cmpnei	a2, 0
	bt	2b		/* Repeat for all bss */

	/*
	 * Assember start up done, C codes start here.
	 */
__goto_c:
	bsr core0	
__release_cores:
    lrw a0, ckcpu_rvbr_table
    lrw a1, 0x80000000
    sub a0, a1
    mtcr a0, cr<28, 0>
    mfcr a0, cr<29, 0>
    bseti a0, 1 
    mtcr a0, cr<29, 0>
   # movi a0, 1
   # mtcr a0, cr<31, 0>
	/* Should never get here. */
__exit:
        bsr corex
        lrw a1, 0xbfffa000
        stw a0, (a1, 0x0)
	//bkpt
	br	__exit


    .text
	.balign 0x1000 
core1start:
    lrw	a3, 0x80000100
	mtcr a3, psr
	lrw	a1, __stack
    subi a1, 0x100
	mov	sp, a1
    bsr core1
    lrw a0, ckcpu_rvbr_table
    lrw a1, 0x80000000
    sub a0, a1
    addi a0, 4
    mtcr a0, cr<28, 0>
    mfcr a0, cr<29, 0>
    bseti a0, 2 
    mtcr a0, cr<29, 0>

   # movi a0, 2
   # mtcr a0, cr<31, 0>
    bsr corex

    .text
	.balign 0x1000 
core2start:
    lrw	a3, 0x80000100
	mtcr	a3, psr
	lrw	a1, __stack
    subi a1, 0x200
	mov	sp, a1
    bsr core2
    lrw a0, ckcpu_rvbr_table
    lrw a1, 0x80000000
    sub a0, a1
    addi a0, 8
    mtcr a0, cr<28, 0>
    mfcr a0, cr<29, 0>
    bseti a0, 3 
    mtcr a0, cr<29, 0>


   # movi a0, 3
   # mtcr a0, cr<31, 0>
    bsr corex 

    .text
	.balign 0x1000 
core3start:
    lrw	a3, 0x80000100
	mtcr	a3, psr
	lrw	a1, __stack
    subi a1, 0x300
	mov	sp, a1
    bsr core3
    bsr corex 
/*
 * default auot interrupt service routine
 */
	.text
	.balign 4
int_autovec_handler:
    subi sp, 16 
    stw a0, (sp, 0)
    stw a1, (sp, 4)
	stw a2, (sp, 8)
	stw a3, (sp, 12)
    bsr mic_int_handler
    ldw a0, (sp, 0)
    ldw a1, (sp, 4)
    ldw a2, (sp, 0)
    ldw a3, (sp, 4)
    addi sp,16 
	rte


/*
 * default exception service routine, before r0 initialized
 */
	.text
	.balign 4
default_exception_handler:
	br	default_exception_handler
	rte
