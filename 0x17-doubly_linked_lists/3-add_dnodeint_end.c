#include "lists.h"

/**
  * add_dnodeint_end - function that adds a new node at the end of a list
  * @head: head of double linked list
  * @n: data of the new list
  *
  * Return: the address of the new element, or NULL if it failed
  */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *h;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	h = *head;
	if (h == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	while (h->next != NULL)
		h = h->next;
	h->next = new;
	new->prev = h;

	return (new);
}
