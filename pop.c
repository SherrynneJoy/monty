#include "monty.h"
#include <stdlib.h>

/**
 * f_pop - deletes the item at the top of a stack
 * @head: pointer to a pointer
 * @line_number: an integer
 * Return: nothing
 */
void f_pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		freedata();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
