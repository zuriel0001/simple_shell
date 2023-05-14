#include "shell.h"

/**
* _atoi - convert string to an integer
* @s: string to be converted to integer
*
* Return: integer value of string, or
*         0 if no number is found
*/

int _atoi(char *s)
{
	int result = 0;
	int digit, sign = 1;

	while (*s != '\0')
	{
		if (*s == '-')
			sign = sign * -1;

		if (*s >= '0' && *s <= '9')
		{
			digit = *s - '0';

			/* overflow check */
			if (result > INT_MAX / 10 ||
				(result == INT_MAX / 10 && digit > INT_MAX % 10))
			{
				return (sign == 1 ? INT_MAX : INT_MIN);
			}
			result = result * 10 + digit;
		}
		if (result != 0 && (*s < '0' || *s > '9'))
		break;

		s++;
	}
	return (result * sign);
}

/**
* _isalpha - a function that checks for alphabetic characters
*
* @c: an input character to be checked
*
* Return: 1 if c is alphabetic, otherwise 0
*/

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
* is_delim - a function that  checks if character is a delimeter
*
* @c: the character to be checke
* @d_str: the delimeter string
*
* Return: 1 if its true, 0 if false
*/

int is_delim(char c, char *d_str)
{
	int i;

	for (i = 0; d_str[i] != '\0'; i++)
	{
		if (*d_str++ == c)
		{
			return (1);
		}
	}
	return (0);
}
