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
	char **args;
	int j;

	while (1)
	{
	write(STDOUT_FILENO, "~$ ", 3);/*display a prompt*/
	fflush(stdout);

	nchars = getline(&command, &size, stdin);/*read user input*/
	if(nchars == -1)/*enf of a file*/
	{
	perror("getline");
	free(command);
	exit(EXIT_SUCCESS);
	}
	else
	{
	if (command[nchars - 1] == '\n')/*remove newline char*/
	command[nchars - 1] ='\0';
	if (command[0] == '\n' || nchars == 1 ||check_delim(command) == 1)/*func call*/
	{
	continue;
	}
	/*write(STDOUT_FILENO, command, nchars -1);
	write(STDOUT_FILENO, "\n", 1);*add a new line*/
	}
	tok = strtok(command, ";\n");/*parsing strings into single args*/
	while (tok)
	{
	args[j] = tok;
	tok = strtok(NULL, "\t\n");
	j++;
	}
	/*args[j] = NULL;*/
	_execute(argv);/*calling the func tp handle fork and execve*/
	}
	free(command);
	return (0);
}
