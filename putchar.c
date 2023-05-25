#include "monty.h"

/*
 * _pchar - print character
 * @stack: top of stack
 * @line_number: number oof lines
 */

void _pchar(stack_t **stack, unsigned int list_number)
{
	int ch;

	if (var.stack_len < 1)
	{
		dprintf(STDOUT_FILENO, "L%u: cant print\n", line_number);
		exit(EXIT_FAILURE);
	}
	ch = (*stack)->i;
	if (!isascii(ch))
	{
		dprintf("L%u: cant pchar, value\n", line_number);
		exit(EXIT_FAILURE);
	}	
	printf("%c\n", ch);
}
