// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: GPL-3.0

#ifndef URD_KERNEL_MMIO_H_
#define URD_KERNEL_MMIO_H_

#define readb(reg) (*(volatile u8 *) (uintptr_t) (reg))
#define readh(reg) (*(volatile u16 *) (uintptr_t) (reg))
#define readw(reg) (*(volatile u32 *) (uintptr_t) (reg))
#define readd(reg) (*(volatile u64 *) (uintptr_t) (reg))

#define writeb(reg, val) (*(volatile u8 *) (uintptr_t) (reg) = (val))
#define writeh(reg, val) (*(volatile u16 *) (uintptr_t) (reg) = (val))
#define writew(reg, val) (*(volatile u32 *) (uintptr_t) (reg) = (val))
#define writed(reg, val) (*(volatile u64 *) (uintptr_t) (reg) = (val))

#endif // URD_KERNEL_MMIO_H_
