# SCC 内核真正问题分析与修复

## 问题现象

内核启动后显示 multiboot 信息，然后黑屏挂起，无任何输出。

## 根本原因

**SCC 项目的链接脚本配置为"高半内核"（Higher-Half Kernel），但代码没有实现分页机制，导致内核无法正常运行。**

## 详细分析

### 1. 高半内核 vs 平坦内核

#### 平坦内核 (Chapt9)
```
物理地址 = 虚拟地址
代码段：0x100000 (1MB)
数据段：0x100000+
不需要分页
```

#### 高半内核 (Chapt10, SCC当前配置)
```
物理地址：0x100000 (1MB)
虚拟地址：0xC0100000 (3GB+1MB)
需要分页机制将虚拟地址映射到物理地址
```

### 2. SCC 当前的链接脚本 (`scripts/kernel.ld`)

```ld
PROVIDE( kern_start = 0xC0100000);  // 虚拟地址
. = 0x100000;                        // 物理地址
.init.text : { *(.init.text) }       // boot代码在物理地址
.init.data : { *(.init.data) }       // boot数据在物理地址

. += 0xC0000000;                     // 虚拟地址 += 3GB
.text : AT(ADDR(.text) - 0xC0000000) // 代码段虚拟地址，物理地址-3GB
```

**含义：**
- Boot 代码（`.init.text`）在物理地址 `0x100000`
- 内核代码（`.text`）虚拟地址 `0xC0102000`，物理地址 `0x102000`
- 需要页表将 `0xC0102000` 映射到 `0x102000`

### 3. 实际执行流程

```
1. GRUB 加载内核到物理地址 0x100000
2. 跳转到 start (物理地址 0x10000C)
3. start 执行:
   100020: call c01039d1 <kern_entry>  // ❌ 调用虚拟地址!
4. CPU 将 0xC01039D1 当作物理地址访问
5. 访问超出物理内存范围或访问到错误内存
6. 系统崩溃/挂起
```

**关键代码：**
```asm
; boot.s 中 (物理地址 0x100020)
call kern_entry  // 链接器解析为: call 0xC01039D1
```

**问题：**
- CPU 在实模式/保护模式下，未开启分页时，所有地址都是物理地址
- `call 0xC01039D1` 尝试访问物理地址 `0xC01039D1` (>3GB)
- 但物理内存只有几百MB，访问失败

### 4. 符号地址验证

```bash
$ nm scc_kernel | grep -E "start|kern_entry|kern_end|glb_mboot"
00101400 T mboot_ptr_tmp      # 物理地址 (在 .init.data)
0010000c T start               # 物理地址 (在 .init.text)
c0100000 A kern_start          # 虚拟地址 (链接脚本定义)
c01039d1 T kern_entry          # 虚拟地址 (在 .text)
c0186848 B glb_mboot_ptr       # 虚拟地址 (在 .bss)
c018f000 R kern_end            # 虚拟地址 (链接脚本定义)
```

**观察：**
- `start` 和 `mboot_ptr_tmp` 在物理地址空间
- `kern_entry` 和 `glb_mboot_ptr` 在虚拟地址空间 (0xC0000000+)
- 从物理地址调用虚拟地址 → 崩溃

### 5. Chapt9 vs Chapt10

#### Chapt9 (工作正常)
- 链接脚本：平坦布局，所有代码在 `0x100000+`
- 无需分页
- `call kern_entry` → `call 0x100xxx` (物理地址)

#### Chapt10 (需要分页支持)
- 链接脚本：高半布局，代码在 `0xC0100000+` (虚拟)
- **boot.s 中包含页表初始化代码**
- 在调用 `kern_entry` 前开启分页
- `call kern_entry` → `call 0xC0100xxx` (虚拟地址，通过页表映射到物理地址)

#### SCC (配置不匹配)
- 链接脚本：高半布局 (来自 chapt10)
- Boot代码：**没有页表初始化** (来自 chapt9)
- 结果：❌ **崩溃**

## 修复方案

### 方案 1: 改用平坦内核布局 (推荐) ⭐⭐⭐⭐⭐

**优点：**
- 简单，只需修改链接脚本
- 与 chapt9 教程代码一致
- 无需实现分页机制

**步骤：**
1. 用 chapt9 的 `kernel.ld` 替换当前的
2. 重新编译

**具体操作：**
```bash
cp /home/xz/xv6/hurlex/hurlex-doc/code/chapt9/scripts/kernel.ld \
   /home/xz/xv6/hurlex/scc/scripts/kernel.ld
make clean && make
```

### 方案 2: 实现完整的高半内核 (复杂) ⭐⭐

**优点：**
- 学习分页机制
- 高半内核更符合现代OS设计

**步骤：**
1. 从 chapt10 复制 boot.s (包含页表初始化)
2. 从 chapt10 复制 vmm.c/vmm.h (虚拟内存管理)
3. 修改所有相关代码支持虚拟地址
4. 需要深入理解分页机制

**具体操作：**
```bash
# 复制 chapt10 的关键文件
cp /home/xz/xv6/hurlex/hurlex-doc/code/chapt10/boot/boot.s \
   /home/xz/xv6/hurlex/scc/boot/boot.s
cp /home/xz/xv6/hurlex/hurlex-doc/code/chapt10/mm/vmm.* \
   /home/xz/xv6/hurlex/scc/mm/
# ... 还需要更多修改
```

## 推荐方案：方案 1

因为：
1. SCC 项目对应 chapt9，应该使用平坦内核
2. 高半内核是 chapt10 的内容
3. 简单快速，立即可以验证修复

## 执行修复

让我们执行方案 1：
