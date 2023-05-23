#include "shell.h"

/**
 * _getenv - this is the caller.
 * @str: this is the str
 * Return: return path
 */
char *_getenv(char *str)
{
	int b = 0;
	int ben = _strlen(str);

	while (environ[b] != NULL)
	{
		if (_strncmp(environ[b], str, ben) == 0 && environ[b][ben] == '=')
		{
			return (&(environ[b][ben + 1]));
		}
		b++;
	}
	return (NULL);
}

