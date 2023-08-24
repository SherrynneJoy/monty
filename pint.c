#include "monty.h"
/**
 * f_pint - prints in at top of stack
 * @head: head ptr
 * @count: line no
 */
void f_pint(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", count);
		fclose(comm.fp);
		free(comm.lineptr);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
