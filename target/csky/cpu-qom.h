/*
 * C-SKY CPU qom
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


#ifndef QEMU_CSKY_CPU_QOM_H
#define QEMU_CSKY_CPU_QOM_H

#include "hw/core/cpu.h"
#include "qom/object.h"

#define TYPE_CSKY_CPU "csky-cpu"

#define CSKY_CPU_CLASS(klass) \
    OBJECT_CLASS_CHECK(CSKYCPUClass, (klass), TYPE_CSKY_CPU)
#define CSKY_CPU(obj) \
    OBJECT_CHECK(CSKYCPU, (obj), TYPE_CSKY_CPU)
#define CSKY_CPU_GET_CLASS(obj) \
    OBJECT_GET_CLASS(CSKYCPUClass, (obj), TYPE_CSKY_CPU)

/**
 * CSKYCPUClass:
 * @parent_realize: The parent class' realize handler.
 * @parent_reset: The parent class' reset handler.
 *
 * A CSKY CPU model.
 */
typedef struct CSKYCPUClass {
    /*< private >*/
    CPUClass parent_class;
    /*< public >*/

    DeviceRealize parent_realize;
    DeviceReset parent_reset;

    /* all c860 cores should see the same rmr and rvbr register */
    uint32_t rmr;
    uint32_t rvbr;
} CSKYCPUClass;

typedef struct CSKYCPU CSKYCPU;

#endif
