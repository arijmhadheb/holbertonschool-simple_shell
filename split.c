#include "shell.h"
/**
 * split - spliting line in tokens.
 * @line: the line
 * Return: The Array of tokens.
 */
char **split_line(char *line)
{
	int bufsize = BUFFER_SIZE, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		error();
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				error();
			}
		}

		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[i] = NULL;
	return (tokens);
}
