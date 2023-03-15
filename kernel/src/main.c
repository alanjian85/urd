// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: GPL-3.0

#include "urd/exception.h"
#include "urd/syscall.h"
#include "urd/uart.h"

int main(void) {
    exception_init();
    uart_init(115200);
    syscall_init();
    syscall(0, "Hello world!\n");
    return 0;
}
