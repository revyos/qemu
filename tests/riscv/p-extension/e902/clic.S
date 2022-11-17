#
# Copyright (c) 2011-2019 C-SKY Limited. All rights reserved.
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, see <http://www.gnu.org/licenses/>.
#

.equ SIFIVE_CLIC_BASE, 0xE000E100
.equ SIFIVE_CLIC_CLINT_SIZE, 0x10000
.equ SIFIVE_CLIC_HART_SIZE, 0x1000

.equ SIFIVE_CLICINTIP_OFFSET, 0x0
.equ SIFIVE_CLICINTIE_OFFSET, 0x400
.equ SIFIVE_CLICINTCFG_OFFSET, 0x800
.equ SIFIVE_CLICCFG_OFFSET, 0xb00

.equ SIFIVE_CLIC_CLINT_MMODE_OFFSET, 0x0
.equ SIFIVE_CLIC_CLINT_SMODE_OFFSET, 0x20000
.equ SIFIVE_CLIC_CLIC_MMODE_OFFSET, 0x800000
.equ SIFIVE_CLIC_CLIC_SMODE_OFFSET, 0xc00000

.equ SIFIVE_CLIC_MIN_SOURCES, 4
.equ SIFIVE_CLIC_MAX_SOURCES, 1024
.equ SIFIVE_CLIC_MIN_INT_BITS, 2
.equ SIFIVE_CLIC_MAX_INT_BITS, 8
.equ SIFIVE_CLIC_MAX_MODE_BITS, 8
.equ SIFIVE_CLIC_MAX_LEVEL_BITS, 8
.equ SIFIVE_CLIC_MAX_PRIORITY_BITS, 8
.equ SIFIVE_CLIC_MAX_VEC_BITS, 1

