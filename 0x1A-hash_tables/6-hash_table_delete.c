#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: The hash table to delete.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head;
	hash_node_t *node, *current;
	unsigned long int j;

	head = ht;
	for (j = 0; j < ht->size; j++)
	{
		if (ht->array[j] != NULL)
		{
			node = ht->array[j];
			while (node != NULL)
			{
				current = node->next;
				free(node->key);
				free(node->value);
				free(node);
				node = current;
			}
		}
	}
	free(head->array);
	free(head);
}
