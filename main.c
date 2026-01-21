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

		/* remove newline */
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		pid = fork();
		if (pid == 0)
		{
			if (execve(line, NULL, environ) == -1)
			{
				perror("./shell");
				exit(1);
			}
		}
		else if (pid > 0)
		{
			wait(&status);
		}
		else
		{
			perror("./shell");
		}
	}
}
