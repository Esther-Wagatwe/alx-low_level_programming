#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"
/**
 * main - Prints the result of simple operations.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *operator;
	int (*operation)(int, int);
	int num1, num2, result;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	operator = argv[2];
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	operation = get_op_func(operator);

	if (operation == NULL || operator[1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}
	if ((*operator == '/' && num2 == 0) || (*operator == '%' && num2 == 0))

	{
		printf("Error\n");
		exit(100);
	}
	result = operation(num1, num2);

	printf("%d\n", result);

	return (0);
}
