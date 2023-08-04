// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: GPL-3.0

#include "urd/syscall.h"

#include "urd/constants.h"
#include "urd/kernel.h"

typedef struct {
    void *func;
    // The number of the arguments of a system call shall not be greater than 7
    int   argc;
} syscall_t;

syscall_t syscall_table[NR_SYSCALLS];

int syscall_init(void) {
    // Whenever a new system call is added, the macro NR_SYSCALLS in
    // include/urd/constants.h should also be updated
    syscall_table[0].func = kputs;
    syscall_table[0].argc = 1;
    return 0;
}
