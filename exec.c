#include "monty.h"

/**
 * f_opecodes - executes the program
 * @opcode: monty bytecode
 */
void (*f_opecodes(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		/*{"stack", f_stack},*/
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
