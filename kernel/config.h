// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: GPL-3.0

#ifndef URD_KERNEL_CONFIG_H_
#define URD_KERNEL_CONFIG_H_

#include <stdbool.h>

// The capacity of the initial stack used by the kernel
#define KERNEL_STACK_SIZE 0x1000

// Whether to output newline character with a preceding carriage return
#define UART_CRLF true

#endif // URD_KERNEL_CONFIG_H_
