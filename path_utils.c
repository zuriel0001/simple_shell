#include "shell.h"

/**
 *  is_regular_file - function that determine whether a file is a regular file
 *  and is executable
 *
 *  @info: a pointer to a structure of type shell_info
 *  @path: a pointer to path to the file
 *
 *  Return: 1 if true, otherwise 0
 */

int is_regular_file(shell_info *info, char *path)
{
	struct stat file_info;
	int result = 0;

	UNUSED(info);

	if (!path || stat(path, &file_info))
	{
		if (file_info.st_mode & S_IFREG)
		{
			result = 1;
		}
	}
	return (result);
}

/**
 * get_sgmnt_without_colon - copy a portion of a string, excluding ':' chars.
 *
 * @inputString: The input string to be copied from.
 * @start: the starting index of the portion to be copied.
 * @end: the ending index (exclusive) of the portion to be copied.
 *
 * Return: A pointer to a new string containing the copied portion.
 */

char *get_sgmnt_without_colon(const char *inputString, int start, int end)
{
	static char buff[1024];
	int i = 0, j = 0;

	for (j = 0, i = start; i < end; i++)
	{
		if (inputString[i] != ':')
		{
			buff[j++] = inputString[i];
		}
	}
	buff[j] = 0;

	return (buff);
}

/**
 * path_finder - function that searches for a command in a colon-separated
 * list of paths
 *
 * @info: pointer to struct shell_info
 * @inputString: given path string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */

char *path_finder(shell_info *info, char *inputString, char *cmd)
{
	int i = 0;
	int curr_i = 0;
	char *path;

	if (!inputString)
		return (NULL);

	if ((_strlen(cmd) > 2) && start_hays_need(cmd, "./"))
	{
		if (is_regular_file(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!inputString[i] || inputString[i] == ':')
		{
			path = get_sgmnt_without_colon(inputString, curr_i, i);

			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}

			if (is_regular_file(info, path))
				return (path);
			if (!inputString[i])
				break;
			curr_i = i;
		}
		i++;
	}
	return (NULL);
}
