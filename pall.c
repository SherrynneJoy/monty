#include "monty.h"

/**
 * f_pall - prints everything
 * @head: a pointer to a pointer
 * @line_number: an integer
 * Return: nothing
 */
void f_pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = (*head);
	if (temp == NULL)
		return;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
