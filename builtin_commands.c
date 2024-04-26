#include "shell.h"
#include <stdlib.h>
/**
 * pwd - builtin command.
 *
 * Return: 1 or 0.
 */
int pwd(void)
{
	char cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
		return (1);
	}
	else
	{
		perror("getcwd() error");
		return (0);
	}
}
/**
 * exit - Builtin command: exit
 *
 * Return: 0 to exit the shell
 */
int exit_shell(void)
{
	exit(EXIT_SUCCESS);
}
