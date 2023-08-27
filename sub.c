#include "monty.h"

/**
 * f_sub - subtracts two nodes
 * @head: a pointer to a pointer
 * @line_number: an integer
 * Return: nothing
 */
void f_sub(stack_t **head, unsigned int line_number)
{
	stack_t *temp = NULL;
	int i = 0;

	temp = *head;

	for (; temp != NULL; temp = temp->next, i++)
		;
	if (i < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		freedata();
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n -= (*head)->n;
	f_pop(head, line_number);
}
