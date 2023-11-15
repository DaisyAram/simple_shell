#include "shell.h"
/**
 * main - main function of a shell
 * @argv: argument vector
 * @argc: argument count
 *
 * Return: 0
 */
int main(__attribute__((unused)) int argc, char **argv __attribute__((unused)), __attribute((unused)) char **envp)
{
	char *command = NULL, *tok;
	size_t size = 0;
	ssize_t nchars;
	char **arr;
	int j = 0;
	bool interactive = isatty(STDIN_FILENO);
	char *cmd;
	char **args;
	while (1)
	{
	if (interactive)
	{
	if(isatty(STDOUT_FILENO) == 1)
	{
	write(STDOUT_FILENO, "~$ ", 3);/*display a prompt in interactive mode*/
	fflush(stdout);
	}
	}
	nchars = getline(&command, &size, stdin);/*read user input*/
	if(nchars == -1)/*end of a file*/
	{
	if (interactive)
	{
	perror("getline");
	}
/*	free(command);*/
	break;
	}
	else
	{
	if (command[nchars - 1] == '\n')/*remove newline char*/
	command[nchars - 1] ='\0';
	if (command[0] == '\n' || nchars == 1 ||check_delim(command) == 1)/*func call*/
	{
	/*non interactive mode*/
	continue;
	}
	}
	tok = strtok(command, " \t\n");/*parsing strings into single args*/
	j = 0;
	arr = malloc(sizeof(char *) * 1024);
	while (tok)
	{
	arr[j] = tok;
	tok = strtok(NULL, " \t\n");
	j++;
	}
	
	arr[j] = NULL;
	cmd = arr[0];
	args = arr;
	_execute(arr);/*calling the func tp handle fork and execve*/

	free(arr);
	}
	free(command);
	return (0);
}
