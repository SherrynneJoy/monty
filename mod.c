#include "monty.h"

/**
 * f_mod - calculates the modulus
 * @head: pointer to pointer
 * @line_number: an integer
 */
void f_mod(stack_t **head, unsigned int line_number)
{
	stack_t *temp = NULL;
	int i = 0;

	temp = *head;

	for (; temp != NULL; temp = temp->next, i++)
		;
	if (i < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		freedata();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		freedata();
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n %= (*head)->n;
	f_pop(head, line_number);
}
