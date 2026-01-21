#include "shell.h"

/**
 * shell_loop - main shell execution loop
 * @state: shell state
 */
void shell_loop(shell_state_t *state)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **argv;
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;

		argv = parse_line(line);
		if (!argv || !argv[0])
		{
			free(argv);
			continue;
		}

		state->count++;

		execute_command(argv, state);

		for (i = 0; argv[i]; i++)
			free(argv[i]);
		free(argv);
	}

	free(line);
}
