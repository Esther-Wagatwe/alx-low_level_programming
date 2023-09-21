#include "lists.h"

/**
 * free_list - frees a linked list
 * @head: list_t list to be freed
 */
void free_list(list_t *head)
{
	list_t *next;

	while (head != NULL)
	{
		next = head->next;/*keep a reference to the next node*/
		free(head->str);
		free(head);/*free current node*/
		head = next;/*move to the next*/
	}
}
