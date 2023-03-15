/* Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
 * SPDX-License-Identifier: GPL-3.0 */

#include "urd/constants.h"

/* Emit the filename to the symbol table */
    .file "syscall_asm.S"

    .section .text

    .globl syscall
syscall:
/* TODO: Relax the limit of argument amount with the help of stack */
    push {r1}
    mov r1, r2
    mov r2, r3
    mov r4, r0
    pop {r0}
    svc #0

    .globl handle_svc
handle_svc:
    cmp r4, #0
    blt 1f
    cmp r4, #NR_SYSCALLS
    bge 1f
    push {r5, lr}
    ldr r5, =syscall_table
    ldr r5, [r5, r4]
    blx r5
    pop {r5, lr}
1:
    movs pc, lr
