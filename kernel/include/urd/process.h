// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: GPL-3.0

#ifndef URD_KERNEL_PROCESS_H_
#define URD_KERNEL_PROCESS_H_

typedef u32 pid_t;

typedef enum {
    PROC_CURR,
    PROC_SLEEP,
    PROC_READY,
} proc_state_t;

typedef struct {
    pid_t        pid;
    char         name[16];
    proc_state_t state;
    void        *stack;
    void        *stack_top;
} proc_t;

#endif // URD_KERNEL_PROCESS_H_
