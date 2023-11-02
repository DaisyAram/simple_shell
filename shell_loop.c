#include "shell.h"
/**
 * main - main function of a shell
 * @argv: argument vector
 * @argc: argument count
 *
 * Return: 0
 */
int main(__attribute__((unused)) int argc, char **argv __attribute__((unused)))
{
	char *command = NULL;
	size_t size = 0;
	ssize_t nchars;

	while (1)
	{
	write(STDOUT_FILENO, "~$ ", 3);/*display a prompt*/
	fflush(stdout);

	/*read the user input*/
	nchars = getline(&command, &size, stdin);
	if(nchars == -1)
	{
	perror("getline");
	free(command);
	}
	else
	{
	/*remove newline characte*/
	if(command[nchars - 1] == '\n')
	command[nchars - 1] ='\0';

	write(STDOUT_FILENO, command, nchars -1);
	write(STDOUT_FILENO, "\n", 1);/*add a new line*/
	}
	}
	free(command);


	return (0);
}
