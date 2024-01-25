#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a node at a given position
 * @h: Pointer to the head of the doubly linked list
 * @idx: Index of the node to be inserted
 * @n: Data for the new node
 *
 * Return: Address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp = *h;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	/* Step 3: Initialize the New Node */
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (idx == 0)
	{
		new_node = add_dnodeint(h, n);
		return (new_node);
	}
	if (temp == NULL)
	{
		new_node = add_dnodeint_end(h, n);
		return (new_node);
	}
	while (temp != NULL && i < idx)
	{
		temp = temp->next;
		i++;
	}
	/* Check if the index is out of bounds */
	if (temp == NULL && i != idx)
	{
		free(new_node);
		return (NULL);
	}
	/* Update pointers of neighboring nodes */
	new_node->next = temp;
	new_node->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = new_node;
	temp->prev = new_node;
	return (new_node);
}

