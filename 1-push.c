#include "monty.h"
/**
 * f_push - adds an element to a stack
 * @head: head ptr
 * @line_no: line no
 */
void f_push(stack_t **head, unsigned int line_no)
{
	int m, n;

	if (!data.arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_no);
		freedata();
		exit(EXIT_FAILURE);
	}
	for (n = 0; data.arg[n] != '\0'; n++)
	{
		if (!isdigit(data.arg[n]) && data.arg[n] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_no);
			freedata();
			exit(EXIT_FAILURE);
		}
	}
	m = atoi(data.arg);
	if (data.lifi == 1)
		addnode(head, m);
	else
		addnodeend(head, m);
}
