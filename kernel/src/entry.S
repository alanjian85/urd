/* Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
 * SPDX-License-Identifier: GPL-3.0 */

#include "config.h"

/* Emit the filename to the symbol table */
    .file "entry.S"

    .section .init
/* This is the entry of the kernel */
    .globl _start
_start:
/* Enter system mode */
    cps #31

/* Setup the stack with the specified size */
    ldr sp, =_end
/* KERNEL_STACK_SIZE must be a enough small value that can fit into the
 * instruction encoding */
    mov r0, #KERNEL_STACK_SIZE
    add sp, r0

/* Zero-out BSS and use early return to tolerate the existence of empty BSS section */
    ldr r0, =_bss_start
    ldr r1, =_bss_end
    mov r2, #0
1:
    cmp r0, r1
    bge 2f
    str r2, [r0]
    add r0, #4
    b 1b

/* Enter main() in main.c */
2:
    bl main

/* Hang after the main function returned */
    b halt
