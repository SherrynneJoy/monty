#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "monty.h"

/**
 * execute - runs the interpreter
 * @lineptr: ptr to a line/instruction
 * @stack: ptr to stack
 * @count: line number
 * @fp: pointer to second file
 * Return: 0 on success
 */
int execute(char *lineptr, stack_t **stack, unsigned int count, FILE *fp)
{
	instruction_t ops[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *ptr;

	ptr = strtok(lineptr, " \n\t");
	if (ptr && ptr[0] == '#')
		return (0);
	comm.arg = strtok(NULL, " \n\t");
	while (ops[i].opcode && ptr)
	{
		if (strcmp(ptr, ops[i].opcode) == 0)
		{
			ops[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (ptr && ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, ptr);
		fclose(fp);
		free(lineptr);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
