#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
  * *string_nconcat - concatenates n bytes of a string to another string
 * @s1: string to append to
 * @s2: string to concatenate from
 * @n: number of bytes from s2 to concatenate to s1
 *
 * Return: pointer to the resulting string
 */


char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	size_t s1_len, s2_len;
	unsigned int i;
	char *str;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	s1_len = strlen(s1);
	s2_len = strlen(s2);

	if (n >= s2_len)
	{
		n = s2_len;
	}
	str = malloc(s1_len + n + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	strcpy(str, s1);

	for (i = 0; i < n; i++)
	{
		str[s1_len + i] = s2[i];
	}
	str[s1_len + n] = '\0';
	return (str);
}
