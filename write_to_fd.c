#include "shell.h"

/**
 * put_cfd - writes character c to given fd
 *
 * @c: character to be printed
 * @fd: file descriptor to write to
 *
 * Return: 1 on success otherwise -1
 */

int put_cfd(char c, int fd)
{
	static int i;
	static char buffer[WRITE_BUF_SIZE];

	if (c == FLUSH_BUFFER || i >= WRITE_BUF_SIZE)
	{
		write(fd, buffer, i);
		i = 0;
	}
	if (c != FLUSH_BUFFER)
	{
		buffer[i++] = c;
	}
	return (1);
}

/**
 * put_sfd - Prints a string to the specified file descriptor
 *
 * @str: the string to be printed
 * @fd: file descriptor to print to
 *
 * Return: the number of characters printed
 */

int put_sfd(char *str, int fd)
{
	int i;

	if (!str)
		return (0);

	while (*str)
	{
		i += put_cfd(*str++, fd);
	}
	return (i);
}

/**
 * print_dec- function prints a decimal number (base 10)
 *
 * The "print_dec" function print output to either the standard error stream
 * or to a specified file descriptor.
 * This behavior is controlled by the fd argument passed to the function
 *
 * @num: the input integer
 * @fd: the file descriptor to write to
 *
 * Return: number of characters printed
 */

int print_dec(int num, int fd)
{
	/* put_func helps print_dec to write to either stdout or stderr */
	int (*put_func)(char) = _putchar;
	int i, count = 0;
	unsigned int abs_num, current_digit;

	if (fd == STDERR_FILENO)
		put_func = putchar_error;
	if (num < 0)
	{
		abs_num = -num;
		put_func('-');
		count++;
	}
	else
		abs_num = num;

	current_digit = abs_num;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (abs_num / i)
		{
			put_func('0' + current_digit / i);
			count++;
		}
		current_digit %= i;
	}
	put_func('0' + current_digit);
	count++;

	return (count);
}
