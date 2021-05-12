#include "monty.h"
/**
 * free_dlistint - Free a listint_t list.
 * @head: Head of linked listint_t list.
 */
void free_dlistint(stack_t *head)
{
	/* create a tail node wich get the next direction from the freeded node */
	stack_t *tailnode = head;
	/* go to every node and free them */
	for (; head;)
	{
		/* the tail get the direction of the next node */
		tailnode = head->next;
		/* free the current node */
		free(head);
		/* head will get the direction gatherertd of the previos node */
		head = tailnode;
	}
}
