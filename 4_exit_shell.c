#include "shell.h"

/**
 * exit_shell - a function that exits the shell
 *
 * @info: a pointer to a structure of type shell_info
 *
 * Return: 1 if error occur, 0 if info.argv[0] != "exit"
 */

int exit_shell(shell_info *info)
{
	int check_exit;

	/* if there is an exit arguement */
	if (info->argv[1])
	{
		check_exit = atoi_overflow(info->argv[1]);

		if (check_exit == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			puts_error(info->argv[1]);
			putchar_error('\n');
			return (1);
		}
		info->error_numb = atoi_overflow(info->argv[1]);
		return (-2);
	}
	info->error_numb = -1;
	return (-2);
}

