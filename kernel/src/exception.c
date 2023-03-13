// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: GPL-3.0

#include "urd/exception.h"

#include <stdint.h>
#include <stdnoreturn.h>
#include <string.h>

#include "urd/kernel.h"

// TODO: Implement exception handlers
noreturn void reset(void) {
    halt();
}

__attribute__((interrupt("UNDEF"))) void handle_undef(void) {}

__attribute__((interrupt("SWI"))) void handle_svc(void) {
    kputs("System call invoked!\n");
}

__attribute__((interrupt("ABORT"))) void handle_prefetch_abort(void) {}

__attribute__((interrupt("ABORT"))) void handle_data_abort(void) {}

__attribute__((interrupt("IRQ"))) void handle_irq(void) {}

__attribute__((interrupt("FIQ"))) void handle_fiq(void) {}
