#include "shell.h"

/**
* _exec - this is executer
* @_argum: This is an array of args
* @av: we use this as a name of the program
*/
void _exec(char **_argum, char *av)
{
	char *cmd2;
	pid_t idchecker;
	char *envp[] = {"TERM=xterm-256color", NULL};
	char ebb[20];

	_strcpy(ebb, av);
	if (_argum[0][0] == '/')
	{
		if (access(_argum[0], X_OK) == 0)
		{
			idchecker = fork();
			if (idchecker == 0)
				execve(_argum[0], _argum, envp);
		}
		else
		{
			perror(ebb);
			return;
		}
	}
	else
	{
		cmd2 = which(_argum[0]);
		if (cmd2 == NULL)
		{
			perror(ebb);
			return;
		}
		idchecker = fork();
		if (idchecker == 0)
			execve(cmd2, _argum, envp);
		free(cmd2);
	}
	wait(NULL);
}
