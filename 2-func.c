#include "monty.h"

/*
 * read_file - reads file
 * @file: pathname of file
 * @stack: pointer o top stack
 */
void read_file(char *file, stack_t **stack)
{
	char *line;
	size_t i = 0;
	int count_line = 1;
	instruct_func c;
	int check;
	int read;

	var_global.file = fopen(file, "r");

	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: cant open file%s\n", file);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&var_global.buf, &i, var_global.file)) != -1)
	{
		line = purse_line(var_global.buf, stack, count_line);
		if (line == NULL || line[0] == '#')
		{
			count_line++;
			continue;
		}
		c = get_opcode(line);
		if (c == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction%s\n", count_line, line);
			exit(EXIT_FAILURE);
		}
		c(stack, count_line);
		count_line++;
	}
	free(var_global.buf);
	if (check == -1)
	{
		fprintf(stderr, "L%d: negative%s\n", count_line);
		exit(-1);
	}
}


/*
 * get_opcode - prints opcode
 * @str: opcode
 */

instruct_func get_opcode(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}

/*
 * isnumber - checks string is number
 * @str: string
 * Return: 1 if string otherwise 0
 */

int isnumber(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);

	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
 * purse_line - passes a line
 * @line: line to be passed
 * @stack: pointer to head of stack
 * @line_number: current line number
 * Return: returns opcode
 */

char *purse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *op_code, *push, *arg;
	(void)stack;

	push = "push";
	op_code = strtok(line, "\n");
	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, push) == 0)
	{
		arg = strtok(NULL, "\n");
		if (isnumber(arg) == 1 && arg != NULL)
		{
			var_global.push_argv = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}
