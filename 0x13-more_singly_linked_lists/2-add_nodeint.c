#include "lists.h"

/**
  * add_nodeint - function that adds a new node at the beginng of a linked-list
  * @head: pointer to the first node in the list
  * @n: data to insert to the new node
  * Return: pointer to the newnode
  */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newnode;

	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = n;
	newnode->next = *head;
	*head = newnode;

	return (newnode);
}
