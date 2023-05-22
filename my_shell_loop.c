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













}

/**
 * discover_cmd - function that finds a command in path
 * @info: the structure parameter
 *
 * Return: void
 */
void discover_cmd(shell_info *info)
{
	char *path = NULL;
	int j, m;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (j = 0, m = 0; info->arg[j]; i++)
		if(!is_delim(info->arg[j], "\t\n"))
			m++;
	if (!m)
		return;
	path = path_finder(info, get_env_var(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_shell_cmd(info);
	}
	else
	{
		if ((interactive_mode(info) || get_env_var(info, "PATH=")
					|| info->argv[0][0] == '/')
				&& is_regular_file(info, info->argv[0]))
			fork_shell_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_shell_cmd - function that forks an executable thread to run cmd
 * @info: the structre parameter
 *
 * Return: void
 */
void fork_shell_cmd(shell_info *info)
{
	pid_t 



