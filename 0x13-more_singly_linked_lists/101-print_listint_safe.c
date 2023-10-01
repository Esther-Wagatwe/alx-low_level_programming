#include "lists.h"
#include <stdio.h>

size_t num_unique_nodes(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * num_unique_nodes - Counts the number of unique nodes
 *                   in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t num_unique_nodes(const listint_t *head)
{
	const listint_t *slow, *fast;
	size_t nodes = 0;

	if (head == NULL)
		exit(98);

	slow = head;
	fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
				nodes++;
			}

			return (nodes);
		}
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;

	nodes = num_unique_nodes(head);

	while (head != NULL)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		if (index == nodes && nodes > 0)
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			exit(98);
		}
		head = head->next;
		index++;
	}
	return (index);
}
