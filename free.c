#include "monty.h"

/**
 * free_stack - frees the stack
 * @exit_s: exit status
 * @c: pointer to stack
 */

void free_stack(int exit_s, void *c)
{
	stack_t **stack;
	stack_t *next;

	(void)exit_s;

	stack = (stack_t **)c;
	if (*stack)
	{
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
	while (*stack != NULL)
	{
		next = (*stack)->next;
		free((*stack));
		*stack = next;
	}
	var.stack_len = 0;
}
