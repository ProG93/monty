#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*
 * struct stack_s - representation of a stack
 * @n: integer
 * @prev: previous element of stack
 * @next: next element of stack
 * Description: double linked list
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/*
 * struct instruction_s - opcode
 * @opcode: opcode
 * @f: function
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*
 * struct global_variable - rep of variable
 * @file: the opcode
 * @push_argv: function to handle
 * @buf: pointer
 */
typedef struct global_variable
{
	FILE *file;
	int push_argv;
	char *buf;

} global_var;

extern global_var var_global;

void read_file(char *file, stack_t **stack);
char *purse_line(char *line, stack_t **stack, unsigned int line_number);
typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
instruct_func get_opcode(char *str);

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);


void free_dlistint(stack_t *head);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);

void _sub(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

void dobfree(stack_t **stack);
void dobfree2(stack_t **stack);
int _isalpha(int c);
#endif
