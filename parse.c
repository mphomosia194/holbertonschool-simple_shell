#include "shell.h"

/**
 * parse_line - tokenize input line
 * @line: input string
 *
 * Return: NULL-terminated argv array
 */
char **parse_line(char *line)
{
	char **argv;
	char *token;
	int i;

	argv = malloc(sizeof(char *) * 64);
	if (!argv)
		return (NULL);

	i = 0;
	token = strtok(line, " \t\n");
	while (token)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	argv[i] = NULL;

	return (argv);
}

/**
 * free_argv - free argv array
 * @argv: argument vector
 */
void free_argv(char **argv)
{
	if (argv)
		free(argv);
}
