#include "main.h"
/*
 * print_char - main function
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Description: it prints a char
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	char t = va_arg(types, int);

	return (handle_write_char(t, buffer, flags, width, precision, size));
}

/*
 * print_string - Another function
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Description: it prints a string
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int length = 0, r;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (r = width - length; r > 0; r--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (r = width - length; r > 0; r--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}
/*
 * print_percent - Another function
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Description: this prints a percent sign
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/*
 * print_int - another function
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Description: this prints an int
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int r = BUFF_SIZE - 2;
	int is_negative = 0;
	long int e = va_arg(types, long int);
	unsigned long int num;

	e = convert_size_number(e, size);

	if (e == 0)
		buffer[r--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)e;
	if (e < 0)
	{
		num = (unsigned long int)((-1) * e);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[r--] = (num % 10) + '0';
		num /= 10;
	}
	r++;
	return (write_number(is_negative, r, buffer, flags, width, precision, size));
}
/*
 * print_binary - another function
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Description: this prints an unsigned number
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	unsigned int e, o, r, sum;
	unsigned int z[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	e = va_arg(types, unsigned int);
	o = 2147483648; /* (2 ^ 31) */
	z[0] = e / o;

	for (r = 1; r < 32; r++)
	{
		o /= 2;
		z[r] = (e / o) % 2;
	}
	for (r = 0, sum = 0, count = 0; r < 32; r++)
	{
		sum += z[r];
		if (sum || r == 31)
		{
			char p = '0' + z[r];

			write(1, &p, 1);
			count++;
		}
	}
	return (count);
}
