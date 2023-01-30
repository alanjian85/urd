// SPDX-FileCopyrightText: © 2023 Alan Jian <alanjian85@outlook.com>
// SPDX-License-Identifier: GPL-3.0

#ifndef URD_KERNEL_KERNEL_H_
#define URD_KERNEL_KERNEL_H_

#define EOF (-1)

__attribute__((noreturn)) void halt(void);

int kputc(char c);
int kputs(const char *s);

#endif // URD_KERNEL_KERNEL_H_