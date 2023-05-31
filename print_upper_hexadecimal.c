#include "main.h"

int is_lowercase(char);
char *string_to_upper(char *);

/**
 * print_upper_hexadecimal - this is main block
 * Description: it prints a number in hexadecimal format
 * @list: Number to print
 * Return: Length of the number
 **/
int print_upper_hexadecimal(va_list list)
{
	char *h;
	int size;

	h = intasc(va_arg(list, unsigned int), 16);
	h = string_to_upper(h);

	size = print((h != NULL) ? h : "NULL");

	return (size);
}

/**
 * is_lowercase - another block of code
 * Description: it checks if the characters are in lowercase
 * @c: Character
 * Return: 1 or 0
 **/
int is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

/**
 * string_to_upper - another block of code
 * Description: it changes the string to uppercase
 * @s: String
 * Return: uppercase string
 **/
char *string_to_upper(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_lowercase(s[i]))
		{
			s[i] = s[i] - 32;
		}
	}

	return (s);
}
