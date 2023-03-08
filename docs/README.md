# Urd
*A Unix-like and microkernel-based operating system for ARM*

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Join the chat at https://gitter.im/urd-os/community](https://badges.gitter.im/urd-os/community.svg)](https://gitter.im/urd-os/community?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
[![Build CI](https://github.com/alanjian85/urd/actions/workflows/build.yml/badge.svg)](https://github.com/alanjian85/urd/actions)

<img src="dark_logo.svg" alt="Dark Logo" width="128" height="128"> <img src="normal_logo.svg" alt="Normal Logo" width="128" height="128"> <img src="light_logo.svg" alt="Light Logo" width="128" height="128">

## What is Urd?
Urd is an ecosystem that is built around a 32-bit [ARM](https://www.arm.com/architecture/cpu) microkernel, which is designed to be [Unix-like](https://en.wikipedia.org/wiki/Unix-like). The Urd kernel comes with its own allocator, scheduler and system calls. It's also associated with a customized virutal memory system, device driver interface and file system. Because the kernel is only intended to run on one platform, its implementation should be fairly simple and efficient.

Urd also has its own shell, text editor, and resource monitor, among other things. However, it is not intended to create a dedicated compiler for this operating system because building software with the ported [GNU toolchain](https://en.wikipedia.org/wiki/GNU_toolchain) should be adequate. Some functions in [glibc](https://www.gnu.org/software/libc/) may need to be modified in order to conform to the Urd environment.

## Hardware Requirements
Urd is designed to be used in conjunction with the [BeagleBone Black](https://beagleboard.org/black). It features a ARM Cortex-A8 SoC as well as a 512MB DDR3 RAM. There is also a microSD card slot and a 4GB on-board flash memory. For video output, it's integrated with the [PowerVR SGX530 GPU](https://en.wikipedia.org/wiki/PowerVR#Series5%5C%20(SGX)) and a Micro-HDMI port. The remaining I/O peripherals are one USB 2.0 port, a RJ45 ethernet port and two 46 pin GPIO headers. Although not all of the above-mentioned devices are supported by Urd, the system is tailored to this specific single-board computer.

In order to run and test Urd, the following items should be prepared:
* A microSD Card
* A BeagleBone Black board
* A 5V DC power adapter with barrel connector
* A USB to TTL UART Converter
* A RJ45 Ethernet Cable
* A Micro-HDMI to HDMI Cable
* A Screen with HDMI Support

## Build Instructions
A cross-compiler or toolchain targeting ARMv7 is required to build Urd. [GNU Make](https://www.gnu.org/software/make/) should also be installed in order for each subsystem to be built automatically. [Git](https://git-scm.com/) is also required to retrieve the source code from the Internet.

The following commands install the dependencies on various platforms:

[Ubuntu](https://ubuntu.com/):
```sh
sudo apt-get install git make gcc-arm-none-eabi
```
[Arch Linux](https://archlinux.org/):
```sh
sudo pacman -S --needed git make arm-none-eabi-gcc
```

The repository must first be cloned, and GNU Make must be run with the cross-compiler's prefix.

```sh
git clone https://github.com/alanjian85/urd & cd urd
make CROSS_COMPILE=arm-none-eabi-
```

The output file `kernel.elf` can be found in the directory `build` alongside the directory of object files. Also, [GitHub Actions](https://github.com/features/actions) is configured to automatically compile and upload the produced `kernel.elf` for each commit. The artifact can be found by going to **Actions -> An Arbitrary Workflow -> Artifacts**.

## Code of Conduct
See [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md).

## References

### Books
* [Computer Systems: A Programmer's Perspective](https://csapp.cs.cmu.edu/)
* [Operating System Design - The Xinu Approach](https://xinu.cs.purdue.edu/)
* [Operating Systems Design and Implementation](https://en.wikipedia.org/wiki/Operating_Systems:_Design_and_Implementation)
* [Operating Systems: Three Easy Pieces](https://pages.cs.wisc.edu/~remzi/OSTEP/)
* [xv6: a simple, Unix-like teaching operating system](https://pdos.csail.mit.edu/6.828/2022/xv6.html)

### Manuals
* [AM335x and AMIC110 Sitara™ Processors Technical Reference Manual](https://www.ti.com/lit/pdf/spruh73)
* [ARM® Cortex™-A Series Programmer's Guide](https://developer.arm.com/documentation/den0013/d)

## License (GPL-3.0)
<a href="https://opensource.org/licenses/GPL-3.0" target="_blank">
<img align="right" src="https://opensource.org/trademarks/opensource/OSI-Approved-License-100x137.png">
</a>

```
                    GNU GENERAL PUBLIC LICENSE
                       Version 3, 29 June 2007

 Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.
```
