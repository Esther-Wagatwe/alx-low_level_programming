#include "main.h"

/**
 * binary_to_uint - function to convert a binary number to an usignrd integer
 * @b: the binary number to be converted
 * Return: The converted number or 0 if b is NULL and if a character is not 0/1
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int i = 0;

	if (b == NULL)
		return (0);
	while (b[i] != '\0')
	{
		if (b[i] != '0' &&  b[i] != '1')
		{
			return (0);
		}
		result = result * 2 + (b[i] - '0');
		i++;
	}
	return (result);
}

