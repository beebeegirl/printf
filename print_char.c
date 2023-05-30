#include "main.h"
/**
 * print_char - print character
 * @list: va_list
 *
 * Return: 1
 */
int print_char(va_list list)
{
	int xyz;

	aux = va_arg(list, int);

	_putchar(xyz);

	return (1);
}
