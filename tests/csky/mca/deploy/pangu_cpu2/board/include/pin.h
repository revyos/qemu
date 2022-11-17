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
 * @file     pin.h
 * @brief    header File for pin definition
 * @version  V1.0
 * @date     02. June 2018
 ******************************************************************************/
#ifndef _PIN_H_
#define _PIN_H_

#include <stdint.h>
#include "pin_name.h"
#include "pinmux.h"

#ifdef __cplusplus
extern "C" {
#endif

//#define CONSOLE_TXD         PB5
//#define CONSOLE_RXD         PB4
//#define CONSOLE_TXD_FUNC    PB5_CPU1_USI1_SD0
//#define CONSOLE_RXD_FUNC    PB4_CPU1_USI1_SCLK
//#define CONSOLE_IDX         6

#define CONSOLE_TXD         PB24
#define CONSOLE_RXD         PB25
#define CONSOLE_TXD_FUNC    PB24_UART2_TX
#define CONSOLE_RXD_FUNC    PB25_UART2_RX
#define CONSOLE_IDX         0

#define EXAMPLE_DEST_MAILBOX_IDX             0
#define EXAMPLE_QSPI_IDX                0
/* example pin manager */
#define EXAMPLE_USART_IDX                   2
#define EXAMPLE_PIN_USART_TX                PB24
#define EXAMPLE_PIN_USART_RX                PB25
#define EXAMPLE_PIN_USART_TX_FUNC           PB24_UART2_TX
#define EXAMPLE_PIN_USART_RX_FUNC           PB25_UART2_RX

#define EXAMPLE_USI_USART_IDX               6
#define EXAMPLE_PIN_USI_USART_TX            PB5
#define EXAMPLE_PIN_USI_USART_RX            PB4
#define EXAMPLE_PIN_USI_USART_TX_FUNC       PB5_CPU1_USI1_SD0
#define EXAMPLE_PIN_USI_USART_RX_FUNC       PB4_CPU1_USI1_SCLK

#define EXAMPLE_USI_SPI_IDX             6
#define EXAMPLE_PIN_USI_SPI_MISO        PB14
#define EXAMPLE_PIN_USI_SPI_MOSI        PB5
#define EXAMPLE_PIN_USI_SPI_CS          PB15
#define EXAMPLE_PIN_USI_SPI_SCK         PB4
#define EXAMPLE_PIN_USI_SPI_MISO_FUNC   PB14_CPU1_USI1_SD1
#define EXAMPLE_PIN_USI_SPI_MOSI_FUNC   PB5_CPU1_USI1_SD0
#define EXAMPLE_PIN_USI_SPI_CS_FUNC     PIN_FUNC_GPIO
#define EXAMPLE_PIN_USI_SPI_SCK_FUNC    PB4_CPU1_USI1_SCLK

#define EXAMPLE_SPI_IDX             6
#define EXAMPLE_PIN_SPI_MISO        PB14
#define EXAMPLE_PIN_SPI_MOSI        PB5
#define EXAMPLE_PIN_SPI_CS          PB15
#define EXAMPLE_PIN_SPI_SCK         PB4
#define EXAMPLE_PIN_SPI_MISO_FUNC   PB14_CPU1_USI1_SD1
#define EXAMPLE_PIN_SPI_MOSI_FUNC   PB5_CPU1_USI1_SD0
#define EXAMPLE_PIN_SPI_CS_FUNC     PIN_FUNC_GPIO
#define EXAMPLE_PIN_SPI_SCK_FUNC    PB4_CPU1_USI1_SCLK

#define EXAMPLE_USI_IIC_IDX             6
#define EXAMPLE_PIN_USI_IIC_SDA         PB5
#define EXAMPLE_PIN_USI_IIC_SCL         PB4
#define EXAMPLE_PIN_USI_IIC_SDA_FUNC    PB5_CPU1_USI1_SD0
#define EXAMPLE_PIN_USI_IIC_SCL_FUNC    PB4_CPU1_USI1_SCLK

#define EXAMPLE_IIC_IDX                 6
#define EXAMPLE_PIN_IIC_SDA             PB5
#define EXAMPLE_PIN_IIC_SCL             PB4
#define EXAMPLE_PIN_IIC_SDA_FUNC        PB5_CPU1_USI1_SD0
#define EXAMPLE_PIN_IIC_SCL_FUNC        PB4_CPU1_USI1_SCLK

#define EXAMPLE_GPIO_PIN            PB17
#define EXAMPLE_BOARD_GPIO_PIN_NAME "J23.5"
#define EXAMPLE_GPIO_PIN_FUNC       PIN_FUNC_GPIO

#define EXAMPLE_PWM_IDX         1
#define EXAMPLE_PWM_CH_IDX      0
#define EXAMPLE_PWM_CH          PB14
#define EXAMPLE_PWM_CH_FUNC     PB14_PWM1_IO0

/* tests pin manager */
#define TEST_USART_IDX               5
#define TEST_PIN_USART_TX            PB1
#define TEST_PIN_USART_RX            PB0
#define TEST_PIN_USART_TX_FUNC       PB1_CPU1_USI0_SD0
#define TEST_PIN_USART_RX_FUNC       PB0_CPU1_USI0_SCLK

#define TEST_USI_USART_IDX           5
#define TEST_PIN_USI_USART_TX        PB1
#define TEST_PIN_USI_USART_RX        PB0
#define TEST_PIN_USI_USART_TX_FUNC   PB1_CPU1_USI0_SD0
#define TEST_PIN_USI_USART_RX_FUNC   PB0_CPU1_USI0_SCLK

#define TEST_USI_SPI_IDX             5
#define TEST_PIN_USI_SPI_MISO        PB2
#define TEST_PIN_USI_SPI_MOSI        PB1
#define TEST_PIN_USI_SPI_CS          PB3
#define TEST_PIN_USI_SPI_SCK         PB0
#define TEST_PIN_USI_SPI_MISO_FUNC   PB2_CPU1_USI0_SD1
#define TEST_PIN_USI_SPI_MOSI_FUNC   PB1_CPU1_USI0_SD0
#define TEST_PIN_USI_SPI_CS_FUNC     PIN_FUNC_GPIO
#define TEST_PIN_USI_SPI_SCK_FUNC    PB0_CPU1_USI0_SCLK

#define TEST_SPI_IDX                5
#define TEST_PIN_SPI_MOSI           PB2
#define TEST_PIN_SPI_MISO           PB1
#define TEST_PIN_SPI_CS             PB3
#define TEST_PIN_SPI_SCK            PB0
#define TEST_PIN_SPI_MOSI_FUNC      PB2_CPU1_USI0_SD1
#define TEST_PIN_SPI_MISO_FUNC      PB1_CPU1_USI0_SD0
#define TEST_PIN_SPI_CS_FUNC        PIN_FUNC_GPIO
#define TEST_PIN_SPI_SCK_FUNC       PB0_CPU1_USI0_SCLK

#define TEST_IIC_IDX                6
#define TEST_PIN_IIC_SDA            PB5
#define TEST_PIN_IIC_SCL            PB4
#define TEST_PIN_IIC_SDA_FUNC       PB5_CPU1_USI1_SD0
#define TEST_PIN_IIC_SCL_FUNC       PB4_CPU1_USI1_SCLK

#define TEST_USI_IIC_IDX             6
#define TEST_PIN_USI_IIC_SDA         PB5
#define TEST_PIN_USI_IIC_SCL         PB4
#define TEST_PIN_USI_IIC_SDA_FUNC    PB5_CPU1_USI1_SD0
#define TEST_PIN_USI_IIC_SCL_FUNC    PB4_CPU1_USI1_SCLK

#define EXAMPLE_SOUND_IIC_SDA       PA5
#define EXAMPLE_SOUND_IIC_SCL       PA4
#define EXAMPLE_SOUND_IIC_SDA_FUN   PA5_USI1_SD0
#define EXAMPLE_SOUND_IIC_SCL_FUN   PA4_USI1_SCLK

#define EXAMPLE_I2S_IDX         0
#define EXAMPLE_I2S_MCLK        PA12
#define EXAMPLE_I2S_SCLK        PA12
#define EXAMPLE_I2S_WSCLK       PA13
#define EXAMPLE_I2S_SDA         PA14
#define EXAMPLE_I2S_MCLK_FUNC   PA12_I2S0_SCLK
#define EXAMPLE_I2S_SCLK_FUNC   PA12_I2S0_SCLK
#define EXAMPLE_I2S_WSCLK_FUNC  PA13_I2S0_WSCLK
#define EXAMPLE_I2S_SDA_FUNC    PA14_I2S0_SDA

#define TEST_GPIO_PIN               PB16
#define TEST_BOARD_GPIO_PIN_NAME    "J23.4"
#define TEST_GPIO_PIN_FUNC          PIN_FUNC_GPIO

#define TEST_PWM_IDX        1
#define TEST_PWM_CH         0
#define TEST_PWM_CH0        PB14
#define TEST_PWM_CH0_FUNC   PB14_PWM1_IO0
#define TEST_PWM_CH1        PB15
#define TEST_PWM_CH1_FUNC   PB15_PWM1_O1
#define TEST_PWM_CH2        PB16
#define TEST_PWM_CH2_FUNC   PB16_PWM1_IO2
#define TEST_PWM_CH3        PB17
#define TEST_PWM_CH3_FUNC   PB17_PWM1_O3
#define TEST_PWM_CH4        PB18
#define TEST_PWM_CH4_FUNC   PB18_PWM1_IO4
#define TEST_PWM_CH5        PB19
#define TEST_PWM_CH5_FUNC   PB19_PWM1_O5


#define SPEECH_I2S_SCLK        PB0
#define SPEECH_I2S_SCLK_FUNC   PB0_I2S2_SCLK
#define SPEECH_I2S_WSCLK       PB1
#define SPEECH_I2S_WSCLK_FUNC  PB1_I2S2_WSCLK
#define SPEECH_I2S_SDA         PB2
#define SPEECH_I2S_SDA_FUNC    PB2_I2S2_SDA

#define SPEECH_I2C_SCLK      PB28
#define SPEECH_I2C_SCLK_FUNC PB28_USI2_SCLK
#define SPEECH_I2C_SDA       PB29
#define SPEECH_I2C_SDA_FUNC  PB29_USI2_SD0


#ifdef __cplusplus
}
#endif

#endif /* _PIN_H_ */

