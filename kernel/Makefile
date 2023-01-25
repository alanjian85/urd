# SPDX-FileCopyrightText: © 2023 Alan Jian <alanjian85@outlook.com>
# SPDX-License-Identifier: GPL-3.0

# -nostdlib: Don't link to any of the standard library object files
LDFLAGS = -nostdlib
# -mcmodel=medany: With this option, the generated code can access data
#                  beyond the 32-bit address space
# -ffreestanding: Assert that compilation targets a freestanding
#                 environment
CFLAGS = -std=gnu11 -mcmodel=medany -ffreestanding

OBJSDIR = $(BUILDDIR)/objs

# Every object file must be prepended with "$(OBJSDIR)/"
OBJS = \
	$(OBJSDIR)/entry.o \
	$(OBJSDIR)/main.o

all: $(BUILDDIR)/kernel.elf

# Link the object files with the customized linker script and output to
# the build directory
$(BUILDDIR)/kernel.elf: kernel.ld $(OBJS)
	$(LD) -T kernel.ld $(OBJS) $(LDFLAGS) -o $@

$(OBJSDIR)/%.o: %.S | $(OBJSDIR)
	$(CC) $< -I $(INCDIR) $(CFLAGS) -c -o $@

$(OBJSDIR)/%.o: %.c | $(OBJSDIR)
	$(CC) $< -I $(INCDIR) $(CFLAGS) -c -o $@

# Create the directory of objects if it doesn't already exist, which is
# required to store object files
$(OBJSDIR):
	mkdir -p $(OBJSDIR)
