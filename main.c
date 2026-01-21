#include "shell.h"

/**
 * main - simple shell 0.1
 *
 * Return: Always 0
 */
int main(void)
{
	char *line;
	size_t len;
	ssize_t read;
	pid_t pid;
	int status;
	char *argv[2];

	line = NULL;
	len = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			exit(0);
		}

		/* ignore empty or spaces-only lines */
		if (read <= 1)
			continue;

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		argv[0] = line;
		argv[1] = NULL;

		pid = fork();
		if (pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("./hsh");
				exit(1);
			}
		}
		else if (pid > 0)
		{
			wait(&status);
		}
		else
		{
			perror("./hsh");
		}
	}
}
