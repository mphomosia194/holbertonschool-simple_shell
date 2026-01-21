#include "shell.h"

/**
 * shell_loop - main shell execution loop
 * @state: shell state
 */
void shell_loop(shell_state_t *state)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		read = getline(&line, &len, stdin);
		if (read == -1)
			break;

		argv = parse_line(line);
		if (!argv || !argv[0])
		{
			free(argv);
			continue;
		}

		state->count++;
		execute_command(argv, state);
		free(argv);
	}

	free(line);
}
