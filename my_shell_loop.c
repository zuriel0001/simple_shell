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
	ssize_t j;
	int b_ret = 0;

	j = 0;
	while (j != -1 && b_ret != -2)
	{
		clear_shell_info(info);
		if (interactive_mode(info))
			_puts("$ ");
		putchar_error(FLUSH_BUFFER);
		j = get_input(info);
		if (j != -1)
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
		if (info->error_numb == -1)
			exit(info->status);
		exit(info->error_numb);
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
	my_builtin_table built_in_b[] = {
		{"exit", exit_shell},
		{"env", built_in_env},
		{"help", helper},
		{"history", show_history},
		{"setenv", set_my_env_var},
		{"unsetenv", unset_my_env_var},
		{"cd", _cd},
		{"alias", see_alias},
		{NULL, NULL}
	};

	for (j = 0; built_in_b[j].type; j++)
		if (_strcmp(info->argv[0], built_in_b[j].type) == 0)
		{
			info->line_count++;
			b_ret = built_in_b[j].func(info);
			break;
		}
	return (b_ret);
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
	for (j = 0, m = 0; info->arg[j]; j++)
		if (!is_delim(info->arg[j], " \t\n"))
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
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error.");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, fetch_environ(info)) == -1)
		{
			free_shell_info(info, 1);
			if (errno == EACCES)
				exit(126);
			/*exit(1); reomoved by victus..trial */
			else
			{
				/* 2 new lines below added by victus..trial */
				perror("Error executing command:");
				exit(1);
			}
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
