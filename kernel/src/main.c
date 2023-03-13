// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: GPL-3.0

#include "urd/kernel.h"
#include "urd/uart.h"

int main(void) {
    uart_init(115200);
    kputs("Hello, Urd!\n");
    return 0;
}
