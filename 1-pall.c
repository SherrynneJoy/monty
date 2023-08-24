#include "monty.h"
/**
 * f_pall - prints all elements of a stack
 * @head: head ptr
 * @count: line no
 */
void f_pall(stack_t **head, unsigned int count)
{
	stack_t *temp = *head;

	(void)count;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp= temp->next;
	}
}
