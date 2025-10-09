#!/bin/bash
# SCC 内核测试脚本
# 用于在 QEMU 中测试修复后的内核

echo "========================================="
echo "SCC 内核启动测试"
echo "========================================="
echo ""

# 检查内核文件是否存在
if [ ! -f "scc_kernel" ]; then
    echo "❌ 错误: 找不到 scc_kernel 文件"
    echo "请先运行: make clean && make"
    exit 1
fi

# 显示内核信息
echo "✅ 内核文件: scc_kernel"
ls -lh scc_kernel
echo ""

# 检查镜像文件
if [ ! -f "floppy.img" ]; then
    echo "❌ 错误: 找不到 floppy.img 文件"
    exit 1
fi

echo "✅ 镜像文件: floppy.img"
ls -lh floppy.img
echo ""

echo "========================================="
echo "启动 QEMU (GUI 模式)"
echo "========================================="
echo ""
echo "预期输出:"
echo "  1. 清屏"
echo "  2. [绿色] init GDT / IDT successfully!"
echo "  3. 内核内存布局信息"
echo "  4. BIOS 物理内存映射"
echo "  5. [红色] The Count of Physical Memory Page is: XXXXX"
echo "  6. [浅棕色] 物理页分配测试 (4次)"
echo "  7. [红色] Tick: 0, 1, 2, ... (每秒200次，快速滚动)"
echo ""
echo "按 Ctrl+Alt+2 可以切换到 QEMU 监视器"
echo "在监视器中输入 'quit' 可以退出"
echo ""
echo "启动 QEMU..."
echo ""

# 启动 QEMU (GUI 模式)
qemu-system-i386 -fda floppy.img -boot a

echo ""
echo "========================================="
echo "测试完成"
echo "========================================="
