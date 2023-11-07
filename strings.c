#include "shell.h"
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
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: dest
 */
char *_strcat(char *dest, const char *src)
{
	int a, b;
	
	for (a = 0; dest[a] != '\0'; i++);/*find null terminator in dest*/
	for (b = 0; src[b] != '\0'; j++)/* apend src to dest*/
	{
	dest[a + b] = src[b];
	}
	dest[a + b] = '\0';
	return (dest);/*add null terminator at the end of the string*/
}

