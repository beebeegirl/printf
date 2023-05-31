#include "main.h"

/**
 * print_lower_hexadecimal - this is the main block
 * Description: it prints a number in hexadecimal format
 * @list: Number to print
 * Return: Length of the number
 **/
int print_lower_hexadecimal(va_list list)
{
	char *h;
	int size;

	h = intasc(va_arg(list, unsigned int), 16);

	size = print((h != NULL) ? h : "NULL");

	return (size);
}
