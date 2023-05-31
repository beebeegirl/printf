#include "main.h"

/**
 * print_string - main block of code
 * Description: it prints string
 * @list: list.
 * Return: the string length
 */

int print_string(va_list list)
{
	char *p;
	int p_len;

	p = va_arg(list, char*);
	p_len = print((p != NULL) ? p : "(null)");

	return (p_len);
}
