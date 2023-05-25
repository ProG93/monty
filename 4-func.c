#include "monty.h"

/**
 * _pstr - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int c = 0;

	(void)line_number;

	while (tmp)
	{
		c = tmp->n;
		if (c == 0 || _isalpha(c) == 0)
			break;
		putchar(c);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * _rotl - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;

	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	aux1 = first->n;

	while (first->next)
	{
		first = first->next;
		first->prev->n = first->n;
	}

	first->n = aux1;
}

/**
 * _rotr - mod top of stack y second top stacks
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *first= *stack;

	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (first->next)
		first = first->next;

	aux1 = first->n;

	while (first->prev)
	{
		first = first->prev;
		first->next->n = first->n;
	}

	first->n = aux1;
}
