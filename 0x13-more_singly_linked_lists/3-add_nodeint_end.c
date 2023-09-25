#include "lists.h"

/**
  * add_nodeint_end - function that adds a new node at the end of a list.
  * @head: pointer to the first element in the list
  * @n: value of newnode
  * Return: pointer to the new node, or NULL if it fails
  */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newnode, *current;

	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = n;
	newnode->next = NULL;

	if (*head == NULL)
	{
		*head = newnode;
		return (newnode);
	}
	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newnode;

	return (newnode);
}
