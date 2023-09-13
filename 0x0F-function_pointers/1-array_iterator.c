#include <stdio.h>
#include "function_pointers.h"

/**
  * array_iterator - perform an action in an array.
 * @array: array holding the elements
 * @size: is the size of the array
* @action: is a pointer to the function you need to use
* Return: Void
*/

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL || action == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
