#include "lists.h"

/**
 * print_list - Prints the elements of a linked list and counts nodes.
 * @h: Pointer to the head of the linked list.
 *
 * Return: The number of nodes printed.
 */

size_t print_list(const list_t *h)
{
	size_t elements = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%d] %s\n", h->len, h->str);
		}
		h = h->next;/*move to the next node*/
		elements++;/*increment node count*/
	}
		return (elements);
}
