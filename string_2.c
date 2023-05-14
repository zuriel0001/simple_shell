#include "shell.h"

/**
 * _strcpy - function that copies a string to src
 * @src: the source
 * @dest: the destination file
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _puts - a function that prints a string
 * @str: the string to be printed
 *
 * Return: void
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _strdup - a function that duplicates a string
 * @str: string to be duplicated
 *
 * Return: apointer to the duplicted string
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *dup;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
		return (NULL);
	for (len++; len--;)
	{
		dup[len] = *--str;
	}
	return (dup);
}

/**
 * _putchar - function tahat writes C character to stdout
 * @c: character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (c == FLUSH_BUFFER || j >= WRITE_BUF_SIZE)
	{
		write(1, buf, j);
		j = 0;
	}
	if (c != FLUSH_BUFFER)
		buf[i++] = c;
	return (1);
}
