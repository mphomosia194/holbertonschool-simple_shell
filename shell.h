#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

/**
 * struct shell_state
 * @av: argument vector
 * @count: command count
 */
typedef struct shell_state
{
	char **av;
	int count;
} shell_state_t;

/* core */
void shell_loop(shell_state_t *state);

/* helpers */
char **parse_line(char *line);
int execute_command(char **argv, shell_state_t *state);
char *find_command(char *cmd);
/* errors */
void print_not_found(char *name, int count, char *cmd);

#endif
