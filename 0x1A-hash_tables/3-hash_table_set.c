#include "hash_tables.h"

/**
  * hash_table_set - func that adds an element to the hash table
  * @ht: the hash table you want to add or update the key/value to
  * @key: is the key. key can not be an empty string
  * @value: value associated with the key. value must be duplicated.
  * Return: 1 if it succeeded, 0 otherwise
  */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int indx, j;
	char *value_dup;
	hash_node_t *new_node;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	value_dup = strdup(value);
	if (value_dup == NULL)
		return (0);
	indx = key_index((const unsigned char *)key, ht->size);
	for (j = indx; ht->array[j]; j++)
	{
		if (strcmp(ht->array[j]->key, key) == 0)
		{
			free(ht->array[j]->value);
			ht->array[j]->value = value_dup;
			return (1);

		}
	}

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(value_dup);
		return (0);
	}
	new_node->key = strdup(key);
	if (new_node == NULL)
	{
		free(new_node);
		return (0);
	}
	new_node->value = value_dup;
	new_node->next = ht->array[indx];
	ht->array[indx] = new_node;

	return (1);
}
