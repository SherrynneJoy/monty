#include "monty.h"

/**
 * f_pall - prints everything
 * @head: a pointer to a pointer
 * @count: an integer
 * Return: nothing
 */
void f_pall(stack_t **head, unsigned int count)
{
	stack_t *temp;
	(void)count;

	temp = (*head);
	if (temp == NULL)
		return;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
