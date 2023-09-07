#include "main.h"
/**
  * malloc_checked - Allocate memory
  * @b: number of bytes to allocate
  * Return: 0 success
  */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);

	if (ptr == NULL)
		exit(98);
	else
		return (ptr);
}
