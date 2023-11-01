#include "main.h"

/**
 * err - prints the error message and exits with a given cde
 * @code: exit code
 * err_message: message to print
 * @file: name of file
 * Return: void
 */
void err(int code, const char *err_message, const char *file)
{
	dprintf(STDERR_FILENO, err_message, file);
	exit(code);
}
/**
 * copyFile - Copy the contents of one file to another file.
 * @srcFilename: The name of the source file to copy from.
 * @destFilename: The name of the destination file to copy to.
 *
 * Return: 0 on success, and exits with error codes on failure.
 */

int copyFile(const char *srcFilename, const char *destFilename)
{
	int srcFile, destFile;
	char buffer[BUFFER_SIZE];
	ssize_t bytesRead, bytesWritten;

	srcFile = open(srcFilename, O_RDONLY);
	umask(0);
	destFile = open(destFilename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (destFile == -1)
		err(99, "Error: Can't write to %s\n", destFilename);
	while ((bytesRead = read(srcFile, buffer, BUFFER_SIZE)) > 0)
	{
		bytesWritten = write(destFile, buffer, bytesRead);
		if (bytesWritten == -1)
			err(99, "Error: Can't write to %s\n", destFilename);
	}
	if (srcFile == -1 || bytesRead == -1)
		err(98, "Error: Can't read from file %s\n", srcFilename);
	if (close(srcFile) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", srcFile);
		exit(100);
	}
	if (close(destFile) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", destFile);
		exit(100);
	}
	return (0); /*Return 0 on success*/
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, and exits with error codes on failure.
 */
int main(int argc, char *argv[])
{
	int result;

	if (argc != 3)
		err(97, "Usage: cp file_from file_to\n", "");
	result = copyFile(argv[1], argv[2]);

	return (result);
}
