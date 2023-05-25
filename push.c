#include "monty.h"

/*
 * pushcode - add code to stack
 * @stack: pointer to the begining of stack
 * @line_number: number of lines
 */

void pushcode(stack_t **stack, unsigned int line_number)
{
	char c;
	int n;

	c = strtok(NULL, "\n\t\r ");
	if (c == NULL || _isdigit(c))
	{
		dprintf(STDOUT_FILENO,
			"L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(c);
	if (!add_node(stack, n))
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}
