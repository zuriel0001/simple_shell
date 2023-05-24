#include "shell.h"

/**
 * interactive_mode - a dfunction tells if a the shell is in interactive mode
 *
 * @info: pointer to a structure
 *
 * Return: 1 if in interactive mode, otherwise 0
 */

int interactive_mode(shell_info *info)
{
	return (isatty(STDIN_FILENO) && info->read_file <= 2);
}
