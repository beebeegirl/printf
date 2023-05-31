#include "main.h"

/**
 * handler - main block of code
 * Description: it formats the controller
 * @str: String format
 * @list: List of arguments
 * Return: Total size of arguments with the total size of the base string
 **/
int handler(const char *str, va_list list)
{
	int size, i, xyz;

	size = 0;
	for (i = 0; str[i] != 0; i++)
	{
		if (str[i] == '%')
		{
			xyz = percent_handler(str, list, &i);
			if (xyz == -1)
				return (-1);

			size += xyz;
			continue;
		}

		_putchar(str[i]);
		size = size + 1;
	}


	return (size);
}

/**
 * percent_handler - another block of code
 * Description: it is the controller for percent format
 * @str: String format
 * @list: List of arguments
 * @i: Iterator
 * Return: Size of the numbers of elements printed
 **/
int percent_handler(const char *str, va_list list, int *i)
{
	int size, j, number_formats;
	format formats[] = {
		{'s', print_string}, {'c', print_char},
		{'d', print_integer}, {'i', print_integer},
		{'b', print_binary}, {'u', print_unsigned_integer},
		{'o', print_octal}, {'x', print_lower_hexadecimal},
		{'X', print_upper_hexadecimal}, {'p', print_pointer},
		{'r', print_reverse_string}, {'R', print_rot13},
	};

	*i = *i + 1;

	if (str[*i] == '\0')
		return (-1);

	if (str[*i] == '%')
	{
		_putchar('%');
		return (1);
	}

	number_formats = sizeof(formats) / sizeof(formats[0]);
	for (size = j = 0; j < number_formats; j++)
	{
		if (str[*i] == formats[j].type)
		{
			size = formats[j].f(list);
			return (size);
		}

	}

	_putchar('%'), _putchar(str[*i]);

	return (2);
}
