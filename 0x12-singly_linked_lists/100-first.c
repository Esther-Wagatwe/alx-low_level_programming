#include "lists.h"

void prints(void) __attribute__((constructor));
/**
 * prints - prints a sentence before the main
 * Return: void
 */
void prints(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
