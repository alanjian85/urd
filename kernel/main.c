// SPDX-FileCopyrightText: © 2023 Alan Jian <alanjian85@outlook.com>
// SPDX-License-Identifier: GPL-3.0

#define EOF (-1)

int putchar(char c) {
    // Put EID #0x01 in the register a7
    register int a7 asm("a7") = 0x01;
    // Put the character in the argument register a0
    register int a0 asm("a0") = c;
    // Invoke the system call and mark a0 as modified
    asm volatile("ecall" : "+r"(a0) : "r"(a7));
    // If any error happens, return EOF
    if (a0 < 0)
        return EOF;
    return c;
}

int puts(const char *s) {
    for (; *s != '\0'; ++s)
        putchar(*s);
}

int main(void) {
    puts("Hello, World!\n");
    return 0;
}
