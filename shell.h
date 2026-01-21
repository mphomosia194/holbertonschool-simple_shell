#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

/**
 * struct shell_state - shell execution state
 * @argv0: program name
 * @line_count: command counter
 */
typedef struct shell_state
{
	char *argv0;
	unsigned int line_count;
} shell_state_t;

/* core loop */
void shell_loop(shell_state_t *state);

/* parsing */
char **parse_line(char *line);

/* execution */
int execute_command(char **argv, shell_state_t *state);

/* errors */
void print_not_found(shell_state_t *state, char *cmd);

/* utils */
void free_argv(char **argv);

extern char **environ;

#endif
