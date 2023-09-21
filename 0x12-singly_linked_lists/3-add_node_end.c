#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a linked list
 * @head: double pointer to the list_t list
 * @str: string to put in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newnode_end;
	unsigned int i, count = 0;
	list_t *temp;

	newnode_end = malloc(sizeof(list_t));
	if (newnode_end == NULL)
		return (NULL);
	newnode_end->str = strdup(str);
	for (i = 0; str[i] != '\0'; i++)
		count++;
	newnode_end->len = count;
	newnode_end->next = NULL;
	/*store head in temporary*/
	temp = *head;
	/*if the list is empty,the new node becomes the head*/
	if (temp == NULL)
		*head = newnode_end;
	else
	{
		/*keep going untill encounters a null character*/
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newnode_end;
	}
	return (newnode_end);
}
