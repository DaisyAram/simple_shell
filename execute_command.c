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
	perror("execve");
	exit(EXIT_FAILURE);
	}
}
/**
 * _execute - executes command
 * @argv: argument vector
 *
 * Return: on success 0 otherwise -1
 */
int _execute(char *argv[])
{
	int status;
	char *path = NULL;
	pid_t child_pid;

	if (access(argv[0], F_OK) == -1)
	{
	perror("Access error");
	return ( -1);
	}
	path = handle_path(argv[0]);
	child_pid = fork();/* fork to create a new process*/
	if (child_pid == -1)/*error*/
	{
	perror("fork");
	return ( -1);
	}

	if (child_pid == 0)/*on success call the exec func*/
	{
	execve_command(argv[0], argv);

	}
	else
	{
	if (waitpid(child_pid, &status, 0) == -1)/*wait for the child to terminate*/
	{
	perror("waitpid");
	return ( -1);
	}
	return (WEXITSTATUS(status));/*return exit of the child*/
	}
	return (0);
}
