#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"
/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    stack_t *head;
    stack_t *new;
    stack_t hello = {8, NULL, NULL};
    size_t n;

    head = &hello;
    new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        dprintf(2, "Error: Can't malloc\n");
        return (EXIT_FAILURE);
    }
    new->n = 9;
    head->prev = new;
    new->next = head;
    new->prev = NULL;
    head = new;
    add_dnodeint(&head, 98);
    add_dnodeint(&head, 402);
    add_dnodeint(&head, 505);
    add_dnodeint(&head, 1024);
    n = print_dlistint(head);
    free(new);

    return (EXIT_SUCCESS);
}
