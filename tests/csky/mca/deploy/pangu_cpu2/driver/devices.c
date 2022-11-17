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
 * @file     devices.c
 * @brief    source file for the devices
 * @version  V1.0
 * @date     07. Mar 2019
 ******************************************************************************/

#include <stdio.h>
#include <csi_config.h>
#include <soc.h>
#include <drv_usart.h>
#include <drv_timer.h>
#include <drv_rtc.h>
#include <drv_trng.h>
#include <drv_crc.h>
#include <drv_aes.h>
#include <drv_rsa.h>
#include <drv_eflash.h>
#include <drv_spiflash.h>
#include <drv_spi.h>
#include <drv_gpio.h>
//#include <drv_efusec.h>

#include "pin_name.h"
#include "pinmux.h"
#include "usi_pin_planning.h"

#define readl(addr) \
    ({ unsigned int __v = (*(volatile unsigned int *) (addr)); __v; })

#define writel(b,addr) (void)((*(volatile unsigned int *) (addr)) = (b))

extern void USI2_IRQHandler(void);
extern void USI3_IRQHandler(void);
extern void TIM4_IRQHandler(void);
extern void TIM5_IRQHandler(void);
extern void TIM6_IRQHandler(void);
extern void TIM7_IRQHandler(void);
extern void PWM1_IRQHandler(void);
extern void GPIO1_IRQHandler(void);
extern void DMAC1_IRQHandler(void);
extern void MAILBOX_IRQHandler(void);
extern void USART2_IRQHandler(void);
extern void USART3_IRQHandler(void);

struct {
    uint32_t base;
    uint32_t irq;
    void *handler;
}
const static sg_usart_config[CONFIG_USART_NUM] = {
    {CSKY_UART2_BASE, UART2_IRQn, USART2_IRQHandler},
    {CSKY_UART3_BASE, UART3_IRQn, USART3_IRQHandler}
};

int32_t target_usart_init(int32_t idx, uint32_t *base, uint32_t *irq, void **handler)
{
    if (idx >= CONFIG_USART_NUM) {
        return -1;
    }

    if (base != NULL) {
        *base = sg_usart_config[idx].base;
    }

    if (irq != NULL) {
        *irq = sg_usart_config[idx].irq;
    }

    if (handler != NULL) {
        *handler = sg_usart_config[idx].handler;
    }

    return idx;
}


struct {
    uint32_t base;
    uint32_t irq;
    void *handler;
}
const sg_usi_config[CONFIG_USI_NUM] = {
    {CSKY_USI2_BASE, USI2_IRQn, USI2_IRQHandler},
    {CSKY_USI3_BASE, USI3_IRQn, USI3_IRQHandler},
};

int32_t target_usi_init(int32_t idx, uint32_t *base, uint32_t *irq)
{
    if (idx >= CONFIG_USI_NUM || idx < 0) {
        return -1;
    }

    *base = sg_usi_config[idx].base;
    *irq = sg_usi_config[idx].irq;

    return idx;
}

int32_t target_usi_usart_init(int32_t idx, uint32_t *base, uint32_t *irq, void **handler)
{
    if (idx >= CONFIG_USI_NUM || idx < 0) {
        return -1;
    }

    if (base != NULL) {
        *base = sg_usi_config[idx].base;
    }

    if (irq != NULL) {
        *irq = sg_usi_config[idx].irq;
    }

    if (handler != NULL) {
        *handler = sg_usi_config[idx].handler;
    }

    return idx;
}

int32_t target_usi_spi_init(int32_t idx, uint32_t *base, uint32_t *irq, void **handler, uint32_t *ssel)
{
    if (idx >= CONFIG_USI_SPI_NUM || idx < 0) {
        return -1;
    }

    if (base != NULL) {
        *base = sg_usi_config[idx].base;
    }

    if (irq != NULL) {
        *irq  = sg_usi_config[idx].irq;
    }

    if (handler != NULL) {
        *handler = sg_usi_config[idx].handler;
    }

    return idx;
}

int32_t target_usi_iic_init(int32_t idx, uint32_t *base, uint32_t *irq, void **handler)
{
    if (idx >= CONFIG_USI_NUM || idx < 0) {
        return -1;
    }

    if (base != NULL) {
        *base = sg_usi_config[idx].base;
    }

    if (irq != NULL) {
        *irq = sg_usi_config[idx].irq;
    }

    if (handler != NULL) {
        *handler = sg_usi_config[idx].handler;
    }

    return idx;
}

struct {
    uint32_t base;
    uint32_t irq;
    void *handler;
}
const sg_timer_config[CONFIG_TIMER_NUM] = {
    {CSKY_TIM2_BASE, TIMER2_INT0_IRQn, TIM4_IRQHandler},
    {CSKY_TIM2_BASE + 0x14, TIMER2_INT1_IRQn, TIM5_IRQHandler},
    {CSKY_TIM3_BASE, TIMER3_INT0_IRQn, TIM6_IRQHandler},
    {CSKY_TIM3_BASE + 0x14, TIMER3_INT1_IRQn, TIM7_IRQHandler},
};

int32_t target_get_timer_count(void)
{
    return CONFIG_TIMER_NUM;
}

int32_t target_get_timer(int32_t idx, uint32_t *base, uint32_t *irq, void **handler)
{
    if (idx >= target_get_timer_count()) {
        return -1;
    }

    if (base != NULL) {
        *base = sg_timer_config[idx].base;
    }

    if (irq != NULL) {
        *irq = sg_timer_config[idx].irq;
    }

    if (irq != NULL) {
        *handler = sg_timer_config[idx].handler;
    }

    return idx;
}

struct {
    uint32_t base;
    uint32_t irq;
    void *handler;
}
const sg_pwm_config[CONFIG_PWM_NUM] = {
    {CSKY_PWM1_BASE, PWM1_IRQn, PWM1_IRQHandler},
};

int32_t target_get_pwm_count(void)
{
    return CONFIG_PWM_NUM;
}

int32_t target_pwm_init(uint32_t idx, uint32_t *base, uint32_t *irq, void **handler)
{
    if (idx >= target_get_pwm_count()) {
        return -1;
    }

    if (base != NULL) {
        *base = sg_pwm_config[idx].base;
    }

    if (irq != NULL) {
        *irq = sg_pwm_config[idx].irq;
    }

    if (handler != NULL) {
        *handler = sg_pwm_config[idx].handler;
    }

    return idx;
}

struct {
    uint32_t base;
    uint32_t irq;
    uint32_t pin_num;
    port_name_e port;
}
const sg_gpio_config[CONFIG_GPIO_NUM] = {
    {CSKY_GPIO1_BASE, GPIO1_IRQn, 32, PORTB},
};

typedef struct {
    int32_t    gpio_pin;
    uint32_t cfg_idx;
} gpio_pin_map_t;
const static gpio_pin_map_t s_gpio_pin_map[] = {
    {PB10, 1},
    {PB11, 1},
    {PB12, 1},
    {PB13, 1},
    {PB14, 1},
    {PB15, 1},
    {PB16, 1},
    {PB17, 1},
    {PB18, 1},
    {PB19, 1},
    {PB20, 1},
    {PB21, 1},
    {PB22, 1},
    {PB23, 1},
    {PB24, 1},
    {PB25, 1},
    {PB26, 1},
    {PB27, 1},
    {PB28, 1},
    {PB29, 1},
    {PB30, 1},
    {PB31, 1},
};

int32_t target_gpio_port_init(port_name_e port, uint32_t *base, uint32_t *irq, void **handler, uint32_t *pin_num)
{
    int i;

    for (i = 0; i < CONFIG_GPIO_NUM; i++) {
        if (sg_gpio_config[i].port == port) {
            if (base != NULL) {
                *base = sg_gpio_config[i].base;
            }

            if (irq != NULL) {
                *irq = sg_gpio_config[i].irq;
            }

            if (pin_num != NULL) {
                *pin_num = sg_gpio_config[i].pin_num;
            }

            if (handler != NULL) {
                if (port == PORTB) {
                    *handler = (void *)GPIO1_IRQHandler;
                } else {
                }
            }

            return i;
        }
    }

    return -1;
}

int32_t target_gpio_pin_init(int32_t gpio_pin, uint32_t *port_idx)
{
    uint32_t idx;

    for (idx = 0; idx < sizeof(s_gpio_pin_map) / sizeof(gpio_pin_map_t); idx++) {
        if (s_gpio_pin_map[idx].gpio_pin == gpio_pin) {
            *port_idx = s_gpio_pin_map[idx].cfg_idx;
            if (idx >= 32) {
                return idx - 32;
            } else {
                return idx;
            }
        }
    }

    return -1;
}

struct {
    uint32_t base;
    uint32_t irq;
    void *handler;
}
const sg_dmac_config[CONFIG_DMA_CHANNEL_NUM] = {
    {CSKY_DMAC1_BASE, DMAC1_IRQn, DMAC1_IRQHandler},
    {CSKY_DMAC1_BASE, DMAC1_IRQn, DMAC1_IRQHandler},
};

int32_t target_get_dma_channel_count(void)
{
    return CONFIG_DMA_CHANNEL_NUM;
}

int32_t target_get_dmac(int32_t idx, uint32_t *base, uint32_t *irq, void **handler)
{
    if (idx >= target_get_dma_channel_count()) {
        return -1;
    }

    if (base != NULL) {
        *base = sg_dmac_config[idx].base;
    }

    if (irq != NULL) {
        *irq = sg_dmac_config[idx].irq;
    }

    if (handler != NULL) {
        *handler = sg_dmac_config[idx].handler;
    }

    return idx;
}

struct {
    uint32_t base;
    uint32_t irq;
    void *handler;
}
const sg_mailbox_config[CONFIG_MAILBOX_NUM] = {
    {CSKY_MCC0_BASE, NULL, NULL},
    {CSKY_MCC0_BASE, NULL, NULL},
    {CSKY_MCC1_BASE, WCOM_IRQn, MAILBOX_IRQHandler},
};

int32_t target_mailbox_init(int32_t idx, uint32_t *base, uint32_t *irq, void **handler)
{
    if (idx >= CONFIG_MAILBOX_NUM) {
        return -1;
    }

    if (base != NULL) {
        *base = sg_mailbox_config[idx].base;
    }

    if (irq != NULL) {
        *irq = sg_mailbox_config[idx].irq;
    }

    if (handler != NULL) {
        *handler = sg_mailbox_config[idx].handler;
    }

    return idx;
}

struct {
    spiflash_info_t info;
}
const sg_spiflash_config[CONFIG_SPIFLASH_NUM] = {
    {{CSKY_QSPIMEM_BASE, CSKY_QSPIMEM_BASE + 0x7fffff, 0x800}}
};

int32_t target_get_spiflash(int32_t idx, spiflash_info_t *info)
{
    if (info != NULL) {
        info->start = sg_spiflash_config[idx].info.start;
        info->end = sg_spiflash_config[idx].info.end;
        info->sector_count = sg_spiflash_config[idx].info.sector_count;
    }

    return idx;
}

struct {
    uint32_t base;
    uint32_t irq;
}
const sg_qspi_config[CONFIG_QSPI_NUM] = {
    {CSKY_QSPIC0_BASE, QSPI_IRQn}
};

int32_t target_qspi_init(int32_t idx, uint32_t *base, uint32_t *irq)
{
    if (idx >= CONFIG_QSPI_NUM) {
        return -1;
    }

    if (base != NULL) {
        *base = sg_qspi_config[idx].base;
    }

    if (irq != NULL) {
        *irq = sg_qspi_config[idx].irq;
    }

    return idx;
}

