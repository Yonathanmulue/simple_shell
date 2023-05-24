#ifndef SHELL_H
#define SHELL_H

#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stddef.h>
#include <signal.h>

#define BUFFER_SIZE 1024
#define MAX_ARGS 1024
#define MAX_NUM_Aliases 100
#define UNUSED  __attribute__((unused))

static char *cmd __attribute__((unused));
extern char **environ UNUSED;

char *_getline(void);
char *read_command(void);
void hash_handler(char *buff);
char *which(char *command);
char *_strtok(char *str, char const *delim);
char *_getenv(char *str);
int _strcmp(const char *str1, const char *str2);
int _strlen(const char *str);
int _strncpy(char *dest, char *src, int size);
void *_memcpy(void *dest, void *src, size_t n);
void *_realloc(void *ptr, size_t size);
int _strncmp(const char *str1, const char *str2, size_t len);
int _strcpy(char *dest, char *src);
void _exec(char **_argum, char *av);
void _1exit(char *status __attribute__((unused)));
int _atoi(const char *str);
char *_strcat(char *dest, const char *src);
char *_strdup(char *s);
void remove_trailing_and_leading_spaces(char *str);
void tokenize(char *command, char *argv[MAX_ARGS]);
int num_args(char *argv[]);
int cd(char *path);
int process_command(char **argv);
/**
* struct alias_s - this is for alias structures
* @name: this is to call the name
* @alias_cmd: we use this for the commands of alias
*/
typedef struct alias_s
{
	char *name;
	char *alias_cmd;
} alias_t;

int alias_command(char *argv[MAX_ARGS], int num_arg);

/**
* struct Node - this is for the structure
* @str: string - malloc'ed string
* @next: As the name indicates it points to the next node
*/
struct Node
{
	char *str;
	struct Node *next;
};

static struct Node *new_node(char *str) UNUSED;
/**
 * new_node - this creates a new node
 * @str: this is the str value we use as a storage
 * Return: we use this return the pointer to create new
 */
static struct Node *new_node(char *str)
{
	struct Node *node = malloc(sizeof(struct Node));

	if (node == NULL)
		return (NULL);

	node->str = str;
	node->next = NULL;
	return (node);
}

static void add_node(struct Node **head, struct Node *node) UNUSED;
/**
 * add_node - This adds a note
 * @head: This Pointes to the head of the list
 * @node: This is the node to be added
 */
static void add_node(struct Node **head, struct Node *node)
{
	if (*head == NULL)
		*head = node;
	else
	{
		struct Node *current = *head;

		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
}

void print_list(struct Node *head);
void free_list(struct Node *head);
void update_environ(struct Node *head);
void handle_segfault(int signo __attribute__((unused)));
int _env(void);
int _unsetenv(const char *name);
int _setenv(const char *name, const char *value);
void alias_name(alias_t alias);
void remwspaces(char *s);
void add_env_var(struct Node **head, const char *name, const char *value);
void handle_sigint(int signo __attribute__((unused)));
int wspace(char s);
#endif

