#include "shell.h"

/**
 *_memset - for filling a memory with a given constant byte
 *@s: memory area pointer
 *@b: the bytes that *s is to be filled with
 *@n: amount of bytes to ffill
 *Return: the pointer to the s memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 *ffree - frees a string in strings
 *@pp: a string in strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 *_realloc - a function to reallocate a block of memory
 *@ptr: the previous malloc'  pointer
 *@old_size: previous block byte size
 *@new_size: new block byte size
 *
 *Return: ol'block name pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
