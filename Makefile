# #!Makefile
# #
# # --------------------------------------------------------
# #
# #    hurlex 这个小内核的 Makefile
# #    默认使用的C语言编译器是 GCC、汇编语言编译器是 nasm
# #
# # --------------------------------------------------------
# #

# # patsubst 处理所有在 C_SOURCES 字列中的字（一列文件名），如果它的 结尾是 '.c'，就用 '.o' 把 '.c' 取代
# C_SOURCES = $(shell find . -name "*.c")
# C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))
# S_SOURCES = $(shell find . -name "*.s")
# S_OBJECTS = $(patsubst %.s, %.o, $(S_SOURCES))

# CC = gcc
# LD = ld
# ASM = nasm

# C_FLAGS = -c -Wall -m32 -ggdb -gstabs+ -nostdinc -fno-pic  -fno-builtin -fno-stack-protector -I include
# LD_FLAGS = -T scripts/kernel.ld -m elf_i386 -nostdlib
# ASM_FLAGS = -f elf -g -F stabs

# all: $(S_OBJECTS) $(C_OBJECTS) link update_image

# # The automatic variable `$<' is just the first prerequisite
# .c.o:
# 	@echo 编译代码文件 $< ...
# 	$(CC) $(C_FLAGS) $< -o $@

# .s.o:
# 	@echo 编译汇编文件 $< ...
# 	$(ASM) $(ASM_FLAGS) $<

# link:
# 	@echo 链接内核文件...
# 	$(LD) $(LD_FLAGS) $(S_OBJECTS) $(C_OBJECTS) -o scc_kernel

# .PHONY:clean
# clean:
# 	$(RM) $(S_OBJECTS) $(C_OBJECTS) scc_kernel

# .PHONY:update_image
# update_image:
# 	sudo mount floppy.img /mnt/kernel
# 	sudo cp scc_kernel /mnt/kernel/scc_kernel
# 	sleep 1
# 	sudo umount /mnt/kernel

# .PHONY:mount_image
# mount_image:
# 	sudo mount floppy.img /mnt/kernel

# .PHONY:umount_image
# umount_image:
# 	sudo umount /mnt/kernel

# .PHONY:qemu
# qemu:
# 	qemu -fda floppy.img -boot a

# .PHONY:bochs
# bochs:
# 	bochs -f scripts/bochsrc.txt

# .PHONY:debug
# debug:
# 	qemu -S -s -fda floppy.img -boot a &
# 	sleep 1
# 	cgdb -x scripts/gdbinit

#!Makefile
#
# --------------------------------------------------------
#    默认使用的 C 语言编译器是 GCC、汇编语言编译器是 nasm
# --------------------------------------------------------
#

# 构建输出目录（所有编译产物集中到 _build 目录，避免污染源码树）
BUILD_DIR := _build
OBJ_DIR   := $(BUILD_DIR)/obj

# 自动收集所有 .c / .s 源文件，排除 _build
C_SOURCES = $(shell find . -path "./$(BUILD_DIR)" -prune -o -name "*.c" -print)
S_SOURCES = $(shell find . -path "./$(BUILD_DIR)" -prune -o -name "*.s" -print)

# 将源码路径映射到 _build/obj 下的对应 .o
C_OBJECTS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(C_SOURCES))
S_OBJECTS = $(patsubst %.s,$(OBJ_DIR)/%.o,$(S_SOURCES))

# 最终内核/镜像放到 _build
KERNEL    := $(BUILD_DIR)/scc_kernel

CC  = gcc
LD  = ld
ASM = nasm

# C 编译选项：
# - 保留 frame pointer，方便用 EBP 做栈回溯
# - 32 位、带调试信息
# 必须有 -fno-pic，不然会生成位置无关的代码
C_FLAGS = -c -Wall -m32 -ggdb -gstabs+ -nostdinc \
          -fno-builtin -fno-stack-protector -fno-pic \
          -fno-omit-frame-pointer -fno-optimize-sibling-calls \
          -I include

LD_FLAGS  = -T scripts/kernel.ld -m elf_i386 -nostdlib
ASM_FLAGS = -f elf -g -F stabs

# 统一的 QEMU 配置（32 位内核，使用 disk.img 启动）
QEMU       = qemu-system-i386
DISK_IMG   = $(BUILD_DIR)/disk.img
# 无图形界面运行 ＋ -nographic
QEMU_FLAGS = -drive file=$(DISK_IMG),if=ide,format=raw \
             -boot c -serial mon:stdio  \
             -no-reboot -no-shutdown

all: $(KERNEL) update_image

# C/Asm 统一规则，自动创建目标目录
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@echo 编译代码文件 $< ...
	$(CC) $(C_FLAGS) $< -o $@

$(OBJ_DIR)/%.o: %.s
	@mkdir -p $(@D)
	@echo 编译汇编文件 $< ...
	$(ASM) $(ASM_FLAGS) $< -o $@

$(KERNEL): $(S_OBJECTS) $(C_OBJECTS)
	@mkdir -p $(BUILD_DIR)
	@echo 链接内核文件...
	$(LD) $(LD_FLAGS) $(S_OBJECTS) $(C_OBJECTS) -o $@

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

.PHONY: update_image
update_image: $(DISK_IMG) $(KERNEL)
	sudo mkdir -p /mnt/kernel
	@set -e; \
	loopdev=$$(sudo losetup -Pf --show $(DISK_IMG)); \
	sudo mount $${loopdev}p1 /mnt/kernel; \
	sudo cp $(KERNEL) /mnt/kernel/scc_kernel; \
	sudo umount /mnt/kernel; \
	sudo losetup -d $${loopdev}

# 如果镜像不存在，调用脚本创建；如需自定义大小，可在命令行传入 DISK_SIZE_MB=64
$(DISK_IMG):
	DISK_IMG=$(DISK_IMG) ./scripts/make_disk.sh

.PHONY: mount_image
mount_image:
	sudo mkdir -p /mnt/kernel
	@set -e; \
	loopdev=$$(sudo losetup -Pf --show $(DISK_IMG)); \
	sudo mount $${loopdev}p1 /mnt/kernel

.PHONY: umount_image
umount_image:
	@set -e; \
	loopdev=$$(sudo losetup -j $(DISK_IMG) | cut -d: -f1 | head -n1); \
	if [ -n "$$loopdev" ]; then sudo umount /mnt/kernel; sudo losetup -d $$loopdev; fi

.PHONY: qemu
qemu: all
	@echo 启动 QEMU（终端模式）...
	$(QEMU) $(QEMU_FLAGS)

.PHONY: bochs
bochs:
	bochs -f scripts/bochsrc.txt

.PHONY: debug
debug: all
	@echo 启动 QEMU 调试会话（-S -s）...
	$(QEMU) -S -s $(QEMU_FLAGS) &
	sleep 1
	@echo 启动 cgdb，使用 scripts/gdbinit 连接到 QEMU...
	cgdb -x scripts/gdbinit
