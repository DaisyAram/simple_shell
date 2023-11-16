#include "shell.h"
/**
 * error_handler - handles errors
 * @command: command
 *
 * Return: nothing
 */
void error_handler(char *command)
{
	fprintf(stderr, "%s\n", command);
	perror("");
	exit(EXIT_FAILURE);
}
