#include "monty.h"
/**
 * _add - Function that adds the top two elements of the stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 */
void _add(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*top)->next;
	tmp->n += (*top)->n;
	pop_stack(top, line_number);
}
void _sub(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*top)->next;
	tmp->n -= (*top)->n;
	pop_stack(top, line_number);
}
#include "monty.h"
/**
 * _div - Function that adds the top two elements of the stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 */
void _div(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*top)->next;
	tmp->n /= (*top)->n;
	pop_stack(top, line_number);
}
