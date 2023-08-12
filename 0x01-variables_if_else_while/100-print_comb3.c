#include <stdio.h>
/**
 *main - prints all possible combinations of two digits
 * Return: ALways 0 (Success)
 */
int main(void)
{
	int i = '0';
	int j = '1';

	while (i <= '9')
	{
		while (j <= '9')
		{
			if (!(i > j) || (i == j))
					{
					putchar (i);
					putchar (j);
					if (i == '8' & j == '9')
						{
						putchar ('\n');
						}
					else
						{
							putchar (',');
							putchar (' ');
						}
					}
			j++;
		 }
		j = '0';
		i++;
	}
	return (0);
}
