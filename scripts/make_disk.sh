#!/usr/bin/env bash
# 生成/重建硬盘镜像 disk.img 的脚本（需要 sudo，依赖 grub-install/parted/losetup/mkfs.ext2）
# 可通过环境变量调整：DISK_IMG、DISK_SIZE_MB、MNT
# 这里不复制内核，后续由 Makefile 的 update_image 负责挂载镜像并复制 scc_kernel。

set -euo pipefail

# -------------------- 可按需调整的参数 --------------------
REPO_DIR="$(cd "$(dirname "$0")/.." && pwd)"
DISK_IMG="${DISK_IMG:-${REPO_DIR}/disk.img}"    # 镜像文件路径
DISK_SIZE_MB="${DISK_SIZE_MB:-32}"              # 镜像大小（MB），如需更大改此值
MNT="${MNT:-/mnt/kernel}"                       # 临时挂载点

# grub.cfg 内容，如需添加 initrd 或修改 menuentry，可调整这里
GRUB_CFG="$(cat <<'EOF'
set timeout=1
set default=0

menuentry "scc" {
    multiboot /scc_kernel
    # 如需加载 initrd: module /initrd
    boot
}
EOF
)"
# ---------------------------------------------------------

loopdev=""

cleanup() {
  # 卸载挂载点并释放 loop
  if mountpoint -q "$MNT"; then
    _sudo umount "$MNT"
  fi
  if [[ -n "$loopdev" ]]; then
    _sudo losetup -d "$loopdev" || true
  fi
}
trap cleanup EXIT

# sudo 包装：若设置了 SUDO_PASS，则用非交互方式；否则走默认 sudo（会提示密码）
_sudo() {
  if [[ -n "${SUDO_PASS:-}" ]]; then
    echo "$SUDO_PASS" | sudo -S "$@"
  else
    sudo "$@"
  fi
}

echo "[1/7] 创建镜像文件 ${DISK_IMG} (${DISK_SIZE_MB}MB)"
truncate -s "${DISK_SIZE_MB}M" "$DISK_IMG"

echo "[2/7] 分区表与主分区 (msdos + ext2)"
_sudo parted -s "$DISK_IMG" mklabel msdos
_sudo parted -s "$DISK_IMG" mkpart primary ext2 1MiB 100%
_sudo parted -s "$DISK_IMG" set 1 boot on

echo "[3/7] 绑定 loop 设备并格式化分区"
loopdev=$(_sudo losetup -Pf --show "$DISK_IMG")
_sudo mkfs.ext2 "${loopdev}p1"

echo "[4/7] 挂载分区并拷贝内核"
_sudo mkdir -p "$MNT"
_sudo mount "${loopdev}p1" "$MNT"
_sudo mkdir -p "$MNT/boot/grub"

echo "[5/7] 写入 grub.cfg"
echo "$GRUB_CFG" | _sudo tee "$MNT/boot/grub/grub.cfg" >/dev/null

echo "[6/7] 安装 GRUB (i386-pc) 到镜像 MBR"
_sudo grub-install --target=i386-pc --boot-directory="$MNT/boot" "$loopdev"

echo "[7/7] 清理挂载与 loop"
_sudo umount "$MNT"
_sudo losetup -d "$loopdev"
loopdev=""

echo "完成：镜像位于 $DISK_IMG"
echo "如需修改容量，请调整 DISK_SIZE_MB；如需替换内核或路径，修改 KERNEL_PATH。"
echo "启动命令示例：qemu-system-i386 -drive file=$DISK_IMG,if=ide,format=raw -boot c"
