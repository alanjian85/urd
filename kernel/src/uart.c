// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: GPL-3.0

#include "urd/uart.h"

#include <stdio.h>
#include <stdlib.h>

#include "urd/mmio.h"

#define UART_BASE (0x10000000)

#define UART_RBR (0)
#define UART_THR (0)
#define UART_IER (1)
#define UART_DLL (0)
#define UART_DLH (1)
#define UART_IIR (2)
#define UART_FCR (2)
#define UART_LCR (3)
#define UART_MCR (4)
#define UART_LSR (5)
#define UART_MSR (6)
#define UART_SCR (7)

#define UART_LSR_THRE (0x20)

#define uart_read_reg(reg)       (readw(UART_BASE + ((reg) << 2)))
#define uart_write_reg(reg, val) (writew(UART_BASE + ((reg) << 2), (val)))

int uart_init(int baud_rate) {
    if (baud_rate <= 0)
        return -1;
    uart_write_reg(UART_LCR, 0x80); // Enable DLAB
    // TODO: Investigate how to calculate the appropriate divisor
    uart_write_reg(UART_LCR, 0x00); // Disable DLAB
    uart_write_reg(UART_IER, 0x00); // Disable all interrupts
    uart_write_reg(UART_LCR, 0x03); // 8 bit mode, no parity, 1 stop bit
    uart_write_reg(UART_FCR, 0x03); // Enable and clear FIFO
    uart_write_reg(UART_MCR, 0x00); // Disable modem control
    return 0;
}

int uart_putc(char c) {
    // Wait the trasmission holding register to be empty
    while ((uart_read_reg(UART_LSR) & UART_LSR_THRE) == 0)
        ;
    uart_write_reg(UART_THR, c);
    return 0;
}
