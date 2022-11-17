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
.include "macros.S"
.include "clic.S"
.include "constants.S"

.file "crt0.S"
/*
 * For importing variable or functions from script file "ckcpu.ld".
 */
.extern __stack     /* The stack pointer from linking script file */
.extern __sbss      /* The end of bss from linking script file */
.extern __ebss      /* The end of bss from linking script file */

/*
 * For importing variable or functions from other c or assemble files.
 */
.extern main                /* The c codes entry */
.extern coretimer_irq_handler

/* For exporting varialbe or functions */
.global ckcpu_vsr_table /* Vector table base address. */
.global __start             /* The system entry. */

.section .exp_table
/* Vector table space. */

.align 10
ckcpu_vsr_table:

.long __start
.rept 16
.long default_exception_handler
.endr
.long csky_timer_irq_handler
.rept  1007
.long default_exception_handler
.endr



/* The ckcpu startup codes. */
.text
    /*
     *
     * This is the codes first entry point. This is where it all
     * begins...
     */

__start:

    /*
     * Setup initial vector base table for interrupts and exceptions
     */
    la      t0, ckcpu_vsr_table
    csrw    mtvec, t0

    /* enable all interrupt */
    li      t0, SIFIVE_CLIC_BASE
    li      t1, SIFIVE_CLICINTIE_OFFSET
    add     t0, t0, t1
    li      t2, SIFIVE_CLIC_MAX_SOURCES
    li      t1, 1
__clic_init_enable:

    sb      t1, (t0)
    addi    t2, t2, -1
    addi    t1, t1, 1
    bnez    t2, __clic_init_enable

    /* Setup stack pointer based on hartid */
    csrr    t0, mhartid
    slli    t0, t0, STACK_SHIFT
    la      sp, __stack
    add     sp, sp, t0

    /*
     * Zero out the bss region.
     * NOTE: __sbss must align 4
     */
    la  t1, __sbss  /* Get start of bss from linking script file */
    la  t2, __ebss  /* Get end of bss from linking script file */
    sub t2, t2, t1      /* Calculate size of bss */
    srli    t2, t2,  2      /* Size of whole words */
    beqz    t2, __goto_c
    li      t0, 0       /* Set zero value to write */
2:
    sw      t0, (t1)    /* Zero next word */
    addi    t1, t1, 4       /* Increase bss pointer */
    addi    t2, t2, -1      /* Decrease counter */
    bnez    t2, 2b      /* Repeat for all bss */


    /*
     * Assember start up done, C codes start here.
     */
__goto_c:
    jal     main

    /* Should never get here. */
__exit:
    li      t0, 0
    li      t1, 0x10002000
    sw      t0, (t1)
    j       __exit

__init_done:

    /* park all harts excpet hart 0 */
    csrr    a0, mhartid
    bnez    a0, __park

    /* sleeping harts mtvec calls trap_fn upon receiving IPI */
__park:
    wfi
    j       __park

    .align 4
    csky_timer_irq_handler:
# Save registers.
    addi    sp, sp, -CONTEXT_SIZE
    sxsp    ra, 0
    sxsp    a0, 1
    sxsp    a1, 2
    sxsp    a2, 3
    sxsp    a3, 4
    sxsp    a4, 5
    sxsp    a5, 6
    sxsp    t0, 7
    sxsp    t1, 8
    sxsp    t2, 9

# Invoke the handler.
    mv      a0, sp
    csrr    a1, mcause
    csrr    a2, mepc
    jal     trap_handler

# Restore registers.
    lxsp    ra, 0
    lxsp    a0, 1
    lxsp    a1, 2
    lxsp    a2, 3
    lxsp    a3, 4
    lxsp    a4, 5
    lxsp    a5, 6
    lxsp    t0, 7
    lxsp    t1, 8
    lxsp    t2, 9
    addi sp, sp, CONTEXT_SIZE

# Return
    mret

/*
 * default exception service routine, before r0 initialized
 */
    .text
    .balign 4
default_exception_handler:
    j   default_exception_handler
    mret

trap_handler:
   li a0, 1
