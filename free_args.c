#include "shell.h"

/**
 * free- Frees memory allocated for a array of strings
 * @args: array of stringsto free.
 */
void free_args(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
}
