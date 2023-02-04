# Copyright (C) 2023 Alan Jian (alanjian85@outlook.com)
# SPDX-License-Identifier: GPL-3.0

# User should input a prefix of cross-compiler, e.g. make
# CROSS_COMPILE=riscv64-unknown-linux-gnu-
CC = $(CROSS_COMPILE)gcc
AS = $(CROSS_COMPILE)as
LD = $(CROSS_COMPILE)ld

BUILD = build
OBJS = $(BUILD)/objs
# Must be absolute path
BUILDDIR = $(CURDIR)/$(BUILD)
OBJSDIR = $(CURDIR)/$(OBJS)

SUBDIRS = kernel

all: githooks $(SUBDIRS)

# Use a custom directory for Git hooks
githooks:
	@git config core.hooksPath scripts

# Generate the documentation page using Doxygen
.PHONY: docs
docs:
	@printf " DOXYGEN\n"
	@doxygen

# Export all the defined variables to the sub-make
export
# Distinguish between filenames and target names
.PHONY: $(SUBDIRS)
$(SUBDIRS): | $(BUILDDIR)
	@$(MAKE) -C $@

# Create the build directory if it doesn't already exist, which is required by
# all sub-directories
$(BUILDDIR):
	@printf " MKDIR\t$(BUILD)\n"
	@mkdir -p $(BUILDDIR)
	@printf " MKDIR\t$(OBJS)\n"
	@mkdir -p $(OBJSDIR)

# Remove the build directory directly to clean the generated files
clean:
	@printf " RM\t$(BUILD)\n"
	@rm -rf $(BUILDDIR)
	@printf " RM\thtml\n"
	@rm -rf html
	@printf " RM\tlatex\n"
	@rm -rf latex
