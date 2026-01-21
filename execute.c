#include "shell.h"

/**
 * execute_command - executes a command with PATH support
 * @argv: argument vector
 * @state: shell state
 *
 * Return: 0
 */
int execute_command(char **argv, shell_state_t *state)
{
	pid_t pid;
	int status;
	char *cmd_path;

	if (!argv || !argv[0])
		return (-1);

	cmd_path = find_command(argv[0]);
	if (!cmd_path)
	{
		print_not_found(state->av[0], state->count, argv[0]);
		return (127);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd_path, argv, environ) == -1)
			exit(126);
	}
	else if (pid < 0)
	{
		free(cmd_path);
		return (-1);
	}
	else
	{
		wait(&status);
	}

	free(cmd_path);
	return (0);
}
