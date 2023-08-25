#include "monty.h"
/**
 * freestack - frees a stack
 * @head: head ptr
 */
void freestack(stack_t *head)
{
	stack_t *temp = head;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
