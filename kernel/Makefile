# SPDX-FileCopyrightText: © 2023 Alan Jian <alanjian85@outlook.com>
# SPDX-License-Identifier: GPL-3.0

OBJSDIR = $(BUILDDIR)/objs

# Every object file must be prepended with "$(OBJSDIR)/"
OBJS = \
	$(OBJSDIR)/entry.o

all: $(BUILDDIR)/kernel.elf

# Link the object files with the customized linker script and output to
# the build directory
$(BUILDDIR)/kernel.elf: kernel.ld $(OBJS)
	$(LD) -T kernel.ld $(OBJS) -o $@

$(OBJSDIR)/%.o: %.S $(OBJSDIR)
	$(CC) $< -c -o $@

$(OBJSDIR)/%.o: %.c $(OBJSDIR)
	$(CC) $< -c -o $@

# Create the directory of objects if it doesn't already exist, which is
# required to store object files
$(OBJSDIR):
	mkdir -p $(OBJSDIR)
