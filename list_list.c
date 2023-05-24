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

/**
 * list_length - function that gets the length of a linked
 * list
 * @head: pointer to the first node
 *
 * Return: the length of the list
 */
size_t list_length(const list_t *head)
{
	size_t j = 0;

	while (head)
	{
		head = head->next;
		j++;
	}
	return (j);
}

/**
 * print_list_string - function that prints only the string of linked list
 * @head: pointer to the first node
 *
 * Return: the size of the list
 */
size_t print_list_string(const list_t *head)
{
	size_t m = 0;

	while (head)
	{
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		m++;
	}
	return (m);
}

/**
 * free_list - a function that freesall the nodes of
 * a list
 * @h_ptr: the address of the pointer to the  head node
 *
 * Return: void
 */
void free_list(list_t **h_ptr)
{
	list_t *n, *next_n, *h;

	if (!h_ptr || !*h_ptr)
		return;
	h = *h_ptr;
	n = h;

	while (n)
	{
		next_n = n->next;
		free(n->str);
		free(n);
		n = next_n;
	}
	*h_ptr = NULL;
}
