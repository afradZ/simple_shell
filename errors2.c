#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: the string to print
 *
 * Return : nothing
 */

void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes the char to stderr
 * @c: the char to print
 *
 * Return: 1 on success, -1 on error and errno is appropriately set
 */
int_eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - writes the char c to fd
 * @c: char to print
 * @fd: filedescriptor
 *
 * Return: 1 on success, -1 on error and errno is appropriately set
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		BUF[i++] = c;
	return (1);
}
