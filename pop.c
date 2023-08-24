#include "monty.h"
/**
 * f_pop - removes an item from a stack
 * @head: head ptr
 * @count:line no
 */
void f_pop(stack_t **head, unsigned int count)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(comm.fp);
		free(comm.lineptr);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	free(temp);
}
