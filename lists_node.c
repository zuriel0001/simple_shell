#include "shell.h"

/**
 * add_node - function that adds a node to the start of a list
 * @head: the address of the pointer to the head node
 * @str: the str field of the node
 * @num: node index
 *
 * Return: size of the list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_h;

	if (!head)
		return (NULL);
	new_h = malloc(sizeof(list_t));
	if (!new_h)
		return (NULL);
	_memset((void *)new_h, 0, sizeof(list_t));
	new_h->num = num;
	if (str)
	{
		new_h->str = _strdup(str);
		if (!new_h->str)
		{
			free(new_h);
			return (NULL);
		}
	}
	new_h->next = *head;
	*head = new_h;
	return (new_h);
}

/**
 * remove_node_at_idx - function that deletes the node at a given index
 * @head: the address of the pointer to the first node
 * @index: the index of the node to delete
 *
 * Return: 1 or 0
 */
int remove_node_at_idx(list_t **head, unsigned int index)
{
	list_t *n, *p_n; /*where n = node and p_n = previous node */
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		n = *head;
		*head = (*head)->next;
		free(n->str);
		free(n);
		return (1);
	}
	n = *head;
	while (n)
	{
		if (i == index)
		{
			p_n->next = n->next;
			free(n->str);
			free(n);
			return (1);
		}
		i++;
		p_n = n;
		n = n->next;
	}
	return (0);
}

/**
 * add_node_end - function that adds a node to the end of the list
 * @head: the address of pointer to the head node
 * @str: the str feld of the node
 * @num: the node index
 *
 * Return: the size of the list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_n, *n;

	if (!head)
		return (NULL);

	n = *head;
	new_n = malloc(sizeof(list_t));
	if (!new_n)
	{
		return (NULL);
	}
	_memset((void *)new_n, 0, sizeof(list_t));
	new_n->num = num;

	if (str)
	{
		new_n->str = _strdup(str);
		if (!new_n->str)
		{
			free(new_n);
			return (NULL);
		}
	}
	if (n)
	{
		while (n->next)
			n = n->next;
		n->next = new_n;
	}
	else
		*head = new_n;
	return (new_n);
}

/**
 * fetch_node_idx -fetches the index of a node
 * @head: pointer to thead head of the list
 * @node: pointer to the node
 *
 * Return: the index of the node
 */
ssize_t fetch_node_idx(list_t *head, list_t 8node)
{
	size_t k = 0;

	while (head)
	{
		if (head == node)
			return (k);
		head = head->next;
		k++;
	}
	return (-1);
}

/**
 * start
