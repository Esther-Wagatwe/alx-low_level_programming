#include "lists.h"

/**
  * print_listint - function that printss elements of a string
  * @h: linked list of type listint_t to print
  * Return: number of nodes
  */

size_t print_listint(const listint_t *h)
{
	size_t elements = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		elements++;
	}
	return (elements);
}
