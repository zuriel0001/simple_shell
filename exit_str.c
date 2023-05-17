#include "shell.h"

/**
 * _strncpy - function that copies a string
 * @dest: the destination string
 * @src: the source string
 * @n: the number of characters to be copied
 * Return: copied string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int k, m;
	char *p = dest;

	k = 0;
	while (src[k] != '\0' && k < n - 1)
	{
		dest[k] = src[k];
		k++;
	}
	if (k < n)
	{
		m = k;
		while (m < n)
		{
			dest[m] = '\0';
			m++;
		}
	}
	return (p);
}

/**
 * _strchr - function that locates a character in a string
 * @s: pointer to a string
 * @ch: the character to be searched for
 * Return: a pointer to the position of the character
 */
char *_strchr(char *s, char ch)
{
	do {
		if (*s == ch)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
 * _strncat - function that concatenates two string
 * @dest: the destination string
 * @src: the source string
 * @n: max number of bytes
 *
 * Return: the concatenanted string
 */
char *_strncat(char *dest, char *src, int n)
{
	int k, m;
	char *p = dest;

	k = 0;
	m = 0;
	while (dest[k] != '\0')
		k++;
	while (src[m] != '\0' && m < n)
	{
		dest[k] = src[m];
		k++;
		m++;
	}
	if (m < n)
		dest[k] = '\0';
	return (p);
}
