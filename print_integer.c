#include "main.h"

/**
 * print_integer - this is the main block of code
 * Description: it prints a number in base 10
 * @list: the number to print in base 10
 * Return: Length of the numbers in decimal
 **/
int print_integer(va_list list)
{
	char *h;
	int size;

	h = intasc(va_arg(list, int), 10);

	size = print((h != NULL) ? h : "NULL");

	return (size);
}
