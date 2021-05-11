#include "monty.h"
/**
 * add_dnodeint - Add a new node at the beginning of a listint_t list.
 * @head: get a pointer to pointer head of the linked list.
 * @n: get a integer number of the node to add.
 * Return: The address of the new element, or NULL if it failed.
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	/* create new node */
	stack_t *newnode;

	/* allocate memory for the new node */
	newnode = malloc(sizeof(stack_t));
	/* check if newnode was created */
	if (newnode == NULL)
	{
		return (NULL);
	}
	/* set values of newnode */
	/* put the new int on the list */
	newnode->n = n;
	/* set new directions */
	newnode->prev = NULL;
	newnode->next = NULL;
	/* check if not exist list actually */
	if (!*head)
	{
		*head = newnode;
	}
	else
	{
		newnode->next = *head;
		/* update direction of the previous node */
		(*head)->prev = newnode;
		/* update the direction of head for the next node */
		*head = newnode;
	}
	return (newnode);
}
