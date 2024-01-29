#include <stdio.h>
#define div my_div
#include <stdlib.h>
#undef div
/**
  * div - divides two integers
  * @a: first int
  * @b: second int
  * Return: division
  */
int div(int a, int b)
{
	return (a / b);
}
