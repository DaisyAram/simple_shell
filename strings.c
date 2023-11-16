#include "shell.h"
/**
 * _strcpy - copies two strings
 * @dest: input
 * @src: input
 *
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int j = 0;

	while (src[j] != '\0')
	{
	dest[j] = src[j];
	j++;
	}
	dest[j] = '\0';
	return (dest);
}

/**
 * _strlen - returns string length
 * @str: string
 *
 * Return: length
 */
int _strlen(char *str)
{
	char *i = str;

	while (*i)
	i++;
	return (i - str);
}

/**
 * _strcmp - compares two strings
 * @str1: input value
 * @str2: input value
 *
 * Return: (str1[a] - str2[a])
 */
int _strcmp(char *str1, char *str2)
{
	int a;

	for (a = 0; str1[a] != '\0' && str2[a] != '\0'; a++)
	{
	if (str1[a] != str2[a])
	{
	return (str1[a] - str2[a]);
	}
	}
	return (0);
}
/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 *
 * Return: pointer to dup string
 */
char *_strdup(char *str)
{
	unsigned int i, len = 0;
	char *dup = NULL;

	if (str == NULL)
	{
	return (NULL);
	}
	len = _strlen(str);/*calculates length of string*/
	if (len > 0)
	{
	dup = (char *)malloc(len + 1);/*memory allocation*/
	if (dup == NULL)
	{
	return (NULL);
	}
	for (i = 0; i < len; i++)
	{
	dup[i] = str[i];/*copy chars from original string to dup string*/
	}
	}
	dup[len] = '\0';/*null terminator of dup string*/
	return (dup);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int a = 0, b = 0;

	while (dest[a] != '\0')
	a++;

	while (src[b] != '\0')
	{
	dest[a] = src[b];/* apend src to dest*/
	a++;
	b++;
	}
	dest[a] = '\0';
	return (dest);/*add null terminator at the end of the string*/
}
