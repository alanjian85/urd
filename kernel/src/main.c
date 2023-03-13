// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: GPL-3.0

#include "urd/exception.h"
#include "urd/kernel.h"
#include "urd/uart.h"

int main(void) {
    exception_init();
    uart_init(115200);
    asm volatile("svc #0");
    return 0;
}
