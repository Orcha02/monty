#include "monty.h"
/**
 * get_op_code - contain the function that will perform the operation
 * @token: operation code
 * @line: line readed
 * Return: void
 */
void (*get_opcode(char *token, unsigned int line)) (stack_t **, unsigned int)
{
	int i;
	instruction_t operation[] = {
		{"push", push_stack},
		{"pall", pall_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"swap", swap},
	};
	for (i = 0; operation[i].opcode != NULL; i++)
	{
		if (strcmp(token, operation[i].opcode) == 0)
		{
			return (operation[i].f)
		}
	}
	Invalid_instruction_error(token, line);
	return (NULL);
}
