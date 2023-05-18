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
