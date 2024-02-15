#include "hash_tables.h"

/**
  * hash_table_get - function that retrieves a value associated with a key.
  * @ht: is the hash table you want to look into
  * @key: is the key you are looking for
  * Return: value associated with the element, or NULL if key not found
  */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int indx;
	hash_node_t *head;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	indx = key_index((const unsigned char *)key, ht->size);
	if (indx >= ht->size || ht->array[indx] == NULL)
		return (NULL);
	head = ht->array[indx];

	while (head != NULL)
	{
		if (strcmp(head->key, key) == 0)
			return (head->value);
		head = head->next;
	}
	return (NULL);
}
