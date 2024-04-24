#ifndef __HEADER_H__
#define __HEADER_H__

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
int main();
char *_getline(char **input, size_t *len);
char **parse(char *input);
int built_in(char **command);
char *find_path(char *command);
const char *get_path();
int execute_command(char *path, char **command);

/* Helper functions */
void *_realloc(void *ptr, size_t old_size, size_t new_size);
int check_malloc(char **array);
int check_realloc(char **array);
void free_string_array(char **array);
void sigint_handler(int sigint_);


#endif
