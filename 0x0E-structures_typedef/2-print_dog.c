#include <stdio.h>
#include "dog.h"

/**
 * print_dog - prints a struct dog
 * @d: struct dog to print
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
	{
		return;
	}
	else
	{
		printf("Name:%s\n", d->name ? d->name : "(nil)");
		printf("Age:%f\n", d->age ? d->age : 0.0);
		printf("Owner:%s\n", d->owner ? d->owner : "(nil)");
	}
}
