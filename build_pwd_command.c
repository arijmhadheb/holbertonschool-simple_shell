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
		printf("%d\n", cwd);
	}
	else
	{
		perror("getcwd");
	}
}
