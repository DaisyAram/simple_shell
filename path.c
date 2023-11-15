#include "shell.h"
/**
 * find_env- find environment variable
 * @PATH: environment variable
 *
 * Return: value of environment variables
 */
char *find_env(char *PATH)
{
	char **var = __environ;/*pointer to global variable that holds env variables*/
	size_t len = _strlen(PATH);/*calculate length of the input variable*/

	while (*var)/*iterate through each env var stored in the environ arr*/
	{
	if (strncmp(PATH, *var, len) == 0 && (*var)[len] == '=')
	/*checks if current env var starts with same chars as PATH*/
	{
	return (*var + len + 1);/*match found*/
	}
	var++;
	}
	return (NULL);/*not found*/
}

/**
 * handle_path - handles path
 * @command: command
 *
 * Return: NULL or path
 */
char *handle_path(char *command)
{
	int dlen, clen;
	char *copy, *tok, *path, *full_path;

	if (command[0] == '.' || command[0] == '/')/*if command has / or .*/
	{
	if (access(command, F_OK) == 0)
	return (_strdup(command));
	else
	return (NULL);/*if file exists*/
	}
	path = find_env("PATH");
	if (path == NULL || command == NULL)/*path environment variable not found*/
	{
	return (NULL);
	}
	else
	{
	copy = _strdup(path);
	clen = _strlen(command);
	tok = strtok(copy, ":");
	while (tok != NULL)
	{
	dlen = _strlen(tok);
	full_path = malloc(sizeof(char) * (dlen + clen + 2));/*allocate mem*/
	_strcpy(full_path, tok);/*copy the full path*/
	_strcat(full_path, "/");
	_strcat(full_path, command);
	_strcat(full_path, "\0");
	if (access(full_path, F_OK) == 0)/*file exists*/
	{
	free(copy);
	return (full_path);
	}
	else
	{
	free(full_path);/*free mem of current path*/
	tok = strtok(NULL, ":");
	}
	}
	free(copy);
	return (NULL);
	}
	return (NULL);
}
