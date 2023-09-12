#include <stdio.h>
#include <stdlib.h>
#include "dog.h"
/**
  * _strlen - calculates length of string
  * @str: string to check length
  * Return: success i
  */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}

/**
  * _strcpy - copy string
  * @s1: destination
  * @s2: Origin
  * Return: success s1
  */
char *_strcpy(char *s1, char *s2)
{
	int i, j = _strlen(s2) + 1;

	for (i = 0; i < j; i++)
	{
		s1[i] = s2[i];
	}
	return (s1);
}
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
	(*new_dog_ptr).name = malloc(sizeof(char) * (_strlen(name) + 1));
	if ((*new_dog_ptr).name == NULL)
	{
		free(new_dog_ptr);
		return (NULL);
	}

	(*new_dog_ptr).owner = malloc(sizeof(char) * (_strlen(owner) + 1));
	if ((*new_dog_ptr).owner == NULL)
	{
		free((*new_dog_ptr).name);
		free(new_dog_ptr);
		return (NULL);
	}

	new_dog_ptr->name = _strcpy(new_dog_ptr->name, name);
	new_dog_ptr->age = age;
	new_dog_ptr->owner = _strcpy(new_dog_ptr->owner, owner);

	return (new_dog_ptr);
}
