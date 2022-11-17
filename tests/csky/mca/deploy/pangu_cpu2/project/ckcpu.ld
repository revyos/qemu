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
 * @file     gcc_csky.h
 * @brief    csky linker file for pangu cpu 2
 * @version  V1.0
 * @date     11. July 2019
 ******************************************************************************/
ENTRY(Reset_Handler)

MEMORY
{
    QSPIFLASH      : ORIGIN = 0x8000000 , LENGTH = 0x800000 /* QSPIFLASH      8MB */

    TCM0           : ORIGIN = 0x80010000, LENGTH = 0x10000  /* CPU1 I-SRAM   64KB */

    TCM1_CHUNK_0   : ORIGIN = 0x80020000, LENGTH = 0x1000   /* CHUNK BUFFER 0 4KB */
    TCM1_FAST_HEAP : ORIGIN = 0x80021000, LENGTH = 0xE000   /* FAST HEAP     56KB */
    TCM1_CHUNK_1   : ORIGIN = 0x8002F000, LENGTH = 0x1000   /* CHUNK BUFFER 1 4KB */
    TCM1_OTHERS    : ORIGIN = 0x80030000, LENGTH = 0x10000  /* OTHERS        64KB */

    SDRAM          : ORIGIN = 0x18000000, LENGTH = 0x800000 /* SDRAM          8MB */
}

HIDDEN(__heap_size = 0x20000);

REGION_ALIAS("REGION_TEXT"          , SDRAM         );
REGION_ALIAS("REGION_RODATA"        , SDRAM         );
REGION_ALIAS("REGION_DATA"          , TCM1_OTHERS   );
REGION_ALIAS("REGION_BSS"           , TCM1_OTHERS   );
REGION_ALIAS("REGION_SDRAM"         , SDRAM         );
REGION_ALIAS("REGION_CHUNK_BUFFER_0", TCM1_CHUNK_0  );
REGION_ALIAS("REGION_CHUNK_BUFFER_1", TCM1_CHUNK_1  );
REGION_ALIAS("REGION_FAST_HEAP"     , TCM1_FAST_HEAP);

SECTIONS
{
	.text : {
		. = ALIGN(0x4);
		KEEP(*crt0.o(.vectors))
		__stext = .;
		*(.text)
		*(.text*)
		*(.text.*)
		*(.gnu.warning)
		*(.stub)
		*(.gnu.linkonce.t*)
		*(.glue_7t)
		*(.glue_7)
		*(.jcr)
		*(.init)
		*(.fini)
		. = ALIGN (4);
		PROVIDE(__ctbp = .);
		*(.call_table_data)
		*(.call_table_text)
		. = ALIGN(0x10);
		__etext = .;
	} > REGION_TEXT

	.eh_frame_hdr : {
		*(.eh_frame_hdr)
	} > REGION_TEXT

	.eh_frame : ONLY_IF_RO {
		KEEP (*(.eh_frame))
	} > REGION_TEXT

	.gcc_except_table : ONLY_IF_RO {
		*(.gcc_except_table .gcc_except_table.*)
	} > REGION_TEXT

	.rodata :  {
		. = ALIGN(0x4);
		__srodata = .;
		*(.rdata)
		*(.rdata*)
		*(.rdata1)
		*(.rdata.*)
		*(.rodata)
		*(.rodata1)
		*(.rodata*)
		*(.rodata.*)
		*(.rodata.str1.4)
		. = ALIGN(0x4);
		__ctor_start__ = .;
		KEEP (*(SORT(.ctors.*)))
		KEEP (*(.ctors))
		__ctor_end__ = .;
		KEEP (*(SORT(.dtors.*)))
		KEEP (*(.dtors))
		__dtor_end__ = .;
		. = ALIGN(0x4);
		__erodata = .;
	} > REGION_RODATA

	.data :  {
		. = ALIGN(0x4);
		__sdata = .;
		__data_start__ = .;
		data_start = .;
		*(.got.plt)
		*(.got)
		*(.gnu.linkonce.r*)
		*(.data)
		*(.data*)
		*(.data1)
		*(.data.*)
		*(.gnu.linkonce.d*)
		*(.data1)
		*(.gcc_except_table)
		*(.gcc_except_table*)
		__start_init_call = .;
		*(.initcall.init)
		__stop_init_call = .;
		__start_cmd = .;
		*(.bootloaddata.cmd)
		. = ALIGN(4);
		__stop_cmd = .;
		*(.sdata)
		*(.sdata.*)
		*(.gnu.linkonce.s.*)
		*(__libc_atexit)
		*(__libc_subinit)
		*(__libc_subfreeres)
		*(.note.ABI-tag)
		. = ALIGN(0x4);
		__edata = .;
		__data_end__ = .;
	} > REGION_DATA

	.eh_frame : ONLY_IF_RW {
		KEEP (*(.eh_frame))
	} > REGION_DATA

	.gcc_except_table : ONLY_IF_RW {
		*(.gcc_except_table .gcc_except_table.*)
		__edata = .;
		__data_end__ = .;
	} > REGION_DATA

	.bss : {
		. = ALIGN(0x4);
		__sbss = ALIGN(0x4);
		__bss_start__ = .;
		*(.dynsbss)
		*(.sbss)
		*(.sbss.*)
		*(.scommon)
		*(.dynbss)
		*(.bss)
		*(.bss.*)
		*(COMMON)
		. = ALIGN(0x4);
		__ebss = .;
		__end = .;
		end = .;
		__bss_end__ = .;
	} > REGION_BSS

	.user_heap : {
		. = ALIGN(0x10);
		__heap_start = .;
		. += __heap_size;
		__heap_end = .;
		. = ALIGN(0x4);
		ASSERT((__heap_size >= 0x20),
			"Error: Heap size must be no less than 0x20 to store some initialial structures.");
	} > REGION_SDRAM

	.chunk_buffer_0 : {
		*(.chunk_buffer_0)
	} > REGION_CHUNK_BUFFER_0

	.chunk_buffer_1 : {
		*(.chunk_buffer_1)
	} > REGION_CHUNK_BUFFER_1

	.fast_heap : {
		*(.fast_heap)
	} > REGION_FAST_HEAP

	.sdram : {
		*(.sdram)
	} > REGION_SDRAM
}
