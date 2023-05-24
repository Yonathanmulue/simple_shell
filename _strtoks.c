#include "shell.h"

/**
* _strtok - This function strtok is for implementation
* @str: string we do
* @delim: we use this for delimiter
*
* Return: token
*/
char *_strtok(char *str, char const *delim)
{
	static char *ptr;
	int sizes = 0;
	char *token;
	int v = 0;

	if (str != NULL)
		ptr = str;
	while (ptr[v] != '\0')
		if (ptr[v] == *delim)
		{
			ptr[v] = '\0';
			token = ptr;
			ptr = &ptr[v + 1];
			return (token);
		}
		else
			v++;
	if (ptr[0] != '\0')
	{
		while (ptr[sizes] != 0)
			sizes++;
		token = ptr;
		ptr += sizes;
		return (token);
	}
	return (NULL);
}
