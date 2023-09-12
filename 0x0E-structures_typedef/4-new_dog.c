#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dog.h"
/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog (Success), NULL otherwise
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog_ptr;

	new_dog_ptr = malloc(sizeof(dog_t));

	if (new_dog_ptr == NULL)
	{
		return (NULL);
	}
	(*new_dog_ptr).name = malloc(sizeof(char) * (strlen(name) + 1));
	if ((*new_dog_ptr).name == NULL)
	{
		free(new_dog_ptr);
		return (NULL);
	}

	(*new_dog_ptr).owner = malloc(sizeof(char) * (strlen(name) + 1));
	if ((*new_dog_ptr).owner == NULL)
	{
		free((*new_dog_ptr).name);
		free(new_dog_ptr);
		return (NULL);
	}

	new_dog_ptr->name = name;
	new_dog_ptr->age = age;
	new_dog_ptr->owner = owner;

	return (new_dog_ptr);
}
