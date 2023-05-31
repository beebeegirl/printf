#include "main.h"

/**
 * _putchar - main block
 * Description: it writes the char c to stdout
 * @c: The char to print
 * Return: success 1.
 * On error, -1 is returned, and errno set appropriately.
 */
int _putchar(char c)
{
	return (buffer(c));
}

/**
 * buffer - another block
 * Description: it saves char in a buffer
 * @c: Char
 * Return: 1
 **/
int buffer(char c)
{
	static char buffering[1024];
	static int i;

	if (c == -1 || i == 1024)
	{
		write(1, buffering, i);
		i = 0;
	}

	if (c != -1)
		buffering[i++] = c;

	return (1);
}
