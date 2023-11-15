#include "shell.h"
void error_handler(char *command)
{
	fprintf(stderr, "%s:", command);
	perror("");
	exit(EXIT_FAILURE);
}
