// SPDX-FileCopyrightText: © 2023 Alan Jian <alanjian85@outlook.com>
// SPDX-License-Identifier: GPL-3.0

#include <stdlib.h>

#include "kernel.h"
#include "uart.h"

int main(void) {
    uart_init(115200);
    kputs("Hello, Urd!\r\n");
    return EXIT_SUCCESS;
}
