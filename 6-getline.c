#include "shell.h"

/**
 * get_line - function that gets the next line of input
 * from STDIN
 * @info: the parameter structure
 * @ptr: the address of pointer to buffer
 * @len: size of ptr
 *
 * Return: the next line
 */
int get_line(shell_info *info, char **ptr, size_t *len)
{
	static char buf[READ_BUF_SIZE];
	static size_t i;
	static size_t l;
	size_t k;
	size_t m;
	size_t st = 0;
	char *pointer = NULL;
	char *new_pointer = NULL;
	char *c;

	pointer = *ptr;
	if (pointer && len)
		st = *len;
	if (i == l)
		i = l = 0;

	m = read_buffer(info, buf, &l);
	if (m == -1 || (m == 0 && l == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : l;
	new_pointer = _realloc(pointer, st, st ? st + k : k + 1);
	if (!new_pointer)
		return (pointer ? free(pointer), -1 : -1);

	if (st)
		_strncat(new_pointer, buf + i, k - i);
	else
		_strncpy(new_pointer, buf + i, k - i + 1);

	st += k - i;
	i = k;
	pointer = new_pointer;

	if (len)
		*len = st;
	*ptr = pointer;
	return (st);
}

/**
 * read_buffer - function that reads a buffer
 * @info: structure parameter
 * @buf: the buffer to read
 * @i: buffer size
 *
 * Return: the declared variable m
 */
ssize_t read_buffer(shell_info *info, char *buf, size_t *i)
{
	ssize_t m = 0;

	if (*i)
		return (0);
	m = read(info->readfd, buf, READ_BUF_SIZE);
	if (m >= 0)
		*i = m;
	return (m);
}
