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
CS_EXCLUDE = -path "./$(BUILD_DIR)" -prune -o
C_SOURCES = $(shell find . $(CS_EXCLUDE) -name "*.c" -print)
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
# 可选：追加加速参数（如 -enable-kvm -cpu host），由目标或命令行传入
QEMU_ACCEL ?=
# 无图形界面运行 ＋ -nographic
QEMU_FLAGS = -drive file=$(DISK_IMG),if=ide,format=raw \
             -boot c -serial mon:stdio  \
             -no-reboot -no-shutdown $(QEMU_ACCEL)

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
	$(RM) -r $(OBJ_DIR) $(KERNEL)

# 全部清理（含镜像）
.PHONY: cleanall
cleanall:
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

# 使用 KVM 加速运行（若嵌套环境不支持，QEMU 会报错或退回软件模式）
.PHONY: qemu-kvm
qemu-kvm: QEMU_ACCEL = -enable-kvm -cpu host
qemu-kvm: qemu

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
