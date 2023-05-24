#include "shell.h"

/**
 * puts_error - a function that prints a string to the standard error stream
 *
 * @str: string to be printed
 *
 */

void puts_error(char *str)
{
	int i;

	if (!str)
		return;

	for (i = 0; str[i] != '\0'; i++)
	{
		putchar_error(str[i]);
	}
}

/**
 * putchar_error - a function that writes a single character
 *                 to the standard error stream
 *
 * @c: character to be printed
 *
 * Return: 1 on sucess, otherwise -1
 */

int putchar_error(char c)
{
	static int index;
	static char buffer[WRITE_BUF_SIZE];

	if (c == FLUSH_BUFFER || index >= WRITE_BUF_SIZE)
	{
		write(2, buffer, index);
		index = 0;
	}
	if (c != FLUSH_BUFFER)
	{
		buffer[index++] = c;
	}
	return (1);
}

/**
 * atoi_overflow - a function that  converts a string to an integer
 * checks for errors and  prints a message to standard error output about it
 *
 * @str: the string to be converted to integer
 *
 * Return: The converted integer if successful, or -1 if there was an error.
 */

int atoi_overflow(char *str)
{
	int i;
	unsigned long int result = 0;

	if (*str == '+')
		str++;

	for (i = 0;  str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += (str[i] - '0');

			if (result > INT_MAX)
				return (-1);
		}
		else
		{
			return (-1);
		}
	}
	return (result);
}


/**
 * print_error - a function that prints an error message
 *
 * @info: a pointer to a structure of type shell_info
 * @str_err: the string with specified error type
 *
 */

void print_error(shell_info *info, char *str_err)
{
	puts_error(info->fname);
	puts_error(": ");
	print_dec(info->line_count, STDERR_FILENO);
	puts_error(": ");
	puts_error(info->argv[0]);
	puts_error(": ");
	puts_error(str_err);
}
