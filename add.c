#include "monty.h"

/**
 * f_add - adds two nodes
 * @head: a pointer to a pointer
 * @count: an integer
 * Return: nothing
 */
void f_add(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int length = 0, m;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(drive.fp);
		free(drive.lineptr);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	m = temp->n + temp->next->n;
	temp->next->n = m;
	*head = temp->next;
	free(temp);
}
