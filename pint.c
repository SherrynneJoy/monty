#include "monty.h"
#include <stdlib.h>

/**
 * f_pint - implements the pint code
 * @head: pointer to a pointer
 * @count: an integer
 * Return: nothing
 */
void f_pint(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(drive.fp);
		free(drive.lineptr);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
