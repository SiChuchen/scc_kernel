# 硬盘镜像创建与测试（GRUB2 + ext2）

本文记录在本项目中使用“硬盘镜像（disk.img）”替代 `floppy.img` 的完整流程，包含创建、安装引导、复制内核与 QEMU 启动测试。所有步骤都带中文注释说明含义。

## 前置条件

- 系统已安装 `grub-install`（GRUB2）、`parted`、`losetup`、`mkfs.ext2`
- 已生成内核文件 `scc_kernel`

## 从零创建硬盘镜像

```bash
# 1) 确保挂载点干净，避免残留挂载导致写入失败
sudo umount /mnt/kernel 2>/dev/null || true

# 2) 创建一个 32MB 的硬盘镜像（大小可按需调整）
truncate -s 32M disk.img

# 3) 在镜像中创建 MBR 分区表
sudo parted -s disk.img mklabel msdos

# 4) 创建一个主分区（从 1MiB 开始，避免覆盖 MBR/对齐问题）
sudo parted -s disk.img mkpart primary ext2 1MiB 100%

# 5) 设置分区为可启动（BIOS 引导需要）
sudo parted -s disk.img set 1 boot on

# 6) 把镜像绑定到 loop 设备，并自动解析分区
#    命令会输出类似 /dev/loopX，把它保存到变量里
loopdev=$(sudo losetup -Pf --show disk.img)

# 7) 格式化分区为 ext2 文件系统
sudo mkfs.ext2 ${loopdev}p1

# 8) 挂载分区到 /mnt/kernel，准备写入文件
sudo mkdir -p /mnt/kernel
sudo mount ${loopdev}p1 /mnt/kernel

# 9) 复制内核到硬盘根目录（GRUB 配置会从这里加载）
sudo cp scc_kernel /mnt/kernel/scc_kernel

# 10) 创建 GRUB2 配置目录
sudo mkdir -p /mnt/kernel/boot/grub

# 11) 写入 GRUB2 配置（multiboot 加载内核）
sudo tee /mnt/kernel/boot/grub/grub.cfg >/dev/null <<'EOF'
set timeout=1
set default=0

menuentry "scc" {
    multiboot /scc_kernel
    boot
}
EOF

# 12) 安装 GRUB2 到镜像的 MBR（BIOS 模式）
sudo grub-install --target=i386-pc --boot-directory=/mnt/kernel/boot ${loopdev}

# 13) 卸载并释放 loop 设备
sudo umount /mnt/kernel
sudo losetup -d ${loopdev}
```

## 更新内核（无需重装 GRUB）

只要 GRUB 配置不变，更新内核只需重新挂载并覆盖 `scc_kernel`：

```bash
# 1) 绑定镜像到 loop 设备
loopdev=$(sudo losetup -Pf --show disk.img)

# 2) 挂载分区
sudo mount ${loopdev}p1 /mnt/kernel

# 3) 覆盖内核文件
sudo cp scc_kernel /mnt/kernel/scc_kernel

# 4) 卸载并释放 loop 设备
sudo umount /mnt/kernel
sudo losetup -d ${loopdev}
```

## QEMU 测试启动

```bash
# 从硬盘启动（BIOS 模式）
qemu-system-i386 -drive file=disk.img,if=ide,format=raw -boot c

# 如果需要在终端查看输出，可加 -nographic
# qemu-system-i386 -drive file=disk.img,if=ide,format=raw -boot c -nographic -serial mon:stdio
```

## 常见问题

- **看到 GRUB 菜单但内核无输出**：说明硬盘与 GRUB 正常，问题在内核本身或串口输出配置。
- **提示找不到 `scc_kernel`**：检查 `grub.cfg` 路径是否为 `/scc_kernel`，并确认文件已复制到分区根目录。
- **`grub-install` 失败**：确认 `--target=i386-pc`，并确保安装到 loop 设备（例如 `/dev/loop0`），而不是分区设备（例如 `/dev/loop0p1`）。
