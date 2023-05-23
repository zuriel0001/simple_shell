#include "shell.h"

/**
 * _cd - a function that changes the current directory of the process
 *
 * @info: a pointer to a structure of type shell_info
 *
 * Return: Always 0 Success
 */

int _cd(shell_info *info)
{
	char *str, *direct, buff[1024];
	int chdir_path;

	str = getcwd(buff, 1024);
	if (!str)
	{
		_puts("TODO: >>getcwd failure emsg here<<\n");
		return (1);
	}
	if (!info->argv[1])
	{
		direct = get_env_var(info, "HOME=");
		if (!direct)
			chdir_path = chdir((direct = get_env_var(info, "PWD=")) ? direct : "/");
		else
			chdir_path = chdir(direct);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!get_env_var(info, "OLDPWD="))
		{
			_puts(str);
			_putchar('\n');
			return (1);
		}
		_puts(get_env_var(info, "OLDPWD=")), _putchar('\n');
		chdir_path = chdir((direct = get_env_var(info, "OLDPWD=")) ? direct : "/");
	}
	else
		chdir_path = chdir(info->argv[1]);
	if (chdir_path == -1)
	{
		print_error(info, "can't cd to ");
		puts_error(info->argv[1]), _putchar('\n');
	}
	else
	{
		set_environ(info, "OLDPWD", get_env_var(info, "PWD="));
		set_environ(info, "PWD", getcwd(buff, 1024)); }
	return (0);
}

