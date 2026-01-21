#include "shell.h"

/**
 * print_not_found - print command not found error
 * @state: shell state
 * @cmd: command name
 */
void print_not_found(shell_state_t *state, char *cmd)
{
	fprintf(stderr, "%s: %u: %s: not found\n",
		state->argv0, state->line_count, cmd);
}
