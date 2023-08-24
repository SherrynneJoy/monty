#include "monty.h"
/**
 * f_add - ads 2 elements
 * @head: head ptr
 * @count: line no
 */
void f_add(stack_t **head, unsigned int count)
{
	stack_t *temp = *head;
	int len = 0, s;

	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(comm.fp);
		free(comm.lineptr);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	s = temp->n + temp->next->n;
	temp->next->n = s;
	*head = temp->next;
	free(temp);
}