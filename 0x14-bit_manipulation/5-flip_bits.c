
/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to get from one number to another.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int currentvalue;
	unsigned long int exclusiveor = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		currentvalue = exclusiveor >> i;
		if (currentvalue & 1)
			count++;
	}

	return (count);
}

