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
	ssize_t m;
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
	new_pointer = resize_mem(pointer, st, st ? st + k : k + 1);
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

/**
 * get_input - get a line aside the newline
 * @info: structure parameter
 *
 * Return: bytes
 */
ssize_t get_input(shell_info *info)
{
	static char *buf;
	static size_t k, m;
	static size_t l; /* length */
	ssize_t a = 0;
	char **buf_pointer = &(info->arg), *pointer;

	_putchar(FLUSH_BUFFER);
	a = input_buffer(info, &buf, &l);
	if (a == -1)
		return (-1);
	if (l)
	{
		m = k;
		pointer = buf + k;

		chain_chk(info, buf, &m, k, l);
		while (m < l)
		{
			if (is_chain(info, buf, &m))
				break;
			m++;
		}

		k = m + 1;
		if (k >= l)
		{
			k = l = 0;
			info->cmd_buf_type = CMD_NORMAL;
		}

		*buf_pointer = pointer;
		return (_strlen(pointer));
	}

	*buf_pointer = buf;
	return (a);
}

/**
 * input_buffer - function that inputs buffer chained commands
 * @info: structure parameter
 * @buf: buffer address
 * @len: len variable address
 *
 * Return: bytes
 */
ssize_t input_buffer(shell_info *info, char **buf, size_t *len)
{
	ssize_t a = 0;
	size_t length_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sig_int_handler);
#if USE_GETLINE
		a = getline(buf, &length_p, stdin);
#else
		a = get_line(info, buf, &length_p);
#endif
		if (a > 0)
		{
			if ((*buf)[a - 1] == '\n')
			{
				(*buf)[a - 1] = '\0';
				a--;
			}
			info->linecount_flag = 1;
			erase_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = a;
				info->cmd_buf = buf;
			}
		}
	}
	return (a);
}

/**
 * sig_int_handler - function that blocks ctrl-C
 * @sig: signal number
 *
 * Return: void
 */
void sig_int_handler(__attribute__((unused))int sig)
{
	_puts("\n");
	_puts("$");
	_putchar(FLUSH_BUFFER);
}
