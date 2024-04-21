#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

extern char **environ;

int launch_prompt_1(char **args);
int launch_prompt_2(int argc_number, char **args);
int built_in(char **command);
char **parse(char *input);
char *find_path(char *command);
char *prompt_and_read_input_1(char **input, size_t *len);
char *prompt_and_read_input_2(char **input, size_t *len);
int execute_command(const char *path, char **command);
const char *get_path();
void free_string_array(char **array);
void sigint_handler();


#endif
