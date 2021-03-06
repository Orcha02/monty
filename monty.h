#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_t *add_dnodeint(stack_t **head, const int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
size_t print_dlistint(const stack_t *h);

/*get_opcode*/
int get_opcode(char *token, unsigned int line, stack_t **stack);

/* stack */
void pint_stack(stack_t **top, unsigned int line_number);
void pall_stack(stack_t **top, unsigned int line_number);
void push_stack(stack_t **top, unsigned int line_number);
void free_stack(stack_t **stack);
void pop_stack(stack_t **top, unsigned int line_number);

/* stack_2 */
void swap_stack(stack_t **top, unsigned int line_number);
void _div(stack_t **top, unsigned int line_number);
void _mod(stack_t **top, unsigned int line_number);
void _pchar(stack_t **top, unsigned int line_number);

/*global*/
int take_num;

/* stack_3 */
void _add(stack_t **top, unsigned int line_number);
void _nop(stack_t **top, unsigned int line_number);
void _sub(stack_t **top, unsigned int line_number);
void _mul(stack_t **top, unsigned int line_number);

/* monty.c */
int is_number(char *token);
int open_file_to_read(char *filename, stack_t **stack);
void _free(char *buff_line, FILE *in_file);

#endif /* MONTY_H */
