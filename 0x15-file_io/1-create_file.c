#include "main.h"
/**
 * stringLength - function that calculates string length
 * @str: string whose length is to be calculated
 *
 * Return: length of the string
 */
int stringLength(const char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
  * create_file - function that creates a file
  * @filename: the name of the file to create
  * @text_content: is a NULL terminated string to write to the file
  * Return: 1 on success, -1 on failure
  */
int create_file(const char *filename, char *text_content)
{
	int fd, written_bytes, num_bytes;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	/*0600 rep permission rw-------*/
	if (fd == -1)
		return (-1);
	if (text_content == NULL)
		text_content = "";
	num_bytes = stringLength(text_content);
	written_bytes = write(fd, text_content, num_bytes);
	if (written_bytes == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}
