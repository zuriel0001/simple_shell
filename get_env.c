#include "shell.h"

/**
 * fetch_environ - functions that returns the string array of
 * an environment
 * @info: potential argument of the structure
 *
 * Return: 0
 */
char **fetch_environ(shell_info *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_str(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * unset_environ - function that clears an environ variable
 * @info: potential arguments of the structure
 * @var: the string environment variable property
 *
 * Return: returns 1 or 0
 */
int unset_environ(shell_info *info, char *var)
{
	list_t *n = info->env;
	size_t i = 0;
	char *ptr;

	if (!n || !var)
		return (0);

	while (n)
	{
		ptr = start_hays_need(n->str, var);
		if (ptr && *ptr == '=')
		{
			info->env_changed = remove_node_at_idx(&(info->env), i);
			i = 0;
			n = info->env;
			continue;
		}
		n = n->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * set_environ - function that sets up a new environment variable
 * @info: potential arguments of structure
 * @var: string environment variable
 * @val: string environment value
 *
 * Return: 0
 */
int set_environ(shell_info *info, char *var, char *val)
{
	char *buf = NULL;
	list_t *n;
	char *ptr;

	if (!var || !val)
		return (0);

	buf = malloc(_strlen(var) + _strlen(val) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, val);
	n = info->env;
	while (n)
	{
		ptr = start_hays_need(n->str, var);
		if (ptr && *ptr == '=')
		{
			free(n->str);
			n->str = buf;
			info->env_changed = 1;
			return (0);
		}
		n = n->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
