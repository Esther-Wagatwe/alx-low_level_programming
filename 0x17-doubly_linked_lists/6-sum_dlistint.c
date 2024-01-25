#include "lists.h"
/**
  * sum_dlistint -  function that returns the sum of all the data (n) of a list
  * @head: head of the list
  *
  * Return: if the list is empty, return 0 else sum of all data
  */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *h;
	int sum = 0;

	h = head;
	if (h == NULL)
		return (0);
	while (h != NULL)
	{
		sum += h->n;
		h = h->next;
	}
	return (sum);
}
