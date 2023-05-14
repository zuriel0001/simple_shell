#include "shell.h"

/**
 * helper - Display help information for the shell.
 *
 * @info: pointer to a struct containing information about the shell.
 *
 * This function displays a list of available shell commands and brief
 * descriptions of what they do. It also provides instructions on how to
 * use the shell, including information on how to navigate the file system,
 * execute commands, and set environment variables.
 *
 * Return: Always returns 0.
 */

int helper(shell_info *info)
{
	_puts("Shell Commands:\n");
	_puts("  help     - Display this help information.\n");
	_puts("  cd       - Change the current working directory.\n");
	_puts("  pwd      - Display the current working directory.\n");
	_puts("  env      - Display a list of environment variables.\n");
	_puts("  setenv   - Set the value of an environment variable.\n");
	_puts("  unsetenv - Remove an environment variable.\n");
	_puts("  exit     - Exit the shell.\n");
	_puts("\n");
	_puts("Usage:\n");
	_puts("  To execute a command, simply type the name of the command\n");
	_puts("  followed by any arguments, separated by spaces.\n");
	_puts("\n");
	_puts("  To navigate the file system, use the 'cd' command.\n");
	_puts("  For example, 'cd /usr/bin' will change the current\n");
	_puts("  working directory to '/usr/bin'.\n");
	_puts("\n");
	_puts("  To set an environment variable, use the 'setenv' command.\n");
	_puts("  For example, 'setenv MY_VAR my_value' will set the value of\n");
	_puts("  the 'MY_VAR' environment variable to 'my_value'.\n");
	_puts("\n");
	_puts("  To remove an environment variable, use the 'unsetenv' command.\n");
	_puts("  For example, 'unsetenv MY_VAR' will remove the 'MY_VAR'\n");
	_puts("  environment variable.\n");
	_puts("\n");
	return (0);
}
