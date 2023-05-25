#include "monty.h"

/*
 * free_ptr - free line pointer
 * @exit_s - exit status
 * @c: pointer to line
 */

void free_ptr(int exit_s, void *c)
{
	char **lineptr = c;

	(void)exit_s;
	if (*lineptr != NULL)
		free(*lineptr);
}
