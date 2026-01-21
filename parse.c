#include "shell.h"

/**
 * parse_line - splits line into arguments
 * @line: input line
 *
 * Return: NULL-terminated array
 */
char **parse_line(char *line)
{
	char **argv = NULL;
	char *token;
	int i = 0;

	argv = malloc(sizeof(char *) * 64);
	if (!argv)
		return (NULL);

	token = strtok(line, " \t\n");
	while (token)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	argv[i] = NULL;

	return (argv);
}
