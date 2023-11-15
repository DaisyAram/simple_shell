#include "shell.h"
/**
 * error_handler - handles errors
 * @command: command
 *
 * Return: nothing
 */
void error_handler(char *command)
{
	fprintf(stderr, "Command not found: %s\n:", command);
	perror("Error");
	exit(EXIT_FAILURE);
}
