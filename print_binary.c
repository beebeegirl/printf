#include "main.h"

/**
 * print_binary - this is the main block of code
 * Description: it prints a binary number
 * @list: Number to print in binary
 * Return: Length of the numbers converted
 **/
int print_binary(va_list list)
{
	char *h;
	int size;

	h = intasc(va_arg(list, unsigned int), 2);

	size = print(h);

	return (size);
}
