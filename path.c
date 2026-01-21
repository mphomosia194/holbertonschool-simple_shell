#include "shell.h"

/**
 * find_command - finds command in PATH
 * @cmd: command name
 *
 * Return: full path to command or NULL
 */
char *find_command(char *cmd)
{
	char *path, *path_copy, *dir, *full_path;
	struct stat st;

	if (!cmd)
		return (NULL);

	/* If command contains '/', check directly */
	if (strchr(cmd, '/'))
	{
		if (stat(cmd, &st) == 0 && (st.st_mode & X_OK))
			return (strdup(cmd));
		return (NULL);
	}

	path = getenv("PATH");
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!full_path)
			break;

		sprintf(full_path, "%s/%s", dir, cmd);

		if (stat(full_path, &st) == 0 && (st.st_mode & X_OK))
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
