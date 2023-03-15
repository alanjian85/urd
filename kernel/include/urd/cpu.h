// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: GPL-3.0

#ifndef URD_KERNEL_CPU_H_
#define URD_KERNEL_CPU_H_

static inline int disable_irq(void) {
    int mask;
    asm volatile("mrs %0, cpsr_c" : "=r"(mask));
    asm volatile("cpsid i");
    return mask;
}

static inline void restore_irq(int mask) {
    asm volatile("msr cpsr_c, %0" : : "r"(mask));
}

#endif // URD_KERNEL_CPU_H_
