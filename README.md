# Urd
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Join the chat at https://gitter.im/urd-os/community](https://badges.gitter.im/urd-os/community.svg)](https://gitter.im/urd-os/community?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
[![Build CI](https://github.com/alanjian85/urd/actions/workflows/build.yml/badge.svg)](https://github.com/alanjian85/urd/actions)

*A Unix-like and microkernel-based operating system for RISC-V*

<img src="docs/assets/dark_logo.svg" alt="Dark Logo" width="128" height="128"> <img src="docs/assets/normal_logo.svg" alt="Normal Logo" width="128" height="128"> <img src="docs/assets/light_logo.svg" alt="Light Logo" width="128" height="128">

## What is Urd?
Urd is an ecosystem that is built around a RV64 microkernel, which is designed to be Unix-like. The Urd kernel comes with its own allocator, scheduler and system calls. It also has a customized virutal memory system, device driver interface and file system. Because the kernel is only intended to run on one platform, its implementation should be fairly simple and efficient.

Urd also has its own shell, text editor, and resource monitor, among other things. However, it is not intended to create a compiler for this operating system because building software with the ported [GNU toolchain](https://en.wikipedia.org/wiki/GNU_toolchain) should be quite convenient. Some functions in [glibc](https://www.gnu.org/software/libc/) may need to be modified in order to conform to the Urd environment.

## Hardware Requirements
Urd is designed to be used in conjunction with the [StarFive VisionFive 2 single board computer](https://www.starfivetech.com/en/site/boards). It features a 64-bit SoC with the RV64GC ISA as well as up to 8GB of LPDDR4 memory. There is also a TF card slot and an on-board flash memory for firmware storage. For video output, it's integrated with the [IMG BXE-4-32 MC1 GPU](https://www.imaginationtech.com/product/img-bxe-4-32-mc1/) and a HDMI 2.0 port. The I/O peripherals are two USB 2.0 ports, two USB 3.0 ports, two RJ45 ethernet port and a 40 pin GPIO header. Although not all of the above-mentioned devices are supported by Urd, the system is tailored to this specific computer.

In order to run and test Urd, you should prepare the following items:
* A microSD Card
* A StarFive VisionFive 2 board
* A 5V DC USB-C Power Supply
* A USB to TTL UART Converter
* A RJ45 Ethernet Cable
* A HDMI Cable
* A Screen with HDMI Support

## References
* [Computer Systems: A Programmer's Perspective](https://csapp.cs.cmu.edu/)
* [Operating System Design - The Xinu Approach](https://xinu.cs.purdue.edu/)
* [Operating Systems Design and Implementation](https://en.wikipedia.org/wiki/Operating_Systems:_Design_and_Implementation)
* [Operating Systems: Three Easy Pieces](https://pages.cs.wisc.edu/~remzi/OSTEP/)
* [The RISC-V Instruction Set Manual - Volume I: Unprivileged ISA](https://riscv.org/technical/specifications/)
* [The RISC-V Instruction Set Manual - Volume II: Privileged ISA](https://riscv.org/technical/specifications/)
* [xv6: a simple, Unix-like teaching operating system](https://pdos.csail.mit.edu/6.828/2022/xv6.html)

## [License (GPL-3.0)](LICENSE)
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
