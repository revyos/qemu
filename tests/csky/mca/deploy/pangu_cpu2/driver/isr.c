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
 * @file     isr.c
 * @brief    source file for the interrupt server route
 * @version  V1.0
 * @date     06. Mar 2019
 ******************************************************************************/
#include <drv_common.h>
#include "csi_config.h"
#include "soc.h"
#include "soc_config.h"
#include "dw_dmac.h"
#ifndef CONFIG_KERNEL_NONE
#include <csi_kernel.h>
#endif

#define readl(addr) \
    ({ unsigned int __v = (*(volatile unsigned int *) (addr)); __v; })

#define writel(b,addr) (void)((*(volatile unsigned int *) (addr)) = (b))

extern void dw_dmac_irqhandler(int idx);
extern void dw_timer_irqhandler(int idx);
extern void ck_usi_irqhandler(int idx);
extern void ck_i2s_irqhandler(int32_t idx);
extern void dw_gpio_irqhandler(int32_t idx);
extern void ck_dma_irqhandler(int32_t idx);
extern void ck_mailbox_irqhandler(int32_t idx);
extern void ck_pwm_irqhandler(int32_t idx);
extern void dw_usart_irqhandler(int32_t idx);
extern void systick_handler(void);
extern void xPortSysTickHandler(void);
extern void OSTimeTick(void);
#ifndef CONFIG_KERNEL_NONE
#define  CSI_INTRPT_ENTER() csi_kernel_intrpt_enter()
#define  CSI_INTRPT_EXIT()  csi_kernel_intrpt_exit()
#else
#define  CSI_INTRPT_ENTER()
#define  CSI_INTRPT_EXIT()
#endif

#if defined(CONFIG_SUPPORT_TSPEND) || defined(CONFIG_KERNEL_NONE)
#define  ATTRIBUTE_ISR __attribute__((isr, no_icf))
#else
#define ATTRIBUTE_ISR
#endif

ATTRIBUTE_ISR  void CORET_IRQHandler(void)
{
#ifndef CONFIG_KERNEL_FREERTOS
    CSI_INTRPT_ENTER();
#endif

    readl(0xE000E010);

#if defined(CONFIG_KERNEL_RHINO)
    systick_handler();
#elif defined(CONFIG_KERNEL_FREERTOS)
    xPortSysTickHandler();
#elif defined(CONFIG_KERNEL_UCOS)
    OSTimeTick();
#endif

#ifndef CONFIG_KERNEL_FREERTOS
    CSI_INTRPT_EXIT();
#endif

}

ATTRIBUTE_ISR void USI2_IRQHandler(void)
{
    CSI_INTRPT_ENTER();
    ck_usi_irqhandler(0);
    CSI_INTRPT_EXIT();
}

ATTRIBUTE_ISR void USI3_IRQHandler(void)
{
    CSI_INTRPT_ENTER();
    ck_usi_irqhandler(1);
    CSI_INTRPT_EXIT();
}

ATTRIBUTE_ISR void TIM4_IRQHandler(void)
{
    CSI_INTRPT_ENTER();
    dw_timer_irqhandler(0);
    CSI_INTRPT_EXIT();
}

ATTRIBUTE_ISR void TIM5_IRQHandler(void)
{
    CSI_INTRPT_ENTER();
    dw_timer_irqhandler(1);
    CSI_INTRPT_EXIT();
}

ATTRIBUTE_ISR void TIM6_IRQHandler(void)
{
    CSI_INTRPT_ENTER();
    dw_timer_irqhandler(2);
    CSI_INTRPT_EXIT();
}
ATTRIBUTE_ISR void TIM7_IRQHandler(void)
{
    CSI_INTRPT_ENTER();
    dw_timer_irqhandler(3);
    CSI_INTRPT_EXIT();
}

ATTRIBUTE_ISR void PWM1_IRQHandler(void)
{
    CSI_INTRPT_ENTER();
    ck_pwm_irqhandler(0);
    CSI_INTRPT_EXIT();
}

ATTRIBUTE_ISR void GPIO1_IRQHandler(void)
{
    CSI_INTRPT_ENTER();
    dw_gpio_irqhandler(0);
    CSI_INTRPT_EXIT();
}

ATTRIBUTE_ISR void DMAC1_IRQHandler(void)
{
    CSI_INTRPT_ENTER();
    dw_dmac_irqhandler(0);
    CSI_INTRPT_EXIT();
}

ATTRIBUTE_ISR void MAESTRO_IRQHandler(void)
{
    writel(0x10, 0x80020210);
}

ATTRIBUTE_ISR void FSMC_IRQHandler(void)
{
    CSI_INTRPT_ENTER();

    writel(0x1, 0x3ffffd24);

    CSI_INTRPT_EXIT();
}

ATTRIBUTE_ISR void MAILBOX_IRQHandler(void)
{
    CSI_INTRPT_ENTER();
    ck_mailbox_irqhandler(2);
    CSI_INTRPT_EXIT();
}

ATTRIBUTE_ISR void USART2_IRQHandler(void)
{
    CSI_INTRPT_ENTER();
    dw_usart_irqhandler(0);
    CSI_INTRPT_EXIT();
}
ATTRIBUTE_ISR void USART3_IRQHandler(void)
{
    CSI_INTRPT_ENTER();
    dw_usart_irqhandler(1);
    CSI_INTRPT_EXIT();
}
