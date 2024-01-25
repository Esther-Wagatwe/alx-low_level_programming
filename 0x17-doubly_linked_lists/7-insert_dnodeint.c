#include "lists.h"

/**
  * insert_dnodeint_at_index - function that inserts a node at a given position
  * @h: head of list
  * @idx: position at which the node is to be inserted
  * @n: data to insert at idx
  *
  * Return: the address of the new node, or NULL if it failed
  */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *head, *new;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	/* initialize the new node */
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	/* handle if idx = 0 (at the beginning) */
	if (idx == 0)
	{
		new->next = *h;
		if (*h != NULL)
			(*h)->prev = new;
		*h = new;
		return (new);
	}
	head = *h;
	while (head != NULL && i < idx)
	{
		head = head->next;
		i++;
	}
	/* check if index is ou of bounds */
	if (head == NULL)
	{
		free(new);
		return (NULL);
	}
	/* update pointer of neighbouring nodes */
	new->next = head;
	new->prev = head->prev;
	if (head->prev != NULL)
		head->prev->next = new;
	head->prev = new;
	return (new);
}
