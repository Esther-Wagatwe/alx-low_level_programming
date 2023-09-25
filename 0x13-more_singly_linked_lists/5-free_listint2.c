#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - frees a linked list and sets the head to NULL
 * @head: pointer to a pointer to the listint_t list to be freed
 */
void free_listint2(listint_t **head)
{
	listint_t *current, *temp;

	if (head == NULL || *head == NULL)
		return; /* If the list or head pointer is NULL, nothing to free */

	current = *head; /* Start from the head of the list */

	while (current != NULL)
	{
		temp = current->next; /* Store the next pointer before freeing */
		free(current); /* Free the current node */
		current = temp; /* Move to the next node */
	}

	*head = NULL; /* Set the head pointer to NULL to indicate an empty list */
}

