#include "shell.h"
/**
 * builtin_exit - implements exit command for a shell
 * @command: command
 *
 * Return: nothing
 */
void builtin_exit(char *command)
{
	free(command);
	exit(EXIT_SUCCESS);
}
/**
 * handle_builtin - handles builtin commands
 * @commands: command
 *
 * Return: 0 success else 1
 */
int handle_builtin(char *command, char **envp)
{
	if (_strcmp(command, "exit") == 0)
	{
	builtin_exit(command);
	}
	
	if(_strcmp(command, "env") == 0)
	{
	builtin_env(envp);
	}
}
