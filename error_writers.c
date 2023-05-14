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
 * @s: the string to be converted to integer
 *
 * Return: The converted integer if successful, or -1 if there was an error.
 */

int atoi_overflow(char *s)
{
	int i;
	unsigned long int convertedNumber;

	if (*s == '+')
		s++;

	i = 0;
	convertedNumber = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			convertedNumber = (convertedNumber * 10);
			convertedNumber += (s[i] - '0');

			if (convertedNumber > INT_MAX)
				return (-1);
		}
		else
		{
			return (-1);
		}
		i++;
	}

	return (convertedNumber);
}

/**
 * print_error - function that prints an error message
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
