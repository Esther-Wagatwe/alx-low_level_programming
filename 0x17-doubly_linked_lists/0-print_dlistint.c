#include "lists.h"

/**
  * print_dlistint - function that prints all the elements of doublelinked list
  * @h: head of doubly linked list
  * Return: number of nodes
  */
size_t print_dlistint(const dlistint_t *h)
{
	size_t elements = 0;

	if (h == NULL)
		return (elements);
	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		elements++;
		h = h->next;
	}
	return (elements);
}
