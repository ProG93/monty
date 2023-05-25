#include "monty.h"

global_var var_global;

/*
 * main - function for monty
 * @argc: num of arguments
 * @argv: array of arguments
 * Return: 0
 */

int main(int argc, char **argv)
{
	stack_t stack;
	(void)stack;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE:	monty file\n");
		exit(EXIT_FAILURE);
	}
	
	read_file(argv[1], &stack);
	free_dlistint(stack);
	return (0);
}

