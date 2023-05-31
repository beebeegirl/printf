#include "main.c"

/**
 * print_unsigned_integer - main block of code
 * Description: it prints an unsigned integer
 * @list: Number to print as inputed by user
 * Return: the Length of the number
 **/
int print_unsigned_integer(va_list list)
{
	char *h;
	int size;

	h = intasc(va_arg(list, unsigned int), 10);

	size = print((h != NULL) ? h : "NULL");

	return (size);
}
