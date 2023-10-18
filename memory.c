#include "shell.h"

/**
 * b_free – it frees the pointer and NULLs the address
 * @ptr: The address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int b_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
