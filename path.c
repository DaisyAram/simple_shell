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
	return (*var +len +1);/*match found*/
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
	char *dir, *tok;
	char *full_path;
	char *path = getenv("PATH");
	

	if (command[0] == '/' || command[0] == '.')
	{
	if(access(command, F_OK) == 0 ? _strdup(command) : NULL);
	}
	path 
	if (path == NULL)/*path environment variable not found*/
	{
	return (NULL);
	}
	dir = strdup(path);
	if (dir == NULL)
	{
	perror("strdup failed");
	return (NULL);
	}
	tok = strtok(dir, ":");
	
	while(tok != NULL)
	{
	full_path = (char *)malloc(strlen(tok) + strlen(command) + 2);/*allocate mem*/
	if (full_path == NULL)
	{
	perror("malloc failed");
	free (dir);
	return (NULL);
	}
	strcpy(full_path, tok);
	strcat(full_path, "/");
	strcat(full_path, command);

	if (access(full_path, X_OK) == 0)/*file exists*/
	{
	free (dir);
	return (full_path);
	}
	free(full_path);/*free mem of current path*/
	tok = strtok(NULL, ":");
	}
	free (dir);
	return (NULL);
}
