#include "shell.h"

/**
 * print_not_found - prints command not found
 * @state: shell state
 * @cmd: command
 */
void print_not_found(shell_state_t *state, char *cmd)
{
	fprintf(stderr, "%s: %u: %s: not found\n",
		state->name, state->count, cmd);
}
