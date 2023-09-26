#include "lists.h"

/**
  * reverse_listint - function that reverses a linked list
  * @head: the head of the list
  * Return: pointer to 1st node of reversed list
  */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *nxt = NULL;
	listint_t *prev = NULL;

	while (*head != NULL)
	{
		nxt = (*head)->next;/*Store the next node temporarily*/
		(*head)->next = prev;
		prev = *head;
		*head = nxt;
	}
	*head = prev;
	return (*head);
}
