#include "shell.h"
extern char **environ;
/** print_env - prints environment
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
	perror("./hsh");
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

	child_pid = fork();/* fork to create a new process*/
	if (child_pid == -1)/*error*/
	{
	perror("fork failed");

	exit(EXIT_FAILURE);
	}

	if (child_pid == 0)/*on success call the exec func*/
	{
	execve_command(argv[0], argv);
	}
	else
	{
	waitpid(child_pid, &status, 0);/*wait for the child to terminate*/
	}
	return (0);
}
