#include "lists.h"

/**
  * insert_nodeint_at_index - function to insert node at position index
  * @head: pointer to the first node in the list
  * @idx: position to insert new node
  * @n: data to insert at new node
  * Return: address of the new node, or NULL if it failed
  */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *newnode, *current;
	unsigned int i = 0;

	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL || head == NULL)
		return (NULL);
	newnode->n = n;
	newnode->next = NULL;

	if (idx == 0)
	{
		newnode->next = *head;
		*head = newnode;
		return (newnode);
	}

	current = *head;
	/*Traverse the list to reach the node just before the desired position*/
	while (current != NULL && i < idx - 1)
	{
		current = current->next;
		i++;
	}
	/*Check if it's not possible to insert at the desired index*/
	if (current == NULL)
		return (NULL);
	newnode->next = current->next;
	current->next = newnode;
	return (newnode);
}
