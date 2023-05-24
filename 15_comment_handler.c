#include "shell.h"

/**
 * erase_comments - a function that ensure comments are not compiled
 * Description:  it replces first occurance of '#' with a '\0'
 *
 * @buf: address of the string to modify
 *
 * Return: nothing
 */

void erase_comments(char *buf)
{
	int index = 0;

	while (buf[index] != '\0')
	{
		if (buf[index] == '#' && (!index || buf[index - 1] == ' '))
		{
			buf[index] = '\0';
			break;
		}
		index++;
	}
}

