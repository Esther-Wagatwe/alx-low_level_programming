
#include <stdio.h>
#include <math.h>

/**
 * main - finds and prints the largest prime factor of the number 612852475143
 * followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int i, maxf;
	long num = 612852475143;

	for (i = 1; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			maxf = num / i;
		}
	}
	printf("%ld\n", maxf);
	return (0);
}
