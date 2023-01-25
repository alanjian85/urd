/* SPDX-FileCopyrightText: © 2023 Alan Jian <alanjian85@outlook.com>
 * SPDX-License-Identifier: GPL-3.0 */

#include "config.h"

/* Emit the filename to the symbol table */
    .file "entry.S"

    .section .init
/* This is the entry of the kernel */
    .globl _start
_start:
/* Setup the stack with the specified size */
    la sp, _end
    li a0, KERNEL_STACK_SIZE
    add sp, sp, a0

/* Zero-out BSS and use early return to allow empty BSS section */
    la a0, _bss_start
    la a1, _bss_end
1:
    bge a0, a1, 2f
    sd zero, 0(a0)
    add a0, a0, 8
    j 1b

/* Enter main() in main.c */
2:
    call main

/* An infinite loop with interrupt waiting is used to save energy */
    .globl halt
halt:
    wfi
    j halt
