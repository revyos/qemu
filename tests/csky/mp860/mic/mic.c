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
#define MIC_BASE 0x1efff000
#define MIC_CPU_BASE 0x1effe000
#define MIC_CPU_LEN 0x200
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
#define MIC_IREADYR_OFFSET 0x58
int k;
void default_irq_handler(void)
{
    k++;
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
volatile int m = 1;
int core0()
{
    int j = 0;
    init_testsuite("Test CK860 mic spdr\n");
    /* init mic */
    /* fisrt clear all enable bits */
    for (int i = 0; i < MIC_CICER_NUM; i++) {
        unsigned int *cicer = (unsigned int *)(0x1ffff000 + 0x600 + i * 4);
        *cicer = 0xffffffff;
    }
    /* set typer, priority, trigger */
    unsigned int *cityper = (unsigned int  *)(MIC_BASE + MIC_CITYPER_OFFSET);
    *cityper = 0;
    unsigned int *cicfgr = (unsigned int *)(MIC_BASE + MIC_CICFGR_OFFSET);
    *cicfgr = 0;
    unsigned int *cipriority = (unsigned int *)(MIC_BASE +
        MIC_CIPRIORITYR_OFFSET);
    *cipriority = 0x44332211;

    /* set dist method */
    unsigned int *cidestr = (unsigned int *)(MIC_BASE + MIC_CIDESTR_OFFSET);
    *cidestr = 0x80000000;

    /* set enable bits */
    unsigned int *ciser = (unsigned int *)(MIC_BASE + MIC_CISER_OFFSET);
    *ciser = 0xffffffff;
    enable_irq();
    irq_handler[32] = irq32_handler;
    /* one interrupt */
    unsigned int *spdr = (unsigned int *)(MIC_CPU_BASE + MIC_SPDR_OFFSET);
    *spdr = 32;

    while (j < 100) {
        j += 5;
    }
    /* loop forever */
    while (m) {
        j++;
        j = j % 3;
    }
    k += 5;
    return j;
}
int mic_int_handler()
{
    int ireadyr = -1;
    int coreid = get_mpid();
    ireadyr = *(unsigned int *)(MIC_CPU_BASE + coreid * MIC_CPU_LEN +
        MIC_IREADYR_OFFSET);
    void (*handler) (void) = irq_handler[ireadyr];
    (*handler)();
    return 0;
}
int core1()
{
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
    TEST(k == 4);
    return done_testing();;
}
