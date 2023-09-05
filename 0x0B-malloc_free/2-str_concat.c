#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * str_concat - get ends of input and add together for size
 * @s1: input one to concat
 * @s2: input two to concat
 * Return: concat of s1 and s2
 */

char *str_concat(char *s1, char *s2)
{
	size_t total_length;
	char *str;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	total_length = strlen(s1) + strlen(s2);
	str = (char *)malloc((total_length + 1) * sizeof(char));

	if (str == NULL)
	{
		return (NULL);
	}

	strcpy(str, s1);
	strcat(str, s2);

	return (str);
}
