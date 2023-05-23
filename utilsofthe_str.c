#include "shell.h"

/**
 * _strcmp - This is to compare two strings
 * @str1: string one
 * @str2: string two
 * Return: If same return 0, otherwise
 */
int _strcmp(const char *str1, const char *str2)
{
	int v = 0;

	while (str1[v] != '\0' && str2[v] != '\0')
	{
		if (str1[v] != str2[v])
		{
			return (str1[v] - str2[v]);
		}
		v++;
	}
	return (str1[v] - str2[v]);
}
/**
 * _strncmp - this is to contast between two strings
 * @s1: first str
 * @s2: second str
 * @n: the var size
 * Return: if same return 0, otherwise if not equal
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t v = 0;

	while (v < n && s1[v] != '\0' && s2[v] != '\0')
	{
		if (s1[v] != s2[v])
		{
			return (s1[v] - s2[v]);
		}
		v++;
	}
	if (v < n)
	{
		return (s1[v] - s2[v]);
	}
	return (0);
}
/**
 * _strlen - this is the lenth
 * @str: str
 * Return: return the len of string
 */
int _strlen(const char *str)
{
	int v = 0;

	while (str[v] != '\0')
	{
		v++;
	}
	return (v);
}
/**
 * _strncpy - This is the string copy of n limit
 * @dest: dest
 * @src: the source of str
 * @size: number of char to copy
 * Return: return size of char copied
 */
int _strncpy(char *dest, char *src, int size)
{
	int v = 0;

	while (v < size)
	{
		dest[v] = src[v];
		v++;
	}
	dest[v] = '\0';
	return (v);
}
/**
 * _strcpy - str copy the n limits
 * @dest: dest
 * @src: the src of the string
 * Return: the size of char copy
 */
int _strcpy(char *dest, char *src)
{
	int v = 0;

	while (src[v] != '\0')
	{
		dest[v] = src[v];
		v++;
	}
	dest[v] = '\0';
	return (v);
}
