#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * read_line - read line from stdin
 * Return: a memory allocated input line
 */
char *read_line(void)
{
	char *line = NULL;
	size_t size = 0;

	if (getline(&line, &size, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			return (NULL);
		}
		else
		{
			perror("you can not read the line");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
/**
 * read_line_file - Read line from file
 *  @file: Pointer to the file from which to read input.
 * Return: A dynamically allocated the input line.
 */
char *read_line_file(FILE *file)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, file) == -1)
	{
		if (feof(file))
		{
			free(line);
			return (NULL);
		}
		else
		{
			perror("you can not read line from a file");
			return (NULL);
		}
	}
	return (line);
}
