# SPDX-FileCopyrightText: © 2023 Alan Jian <alanjian85@outlook.com>
# SPDX-License-Identifier: GPL-3.0

# User should input a prefix of cross-compiler, e.g. make
# CROSS_COMPILE=riscv64-unknown-linux-gnu-
CC = $(CROSS_COMPILE)gcc
AS = $(CROSS_COMPILE)as
LD = $(CROSS_COMPILE)ld

SUBDIRS = kernel
# Must be absolute path
INCDIR = $(CURDIR)/include
BUILDDIR = $(CURDIR)/build

all: githooks $(SUBDIRS)

# Use a custom directory for Git hooks
githooks:
	git config core.hooksPath scripts

# Export all the defined variables to the sub-make
export
# Distinguish between filenames and target names
.PHONY: $(SUBDIRS)
$(SUBDIRS): | $(BUILDDIR)
	$(MAKE) -C $@

# Create the build directory if it doesn't already exist, which is
# required by all sub-directories
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Remove the build directory directly to clean the generated files
clean:
	rm -rf $(BUILDDIR)
