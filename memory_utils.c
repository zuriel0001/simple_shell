#include "shell.h"

/**
 * resize_mem - a function that resize a previously allocated block of memory
 *
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

