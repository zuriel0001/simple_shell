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
	int i, j = 0;

	/**
	 * int length = stop - start;
	char *buf = (char *)malloc((length + 1) * sizeof(char));

	buf = (char *)malloc((length + 1) * sizeof(char));
	*/

	i = start;
	while (i < end)
	{
		if (inputString[i] != ':')
		{
			buff[j++] = inputString[i];
		}
		i++;
	}
	buff[j] = '\0';

	return (buff);
}
