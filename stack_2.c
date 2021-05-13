#include "monty.h"
/**
 * swap_stack - Function that pushes an element to the stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 */
void swap_stack(stack_t **top, unsigned int line_number)
{
	stack_t *node_1_swap, *node_2_swap;

	node_1_swap = *top;
	if (*top && (*top)->next)
	{
		node_2_swap = node_1_swap->next; /* Address of second node*/
		node_1_swap->prev = node_1_swap->next;
		node_1_swap->next = node_2_swap->next;
		if (node_2_swap->next) /* if node_3 exist */
			(node_2_swap->next)->prev = node_1_swap;
		node_2_swap->prev = NULL;
		node_2_swap->next = node_1_swap;
		*top = node_2_swap;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		/*free(gv.tokens);*/
		/*fclose(gv.fp);*/
		exit(EXIT_FAILURE);
	}
}
