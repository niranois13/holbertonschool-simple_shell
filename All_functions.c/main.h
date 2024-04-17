#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char **parse(char *input);
char *find_path(char *command);
char *prompt_and_read_input(char **input, size_t *len);
int execute_command(char **command);



#endif
