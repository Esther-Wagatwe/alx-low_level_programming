#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a linked list
 * @head: double pointer to the list_t list
 * @str: new string to be added in the node
 *
 * Return: the address of the new element
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *newnode;

	newnode = malloc(sizeof(list_t));
	if (newnode == NULL)
	{
		return (NULL);
	}
	/*duplicates a string and store it in newnode*/
	newnode->str = strdup(str);
	/*update the new node*/
	newnode->len = strlen(newnode->str);
	newnode->next = *head;
	/*update head pointer*/
	*head = newnode;

	return (*head);
}