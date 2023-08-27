#include "monty.h"
/**
 * f_pall - prints all elements of a stack
 * @head: head ptr
 * @line_no: line no
 */
void f_pall(stack_t **head, unsigned int line_no)
{
	stack_t *temp = *head;

	(void)line_no;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
