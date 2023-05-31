#include "main.h"
/**
 * print_char - this is the main block of code
 * Description: it prints character
 * @list: va_list
 * Return: 1
 */
int print_char(va_list list)
{
	char xyz;

	xyz = va_arg(list, int);

	_putchar(xyz);

	return (1);
}
