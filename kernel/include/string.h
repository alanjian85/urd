// Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
// SPDX-License-Identifier: GPL-3.0

#ifndef URD_KERNEL_STRING_H_
#define URD_KERNEL_STRING_H_

#include <stddef.h>

static inline void *memcpy(void *restrict dest, const void *restrict src,
                           size_t n) {
    char       *d = dest;
    const char *s = src;
    while (n--)
        *d++ = *s++;
    return d;
}

#endif // URD_KERNEL_STRING_H_
