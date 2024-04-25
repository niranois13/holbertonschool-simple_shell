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
int built_in(char **command, int *exit_status);
char *read_input(char **input, size_t *len, int argc, char *argv[], int *exit_status);
char **parse(char *input, int argc, char *argv[], int *exit_status);
const char *get_path();
char *find_path(char *command, int argc, char *argv[], int *exit_status);
int execute_command(const char *path, char **command, int *exit_status);
int handle_command_found(char **command,int argc, char *argv[], int *exit_status);

/* Helper functions prototypes */
void *_realloc(void *ptr, size_t old_size, size_t new_size);
void free_string_array(char **array);
void sigint_handler(int sig);
int _perror(char *error_msg, int *exit_status);
void _error(const char *error_msg, int argc, char *argv[], int *exit_status);
#endif
