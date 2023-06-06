// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: GPL-3.0

#ifndef URD_KERNEL_SYSCALL_H_
#define URD_KERNEL_SYSCALL_H_

int syscall(int number, ...);

int syscall_init(void);

#endif // URD_KERNEL_SYSCALL_H_
