#include "monty.h"
#include <stdlib.h>

/**
 * f_swap - swaps the top two elements
 * @head: pointer to pointer
 * @line_number: an integer
 * Return: nothing
 */
void f_swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp = NULL;
	int m = 0;

	temp = *head;

	for (; temp != NULL; temp = temp->next, m++)
		;
	if (m < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		freedata();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	temp->prev = *head;
	(*head)->next = temp;
	(*head)->prev = NULL;
}
