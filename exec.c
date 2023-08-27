#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "monty.h"

/**
 * f_opcodes - ptr to a stack
 * @opcode: opcode
 * Return: opcode
 */
void (*f_opcodes(char *opcode))(stack_t **stack, unsigned int line_no)
{
	instruction_t ops[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, opcode) == 0)
			break;
		i++;
	}
	return (ops[i].f);
}
