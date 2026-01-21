#include "shell.h"

/**
 * execute_command - executes a command
 * @argv: argument vector
 * @state: shell state
 *
 * Return: 0 on success
 */
int execute_command(char **argv, shell_state_t *state)
{
	pid_t pid;
	int status;

	if (!argv || !argv[0])
		return (-1);

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			print_not_found(state->av[0], state->count, argv[0]);
			exit(127);
		}
	}
	else if (pid < 0)
		return (-1);
	else
		wait(&status);

	return (0);
}
