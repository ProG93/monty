#include "monty.h"

/*
 * _push - add int to stack
 * @stack: pointer beginning of a stack
 * @line_number: number of lines
 */
void _push(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *first;
	(void)line_number;

	first = malloc(sizeof(stack_t));
	if (first == NULL)
	{
		fprintf(stderr, "L<line_number>: push integer\n");
		exit(EXIT_FAILURE);	
	}
	
	first->n = var_global.push_argv;
	first->next = *stack;
	first->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = first;
	*stack = first;
}

/*
 * _pall - print all functions
 * @stack: first pointer in stack
 * @line_number: number of lines
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *first;

	first = *stack;
	while (first != NULL)
	{
		printf("%d\n", first->n);
		first = first->next;
	}
}

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *first;

	first = *stack;
	if (first == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", first->n);
}

/**
 * _pop - remove element a list
 *@stack: pointer to first node
 *@line_number: integer
 *Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *nodo = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = nodo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(nodo);
}
