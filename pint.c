#include "monty.h"
/**
 * f_pint - prints in at top of stack
 * @head: head ptr
 * @line_no: line no
 */
void f_pint(stack_t **head, unsigned int line_no)
{
	(void)line_no;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_no);
		freedata();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
