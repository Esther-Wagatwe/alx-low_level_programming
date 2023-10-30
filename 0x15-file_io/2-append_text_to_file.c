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
  * append_text_to_file - function that appends text at the end of a file
  * @filename: the name of the file
  * @text_content: the NULL terminated string to add at the end of the file
  * Return: 1 on success and -1 on failure
  */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, written_bytes, numbytes;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	if (text_content != NULL)
	{
		numbytes = stringLength(text_content);
		written_bytes = write(fd, text_content, numbytes);
		if (written_bytes == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
