#include "main.h"

/**
 * print_octal - Print a unsigned octal
 * @list: Numb to print
 *
 * Return: Lngth of the numb
 **/
int print_octal(va_list list)
{
	char *p_buff;
	int size;

	p_buff = itoa(va_arg(list, unsigned int), 8);

	size = print((p_buff != NULL) ? p_buff : "NULL");

	return (size);
}