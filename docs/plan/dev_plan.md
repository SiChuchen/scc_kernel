# Hurlex-II Parity Development Plan

目标：在学习和迭代中，使当前内核逐步达到 Hurlex-II 同等功能水平。每个阶段都包含可验证的交付物和建议测试。

## 阶段 0：基线确认
- 目标：保证当前主分支可编译、可启动（已有硬盘镜像）。
- 交付：`make` 通过，`make qemu` 能看到定时器调度和现有线程输出。
- 测试：`make && make update_image && make qemu`（或手动 `qemu-system-i386 -drive file=disk.img,if=ide,format=raw -boot c`）。

## 阶段 1：同步原语与中断安全
- 目标：补齐原子操作、自旋锁、局部关/开中断封装，为后续并发和中断上下文代码打基础。
- 交付：
  - `atomic.h`/`spinlock.h` 等内联原语。
  - `sync.h` 的 `local_intr_store/restore` 辅助宏。
- 测试：
  - 编译通过。
  - 在时钟中断回调里使用自旋锁保护共享计数，打印结果验证不会卡死。

## 阶段 2：内存管理增强
- 目标：从简单栈式 PFA 迁移到 page_t 元数据 + 多策略物理分配器（first-fit / buddy），并引入 SLOB 内核堆；补齐 VMA 结构和页故障路径。
- 交付：
  - `page_t` 数组、zone 边界、`alloc_pages/free_pages` 接口。
  - SLOB 或等价小块分配器替换/补充现有 heap。
  - VMM 提供 `map/unmap/get_mapping`，注册 page fault handler。
- 测试：
  - 自检打印内存布局、空闲页数量。
  - 连续分配/释放页与小块，检查回收与碎片情况。
  - 触发一次人工缺页，观察 #PF 输出。

## 阶段 3：任务模型与系统调用
- 目标：拓展任务控制块（stack/mm/files/need_resched/pid 位图），完善调度与线程创建，建立 int 0x80 系统调用入口。
- 交付：
  - `task_struct` 扩展字段，`task_init`/`schedule` 使用 need_resched/链表。
  - 内核线程入口 `kthread_entry` 汇编，`do_fork` 框架。
  - 系统调用表与最小 syscall（test/exit/fork/read/write/open/close/getpid）。
- 测试：
  - 内核创建两个线程轮流打印。
  - 触发 syscall test / write，确认返回值与输出。

## 阶段 4：设备抽象与驱动
- 目标：建立字符/块设备框架，引入键盘驱动与 IDE 驱动，PIC 封装。
- 交付：
  - `char_dev`/`block_dev` 注册表，`device_init`。
  - 键盘中断读取扫描码并提供 `getchar`。
  - IDE 识别主盘，打印扇区数和描述。
  - PIC 初始化/EOI 抽象。
- 测试：
  - 启动后按键可被读取（串口/屏幕打印按键码）。
  - IDE 初始化日志正确；必要时读首扇区校验非零。

## 阶段 5：VFS 与简易文件系统
- 目标：构建 VFS 骨架与根文件系统（RAMFS），并解析 MBR；预留 SFS 挂载流程。
- 交付：
  - VFS 数据结构（super/inode/dentry/file/vfsmount）与 `add_filesystem`、基本读写打开接口骨架。
  - RAMFS 作为根挂载，MBR 解析打印分区信息。
  - SFS 框架与格式化/挂载入口（即便初期只跑初始化流程）。
- 测试：
  - 引导时打印“Init VFS/RAMFS/MBR info”。
  - 调用 `vfs_open/read/write/close` 伪实现返回预期值，确保不崩溃。

## 阶段 6：用户态与交互改进
- 目标：在内核线程中模拟用户态交互（键盘输入 + 控制台滚屏），并完善 console 功能。
- 交付：
  - `console_view_up/down` 功能，键盘方向键触发滚动。
  - `getchar` 循环演示。
- 测试：
  - 手动按键验证滚屏与字符读取。

## 阶段 7：发布与打包
- 目标：固化构建/镜像流程，增加 ISO 生成与硬盘启动双通道。
- 交付：
  - Make 目标：更新硬盘镜像、生成 ISO、QEMU 启动脚本。
- 测试：
  - `make iso` + `qemu -cdrom` 启动。
  - 硬盘镜像启动验证。

## 阶段 8：用户态与特权切换
- 目标：实现 Ring3 运行通路（用户代码段/数据段、TSS、栈切换），支持从内核创建并跳转到用户态。
- 交付：
  - 用户态段选择子与 TSS 设置，`switch_to`/`task_struct` 支持用户栈指针。
  - 用户态入口 stub（汇编）+ 简单用户程序镜像（可内嵌或从 RAMFS/SFS 读取）。
- 测试：
  - 创建用户态任务，执行一段打印/触发 syscall 的代码并返回。
  - 验证用户态触发 #PF 时能回落到内核处理。

## 阶段 9：ELF 加载与进程地址空间
- 目标：实现 ELF 装载器，为用户进程构建独立页表、用户栈和参数传递。
- 交付：
  - ELF 解析与段映射（text/data/bss），建立用户页表并切换 CR3。
  - `execve` 框架：销毁旧地址空间、加载新镜像、设置用户栈/argc/argv/envp。
- 测试：
  - 加载一个简单 ELF（如“hello”）并在用户态输出。
  - 多进程并存的页表独立性（互不干扰数据）。

## 阶段 10：系统调用完善与 libc 雏形
- 目标：补全基础 syscall 集，并提供最小 libc 包装（用户态 stub）。
- 交付：
  - 必备 syscall：`fork/execve/exit/waitpid/getpid/read/write/open/close/lseek/sbrk`（或 `brk`）/`sleep`。
  - 用户态 syscall stub（int 0x80 或后续 sysenter），简易 `libc` 头/实现。
- 测试：
  - 用户态程序链路：`fork` 后子进程 `execve` 新程序。
  - `waitpid` 能回收子进程，验证退出码。
  - `sbrk/brk` 扩展堆，简单 malloc/free 验证。

## 阶段 11：调度与进程控制增强
- 目标：完善调度器（时间片、睡眠/唤醒、僵尸回收），支持阻塞等待。
- 交付：
  - 时间片消耗与 `need_resched` 驱动的抢占。
  - 睡眠队列/定时器队列，`sleep`/`usleep` 支持。
  - 僵尸列表与 `wait` 路径，`do_exit` 清理 mm/文件表。
- 测试：
  - 多进程/线程轮转打印，时间片生效。
  - `sleep`/`waitpid` 功能测试。

## 阶段 12：IPC 与描述符机制
- 目标：实现基础进程间通信与文件描述符操作。
- 交付：
  - `pipe`/`dup`/`dup2`、阻塞读写语义。
  - 文件描述符表共享/拷贝（fork 继承），引用计数。
- 测试：
  - 管道生产者/消费者在用户态通信。
  - `dup2` 重定向 stdout 到管道，shell 将来可复用。

## 阶段 13：文件系统落地
- 目标：让 VFS + RAMFS/SFS 可读写，具备基本路径解析、缓存。
- 交付：
  - VFS 路径解析、打开/读写/关闭实现（不再是空壳）。
  - SFS 读写数据块、inode 分配、block bitmap；简易 buffer cache。
  - 设备节点挂载：将 IDE 作为 SFS 载体，或从 RAMFS 启动。
- 测试：
  - 格式化/挂载 SFS，创建/读写/删除文件。
  - 简单 `ls`/`cat` 用户程序验证路径解析与读写。

## 阶段 14：用户态 Shell
- 目标：编写最小 shell，支持内建命令与外部程序执行。
- 交付：
  - 内建命令：`cd`、`pwd`、`exit`、`help`、`ls`、`cat`。
  - 解析/执行外部程序（`fork` + `execve`），支持管道/重定向（基于 `dup2`）。
  - 简单行编辑（退格、基本快捷键）。
- 测试：
  - 交互式运行上述命令；管道 `ls | cat`、重定向 `echo > file`。

## 阶段 15：打包与回归
- 目标：形成可复现的构建/测试手册与自动化脚本。
- 交付：
  - 脚本化的构建、镜像更新、QEMU 启动、示例用户程序构建。
  - 回归测试脚本：启动 → 运行 shell 脚本执行一组命令 → 校验输出。
- 测试：
  - 一键运行回归脚本完成启动、命令序列、输出校验。

> 注：每阶段完成后保持“能编译、能启动、能看到预期日志/行为”的验证习惯，并记录测试步骤。

## 提交与里程碑要求
- 每完成一个关键阶段，生成一次 git 提交，提交信息中包含阶段编号、主要交付物和测试方式摘要。
- 不要把大体积镜像/二进制（如 `floppy.img`/`disk.img`/`scc_kernel`）纳入版本控制；仅提交源码、脚本、文档。
- 提交前执行 `make`（或相关测试命令）确保可编译可启动；在提交备注中写明已跑的命令。
