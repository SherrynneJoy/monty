#include "monty.h"
#include <string.h>
#include <stdlib.h>
/**
 * f_push - adds an element to a stack
 * @head: head ptr
 * @count: line no
 */
void f_push(stack_t **head, unsigned int count)
{
	int n, m = 0, flag = 0;

	if (drive.arg)
	{
		if (drive.arg[0] == '-')
			m++;
		for (; drive.arg[m] != '\0'; m++)
		{
			if (drive.arg[m] > 57 || drive.arg[m] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(drive.fp);
			free(drive.lineptr);
			freestack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(drive.fp);
		free(drive.lineptr);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(drive.arg);
	if (drive.lifi == 0)
		addnode(head, n);
}
