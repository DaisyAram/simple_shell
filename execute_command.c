#include "shell.h"
extern char **environ;
/**
 * print_env - prints environment
 * @args: arguments
 *
 * Return: nothing
 */
void print_env(char **args __attribute__((unused)))
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
 * execve_command _ execve function that executes command with given path
 * @argv: argument vector
 * @path: command path
 * @env: environment
 *
 * Return: nothing
 */
void execve_command(char *path, char *const argv[])
{
	if (execve(path, argv, environ) == -1)
	{
	perror("could not execute");
	if (path)
	free(path);
	exit(EXIT_FAILURE);
	}
}
/**
 * _execute - executes command
 * @argv: argument vector
 *
 * Return: on success 0
 */
int _execute(char *argv[])
{
	int status;
	pid_t child_pid;
	char *path = NULL;

	if (path == NULL)
	{
	perror(argv[0]);
	return(EXIT_FAILURE);
	}

	child_pid = fork();/* fork to create a new process*/
	if (child_pid < 0)/*error*/
	{
	perror("fork failed");
	free(path);
	exit(EXIT_FAILURE);
	}

	if (child_pid == 0)/*on success call the exec func*/
	{
	execve_command(path, argv);
	}
	else
	{
	waitpid(child, &status, 0);/*wait for the child to terminate*/

	/*if (WIFEXITED(status);*/
	
	if (path)
	free (path);
	}
	return (0);
}
