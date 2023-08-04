// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: GPL-3.0

#include "urd/syscall.h"

#include "urd/constants.h"
#include "urd/kernel.h"

void *syscall_table[NR_SYSCALLS];

int syscall_init(void) {
    syscall_table[0] = kputs;
    return 0;
}
