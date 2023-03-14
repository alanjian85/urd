/* Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
 * SPDX-License-Identifier: GPL-3.0 */

/* Emit the filename to the symbol table */
    .file "exception_asm.S"

    .section .text

    .globl vector_table
    /* Since the vector table won't be copied to another address in memory,
     * using relative branch here is safe */
vector_table:
    b reset
    b handle_undef
    b handle_svc
    b handle_prefetch_abort
    b handle_data_abort
    nop
    b handle_irq
    b handle_fiq
