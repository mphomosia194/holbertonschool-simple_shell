#include "shell.h"

/**
 * shell_loop - main shell loop
 */
void shell_loop(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *cmd;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		cmd = trim_spaces(line);

		if (*cmd == '\0')
			continue;

		execute_cmd(cmd);
	}
}
