#include <stdio.h>
#include <stdlib.h>
/**
  * array_range - function that creates an array of integers.
  * @min: minimum value of array
  * @max: maximum value of arrays
  * Return: success 0
 */
int *array_range(int min, int max)
{
	int i, total_elements, current_val;
	int *ptr;

	if (min > max)
	{
		return (NULL);
	}
	total_elements = max - min + 1;
	ptr = malloc(total_elements * sizeof(int));

	if (ptr == NULL)
	{
		return (NULL);
	}
	current_val = min;
	for (i = 0; i < total_elements; i++)
	{
		ptr[i] = current_val;
		current_val++;
	}
	return (ptr);
}
