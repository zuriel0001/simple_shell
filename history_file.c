#include "shell.h"

/**
 * recode_history - function that recodes the history linked list
 * after changes have been made
 * @infor: potential aarguments of the structure
 *
 * Return: the history count
 */
int recode_history(shell_info *info)
{
	list_t *n = info->history;
	int j = 0;

	while (n)
	{
		n->num = j++;
		n = n->next;
	}
	return (info->histcount = j);
}

/**
 * create_history_list - attach an entry to a history linked list
 * @info: structure of potential args
 * @buf: the buffer
 * @linecount: history linecount
 *
 * Return: 0
 */
int create_history_list(shell_info *info, char *buf, int linecount)
{
	list_t *n = NULL;

	if (info->history)
		n = info->history;
	add_node_end(&n, buf, linecount);

	if (!info->history)
		info->history = n;
	return (0);
}

/**
 * read_hist - function that reads the history from the file
 * @info: parameter structure
 *
 * Return: the history count or 0
 */
int read_hist(shell_info *info)
{
	int j;
	int la = 0, linecount = 0;
	ssize_t f, readlength, fs = 0;
	struct stat st;
	char *buf = NULL, *fname = fetch_history_file(info);

	if (!fname)
		return (0);

	f = open(fname, O_RDONLY);
	free(fname);
	if (f == -1)
		return (0);
	if (!fstat(f, &st))
		fs = st.st_size;
	if (fs < 2)
		return (0);
	buf = malloc(sizeof(char) * (fs + 1));
	if (!buf)
		return (0);
	readlength = read(f, buf, fs);
	buf[fs] = 0;
	if (readlength <= 0)
		return (free(buf), 0);
	close(f);

	for (j = 0; j < fs; j++)
		if (buf[j] == '\n')
		{
			buf[j] = 0;
			create_history_list(info, buf + la, linecount++);
			la = j + 1;
		}
	if (la != j)
		create_history_list(info, buf + la, linecount++);
	free(buf);
	info->histcount linecount;
	while (info->histcount-- >= HIST_MAX)
		remove_node_at_idx(&(info->history), 0);
	recode_history(info);
	return (info->histcount);
}
