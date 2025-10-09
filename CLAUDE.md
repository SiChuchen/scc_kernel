# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is **SCC** (Simple C Compiler? / Simple C Codebase?), an x86 32-bit operating system kernel written in C and x86 assembly. It follows GRUB Multiboot v0 specification and boots into a higher-half kernel (virtual address 0xC0100000, physical 0x100000). The kernel implements basic OS primitives: GDT/IDT setup, interrupt handling, timer, console driver, physical memory management, and debugging facilities with symbol resolution.

## Build & Run Commands

Build the kernel:
```bash
make
```

This compiles all `.c` and `.s` files and produces the `scc_kernel` ELF binary. The linker script at `scripts/kernel.ld` defines the memory layout.

Update the floppy image (requires sudo):
```bash
make update_image
```

This mounts `floppy.img`, copies `scc_kernel` into it, then unmounts. You can manually mount/unmount with `make mount_image` and `make umount_image`.

Boot in QEMU:
```bash
make qemu
```

Debug with GDB:
```bash
make debug
```

This starts QEMU paused on port 1234 and launches `cgdb` with `scripts/gdbinit` pre-loaded.

Clean build artifacts:
```bash
make clean
```

## Architecture & Memory Layout

### Higher-Half Kernel Mapping

The linker script (`scripts/kernel.ld`) places `.init.text` and `.init.data` at physical 0x100000 (1MB), then shifts all subsequent sections to virtual 0xC0100000 by adding 0xC0000000. The kernel entry point is `start` in `boot/boot.s`, which runs in the lower 1MB identity-mapped region, sets up the stack, and calls `kern_entry()` in `init/entry.c`. The kernel provides `kern_start` and `kern_end` symbols to track its memory footprint.

### Boot Flow

1. GRUB loads the kernel and passes Multiboot info pointer in `ebx`
2. `boot/boot.s` saves `ebx` to `mboot_ptr_tmp`, sets up stack, calls `kern_entry()`
3. `init/entry.c::kern_entry()` initializes subsystems in order:
   - Debug (ELF symbol parsing from Multiboot)
   - GDT (Global Descriptor Table)
   - IDT (Interrupt Descriptor Table)
   - Timer (PIT at 200Hz)
   - Physical memory manager
4. Kernel prints diagnostics and tests page allocation

### Subsystem Organization

- **boot/**: Stage-1 assembly (`boot.s`) with Multiboot header and stack setup
- **init/**: C entry point (`entry.c`) that orchestrates initialization
- **gdt/**: Global Descriptor Table setup (C + assembly)
- **idt/**: Interrupt Descriptor Table and exception handlers (C + assembly)
- **drivers/**: Hardware abstraction (console VGA text mode, PIT timer)
- **mm/**: Physical memory manager using page stack allocator
- **kernel/debug/**: Kernel panic, stack tracing with ELF symbol resolution, `printk` formatting
- **libs/**: Utility functions (`common.c` for `memcpy`/`memset`/etc, `elf.c` for symbol parsing)
- **include/**: All public headers with subsystem interfaces
- **scripts/**: Linker script (`kernel.ld`) and GDB init script

### Multiboot Integration

The kernel relies on GRUB Multiboot v0. `include/multiboot.h` defines `multiboot_t` and `mmap_entry_t` structures. The global pointer `glb_mboot_ptr` (initialized in `init/entry.c:19`) provides:

- **ELF section headers** (`num`, `size`, `addr`, `shndx`): Used by `libs/elf.c` to extract `.symtab` and `.strtab` for stack trace symbol resolution
- **Physical memory map** (`mmap_addr`, `mmap_length`): E820-style entries used by `mm/pmm.c` to discover available RAM regions (type=1)

Important: All Multiboot-provided addresses are physical. The higher-half kernel must translate or map them before access. See `docs/multiboot-notes.md` for detailed field descriptions and iteration patterns.

### Physical Memory Management

`mm/pmm.c` implements a stack-based physical page allocator:

- `init_pmm()`: Iterates Multiboot memory map, pushes all free 4KB pages above `kern_end` onto a stack
- `pmm_alloc_page()`: Pops a page from the stack
- `pmm_free_page()`: Pushes a page back

The allocator tracks total pages in `phy_page_count`. Current implementation does not yet implement virtual memory paging.

## Code Style

- **Indentation**: 4 spaces, no tabs
- **Braces**: K&R style (opening brace on same line for control structures, next line for functions)
- **Naming**: `lower_snake_case` for functions and variables, `rc_*` prefix for color enums, `*_t` suffix for typedefs
- **Header guards**: `INCLUDE_<NAME>_H_` pattern
- **Comments**: Bilingual (Chinese + English); prefer intent over mechanics

Keep subsystem-private helpers `static`. Expose public interfaces through headers in `include/`.

## Testing Strategy

No automated test suite exists. After changes:

1. Build with `make` and check for compilation errors
2. Run `make update_image` (requires sudo to mount floppy)
3. Boot with `make qemu` and observe console output
4. For deeper inspection, use `make debug` to attach GDB

Expected boot output includes:
- "init GDT / GDT successfully!"
- Kernel memory bounds and size in KB
- Physical memory map dump (from Multiboot)
- Physical page count
- Test allocations showing 4 consecutive physical addresses

## Additional Documentation

- **docs/multiboot-notes.md**: Detailed walkthrough of `multiboot_t` structure fields, usage patterns, and how the kernel extracts ELF symbols and memory map
- **docs/vargs-qa.md**: Notes on variadic argument handling
- **docs/hurlex-index.pdf**: External reference documentation

## Important Notes

- **Privileged operations**: `make update_image` requires `sudo` for loopback mounting. Always run `make umount_image` if mount fails
- **32-bit toolchain**: Kernel is compiled with `-m32` flag. Ensure your GCC and binutils support i386 target
- **Assembly syntax**: Uses NASM with Intel syntax (not AT&T)
- **Higher-half awareness**: When adding new code that accesses Multiboot data or early boot structures, remember to handle physical-to-virtual address translation
