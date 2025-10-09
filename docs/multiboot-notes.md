# Multiboot 信息结构 `multiboot_t` 详解（学习笔记）

参考实现：`include/multiboot.h:19` 定义了 GRUB Multiboot（v0）在进入 32 位内核时提供的系统信息结构体。该结构体中的大多数字段是否有效由 `flags` 位指示。

## 基础与总体规则
- `flags`（`multiboot_t::flags`，`include/multiboot.h:20`）按位告知哪些字段有效：
  - bit0：`mem_lower/mem_upper` 有效
  - bit1：`boot_device` 有效
  - bit2：`cmdline` 有效
  - bit3：`mods_count/mods_addr` 有效
  - bit5：ELF section 头信息有效（`num/size/addr/shndx`）；bit4 则对应 a.out 符号表（本项目未用）
  - bit6：内存映射 `mmap_*` 有效
  - bit7：磁盘驱动器信息 `drives_*` 有效
  - bit8：`config_table` 有效
  - bit9：`boot_loader_name` 有效
  - bit10：`apm_table` 有效
  - bit11：VBE 字段有效（`vbe_*`）
- 地址语义：Multiboot 提供的地址通常是物理地址。高半内核需映射后才能以内核虚拟地址访问。
- 结构体使用 `__attribute__((packed))` 避免编译器填充字节，严格匹配引导器布局。

## 字段分组与用途
- 基本内存信息（bit0）
  - `mem_lower`、`mem_upper`（`include/multiboot.h:29-30`）：以 KB 计的低/高端内存容量，粗粒度估计。
- 引导设备与命令行（bit1/bit2）
  - `boot_device`（:32）：BIOS 磁盘设备编码。
  - `cmdline`（:33）：内核命令行 C 字符串的物理地址。
- 模块信息（bit3）
  - `mods_count`、`mods_addr`（:34-35）：initrd 等附加模块表。
- ELF 符号查找（bit5）
  - `num/size/addr/shndx`（:42-45）：ELF section 头表参数。本仓库据此提取 `.symtab/.strtab` 并完成符号解析（见 `libs/elf.c:8`）。
- 物理内存映射（bit6）
  - `mmap_length`、`mmap_addr`（:52-53）：E820 形式的可变长表，元素类型为 `mmap_entry_t`（:75-82）。
  - 迭代正确方式（根据 `size` 跳转）：
    ```c
    mmap_entry_t *m = (void*)mb->mmap_addr;
    while ((uint32_t)m < mb->mmap_addr + mb->mmap_length) {
        // 使用 m->type 判断是否可用 (1 = RAM)
        m = (mmap_entry_t*)((uint32_t)m + m->size + sizeof(m->size));
    }
    ```
    注：仓库当前简单按固定结构步进，实际应参考 `size` 以保证兼容性。
- 其他可选信息（bit7 及以后）
  - `drives_*`（:55-56）：磁盘几何信息。
  - `config_table`（:57）：ROM 配置表。
  - `boot_loader_name`（:58）：引导器名称字符串。
  - `apm_table`（:59）：APM 信息。
  - `vbe_*`（:60-65）：VESA BIOS 扩展视频信息。

## 本仓库中的用法与示例
- 全局指针
  - 声明：`include/multiboot.h:86` `extern multiboot_t *glb_mboot_ptr;`
  - 定义并初始化：`init/entry.c:14-19`（由 `boot/boot.s` 传入的 `mboot_ptr_tmp` 设置）
- ELF 符号获取
  - `libs/elf.c:8-17` 通过 `num/size/addr/shndx` 构造 `elf_t`，用于 `debug.c` 的栈回溯符号名解析。
- 物理内存拓扑
  - `mm/pmm.c:18-21,35-41` 使用 `mmap_*` 枚举类型为 1 的可用区域，并将页框推入物理页栈。

## ELF 与 Multiboot 的关系

### 问题：ELF 格式与 Multiboot 信息结构是什么关系？

**简答**：GRUB 在加载 ELF 格式的内核时，会解析内核的 ELF section header table，并通过 Multiboot 信息结构的 `num/size/addr/shndx` 字段将这些元数据传递给内核，使内核能够在运行时访问自己的符号表和字符串表，从而实现符号解析（例如栈回溯时显示函数名）。

### 详细解释

1. **ELF 格式内核的编译产物**
   - 本项目编译生成的 `scc_kernel` 是一个 ELF（Executable and Linkable Format）格式的可执行文件
   - ELF 文件包含多个 section（节），常见的有：
     - `.text`：代码段
     - `.data`：已初始化数据
     - `.bss`：未初始化数据
     - `.symtab`：符号表（包含函数名、变量名等符号信息）
     - `.strtab`：字符串表（存储符号名称的实际字符串）
     - `.shstrtab`：section 名称字符串表
   - 这些 section 的元数据保存在 **section header table** 中

2. **GRUB 的 ELF 加载过程**
   - GRUB 检测到内核是 ELF 格式后，会解析 ELF header 和 section header table
   - GRUB 将内核的各个 section 加载到内存中的对应物理地址（根据 linker script `scripts/kernel.ld` 的定义）
   - **关键**：GRUB 将 section header table 的信息通过 Multiboot 信息结构传递给内核

3. **Multiboot 信息结构中的 ELF 字段**（`include/multiboot.h:42-45`）
   ```c
   uint32_t num;    // section header 的数量
   uint32_t size;   // 每个 section header 的大小（字节）
   uint32_t addr;   // section header table 的物理地址
   uint32_t shndx;  // section 名称字符串表的索引（指向 .shstrtab）
   ```
   - 这些字段仅在 `flags` 的 bit5 被设置时有效
   - `addr` 指向的是已加载到内存中的 section header table 数组

4. **内核如何使用这些信息**
   - **符号解析初始化**（`kernel/debug/debug.c:9-14`）：
     ```c
     void init_debug() {
         kernel_elf = elf_from_multiboot(glb_mboot_ptr);
     }
     ```
   - **提取符号表和字符串表**（`libs/elf.c:8-29`）：
     - 从 `multiboot_t->addr` 获取 section header table
     - 从 `multiboot_t->shndx` 获取 `.shstrtab` 的地址
     - 遍历所有 section header，找到名为 `.symtab` 和 `.strtab` 的 section
     - 将它们的地址和大小保存到 `elf_t` 结构中
   - **符号查找**（`libs/elf.c:32-47`）：
     - `elf_lookup_symbol()` 函数通过地址在符号表中查找对应的函数名
     - 在栈回溯时（`kernel/debug/debug.c:49-59`），将返回地址转换为可读的函数名

5. **实际应用场景**
   - **Panic 栈回溯**：当内核发生致命错误调用 `panic()` 时，会打印调用栈，每个地址旁边显示对应的函数名
   - **调试信息**：通过 GDB 调试时，符号信息帮助开发者理解代码执行位置
   - **示例输出**：
     ```
     *** System panic: test
        [0xc0100abc] kern_entry
        [0xc0100def] some_function
        [0xc0100123] another_function
     ```

### 数据流总结

```
编译链接                GRUB 加载              内核初始化             符号查找
┌─────────┐          ┌──────────┐          ┌──────────┐          ┌──────────┐
│ ELF     │          │ Section  │          │ init_    │          │ Stack    │
│ Kernel  │  ──────> │ Header   │  ──────> │ debug()  │  ──────> │ Trace    │
│ (.symtab│          │ Table in │          │          │          │ with     │
│  .strtab│          │ Memory   │          │ Extract  │          │ Function │
│  etc.)  │          │          │          │ .symtab  │          │ Names    │
└─────────┘          └──────────┘          │ .strtab  │          └──────────┘
                            │               └──────────┘
                            │                     ▲
                            └─────────────────────┘
                          Multiboot->num/size/addr/shndx
```

### 关键要点
- **ELF 是内核的文件格式**，包含代码、数据和元数据（符号表）
- **Multiboot 是 GRUB 与内核的通信协议**，将 ELF 元数据传递给内核
- **符号表使内核具有"自省"能力**，可以在运行时将地址转换为符号名
- 本项目中，ELF section headers 通过 Multiboot 字段传递，专门用于调试功能（栈回溯）

## 常见注意事项
- Multiboot 提供的是"物理地址"。高半内核需做 `phys → virt` 转换或建立 1:1 映射后再访问。
- 迭代 `mmap` 时务必按 `size` 前进，避免因引导器结构差异产生越界。
- 只有当 `flags` 相应位被置位时，相关字段才可读；否则内容未定义。
- ELF section header table 地址（`multiboot_t->addr`）是物理地址，本项目因高半内核映射，在 `libs/elf.c` 中直接使用时需确保地址已正确映射。

