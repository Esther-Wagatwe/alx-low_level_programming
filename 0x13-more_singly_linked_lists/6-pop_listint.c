#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: pointer to a pointer to the head of the list
 * Return: the head node's data (n), or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int data;

	if (head == NULL || *head == NULL)
		return (0);
	/* Create a temporary pointer to the current head node */
	temp = *head;
	/*data is used to store the data from the headnode to be deleted.*/
	data = temp->n;
	*head =  (*head)->next;/* Update the head pointer to the next node */
	free(temp); /* Free the old head node */
	return (data); /* Return the data from the old head node */
}
