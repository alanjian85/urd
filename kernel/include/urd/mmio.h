// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: GPL-3.0

#ifndef URD_KERNEL_MMIO_H_
#define URD_KERNEL_MMIO_H_

#include <stdint.h>

#define readb(addr) (*(volatile uint8_t *) (uintptr_t) (addr))
#define readh(addr) (*(volatile uint16_t *) (uintptr_t) (addr))
#define readw(addr) (*(volatile uint32_t *) (uintptr_t) (addr))
#define readd(addr) (*(volatile uint64_t *) (uintptr_t) (addr))

#define writeb(addr, data) (*(volatile uint8_t *) (uintptr_t) (addr) = (data))
#define writeh(addr, data) (*(volatile uint16_t *) (uintptr_t) (addr) = (data))
#define writew(addr, data) (*(volatile uint32_t *) (uintptr_t) (addr) = (data))
#define writed(addr, data) (*(volatile uint64_t *) (uintptr_t) (addr) = (data))

#endif // URD_KERNEL_MMIO_H_
