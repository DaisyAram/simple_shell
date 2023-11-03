#include "shell.h"
/**
 * check_delim - checks if the command has a delimeter
 * @command: command to be cheked
 *
 * Return: 1 if delimeter is present, otherwise 0
 */
int check_delim(const char *command)
{
	size_t j;

	for(j = 0; command[j] != '\0'; j++)/* not null char*/
	{
	if(command[j] != '\t' && command[j] != ' ')/*not a space or tab*/
	{
	return (0);/* no space or tab is found*/
	}
	}
	return (1);/*space or tab is found*/
}
