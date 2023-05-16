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
		info->cmd_buf_type = OR_CMD;
	}
	else if (buf[i] == '&' && buf[i + 1] == '&')
	{
		buf[i] = 0;
		i++;
		info->cmd_buf_type = AND_CMD;
	}
	else if (buf[i] == ';')
	{
		buf[i] = 0;
		info->cmd_buf_type = CHAIN_CMD;
	}
	else
		return (0);
	*ptr = i;
	return (1);
}

/**
 * chain_chk - assess the latest update before deciding whether
 * we should continue with the chain of actions
 * @info: the structure parameter
 * @buf: the character buffer
 * @ptr: the address of the current posssiton in buffer
 * @j: starting position in buffer
 * @len: length of buffer
 *
 * Return: void
 */
void chain_chk(shell_info *info, char *buf, size_t *ptr, size_t j, size_t len)
{
	size_t i = *ptr;

	if (info->cmd_buf_type == AND_CMD)
	{
		if (info->status)
		{
			buf[j] = 0;
			i = len;
		}
	}
	if (info->cmd_buf_type == OR_CMD)
	{
		if (!info->status)
		{
			buf[j] = 0;
			i = len;
		}
	}
	*ptr = i;
}
