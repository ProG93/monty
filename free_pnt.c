#include "monty.h"

/**
 * free_lineptr - free line pointer
 * @exit_s: - exit status
 * @c: pointer to line
 */

void free_lineptr(int exit_s, void *c)
{
	char **lineptr = c;

	(void)exit_s;
	if (*lineptr != NULL)
		free(*lineptr);
}
