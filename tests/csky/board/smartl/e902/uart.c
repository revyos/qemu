/* ---------------------------------------------------------------------------
 * Copyright (C) 2016 CSKY Limited. All rights reserved.
 *
 * Redistribution and use of this software in source and binary forms,
 * with or without modification, are permitted provided that the following
 * conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *   * Neither the name of CSKY Ltd. nor the names of CSKY's contributors may
 *     be used to endorse or promote products derived from this software without
 *     specific prior written permission of CSKY Ltd.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 * -------------------------------------------------------------------------- */
/*
 * Filename: uart.c
 * Description: this file contains the functions support uart operations
 * Copyright (C): Hangzhou C-Sky Microsystem Co, Ltd.
 * Author(s): Shuli Wu (shuli_wu@c-sky.com), YUN YE (yun_ye@c-sky.com).
 * Contributors:
 * Date: Otc 10, 2008
 */

#include <stdio.h>
#include <stdarg.h>
#include "uart.h"

/* the table of the uart serial ports */
static CKStruct_UartInfo CK_Uart_Table[] = {
    {0, SMARTL_UART0, UART0_IRQn, FALSE, NULL},
};

/*
 * Make all the uarts in the idle state;
 * this function should be called before
 * INTC module working;
 */
void CK_Deactive_UartModule()
{
    int i;
    SMARTL_UART_TypeDef *uart;

    uart = CK_Uart_Table[0].addr;
    uart->LCR = 0x83;
    uart->DLL = 0x1;
    uart->DLH = 0x0;

}

/*
 * initialize the uart:
 * baudrate: 19200
 * date length: 8 bits
 * paity: None(disabled)
 * number of stop bits: 1 stop bit
 * query mode
 * return: SUCCESS
 */
CK_INT32 CK_Uart_Init(CK_Uart_Device uartid)
{
    CK_Uart_ChangeBaudrate(uartid, B19200);
    CK_Uart_SetParity(uartid, NONE);
    CK_Uart_SetWordSize(uartid, LCR_WORD_SIZE_8);
    CK_Uart_SetStopBit(uartid, LCR_STOP_BIT_1);
    CK_Uart_SetRXMode(uartid, TRUE);
    CK_Uart_SetTXMode(uartid, TRUE);
    return SUCCESS;
}

/* open the uart :
 * set the callback function --- handler(void);
 * intilize the serial port,sending and receiving buffer;
 * intilize irqhandler ;
 * register irqhandler
 * return: SUCCESS or FAILURE
 */
CK_INT32 CK_Uart_Open(CK_Uart_Device uartid, void (*handler) (CK_INT8 error))
{
    CKStruct_UartInfo *info;
    info = &(CK_Uart_Table[uartid]);

    if (info->bopened) {
        return FAILURE;
    }
    CK_Uart_Init(uartid);

    info->handler = handler;
    info->bopened = TRUE;
    return SUCCESS;
}

/* This function is used to close the uart
 * clear the callback function
 * free the irq
 * return: SUCCESS or FAILURE
 */
CK_INT32 CK_Uart_Close(CK_Uart_Device uartid)
{
    CKStruct_UartInfo *info;
    SMARTL_UART_TypeDef *uart;

    info = &(CK_Uart_Table[uartid]);
    uart = info->addr;
    if (info->bopened) {
        /* Stop UART interrupt. */
        uart->IER &= ~IER_RDA_INT_ENABLE;
        info->handler = NULL;
        info->bopened = 0;
        return SUCCESS;
    }
    return FAILURE;
}

/*
 * This function is used to change the bautrate of uart.
 * Parameters:
 * uartid--a basepointer, could be one of UART0, UART1, UART2 or UART3.
 * baudrate--the baudrate that user typed in.
 * return: SUCCESS or FAILURE
 */

CK_INT32 CK_Uart_ChangeBaudrate(CK_Uart_Device uartid,
                                CK_Uart_Baudrate baudrate)
{
    CK_INT32 divisor;
    CK_INT32 timecount;
    CKStruct_UartInfo *info;
    SMARTL_UART_TypeDef *uart;

    timecount = 0;
    info = &(CK_Uart_Table[uartid]);
    uart = info->addr;

    /*
     * DLH and DLL may be accessed when the UART is not
     * busy(USR[0]=0) and the DLAB bit(LCR[7]) is set.
     */
    while ((uart->USR & USR_UART_BUSY)
           && (timecount < UART_BUSY_TIMEOUT)) {
        timecount++;
    }
    if (timecount >= UART_BUSY_TIMEOUT) {
        return FAILURE;
    } else {
        /*baudrate=(seriak clock freq)/(16*divisor). */
        divisor = ((APB_DEFAULT_FREQ / baudrate) >> 4);
        uart->LCR |= LCR_SET_DLAB;
        /* DLL and DLH is lower 8-bits and higher 8-bits of divisor. */
        uart->DLL = divisor & 0xff;
        uart->DLH = (divisor >> 8) & 0xff;
        /*
         * The DLAB must be cleared after the baudrate is setted
         * to access other registers.
         */
        uart->LCR &= (~LCR_SET_DLAB);
        info->baudrate = baudrate;
        return SUCCESS;
    }
    return FAILURE;
}

/*
 * This function is used to enable or disable parity, also to set ODD or EVEN
 * parity.
 * Parameters:
 *   uartid--a basepointer, could be one of UART0, UART1, UART2 or UART3.
 *   parity--ODD=8, EVEN=16, or NONE=0.
 * return: SUCCESS or FAILURE
 */

CK_INT32 CK_Uart_SetParity(CK_Uart_Device uartid, CK_Uart_Parity parity)
{
    CKStruct_UartInfo *info;
    SMARTL_UART_TypeDef *uart;

    info = &(CK_Uart_Table[uartid]);
    uart = info->addr;
    CK_INT32 timecount;
    timecount = 0;
    /* PEN bit(LCR[3]) is writeable when the UART is not busy(USR[0]=0). */
    while ((uart->USR & USR_UART_BUSY) &&
           (timecount < UART_BUSY_TIMEOUT)) {
        timecount++;
    }
    if (timecount >= UART_BUSY_TIMEOUT) {
        return FAILURE;
    } else {
        /*CLear the PEN bit(LCR[3]) to disable parity. */
        uart->LCR &= (~LCR_PARITY_ENABLE);

        info->parity = parity;
        return SUCCESS;
    }
}

/*
 * We can call this function to set the stop bit--1 bit, 1.5 bits, or 2 bits.
 * But that it's 1.5 bits or 2, is decided by the wordlenth. When it's 5 bits,
 * there are 1.5 stop bits, else 2.
 * Parameters:
 *  uartid--a basepointer, could be one of UART0, UART1, UART2 or UART3.
 *  stopbit--it has two possible value: STOP_BIT_1 and STOP_BIT_2.
 * return: SUCCESS or FAILURE
 */

CK_INT32 CK_Uart_SetStopBit(CK_Uart_Device uartid, CK_Uart_StopBit stopbit)
{
    CKStruct_UartInfo *info;
    SMARTL_UART_TypeDef *uart;

    info = &(CK_Uart_Table[uartid]);
    uart = info->addr;
    CK_INT32 timecount;
    timecount = 0;
    /* PEN bit(LCR[3]) is writeable when the UART is not busy(USR[0]=0). */
    while ((uart->USR & USR_UART_BUSY) &&
           (timecount < UART_BUSY_TIMEOUT)) {
        timecount++;
    }
    if (timecount >= UART_BUSY_TIMEOUT) {
        return FAILURE;
    } else {
        /* Clear the STOP bit to set 1 stop bit */
        uart->LCR &= LCR_STOP_BIT1;
    }
    info->stop = stopbit;
    return SUCCESS;
}

/*
 * We can use this function to reset the transmit data length,and we
 * have four choices:5, 6, 7, and 8 bits.
 * Parameters:
 *  uartid--a basepointer, could be one of UART0, UART1, UART2 or UART3.
 *  wordsize--the data length that user decides
 * return: SUCCESS or FAILURE
 */

CK_INT32 CK_Uart_SetWordSize(CK_Uart_Device uartid, CK_Uart_WordSize wordsize)
{
    CKStruct_UartInfo *info;
    SMARTL_UART_TypeDef *uart;
    int timecount = 0;

    info = &(CK_Uart_Table[uartid]);
    uart = info->addr;
    /* DLS(LCR[1:0]) is writeable when the UART is not busy(USR[0]=0). */
    while ((uart->USR & USR_UART_BUSY) &&
           (timecount < UART_BUSY_TIMEOUT)) {
        timecount++;
    }
    if (timecount >= UART_BUSY_TIMEOUT) {
        return FAILURE;
    } else {
        uart->LCR |= LCR_WORD_SIZE_8;
    }
    info->word = wordsize;
    return SUCCESS;
}

/*
 * This function is used to set the transmit mode, interrupt mode or
 * query mode.
 * Parameters:
 *  uartid--a basepointer, could be one of UART0, UART1, UART2 or UART3.
 *  bQuery--it indicates the transmit mode: TRUE - query mode, FALSE -
 *  inerrupt mode
 * return: SUCCESS or FAILURE
 */

CK_INT32 CK_Uart_SetTXMode(CK_Uart_Device uartid, BOOL bQuery)
{
    CKStruct_UartInfo *info;
    SMARTL_UART_TypeDef *uart;

    info = &(CK_Uart_Table[uartid]);
    uart = info->addr;
    CK_INT32 timecount;
    timecount = 0;
    while ((uart->USR & USR_UART_BUSY) &&
           (timecount < UART_BUSY_TIMEOUT)) {
        timecount++;
    }
    if (timecount >= UART_BUSY_TIMEOUT) {
        return FAILURE;
    } else {
        if (bQuery) {
            /* When query mode, disable the Transmit Holding Register Empty
             * Interrupt. To do this, we clear the ETBEI bit(IER[1]).
             */
            uart->IER &= (~IER_THRE_INT_ENABLE);
            /* Refresh the uart info: transmit mode - query. */
            info->btxquery = TRUE;
        } else {
            /* When interrupt mode, inable the Transmit Holding Register
             * Empty Interrupt. To do this, we set the ETBEI bit(IER[1]).
             */
            uart->IER |= IER_THRE_INT_ENABLE;
            /* Refresh the uart info: transmit mode - interrupt. */
            info->btxquery = FALSE;
        }
    }
    return SUCCESS;
}

/*
 * This function is used to set the receive mode, interrupt mode or
 * query mode.
 * Parameters:
 *  uartid--a basepointer, could be one of UART0, UART1, UART2 or UART3.
 *  bQuery--it indicates the receive mode: TRUE - query mode, FALSE -
 *  interrupt mode
 * return: SUCCESS or FAILURE

 */
CK_INT32 CK_Uart_SetRXMode(CK_Uart_Device uartid, BOOL bQuery)
{
    CKStruct_UartInfo *info;
    SMARTL_UART_TypeDef *uart;

    info = &(CK_Uart_Table[uartid]);
    uart = info->addr;
    CK_INT32 timecount;
    timecount = 0;
    /* PEN bit(LCR[3]) is writeable when the UART is not busy(USR[0]=0). */
    while ((uart->USR & USR_UART_BUSY) &&
           (timecount < UART_BUSY_TIMEOUT)) {
        timecount++;
    }
    if (timecount >= UART_BUSY_TIMEOUT) {
        return FAILURE;
    } else {
        if (bQuery) {
            /* When query mode, disable the Received Data Available
             * Interrupt. To do this, we clear the ERBFI bit(IER[0]).
             */
            uart->IER &= (~IER_RDA_INT_ENABLE);
            /* Refresh the uart info: receive mode - query. */
            info->brxquery = TRUE;
        } else {
            /* When interrupt mode, inable the Received Data Available
             * Interrupt. To do this, we set the ERBFI bit(IER[0]).
             */
            uart->IER |= IER_RDA_INT_ENABLE;
            /* Refresh the uart info: receive mode - interrupt. */
            info->brxquery = FALSE;
        }
    }
    return SUCCESS;
}

/*
 * Register uart into powermanager.
 */
CK_INT32 CK_Uart_DriverInit()
{
    CK_Deactive_UartModule();
    return SUCCESS;
}

/* This function is used to get character,in query mode or interrupt mode.
 * Parameters:
 *   uartid--a basepointer, could be one of UART0, UART1, UART2 or UART3.
 *   brxquery--it indicates the receive mode: TRUE - query mode, FALSE -
 *   interrupt mode
 * return: SUCCESS or FAILURE
 */
CK_INT32 CK_Uart_GetChar(IN CK_Uart_Device uartid, OUT CK_UINT8 * ch)
{
    CKStruct_UartInfo *info;
    SMARTL_UART_TypeDef *uart;

    info = &(CK_Uart_Table[uartid]);
    uart = info->addr;
    if (!(info->bopened)) {
        return FAILURE;
    }

    if (info->brxquery) {
        while (!(uart->LSR & LSR_DATA_READY)) {
            /* nothing */
        };

        *ch = uart->RBR;
        return SUCCESS;
    }

    return FAILURE;
}

/* This function is used to get character,in query mode or interrupt mode.
 * Parameters:
 *       uartid--a basepointer, could be one of UART0, UART1, UART2 or UART3.
 *   brxquery--it indicates the receive mode: TRUE - query mode, FALSE -
 *   interrupt mode
 * return: SUCCESS or FAILURE
 */
CK_INT32 CK_Uart_GetCharUnBlock(IN CK_Uart_Device uartid, OUT CK_UINT8 * ch)
{
    CKStruct_UartInfo *info;
    SMARTL_UART_TypeDef *uart;

    info = &(CK_Uart_Table[uartid]);
    uart = info->addr;
    if (!(info->bopened)) {
        return FAILURE;
    }

    /*query mode */
    if (info->brxquery) {
        if (uart->LSR & LSR_DATA_READY) {
            *ch = uart->RBR;
            return SUCCESS;
        }
    }
    return FAILURE;
}

/* This function is used to transmit character,in query mode or interrupt mode.
 * Parameters:
 *   uartid--a basepointer, could be one of UART0, UART1, UART2 or UART3.
 *   brxquery--it indicates the receive mode: TRUE - query mode, FALSE -
 *   interrupt mode
 * Return: SUCCESS or FAILURE.
 */
CK_INT32 CK_Uart_PutChar(CK_Uart_Device uartid, CK_UINT8 ch)
{
    CKStruct_UartInfo *info;
    SMARTL_UART_TypeDef *uart;
    CK_UINT8 temp;

    info = &(CK_Uart_Table[uartid]);
    uart = info->addr;
    if (!(info->bopened)) {
        return FAILURE;
    }
    /*query mode */
    if (info->btxquery) {
        while ((!(uart->LSR & CK_LSR_TRANS_EMPTY))) {
            /* nothing */
        };
        if (ch == '\n') {
            uart->THR = '\r';
        }

        while ((!(uart->LSR & CK_LSR_TRANS_EMPTY))) {
            /* nothing */
        };
        uart->THR = ch;

        return SUCCESS;
    }

    return SUCCESS;
}

static int i = 1;

static void CK_Console_CallBack(signed char error)
{
}

int getchar1(void)
{
    char ch;
    if (i == 1) {
        CK_Uart_Open(UART0, CK_Console_CallBack);
        i = 0;
    }

    CK_Uart_GetChar(UART0, &ch);
    return (int)ch;
}

int fputc(int ch, FILE *stream)
{
    if (i == 1) {
        CK_Uart_Open(UART0, CK_Console_CallBack);
        i = 0;
    }

    CK_Uart_PutChar(UART0, ch);
}

int fgetc(FILE *stream)
{
    int ch = getchar1();
    fputc(ch, stream);
    return ch;
}

/******************************************************
*change the number to string
*
* uq : the number need to change
* base: the base of system(for example 2,8,10,16 as usual)
* buf: data buffer for change procedure and return result
* return value: the string  after change
*********************************************************/
static char *numtostring (unsigned int uq, int base, char *buf )
{
  register char *p, *p0;
  int n = 0, i;

  p = buf;
  *buf = 0;
  do
  {
    *buf ++ = "0123456789abcdef"[uq % base];
    n++;
  } while (uq /= base);
  p[n] = '\0';

  p0 = ++buf;
  if (base == 16 && n < 8)  //If Hex, the length is fixxed with 8 digitals
  {
    for (i = 0; i < 8 - n; i++)
    {
      p0[i] = '0';
    }
    for (; i < 8; i++)
    {
      p0[i] = p[8 - i - 1];
    }
    p0[8] = '\0';
  }
  else
  {
    for (i = 0; i < n; i++)
    {
      p0[i] = p[n - i - 1];
    }
    p0[n] = '\0';
  }

  return (p0);
}

/*
 * display the char on the console
 * ch: the char need to display
 */
int putchar(int ch)
{
  while(CK_Uart_PutChar(UART0,ch) != SUCCESS);
  return 0;
}

/*
 * display a string on the console
 * ptr: the string need to display
 */
int puts(const char *ptr)
{
    if (i == 1) {
        CK_Uart_Open(UART0, CK_Console_CallBack);
        i = 0;
    }
   while(*ptr !='\0')
   {
     if (SUCCESS == CK_Uart_PutChar(UART0, *ptr))
       ptr++;
   }
   CK_Uart_PutChar(UART0, '\n');
   return 0;
}

/*
 * display a string on the console
 * ptr: the string need to display
 */

static int puts_without_enter(const char *ptr)
{
   while(*ptr !='\0')
   {
     if (SUCCESS == CK_Uart_PutChar(UART0, *ptr))
       ptr++;
   }
   return 0;
}
/*
 * print the result after translated according to the format
 */
int printf ( const char *fmt, ... )
{
  const char *s;
  int        value;
  CK_UINT32        ptr;
  char       ch, buf[64], *pbuf;
  va_list    ap;

  va_start(ap, fmt);
  while (*fmt)
  {
    if (*fmt != '%')
    {
      putchar(*fmt++);
      continue;
    }

    switch (*++fmt)
    {
      case 's':
         s = va_arg(ap, const char *);
         puts_without_enter(s);
         break;
      case 'd':
         value = va_arg(ap, int);
         if (value < 0)
         {
            putchar('-');
            value = 0 - value;
         }
         pbuf = numtostring((unsigned int)value, 10, buf);
         puts_without_enter(pbuf);
         break;
       case 'x':
         value = va_arg(ap,int);
         pbuf = numtostring((unsigned int)value, 16, buf);
         puts_without_enter(pbuf);
         break;
       case 'c':
          ch = (unsigned char)va_arg(ap, int);
          pbuf = &ch;
          putchar(*pbuf);
          break;
//     case 'f':
//       f = va_arg(ap, float);
//       sprintf(buf, "%f\0", f);
//       for (s = buf; *s; s ++)
//       {
//          putchar(*s);
//        }
//        break;
       case 'p':
         ptr = (unsigned) va_arg(ap, void *);
         pbuf = numtostring(ptr, 16, buf);
         puts_without_enter(pbuf);
         break;
       default:
         putchar(*fmt);
         break;
    }
    fmt ++;
  }
  va_end(ap);
  return 0x01;
}

