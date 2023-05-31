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

	if (!str)
		str = "(null)";
	while (str[i])
		i++;
	while (i >= 0)
	{
		size += _putchar(str[i]);
		i--;
	}
	size--;
	return (size);
}

/**
	size = _strlen(str);

	for (i = size - 1; i >= 0; i--)
		_putchar(str[i]);

	return (size);
}

int count_fun = 0, i = 0;
	char *s = va_arg(args, char *);

	while (i >= 0)
	{
		count_fun += _putchar(s[i]);
		i--;
	}
	count_fun--;
	return (count_fun);
**/
