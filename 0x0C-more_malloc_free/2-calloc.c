#include <stdio.h>
#include <stdlib.h>
/**
 * *_calloc - allocates memory for an array
 * @nmemb: number of elements in the array
 * @size: size of each element
 *
 * Return: pointer to allocated memory
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *str;
	size_t i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	str = malloc(nmemb * size);
	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (nmemb * size); i++)
	{
		str[i] = 0;
	}
	return (str);
}
