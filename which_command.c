#include "shell.h"

/**
 * which - function
 * @command: this is a command
 * Return: the path to execute
 */

char *which(char *command)
{
	char *paths = _getenv("PATH");
	char *path_copy;
	char *dir;

	if (paths == NULL)
	{
		return (NULL);
	}
	path_copy = _strdup(paths);
	dir = _strtok(path_copy, ":");

	while (dir != NULL)
	{
		char full_path[1024];

		_strcpy(full_path, dir);
		_strcat(full_path, "/");
		_strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (_strdup(full_path));
		}
		dir = _strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

