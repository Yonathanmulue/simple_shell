#include "shell.h"

/**
* remove_trailing_and_leading_spaces - we use this to delete the 
* trailing spaces from a string
* @str: this is the string to delete trailing spaces
*/
void remove_trailing_and_leading_spaces(char *str)
{
	size_t lens = _strlen(str);
	size_t starter = 0;
	size_t v;

	if (lens > 0)
	{
		while (lens > 0 && str[lens - 1] == ' ')
			lens--;
		str[lens] = '\0';
	}

	while (str[starter] == ' ')
		starter++;

	if (starter > 0)
	{
		v = 0;
		while (str[starter + v] != '\0')
		{
			str[v] = str[starter + v];
			v++;
		}
		str[v] = '\0';
	}
}

/**
* tokenize - this tokenizes the string into an array tokens
* @command: this is the string tokenizes
* @argv: this argument is an array to store tokenns
*/

void tokenize(char *command, char *argv[MAX_ARGS])
{
	char *token;
	int v = 0;

	token = _strtok(command, " ");
	while (token != NULL)
	{
		argv[v++] = token;
		token = _strtok(NULL, " ");
	}
	argv[v] = NULL;
}

/**
* num_args - this funtion counts the number of 
* arguments in an array of inputted args
* @argv: this the array of args
*
* Return: we return the number of arguments in argv
*/
int num_args(char *argv[])
{
	int v = 0;

	while (argv[v] != NULL)
		v++;
	return (v);
}

/**
* _atoi - this atoi function converts a strings into array
* @str: this is the string that convert
*
* Return: this is the integer value of str
*/
int _atoi(const char *str)
{
	int v, m = 0;
	int signs = 1;

	for (v = 0; str[v] != '\0'; v++)
		if (str[v] == '-')
			signs = -1;
		else if (str[v] >= '0' && str[v] <= '9')
			m = m * 10 + (str[v] - '0');
		else
			break;

	return (m * signs);
}

/**
* _1exit - this functions exits with a status 
* @status: this is the status code to exit 
*/
void _1exit(char *status __attribute__((unused)))
{
	int v;

	if (status != NULL)
	{
		v  = _atoi(status);
		exit(v);
	}
	exit(0);
}

