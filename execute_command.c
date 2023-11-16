#include "shell.h"
/**
 * execve_command - execve function that executes command with given path
 * @argv: argument vector
 * @path: command path
 *
 * Return: nothing
 */
void execve_command(char *path, char *const argv[])
{
	if (execve(path, argv, environ) == -1)
	{
	error_handler(argv[0]);
	}
}


/**
 * execute_command - executes command
 * @argv: argument vector
 *
 * Return: on success 0 otherwise -1
 */
int execute_command(char *argv[])
{
	int status;
	pid_t child_pid;
	int built_in = handle_builtin(argv[0], argv);
	char *path = NULL;

	path = handle_path(argv[0]);
	if (!built_in && path == NULL)
	{
	perror(argv[0]);
	return (EXIT_FAILURE);
	}
	if (built_in)
	{
	if (path)
	free(path);
	return (1);
	}
	child_pid = fork();/* fork to create a new process*/
	if (child_pid == -1)/*error*/
	{
	perror("fork");
	if (path)
	/*free(path);*/
	return (-1);
	}
	if (child_pid == 0)/*on success call the exec func*/
	{
	execve_command(path, argv);
	}
	else
	{
	if (waitpid(child_pid, &status, 0) == -1)/*wait for child to terminate*/
	{
	perror("waitpid");
	return (-1);
	}
	return (WEXITSTATUS(status));/*return exit of the child*/
	}
	return (0);
}
