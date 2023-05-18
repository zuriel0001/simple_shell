#include "shell.h"

/**
 * print_list - function that prints all elements of a list_t
 * linked list
 * @h: pointer to the first node
 *
 * Return: the size of the list
 */
size_t print_list(const list_t *h)
{
	size_t j = 0;

	while (h)
	{
		_puts(convert_num(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		j++;
	}
	return (j);
}

/**
 * list_str - function that returns an array of string to the list
 * @h: pointer to the first node
 *
 * Return: the array of string
 */
char **list_str(list_t *h)
{
	list_t *n = h;
	size_t i = list_length(h), k;
	char **sss;
	char *str;

	if (!h || !i)
		return (NULL);
	sss = malloc(sizeof(char *) * (i + 1));

	if (!sss)
		return (NULL);

	for (i = 0; n; n = n->next, i++)
	{
		str = malloc(_strlen(n->str) + 1);
		if (!str)
		{
			k = 0;
			while (k < i)
			{
				free(sss[k]);
				k++;
			}
			free(sss);
			return (NULL);
		}
		str = _strcpy(str, n->str);
		sss[i] = str;
	}
	sss[i] = NULL;
	return (sss);
}
