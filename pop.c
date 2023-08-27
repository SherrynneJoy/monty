#include "monty.h"
/**
 * f_pop - removes an item from a stack
 * @head: head ptr
 * @line_no: line no
 */
void f_pop(stack_t **head, unsigned int line_no)
{
	stack_t *temp;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_no);
		freedata();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	(*head) = (*head)->next;
	free(temp);
}
