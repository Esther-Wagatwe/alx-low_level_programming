#include "main.h"

/**
  * read_textfile - function that reads a file and prints it to the POSIX stout
  * @letters: the number of letters it should read and print
  * @filename: the file to read
  * Return: the actual number of letters it could read and print
  * also returns 0 when function fails or filename is NULL.
  */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t bytes_read, bytes_written;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}
	bytes_read = read(fd, buffer, letters);
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	free(buffer);
	close(fd);
	return (bytes_written);

}

