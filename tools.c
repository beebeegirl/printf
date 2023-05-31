#include "main.h"


/**
 * _strlen - block of code
 * Description: it calculates the length of a string
 * @str: string
 * Return: the length of the string
 **/
int _strlen(const char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
		;

	return (i);
}

/**
 * print - block of code
 * Description: it prints char
 * @str: string
 * Return: the string length
 */

int print(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; ++i)
		_putchar(str[i]);

	return (i);
}
