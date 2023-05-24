#include "shell.h"

/**
 * main - This is the main of the program.
 * @ac: This is to show the number of command lines args.
 * @av: this is to show the array
 *
 * Return: 0 on success other wise
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *__attribute__ ((unused)) cmd1;
	char *argv[MAX_ARGS];

	char *__attribute__ ((unused)) full_path;
	int __attribute__ ((unused)) num_arg;
	signal(SIGSEGV, handle_segfault);

	do {
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		cmd = read_command();
		if (cmd == NULL)
			exit(EXIT_SUCCESS);
		if (cmd[0] == '\0' || (_strcmp(cmd, "\n") == 0))
			continue;

		remwspaces(cmd);
		tokenize(cmd, argv);
		if (cmd[0] == '\0')
			continue;
		if (_strcmp(argv[0], "exit") == 0)
		{
			_1exit(argv[1]);
		}

		if (process_command(argv) == 0)
		{
			free(cmd);
			continue;
		}
		else
			_exec(argv, av[0]);

		free(cmd);
		cmd = NULL;
	} while (1);

	return (0);
}

/**
 * wspace - This checks character space or the tabs
 * @s: this is the to check
 *
 * Return: 1 if success or 0 otherwise.
 */

int wspace(char s)
{
	if (s == ' ' || s == '\t')
		return (1);

	return (0);
}

/**
 * remwspaces - this is to remove all the white spaces
 * @s: this is the string to be checked that we implement
 */

void remwspaces(char *s)
{
	int len = _strlen(s);
	int v = 0, d = len - 1, h;
	int g, count, n;

	if (s == NULL)
		return;

	while (v < len && wspace(s[v]))
	{
		v++;
	}
	while (d >= v && wspace(s[d]))
	{
		d--;
	}
	h = 0;
	while (v <= d)
	{
		s[h++] = s[v++];
	}
	s[h] = '\0';
	g = 0;
	count = 0;
	for (n = 0; n <= d; n++)
	{
		if (s[n] != ' ')
		{
			s[g++] = s[n];
			count = 0;
		}
		else if (count == 0)
		{
			s[g++] = s[n];
			count++;
		}
	}
	s[g] = '\0';
}

/**
 * read_command - As the name indicates it reads user input
 *
 * Return: This is to return the pointer to the input string.
 */
char *read_command(void)
{
	char *cmdd = _getline();

	signal(SIGINT, handle_sigint);
	return (cmdd);
}

/**
 * handle_sigint - This is the Signal handlers.
 * @signo: we use this as a signal num
 */
void handle_sigint(int signo __attribute__((unused)))
{
	write(1, "\n", 1);
	if (cmd != NULL)
	{
		free(cmd);
		cmd = NULL;
	}
	exit(0);
}

