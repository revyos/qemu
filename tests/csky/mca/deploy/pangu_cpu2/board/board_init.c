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
 * @file     board_init.c
 * @brief    CSI Source File for board init
 * @version  V1.0
 * @date     01. Feb 2019
 ******************************************************************************/
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <drv_usart.h>
#include <soc.h>
#include <csi_config.h>
#include <csi_core.h>
#include <pin.h>
#include <ck_usi.h>
#include <dw_dmac.h>
#include <ck_i2s_v2.h>


#define readl(addr) \
    ({ unsigned int __v = (*(volatile unsigned int *) (addr)); __v; })

    #define writel(b,addr) (void)((*(volatile unsigned int *) (addr)) = (b))
extern void yunvoice_initial(void);

void delay (volatile uint32_t n) {
    while(n>0) {n--;}
}

void board_init(void)
{
    yunvoice_initial();

    extern usart_handle_t console_handle;
    drv_pinmux_config(CONSOLE_TXD, CONSOLE_TXD_FUNC);
    drv_pinmux_config(CONSOLE_RXD, CONSOLE_RXD_FUNC);
    writel(0, 0x8B000004); /* not divide */
    /* init the console*/
    console_handle = csi_usart_initialize(CONSOLE_IDX, NULL);
    /* config the UART */
    csi_usart_config(console_handle, 115200, USART_MODE_ASYNCHRONOUS, USART_PARITY_NONE, USART_STOP_BITS_1, USART_DATA_BITS_8);
}
