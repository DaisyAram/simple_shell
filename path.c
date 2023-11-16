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
	int j = 0;
	size_t len = _strlen(PATH);/*calculate length of the input variable*/
	char *val;

	for (; var[j]; j++)
	{
	if (strncmp(PATH, var[j], len) == 0 && (var[j][len] == '='))
	/*checks if current env var starts with same chars as PATH*/
	{
	val = var[j] + len + 1;/*match found*/
	break;
	}
	}
	return (val);
}

/**
 * handle_path - handles path
 * @command: command
 * Return: NULL or path
 */
char *handle_path(char *command)
{
	int dlen, clen;
	char *copy, *tok, *path, *full_path;

	if (command[0] == '/' || command[0] == '.')
	{
	if (access(command, F_OK) == 0)
	return (_strdup(command));
	else
	return (NULL);/*if file exists*/
	}
	path = find_env("PATH");
	if (path)
	{
	copy = _strdup(path);
	clen = _strlen(command);
	tok = strtok(copy, ":");
	while (tok)
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

