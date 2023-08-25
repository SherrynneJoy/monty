#include "monty.h"
#include <stdlib.h>

/**
 * f_pop - deletes the item at the top of a stack
 * @head: pointer to a pointer
 * @count: an integer
 * Return: nothing
 */
void f_pop(stack_t **head, unsigned int count)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(drive.fp);
		free(drive.lineptr);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	free(temp);
}
