#include "monty.h"
/**
 * f_swap - swaps integer positions
 * @head: head ptr
 * @line_no: line number
 */
void f_swap(stack_t **head, unsigned int line_no)
{
	stack_t *temp = *head;
	int len = 0;

	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_no);
		freedata();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	(*head) = (*head)->next;
	temp->next = (*head)->next;
	temp->prev = (*head);
	(*head)->next = temp;
	(*head)->prev = NULL;
}
