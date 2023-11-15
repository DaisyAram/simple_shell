#include "shell.h"
/**
 * builtin_env - handles builtin env that prints current env
 * @arg: arguments unused
 *
 * Return: nothing
 */
void builtin_env(char **arg __attribute__((unused)))
{
	int j = 0;

	while (environ[j] != NULL)
	{
	_puts(environ[j]);
	_putchar('\n');
	j++;
	}
}
/**
 * builtin_exit - implements exit command for a shell
 * @arg: arguments
 *
 * Return: nothing
 */
void builtin_exit(char **arg)
{
	free(arg);
	exit(EXIT_SUCCESS);
}
/**
 * handle_builtin - handles builtin commands
 * @command: command
 * @arg: arguments
 *
 * Return: 1 on success
 */
int handle_builtin(char *command, char **arg)
{
	if (_strcmp(command, "exit") == 0)
	{
	builtin_exit(arg);
	return (1);
	}
	if (_strcmp(command, "env") == 0)
	{
	builtin_env(arg);
	return (1);
	}
	return (0);
}
