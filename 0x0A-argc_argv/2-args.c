#include <stdio.h>
/**
 * main - prints the name of the program
 * @argc: argument count
 * @argv: vector count
 *
 * Return: 0 success
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
	return (0);
}
