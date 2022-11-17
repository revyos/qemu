/*
 * a dummy similar with T-HEAD Trilobite V2 System emulation.
 *
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

#undef NEED_CPU_H
#define NEED_CPU_H

#include "qemu/osdep.h"
#include "qapi/error.h"
#include "qemu-common.h"
#include "target/riscv/cpu.h"
#include "hw/csky/csky_boot.h"
#include "hw/sysbus.h"
#include "net/net.h"
#include "sysemu/sysemu.h"
#include "hw/boards.h"
#include "hw/loader.h"
#include "sysemu/block-backend.h"
#include "exec/address-spaces.h"
#include "qemu/error-report.h"
#include "hw/char/csky_uart.h"
#include "hw/timer/csky_coret.h"
#include "hw/csky/dynsoc.h"
#include "elf.h"
#include "hw/intc/sifive_clint.h"
#include "hw/intc/sifive_plic.h"
#include "hw/intc/riscv_clic.h"
#include "hw/intc/thead_clint.h"
#include "hw/riscv/riscv_hart.h"
#include "hw/riscv/virt.h"

static struct csky_boot_info dummyh_binfo = {
    .loader_start = 0x0,
    .dtb_addr = 0x8f000000,
    .magic = 0x20150401,
};

static uint64_t load_kernel(CPURISCVState* env, const char *kernel_filename)
{
    uint64_t kernel_entry = 0, kernel_low = 0, kernel_high = 0;

    if (load_elf(kernel_filename, NULL, NULL, NULL,
                 &kernel_entry, &kernel_low, &kernel_high,
                 0, 0, EM_RISCV, 1, 0) < 0) {
        error_report("qemu: could not load kernel '%s'", kernel_filename);
        exit(1);
    }
    env->pc = (target_ulong)kernel_entry;
    env->elf_start = kernel_entry;
    return kernel_entry;
}

#define RAM_NUM     8
#define DEV_NUM     32
static void dummyh_init(MachineState *machine)
{
    Object *cpuobj;
    CPURISCVState *env;
    DeviceState *dev = NULL;
    RISCVVirtState *s = NULL;
    int i;
    struct dynsoc_board_info *b_info = dynsoc_b_info;
    MemoryRegion *sysmem = get_system_memory();
    MemoryRegion *ram[RAM_NUM];
    int dev_type;
    qemu_irq *irqs = NULL;
    char *plic_hart_config;
    size_t plic_hart_config_len;
    bool has_clint = false, has_clic = false, has_plic = false;

    cpuobj = object_new(machine->cpu_type);

    object_property_set_bool(cpuobj, "realized", true, &error_fatal);
    env = &RISCV_CPU(cpuobj)->env;

    for (i = 0; i < RAM_NUM; i++) {
        ram[i] = g_new(MemoryRegion, 1);
        if (b_info->mem[i].size != 0) {
            if (b_info->mem[i].boot == 1) {
                dummyh_binfo.ram_size = b_info->mem[i].size;
            }
            if (b_info->mem[i].writeable == 1) {
                memory_region_init_ram(ram[i], NULL,
                                       b_info->mem[i].name,
                                       b_info->mem[i].size,
                                       &error_fatal);
                memory_region_add_subregion(sysmem, b_info->mem[i].addr,
                                            ram[i]);
            } else if (b_info->mem[i].writeable == 0) {
                /* !writeable means this ram is alias of a rom/flash */
                memory_region_init_ram(ram[i], NULL,
                                       b_info->mem[i].name,
                                       b_info->mem[i].size,
                                       &error_fatal);
                memory_region_set_readonly(ram[i], true);
                memory_region_add_subregion(sysmem, b_info->mem[i].addr,
                                            ram[i]);
            }
        }

        if (b_info->mem[i].size == 0) {
            continue;
        }
    }

    if (b_info->set_intc == 0) {
        goto finish_device;
    }
    for (i = 0; i < DEV_NUM; i++) {
        if (strstr(b_info->dev[i].name, "csky_clic")) {
            has_clic = true;
        }
        if (strstr(b_info->dev[i].name, "csky_plic")) {
            has_plic = true;
        }
        if (strstr(b_info->dev[i].name, "csky_clint")) {
            has_clint = true;
        }
    }

    for (i = 0; i < DEV_NUM; i++) {
        dev_type = b_info->dev[i].type;
        switch (dev_type) {
        case DYNSOC_EMPTY:
            /* do nothing */
            break;
        case DYNSOC_INTC:
            if (strstr(b_info->dev[i].name, "csky_clic")) {
                    int j;
                    dev = riscv_clic_create(b_info->dev[i].addr + (has_clint ? 0 : 0x800000),
                                            false, false, true,
                                            1, 256, 3, "v0.8");
                    irqs = malloc(sizeof(qemu_irq) * 256);
                    for (j = 0; j < 256; j++) {
                        irqs[j] = qdev_get_gpio_in(dev, j);
                    }
                    if (!has_clint) { /* Compitable with no clint configuration */
                        qemu_irq pirq[2] = {irqs[3], irqs[7]};
                        thead_clint_create(b_info->dev[i].addr, pirq, 1);
                    }
            } else if (!strcmp(b_info->dev[i].name, "csky_plic")) {
                int j;
                /* create PLIC hart topology configuration string */
                plic_hart_config_len = (strlen(VIRT_PLIC_HART_CONFIG) + 1);
                plic_hart_config = g_malloc0(plic_hart_config_len);
                strncat(plic_hart_config, VIRT_PLIC_HART_CONFIG,
                        plic_hart_config_len);
                /* create PLIC */
                s = g_new0(RISCVVirtState, 1);
                irqs = g_new0(qemu_irq, 128);
                s->plic[0] = sifive_plic_create(b_info->dev[i].addr,
                    plic_hart_config, 0,
                    VIRT_PLIC_NUM_SOURCES,
                    VIRT_PLIC_NUM_PRIORITIES,
                    VIRT_PLIC_PRIORITY_BASE,
                    VIRT_PLIC_PENDING_BASE,
                    VIRT_PLIC_ENABLE_BASE,
                    VIRT_PLIC_ENABLE_STRIDE,
                    VIRT_PLIC_CONTEXT_BASE,
                    VIRT_PLIC_CONTEXT_STRIDE,
                    0x4000000);
                for (j = 0; j < VIRT_PLIC_NUM_SOURCES; j++) {
                    irqs[j] = qdev_get_gpio_in(DEVICE(s->plic[0]), j);
                }

            } else if (!strcmp(b_info->dev[i].name, "csky_clint")) {
                if (has_plic) {
                    sifive_clint_create(b_info->dev[i].addr,
                        0x10000, 0,
                        machine->smp.cpus,
                        SIFIVE_SIP_BASE,
                        0xC000,
                        SIFIVE_TIMECMP_BASE,
                        0xD000,
                        SIFIVE_TIME_BASE,
                        SIFIVE_CLINT_TIMEBASE_FREQ, true);
                } else if (has_clic) {
                    qemu_irq pirq[2] = {irqs[3], irqs[7]};
                    thead_clint_create(b_info->dev[i].addr, pirq, 1);
                }
            }
            break;
        case DYNSOC_UART:
            csky_uart_create(b_info->dev[i].addr,
                             irqs[b_info->dev[i].irq],
                             serial_hd(0));
            break;
        case DYNSOC_TIMER:
            if (!strcmp(b_info->dev[i].name, "csky_coret")) {
                continue;
            }
            sysbus_create_varargs(b_info->dev[i].name, b_info->dev[i].addr,
                                  irqs[b_info->dev[i].irq],
                                  irqs[b_info->dev[i].irq + 1],
                                  irqs[b_info->dev[i].irq + 2],
                                  irqs[b_info->dev[i].irq + 3],
                                  NULL);

            break;
        case DYNSOC_LCDC:
            /* todo */
            break;
        case DYNSOC_MAC:
            /* todo */
            break;
        case DYNSOC_EXIT:
        case DYNSOC_MEMLOG:
            sysbus_create_simple(b_info->dev[i].name, b_info->dev[i].addr,
                                 NULL);
            break;
        case DYNSOC_DMA:
            /* todo */
            break;
        case DYNSOC_IIS:
            /* todo */
            break;
        case DYNSOC_NAND:
        case DYNSOC_SDHC:
            /* todo */
            break;
        case DYNSOC_USB:
        case DYNSOC_CUSTOM:
            /* todo */
            break;
        default:
            fprintf(stderr, "not support device type\n");
            exit(1);
        }

    }

finish_device:
    if (dummyh_binfo.ram_size == 0) {
        dummyh_binfo.ram_size = machine->ram_size;
    }
    dummyh_binfo.kernel_filename = machine->kernel_filename;
    dummyh_binfo.kernel_cmdline = machine->kernel_cmdline;
    dummyh_binfo.initrd_filename = machine->initrd_filename;
    dummyh_binfo.bios = machine->firmware;
    dummyh_binfo.loader_start = b_info->loader_start;
    load_kernel(env, dummyh_binfo.kernel_filename);
}

static void dummyh_class_init(ObjectClass *oc, void *data)
{
    MachineClass *mc = MACHINE_CLASS(oc);

    mc->desc = "THEAD dummyh";
    mc->init = dummyh_init;
    mc->default_cpu_type = RISCV_CPU_TYPE_NAME("e902");
}

static const TypeInfo dummyh_type = {
    .name = MACHINE_TYPE_NAME("dummyh"),
    .parent = TYPE_MACHINE,
    .class_init = dummyh_class_init,
};

static void dummyh_machine_init(void)
{
    type_register_static(&dummyh_type);
}

type_init(dummyh_machine_init)
