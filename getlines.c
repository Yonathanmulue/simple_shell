#include "shell.h"

/**
* _getline - This function Reads The Inputs By User From Stdin
*
* Return: Inputs that we submitted
*/
char *_getline(void)
{
	int v = 0;
	ssize_t nread;
	char d = 0, *buffer = malloc(sizeof(char) * BUFFER_SIZE);

	if (buffer == NULL)
	{
		return (NULL);
	}
	while (d != EOF && d != '\n')
	{
		nread = read(STDIN_FILENO, &d, 1);
		if (nread == 0 || nread == -1)
		{
			free(buffer);
			if (nread == 0)
				exit(EXIT_SUCCESS);
			if (nread == -1)
				perror("Error: ");
		}
		buffer[v] = d;
		if (buffer[0] == '\n')
		{
			free(buffer);
			return ("\0");
		}
		if (v + 1 >= BUFFER_SIZE)
		{
			buffer = _realloc(buffer, v + 1);
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
		v++;
	}
	buffer[v - 1] = '\0';
	hash_handler(buffer);
	return (buffer);
}

/**
* hash_handler - This function handles the hash character in input
* @buff: input buffer that we implemented
*/
void hash_handler(char *buff)
{
	int v = 0;

	while (buff[v] != '\0')
	{
		if (buff[v] == '#')
			buff[v] = '\0';
		v++;
	}
}
