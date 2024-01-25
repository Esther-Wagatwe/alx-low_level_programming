#include "lists.h"

/**
  * dlistint_len - function that returns the number of elements in dlinked list
  * @h: head of the doubly linked list
  *
  * Return: number of elements
  */
size_t dlistint_len(const dlistint_t *h)
{
	size_t elements = 0;

	if (h == NULL)
		return (elements);
	if (h->prev != NULL)
		h = h->prev;
	while (h != NULL)
	{
		elements++;
		h = h->next;
	}
	return (elements);
}
