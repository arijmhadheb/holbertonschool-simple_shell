#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void display_prompt();
char *read_line();
char *read_line_file(FILE *file);
void error(void);

#endif /* SHELL_H*/
