#include "monty.h"
/**
 * print_dlistint - Prints all the elements of a listint_t list.
 * @h: Get a pointer to linked list listint_t.
 * Return: Return the number of nodes.
 */
size_t print_dlistint(const stack_t *h)
{
	size_t counter = 0; /* count the number of nodes */
	/* iterate as long as a node exists */
	for (counter = 0; h != NULL; counter++)
	{
		printf("%d\n", h->n); /* search the data in "n" inside of h */
		h = h->next; /* in the end, update the adress of "h" and go */
	}
	return (counter);
}
