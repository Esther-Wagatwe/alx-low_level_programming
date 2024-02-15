#include "hash_tables.h"

/**
  * hash_table_print -  function that prints a hash table.
  * @ht: is the hash table
  *
  * Return: void
  */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *head;
	unsigned char flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			if (flag == 1)
				printf(", ");

			head = ht->array[i];
			while (head != NULL)
			{
				printf("'%s': '%s'", head->key, head->value);
				head = head->next;
				if (head != NULL)
					printf(",");
			}
			flag = 1;
		}
	}
	printf("}\n");
}
