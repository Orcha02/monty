#include "monty.h"
/**
 * get_op_code - contain the function that will perform the operation
 * @token: operation code
 * @line: line readed
 * Return: 0 on success and 1 if fails
 */
int get_opcode(char *token, unsigned int line, stack_t **stack)
{
        instruction_t operation[] = {
                {"push", push_stack},
                /*{"pall", pall_stack},*/
                {"pint", pint_stack},
                /*{"pop", pop_stack},*/
                /*{"swap", swap},*/
                {NULL, NULL}
        };
        int i;

        for (i = 0; operation[i].opcode; i++)
        {
                if (strcmp(token, operation[i].opcode) == 0)
                {
                        operation[i].f(stack, line);
                        return (0);
                }
        }
        return (1);
}
