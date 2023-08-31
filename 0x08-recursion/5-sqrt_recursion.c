#include "main.h"
int helper_sqrt_recursion(int n, int i);
/**
  *helper_sqrt_recursion - returns the natural square root of a num
  *@n : num to caalculate sqrt of
  *
  *Return : the resulting sqrt
  */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (helper_sqrt_recursion(n, 0));
}

/**
 * actual_sqrt_recursion - recurses to find the natural
 * square root of a number
 * @n: number to calculate the sqaure root of
 * @i: iterator
 *
 * Return: the resulting square root
 */
int helper_sqrt_recursion(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (helper_sqrt_recursion(n, i + 1));
}

