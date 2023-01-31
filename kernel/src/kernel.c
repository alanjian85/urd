// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: GPL-3.0

#include "urd/kernel.h"

#include "urd/uart.h"

void halt(void) {
    for (;;)
        // Wait for the next interrupt to save energy
        asm("wfi");
}

int kputc(char c) {
    return uart_putc(c);
}

int kputs(const char *s) {
    for (; *s != '\0'; ++s)
        kputc(*s);
}
