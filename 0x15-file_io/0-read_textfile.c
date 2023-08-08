#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads and prints a text file.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 * Return: The actual number of letters read and printed, or 0 on error.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return (0);

	FILE *file = fopen(filename, "r");
	if (file == NULL)
		return (0);

	char *buffer = malloc(letters + 1);
	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}

	ssize_t bytesRead = fread(buffer, 1, letters, file);
	if (bytesRead <= 0)
	{
		fclose(file);
		free(buffer);
		return (0);
	}

	buffer[bytesRead] = '\0';

	ssize_t bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
	if (bytesWritten != bytesRead)
	{
		fclose(file);
		free(buffer);
		return (0);
	}

	fclose(file);
	free(buffer);

	return (bytesRead);
}

int main(void)
{
	const char *filename = "example.txt";
	size_t letters = 100;

	ssize_t result = read_textfile(filename, letters);

	if (result == 0)
	{
		fprintf(stderr, "Error reading or printing the file.\n");
		return (1);
	}

	printf("\nTotal letters read and printed: %zd\n", result);

	return (0);
}

