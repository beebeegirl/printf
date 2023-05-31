#include "main.h"

/**
 * print_octal - this is the main block of code
 * Description: it prints an unsigned octal
 * @list: the number to print
 * Return: Length of the number
 **/
int print_octal(va_list list)
{
	char *h;
	int size;

	h = intasc(va_arg(list, unsigned int), 8);

	size = print((h != NULL) ? h : "NULL");

	return (size);
}
