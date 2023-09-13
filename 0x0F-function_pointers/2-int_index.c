#include <stdio.h>
#include "function_pointers.h"

/**
  * int_index - function that searches for an integer.
  * @array: array containing elements
  * @size: is the number of elements in the array
  * @cmp: pointer to the function to be used to compare values
  * Return: 0 success
  */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size <= 0 || array == NULL || cmp == NULL)
		return (-1);
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}

