#include "monty.h"
int take_num;

/**
 * push_stack - Function that pushes an element to the stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 */
void push_stack(stack_t **stack, unsigned int nline)
{
        stack_t *new;
        if (stack == NULL)
        {
                fprintf(stderr, "L%d: stack not found\n", nline);
                exit(EXIT_FAILURE);
        }
        new = malloc(sizeof(stack_t));
        if (new == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }
        new->next = *stack;
        new->prev = NULL;
        new->n = take_num;
        if (*stack)
                (*stack)->prev = new;
        *stack = new;
}
/**
 * pint_stack - Function that print the valueat top of stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 */
void pint_stack(stack_t **top, unsigned int line_number)
{
        stack_t *tmp = *top;

        if (tmp == NULL)
        {
                fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
                exit(EXIT_FAILURE);
        }
        else
                printf("%d\n", tmp->n);
}
