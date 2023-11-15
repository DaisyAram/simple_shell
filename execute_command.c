#include "shell.h"
extern char **environ;
/** 
 * builtin_env - prints environment
 * @envp: environment
 *
 * Return: nothing
 */
void builtin_env(char **envp)
{
	char **env = envp;

	while (*env != NULL)
	{
	_puts(*env);
	_putchar('\n');
	env++;
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
	error_handler(argv[0]);
	if (path)
	free(path);
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
	pid_t child_pid;
	int built_in = handle_builtin(argv[0], argv)

	if (access(argv[0], F_OK) == -1)
	{
	error_handler(argv[0]);
	return ( -1);
	}
	handle_path(argv[0]);
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
