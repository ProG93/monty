#include "monty.h"

/**
 * get_op - check valid opcodes
 * @op: check op
 * @stack: beginning of stack
 * @line_number: number of lines
 */
void get_op(char *op, stack_t **stack, unsigned int line_number)
{
	size_t n;
	instruction_t valid_ops[] = {
		{"push", pushcode},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", _stack},
		{"queue", _queue},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{NULL, NULL}
	};

	for (n = 0; valid_ops[n].opcode != NULL; n++)
	{
		if (strcmp(valid_ops[n].opcode, op) == 0)
		{
			valid_ops[n].f(stack, line_number);
			return;
		}
	}

	dprintf(STDOUT_FILENO, "L%u: unknown instruction %s\n", line_number, op);
	exit(EXIT_FAILURE);
}
