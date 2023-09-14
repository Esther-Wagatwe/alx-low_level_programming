#include <stdio.h>
#include "variadic_functions.h"
#include <stdarg.h>

/**
  * sum_them_all - function that returns sum of all parameters
  * @n: The parameter
  *
  * Return: sum of parameters
  */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int sum = 0;
	va_list arg;

	if (n == 0)
		return (0);

	va_start(arg, n);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(arg, unsigned int);
	}
	return (sum);
}
