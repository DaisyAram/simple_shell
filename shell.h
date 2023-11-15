#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>
#include <sys/stat.h>

#define MAX_ARGS 256

extern char **environ;

/*myprint_func*/
void _puts(const char *str);
int _putchar(char c);

/*execute_command*/
void execve_command(char *path, char *const argv[]);
int execute_command(char *args[]);

/*delim_command*/
int check_delim(const char *command);

/*handle_error*/
void error_handler(char* command);

/* handle path*/
char *handle_path(char *command);
char *find_env(char *PATH);

/*handle command line arguments*/
int command_args(int argc, char *argv[]);

/**handle builtin commands*/
int handle_builtin(char *command, char **arg);
void builtin_exit(char **arg);
void builtin_env(char **arg __attribute__((unused)));


/*strings.c*/
int _strcmp(char *str1, char *str2);
char *_strdup(const char *str);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
int _strlen(char *str);
#endif 
