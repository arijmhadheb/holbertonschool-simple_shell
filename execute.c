#include "shell.h"

/**
 * execute - Executes a command by fork and using execve.
 * @tok: The pointer
 * @path: The full path
 *
 * Return: The exit status of the executed command.
 */
int execute(char **tok, char *path)
{
	int stat = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork Unsuccessful");
		exit(1);
	}

	if (pid == 0)
	{
		execve(path, tok, env);
		perror("execve unsyccessful");
		exit(2);
	}
	else
	{
		wait(&stat);
		if (WIFEXITED(stat))
			stat = WEXITSTATUS(stat);
	}

	return (stat);
}
