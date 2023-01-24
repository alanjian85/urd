/* SPDX-FileCopyrightText: © 2023 Alan Jian <alanjian85@outlook.com>
 * SPDX-License-Identifier: GPL-3.0 */

/* Emit the filename to the symbol table */
    .file "entry.S"

    .section .init
/* This is the entry of the kernel */
    .globl _start
_start:
/* Keep looping and outputting until a null character is encountered */
    li a7, 1
    la a1, msg
1:
    lb a0, 0(a1)
    beq a0, zero, halt
    ecall
    add a1, a1, 1
    j 1b

/* An infinite loop with interrupt waiting is used to save energy */
    .globl halt
halt:
    wfi
    j halt

    .section .data
/* Store the print message in the data section */
msg:
    .string "Hello, World!\n"
