/* Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
 * SPDX-License-Identifier: GPL-3.0 */

#include "urd/constants.h"

/* Emit the filename to the symbol table */
    .file "syscall_asm.S"

    .section .text

    .globl syscall
syscall:
/* Registers r4 ~ r8 are callee-saved */
    push {r4-r8}
/* Arguments are placed in r0 ~ r6, and r7 is the system call number */
    push {r0}
    mov r0, r1
    mov r1, r2
    mov r2, r3
    pop {r7}
/* Load the argc member of the system call */
    ldr r8, =syscall_table
    add r8, #4
    ldr r8, [r8, r7, lsl #3]
/* Pull an appropriate number of arguments off from the stack */
    cmp r8, #4
    ldrhs r3, [sp, #20]
    cmp r8, #5
    ldrhs r4, [sp, #24]
    cmp r8, #6
    ldrhs r5, [sp, #28]
    cmp r8, #7
    ldrhs r6, [sp, #32]
/* Trigger software interrupt and do the system call */
    svc #0
    pop {r4-r8}
    mov pc, lr

    .globl handle_svc
handle_svc:
/* Check if the system call number is defined */
    cmp r7, #0
    blt 1f
    cmp r7, #NR_SYSCALLS
    bge 1f
    push {r8, lr}
/* Load the func member of the system call */
    ldr r8, =syscall_table
    ldr r8, [r8, r7, lsl #3]
/* Push arguments in r4 ~ r6 to comply with the calling convention */
    push {r4, r5, r6}
    blx r8
    pop {r4, r5, r6}
    pop {r8, lr}
1:
    movs pc, lr
