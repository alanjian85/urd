/* Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
 * SPDX-License-Identifier: GPL-3.0 */

ENTRY(_start)

SECTIONS
{
    /* 0x81000000 is the entry's address and the start of all instructions and
     * data. */
    /* NOTE: Instead of using the value of kernel_addr_r in U-boot, 0x81000000
     * is used as the start address of the ELF file because if kernel_addr_r is
     * used, the binary image will overwrite the loaded ELF file in memory. */
    . = 0x81000000;

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
        /* Provide the start and the end of BSS to allow the entry routine to
         * clear BSS */
        PROVIDE(_bss_start = .);
        *(.bss .bss.*)
        /* Align the end to the size of registers for faster memory writing */
        . = ALIGN(4);
        PROVIDE(_bss_end = .);
    }

    /* Map to the extern variable "end" in C */
    PROVIDE(_end = .);
}
