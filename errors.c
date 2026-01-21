#include "shell.h"

/**
 * print_not_found - prints command not found error
 * @name: program name (argv[0])
 * @count: command count
 * @cmd: command entered
 */
void print_not_found(char *name, int count, char *cmd)
{
	fprintf(stderr, "%s: %d: %s: not found\n", name, count, cmd);
}
