#include "shell.h"

/**
 * recode_history - function that recodes the history linked list
 * after changes have been made
 * @infor: potential aarguments of the structure
 *
 * Return: the history count
 */
int recode_history(shell_info *info)
{
	list_t *n = info->history;
	int j = 0;

	while (n)
	{
		n->num = j++;
		n = n->next;
	}
	return (info->histcount = j);
}

/**
 * create_history_list - attach an entry to a history linked list
 * @info: structure of potential args
 * @buf: the buffer
 * @linecount: history linecount
 *
 * Return: 0
 */
int create_history_list(shell_info *info, char *buf, int linecount)
{
	list_t *n = NULL;

	if (info->history)
		n = info->history;
	add_node_end(&n, buf, linecount);

	if (!info->history)
		info->history = n;
	return (0);
}
