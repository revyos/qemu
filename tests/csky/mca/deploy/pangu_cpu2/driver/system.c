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
 * @file     system.c
 * @brief    CSI Device System Source File for YUNVOICE
 * @version  V1.0
 * @date     06. Mar 2019
 ******************************************************************************/

#include <csi_config.h>
#include <stdint.h>
#include <io.h>
#include <soc.h>
#include <csi_core.h>
#ifndef CONFIG_SYSTICK_HZ
#define CONFIG_SYSTICK_HZ 100
#endif

extern uint32_t __Vectors[];
extern int32_t g_top_irqstack;
extern void irq_vectors_init(void);
extern void mm_heap_initialize(void);

int32_t drv_get_cpu_id(void)
{
#ifdef CONFIG_CHIP_YUNVOICE2_CPU0
    return 0;
#endif

#ifdef CONFIG_CHIP_YUNVOICE2_CPU1
    return 1;
#endif

    return 2;
}

#ifdef CONFIG_KERNEL_NONE
static void _system_init_for_baremetal(void)
{
    __enable_excp_irq();

    csi_coret_config(drv_get_sys_freq() / CONFIG_SYSTICK_HZ, CORET_IRQn);    //10ms

    mm_heap_initialize();
}
#endif

#ifndef CONFIG_KERNEL_NONE
static void _system_init_for_kernel(void)
{
#if defined(CONFIG_SUPPORT_TSPEND)
    __set_Int_SP((uint32_t)&g_top_irqstack);
    __set_CHR(__get_CHR() | CHR_ISE_Msk);
    VIC->TSPR = 0xFF;
#endif

#if !defined(CONFIG_SUPPORT_TSPEND)
    irq_vectors_init();
#endif

    csi_coret_config(drv_get_sys_freq() / CONFIG_SYSTICK_HZ, CORET_IRQn);    //10ms
    drv_irq_enable(CORET_IRQn);

#ifndef CONFIG_KERNEL_RHINO
#ifndef CONFIG_NUTTXMM_NONE
    mm_heap_initialize();
#endif
#endif
}
#endif

/**
  * @brief  initialize the system
  *         Initialize the psr and vbr.
  * @param  None
  * @return None
  */
void SystemInit(void)
{
    __set_VBR((uint32_t) & (__Vectors));

    /* Clear active and pending IRQ, and disable IRQ */
    VIC->IABR[0] = 0x0;
    VIC->ICPR[0] = 0xFFFFFFFF;
    VIC->ICER[0] = 0xFFFFFFFF;

#ifdef CONFIG_KERNEL_NONE
    _system_init_for_baremetal();
#else
    _system_init_for_kernel();
#endif
}


