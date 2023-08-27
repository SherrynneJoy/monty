#include "monty.h"
#include <stdlib.h>

/**
 * f_pint - implements the pint code
 * @head: pointer to a pointer
 * @line_number: an integer
 * Return: nothing
 */
void f_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		freedata();
		exit(EXIT_FAILURE);
	}
	printf("%u\n", (*head)->n);
}
