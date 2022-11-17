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

#include "testsuite.h"
#include "test_device.h"

#define USER1_INT_PRIO   3
#define USER2_INT_PRIO   2 
#define USER3_INT_PRIO   1 
#define NVIC_THRESHOLD   0  
#define USER1_IRQ        3
#define USER2_IRQ        4 
#define USER3_IRQ        5     
static volatile int tick_count;

int coretimer_irq_handler(void)
{
    int temp;
    CORET_LOAD_CSR();
    tick_count++;
	if ((tick_count == 9876) || (tick_count == 98)) 
	{
		printf("tick = %d\n", tick_count);
	printf("----------------------------------------\n");
	}

}

void user1_int_irq_handler(void)
{ 
	int NVIC_Pend=0;
 	int NVIC_Active = 0;
	int NVIC_wakeup1 = 0;
	printf("--------start user1 irq handler!\n");
	
	NVIC_Active=NVIC_GetActive(USER1_IRQ);
        TEST(NVIC_Active);
        if(NVIC_Active)
 		printf("User1  NVIC_Active successed!\n");
        NVIC_wakeup1=NVIC_GetWakeupIRQ(USER1_IRQ);
        TEST(NVIC_wakeup1);
        if(NVIC_wakeup1)
        printf("User1 NVIC_SetWakeupIRQ successed!\n");

   	NVIC_ClearPendingIRQ(USER1_IRQ );
 	NVIC_DisableIRQ(USER1_IRQ );

        __disable_irq();
	NVIC_SetPendingIRQ(USER2_IRQ );

	NVIC_Pend= NVIC_GetPendingIRQ(USER2_IRQ);
        __enable_irq();
        TEST(NVIC_Pend);
        if(NVIC_Pend)
            printf("User2 NVIC_SetPending successed!\n");
       
        printf("--------User1 irq handle successed!\n");
} 

void user2_int_irq_handler(void)
{ 
	int NVIC_Pend=0;
 	int NVIC_Active = 0;
	int NVIC_wakeup2 = 0;
	printf("--------start user2 irq handler!\n");
	
	NVIC_Active=NVIC_GetActive(USER2_IRQ);
        TEST(NVIC_Active);
        if(NVIC_Active)
 		printf("User2  NVIC_Active successed!\n");
        NVIC_wakeup2=NVIC_GetWakeupIRQ(USER2_IRQ);
        TEST(NVIC_wakeup2);
        if(NVIC_wakeup2)
        printf("User2 NVIC_SetWakeupIRQ successed!\n");
#if __CK80X < 3
        NVIC_SetThreshold(USER2_IRQ,NVIC_THRESHOLD);
#endif
   	NVIC_ClearPendingIRQ(USER2_IRQ );
 	NVIC_DisableIRQ(USER2_IRQ );

        __disable_irq();
	NVIC_SetPendingIRQ(USER3_IRQ );

	NVIC_Pend= NVIC_GetPendingIRQ(USER3_IRQ);
        __enable_irq();
        TEST(NVIC_Pend);
        if(NVIC_Pend)
            printf("User3 NVIC_SetPending successed!\n");
       
        printf("--------User2 irq handle successed!\n");
} 
void user3_int_irq_handler(void)
{ 
	int NVIC_Pend=0;
	int NVIC_Active = 0;
	int NVIC_wakeup3 = 0;
	printf("--------Start user3 irq handler!\n");
	
	NVIC_Active=NVIC_GetActive(USER3_IRQ);
        TEST(NVIC_Active);
        if(NVIC_Active)
 		printf("User3  NVIC_Active successed!\n");
 	NVIC_wakeup3=NVIC_GetWakeupIRQ(USER3_IRQ);
        TEST(NVIC_wakeup3);
        if(NVIC_wakeup3)
        printf("User3 NVIC_SetWakeupIRQ successed!\n");
      
	NVIC_ClearPendingIRQ(USER3_IRQ);
	NVIC_DisableIRQ(USER3_IRQ);
        printf("--------User3 irq handle successed!\n");
} 


void user1_int(IRQn_Type IRQn, uint32_t priority)
{
	int NVIC_Priority = 0;
        int NVIC_Active = 0;
        init_testsuite("Testing User1 int  function!\n");
	NVIC_SetPriority(IRQn, priority);
        NVIC_SetWakeupIRQ(IRQn);
	NVIC_EnableIRQ(IRQn);
        NVIC_Priority=NVIC_GetPriority(IRQn);
        TEST(NVIC_Priority==USER1_INT_PRIO);
        if(NVIC_Priority==USER1_INT_PRIO)
            printf("User1 NVIC_SetPriority IRQ successed!\n");
        printf("----------------------------------------\n");
}

void user2_int(IRQn_Type IRQn, uint32_t priority)
{
	int NVIC_Priority = 0;
	int NVIC_Active = 0;
        init_testsuite("Testing User2 int  function!\n");
	NVIC_SetPriority(IRQn, priority);
        NVIC_SetWakeupIRQ(IRQn);
        NVIC_EnableIRQ(IRQn);
        NVIC_Priority=NVIC_GetPriority(IRQn);
        TEST(NVIC_Priority==USER2_INT_PRIO);
        if(NVIC_Priority==USER2_INT_PRIO)
            printf("User2 NVIC_SetPriority IRQ successed!\n");
        printf("----------------------------------------\n");
}

void user3_int(IRQn_Type IRQn, uint32_t priority)
{
	int NVIC_Priority = 0;
	int NVIC_Active = 0;
        init_testsuite("Testing User3 int  function!\n");
	NVIC_SetPriority(IRQn, priority);
        NVIC_SetWakeupIRQ(IRQn);
        NVIC_EnableIRQ(IRQn);
        NVIC_Priority=NVIC_GetPriority(IRQn);
        TEST(NVIC_Priority==USER3_INT_PRIO);
        if(NVIC_Priority==USER3_INT_PRIO)
            printf("User3 NVIC_SetPriority IRQ successed!\n");
        printf("----------------------------------------\n");
}
int main(void)
{
	int i = 0;
        int NVIC_Priority; 
	int NVIC_Pend=0;
        int NVIC_wakeup = 1;

	init_testsuite("-*************Testing functions NVIC function********************\n");
	SysTick_Config(10000);
	NVIC_EnableIRQ (CORET_IRQn);
        __enable_irq();

	while (1) 
	{
		if (tick_count >10000)
                {
			
			NVIC_SetPendingIRQ(USER1_IRQ);
			NVIC_Pend= NVIC_GetPendingIRQ(USER1_IRQ);
                        TEST(NVIC_Pend);
 			if(NVIC_Pend)
        		printf("User1 NVIC_SetPending successed!\n");
			break;
		}
	}
        NVIC_Priority=NVIC_GetPriority(CORET_IRQn);
        printf("CORET_INT Prioriyt =%d \n",NVIC_Priority);
        NVIC_DisableIRQ(CORET_IRQn);
        user3_int(USER3_IRQ,USER3_INT_PRIO);
	user2_int(USER2_IRQ,USER2_INT_PRIO);
	user1_int(USER1_IRQ,USER1_INT_PRIO);
	
        NVIC_ClearWakeupIRQ(USER1_IRQ);
        NVIC_wakeup=NVIC_GetWakeupIRQ(USER1_IRQ);
 	TEST(!NVIC_wakeup);
        if(!NVIC_wakeup)
        printf("User1 NVIC_ClearWakeupIRQ successed!\n");
        NVIC_wakeup=1;

        NVIC_ClearWakeupIRQ(USER2_IRQ);
 	NVIC_wakeup=NVIC_GetWakeupIRQ(USER2_IRQ);
	TEST(!NVIC_wakeup);
        if(!NVIC_wakeup)
        printf("User2 NVIC_ClearWakeupIRQ successed!\n");
 	NVIC_wakeup=1;

        NVIC_ClearWakeupIRQ(USER3_IRQ);
 	NVIC_wakeup=NVIC_GetWakeupIRQ(USER3_IRQ);

	TEST(!NVIC_wakeup);
        if(!NVIC_wakeup)
        printf("User3 NVIC_ClearWakeupIRQ successed!\n");

	return done_testing();
}
