#include "monty.h"
/**
 * f_pstr - prints a str
 * @head: head ptr
 * @line_no: line number
 */
void f_pstr(stack_t **head, unsigned int line_no)
{
	stack_t *temp = *head;

	(void)line_no;
	while (temp && temp->n > 0 && temp->n < 128)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
