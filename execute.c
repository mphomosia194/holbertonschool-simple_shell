#include "shell.h"

/**
 * execute_command - executes a command
 * @argv: argument vector
 * @state: shell state
 *
 * Return: 0
 */
int execute_command(char **argv, shell_state_t *state)
{
	pid_t pid;
	char *cmd_path;

	cmd_path = find_command(argv[0]);
	if (!cmd_path)
	{
		print_not_found(state, argv[0]);
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		execve(cmd_path, argv, environ);
		exit(1);
	}
	else
		wait(NULL);

	free(cmd_path);
	return (0);
}
