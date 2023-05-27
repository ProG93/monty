#include "monty.h"

/**
 * _pall - print values
 * @stack: head of stack
 * @line_number: number of lines
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void)(line_number);

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		if (head == *stack)
		{
			return;
		}
	}
}
