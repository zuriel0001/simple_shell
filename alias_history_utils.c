#include "shell.h"

/**
 * show_history - function that display the command history list
 *
 * @info: pointer to a structure
 *
 *  Return: Always 0 (Success)
 */

int show_history(shell_info *info)
{
	print_list(info->history);

	return (0);
}



/**
 * remove_alias - function removes an alias from the list of aliases
 *
 * @info: pointer to a structure that contains information about the aliases
 * @str: A pointer to a string that contains the alias to be unset
 *
 * Return:  0 on success, otherwise 1 on error
 */

int remove_alias(shell_info *info, char *str)
{
	char *ptr; /* A pointer to a character in the string str */
	char saved_char; /* temporarily store the value of the '=' character in str */
	int ret; /* store the return value of the "remove_node_at_idx()" function */
	int node_ind;

	ptr = _strchr(str, '=');

	if (ptr == NULL)
		return (1);

	saved_char = *ptr;
	*ptr = '\0';

	node_ind = fetch_node_idx(info->alias, start_node_with(info->alias, str, -1));
	ret = remove_node_at_idx(&(info->alias), node_ind);

	/**
	* ret = remove_node_at_idx(&(info->alias), fetch_node_idx(info->alias,
	* node_starts_with(info->alias, str, -1)));
	*/

	*ptr = saved_char;
	return (ret);
}


/**
 * create_alias - function sets an alias in the shell
 *
 * @info: A pointer to a shell_info structure
 * @str: a pointer to a string
 *
 * Return: 0 on success, otherwise 1 on error
 */

int create_alias(shell_info *info, char *str)
{
	char *ptr; /* a pointer to a character */
	int i = 0;
	int is_null;

	while (str[i] != '\0')
	{
		if (str[i] == '=')
		{
			ptr = &str[i];
			break;
		}
		i++;
	}

	if (str[i] == '\0')
	{
		return (1);
	}
	if (!*++ptr)
	{
		return (remove_alias(info, str));
	}
	remove_alias(info, str);

	is_null = (add_node_end(&(info->alias), str, 0) == NULL);
	return (is_null);
}

/**
 * print_alias - a function that prints an alias string
 *
 * @node: pointer to a structure
 *
 * Return: 0 on success else 1 on error
 */

int print_alias(list_t *node)
{
	char *equal_sign_position = NULL;
	char *current_char = NULL;

	if (node)
	{
		equal_sign_position = _strchr(node->str, '=');
		current_char = node->str;

		while (current_char <= equal_sign_position)
		{
			_putchar(*current_char);
			current_char++;
		}
		_putchar('\'');
		_puts(equal_sign_position + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}


/**
 * my_alias - function that creates an alias for a command
 *
 * @info: pointer to shell_info struct
 *
 * Return: 0 on success, -1 on failure
 */

int my_alias(shell_info *info)
{
	list_t *node = NULL;
	int i = 0;
	char *equal_sign_position = NULL;

	if (info->argc == 1)
	{
		for (node = info->my_alias; node != NULL; node = node->next)
		{
			print_alias(node);
		}
		return (0);
	}

	for (i = 1; info->argv[i]; i++)
	{
		equal_sign_position = _strchr(info->argv[i], '=');
		if (equal_sign_position)
		{
			create_alias(info, info->argv[i]);
		}
		else
			print_alias(start_node_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

