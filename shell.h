#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_ARGS 256

/*myprint_func*/
void _puts(const char *str);
int _putchar(char c);

/*execute_command*/
void print_env(char **args __attribute__((unused)));
void execve_command(char *path, char *const argv[]);
int _execute(char *args[]);

/*delim_command*/
int check_delim(const char *command);

/*handle_error*/
void handle_error(char* command);


#endif 
