# Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
# SPDX-License-Identifier: GPL-3.0

INCDIR = include
SRCDIR = src

# -Wall: Enable all the warnings about questionable constructions
# -Wextra: Enable extra warning flags that are not enabled by -Wall
# -Werror: Make all warnings into errors
# -O3: See https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
COMMONFLAGS = -Wall -Wextra -Werror -O3
# -nostdlib: Don't link with any of the standard library object files
# -lgcc: Link with libraries containing GCC magic to compile successfully
LDFLAGS = -nostdlib -lgcc
# -std=gnu11: Comply with the GNU dialect of C11
# -mcpu=cortex-a8: Set the target CPU model to that of Beagle Bone Black
# -ffreestanding: Assert that the compilation targets a freestanding environment
CFLAGS = -std=gnu11 -mcpu=cortex-a8 -ffreestanding

# Automatic source file matching and substituting
SRCS = $(wildcard $(SRCDIR)/*.S $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.S,$(OBJSDIR)/%.o,$(SRCS))
OBJS := $(patsubst $(SRCDIR)/%.c,$(OBJSDIR)/%.o,$(OBJS))
DEPS = $(patsubst %.o,%.d,$(OBJS))

all: $(BUILDDIR)/kernel.elf

# Link the object files with the customized linker script and output to the
# build directory
$(BUILDDIR)/kernel.elf: kernel.ld $(OBJS)
	@printf " CC\t$(BUILD)/kernel.elf\n"
	@$(CC) -T kernel.ld $(OBJS) $(LDFLAGS) -o $@

$(OBJSDIR)/%.o: $(SRCDIR)/%.S
	@printf " CC\t$<\n"
	@$(CC) $< -MMD $(CFLAGS) -I . -I $(INCDIR) -c -o $@

$(OBJSDIR)/%.o: $(SRCDIR)/%.c
	@printf " CC\t$<\n"
	@$(CC) $< -MMD $(CFLAGS) -I . -I $(INCDIR) -c -o $@

# Use header dependency files generated by compiler
-include $(DEPS)
