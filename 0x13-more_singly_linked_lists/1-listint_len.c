#include "lists.h"

/**
  * listint_len - function that returns number of nodes
  * @h: linked list of type listint_t
  * Return: Number of nodes
  */

size_t listint_len(const listint_t *h)
{
	size_t elements = 0;

	while (h != NULL)
	{
		h = h->next;
		elements++;
	}
	return (elements);
}
