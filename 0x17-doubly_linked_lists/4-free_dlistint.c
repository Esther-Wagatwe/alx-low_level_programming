#include "lists.h"

/**
  * free_dlistint - function that frees a dlistint_t list.
  * @head: head of list
  *
  * Return: void
  */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *new;

	if (head != NULL)
	{
		/* ensure that the head pointer is at the head of the list */
		while (head->prev != NULL)
			head = head->prev;
	}
	/* iterate through the linked list and free each node */
	while ((new = head) != NULL)
	{
		head = head->next;
		free(new);
	}
}
