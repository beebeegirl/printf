#include "main.h"

/**
 * get_width - main function
 * Description: Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments
 * Return: result
 */
int get_width(const char *format, int *i, va_list list)
{
	int p;
	int width = 0;

	for (p = *i + 1; format[p] != '\0'; p++)
	{
		if (is_digit(format[p]))
		{
			width *= 10;
			width += format[p] - '0';
		}
		else if (format[p] == '*')
		{
			p++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = p - 1;

	return (width);
}
