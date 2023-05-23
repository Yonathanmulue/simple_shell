#include "shell.h"

/**
 * process_command - This command executes corresponding actions.
 * @argv: The array of strs.
 *
 * Return: 0 on success, 1 .
 */
int process_command(char **argv)
{
	int num_argu = num_args(argv);

	if (_strcmp(argv[0], "cd") == 0)
	{
		if (num_argu >= 1)
		{
			cd(argv[1]);
			return (0);
		}
	}
	if (_strcmp(argv[0], "env") == 0)
	{
		_env();
		return (0);
	}
	if (_strcmp(argv[0], "setenv") == 0)
	{
		if (num_argu == 3)
		{
			_setenv(argv[1], argv[2]);
			return (0);
		}
	}
	if (_strcmp(argv[0], "unsetenv") == 0)
	{
		if (num_argu == 2)
		{
			_unsetenv(argv[1]);
			return (0);
		}
	}
	if (alias_command(argv, num_argu))
	{
		return (0);
	}
	return (1);
}
