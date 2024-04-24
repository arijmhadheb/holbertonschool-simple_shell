#include "shell.h"
/**
 * error - Print error message and exit
 */
void error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}
