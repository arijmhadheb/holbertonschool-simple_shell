#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define EXIT_SUCCESS 0

void display_prompt(void);
char *read_line(void);
char *read_line_file(FILE *file);
void env(void);
void free_args(char **args);
char *path(char *cmd);
int execute(char **tok, char *path);
char **split_line(char *line);

#endif /* SHELL_H*/
