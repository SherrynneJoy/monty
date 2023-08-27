#include "monty.h"
/**
 * f_div - divides 2 elements
 * @head: head ptr
 * @line_no: line number
 */
void f_div(stack_t **head, unsigned int line_no)
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
		fprintf(stderr, "L%u: can't div, stack too short\n", line_no);
		freedata();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_no);
	}
	temp = (*head)->next;
	temp->n /= (*head)->n;
	f_pop(head, line_no);
}
