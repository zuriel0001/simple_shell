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
