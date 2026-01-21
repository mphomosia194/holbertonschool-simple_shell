#include "shell.h"

/**
 * shell_loop - main shell loop
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
		{
			free(line);
			break;
		}

		if (line[0] == '\n')
			continue;

		argv = parse_line(line);
		if (!argv || !argv[0])
		{
			free_argv(argv);
			continue;
		}

		execute_command(argv, state);
		free_argv(argv);
	}

	free(line);
}
