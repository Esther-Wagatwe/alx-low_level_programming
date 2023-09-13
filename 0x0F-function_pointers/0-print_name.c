#include <stdio.h>
#include "function_pointers.h"

/**
  * print_name - function that prints a name
  * @name: Pointer to a character used to pass the name to print
  * @f: pointer to a function with no return and takes char * as an argument
  * char *: parameter list that the function pointed to by f should accept
  * Return: Void
  */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	/* call the function pointer to print the name*/
	f(name);
}
