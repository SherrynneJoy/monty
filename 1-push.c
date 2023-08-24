#include "monty.h"
/**
 * f_push - adds an element to a stack
 * @head: head ptr
 * @count: line no
 */
void f_push(stack_t **head, unsigned int count)
{
	int n, m = 0, flag = 0;

	if (comm.arg)
	{
		if (comm.arg[0] == '-')
			m++;
		for (; comm.arg[m] != '\0'; m++)
		{
			if (comm.arg[m] > 57 || comm.arg[m] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(comm.fp);
			free(comm.lineptr);
			freestack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(comm.fp);
		free(comm.lineptr);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(comm.arg);
	if (comm.lifi == 0)
		addnode(head, n);
}
