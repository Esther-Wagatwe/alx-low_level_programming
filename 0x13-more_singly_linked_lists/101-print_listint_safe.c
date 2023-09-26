#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head of the linked list
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow, *fast;
	size_t count = 0;

	if (head == NULL || head->next == NULL)
		exit(98);

	slow = head;
	fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;

		if (slow == fast)/*loop detected*/
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			printf(" [%p] %d\n", (void *)slow, slow->n);
			printf("-> [%p] %d\n", (void *)fast->next, fast->next->n);
		 	return (count);
		}
	}
	return (count);
}
