#include "shell.h"

/**
 * find_command - finds command in PATH
 * @cmd: command name
 *
 * Return: full path or NULL
 */
char *find_command(char *cmd)
{
	char *path, *path_copy, *dir, *full;
	struct stat st;

	if (!cmd)
		return (NULL);

	if (stat(cmd, &st) == 0 && (st.st_mode & X_OK))
		return (strdup(cmd));

	path = get_env("PATH");
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	dir = strtok(path_copy, ":");

	while (dir)
	{
		full = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!full)
			break;

		sprintf(full, "%s/%s", dir, cmd);
		if (stat(full, &st) == 0 && (st.st_mode & X_OK))
		{
			free(path_copy);
			return (full);
		}

		free(full);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
