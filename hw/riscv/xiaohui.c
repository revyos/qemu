/*
 * RISCV Xiaohui System emulation.
 *
 * Copyright (c) 2024 Alibaba Gropu. All rights reserved.
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

#include "qemu/osdep.h"
#include "qemu/units.h"
#include "qapi/error.h"
#include "target/riscv/cpu.h"
#include "hw/sysbus.h"
#include "net/net.h"
#include "sysemu/sysemu.h"
#include "hw/boards.h"
#include "hw/loader.h"
#include "exec/address-spaces.h"
#include "qemu/error-report.h"
#include "elf.h"
#include "hw/riscv/riscv_hart.h"
#include "hw/intc/sifive_plic.h"
#include "hw/intc/riscv_aclint.h"
#include "hw/char/csky_uart.h"
#include "hw/timer/csky_timer.h"
#include "hw/riscv/boot.h"

enum {
    XIAOHUI_SRAM = 0,
    XIAOHUI_PLIC = 1,
    XIAOHUI_CLINT = 2,
    XIAOHUI_AHB_CPR = 3,
    XIAOHUI_TIMER = 4,
    XIAOHUI_UART0 = 5,
    XIAOHUI_TEST = 6,
    XIAOHUI_DRAM = 7,
    XIAOHUI_ACLINT_DEFAULT_TIMEBASE_FREQ = 25000000,
    XIAOHUI_TIMER_DEFAULT_TIMEBASE_FREQ = 25000000,
};

enum {
    XIAOHUI_PLIC_NUM_SOURCES = 1023,
    XIAOHUI_PLIC_NUM_PRIORITIES = 32,
    XIAOHUI_PLIC_PRIORITY_BASE = 0x04,
    XIAOHUI_PLIC_PENDING_BASE = 0x1000,
    XIAOHUI_PLIC_ENABLE_BASE = 0x2000,
    XIAOHUI_PLIC_ENABLE_STRIDE = 0x80,
    XIAOHUI_PLIC_CONTEXT_BASE = 0x200000,
    XIAOHUI_PLIC_CONTEXT_STRIDE = 0x1000,
};

typedef struct RISCVXiaohuiState {
    /*< private >*/
    MachineState parent;

    /*< public >*/
    RISCVHartArrayState soc;
} RISCVXiaohuiState;

static const MemMapEntry xiaohui_memmap[] = {
     [XIAOHUI_SRAM]         = { 0x0000000000,    1 * MiB },
     [XIAOHUI_PLIC]         = { 0x0008000000,   64 * MiB },
     [XIAOHUI_CLINT]        = { 0x000c000000,  192 * MiB },
     [XIAOHUI_AHB_CPR]      = { 0x0018030000,   64 * KiB },
     [XIAOHUI_TIMER]        = { 0x0019001000,    4 * KiB },
     [XIAOHUI_UART0]        = { 0x001900d000,    4 * KiB },
     /* Using the simulation2 for exit qemu */
     [XIAOHUI_TEST]         = { 0x004c000000,    4 * KiB },
     [XIAOHUI_DRAM]         = { 0x0050000000,    0 },
};

static uint64_t load_kernel(const char *kernel_filename)
{
    uint64_t kernel_entry = 0, kernel_low = 0, kernel_high = 0;

    if (load_elf(kernel_filename, NULL, NULL, NULL,
                 &kernel_entry, &kernel_low, &kernel_high,
                 0, 0, EM_RISCV, 1, 0) < 0) {
        error_report("qemu: could not load kernel '%s'", kernel_filename);
        exit(1);
    }
    return kernel_entry;
}

static void xiaohui_init(MachineState *machine)
{
    qemu_irq irqs[128];
    RISCVXiaohuiState *s = g_new0(RISCVXiaohuiState, 1);
    MemoryRegion *system_memory = get_system_memory();
    MemoryRegion *sram = g_new(MemoryRegion, 1);
    char *plic_hart_config;
    int i;
    unsigned int smp_cpus = machine->smp.cpus;
    uint64_t kernel_entry = 0;

    /* Initialize SOC */
    object_initialize_child(OBJECT(machine), "soc", &s->soc,
                            TYPE_RISCV_HART_ARRAY);
    object_property_set_str(OBJECT(&s->soc), "cpu-type", machine->cpu_type,
                            &error_abort);
    object_property_set_int(OBJECT(&s->soc),  "num-harts", smp_cpus,
                            &error_abort);
    if (machine->kernel_filename) {
        kernel_entry = load_kernel(machine->kernel_filename);
        object_property_set_uint(OBJECT(&s->soc),  "resetvec",
                                 kernel_entry, &error_abort);

    }
    object_property_set_bool(OBJECT(&s->soc),  "cpu-off", true, &error_abort);
    sysbus_realize(SYS_BUS_DEVICE(&s->soc), &error_abort);
    s->soc.harts[0].env.elf_start = kernel_entry;

    /* Register SRAM */
    memory_region_init_ram(sram, NULL, "xiaohui.sram",
                           xiaohui_memmap[XIAOHUI_SRAM].size, &error_fatal);
    memory_region_add_subregion(system_memory,
                                xiaohui_memmap[XIAOHUI_SRAM].base, sram);

    /* Register DRAM */
    memory_region_add_subregion(system_memory,
                                xiaohui_memmap[XIAOHUI_DRAM].base,
                                machine->ram);

    /* create PLIC hart topology configuration string */
    plic_hart_config = riscv_plic_hart_config_string(smp_cpus);
    /* create PLIC */
    DeviceState *plic = sifive_plic_create(xiaohui_memmap[XIAOHUI_PLIC].base,
        plic_hart_config, smp_cpus, 0,
        XIAOHUI_PLIC_NUM_SOURCES,
        XIAOHUI_PLIC_NUM_PRIORITIES,
        XIAOHUI_PLIC_PRIORITY_BASE,
        XIAOHUI_PLIC_PENDING_BASE,
        XIAOHUI_PLIC_ENABLE_BASE,
        XIAOHUI_PLIC_ENABLE_STRIDE,
        XIAOHUI_PLIC_CONTEXT_BASE,
        XIAOHUI_PLIC_CONTEXT_STRIDE,
        xiaohui_memmap[XIAOHUI_PLIC].size);
    g_free(plic_hart_config);
    for (i = 0; i < 127; i++) {
        irqs[i] = qdev_get_gpio_in(DEVICE(plic), i);
    }
    riscv_aclint_swi_create(xiaohui_memmap[XIAOHUI_CLINT].base, 0, smp_cpus,
                            false);
    riscv_aclint_swi_create(xiaohui_memmap[XIAOHUI_CLINT].base + 0xC000, 0,
                            smp_cpus, true);
    riscv_aclint_mtimer_create(xiaohui_memmap[XIAOHUI_CLINT].base + 0x4000,
                               RISCV_ACLINT_DEFAULT_MTIMER_SIZE,
                               0, smp_cpus, RISCV_ACLINT_DEFAULT_MTIMECMP,
                               RISCV_ACLINT_DEFAULT_MTIME,
                               XIAOHUI_ACLINT_DEFAULT_TIMEBASE_FREQ, true);
    riscv_aclint_mtimer_create(xiaohui_memmap[XIAOHUI_CLINT].base + 0xD000,
                               RISCV_ACLINT_DEFAULT_MTIMER_SIZE,
                               0, smp_cpus, RISCV_ACLINT_DEFAULT_MTIMECMP,
                               UINT32_MAX, XIAOHUI_ACLINT_DEFAULT_TIMEBASE_FREQ,
                               false);
    csky_uart_create(xiaohui_memmap[XIAOHUI_UART0].base, irqs[20],
                     serial_hd(0));

    csky_timer_set_freq(XIAOHUI_TIMER_DEFAULT_TIMEBASE_FREQ);
    sysbus_create_varargs("csky_timer", xiaohui_memmap[XIAOHUI_TIMER].base,
                          irqs[25], irqs[26], irqs[27], irqs[28], NULL);

    sysbus_create_simple("csky_exit", xiaohui_memmap[XIAOHUI_TEST].base, NULL);
    sysbus_create_simple("xiaohui_cpr", xiaohui_memmap[XIAOHUI_AHB_CPR].base,
                         NULL);
    g_free(plic_hart_config);
}

static void xiaohui_class_init(ObjectClass *oc, void *data)
{
    MachineClass *mc = MACHINE_CLASS(oc);

    mc->desc = "RISC-V xiaohui";
    mc->default_ram_id = "riscv.xiaohui.dram";
    mc->init = xiaohui_init;
    mc->max_cpus = 8; /* hardcoded limit in BBL */
    mc->default_cpu_type = RISCV_CPU_TYPE_NAME("c907fdvm");
}

static const TypeInfo xiaohui_type = {
    .name = MACHINE_TYPE_NAME("xiaohui"),
    .parent = TYPE_MACHINE,
    .class_init = xiaohui_class_init,
};

static void xiaohui_machine_init(void)
{
    type_register_static(&xiaohui_type);
}

type_init(xiaohui_machine_init)
