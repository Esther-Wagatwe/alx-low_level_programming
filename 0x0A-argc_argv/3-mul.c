#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (Success), 1 (Error)
 */

int main(int argc, char *argv[])
{
	int num1, num2, product = 0;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	if ((num1 == 0 && argv[1][0] != '0') || (num2 == 0 && argv[2][0] != '0'))
	{
		printf("Error\n");
		return (1);
	}

	product = num1 * num2;

	printf("%d\n", product);
	return (0);
}

