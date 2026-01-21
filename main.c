#include "shell.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	shell_state_t state;

	(void)argc;

	state.av = argv;
	state.count = 0;

	shell_loop(&state);
	return (0);
}
