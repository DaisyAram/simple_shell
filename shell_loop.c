#include "shell.h"
/**
 * main - main function of a shell
 *
 * Return: 0
 */
int main(void)
{
	char *command = NULL, *tok;
	size_t size = 0;
	ssize_t nchars;
	char **arr;
	int j;

	while (1)
	{
	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "~$ ", 3);/*display a prompt in interactive mode*/
	fflush(stdout);
	nchars = getline(&command, &size, stdin);/*read user input*/
	if (nchars == -1)/*end of a file*/
	{
	free(command);
	exit(EXIT_SUCCESS);/*exit shell*/
	}
	else
	{
	if (command[nchars - 1] == '\n')/*remove newline char*/
	command[nchars - 1] = '\0';
	if (command[0] == '\n' || nchars == 1 || check_delim(command) == 1)/*funcall*/
	continue;
	}
	arr = malloc(sizeof(char *) * 1024);
	j = 0;
	tok = strtok(command, " ");/*parsing strings into single args*/
	while (tok)
	{
	arr[j] = tok;
	tok = strtok(NULL, " ");
	j++;
	}
	arr[j] = NULL;
	execute_command(arr);/*calling the func tp handle fork and execve*/
	free(arr);
	tok = strtok(NULL, "\t\n");
	}
	free(command);
	return (0);
}
