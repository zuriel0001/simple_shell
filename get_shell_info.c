#include "shell.h"

/**
 * clear_shell_info - function that initializes shell_info structure
 * @info: address of the structure
 */
void clear_shell_info(shell_info *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_shell_info - initializes the shell_info structure
 * @info: address of structure
 * @av: argument vector
 */
void set_shell_info(shell_info *info, char **av)
{
	int k = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = stringToWords(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (k = 0; info->argv && info->argv[k]; k++)
			;
		info->argc = k;

		substitute_alias(info);
		substitute_vars(info);
	}
}

/**
 * free_shell_info - frees the fields in shell_info structure
 * @info: structure address
 * @abc: all fields
 */
void free_shell_info(shell_info *info, int abc)
{
	free_string_array(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (abc)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->my_alias)
			free_list(&(info->my_alias));
		free_string_array(info->environ);
			info->environ = NULL;
		buf_free((void **)info->cmd_buf);
		if (info->read_file > 2)
			close(info->read_file);
		_putchar(FLUSH_BUFFER);
	}
}
