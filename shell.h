#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

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

void shell_loop(shell_state_t *state);

char **parse_line(char *line);
int execute_command(char **argv, shell_state_t *state);
void print_not_found(shell_state_t *state, char *cmd);
void free_argv(char **argv);

extern char **environ;

#endif
