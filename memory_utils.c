#include "shell.h"

/**
 * resize_mem - a function that resize a previously allocated block of memory
 * @p_mem: pointer to previous allocated block or mem. using malloc
 * @old_size: bytes of previewsly allocated memory
 * @new_size: bytes of newly allocated memory
 *
 * Return: pointer to the newly allocated memory block
 */

void *resize_mem(void *p_mem, unsigned int old_size, unsigned int new_size)
{
	char *ptr;
	unsigned int i;

	if (!p_mem)
		return (malloc(new_size));

	if (!new_size)
		return (free(p_mem), NULL);

	if (new_size == old_size)
		return (p_mem);

	ptr = malloc(new_size);
	if (!ptr)
		return (NULL);

	if (old_size < new_size)
		old_size = old_size;
	else
		old_size = new_size;

	for (i = 0; i < old_size; i++)
	{
		ptr[i] = ((char *)p_mem)[i];
	}

	free(p_mem);
	return (ptr);
}

/**
 * my_memset - function that fill memory with  conctant byte
 *
 * @mem: pointer to memory to be filled
 * @b: the constant byte
 * @n_byte: the amount of bytes to be filled
 *
 * Return: pointer to the memory
 */

char *my_memset(char *mem, char b, unsigned int n_byte)
{
	char *p = mem;

	while (n_byte--)

		*p++ = b;

	return (mem);
}

/**
 * free_string_array - deallocates the memory occupied by each string
 * within a string array and then frees the array itself
 *
 *@ptr: a pointer to a pointer to char
 */

void free_string_array(char **ptr)
{
	char **arr = ptr;

	if (!ptr)
		return;

	while (*ptr)
	{
		free(*ptr++);
	}
	free(arr);
}

/**
 * buf_free - frees a pointer and sets it to NULL
 * @ptr: pointer to free
 *
 * Return: 1 if pointer was freed, 0 otherwise
 */

int buf_free(void **ptr)
{
	if (!ptr || !*ptr)
	{
		return (0);
	}

	free(*ptr);
	*ptr = NULL;

	return (1);
}
