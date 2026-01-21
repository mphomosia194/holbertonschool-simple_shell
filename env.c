#include "shell.h"

/**
 * get_env - gets environment variable
 * @name: variable name
 *
 * Return: value or NULL
 */
char *get_env(const char *name)
{
	int i;
	size_t len;

	if (!name)
		return (NULL);

	len = strlen(name);

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, len) == 0 &&
		    environ[i][len] == '=')
			return (environ[i] + len + 1);
	}
	return (NULL);
}
