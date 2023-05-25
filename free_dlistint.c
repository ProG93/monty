#include "monty.h"

/*
 * free_dlistint - free double list
 * @head: head of stack
 * Return: 0
 */

void free_dlistint(stack_t *head)
{
	stack_t *tmp;
	
	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
