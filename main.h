#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

/* Extern global variable */
extern char **environ;

/* Main functions prototypes */
int built_in(char **command);
char **parse(char *input);
char *find_path(char *command);
char *read_input(char **input, size_t *len);
int execute_command(const char *path, char **command);
const char *get_path();
int handle_command_found(char **command,int argc, char *argv[]);

/* Helper functions prototypes */
void free_string_array(char **array);
void sigint_handler(int sig);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
int _perror(char *error_msg);
#endif
