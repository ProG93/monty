#include "monty.h"

/*
 * _add - adds top two elements
 * @stack: begin of stack
 * @line_number: number of line
 */

void _add(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	if (var.stack_len < 2)
	{
		perror("cannot add");
		exit(EXIT_FAILURE);
	}
	i += (*stack)->i;
	_pop(stack, line_number);
	(*stack)->i += i;
}

/*
 * _sub - adds top two elements
 * @stack: begin of stack
 * @line_number: number of line
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int i;

	if (var.stack_len < 2)
        {
		dprintf(STDOUT_FILENO, "L%u: can't sub, stack short", line_number)
		exit(EXIT_FAILURE);
        }
	i = (*stack)->i;
	_pop(stack, line_number);
	(*stack)->i -= i;
}




/*
 * _mul - adds top two elements
 * @stack: begin of stack
 * @line_number: number of line
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int i;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO, "L%u: can't mul\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->i;
	_pop(stack, line_number);
	(*stack)->i *=i;
}

/*
 * _div - adds top two elements
 * @stack: begin of stack
 * @line_number: number of line
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int i;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO, "L%u: can't div\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->i;
	_pop(stack, line_number);
	if (i == 0)
	{
		dprintf(STDOUT_FILENO, "L%u: div by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->i /= i;

}
