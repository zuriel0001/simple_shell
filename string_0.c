#include "shell.h"

/**
 * _strlen - function that returns the length of a string
 * @s: string whose length is to be determined
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
	{
		i++;
	}
	return (i);
}

/**
 * _strcmp - a function that compares two strings
 * @s1: the first string
 * @s2: the second sring
 *
 * Return: negative if s1 is less than s2, positive if
 * s1 is greater than s2, or zero if s1 = s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

