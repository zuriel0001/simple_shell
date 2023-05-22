#include "shell.h"

/**
 * my_shell - main shell loop
 * @info: the structure parameter
 * @av: the argument vector
 *
 * Return: 1 on success, 0 on error
 */
int my_shell(shell_info *info, char **av)
{
	ssize_t j = 0;
	int b_ret = 0;

	while (j != -1 && b_ret != -2)
	{
		clear_shell_info(info);
		if (interactive_mode(info))
			_puts("$ ");
		putchar_error(FLUSH_BUFFER);
		j = get_input(info);
		if (j! = -1)
		{
			set_shell_info(info, av);
			b_ret = discover_builtin(info);
			if (b_ret == -1)
				discover_cmd(info);
		}
		else if (interactive_mode(info))
			_putchar('\n');
		free_shell_info(info, 0);
	}
	write_hist(info);
	free_shell_info(info, 1);
	if (!interactive_mode(info) && info->status)
		exit(info->status);
	if (b_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (b_ret);
}

/**
 * discover_builtin - function that fins a builtin command
 * @info: the structure parameter
 *
 * Return: -1, 0, 1, or 2
 */
int discover_builtin(shell_info *info)
{
	int j, b_ret = -1;
	builtin_table builtinb
