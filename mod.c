#include "monty.h"

/**
 * _mod - modulus of top element
 * @stack: head of stack
 * @line_number: current operation
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO, "L%u: can't mod\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	_pop(stack, line_number);
	if (n == 0)
	{
		dprintf(STDOUT_FILENO, "L%u: div by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n %= n;
}
