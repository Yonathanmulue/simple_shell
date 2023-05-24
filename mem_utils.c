#include "shell.h"
/**
 * _memcpy - this function copies memory from the source to destination
 * @dest: our destination
 * @src:  this is the source
 * @n:  this is for the size of memory to be copied
 * Return: the memory of destination
 */
void *_memcpy(void *dest, void *src, size_t n)
{
	char *ddest = (char *)(dest);
	const char *dsrc = (const char *)(src);
	size_t v = 0;

	while (v < n)
	{
		ddest[v] = dsrc[v];
		v++;
	}
	return (dest);
}
/**
 * _realloc - this is realloc function
 * @ptr: old malloc pointer for our functions
 * @size: our new size
 * Return: the new ptr we implement
 */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
/**
 * _strdup - strdup()
 * @s:  this is our string variable
 * Return: the return of duplicate of s
 */
char *_strdup(char *s)
{
	size_t lens = _strlen(s) + 1;
	char *new_str = malloc(lens);

	if (new_str == NULL)
	{
		return (NULL);
	}
	_memcpy(new_str, s, lens);

	return (new_str);
}
/**
 * _strcat - strcat()
 * @dest: this uses as a destination string
 * @src: This is the source strings
 * Return: this returns concatenated strings
 */
char *_strcat(char *dest, const char *src)
{
	char *p = dest;
	int v = 0, d = 0;

	while (dest[v] != '\0')
	{
		v++;
	}
	while (src[d] != '\0')
	{
		p[v] = src[d];
		v++;
		d++;
	}
	p[v] = '\0';
	return (p);
}
