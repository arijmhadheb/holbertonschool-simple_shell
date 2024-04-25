#include "shell.h"
/**
 * main - The main function
 * Return: returns 0 to indicate successful execution.
 */
int main(void)
{
	char *readline, **tok, *path = NULL;
	int stat;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		readline = read_line();
		if (strcmp("env\n", readline) == 0)
		{
			free(readline);
			_env();
			continue;
		}
		if (strcmp(readline, "exit\n") == 0)
		{
			free(readline);
			break;
		}
		tok = split(readline, TOK_DELIM);
		if (*tok == NULL)
		{
			free_args(tokens);
			continue;
		}
		path = path(*tok);
		if (path == NULL)
		{
			perror("command not found");
			free(path);
			free_args(tok);
			return (3);
		}
		if (path != NULL)
		{
			stat = execute(tok, path);
			free(path);
		}
		free_args(tok);
	}
	return (stat);
}
