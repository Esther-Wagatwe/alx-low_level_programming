#include "lists.h"

/**
  * delete_nodeint_at_index - function to delete node at a certain index
  * @head: The first node of the linked list
  * @index: The index of the node to delete
  * Return: 1 if it succeeded, -1 if it failed
  */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp;
	listint_t *current;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	current = *head;
	while (current->next != NULL && i < index - 1)
	{
		current = current->next;
		i++;
	}
	if (current->next == NULL)
		return (-1);
	temp = current->next;
	current->next = current->next->next;
	free(temp);
	return (1);
}
