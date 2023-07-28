#include "shell.h"

/**
 *bfree - frees pointer and the address is NULLED
 *@ptr: address of the pointer to free
 *
 *Return: 1 if memory is freed, 0 if not
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
