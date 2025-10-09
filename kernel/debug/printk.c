/* 内核的打印函数 */

#include "console.h"
#include "string.h"
#include "vargs.h"
#include "debug.h"

static int vsprintf(char *buff,const char *format,va_list args);

void printk(const char *format, ...)
{
    // 避免频繁创建临时变量，内核的栈很宝贵
    static char buff[1024]; // 静态缓冲区，避免频繁栈内存分配
    va_list args;           // 可变参数列表指针
    int i;                  // 用于记录写入字符数

    // 处理可变参数的核心部分

    // 根据最后一个固定参数（format）的地址，计算第一个可变参数的内存地址，并初始化 args 指针
    // 参数按从右到左顺序压栈
    va_start(args,format);          // 初始化args，使其指向format后的第一个可变参数
    
    // 将 format 字符串与 args 中的可变参数按格式符解析，写入 buff，返回写入的字符数
    i = vsprintf(buff,format,args); // 格式化字符串到缓冲区
    va_end(args);                   // 清理可变参数列表

    buff[i] = '\0';

    console_write(buff);    // 输出到内核控制台
}

void printk_color(real_color_t back,real_color_t fore,const char *format,...)
{
    // 避免频繁创建临时变量，内核的栈很宝贵
	static char buff[1024];
	va_list args;
	int i;

	va_start(args, format);
	i = vsprintf(buff, format, args);
	va_end(args);

	buff[i] = '\0';

	console_write_color(buff, back, fore);
}

// 判断是不是该字符是不是数字
#define is_digit(c)	((c) >= '0' && (c) <= '9')

// 从字符串中提取连续的数字字符，将其转换为整数，同时将指针 *s 移动到第一个非数字字符的位置
static int skip_atoi(const char **s)
{
	int i = 0;

    // 是否是数字？
	while (is_digit(**s)) {
        // 利用索引转换为数字
		i = i * 10 + *((*s)++) - '0';
	}

	return i;
}

#define ZEROPAD  1  // 用零填充（否则用空格）
#define SIGN     2  // 处理有符号数（自动添加负号）
#define PLUS     4  // 显示正数的 '+'
#define SPACE    8  // 正数用空格替代 '+'
#define LEFT    16  // 左对齐（默认右对齐）
#define SPECIAL 32  // 添加进制前缀（如 0x 或 0）
#define SMALL   64  // 小写十六进制字母

// 执行 32 位除法，返回余数，同时将商写入 n
#define do_div(n,base) ({ \
		int __res; \
		__asm__("divl %4":"=a" (n),"=d" (__res):"0" (n),"1" (0),"r" (base)); \
		__res; })


// 将整数 num 格式化为字符串，按指定进制、对齐方式、符号等规则写入缓冲区 str，返回更新后的 str 指针（指向下一个写入位置）
static char *number(char *str, int num, int base, int size, int precision, int type)
{
	char c, sign, tmp[36];
	const char *digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i;

	if (type & SMALL) {
		digits ="0123456789abcdefghijklmnopqrstuvwxyz";
	}
	if (type & LEFT) {
		type &= ~ZEROPAD;
	}
	if (base < 2 || base > 36) {
		return 0;
	}

    // 根据 num 正负和 type 标志确定符号字符（+、- 或空格）
	c = (type & ZEROPAD) ? '0' : ' ' ;

	if (type & SIGN && num < 0) {
		sign = '-';
		num = -num;
	} else {
		sign = (type&PLUS) ? '+' : ((type&SPACE) ? ' ' : 0);
	}

	if (sign) {
	      size--;
	}
    // 进制处理
	if (type & SPECIAL) {
		if (base == 16) {
			size -= 2;
		} else if (base == 8) {
			size--;
		}
	}
    // 数值转换（逆序填充 tmp）​
	i = 0;
	if (num == 0) {
		tmp[i++] = '0';
	} else {
		while (num != 0) {
			tmp[i++] = digits[do_div(num,base)];
		}
	}

    // 精度与宽度调整
	if (i > precision) { // 精度至少为数字位数
		precision = i;  
	}
	size -= precision;   // 计算剩余需要填充的宽度

    // 非零填充且右对齐时，先填充空格
	if (!(type&(ZEROPAD+LEFT))) {
		while (size-- > 0) {
			*str++ = ' ';
		}
	}
	if (sign) {
		*str++ = sign;  // 写入符号
	}
	if (type & SPECIAL) {   // 写入进制前缀
		if (base == 8) {
			*str++ = '0';
		} else if (base == 16) {
			*str++ = '0';
			*str++ = digits[33];
		}
	}
	if (!(type&LEFT)) {     // 右对齐时填充零或空格
		while (size-- > 0) {
			*str++ = c;
		}
	}
	while (i < precision--) {   // 补零至满足精度
		*str++ = '0';
	}
	while (i-- > 0) {       // 逆序写入数字
		*str++ = tmp[i];
	}
	while (size-- > 0) {    // 左对齐补空格
		*str++ = ' ';
	}

	return str;
}

// 将格式化字符串 format 与可变参数列表 args 按规则转换为字符串，写入缓冲区 buff，返回写入的字符数（不含终止符）
// buff：目标缓冲区     format：格式字符串（支持 % 格式化指令）     args：可变参数列表（通过 va_list 传递）
static int vsprintf(char *buff, const char *format, va_list args)
{
	int len;
	int i;
	char *str;
	char *s;
	int *ip;

	int flags;		// flags to number()

	int field_width;	// width of output field
	int precision;		// min. # of digits for integers; max number of chars for from string

    // 主循环遍历格式字符串​
	for (str = buff ; *format ; ++format) {
		if (*format != '%') {
			*str++ = *format;   // 非格式化字符​​：直接复制到 buff 中
			continue;
		}
		
        // 解析格式标志（Flags）
        // 支持标志​​：-（左对齐）、+（显示正号）、空格（正数空格占位）、#（特殊格式，如十六进制前缀）、0（零填充）
		flags = 0;
		repeat:
			++format;		// this also skips first '%'
			switch (*format) {
				case '-': flags |= LEFT;
					  goto repeat;
				case '+': flags |= PLUS;
					  goto repeat;
				case ' ': flags |= SPACE;
					  goto repeat;
				case '#': flags |= SPECIAL;
					  goto repeat;
				case '0': flags |= ZEROPAD;
					  goto repeat;
			}
		
		// 处理字段宽度（Field Width）​
		field_width = -1;   // -1 表示未指定
		if (is_digit(*format)) {
			field_width = skip_atoi(&format);   // 直接解析数字
		} else if (*format == '*') {
			// it's the next argument
			field_width = va_arg(args, int);    // 从参数获取宽度
			if (field_width < 0) {
				field_width = -field_width;
				flags |= LEFT;  // 负宽度视为左对齐
			}
		}

		// 处理精度（Precision）
		precision = -1;
		if (*format == '.') {
			++format;	
			if (is_digit(*format)) {
				precision = skip_atoi(&format);
			} else if (*format == '*') {
				// it's the next argument
				precision = va_arg(args, int);
			}
			if (precision < 0) {
				precision = 0;
			}
		}

		// 转换限定符（Qualifier）​
		//int qualifier = -1;	// 'h', 'l', or 'L' for integer fields
		if (*format == 'h' || *format == 'l' || *format == 'L') {
			//qualifier = *format;
			++format;
		}

        // 处理转换说明符（Conversion Specifiers）
		switch (*format) {
		case 'c':   // 字符
			if (!(flags & LEFT)) {
				while (--field_width > 0) {
					*str++ = ' ';
				}
			}
			*str++ = (unsigned char) va_arg(args, int);
			while (--field_width > 0) {
				*str++ = ' ';
			}
			break;

		case 's':   // 字符串
			s = va_arg(args, char *);
			len = strlen(s); // 计算字符串长度，后续会根据该函数判断，如果长度错误会导致整个输出错误，第一个bug错误点
			if (precision < 0) {
				precision = len;
			} else if (len > precision) {
				len = precision;
			}

			if (!(flags & LEFT)) {
				while (len < field_width--) {
					*str++ = ' ';
				}
			}
			for (i = 0; i < len; ++i) {
				*str++ = *s++;
			}
			while (len < field_width--) {
				*str++ = ' ';
			}
			break;

		case 'o':
			str = number(str, va_arg(args, unsigned long), 8,
				field_width, precision, flags);
			break;

		case 'p':
			if (field_width == -1) {
				field_width = 8;
				flags |= ZEROPAD;
			}
			str = number(str, (unsigned long) va_arg(args, void *), 16,
				field_width, precision, flags);
			break;

		case 'x':
			flags |= SMALL;
		case 'X':
			str = number(str, va_arg(args, unsigned long), 16,
				field_width, precision, flags);
			break;

		case 'd':
		case 'i':
			flags |= SIGN;
		case 'u':
			str = number(str, va_arg(args, unsigned long), 10,
				field_width, precision, flags);
			break;
		case 'b':
			str = number(str, va_arg(args, unsigned long), 2,
				field_width, precision, flags);
			break;

		case 'n':
			ip = va_arg(args, int *);
			*ip = (str - buff);
			break;

		default:
			if (*format != '%')
				*str++ = '%';
			if (*format) {
				*str++ = *format;
			} else {
				--format;
			}
			break;
		}
	}
	*str = '\0';

	return (str - buff);
}