#include "main.h"

/**
 * print_reverse_string - main block of code
 * Description: it prints a string in reverse
 * @list: List of arguments
 * Return: the length of the string
 **/
int print_reverse_string(va_list list)
{
	int i, size;
	const char *str;

	str = va_arg(list, const char *);

	size = _strlen(str);

	for (i = size - 1; i >= 0; i--)
		_putchar(str[i]);

	return (size);
}

