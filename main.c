#include "shell.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	shell_state_t state;

	(void)argc;

	state.argv0 = argv[0];
	state.line_count = 1;

	shell_loop(&state);

	return (0);
}
