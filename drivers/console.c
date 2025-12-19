/* VGA 文本模式控制台驱动
 * 使用 VGA 文本模式在屏幕上显示字符
 * 屏幕分辨率：80 列 x 25 行
 * 显存地址：0xB8000
 * 每个字符占 2 字节：低字节是 ASCII 码，高字节是颜色属性
 */

#include "console.h"
#include "common.h"
#include "vmm.h"

 /*
  * VGA (Video Graphics Array) 是一种视频显示标准
  * 在默认的文本模式下，VGA 控制器保留了一块内存作为屏幕字符显示的缓冲区
  * 通过修改这块内存，可以改变屏幕上显示的字符和颜色
  */
// VGA 文本模式显存起始地址
// 在 x86 PC 中，VGA 文本模式显存映射到物理地址 0xB8000
static uint16_t *video_memory = (uint16_t *)(0xB8000 + PAGE_OFFSET);

// 屏幕光标的坐标（字符位置）
static uint8_t cursor_x = 0;	// 列（0-79）
static uint8_t cursor_y = 0;	// 行（0-24）

// 移动光标到当前 cursor_x, cursor_y 位置
// 通过 VGA 控制器端口设置硬件光标位置
static void move_cursor()
{
    // 计算光标在屏幕上的线性位置
    // 屏幕是 80 列，所以位置 = 行 * 80 + 列
    uint16_t cursorLocation = cursor_y * 80 + cursor_x;

    // VGA 控制器通过两个端口访问：
    // 0x3D4 是索引寄存器（选择要访问的内部寄存器）
    // 0x3D5 是数据寄存器（读写选中的寄存器）

    // 设置光标位置高字节
    outb(0x3D4, 14);                    // 选择寄存器 14（光标位置高字节）
    outb(0x3D5, cursorLocation >> 8);   // 写入高 8 位

    // 设置光标位置低字节
    outb(0x3D4, 15);                    // 选择寄存器 15（光标位置低字节）
    outb(0x3D5, cursorLocation);        // 写入低 8 位
}

// 清屏操作
// 用空格填充整个屏幕，并将光标移到左上角
void console_clear()
{
    // 构造颜色属性字节：黑底白字
    // 高 4 位是背景色（0=黑色），低 4 位是前景色（15=白色）
    uint8_t attribute_byte = (0 << 4) | (15 & 0x0F);

    // 构造空格字符：低字节是 ASCII 空格（0x20），高字节是颜色属性
    uint16_t blank = 0x20 | (attribute_byte << 8);

    int i;
    // 填充整个屏幕（80 列 x 25 行 = 2000 个字符）
    for (i = 0; i < 80 * 25; i++)
    {
        video_memory[i] = blank;
    }

    // 将光标移到左上角（0, 0）
    cursor_x = 0;
    cursor_y = 0;
    move_cursor();
}

// 屏幕滚动操作（向上滚动一行）
// 当光标超出屏幕底部时调用
static void scroll()
{
    // 构造颜色属性字节：黑底白字
    uint8_t attribute_byte = (0 << 4) | (15 & 0x0F);
    uint16_t blank = 0x20 | (attribute_byte << 8);

    // 当光标到达第 25 行（超出屏幕）时，需要向上滚动
    if (cursor_y >= 25)
    {
        int i;

        // 将第 1-24 行的内容向上移动一行（覆盖第 0 行）
        // 即：第 0 行 = 第 1 行，第 1 行 = 第 2 行，...
        for (i = 0 * 80; i < 24 * 80; i++)
        {
            video_memory[i] = video_memory[i + 80];
        }

        // 清空最后一行（第 24 行）
        for (i = 24 * 80; i < 25 * 80; i++)
        {
            video_memory[i] = blank;
        }

        // 将光标移到最后一行的开头
        cursor_y = 24;
    }
}

// 屏幕输出一个字符，带颜色
// c - 要输出的字符
// back - 背景色
// fore - 前景色（字符颜色）
void console_putc_color(char c, real_color_t back, real_color_t fore)
{
    uint8_t back_color = (uint8_t)back;
    uint8_t fore_color = (uint8_t)fore;

    // 构造颜色属性字节
    // 高 4 位是背景色，低 4 位是前景色
    uint8_t attribute_byte = (back_color << 4) | (fore_color & 0x0F);
    uint16_t attribute = attribute_byte << 8;

    // 处理特殊字符
    if (c == 0x08 && cursor_x)  // 退格符（Backspace）
    {
        cursor_x--;  // 光标左移一格
    }
    else if (c == 0x09)  // 制表符（Tab）
    {
        // 将光标移到下一个 8 的倍数位置
        cursor_x = (cursor_x + 8) & ~(8 - 1);
    }
    else if (c == '\r')  // 回车符（Carriage Return）
    {
        cursor_x = 0;  // 光标移到行首
    }
    else if (c == '\n')  // 换行符（Line Feed）
    {
        cursor_x = 0;   // 光标移到行首
        cursor_y++;     // 光标下移一行
    }
    else if (c >= ' ')  // 可打印字符（ASCII >= 32）
    {
        // 在当前光标位置写入字符和颜色属性
        video_memory[cursor_y * 80 + cursor_x] = c | attribute;
        cursor_x++;  // 光标右移一格
    }

    // 如果光标超出行尾，自动换行
    if (cursor_x >= 80)
    {
        cursor_x = 0;
        cursor_y++;
    }

    // 检查是否需要滚动屏幕
    scroll();

    // 更新硬件光标位置
    move_cursor();
}

// 屏幕打印一个以 \0 结尾的字符串，默认黑底白字
// cstr - 要打印的字符串
void console_write(char *cstr)
{
    while (*cstr)
    {
        console_putc_color(*cstr++, rc_black, rc_white);
    }
}

// 屏幕打印一个以 \0 结尾的字符串，带颜色
// cstr - 要打印的字符串
// back - 背景色
// fore - 前景色
void console_write_color(char *cstr, real_color_t back, real_color_t fore)
{
    while (*cstr)
    {
        console_putc_color(*cstr++, back, fore);
    }
}

// 屏幕输出一个 16 进制的整型数
// n - 要输出的数字
// back - 背景色
// fore - 前景色
void console_write_hex(uint32_t n, real_color_t back, real_color_t fore)
{
    int tmp;
    char noZeros = 1;  // 标记是否跳过前导 0

    // 先打印 "0x" 前缀
    console_write_color("0x", back, fore);

    int i;
    // 从最高的 4 位开始，每次处理 4 位（一个十六进制数字）
    for (i = 28; i >= 0; i -= 4)
    {
        tmp = (n >> i) & 0xF;  // 取出当前 4 位

        // 跳过前导 0（但至少要输出一个 0）
        if (tmp == 0 && noZeros != 0)
        {
            continue;
        }

        noZeros = 0;  // 遇到第一个非 0 数字后，不再跳过

        // 将数字转换为字符
        if (tmp >= 0xA)  // 10-15 转换为 a-f
        {
            console_putc_color(tmp - 0xA + 'a', back, fore);
        }
        else  // 0-9 转换为 '0'-'9'
        {
            console_putc_color(tmp + '0', back, fore);
        }
    }
}

// 屏幕输出一个 10 进制的整型数
// n - 要输出的数字
// back - 背景色
// fore - 前景色
void console_write_dec(uint32_t n, real_color_t back, real_color_t fore)
{
    // 特殊情况：如果是 0，直接输出
    if (n == 0)
    {
        console_putc_color('0', back, fore);
        return;
    }

    uint32_t acc = n;
    char c[32];  // 临时缓冲区，存储倒序的数字字符
    int i = 0;

    // 将数字的每一位转换为字符（倒序存储）
    while (acc > 0)
    {
        c[i] = '0' + acc % 10;  // 取出最低位
        acc /= 10;              // 去掉最低位
        i++;
    }
    c[i] = 0;  // 字符串结束符

    // 反转字符串
    char c2[32];
    c2[i--] = 0;  // 字符串结束符

    int j = 0;
    while (i >= 0)
    {
        c2[i--] = c[j++];
    }

    // 输出反转后的字符串
    console_write_color(c2, back, fore);
}
