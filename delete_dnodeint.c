#include "monty.h"
/**
 * delete_dnodeint_at_index - function that inserts a new node at a
 * given position.
 * @head: Double pointer with address to head of a double linked list.
 * @index: The index of the node that should be deleted. Index starts at 0.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *copy;
	unsigned int position;

	copy = *head;
	for (position = 0; copy; position++, copy = copy->next)
	{
		if (position == index)
		{
			if (position == 0) /*Head node*/
			{
				if (copy->next != NULL)
				{
					*head = copy->next;
					(copy->next)->prev = NULL;
				}
				else
					*head = NULL;
			}
			else if (copy->next == NULL && copy->prev) /*Tail node*/
				(copy->prev)->next = NULL;
			else
			{
				(copy->prev)->next = copy->next;
				(copy->next)->prev = copy->prev;
			}
			free(copy);
			return (1);
		}
	}
	return (-1);
}
