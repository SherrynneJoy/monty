#include "monty.h"
/**
 * f_pchar - prints a char
 * @head: head ptr
 * @line_no: line number
 */
void f_pchar(stack_t **head, unsigned int line_no)
{
	if (!head || (*head) == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_no);
		freedata();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 128)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_no);
		freedata();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
