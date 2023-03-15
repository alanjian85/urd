// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: GPL-3.0

#include "urd/exception.h"

#include <stdint.h>
#include <stdnoreturn.h>
#include <string.h>

#include "urd/kernel.h"

extern uint32_t vector_table[8];

int exception_init(void) {
    // Write the address of the new vector table to the vector base address
    // register on system control coprocessor
    asm volatile("mcr p15, 0, %0, c12, c0, 0" : : "r"(&vector_table));
    return 0;
}

// TODO: Implement exception handlers
noreturn void reset(void) {
    halt();
}

__attribute__((interrupt("UNDEF"))) void handle_undef(void) {}

__attribute__((interrupt("ABORT"))) void handle_prefetch_abort(void) {}

__attribute__((interrupt("ABORT"))) void handle_data_abort(void) {}

__attribute__((interrupt("IRQ"))) void handle_irq(void) {}

__attribute__((interrupt("FIQ"))) void handle_fiq(void) {}
