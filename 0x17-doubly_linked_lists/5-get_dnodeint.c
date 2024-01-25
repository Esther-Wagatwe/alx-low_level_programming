#include "lists.h"

/**
  * get_dnodeint_at_index - function that returns the nth node of a list
  * @head: head of the doubly linked list
  * @index: index of the node
  *
  * Return: NULL if node does not exist, else the node
  */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *h;
	unsigned int i = 0;

	h = head;
	if (h == NULL)
		return (NULL);
	/*while (h->prev != NULL)*/
		/*h = h->prev;*/
	while (h != NULL && i < index)
	{
		h = h->next;
		i++;
	}
	return (h);
}
