#include "shell.h"

/**
 * substitute_vars - substitutes vars in the tokenized string
 * @info: the structure parameter
 *
 * Return: 1 or 0
 */
int substitute_vars(shell_info *info)
{
	int k = 0;
	list_t *n;

	for (k = 0; info->argv[k]; k++)
	{
		if (info->argv[k][0] != '$' ||
				!info->argv[k][1])
			continue;

		if (!_strcmp(info->argv[k], "$?"))
		{
			substitute_string(&(info->argv[k]),
					_strdup(convert_num(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[k], "$$"))
		{
			substitute_string(&(info->argv[k]),
					_strdup(convert_num(getpid(), 10, 0)));
			continue;
		}
		n = start_node_with(info->env, &info->argv[k][1], '=');
		if (n)
		{
			substitute_string(&(info->argv[k]),
					_strdup(_strchr(n->str, '=') + 1));
			continue;
		}
		substitute_string(&info->argv[k], _strdup(""));
	}
	return (0);
}

/**
 * substitute_alias - substitute an alias in the tokenized string
 * @info: the structure parameter
 *
 * Return: 1 0r 0
 */
int substitute_alias(shell_info *info)
{
	int j = 0;
	list_t *n;
	char *a;

	while (j < 10)
	{
		n = start_node_with(info->my_alias, info->argv[0], '=');
		if (!n)
			return (0);
		free(info->argv[0]);
		a = _strchr(n->str, '=');
		if (!a)
			return (0);
		a = _strdup(a + 1);
		if (!a)
			return (0);
		info->argv[0] = a;

		j++;
	}
	return (1);
}

/**
 * substitute_string - function that susitutes a string
 * @old: the address of the old string
 * @new: the address of the new string
 *
 * Return: 1 or 0
 */
int substitute_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
