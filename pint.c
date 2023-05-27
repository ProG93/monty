#include "monty.h"

/**
 * _pint - print value on top
 * @stack: head of stack
 * @line_number: number of lines
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDOUT_FILENO, "L%u: cant pint\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}
