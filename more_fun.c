#include "shell.h"
/**
 * add_env_var - This fun adds a new env to the list
 * @head: This is the pointer to the header of the list.
 * @name: we use this as a name of the env variable
 * @value: This is the value.
 */
void add_env_var(struct Node **head, const char *name, const char *value)
{
	size_t names_2 = _strlen(name);
	size_t value_length = _strlen(value);
	char *new_env_var = malloc(names_2 + value_length + 2);
	struct Node *current = *head;

	if (new_env_var == NULL)
	{
		return;
	}

	_memcpy(new_env_var, (void *)name, names_2);
	new_env_var[names_2] = '=';
	_memcpy(new_env_var + names_2 + 1, (void *)value, value_length);
	new_env_var[names_2 + value_length + 1] = '\0';

	while (current != NULL)
	{
		if (_strncmp(current->str, name, names_2)
				== 0 && current->str[names_2] == '=')
		{
			free(current->str);
			current->str = new_env_var;
			return;
		}
		current = current->next;
	}

	add_node(head, new_node(new_env_var));
}

/**
 * update_environ - This is to Update the env var
 * @head: we use this as a head of the list.
 */
void update_environ(struct Node *head)
{
	size_t counter = 0;
	size_t v;
	struct Node *current = head;
	char **new_environ;

	while (current != NULL)
	{
		counter++;
		current = current->next;
	}

	new_environ = malloc((counter + 1) * sizeof(char *));
	if (new_environ == NULL)
	{
		return;
	}

	current = head;
	for (v = 0; v < counter; v++)
	{
		new_environ[v] = current->str;
		current = current->next;
	}
	new_environ[counter] = NULL;

	environ = new_environ;
}

