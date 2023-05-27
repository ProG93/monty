#include "monty.h"

/**
 * _fs_close - close file
 * @exit_s: status passed
 * @c: pointer to file
 *
 * Return: void
 */

void _fs_close(int exit_s, void *c)
{
	FILE *fs;

	(void)exit_s;

	fs = (FILE *) c;
	fclose(fs);
}
