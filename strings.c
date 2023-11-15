#include "shell.h"
/**
 * strcpy - copies two strings
 * @dest: input
 * @src: input
 *
 * Return: dest
 */
char *_strcpy(char *dest, const char *src)
{
	int j = 0;

	while ((dest[j] = src[j]) != '\0')
	j++;
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
	int i = 0;

	while (*str != '\0')
	{
	i++;
	str++;
	}
	return (i);
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
char *_strdup(const char *str)
{
	unsigned int i, len = 0;
	char *dup = NULL;

	if (str == NULL)
	{
	return (NULL);
	}

	for (len = 0; str[len] != '\0'; len++);/*calulates length of string*/

	dup = (char *)malloc(len + 1);/*memory allocation*/
	if (dup == NULL)
	{
	return (NULL);
	}
	for (i = 0; i < len; i++)
	{
	dup[i] = str[i];/*copy chars from original string to dup string*/
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
char *_strcat(char *dest, const char *src)
{
	int a, b;

	for (a = 0; dest[a] != '\0'; a++);/*find null terminator in dest*/

	for (b = 0; src[b] != '\0'; b++)/* apend src to dest*/
	{
	dest[a + b] = src[b];
	}
	dest[a + b] = '\0';
	return (dest);/*add null terminator at the end of the string*/
}
