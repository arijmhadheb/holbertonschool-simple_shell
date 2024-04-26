#include "shell.h"

/**
 * path - Checks if a command exists in the PATH.
 * @cmd: The name of the command to search for.
 *
 * Return: 1 or 0
 */
char *path(char *cmd)
{
	char *array[1000], *path = strdup(getenv("PATH"));
	char *path_tok = strtok(path, ":");
	int i = 0;
	char *f_path;
	struct stat info;

	if (stat(cmd, &info) == 0)
	{
		strcpy(path, cmd);
		return (path);
	}

	f_path = (char *) malloc(1024 * sizeof(char));

	while (path_tok != NULL)
	{
		array[i] = path_tok;
		i++;
		path_tok = strtok(NULL, ":");
	}
	i = 0;
	while (array[i] != NULL)
	{
		strcpy(f_path, array[i]);
		strcat(f_path, "/");
		strcat(f_path, cmd);
		strcat(f_path, "\0");
		if (stat(f_path, &info) == 0)
		{
			free(path);
			return (f_path);
		}
		i++;
	}
	free(f_path);
	free(path);
	return (NULL);
}
