#include "shell.h"

/**
* cd - this changes directory
* @path: we use this path to change
*
* Return: 0 on success, otherwise 1
*/
int cd(char *path)
{
	static int olds;
	char *home = _getenv("HOME");
	char *oldpwd = _getenv("PWD");
	char *newpwd;

	if (path == NULL || _strcmp(path, "~") == 0)
		newpwd = home;
	else if (_strcmp(path, "-") == 0)
	{
		if (old == 0)
		{
			write(2, "cd: OLDPWD not set\n", 20);
			return (0);
		}
		else
			newpwd = _getenv("OLDPWD");
	}
	else
		newpwd = path;
	if (chdir(newpwd) != 0)
	{
		perror("cd");
		return (1);
	}
	old = 1;
	_setenv("OLDPWD", oldpwd);
	_setenv("PwD", newpwd);
	return (0);
}
