#include "main.h"
/**
 * puts2 - function should print only one character out of two
 * starting with the first one
 * @str: input
 * Return: print
 */
void puts2(char *str)
{
	int n = 0;

	while (str[n] != '\0')
	{
		if ((n % 2) == 0)
		{
			_putchar(str[n]);
		}
		n++;
	}
	_putchar('\n');
}
