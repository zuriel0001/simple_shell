#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: pointer to array of vector
 *
 * Return: EXIT_SUCCESS (0) on success
 */

int main(int ac, char **av)
{
	shell_info info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				puts_error(av[0]);
				puts_error(": 0: Can't open ");
				puts_error(av[1]);
				putchar_error('\n');
				putchar_error(FLUSH_BUFFER);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->read_file = fd;
	}
	pop_env_list(info);
	read_hist(info);
	my_shell(info, av);
	return (EXIT_SUCCESS);
}

