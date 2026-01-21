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

/**
 * free_argv - free argv array
 * @argv: argument vector
 */
void free_argv(char **argv)
{
	if (argv)
		free(argv);
}
/**
 * trim_spaces - removes leading and trailing spaces/tabs
 * @str: input string
 *
 * Return: pointer to trimmed string
 */
char *trim_spaces(char *str)
{
	char *end;

	while (*str == ' ' || *str == '\t')
		str++;

	if (*str == '\0')
		return (str);

	end = str + strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t'))
	{
		*end = '\0';
		end--;
	}

	return (str);
}
