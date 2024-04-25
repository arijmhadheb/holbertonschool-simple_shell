#include "shell.h"
/**
 * env - the environment variables.
 */
void env(void)
{
	char *p = env[0];
	int i = 0;

	while (p != NULL)
	{
		printf("%s\n", env[i]);
		p = env[++i];
	}
}
