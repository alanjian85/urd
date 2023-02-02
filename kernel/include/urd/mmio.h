// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: GPL-3.0

#ifndef URD_KERNEL_MMIO_H_
#define URD_KERNEL_MMIO_H_

#include <stdint.h>

#define readb(reg) (*(volatile uint8_t *) (uintptr_t) (reg))
#define readh(reg) (*(volatile uint16_t *) (uintptr_t) (reg))
#define readw(reg) (*(volatile uint32_t *) (uintptr_t) (reg))
#define readd(reg) (*(volatile uint64_t *) (uintptr_t) (reg))

#define writeb(reg, val) (*(volatile uint8_t *) (uintptr_t) (reg) = (val))
#define writeh(reg, val) (*(volatile uint16_t *) (uintptr_t) (reg) = (val))
#define writew(reg, val) (*(volatile uint32_t *) (uintptr_t) (reg) = (val))
#define writed(reg, val) (*(volatile uint64_t *) (uintptr_t) (reg) = (val))

#endif // URD_KERNEL_MMIO_H_
