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
	char *s;

	s = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (s);
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
