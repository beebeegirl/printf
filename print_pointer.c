#include "main.h"
#include <stdio.h>

int _strcmp(char *, char *);

/**
 * print_pointer - this is the main block
 * Description: it prints a number in hexadecimal format
 * @list: the number to print
 * Return: Length of number
 **/
int print_pointer(va_list list)
{
	char *h;
	int size;

	h = intasc(va_arg(list, unsigned long int), 16);

	if (!_strcmp(h, "0"))
		return (print("(nil)"));

	size = print("0x");

	if (!_strcmp(h, "-1"))
		size += print("ffffffffffffffff");
	else
		size += print(h);

	return (size);
}

/**
 * _strcmp - another block
 * Description: it compares two strings
 * @s1: Strng 1
 * @s2: Strng 2
 * Return: Int
 **/
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return (0);
}
