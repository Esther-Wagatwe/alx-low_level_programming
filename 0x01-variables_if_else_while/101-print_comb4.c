#include<stdio.h>
/**
  * main - prints all different possible combinations of three digit numbers
  *
  * Return: 0 when successful
  */
int main(void)
{
	int j, k, l;

	for (j = 48 ; j <= 57 ; j++)
	{
		for (k = 49 ; k <= 57 ; k++)
		{
			for (l = 50 ; l <= 57 ; l++)
			{
				if (l > k && k > j)
				{
					putchar(j);
					putchar(k);
					putchar(l);
					if (j != 55 || k != 56)
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
