#include "shell.h"

/**
 * execute_command - executes a command
 * @argv: argument vector
 * @state: shell state
 *
 * Return: 1 on success, 0 otherwise
 */
int execute_command(char **argv, shell_state_t *state)
{
	pid_t pid;
	int status;

	if (!argv || !argv[0])
		return (0);

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			print_not_found(state, argv[0]);
			exit(127);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
		state->line_count++;
	}
	else
	{
		perror(state->argv0);
	}

	return (1);
}
