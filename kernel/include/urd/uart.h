// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: GPL-3.0

#ifndef URD_KERNEL_UART_H_
#define URD_KERNEL_UART_H_

int uart_init(int baud_rate);

int uart_putc(char c);

#endif // URD_KERNEL_UART_H_
