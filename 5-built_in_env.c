#include "shell.h"

/**
 * built_in_env - function that prints the curent environment
 * @info: structure of potential arguments
 *
 * Return: 0
 */
int built_in_env(info_t *info)
{
	print_list_string(info->env);
	return (0);
}

/**
 * get_env_var - function that gets the value of an environ variable
 * @info: structure containing potential arguments
 * @name: name of environ variable
 *
 * Return: the value of env variable
 */
char *get_env_var(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *k;

	while (node)
	{
		k = starts_with(node->str, name);
		if (k && *k)
			return (k);
		node = node->next;
	}
	return (NULL);
}

/**
 * pop_env_list - function that populates an environ linked list
 * @info: structure of potential arguments
 *
 * Return: 0
 */
int pop_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t j = 0;

	while (environ[j])
	{
		add_node_end(&node, environ[j], 0);
		j++;
	}
	info->env = node;
	return (0);
}

/**
 * set_my_env_var - function that sets a new environmment variable
 * @info: structure containing potentiala argument
 *
 * Return: 0
 */
int set_my_env_var(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("incorrect number of arguments\n");
		return (1);
	}
	if (set_environ(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * unset_my_env_var - function that removes an environment variable
 * @info: structure containing potential args
 *
 * Return: 0
 */
int unset_my_env_var(info_t *info)
{
	int i = 1;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	while (i <= info->argc)
	{
		unset_environ(info, info->argv[i]);
		i++;
	}
	return (0);
}
