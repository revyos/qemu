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
#include <testsuite.h>
#include <micfunc.h>
#define MIC_IRQ_NUM 224
#define MIC_BASE 0x9ffe0000
#define MIC_CPU_BASE 0x9ffe8000
#define MIC_CPU_LEN 0x1000
#define MIC_CICER_OFFSET 0x600
#define MIC_CICER_NUM 6
#define MIC_CISER_OFFSET 0x580
#define MIC_CISER_NUM 6

#define MIC_CITYPER_OFFSET 0x80
#define MIC_CITYPER_NUM 6
#define MIC_CICFGR_OFFSET 0x100
#define MIC_CICFGR_NUM 12
#define MIC_CIPRIORITYR_OFFSET 0x180
#define MIC_CIPRIORITYR_NUM 48

#define MIC_CIDESTR_OFFSET 0x880
#define MIC_CIDESTR_NUM 192

#define MIC_SPDR_OFFSET 0x10c
#define MIC_IREADYR_OFFSET 0x6c
#define MIC_PSITYPER_OFFSET 0x10
#define MIC_PSIPRIORITYR_OFFSET 0x30
#define MIC_PICFGR_OFFSET 0x14
#define MIC_PSICER_OFFSET 0x44
#define MIC_PSISER_OFFSET 0x40

#define MPTIMER_BASE 0x9fffd000

volatile int m = 0;
int corex()
{
   int j = 0;
   printf("enter corex\n");
   while (m == 1) {
        j++;
        j = j % 3;
    }
}

int k;
void default_irq_handler(void)
{
    k++;
    m = 1;
    return;
}
void irq16_handler(void)
{
    printf("timer interrupt came\n");
    k++;
    m = 1;
    mptimer_clear_irq();
    return;
}
void irq32_handler(void)
{
    k += 2;
    return;
}
void (*irq_handler[MIC_IRQ_NUM])(void) = {
    default_irq_handler
};
int core0()
{
    int j = 0;
    init_testsuite("Test CK860 mptimer\n");
    /* init mic */
    /* fisrt clear all enable bits */
    unsigned int *psicer = (unsigned int *)(MIC_CPU_BASE + MIC_PSICER_OFFSET);
    *psicer = 0xffffffff;
    /* set typer, priority, trigger */
    unsigned int *psityper = (unsigned int *)(MIC_CPU_BASE +
        MIC_PSITYPER_OFFSET);
    *psityper = 0x0;
    unsigned int *picfgr = (unsigned int *)(MIC_CPU_BASE + MIC_PICFGR_OFFSET);
    *picfgr = 0x0;
    unsigned int *psipriority = (unsigned int *)(MIC_CPU_BASE +
        MIC_PSIPRIORITYR_OFFSET);
    *psipriority = 0x44332211;

    /* set enable bits */
    unsigned int *psiser = (unsigned int *)(MIC_CPU_BASE + MIC_PSISER_OFFSET);
    *psiser = 0xffffffff;
    enable_irq();
    /* init mptimer */
    /* enable counter */
    unsigned int *cnt_ctlr = (unsigned int *)(MPTIMER_BASE);
    *cnt_ctlr = 1;

    irq_handler[32] = irq32_handler;
    irq_handler[16] = irq16_handler;
    /* enable ptim */
    enable_ptim();

    /* set lvr */
    set_lvr(0x500000);

    while (j < 100) {
        j += 5;
    }
    k += 5;
    /* loop forever */
    while (m == 0) {
        j++;
        j = j % 3;
    }
    return j;
}
int mic_int_handler()
{
    printf("enter mic int handler\n");
    int ireadyr = -1;
    int coreid = get_mpid();
    ireadyr = *(unsigned int *)(MIC_CPU_BASE + coreid * MIC_CPU_LEN +
        MIC_IREADYR_OFFSET);
    printf("the irq num is %d\n", ireadyr);
    void (*handler) (void) = irq_handler[ireadyr];
    printf("handler 0x%08x\n", handler);
    (*handler)();
    return 0;
}
int core1()
{
    printf("enter core1\n");
    k++;
    return 0;
}
int core2()
{
    k++;
    return 0;
}
int core3()
{
    printf("core3 is running\n");
    TEST(k == 8);
    return done_testing();;
}
