#include "monty.h"
#include <stdlib.h>

/**
 * f_swap - swaps the top two elements
 * @head: pointer to pointer
 * @count: an integer
 * Return: nothing
 */
void f_swap(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int length, m = 0;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(drive.fp);
		free(drive.lineptr);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	m = temp->n;
	temp->n = temp->next->n;
	temp->next->n = m;
}
