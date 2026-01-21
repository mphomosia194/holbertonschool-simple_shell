#include "shell.h"

/**
 * execute_command - fork and execute command
 * @argv: argument vector
 * @state: shell state
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char **argv, shell_state_t *state)
{
	pid_t pid;
	int status;

	if (access(argv[0], X_OK) == -1)
	{
		print_not_found(state, argv[0]);
		return (-1);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			exit(1);
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	else
	{
		perror(state->name);
	}

	return (0);
}
