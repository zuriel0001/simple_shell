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
	int i, numSign = 1, flag = 0;
	unsigned int result = 0;
	int convertedNum;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			numSign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (numSign == -1)
	{
		convertedNum = -result;
	}
	else
		convertedNum = result;

	return (convertedNum);
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


/**
 * convert_num - convert a number to a string representation in the given base
 *
 * @num: the number to convert
 * @base: the base to use for the conversion (2-36)
 * @flags: control the conversion (CONVERT_TO _UNSIGNED, CONVERT_TO_LOWERCASE)
 *
 * The function converts a number to a string representation in the given
 * base.
 * The result is stored in a static buffer array.
 * If the number is negative and the CONVERT_TO_UNSIGNED flag
 * is not set, a minus sign is added to the beginning of the string. If the
 * CONVERT_TO_LOWERCASE flag is set, lowercase letters are used for
 * hexadecimal digits.
 *
 * Return: buffer array and a pointer to the first element of the buffer array
 */

char *convert_num(long int num, int base, int flags)
{
	static char *arr;
	static char buf[50];
	char numSign = 0;
	unsigned long n = num;
	char *p;

	if (!(flags & CONVERT_TO_UNSIGNED) && num < 0)
	{
		n = -num;
		numSign = '-';

	}
	if (flags & CONVERT_TO_LOWERCASE)
	{
		arr = "0123456789abcdef";
	}
	else
	{
		arr = "0123456789ABCDEF";
	}
	p = &buf[49];
	*p = '\0';

	while (n != 0)
	{
		--p;
		*p = arr[n % base];
		n /= base;
	}

	if (numSign)
	{
		*--p = numSign;
	}
	return (p);
}

