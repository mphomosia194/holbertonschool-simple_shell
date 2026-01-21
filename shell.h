#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/**
 * struct shell_state - shell state
 * @name: program name
 * @count: command count
 */
typedef struct shell_state
{
	char *name;
	unsigned int count;
} shell_state_t;

/* core */
void shell_loop(shell_state_t *state);

/* parsing */
char **parse_line(char *line);

/* execution */
int execute_command(char **argv, shell_state_t *state);

/* path */
char *find_command(char *cmd);
char *get_env(const char *name);

/* errors */
void print_not_found(shell_state_t *state, char *cmd);

#endif
