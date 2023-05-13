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
