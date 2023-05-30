#include "main.h"

/**
 * print_binary - Print a binary number
 * @list: Number to print in binary
 *
 * Return: Length of the numbers converted
 **/
int print_binary(va_list list)
{
	char *p_buff;
	int size;

	p_buff = itoa(va_arg(list, unsigned int), 2);

	size = print(p_buff);

	return (size);
}
