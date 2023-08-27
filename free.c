#include "monty.h"
/**
 * freestack - frees a stack
 * @head: head ptr
 */
void freelist(stack_t *head)
{
	stack_t *temp;

	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}
