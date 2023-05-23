#include "shell.h"

/**
 * _strcat - function that concatenates two strings
 * @dest: destination buf
 * @src: source buf
 *
 * Return: the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	char *new_str;
	char *p;

	new_str = malloc(_strlen(dest) + _strlen(src) + 1);
	while (*dest)
	{
		*p++ = *dest++;
	}

	p = new_str;
	while (*src)
	{
		*p++ = *src++;
	}
	*p = '\0';

	return (new_str);
}


/**
 * start_hays_need - function that checks if needle starts with
 * haysatck
 * @needle: substring
 * @haystack: string to search
 *
 * Return: the address of the next character in the haystack
 * string or NULL
 */
char *start_hays_need(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
