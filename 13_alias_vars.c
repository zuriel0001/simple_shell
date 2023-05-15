#include "shell.h"

/**
 * is_chain - function that checks if the current characer is a
 * a chain deli
 * @info: structure parameter
 * @buf: the character buffer
 * @ptr: pointer to current position in the buffer
 *
 * Return: 1 or 0
 */
int is_chain(shell_info *info, char *buf, size_t *ptr)
{
	size_t i = *ptr;

	if (buf[i] == '|' && buf[i + 1] == '|')
	{
		buf[i] = 0;
		i++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[i] == '&' && buf[i + 1] == '&')
	{
		buf[i] = 0;

