#include "shell.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	shell_state_t state;

	(void)argc;
	state.name = argv[0];
	state.count = 0;

	shell_loop(&state);
	return (0);
}
