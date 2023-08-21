#include "main.h"

/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int n = -1;

	do {
		n++;
		dest[n] = src[n];
	}
	while (src[n] != '\0');
	return (dest);
}
