#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number or 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int i = 0, result = 0;

	if (!b)
		return (0);
	while (*b)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		result = 2 * result + (b[i] - '0');
		b++;
	}
	return (result);
}
