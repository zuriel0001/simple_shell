#include "shell.h"


/**
 * stringToWords - split a string into words using a delimiter string
 *
 * @str: Input string to be split
 * @d_str: delimiter string used to separate words
 *
 * Return: pointer to an array of strings or NULL when it fails
 */

char **stringToWords(char *str, char *d_str)
{
	int i = 0, n = 0, word_count = 0, j, m;
	char **arr_str;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (d_str == NULL)
		d_str = " ";
	while (str[i] != '\0')
	{
		if (!is_delim(str[i], d_str) && (is_delim(str[i + 1], d_str) || !str[i + 1]))
			word_count++;
		i++;
	}
	if (word_count == 0)
		return (NULL);
	arr_str = malloc((word_count + 1) * sizeof(char *));
	if (!arr_str)
		return (NULL);
	for (i = 0, j = 0; j < word_count; j++)
	{
		while (is_delim(str[i], d_str))
			i++;
		while (!is_delim(str[i + n], d_str) && str[i + n])
			n++;
		arr_str[j] = malloc((n + 1) * sizeof(char));
		if (!arr_str[j])
		{
			for (n = 0; n < j; n++)
				free(arr_str[n]);
			free(arr_str);
			return (NULL);
		}
		for (m = 0; m < n; m++)
			arr_str[j][m] = str[i++];
		arr_str[j][m] = 0;
	}
	arr_str[j] = NULL;
	return (arr_str);
}

