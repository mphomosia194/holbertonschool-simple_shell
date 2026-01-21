#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/**
 * struct shell_state - shell runtime state
 * @name: program name (argv[0])
 * @count: command counter
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

/* errors */
void print_not_found(shell_state_t *state, char *cmd);

/* utils */
void free_argv(char **argv);

#endif /* SHELL_H */
