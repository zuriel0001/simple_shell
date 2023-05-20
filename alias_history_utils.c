#include "shell.h"

/**
 * show_history - function that display the command history list
 *
 * @info: pointer to a structure
 *
 *  Return: Always 0 (Success)
 */

int show_history(shell_info *info)
{
	print_list(info->history);

	return (0);
}
