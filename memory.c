#include "shell.h"

/**
 * bfree - frees a ptr & NULLs address
 * @ptr: address of the ptr to free
 *
 * Return: 1 freed, otherwise 0.
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
