#include "shell.h"

/**
 * shell_loop - main shell loop
 * @state: shell state
 */
void shell_loop(shell_state_t *state)
{
	char *line;
	size_t len;
	ssize_t read;
	char **argv;

	line = NULL;
	len = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			exit(0);
		}

		state->count++;
		argv = parse_line(line);
		if (argv && argv[0])
			execute_command(argv, state);

		free_argv(argv);
	}
}
