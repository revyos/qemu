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

int main(void)
{
	int i = 0;
	uint8_t *p;

	init_testsuite("Testing NVIC api\n");

	TEST(&(NVIC->ISER) == (uint32_t *)0xE000E100);
	TEST(&(NVIC->IWER) == (uint32_t *)0xE000E140);
	TEST(&(NVIC->ICER) == (uint32_t *)0xE000E180);
	TEST(&(NVIC->ICPR) == (uint32_t *)0xE000E280);
	TEST(&(NVIC->IABR) == (uint32_t *)0xE000E300);
	TEST(&(NVIC->IPR) == (uint32_t *)0xE000E400);
	TEST(&(NVIC->ISR) == (uint32_t *)0xE000EC00);
	TEST(&(NVIC->IPTR) == (uint32_t *)0xE000EC04);

	unsigned char free_mem[0x1000];

#undef NVIC
#define NVIC	((NVIC_Type *) free_mem)

	p = (uint8_t *)free_mem;

	NVIC->IWER[0] = 0x12345678;
	TEST(*(uint32_t *)(p + 0x40) == 0x12345678);

	NVIC->IABR[0] = 0x22345678;
	TEST(*(uint32_t *)(p + 0x200) == 0x22345678);

	NVIC->IPTR = 0x32345678;
	TEST(*(uint32_t *)(p + 0xB04) == 0x32345678);

	return done_testing();
}
