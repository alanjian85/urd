/* SPDX-FileCopyrightText: © 2023 Alan Jian <alanjian85@outlook.com>
 * SPDX-License-Identifier: GPL-3.0 */

OUTPUT_ARCH(riscv)
ENTRY(_start)

SECTIONS
{
    /* 0x80000000 is the entry's address and the start of all
     * instructions and data. */
    /* NOTE: Not the default value of "kernel_addr_r" 0x40200000 in
     * U-boot in StarFive VisionFive 2. 0x40200000 is the address of the
     * loaded ELF file. So, rather than overwriting the existing ELF image,
     * map the binary to a free region in the main memory. */
    . = 0x80000000;

    /* Ensure next section is page-aligned */
    . = ALIGN(0x1000);
    .init : {
        *(.init .init.*)
    }

    /* Ensure next section is page-aligned */
    . = ALIGN(0x1000);
    .text : {
        *(.text .text.*)
        /* Map to the extern variable "etext" in C */
        PROVIDE(_etext = .);
    }

    /* Ensure next section is page-aligned */
    . = ALIGN(0x1000);
    .rodata : {
        *(.rodata .rodata.*)
    }

    /* Ensure next section is page-aligned */
    . = ALIGN(0x1000);
    .data : {
        *(.data .data.*)
        /* Map to the extern variable "edata" in C */
        PROVIDE(_edata = .);
    }

    /* Ensure next section is page-aligned */
    . = ALIGN(0x1000);
    .bss : {
        *(.bss .bss.*)
    }

    /* Map to the extern variable "end" in C */
    PROVIDE(_end = .);
}
