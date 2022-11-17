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
#ifndef _SYS_TIPC_H_
#define _SYS_TIPC_H_

#include <soc.h>
#include <ck_tipc.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    AHB0_FMC_TRUST = 0,
    AHB0_SDMMC_TRUST,
    AHB0_SDIO_TRUST,
    AHB0_DMAC_TRUST,
    AHB1_FMC_TRUST,
    AHB1_DMAC_TRUST,
    AHB0_USB2_TRUST,
    APB0_WDT_TRUST,
    APB0_RTC_TRUST,
    APB0_TIM0_TRUST,
    APB0_TIM1_TRUST,
    APB0_TIM2_TRUST,
    APB0_QSPI0_TRUST,
    APB0_PADREG_TRUST,
    APB0_GPIO0_TRUST,
    APB0_PWM_TRUST,
    APB0_USI0_TRUST,
    APB0_USI1_TRUST,
    APB0_USI2_TRUST,
    APB0_USI3_TRUST,
    APB0_USI4_TRUST,
    APB0_USI5_TRUST,
    APB2_SPDIF0_TRUST,
    APB2_SPDIF1_TRUST,
    APB2_I2S0_TRUST,
    APB2_I2S1_TRUST,
    APB2_I2S2_TRUST,
    APB2_I2S3_TRUST,
    APB2_TDM_TRUST,
    APB2_PDM_TRUST,
    APB2_TIM0_TRUST,
    APB2_TIM1_TRUST,
    APB2_USI0_TRUST,
    APB2_USI1_TRUST
} ckenum_tipc_module_e;
ck_tipc_info_t ck_tipc_info[] =
{
    //{AHB0_FMC_TRUST,    0x0, 0x00, 0x0, CSKY_CPU0_FMC_BASE},
    {AHB0_SDMMC_TRUST,  0x0, 0x01, 0x0, CSKY_SDIO1_BASE + 0x4},
    {AHB0_SDIO_TRUST,   0x0, 0x02, 0x0, CSKY_SDIO0_BASE + 0x4},
    {AHB0_DMAC_TRUST,   0x0, 0x03, 0x0, CSKY_DMAC0_BASE},
   // {AHB1_FMC_TRUST,    0x0, 0x04, 0x0, CSKY_CPU1_FMC_BASE},
    {AHB1_DMAC_TRUST,   0x0, 0x05, 0x0, CSKY_DMAC1_BASE},
   // {AHB0_USB2_TRUST,   0x0, 0x06, 0x0, CSKY_USB_BASE},
    //{APB0_WDT_TRUST,    0x4, 0x00, 0x0, CSKY_WDT_BASE + 0x4},
    //{APB0_RTC_TRUST,    0x4, 0x01, 0x0, CSKY_RTC_BASE + 0x4},
    //{APB0_TIM0_TRUST,   0x4, 0x02, 0x0, CSKY_TIM0_BASE},
    //{APB0_TIM1_TRUST,   0x4, 0x03, 0x0, CSKY_TIM1_BASE},
    //{APB0_TIM2_TRUST,   0x4, 0x04, 0x0, CSKY_TIM2_BASE},
    //{APB0_QSPI0_TRUST,  0x4, 0x05, 0x0, CSKY_QSPIC0_BASE + 0x94},
    //{APB0_PADREG_TRUST, 0x4, 0x06, 0x0, CSKY_PADREG_BASE + 0xc},
    //{APB0_GPIO0_TRUST,  0x4, 0x07, 0x0, CSKY_GPIO0_BASE + 0x30},
    //{APB0_PWM_TRUST,    0x4, 0x08, 0x0, CSKY_CPU0_PWM_BASE},
    //{APB0_USI0_TRUST,   0x4, 0x09, 0x0, CSKY_USI0_BASE + 0x4},
    //{APB0_USI1_TRUST,   0x4, 0x0a, 0x0, CSKY_USI1_BASE + 0x4},
    //{APB0_USI2_TRUST,   0x4, 0x0b, 0x0, CSKY_USI2_BASE + 0x4},
    //{APB0_USI3_TRUST,   0x4, 0x0c, 0x0, CSKY_CPU0_USI3_BASE + 0x4},
    //{APB0_USI4_TRUST,   0x4, 0x0d, 0x0, CSKY_CPU0_USI4_BASE + 0x4},
    //{APB2_SPDIF0_TRUST, 0x8, 0x00, 0x0, CSKY_CPU1_SPDIF0_BASE},
    //{APB2_SPDIF1_TRUST, 0x8, 0x01, 0x0, CSKY_CPU1_SPDIF1_BASE},
    //{APB2_TDM_TRUST,    0x8, 0x06, 0x0, CSKY_CPU1_TDM_BASE},
    //{APB2_PDM_TRUST,    0x8, 0x07, 0x0, CSKY_CPU1_PDM_BASE},
    //{APB2_TIM0_TRUST,   0x8, 0x08, 0x0, CSKY_CPU1_TIM0_BASE},
    //{APB2_TIM1_TRUST,   0x8, 0x09, 0x0, CSKY_CPU1_TIM1_BASE},
    //{APB2_USI0_TRUST,   0x8, 0x0a, 0x0, CSKY_CPU1_USI0_BASE + 0x04},
    //{APB2_USI1_TRUST,   0x8, 0x0b, 0x0, CSKY_CPU1_USI1_BASE + 0x04},
};

#define TIPC_MODULE_NUM  (sizeof(ck_tipc_info) / sizeof(ck_tipc_info_t))
#ifdef __cplusplus
}
#endif

#endif

