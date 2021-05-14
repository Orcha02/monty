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
		exit(EXIT_FAILURE);
	}
}
/**
 * _div - Divides the seccond top element of the stack by the top element
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 */

void _div(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*top)->next;
	tmp->n = (tmp->n) / (*top)->n;
	pop_stack(top, line_number);
}
/**
 *_mod - Module of the second top element of the stack by the top element
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 */
void _mod(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next ==  NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*top)->next;
	tmp->n = (tmp->n) % (*top)->n;
	pop_stack(top, line_number);
}
/**
 * _pchar - prints the char at the top of the stack, followed by a new line.
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 */
void _pchar(stack_t **top, unsigned int line_number)
{
	int character;

	if (*top == NULL || top == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	character = (*top)->n;
	if (((character >= 'a') && (character <= 'z')) ||
	    ((character >= 'A') && (character <= 'Z')))
		printf("%c\n", character);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_stack(top);
		exit(EXIT_FAILURE);
	}
}
