#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
  * _strdup - duplicate to new space location
  * @str: pointer to character string
  * Return: 0 success
  */
char *_strdup(char *str)
{
	char *ptr;
	int i, j;

	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
	}
	ptr = malloc(sizeof(char) * (i + 1));
	
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (j = 0; str[j]; j++)
	{
		ptr[j] = str[j];
	}
	ptr[j] = '\0';

	return (ptr);
}
