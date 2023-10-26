#include "main.h"

/**
 * print_binary - convert a number from  decimal format fo binary
 * @n: number to be converted
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int currentbit;

	for (i = 63; i >= 0; i--)
	{
		currentbit = n >> i;/* Right-shift 'n' by 'i' bits */

		if (currentbit & 1)
		{
			_putchar('1'); /* Print '1' for a set bit */
			count++;
		}
		else if (count)
		{
			_putchar('0'); /* Print '0' for trailing zeros */
		}
	}
	if (!count)
	{
		_putchar('0'); /* If there are no significant bits, print '0' */
	}
}
