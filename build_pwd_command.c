#include "shell.h"
/**
 * pwd_command - handle the pwd
 * Return: 0.
 */
void pwd_command(void)
{
	char cwd;

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
		return (1);
	}
	else
	{
		perror("getcwd");
		return (0);
	}
}
